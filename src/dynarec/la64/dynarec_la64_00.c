#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <signal.h>

#include "debug.h"
#include "box64context.h"
#include "dynarec.h"
#include "emu/x64emu_private.h"
#include "emu/x64run_private.h"
#include "x64run.h"
#include "x64emu.h"
#include "box64stack.h"
#include "callback.h"
#include "bridge.h"
#include "emu/x64run_private.h"
#include "x64trace.h"
#include "dynarec_native.h"
#include "custommem.h"

#include "la64_printer.h"
#include "dynarec_la64_private.h"
#include "dynarec_la64_functions.h"
#include "dynarec_la64_helper.h"

int isSimpleWrapper(wrapper_t fun);
int isRetX87Wrapper(wrapper_t fun);

uintptr_t dynarec64_00(dynarec_la64_t* dyn, uintptr_t addr, uintptr_t ip, int ninst, rex_t rex, int rep, int* ok, int* need_epilog)
{
    uint8_t nextop, opcode;
    uint8_t gd, ed;
    int8_t i8;
    int32_t i32, tmp;
    int64_t i64, j64;
    uint8_t u8;
    uint8_t gb1, gb2, eb1, eb2;
    uint32_t u32;
    uint64_t u64;
    uint8_t wback, wb1, wb2, wb;
    int64_t fixedaddress;
    int unscaled;
    int lock;
    int cacheupd = 0;

    opcode = F8;
    MAYUSE(eb1);
    MAYUSE(eb2);
    MAYUSE(j64);
    MAYUSE(wb);
    MAYUSE(lock);
    MAYUSE(cacheupd);

    switch (opcode) {
        case 0x00:
            INST_NAME("ADD Eb, Gb");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETEB(x1, 0);
            GETGB(x2);
            emit_add8(dyn, ninst, x1, x2, x4, x5);
            EBBACK(x5, 0);
            break;
        case 0x01:
            INST_NAME("ADD Ed, Gd");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETGD;
            GETED(0);
            emit_add32(dyn, ninst, rex, ed, gd, x3, x4, x5);
            WBACK;
            break;
        case 0x02:
            INST_NAME("ADD Gb, Eb");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETEB(x1, 0);
            GETGB(x2);
            emit_add8(dyn, ninst, x2, x1, x4, x5);
            GBBACK(x5);
            break;
        case 0x03:
            INST_NAME("ADD Gd, Ed");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETGD;
            GETED(0);
            emit_add32(dyn, ninst, rex, gd, ed, x3, x4, x5);
            break;
        case 0x04:
            INST_NAME("ADD AL, Ib");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            u8 = F8;
            ANDI(x1, xRAX, 0xff);
            emit_add8c(dyn, ninst, x1, u8, x3, x4, x5);
            ADDI_W(x3, xZR, 0xf00);
            AND(xRAX, xRAX, x3);
            OR(xRAX, xRAX, x1);
            break;
        case 0x05:
            INST_NAME("ADD EAX, Id");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            i64 = F32S;
            emit_add32c(dyn, ninst, rex, xRAX, i64, x3, x4, x5, x6);
            break;
        case 0x0F:
            switch (rep) {
                case 0:
                    addr = dynarec64_0F(dyn, addr, ip, ninst, rex, ok, need_epilog);
                    break;
                case 2:
                    addr = dynarec64_F30F(dyn, addr, ip, ninst, rex, ok, need_epilog);
                    break;
                default:
                    DEFAULT;
            }
            break;
        case 0x25:
            INST_NAME("AND EAX, Id");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            i64 = F32S;
            emit_and32c(dyn, ninst, rex, xRAX, i64, x3, x4);
            break;
        case 0x28:
            INST_NAME("SUB Eb, Gb");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETEB(x1, 0);
            GETGB(x2);
            emit_sub8(dyn, ninst, x1, x2, x4, x5, x6);
            EBBACK(x5, 0);
            break;
        case 0x29:
            INST_NAME("SUB Ed, Gd");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETGD;
            GETED(0);
            emit_sub32(dyn, ninst, rex, ed, gd, x3, x4, x5);
            WBACK;
            break;
        case 0x2A:
            INST_NAME("SUB Gb, Eb");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETEB(x1, 0);
            GETGB(x2);
            emit_sub8(dyn, ninst, x2, x1, x4, x5, x6);
            GBBACK(x5);
            break;
        case 0x2B:
            INST_NAME("SUB Gd, Ed");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETGD;
            GETED(0);
            emit_sub32(dyn, ninst, rex, gd, ed, x3, x4, x5);
            break;
        case 0x2C:
            INST_NAME("SUB AL, Ib");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            u8 = F8;
            ANDI(x1, xRAX, 0xff);
            emit_sub8c(dyn, ninst, x1, u8, x2, x3, x4, x5);
            ADDI_W(x3, xZR, 0xf00);
            AND(xRAX, xRAX, x3);
            OR(xRAX, xRAX, x1);
            break;
        case 0x2D:
            INST_NAME("SUB EAX, Id");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            i64 = F32S;
            emit_sub32c(dyn, ninst, rex, xRAX, i64, x2, x3, x4, x5);
            break;
        case 0x31:
            INST_NAME("XOR Ed, Gd");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETGD;
            GETED(0);
            emit_xor32(dyn, ninst, rex, ed, gd, x3, x4);
            if(ed!=gd) {
                WBACK;
            }
            break;
        case 0x33:
            INST_NAME("XOR Gd, Ed");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETGD;
            GETED(0);
            emit_xor32(dyn, ninst, rex, gd, ed, x3, x4);
            break;
        case 0x39:
            INST_NAME("CMP Ed, Gd");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETGD;
            GETED(0);
            emit_cmp32(dyn, ninst, rex, ed, gd, x3, x4, x5, x6);
            break;
        case 0x3D:
            INST_NAME("CMP EAX, Id");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            i64 = F32S;
            if(i64) {
                MOV64xw(x2, i64);
                emit_cmp32(dyn, ninst, rex, xRAX, x2, x3, x4, x5, x6);
            } else
                emit_cmp32_0(dyn, ninst, rex, xRAX, x3, x4);
            break;
        case 0x50:
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
            INST_NAME("PUSH reg");
            gd = TO_LA64((opcode & 0x07) + (rex.b << 3));
            PUSH1z(gd);
            break;
        case 0x58:
        case 0x59:
        case 0x5A:
        case 0x5B:
        case 0x5C:
        case 0x5D:
        case 0x5E:
        case 0x5F:
            INST_NAME("POP reg");
            gd = TO_LA64((opcode & 0x07) + (rex.b << 3));
            POP1z(gd);
            break;
            break;
        case 0x66:
            addr = dynarec64_66(dyn, addr, ip, ninst, rex, rep, ok, need_epilog);
            break;
        case 0x68:
            INST_NAME("PUSH Id");
            i64 = F32S;
            if(PK(0)==0xC3) {
                MESSAGE(LOG_DUMP, "PUSH then RET, using indirect\n");
                TABLE64(x3, addr-4);
                LD_W(x1, x3, 0);
                PUSH1z(x1);
            } else {
                MOV64z(x3, i64);
                PUSH1z(x3);
            }
            break;

        #define GO(GETFLAGS, NO, YES, F, I)                                                         \
            READFLAGS(F);                                                                           \
            i8 = F8S;                                                                               \
            BARRIER(BARRIER_MAYBE);                                                                 \
            JUMP(addr + i8, 1);                                                                     \
            if (la64_lbt && (opcode - 0x70) >= 0xC) {                                               \
                X64_SET_EFLAGS(xFlags, F);                                                          \
                X64_SETJ(x1, I);                                                                    \
            } else {                                                                                \
                GETFLAGS;                                                                           \
            }                                                                                       \
            if (dyn->insts[ninst].x64.jmp_insts == -1 || CHECK_CACHE()) {                           \
                /* out of block */                                                                  \
                i32 = dyn->insts[ninst].epilog - (dyn->native_size);                                \
                if (la64_lbt && (opcode - 0x70) >= 0xC)                                             \
                    BEQZ_safe(x1, i32);                                                             \
                else                                                                                \
                    B##NO##_safe(x1, i32);                                                          \
                if (dyn->insts[ninst].x64.jmp_insts == -1) {                                        \
                    if (!(dyn->insts[ninst].x64.barrier & BARRIER_FLOAT))                           \
                        fpu_purgecache(dyn, ninst, 1, x1, x2, x3);                                  \
                    jump_to_next(dyn, addr + i8, 0, ninst, rex.is32bits);                           \
                } else {                                                                            \
                    CacheTransform(dyn, ninst, cacheupd, x1, x2, x3);                               \
                    i32 = dyn->insts[dyn->insts[ninst].x64.jmp_insts].address - (dyn->native_size); \
                    B(i32);                                                                         \
                }                                                                                   \
            } else {                                                                                \
                /* inside the block */                                                              \
                i32 = dyn->insts[dyn->insts[ninst].x64.jmp_insts].address - (dyn->native_size);     \
                if (la64_lbt && (opcode - 0x70) >= 0xC)                                             \
                    BNEZ_safe(x1, i32);                                                             \
                else                                                                                \
                    B##YES##_safe(x1, i32);                                                         \
            }

            GOCOND(0x70, "J", "ib");

        #undef GO

        case 0x80:
            nextop = F8;
            switch((nextop>>3)&7) {
                case 7: // CMP
                    INST_NAME("CMP Eb, Ib");
                    SETFLAGS(X_ALL, SF_SET_PENDING);
                    GETEB(x1, 1);
                    u8 = F8;
                    if(u8) {
                        ADDI_D(x2, xZR, u8);
                        emit_cmp8(dyn, ninst, x1, x2, x3, x4, x5, x6);
                    } else {
                        emit_cmp8_0(dyn, ninst, x1, x3, x4);
                    }
                    break;
                default:
                    DEFAULT;
            }
            break;
        case 0x81:
        case 0x83:
            nextop = F8;
            switch ((nextop >> 3) & 7) {
                case 0: // ADD
                    if (opcode == 0x81) {
                        INST_NAME("ADD Ed, Id");
                    } else {
                        INST_NAME("ADD Ed, Ib");
                    }
                    SETFLAGS(X_ALL, SF_SET_PENDING);
                    GETED((opcode == 0x81) ? 4 : 1);
                    if (opcode == 0x81) i64 = F32S; else i64 = F8S;
                    emit_add32c(dyn, ninst, rex, ed, i64, x3, x4, x5, x6);
                    WBACK;
                    break;
                case 4: // AND
                    if (opcode == 0x81) { INST_NAME("AND Ed, Id"); } else { INST_NAME("AND Ed, Ib"); }
                    SETFLAGS(X_ALL, SF_SET_PENDING);
                    GETED((opcode == 0x81) ? 4 : 1);
                    if (opcode == 0x81) i64 = F32S; else i64 = F8S;
                    emit_and32c(dyn, ninst, rex, ed, i64, x3, x4);
                    WBACK;
                    break;
                case 5: // SUB
                    if (opcode == 0x81) {
                        INST_NAME("SUB Ed, Id");
                    } else {
                        INST_NAME("SUB Ed, Ib");
                    }
                    SETFLAGS(X_ALL, SF_SET_PENDING);
                    GETED((opcode == 0x81) ? 4 : 1);
                    if (opcode == 0x81)
                        i64 = F32S;
                    else
                        i64 = F8S;
                    emit_sub32c(dyn, ninst, rex, ed, i64, x3, x4, x5, x6);
                    WBACK;
                    break;
                case 7: // CMP
                    if (opcode == 0x81) {
                        INST_NAME("CMP Ed, Id");
                    } else {
                        INST_NAME("CMP Ed, Ib");
                    }
                    SETFLAGS(X_ALL, SF_SET_PENDING);
                    GETED((opcode == 0x81) ? 4 : 1);
                    if (opcode == 0x81) i64 = F32S; else i64 = F8S;
                    if (i64) {
                        MOV64xw(x2, i64);
                        emit_cmp32(dyn, ninst, rex, ed, x2, x3, x4, x5, x6);
                    } else {
                        if (!rex.w && MODREG) {
                            AND(x1, ed, xMASK);
                            ed = x1;
                        }
                        emit_cmp32_0(dyn, ninst, rex, ed, x3, x4);
                    }
                    break;
                default:
                    DEFAULT;
            }
            break;
        case 0x85:
            INST_NAME("TEST Ed, Gd");
            SETFLAGS(X_ALL, SF_SET_PENDING);
            nextop = F8;
            GETGD;
            GETED(0);
            emit_test32(dyn, ninst, rex, ed, gd, x3, x4, x5);
            break;
        case 0x89:
            INST_NAME("MOV Ed, Gd");
            nextop = F8;
            GETGD;
            if (MODREG) { // reg <= reg
                MVxw(TO_LA64((nextop & 7) + (rex.b << 3)), gd);
            } else { // mem <= reg
                addr = geted(dyn, addr, ninst, nextop, &ed, x2, x1, &fixedaddress, rex, &lock, 1, 0);
                if (rex.w) {
                    ST_D(gd, ed, fixedaddress);
                } else {
                    ST_W(gd, ed, fixedaddress);
                }
                SMWRITELOCK(lock);
            }
            break;
        case 0x8B:
            INST_NAME("MOV Gd, Ed");
            nextop = F8;
            GETGD;
            if (MODREG) {
                MVxw(gd, TO_LA64((nextop & 7) + (rex.b << 3)));
            } else {
                addr = geted(dyn, addr, ninst, nextop, &ed, x2, x1, &fixedaddress, rex, &lock, 1, 0);
                SMREADLOCK(lock);
                LDxw(gd, ed, fixedaddress);
            }
            break;
        case 0x8D:
            INST_NAME("LEA Gd, Ed");
            nextop = F8;
            GETGD;
            if (MODREG) { // reg <= reg? that's an invalid operation
                DEFAULT;
            } else { // mem <= reg
                addr = geted(dyn, addr, ninst, nextop, &ed, x2, x1, &fixedaddress, rex, NULL, 0, 0);
                MV(gd, ed);
                if (!rex.w || rex.is32bits) {
                    ZEROUP(gd); // truncate the higher 32bits as asked
                }
            }
            break;
        case 0xB8:
        case 0xB9:
        case 0xBA:
        case 0xBB:
        case 0xBC:
        case 0xBD:
        case 0xBE:
        case 0xBF:
            INST_NAME("MOV Reg, Id");
            gd = TO_LA64((opcode & 7) + (rex.b << 3));
            if (rex.w) {
                u64 = F64;
                MOV64x(gd, u64);
            } else {
                u32 = F32;
                MOV32w(gd, u32);
            }
            break;
        case 0xC1:
            nextop = F8;
            switch ((nextop >> 3) & 7) {
                case 5:
                    INST_NAME("SHR Ed, Ib");
                    SETFLAGS(X_ALL, SF_SET_PENDING); // some flags are left undefined
                    GETED(1);
                    u8 = (F8) & (rex.w ? 0x3f : 0x1f);
                    emit_shr32c(dyn, ninst, rex, ed, u8, x3, x4);
                    if (u8) { WBACK; }
                    break;
                case 7:
                    INST_NAME("SAR Ed, Ib");
                    SETFLAGS(X_ALL, SF_SET_PENDING); // some flags are left undefined
                    GETED(1);
                    u8 = (F8) & (rex.w ? 0x3f : 0x1f);
                    emit_sar32c(dyn, ninst, rex, ed, u8, x3, x4);
                    if (u8) { WBACK; }
                    break;
                default:
                    DEFAULT;
            }
            break;
        case 0xC3:
            INST_NAME("RET");
            // SETFLAGS(X_ALL, SF_SET);    // Hack, set all flags (to an unknown state...)
            if (box64_dynarec_safeflags) {
                READFLAGS(X_PEND); // so instead, force the deferred flags, so it's not too slow, and flags are not lost
            }
            BARRIER(BARRIER_FLOAT);
            ret_to_epilog(dyn, ninst, rex);
            *need_epilog = 0;
            *ok = 0;
            break;
        case 0xC6:
            INST_NAME("MOV Eb, Ib");
            nextop = F8;
            if (MODREG) { // reg <= u8
                u8 = F8;
                if (!rex.rex) {
                    ed = (nextop & 7);
                    eb1 = TO_LA64((ed & 3)); // Ax, Cx, Dx or Bx
                    eb2 = (ed & 4) >> 2;   // L or H
                } else {
                    eb1 = TO_LA64((nextop & 7) + (rex.b << 3));
                    eb2 = 0;
                }
                if (eb2) {
                    // load a mask to x3 (ffffffffffff00ff)
                    LU12I_W(x3, 0xffff0);
                    ORI(x3, x3, 0xff);
                    // apply mask
                    AND(eb1, eb1, x3);
                    if (u8) {
                        if ((u8 << 8) < 2048) {
                            ADDI_D(x4, xZR, u8 << 8);
                        } else {
                            ADDI_D(x4, xZR, u8);
                            SLLI_D(x4, x4, 8);
                        }
                        OR(eb1, eb1, x4);
                    }
                } else {
                    ADDI_W(x3, xZR, 0xf00); // mask ffffffffffffff00
                    AND(eb1, eb1, x3);
                    ORI(eb1, eb1, u8);
                }
            } else { // mem <= u8
                addr = geted(dyn, addr, ninst, nextop, &wback, x2, x1, &fixedaddress, rex, &lock, 0, 1);
                u8 = F8;
                if (u8) {
                    ADDI_D(x3, xZR, u8);
                    ed = x3;
                } else
                    ed = xZR;
                ST_B(ed, wback, fixedaddress);
                SMWRITELOCK(lock);
            }
            break;
        case 0xC7:
            INST_NAME("MOV Ed, Id");
            nextop = F8;
            if (MODREG) { // reg <= i32
                i64 = F32S;
                ed = TO_LA64((nextop & 7) + (rex.b << 3));
                MOV64xw(ed, i64);
            } else { // mem <= i32
                addr = geted(dyn, addr, ninst, nextop, &wback, x2, x1, &fixedaddress, rex, &lock, 0, 4);
                i64 = F32S;
                if (i64) {
                    MOV64xw(x3, i64);
                    ed = x3;
                } else
                    ed = xZR;
                SDxw(ed, wback, fixedaddress);
                SMWRITELOCK(lock);
            }
            break;
        case 0xC9:
            INST_NAME("LEAVE");
            MVz(xRSP, xRBP);
            POP1z(xRBP);
            break;
        case 0xCC:
            SETFLAGS(X_ALL, SF_SET);
            SKIPTEST(x1);
            if (PK(0) == 'S' && PK(1) == 'C') {
                addr += 2;
                BARRIER(BARRIER_FLOAT);
                INST_NAME("Special Box64 instruction");
                if (PK64(0) == 0) {
                    addr += 8;
                    MESSAGE(LOG_DEBUG, "Exit x64 Emu\n");
                    MOV64x(x1, 1);
                    ST_W(x1, xEmu, offsetof(x64emu_t, quit));
                    *ok = 0;
                    *need_epilog = 1;
                } else {
                    MESSAGE(LOG_DUMP, "Native Call to %s\n", GetNativeName(GetNativeFnc(ip)));
                    x87_forget(dyn, ninst, x3, x4, 0);
                    sse_purge07cache(dyn, ninst, x3);

                    // FIXME: Even the basic support of isSimpleWrapper is disabled for now.

                    GETIP(ip + 1); // read the 0xCC
                    STORE_XEMU_CALL();
                    ADDI_D(x1, xEmu, (uint32_t)offsetof(x64emu_t, ip)); // setup addr as &emu->ip
                    CALL_S(x64Int3, -1);
                    LOAD_XEMU_CALL();
                    addr += 8 + 8;
                    TABLE64(x3, addr); // expected return address
                    BNE_MARK(xRIP, x3);
                    LD_W(w1, xEmu, offsetof(x64emu_t, quit));
                    CBZ_NEXT(w1);
                    MARK;
                    jump_to_epilog_fast(dyn, 0, xRIP, ninst);
                }
            } else {
                if (!box64_ignoreint3) {
                    INST_NAME("INT 3");
                    // check if TRAP signal is handled
                    LD_D(x1, xEmu, offsetof(x64emu_t, context));
                    MOV64x(x2, offsetof(box64context_t, signals[SIGTRAP]));
                    ADD_D(x2, x2, x1);
                    LD_D(x3, x2, 0);
                    CBZ_NEXT(x3);
                    GETIP(ip);
                    STORE_XEMU_CALL();
                    CALL(native_int3, -1);
                    LOAD_XEMU_CALL();
                }
            }
            break;
        case 0xD1:
            nextop = F8;
            switch ((nextop >> 3) & 7) {
                case 5:
                    INST_NAME("SHR Ed, 1");
                    SETFLAGS(X_ALL, SF_SET_PENDING); // some flags are left undefined
                    GETED(0);
                    emit_shr32c(dyn, ninst, rex, ed, 1, x3, x4);
                    WBACK;
                    break;
                case 7:
                    INST_NAME("SAR Ed, 1");
                    SETFLAGS(X_ALL, SF_SET_PENDING); // some flags are left undefined
                    GETED(0);
                    emit_sar32c(dyn, ninst, rex, ed, 1, x3, x4);
                    WBACK;
                    break;
                default:
                    DEFAULT;
            }
            break;
        case 0xE8:
            INST_NAME("CALL Id");
            i32 = F32S;
            if (addr + i32 == 0) {
                #if STEP == 3
                printf_log(LOG_INFO, "Warning, CALL to 0x0 at %p (%p)\n", (void*)addr, (void*)(addr - 1));
                #endif
            }
            #if STEP < 2
            if (!rex.is32bits && isNativeCall(dyn, addr + i32, &dyn->insts[ninst].natcall, &dyn->insts[ninst].retn))
                tmp = dyn->insts[ninst].pass2choice = 3;
            else
                tmp = dyn->insts[ninst].pass2choice = 0;
            #else
            tmp = dyn->insts[ninst].pass2choice;
            #endif
            switch (tmp) {
                case 3:
                    SETFLAGS(X_ALL, SF_SET); // Hack to set flags to "dont'care" state
                    SKIPTEST(x1);
                    BARRIER(BARRIER_FULL);
                    // BARRIER_NEXT(BARRIER_FULL);
                    if (dyn->last_ip && (addr - dyn->last_ip < 0x1000)) {
                        ADDI_D(x2, xRIP, addr - dyn->last_ip);
                    } else {
                        TABLE64(x2, addr);
                    }
                    PUSH1(x2);
                    MESSAGE(LOG_DUMP, "Native Call to %s (retn=%d)\n", GetNativeName(GetNativeFnc(dyn->insts[ninst].natcall - 1)), dyn->insts[ninst].retn);
                    // calling a native function
                    sse_purge07cache(dyn, ninst, x3);
                    if ((box64_log < 2 && !cycle_log) && dyn->insts[ninst].natcall) {
                        // FIXME: Add basic support for isSimpleWrapper
                        tmp = 0; // isSimpleWrapper(*(wrapper_t*)(dyn->insts[ninst].natcall + 2));
                    } else
                        tmp = 0;
                    if (tmp < 0 || tmp > 1)
                        tmp = 0; // TODO: removed when FP is in place
                    // FIXME: if (dyn->insts[ninst].natcall && isRetX87Wrapper(*(wrapper_t*)(dyn->insts[ninst].natcall + 2)))
                    //     // return value will be on the stack, so the stack depth needs to be updated
                    //     x87_purgecache(dyn, ninst, 0, x3, x1, x4);
                    if ((box64_log < 2 && !cycle_log) && dyn->insts[ninst].natcall && tmp) {
                        // GETIP(ip+3+8+8); // read the 0xCC
                        // FIXME: call_n(dyn, ninst, *(void**)(dyn->insts[ninst].natcall + 2 + 8), tmp);
                        POP1(xRIP); // pop the return address
                        dyn->last_ip = addr;
                    } else {
                        GETIP_(dyn->insts[ninst].natcall); // read the 0xCC already
                        STORE_XEMU_CALL();
                        ADDI_D(x1, xEmu, (uint32_t)offsetof(x64emu_t, ip)); // setup addr as &emu->ip
                        CALL_S(x64Int3, -1);
                        LOAD_XEMU_CALL();
                        TABLE64(x3, dyn->insts[ninst].natcall);
                        ADDI_D(x3, x3, 2 + 8 + 8);
                        BNE_MARK(xRIP, x3); // Not the expected address, exit dynarec block
                        POP1(xRIP);         // pop the return address
                        if (dyn->insts[ninst].retn) {
                            if (dyn->insts[ninst].retn < 0x1000) {
                                ADDI_D(xRSP, xRSP, dyn->insts[ninst].retn);
                            } else {
                                MOV64x(x3, dyn->insts[ninst].retn);
                                ADD_D(xRSP, xRSP, x3);
                            }
                        }
                        TABLE64(x3, addr);
                        BNE_MARK(xRIP, x3); // Not the expected address again
                        LD_W(w1, xEmu, offsetof(x64emu_t, quit));
                        CBZ_NEXT(w1);
                        MARK;
                        jump_to_epilog_fast(dyn, 0, xRIP, ninst);
                        dyn->last_ip = addr;
                    }
                    break;
                default:
                    if ((box64_dynarec_safeflags > 1) || (ninst && dyn->insts[ninst - 1].x64.set_flags)) {
                        READFLAGS(X_PEND); // that's suspicious
                    } else {
                        SETFLAGS(X_ALL, SF_SET); // Hack to set flags to "dont'care" state
                    }
                    // regular call
                    if (box64_dynarec_callret && box64_dynarec_bigblock > 1) {
                        BARRIER(BARRIER_FULL);
                    } else {
                        BARRIER(BARRIER_FLOAT);
                        *need_epilog = 0;
                        *ok = 0;
                    }

                    if (rex.is32bits) {
                        MOV32w(x2, addr);
                    } else {
                        TABLE64(x2, addr);
                    }
                    PUSH1z(x2);
                    if (box64_dynarec_callret) {
                        SET_HASCALLRET();
                        // Push actual return address
                        if (addr < (dyn->start + dyn->isize)) {
                            // there is a next...
                            j64 = (dyn->insts) ? (dyn->insts[ninst].epilog - (dyn->native_size)) : 0;
                            PCADDU12I(x4, ((j64 + 0x800) >> 12) & 0xfffff);
                            ADDI_D(x4, x4, j64 & 0xfff);
                            MESSAGE(LOG_NONE, "\tCALLRET set return to +%di\n", j64 >> 2);
                        } else {
                            MESSAGE(LOG_NONE, "\tCALLRET set return to Jmptable(%p)\n", (void*)addr);
                            j64 = getJumpTableAddress64(addr);
                            TABLE64(x4, j64);
                            LD_D(x4, x4, 0);
                        }
                        ADDI_D(xSP, xSP, -16);
                        ST_D(x4, xSP, 0);
                        ST_D(x2, xSP, 8);
                    } else {
                        *ok = 0;
                        *need_epilog = 0;
                    }
                    jump_to_next(dyn, addr + i32, 0, ninst, rex.is32bits);
                    break;
            }
            break;
        case 0xE9:
        case 0xEB:
            BARRIER(BARRIER_MAYBE);
            if (opcode == 0xE9) {
                INST_NAME("JMP Id");
                i32 = F32S;
            } else {
                INST_NAME("JMP Ib");
                i32 = F8S;
            }
            JUMP((uintptr_t)getAlternate((void*)(addr + i32)), 0);
            if (dyn->insts[ninst].x64.jmp_insts == -1) {
                // out of the block
                fpu_purgecache(dyn, ninst, 1, x1, x2, x3);
                jump_to_next(dyn, (uintptr_t)getAlternate((void*)(addr + i32)), 0, ninst, rex.is32bits);
            } else {
                // inside the block
                CacheTransform(dyn, ninst, CHECK_CACHE(), x1, x2, x3);
                tmp = dyn->insts[dyn->insts[ninst].x64.jmp_insts].address - (dyn->native_size);
                MESSAGE(1, "Jump to %d / 0x%x\n", tmp, tmp);
                if (tmp == 4) {
                    NOP();
                } else {
                    B(tmp);
                }
            }
            *need_epilog = 0;
            *ok = 0;
            break;
        case 0xF7:
            nextop = F8;
            switch ((nextop >> 3) & 7) {
                case 0:
                case 1:
                    INST_NAME("TEST Ed, Id");
                    SETFLAGS(X_ALL, SF_SET_PENDING);
                    GETED(4);
                    i64 = F32S;
                    emit_test32c(dyn, ninst, rex, ed, i64, x3, x4, x5);
                    break;
                default:
                    DEFAULT;
            }
            break;
        case 0xFF:
            nextop = F8;
            switch ((nextop >> 3) & 7) {
                case 2:
                    INST_NAME("CALL Ed");
                    PASS2IF((box64_dynarec_safeflags > 1) || ((ninst && dyn->insts[ninst - 1].x64.set_flags) || ((ninst > 1) && dyn->insts[ninst - 2].x64.set_flags)), 1)
                    {
                        READFLAGS(X_PEND); // that's suspicious
                    }
                    else
                    {
                        SETFLAGS(X_ALL, SF_SET); // Hack to put flag in "don't care" state
                    }
                    GETEDz(0);
                    if (box64_dynarec_callret && box64_dynarec_bigblock > 1) {
                        BARRIER(BARRIER_FULL);
                    } else {
                        BARRIER(BARRIER_FLOAT);
                        *need_epilog = 0;
                        *ok = 0;
                    }
                    GETIP_(addr);
                    if (box64_dynarec_callret) {
                        SET_HASCALLRET();
                        // Push actual return address
                        if (addr < (dyn->start + dyn->isize)) {
                            // there is a next
                            j64 = (dyn->insts) ? (dyn->insts[ninst].epilog - (dyn->native_size)) : 0;
                            PCADDU12I(x4, ((j64 + 0x800) >> 12) & 0xfffff);
                            ADDI_D(x4, x4, j64 & 0xfff);
                            MESSAGE(LOG_NONE, "\tCALLRET set return to +%di\n", j64 >> 2);
                        } else {
                            MESSAGE(LOG_NONE, "\tCALLRET set return to Jmptable(%p)\n", (void*)addr);
                            j64 = getJumpTableAddress64(addr);
                            TABLE64(x4, j64);
                            LD_D(x4, x4, 0);
                        }
                        ADDI_D(xSP, xSP, -16);
                        ST_D(x4, xSP, 0);
                        ST_D(xRIP, xSP, 8);
                    }
                    PUSH1z(xRIP);
                    jump_to_next(dyn, 0, ed, ninst, rex.is32bits);
                    break;
                case 4: // JMP Ed
                    INST_NAME("JMP Ed");
                    READFLAGS(X_PEND);
                    BARRIER(BARRIER_FLOAT);
                    GETEDz(0);
                    jump_to_next(dyn, 0, ed, ninst, rex.is32bits);
                    *need_epilog = 0;
                    *ok = 0;
                    break;
                case 6: // Push Ed
                    INST_NAME("PUSH Ed");
                    GETEDz(0);
                    PUSH1z(ed);
                    break;
                
                default:
                    DEFAULT;
            }
            break;
        default:
            DEFAULT;
    }

    return addr;
}