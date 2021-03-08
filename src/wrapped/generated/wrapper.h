/*****************************************************************
 * File automatically generated by rebuild_wrappers.py (v1.2.0.09)
 *****************************************************************/
#ifndef __WRAPPER_H_
#define __WRAPPER_H_
#include <stdint.h>
#include <string.h>

typedef struct x64emu_s x64emu_t;

// the generic wrapper pointer functions
typedef void (*wrapper_t)(x64emu_t* emu, uintptr_t fnc);

// list of defined wrapper
// v = void, i = int32, u = uint32, U/I= (u)int64
// l = signed long, L = unsigned long (long is an int with the size of a pointer)
// p = pointer, P = callback
// f = float, d = double, D = long double, K = fake long double
// V = vaargs, E = current x86emu struct, e = ref to current x86emu struct
// 0 = constant 0, 1 = constant 1
// o = stdout
// C = unsigned byte c = char
// W = unsigned short w = short
// O = libc O_ flags bitfield
// S = _IO_2_1_stdXXX_ pointer (or FILE*)
// Q = ...
// N = ... automatically sending 1 arg
// M = ... automatically sending 2 args
// H = Huge 128bits value/struct

void vFE(x64emu_t *emu, uintptr_t fnc);
void vFv(x64emu_t *emu, uintptr_t fnc);
void vFi(x64emu_t *emu, uintptr_t fnc);
void vFu(x64emu_t *emu, uintptr_t fnc);
void vFf(x64emu_t *emu, uintptr_t fnc);
void vFd(x64emu_t *emu, uintptr_t fnc);
void vFp(x64emu_t *emu, uintptr_t fnc);
void cFi(x64emu_t *emu, uintptr_t fnc);
void cFu(x64emu_t *emu, uintptr_t fnc);
void cFp(x64emu_t *emu, uintptr_t fnc);
void wFp(x64emu_t *emu, uintptr_t fnc);
void iFE(x64emu_t *emu, uintptr_t fnc);
void iFv(x64emu_t *emu, uintptr_t fnc);
void iFi(x64emu_t *emu, uintptr_t fnc);
void iFu(x64emu_t *emu, uintptr_t fnc);
void iFf(x64emu_t *emu, uintptr_t fnc);
void iFd(x64emu_t *emu, uintptr_t fnc);
void iFL(x64emu_t *emu, uintptr_t fnc);
void iFp(x64emu_t *emu, uintptr_t fnc);
void IFf(x64emu_t *emu, uintptr_t fnc);
void IFd(x64emu_t *emu, uintptr_t fnc);
void IFp(x64emu_t *emu, uintptr_t fnc);
void WFi(x64emu_t *emu, uintptr_t fnc);
void WFp(x64emu_t *emu, uintptr_t fnc);
void uFv(x64emu_t *emu, uintptr_t fnc);
void uFi(x64emu_t *emu, uintptr_t fnc);
void uFu(x64emu_t *emu, uintptr_t fnc);
void uFp(x64emu_t *emu, uintptr_t fnc);
void UFv(x64emu_t *emu, uintptr_t fnc);
void UFV(x64emu_t *emu, uintptr_t fnc);
void fFi(x64emu_t *emu, uintptr_t fnc);
void fFf(x64emu_t *emu, uintptr_t fnc);
void fFp(x64emu_t *emu, uintptr_t fnc);
void dFi(x64emu_t *emu, uintptr_t fnc);
void dFd(x64emu_t *emu, uintptr_t fnc);
void dFp(x64emu_t *emu, uintptr_t fnc);
void lFp(x64emu_t *emu, uintptr_t fnc);
void LFv(x64emu_t *emu, uintptr_t fnc);
void LFp(x64emu_t *emu, uintptr_t fnc);
void pFE(x64emu_t *emu, uintptr_t fnc);
void pFv(x64emu_t *emu, uintptr_t fnc);
void pFi(x64emu_t *emu, uintptr_t fnc);
void pFu(x64emu_t *emu, uintptr_t fnc);
void pFL(x64emu_t *emu, uintptr_t fnc);
void pFp(x64emu_t *emu, uintptr_t fnc);
void HFi(x64emu_t *emu, uintptr_t fnc);
void HFp(x64emu_t *emu, uintptr_t fnc);
void vFEp(x64emu_t *emu, uintptr_t fnc);
void vFii(x64emu_t *emu, uintptr_t fnc);
void vFiu(x64emu_t *emu, uintptr_t fnc);
void vFif(x64emu_t *emu, uintptr_t fnc);
void vFid(x64emu_t *emu, uintptr_t fnc);
void vFip(x64emu_t *emu, uintptr_t fnc);
void vFWW(x64emu_t *emu, uintptr_t fnc);
void vFui(x64emu_t *emu, uintptr_t fnc);
void vFuu(x64emu_t *emu, uintptr_t fnc);
void vFuf(x64emu_t *emu, uintptr_t fnc);
void vFud(x64emu_t *emu, uintptr_t fnc);
void vFup(x64emu_t *emu, uintptr_t fnc);
void vFfi(x64emu_t *emu, uintptr_t fnc);
void vFff(x64emu_t *emu, uintptr_t fnc);
void vFfp(x64emu_t *emu, uintptr_t fnc);
void vFdd(x64emu_t *emu, uintptr_t fnc);
void vFpi(x64emu_t *emu, uintptr_t fnc);
void vFpu(x64emu_t *emu, uintptr_t fnc);
void vFpL(x64emu_t *emu, uintptr_t fnc);
void vFpp(x64emu_t *emu, uintptr_t fnc);
void cFpp(x64emu_t *emu, uintptr_t fnc);
void iFEp(x64emu_t *emu, uintptr_t fnc);
void iFii(x64emu_t *emu, uintptr_t fnc);
void iFip(x64emu_t *emu, uintptr_t fnc);
void iFIi(x64emu_t *emu, uintptr_t fnc);
void iFui(x64emu_t *emu, uintptr_t fnc);
void iFuu(x64emu_t *emu, uintptr_t fnc);
void iFup(x64emu_t *emu, uintptr_t fnc);
void iFUU(x64emu_t *emu, uintptr_t fnc);
void iFLL(x64emu_t *emu, uintptr_t fnc);
void iFLp(x64emu_t *emu, uintptr_t fnc);
void iFpw(x64emu_t *emu, uintptr_t fnc);
void iFpi(x64emu_t *emu, uintptr_t fnc);
void iFpI(x64emu_t *emu, uintptr_t fnc);
void iFpC(x64emu_t *emu, uintptr_t fnc);
void iFpu(x64emu_t *emu, uintptr_t fnc);
void iFpf(x64emu_t *emu, uintptr_t fnc);
void iFpd(x64emu_t *emu, uintptr_t fnc);
void iFpl(x64emu_t *emu, uintptr_t fnc);
void iFpL(x64emu_t *emu, uintptr_t fnc);
void iFpp(x64emu_t *emu, uintptr_t fnc);
void IFEp(x64emu_t *emu, uintptr_t fnc);
void IFpu(x64emu_t *emu, uintptr_t fnc);
void CFui(x64emu_t *emu, uintptr_t fnc);
void CFpi(x64emu_t *emu, uintptr_t fnc);
void CFpu(x64emu_t *emu, uintptr_t fnc);
void uFEp(x64emu_t *emu, uintptr_t fnc);
void uFiu(x64emu_t *emu, uintptr_t fnc);
void uFui(x64emu_t *emu, uintptr_t fnc);
void uFuu(x64emu_t *emu, uintptr_t fnc);
void uFup(x64emu_t *emu, uintptr_t fnc);
void uFpi(x64emu_t *emu, uintptr_t fnc);
void uFpu(x64emu_t *emu, uintptr_t fnc);
void uFpU(x64emu_t *emu, uintptr_t fnc);
void uFpp(x64emu_t *emu, uintptr_t fnc);
void UFEp(x64emu_t *emu, uintptr_t fnc);
void fFif(x64emu_t *emu, uintptr_t fnc);
void fFfi(x64emu_t *emu, uintptr_t fnc);
void fFff(x64emu_t *emu, uintptr_t fnc);
void fFfp(x64emu_t *emu, uintptr_t fnc);
void dFid(x64emu_t *emu, uintptr_t fnc);
void dFdi(x64emu_t *emu, uintptr_t fnc);
void dFdd(x64emu_t *emu, uintptr_t fnc);
void dFdp(x64emu_t *emu, uintptr_t fnc);
void dFpp(x64emu_t *emu, uintptr_t fnc);
void LFpi(x64emu_t *emu, uintptr_t fnc);
void LFpL(x64emu_t *emu, uintptr_t fnc);
void LFpp(x64emu_t *emu, uintptr_t fnc);
void pFEp(x64emu_t *emu, uintptr_t fnc);
void pFii(x64emu_t *emu, uintptr_t fnc);
void pFip(x64emu_t *emu, uintptr_t fnc);
void pFui(x64emu_t *emu, uintptr_t fnc);
void pFuu(x64emu_t *emu, uintptr_t fnc);
void pFup(x64emu_t *emu, uintptr_t fnc);
void pFlp(x64emu_t *emu, uintptr_t fnc);
void pFLL(x64emu_t *emu, uintptr_t fnc);
void pFpi(x64emu_t *emu, uintptr_t fnc);
void pFpC(x64emu_t *emu, uintptr_t fnc);
void pFpu(x64emu_t *emu, uintptr_t fnc);
void pFpL(x64emu_t *emu, uintptr_t fnc);
void pFpp(x64emu_t *emu, uintptr_t fnc);
void pFpV(x64emu_t *emu, uintptr_t fnc);
void HFpi(x64emu_t *emu, uintptr_t fnc);
void vFEpu(x64emu_t *emu, uintptr_t fnc);
void vFEpp(x64emu_t *emu, uintptr_t fnc);
void vFEpV(x64emu_t *emu, uintptr_t fnc);
void vFiii(x64emu_t *emu, uintptr_t fnc);
void vFiip(x64emu_t *emu, uintptr_t fnc);
void vFiui(x64emu_t *emu, uintptr_t fnc);
void vFiuu(x64emu_t *emu, uintptr_t fnc);
void vFiup(x64emu_t *emu, uintptr_t fnc);
void vFiff(x64emu_t *emu, uintptr_t fnc);
void vFidd(x64emu_t *emu, uintptr_t fnc);
void vFipi(x64emu_t *emu, uintptr_t fnc);
void vFipu(x64emu_t *emu, uintptr_t fnc);
void vFipp(x64emu_t *emu, uintptr_t fnc);
void vFuii(x64emu_t *emu, uintptr_t fnc);
void vFuiI(x64emu_t *emu, uintptr_t fnc);
void vFuiu(x64emu_t *emu, uintptr_t fnc);
void vFuif(x64emu_t *emu, uintptr_t fnc);
void vFuid(x64emu_t *emu, uintptr_t fnc);
void vFuip(x64emu_t *emu, uintptr_t fnc);
void vFuui(x64emu_t *emu, uintptr_t fnc);
void vFuuu(x64emu_t *emu, uintptr_t fnc);
void vFuuf(x64emu_t *emu, uintptr_t fnc);
void vFuud(x64emu_t *emu, uintptr_t fnc);
void vFuup(x64emu_t *emu, uintptr_t fnc);
void vFuff(x64emu_t *emu, uintptr_t fnc);
void vFudd(x64emu_t *emu, uintptr_t fnc);
void vFupi(x64emu_t *emu, uintptr_t fnc);
void vFfff(x64emu_t *emu, uintptr_t fnc);
void vFfpp(x64emu_t *emu, uintptr_t fnc);
void vFddd(x64emu_t *emu, uintptr_t fnc);
void vFdpp(x64emu_t *emu, uintptr_t fnc);
void vFLpp(x64emu_t *emu, uintptr_t fnc);
void vFpii(x64emu_t *emu, uintptr_t fnc);
void vFpiu(x64emu_t *emu, uintptr_t fnc);
void vFpif(x64emu_t *emu, uintptr_t fnc);
void vFpid(x64emu_t *emu, uintptr_t fnc);
void vFpip(x64emu_t *emu, uintptr_t fnc);
void vFpui(x64emu_t *emu, uintptr_t fnc);
void vFpuI(x64emu_t *emu, uintptr_t fnc);
void vFpuu(x64emu_t *emu, uintptr_t fnc);
void vFpup(x64emu_t *emu, uintptr_t fnc);
void vFppi(x64emu_t *emu, uintptr_t fnc);
void vFppu(x64emu_t *emu, uintptr_t fnc);
void vFppp(x64emu_t *emu, uintptr_t fnc);
void iFEip(x64emu_t *emu, uintptr_t fnc);
void iFEWW(x64emu_t *emu, uintptr_t fnc);
void iFEup(x64emu_t *emu, uintptr_t fnc);
void iFEpi(x64emu_t *emu, uintptr_t fnc);
void iFEpp(x64emu_t *emu, uintptr_t fnc);
void iFEpV(x64emu_t *emu, uintptr_t fnc);
void iFiip(x64emu_t *emu, uintptr_t fnc);
void iFipu(x64emu_t *emu, uintptr_t fnc);
void iFipp(x64emu_t *emu, uintptr_t fnc);
void iFuup(x64emu_t *emu, uintptr_t fnc);
void iFuff(x64emu_t *emu, uintptr_t fnc);
void iFfff(x64emu_t *emu, uintptr_t fnc);
void iFpii(x64emu_t *emu, uintptr_t fnc);
void iFpiu(x64emu_t *emu, uintptr_t fnc);
void iFpiL(x64emu_t *emu, uintptr_t fnc);
void iFpip(x64emu_t *emu, uintptr_t fnc);
void iFpui(x64emu_t *emu, uintptr_t fnc);
void iFpuu(x64emu_t *emu, uintptr_t fnc);
void iFpuU(x64emu_t *emu, uintptr_t fnc);
void iFpuL(x64emu_t *emu, uintptr_t fnc);
void iFpup(x64emu_t *emu, uintptr_t fnc);
void iFpfu(x64emu_t *emu, uintptr_t fnc);
void iFpff(x64emu_t *emu, uintptr_t fnc);
void iFplp(x64emu_t *emu, uintptr_t fnc);
void iFpLp(x64emu_t *emu, uintptr_t fnc);
void iFppi(x64emu_t *emu, uintptr_t fnc);
void iFppI(x64emu_t *emu, uintptr_t fnc);
void iFppu(x64emu_t *emu, uintptr_t fnc);
void iFppd(x64emu_t *emu, uintptr_t fnc);
void iFppL(x64emu_t *emu, uintptr_t fnc);
void iFppp(x64emu_t *emu, uintptr_t fnc);
void IFpIi(x64emu_t *emu, uintptr_t fnc);
void IFppi(x64emu_t *emu, uintptr_t fnc);
void uFEpW(x64emu_t *emu, uintptr_t fnc);
void uFEpu(x64emu_t *emu, uintptr_t fnc);
void uFEpU(x64emu_t *emu, uintptr_t fnc);
void uFipu(x64emu_t *emu, uintptr_t fnc);
void uFuip(x64emu_t *emu, uintptr_t fnc);
void uFuuu(x64emu_t *emu, uintptr_t fnc);
void uFuup(x64emu_t *emu, uintptr_t fnc);
void uFupu(x64emu_t *emu, uintptr_t fnc);
void uFupp(x64emu_t *emu, uintptr_t fnc);
void uFpiu(x64emu_t *emu, uintptr_t fnc);
void uFpip(x64emu_t *emu, uintptr_t fnc);
void uFpLp(x64emu_t *emu, uintptr_t fnc);
void uFppi(x64emu_t *emu, uintptr_t fnc);
void uFppu(x64emu_t *emu, uintptr_t fnc);
void UFppi(x64emu_t *emu, uintptr_t fnc);
void fFuii(x64emu_t *emu, uintptr_t fnc);
void fFfff(x64emu_t *emu, uintptr_t fnc);
void fFffp(x64emu_t *emu, uintptr_t fnc);
void dFddd(x64emu_t *emu, uintptr_t fnc);
void dFddp(x64emu_t *emu, uintptr_t fnc);
void LFpii(x64emu_t *emu, uintptr_t fnc);
void pFEip(x64emu_t *emu, uintptr_t fnc);
void pFEpi(x64emu_t *emu, uintptr_t fnc);
void pFEpp(x64emu_t *emu, uintptr_t fnc);
void pFipi(x64emu_t *emu, uintptr_t fnc);
void pFipp(x64emu_t *emu, uintptr_t fnc);
void pFIpi(x64emu_t *emu, uintptr_t fnc);
void pFuii(x64emu_t *emu, uintptr_t fnc);
void pFupi(x64emu_t *emu, uintptr_t fnc);
void pFUpi(x64emu_t *emu, uintptr_t fnc);
void pFpii(x64emu_t *emu, uintptr_t fnc);
void pFpiu(x64emu_t *emu, uintptr_t fnc);
void pFpiL(x64emu_t *emu, uintptr_t fnc);
void pFpip(x64emu_t *emu, uintptr_t fnc);
void pFpCC(x64emu_t *emu, uintptr_t fnc);
void pFpuu(x64emu_t *emu, uintptr_t fnc);
void pFpuL(x64emu_t *emu, uintptr_t fnc);
void pFpup(x64emu_t *emu, uintptr_t fnc);
void pFpUp(x64emu_t *emu, uintptr_t fnc);
void pFppi(x64emu_t *emu, uintptr_t fnc);
void pFppu(x64emu_t *emu, uintptr_t fnc);
void pFppL(x64emu_t *emu, uintptr_t fnc);
void pFppp(x64emu_t *emu, uintptr_t fnc);
void vFEipV(x64emu_t *emu, uintptr_t fnc);
void vFEpip(x64emu_t *emu, uintptr_t fnc);
void vFEpup(x64emu_t *emu, uintptr_t fnc);
void vFiiii(x64emu_t *emu, uintptr_t fnc);
void vFiiip(x64emu_t *emu, uintptr_t fnc);
void vFiuip(x64emu_t *emu, uintptr_t fnc);
void vFiuuu(x64emu_t *emu, uintptr_t fnc);
void vFiupu(x64emu_t *emu, uintptr_t fnc);
void vFiupV(x64emu_t *emu, uintptr_t fnc);
void vFifff(x64emu_t *emu, uintptr_t fnc);
void vFiddd(x64emu_t *emu, uintptr_t fnc);
void vFipup(x64emu_t *emu, uintptr_t fnc);
void vFippp(x64emu_t *emu, uintptr_t fnc);
void vFuiii(x64emu_t *emu, uintptr_t fnc);
void vFuiip(x64emu_t *emu, uintptr_t fnc);
void vFuiui(x64emu_t *emu, uintptr_t fnc);
void vFuiuu(x64emu_t *emu, uintptr_t fnc);
void vFuiup(x64emu_t *emu, uintptr_t fnc);
void vFuifi(x64emu_t *emu, uintptr_t fnc);
void vFuiff(x64emu_t *emu, uintptr_t fnc);
void vFuidd(x64emu_t *emu, uintptr_t fnc);
void vFuipi(x64emu_t *emu, uintptr_t fnc);
void vFuipu(x64emu_t *emu, uintptr_t fnc);
void vFuipp(x64emu_t *emu, uintptr_t fnc);
void vFuuii(x64emu_t *emu, uintptr_t fnc);
void vFuuiu(x64emu_t *emu, uintptr_t fnc);
void vFuuip(x64emu_t *emu, uintptr_t fnc);
void vFuuui(x64emu_t *emu, uintptr_t fnc);
void vFuuuu(x64emu_t *emu, uintptr_t fnc);
void vFuuuf(x64emu_t *emu, uintptr_t fnc);
void vFuuud(x64emu_t *emu, uintptr_t fnc);
void vFuuup(x64emu_t *emu, uintptr_t fnc);
void vFuupi(x64emu_t *emu, uintptr_t fnc);
void vFuupp(x64emu_t *emu, uintptr_t fnc);
void vFufff(x64emu_t *emu, uintptr_t fnc);
void vFuddd(x64emu_t *emu, uintptr_t fnc);
void vFupii(x64emu_t *emu, uintptr_t fnc);
void vFuppi(x64emu_t *emu, uintptr_t fnc);
void vFffff(x64emu_t *emu, uintptr_t fnc);
void vFdddd(x64emu_t *emu, uintptr_t fnc);
void vFpiii(x64emu_t *emu, uintptr_t fnc);
void vFpiip(x64emu_t *emu, uintptr_t fnc);
void vFpipp(x64emu_t *emu, uintptr_t fnc);
void vFpupp(x64emu_t *emu, uintptr_t fnc);
void vFpdii(x64emu_t *emu, uintptr_t fnc);
void vFpddd(x64emu_t *emu, uintptr_t fnc);
void vFppip(x64emu_t *emu, uintptr_t fnc);
void vFppui(x64emu_t *emu, uintptr_t fnc);
void vFppup(x64emu_t *emu, uintptr_t fnc);
void vFpppi(x64emu_t *emu, uintptr_t fnc);
void vFpppu(x64emu_t *emu, uintptr_t fnc);
void vFpppp(x64emu_t *emu, uintptr_t fnc);
void cFpiii(x64emu_t *emu, uintptr_t fnc);
void iFEipp(x64emu_t *emu, uintptr_t fnc);
void iFEupp(x64emu_t *emu, uintptr_t fnc);
void iFEpip(x64emu_t *emu, uintptr_t fnc);
void iFEppi(x64emu_t *emu, uintptr_t fnc);
void iFEppp(x64emu_t *emu, uintptr_t fnc);
void iFEppV(x64emu_t *emu, uintptr_t fnc);
void iFiiii(x64emu_t *emu, uintptr_t fnc);
void iFiiiu(x64emu_t *emu, uintptr_t fnc);
void iFippi(x64emu_t *emu, uintptr_t fnc);
void iFippp(x64emu_t *emu, uintptr_t fnc);
void iFuipp(x64emu_t *emu, uintptr_t fnc);
void iFuuff(x64emu_t *emu, uintptr_t fnc);
void iFuppp(x64emu_t *emu, uintptr_t fnc);
void iFpiii(x64emu_t *emu, uintptr_t fnc);
void iFpiiu(x64emu_t *emu, uintptr_t fnc);
void iFpiiL(x64emu_t *emu, uintptr_t fnc);
void iFpiip(x64emu_t *emu, uintptr_t fnc);
void iFpiup(x64emu_t *emu, uintptr_t fnc);
void iFpipi(x64emu_t *emu, uintptr_t fnc);
void iFpipp(x64emu_t *emu, uintptr_t fnc);
void iFpCCC(x64emu_t *emu, uintptr_t fnc);
void iFpWWu(x64emu_t *emu, uintptr_t fnc);
void iFpuip(x64emu_t *emu, uintptr_t fnc);
void iFpuui(x64emu_t *emu, uintptr_t fnc);
void iFpuuu(x64emu_t *emu, uintptr_t fnc);
void iFpuup(x64emu_t *emu, uintptr_t fnc);
void iFpuLL(x64emu_t *emu, uintptr_t fnc);
void iFpuLp(x64emu_t *emu, uintptr_t fnc);
void iFpupV(x64emu_t *emu, uintptr_t fnc);
void iFppii(x64emu_t *emu, uintptr_t fnc);
void iFppiu(x64emu_t *emu, uintptr_t fnc);
void iFppiL(x64emu_t *emu, uintptr_t fnc);
void iFppip(x64emu_t *emu, uintptr_t fnc);
void iFppuw(x64emu_t *emu, uintptr_t fnc);
void iFppui(x64emu_t *emu, uintptr_t fnc);
void iFppuu(x64emu_t *emu, uintptr_t fnc);
void iFppup(x64emu_t *emu, uintptr_t fnc);
void iFpplp(x64emu_t *emu, uintptr_t fnc);
void iFppLp(x64emu_t *emu, uintptr_t fnc);
void iFpppi(x64emu_t *emu, uintptr_t fnc);
void iFpppu(x64emu_t *emu, uintptr_t fnc);
void iFpppL(x64emu_t *emu, uintptr_t fnc);
void iFpppp(x64emu_t *emu, uintptr_t fnc);
void IFEpIi(x64emu_t *emu, uintptr_t fnc);
void uFuuuu(x64emu_t *emu, uintptr_t fnc);
void uFpipp(x64emu_t *emu, uintptr_t fnc);
void uFpCCC(x64emu_t *emu, uintptr_t fnc);
void uFpuip(x64emu_t *emu, uintptr_t fnc);
void uFpuuu(x64emu_t *emu, uintptr_t fnc);
void uFpppi(x64emu_t *emu, uintptr_t fnc);
void uFpppp(x64emu_t *emu, uintptr_t fnc);
void UFpipp(x64emu_t *emu, uintptr_t fnc);
void LFpuuu(x64emu_t *emu, uintptr_t fnc);
void LFpLLp(x64emu_t *emu, uintptr_t fnc);
void pFEupp(x64emu_t *emu, uintptr_t fnc);
void pFEpip(x64emu_t *emu, uintptr_t fnc);
void pFEppi(x64emu_t *emu, uintptr_t fnc);
void pFEppp(x64emu_t *emu, uintptr_t fnc);
void pFiiiu(x64emu_t *emu, uintptr_t fnc);
void pFiiup(x64emu_t *emu, uintptr_t fnc);
void pFuiii(x64emu_t *emu, uintptr_t fnc);
void pFpiii(x64emu_t *emu, uintptr_t fnc);
void pFpiip(x64emu_t *emu, uintptr_t fnc);
void pFpiuu(x64emu_t *emu, uintptr_t fnc);
void pFpipp(x64emu_t *emu, uintptr_t fnc);
void pFpCWp(x64emu_t *emu, uintptr_t fnc);
void pFpCuW(x64emu_t *emu, uintptr_t fnc);
void pFpCuu(x64emu_t *emu, uintptr_t fnc);
void pFpuii(x64emu_t *emu, uintptr_t fnc);
void pFpuWp(x64emu_t *emu, uintptr_t fnc);
void pFpuuu(x64emu_t *emu, uintptr_t fnc);
void pFpuup(x64emu_t *emu, uintptr_t fnc);
void pFpupi(x64emu_t *emu, uintptr_t fnc);
void pFplpp(x64emu_t *emu, uintptr_t fnc);
void pFppii(x64emu_t *emu, uintptr_t fnc);
void pFppiL(x64emu_t *emu, uintptr_t fnc);
void pFppip(x64emu_t *emu, uintptr_t fnc);
void pFppuL(x64emu_t *emu, uintptr_t fnc);
void pFppup(x64emu_t *emu, uintptr_t fnc);
void pFppLL(x64emu_t *emu, uintptr_t fnc);
void pFpppi(x64emu_t *emu, uintptr_t fnc);
void pFpppu(x64emu_t *emu, uintptr_t fnc);
void pFpppL(x64emu_t *emu, uintptr_t fnc);
void pFpppp(x64emu_t *emu, uintptr_t fnc);
void vFEpuup(x64emu_t *emu, uintptr_t fnc);
void vFiiiii(x64emu_t *emu, uintptr_t fnc);
void vFiiiiu(x64emu_t *emu, uintptr_t fnc);
void vFiiuup(x64emu_t *emu, uintptr_t fnc);
void vFiipii(x64emu_t *emu, uintptr_t fnc);
void vFiuiip(x64emu_t *emu, uintptr_t fnc);
void vFiuipi(x64emu_t *emu, uintptr_t fnc);
void vFiuuuu(x64emu_t *emu, uintptr_t fnc);
void vFiffff(x64emu_t *emu, uintptr_t fnc);
void vFidddd(x64emu_t *emu, uintptr_t fnc);
void vFilill(x64emu_t *emu, uintptr_t fnc);
void vFipipu(x64emu_t *emu, uintptr_t fnc);
void vFipipp(x64emu_t *emu, uintptr_t fnc);
void vFipupi(x64emu_t *emu, uintptr_t fnc);
void vFuiiii(x64emu_t *emu, uintptr_t fnc);
void vFuiiiu(x64emu_t *emu, uintptr_t fnc);
void vFuiiip(x64emu_t *emu, uintptr_t fnc);
void vFuiiup(x64emu_t *emu, uintptr_t fnc);
void vFuiIII(x64emu_t *emu, uintptr_t fnc);
void vFuiuii(x64emu_t *emu, uintptr_t fnc);
void vFuiuiu(x64emu_t *emu, uintptr_t fnc);
void vFuiuip(x64emu_t *emu, uintptr_t fnc);
void vFuiuuu(x64emu_t *emu, uintptr_t fnc);
void vFuiuup(x64emu_t *emu, uintptr_t fnc);
void vFuiupi(x64emu_t *emu, uintptr_t fnc);
void vFuiupu(x64emu_t *emu, uintptr_t fnc);
void vFuifff(x64emu_t *emu, uintptr_t fnc);
void vFuiddd(x64emu_t *emu, uintptr_t fnc);
void vFuipii(x64emu_t *emu, uintptr_t fnc);
void vFuipip(x64emu_t *emu, uintptr_t fnc);
void vFuipup(x64emu_t *emu, uintptr_t fnc);
void vFuippp(x64emu_t *emu, uintptr_t fnc);
void vFuuiii(x64emu_t *emu, uintptr_t fnc);
void vFuuiui(x64emu_t *emu, uintptr_t fnc);
void vFuuiuu(x64emu_t *emu, uintptr_t fnc);
void vFuuiup(x64emu_t *emu, uintptr_t fnc);
void vFuuipi(x64emu_t *emu, uintptr_t fnc);
void vFuuipu(x64emu_t *emu, uintptr_t fnc);
void vFuuipp(x64emu_t *emu, uintptr_t fnc);
void vFuuuii(x64emu_t *emu, uintptr_t fnc);
void vFuuuiu(x64emu_t *emu, uintptr_t fnc);
void vFuuuip(x64emu_t *emu, uintptr_t fnc);
void vFuuuui(x64emu_t *emu, uintptr_t fnc);
void vFuuuuu(x64emu_t *emu, uintptr_t fnc);
void vFuuuup(x64emu_t *emu, uintptr_t fnc);
void vFuupii(x64emu_t *emu, uintptr_t fnc);
void vFuffff(x64emu_t *emu, uintptr_t fnc);
void vFudddd(x64emu_t *emu, uintptr_t fnc);
void vFupupi(x64emu_t *emu, uintptr_t fnc);
void vFuppip(x64emu_t *emu, uintptr_t fnc);
void vFupppp(x64emu_t *emu, uintptr_t fnc);
void vFfffff(x64emu_t *emu, uintptr_t fnc);
void vFddddp(x64emu_t *emu, uintptr_t fnc);
void vFpiiii(x64emu_t *emu, uintptr_t fnc);
void vFpipii(x64emu_t *emu, uintptr_t fnc);
void vFpuipp(x64emu_t *emu, uintptr_t fnc);
void vFpddii(x64emu_t *emu, uintptr_t fnc);
void vFppiii(x64emu_t *emu, uintptr_t fnc);
void vFppWui(x64emu_t *emu, uintptr_t fnc);
void vFpppii(x64emu_t *emu, uintptr_t fnc);
void vFppppi(x64emu_t *emu, uintptr_t fnc);
void vFppppp(x64emu_t *emu, uintptr_t fnc);
void iFEpipp(x64emu_t *emu, uintptr_t fnc);
void iFEppiV(x64emu_t *emu, uintptr_t fnc);
void iFEpppp(x64emu_t *emu, uintptr_t fnc);
void iFiiupp(x64emu_t *emu, uintptr_t fnc);
void iFipppi(x64emu_t *emu, uintptr_t fnc);
void iFpiiii(x64emu_t *emu, uintptr_t fnc);
void iFpiiip(x64emu_t *emu, uintptr_t fnc);
void iFpiiuu(x64emu_t *emu, uintptr_t fnc);
void iFpiipi(x64emu_t *emu, uintptr_t fnc);
void iFpiipp(x64emu_t *emu, uintptr_t fnc);
void iFpipii(x64emu_t *emu, uintptr_t fnc);
void iFpippp(x64emu_t *emu, uintptr_t fnc);
void iFpCCCC(x64emu_t *emu, uintptr_t fnc);
void iFpuuui(x64emu_t *emu, uintptr_t fnc);
void iFpuuLL(x64emu_t *emu, uintptr_t fnc);
void iFpuupp(x64emu_t *emu, uintptr_t fnc);
void iFppiip(x64emu_t *emu, uintptr_t fnc);
void iFppiup(x64emu_t *emu, uintptr_t fnc);
void iFppipi(x64emu_t *emu, uintptr_t fnc);
void iFppipp(x64emu_t *emu, uintptr_t fnc);
void iFppupi(x64emu_t *emu, uintptr_t fnc);
void iFpppii(x64emu_t *emu, uintptr_t fnc);
void iFpppiL(x64emu_t *emu, uintptr_t fnc);
void iFpppip(x64emu_t *emu, uintptr_t fnc);
void iFppppi(x64emu_t *emu, uintptr_t fnc);
void iFppppp(x64emu_t *emu, uintptr_t fnc);
void IFppIII(x64emu_t *emu, uintptr_t fnc);
void uFEppuu(x64emu_t *emu, uintptr_t fnc);
void uFiuuuu(x64emu_t *emu, uintptr_t fnc);
void uFuiiiu(x64emu_t *emu, uintptr_t fnc);
void uFpCCCC(x64emu_t *emu, uintptr_t fnc);
void uFpuuuu(x64emu_t *emu, uintptr_t fnc);
void uFppiip(x64emu_t *emu, uintptr_t fnc);
void uFppppp(x64emu_t *emu, uintptr_t fnc);
void LFppppp(x64emu_t *emu, uintptr_t fnc);
void pFEpipL(x64emu_t *emu, uintptr_t fnc);
void pFuiiiu(x64emu_t *emu, uintptr_t fnc);
void pFuiipp(x64emu_t *emu, uintptr_t fnc);
void pFpiiuu(x64emu_t *emu, uintptr_t fnc);
void pFpCuup(x64emu_t *emu, uintptr_t fnc);
void pFpCppp(x64emu_t *emu, uintptr_t fnc);
void pFpuiii(x64emu_t *emu, uintptr_t fnc);
void pFpuWWW(x64emu_t *emu, uintptr_t fnc);
void pFpuuWW(x64emu_t *emu, uintptr_t fnc);
void pFpuuup(x64emu_t *emu, uintptr_t fnc);
void pFppipi(x64emu_t *emu, uintptr_t fnc);
void pFppipp(x64emu_t *emu, uintptr_t fnc);
void pFppuuu(x64emu_t *emu, uintptr_t fnc);
void pFppuup(x64emu_t *emu, uintptr_t fnc);
void pFppLLp(x64emu_t *emu, uintptr_t fnc);
void pFpppip(x64emu_t *emu, uintptr_t fnc);
void pFpppuu(x64emu_t *emu, uintptr_t fnc);
void pFpppup(x64emu_t *emu, uintptr_t fnc);
void pFppppi(x64emu_t *emu, uintptr_t fnc);
void pFppppp(x64emu_t *emu, uintptr_t fnc);
void vFEiiipp(x64emu_t *emu, uintptr_t fnc);
void vFiiiiii(x64emu_t *emu, uintptr_t fnc);
void vFiiiuil(x64emu_t *emu, uintptr_t fnc);
void vFiuippp(x64emu_t *emu, uintptr_t fnc);
void vFiffiff(x64emu_t *emu, uintptr_t fnc);
void vFiddidd(x64emu_t *emu, uintptr_t fnc);
void vFuiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuiiiip(x64emu_t *emu, uintptr_t fnc);
void vFuiiuii(x64emu_t *emu, uintptr_t fnc);
void vFuiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuiuiii(x64emu_t *emu, uintptr_t fnc);
void vFuiuiip(x64emu_t *emu, uintptr_t fnc);
void vFuiuiuu(x64emu_t *emu, uintptr_t fnc);
void vFuiuuip(x64emu_t *emu, uintptr_t fnc);
void vFuiuuuu(x64emu_t *emu, uintptr_t fnc);
void vFuiupii(x64emu_t *emu, uintptr_t fnc);
void vFuiupiu(x64emu_t *emu, uintptr_t fnc);
void vFuiffff(x64emu_t *emu, uintptr_t fnc);
void vFuidddd(x64emu_t *emu, uintptr_t fnc);
void vFuipiup(x64emu_t *emu, uintptr_t fnc);
void vFuuiiii(x64emu_t *emu, uintptr_t fnc);
void vFuuiuii(x64emu_t *emu, uintptr_t fnc);
void vFuuiuiu(x64emu_t *emu, uintptr_t fnc);
void vFuuiuup(x64emu_t *emu, uintptr_t fnc);
void vFuuippp(x64emu_t *emu, uintptr_t fnc);
void vFuuuiup(x64emu_t *emu, uintptr_t fnc);
void vFuuuipi(x64emu_t *emu, uintptr_t fnc);
void vFuuuipp(x64emu_t *emu, uintptr_t fnc);
void vFuuuuii(x64emu_t *emu, uintptr_t fnc);
void vFuuuuip(x64emu_t *emu, uintptr_t fnc);
void vFuuuuuu(x64emu_t *emu, uintptr_t fnc);
void vFuuuuff(x64emu_t *emu, uintptr_t fnc);
void vFuuuppi(x64emu_t *emu, uintptr_t fnc);
void vFuuuppp(x64emu_t *emu, uintptr_t fnc);
void vFuuffff(x64emu_t *emu, uintptr_t fnc);
void vFuudddd(x64emu_t *emu, uintptr_t fnc);
void vFuffiip(x64emu_t *emu, uintptr_t fnc);
void vFufffff(x64emu_t *emu, uintptr_t fnc);
void vFuddiip(x64emu_t *emu, uintptr_t fnc);
void vFupupip(x64emu_t *emu, uintptr_t fnc);
void vFuppppp(x64emu_t *emu, uintptr_t fnc);
void vFffffff(x64emu_t *emu, uintptr_t fnc);
void vFdddddd(x64emu_t *emu, uintptr_t fnc);
void vFpipipV(x64emu_t *emu, uintptr_t fnc);
void vFpipppi(x64emu_t *emu, uintptr_t fnc);
void vFpdddii(x64emu_t *emu, uintptr_t fnc);
void vFppiiii(x64emu_t *emu, uintptr_t fnc);
void vFppiipi(x64emu_t *emu, uintptr_t fnc);
void vFppupii(x64emu_t *emu, uintptr_t fnc);
void vFpppppp(x64emu_t *emu, uintptr_t fnc);
void iFEpippi(x64emu_t *emu, uintptr_t fnc);
void iFEppppp(x64emu_t *emu, uintptr_t fnc);
void iFiiiiii(x64emu_t *emu, uintptr_t fnc);
void iFiiiiip(x64emu_t *emu, uintptr_t fnc);
void iFuppipp(x64emu_t *emu, uintptr_t fnc);
void iFuppppp(x64emu_t *emu, uintptr_t fnc);
void iFpiiiii(x64emu_t *emu, uintptr_t fnc);
void iFpiiipp(x64emu_t *emu, uintptr_t fnc);
void iFpiippp(x64emu_t *emu, uintptr_t fnc);
void iFpipppp(x64emu_t *emu, uintptr_t fnc);
void iFpupuui(x64emu_t *emu, uintptr_t fnc);
void iFppiiuu(x64emu_t *emu, uintptr_t fnc);
void iFppIppp(x64emu_t *emu, uintptr_t fnc);
void iFppuiii(x64emu_t *emu, uintptr_t fnc);
void iFppuiiL(x64emu_t *emu, uintptr_t fnc);
void iFppuIII(x64emu_t *emu, uintptr_t fnc);
void iFppuupp(x64emu_t *emu, uintptr_t fnc);
void iFppupip(x64emu_t *emu, uintptr_t fnc);
void iFpppiuu(x64emu_t *emu, uintptr_t fnc);
void iFpppipi(x64emu_t *emu, uintptr_t fnc);
void iFpppipp(x64emu_t *emu, uintptr_t fnc);
void iFppppii(x64emu_t *emu, uintptr_t fnc);
void iFpppppi(x64emu_t *emu, uintptr_t fnc);
void iFpppppL(x64emu_t *emu, uintptr_t fnc);
void iFpppppp(x64emu_t *emu, uintptr_t fnc);
void uFpippup(x64emu_t *emu, uintptr_t fnc);
void UFpippup(x64emu_t *emu, uintptr_t fnc);
void pFEpippp(x64emu_t *emu, uintptr_t fnc);
void pFiCiiCi(x64emu_t *emu, uintptr_t fnc);
void pFpiiiiu(x64emu_t *emu, uintptr_t fnc);
void pFpippip(x64emu_t *emu, uintptr_t fnc);
void pFpCuuCC(x64emu_t *emu, uintptr_t fnc);
void pFpCuuWW(x64emu_t *emu, uintptr_t fnc);
void pFpCuuup(x64emu_t *emu, uintptr_t fnc);
void pFpuuuuu(x64emu_t *emu, uintptr_t fnc);
void pFppiiii(x64emu_t *emu, uintptr_t fnc);
void pFpppppp(x64emu_t *emu, uintptr_t fnc);
void vFiiiiiip(x64emu_t *emu, uintptr_t fnc);
void vFiiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFiiupuip(x64emu_t *emu, uintptr_t fnc);
void vFiiffffp(x64emu_t *emu, uintptr_t fnc);
void vFiupuuup(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuiiiuip(x64emu_t *emu, uintptr_t fnc);
void vFuiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuiuiiii(x64emu_t *emu, uintptr_t fnc);
void vFuiuiiip(x64emu_t *emu, uintptr_t fnc);
void vFuiuiiuu(x64emu_t *emu, uintptr_t fnc);
void vFuiupiiu(x64emu_t *emu, uintptr_t fnc);
void vFuipiiii(x64emu_t *emu, uintptr_t fnc);
void vFuipffff(x64emu_t *emu, uintptr_t fnc);
void vFuipdddd(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiip(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiui(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiuu(x64emu_t *emu, uintptr_t fnc);
void vFuuiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuuiuiii(x64emu_t *emu, uintptr_t fnc);
void vFuuipppp(x64emu_t *emu, uintptr_t fnc);
void vFuuuiiii(x64emu_t *emu, uintptr_t fnc);
void vFuuuiiip(x64emu_t *emu, uintptr_t fnc);
void vFuuuiuii(x64emu_t *emu, uintptr_t fnc);
void vFuuuiupi(x64emu_t *emu, uintptr_t fnc);
void vFuuuuiip(x64emu_t *emu, uintptr_t fnc);
void vFuuuuuuu(x64emu_t *emu, uintptr_t fnc);
void vFuuuufff(x64emu_t *emu, uintptr_t fnc);
void vFuuuffff(x64emu_t *emu, uintptr_t fnc);
void vFuuudddd(x64emu_t *emu, uintptr_t fnc);
void vFuuffiip(x64emu_t *emu, uintptr_t fnc);
void vFuuddiip(x64emu_t *emu, uintptr_t fnc);
void vFuffffff(x64emu_t *emu, uintptr_t fnc);
void vFudddddd(x64emu_t *emu, uintptr_t fnc);
void vFpipipii(x64emu_t *emu, uintptr_t fnc);
void vFpddiidd(x64emu_t *emu, uintptr_t fnc);
void vFppiiipi(x64emu_t *emu, uintptr_t fnc);
void vFpppiiii(x64emu_t *emu, uintptr_t fnc);
void vFppppipi(x64emu_t *emu, uintptr_t fnc);
void iFEpppiiu(x64emu_t *emu, uintptr_t fnc);
void iFEpppppp(x64emu_t *emu, uintptr_t fnc);
void iFiiiiiip(x64emu_t *emu, uintptr_t fnc);
void iFpiiuuiu(x64emu_t *emu, uintptr_t fnc);
void iFpiupiii(x64emu_t *emu, uintptr_t fnc);
void iFpuuiuui(x64emu_t *emu, uintptr_t fnc);
void iFpupuuui(x64emu_t *emu, uintptr_t fnc);
void iFpuppppp(x64emu_t *emu, uintptr_t fnc);
void iFppiiuui(x64emu_t *emu, uintptr_t fnc);
void iFppiipii(x64emu_t *emu, uintptr_t fnc);
void iFppipipi(x64emu_t *emu, uintptr_t fnc);
void iFppipppp(x64emu_t *emu, uintptr_t fnc);
void iFpppiiii(x64emu_t *emu, uintptr_t fnc);
void iFpppiiuu(x64emu_t *emu, uintptr_t fnc);
void iFpppiipi(x64emu_t *emu, uintptr_t fnc);
void iFpppiuwu(x64emu_t *emu, uintptr_t fnc);
void iFppppiii(x64emu_t *emu, uintptr_t fnc);
void iFppppdpi(x64emu_t *emu, uintptr_t fnc);
void iFppppppp(x64emu_t *emu, uintptr_t fnc);
void uFuippppp(x64emu_t *emu, uintptr_t fnc);
void pFEppppip(x64emu_t *emu, uintptr_t fnc);
void pFuupupup(x64emu_t *emu, uintptr_t fnc);
void pFpCuwwWW(x64emu_t *emu, uintptr_t fnc);
void pFpCuWCCC(x64emu_t *emu, uintptr_t fnc);
void pFpCuuwwp(x64emu_t *emu, uintptr_t fnc);
void pFpCuuuuu(x64emu_t *emu, uintptr_t fnc);
void pFppuuppp(x64emu_t *emu, uintptr_t fnc);
void pFppppuuu(x64emu_t *emu, uintptr_t fnc);
void pFpppppuu(x64emu_t *emu, uintptr_t fnc);
void pFppppppp(x64emu_t *emu, uintptr_t fnc);
void vFiiiiuuip(x64emu_t *emu, uintptr_t fnc);
void vFiupuiuup(x64emu_t *emu, uintptr_t fnc);
void vFiupuuuup(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuiiipiup(x64emu_t *emu, uintptr_t fnc);
void vFuiuiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuiuiiiip(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiuip(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuuiiuupp(x64emu_t *emu, uintptr_t fnc);
void vFuuiuiiii(x64emu_t *emu, uintptr_t fnc);
void vFuuiuiiip(x64emu_t *emu, uintptr_t fnc);
void vFuuuiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuuuiuiii(x64emu_t *emu, uintptr_t fnc);
void vFuuuipipp(x64emu_t *emu, uintptr_t fnc);
void vFuuuuuuuu(x64emu_t *emu, uintptr_t fnc);
void vFuuuuufff(x64emu_t *emu, uintptr_t fnc);
void vFffffffff(x64emu_t *emu, uintptr_t fnc);
void vFpippiiuu(x64emu_t *emu, uintptr_t fnc);
void vFpippiipi(x64emu_t *emu, uintptr_t fnc);
void vFppiiipii(x64emu_t *emu, uintptr_t fnc);
void vFppppiipi(x64emu_t *emu, uintptr_t fnc);
void iFEpippppp(x64emu_t *emu, uintptr_t fnc);
void iFiiiiiiip(x64emu_t *emu, uintptr_t fnc);
void iFiiupiupi(x64emu_t *emu, uintptr_t fnc);
void iFuiifpppp(x64emu_t *emu, uintptr_t fnc);
void iFpuuiiiii(x64emu_t *emu, uintptr_t fnc);
void iFpupppppp(x64emu_t *emu, uintptr_t fnc);
void iFppIIIppp(x64emu_t *emu, uintptr_t fnc);
void iFpppiippp(x64emu_t *emu, uintptr_t fnc);
void iFpppipipi(x64emu_t *emu, uintptr_t fnc);
void iFpppipppp(x64emu_t *emu, uintptr_t fnc);
void iFppppiipi(x64emu_t *emu, uintptr_t fnc);
void iFpppppppp(x64emu_t *emu, uintptr_t fnc);
void uFuipppppp(x64emu_t *emu, uintptr_t fnc);
void pFuiiiuuuu(x64emu_t *emu, uintptr_t fnc);
void pFuupupipp(x64emu_t *emu, uintptr_t fnc);
void pFpCuwwWWu(x64emu_t *emu, uintptr_t fnc);
void pFpCuuuCup(x64emu_t *emu, uintptr_t fnc);
void pFpppuuLLu(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiiuip(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuiuiiiiip(x64emu_t *emu, uintptr_t fnc);
void vFuiupuffup(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuuiuiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuuiuiiiip(x64emu_t *emu, uintptr_t fnc);
void vFuuiuiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuuuiiiiip(x64emu_t *emu, uintptr_t fnc);
void vFuuuuuuuuu(x64emu_t *emu, uintptr_t fnc);
void vFuupiuiuuf(x64emu_t *emu, uintptr_t fnc);
void vFuffffffff(x64emu_t *emu, uintptr_t fnc);
void vFffuuuufff(x64emu_t *emu, uintptr_t fnc);
void vFddddddddd(x64emu_t *emu, uintptr_t fnc);
void vFpipppiipi(x64emu_t *emu, uintptr_t fnc);
void vFppiiipiii(x64emu_t *emu, uintptr_t fnc);
void vFpppppippp(x64emu_t *emu, uintptr_t fnc);
void iFiiiiiiiip(x64emu_t *emu, uintptr_t fnc);
void iFiiiipiiip(x64emu_t *emu, uintptr_t fnc);
void iFdddpppppp(x64emu_t *emu, uintptr_t fnc);
void iFpipLpiiip(x64emu_t *emu, uintptr_t fnc);
void iFppiuiippL(x64emu_t *emu, uintptr_t fnc);
void iFpppiiuuii(x64emu_t *emu, uintptr_t fnc);
void iFpppiipiiu(x64emu_t *emu, uintptr_t fnc);
void iFppppppppp(x64emu_t *emu, uintptr_t fnc);
void pFEppiiuuLi(x64emu_t *emu, uintptr_t fnc);
void pFEppuippuu(x64emu_t *emu, uintptr_t fnc);
void pFpiiiiuuuu(x64emu_t *emu, uintptr_t fnc);
void pFpCuWCCuuu(x64emu_t *emu, uintptr_t fnc);
void pFpuuwwWWww(x64emu_t *emu, uintptr_t fnc);
void pFppiiuuuLL(x64emu_t *emu, uintptr_t fnc);
void vFiiiiiiiiiu(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuiuiiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiiiiii(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiiiuip(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuuiuiiiiip(x64emu_t *emu, uintptr_t fnc);
void vFuuiuiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuuuuuuuiii(x64emu_t *emu, uintptr_t fnc);
void vFuuuuuuuuuu(x64emu_t *emu, uintptr_t fnc);
void vFuupiiupuuf(x64emu_t *emu, uintptr_t fnc);
void vFuffiiffiip(x64emu_t *emu, uintptr_t fnc);
void vFuddiiddiip(x64emu_t *emu, uintptr_t fnc);
void vFffffffffff(x64emu_t *emu, uintptr_t fnc);
void iFiiiiiiiiip(x64emu_t *emu, uintptr_t fnc);
void iFpuupiuiipp(x64emu_t *emu, uintptr_t fnc);
void iFppuuiiiiii(x64emu_t *emu, uintptr_t fnc);
void iFppuuiiuupi(x64emu_t *emu, uintptr_t fnc);
void iFppppiiuuii(x64emu_t *emu, uintptr_t fnc);
void pFpCuWCCuuCW(x64emu_t *emu, uintptr_t fnc);
void pFpuuuwwwwWW(x64emu_t *emu, uintptr_t fnc);
void pFppuiipuuii(x64emu_t *emu, uintptr_t fnc);
void pFpppppppppp(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiiiiiip(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiiiiuip(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuiuiiiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuuiuiiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuuuuuuuuuuu(x64emu_t *emu, uintptr_t fnc);
void vFuuffiiffiip(x64emu_t *emu, uintptr_t fnc);
void vFuufffffffff(x64emu_t *emu, uintptr_t fnc);
void vFuuddiiddiip(x64emu_t *emu, uintptr_t fnc);
void vFuffffffffff(x64emu_t *emu, uintptr_t fnc);
void vFpipipiipiii(x64emu_t *emu, uintptr_t fnc);
void vFpipppiiiipi(x64emu_t *emu, uintptr_t fnc);
void iFEppppiiiiuu(x64emu_t *emu, uintptr_t fnc);
void iFiiiiiiiiiip(x64emu_t *emu, uintptr_t fnc);
void iFpipllippppp(x64emu_t *emu, uintptr_t fnc);
void iFppppiiuuiiL(x64emu_t *emu, uintptr_t fnc);
void pFEppuiipuuii(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiiiiiuip(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiiiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuuuuuuuuuuuu(x64emu_t *emu, uintptr_t fnc);
void vFffffffffffff(x64emu_t *emu, uintptr_t fnc);
void vFpipppiiiipii(x64emu_t *emu, uintptr_t fnc);
void vFpippppiiiipi(x64emu_t *emu, uintptr_t fnc);
void iFEppppiiiiuui(x64emu_t *emu, uintptr_t fnc);
void iFpipppppppppp(x64emu_t *emu, uintptr_t fnc);
void iFpppllipppppp(x64emu_t *emu, uintptr_t fnc);
void iFpppppppppppp(x64emu_t *emu, uintptr_t fnc);
void pFEppiiuuuipii(x64emu_t *emu, uintptr_t fnc);
void pFpCuuWWwwCCup(x64emu_t *emu, uintptr_t fnc);
void pFpuuuWWWWWWWW(x64emu_t *emu, uintptr_t fnc);
void pFppiiuuuiupLp(x64emu_t *emu, uintptr_t fnc);
void vFuiiiiiiiiiuup(x64emu_t *emu, uintptr_t fnc);
void vFuuuuuuuuuuuuu(x64emu_t *emu, uintptr_t fnc);
void vFuffffffffffff(x64emu_t *emu, uintptr_t fnc);
void iFddddpppddpppp(x64emu_t *emu, uintptr_t fnc);
void iFpippuuuiipppp(x64emu_t *emu, uintptr_t fnc);
void iFpupiiiipppppp(x64emu_t *emu, uintptr_t fnc);
void pFpCuuwwWWWWuup(x64emu_t *emu, uintptr_t fnc);
void pFppppppppppppp(x64emu_t *emu, uintptr_t fnc);
void vFuffiiffiiffiip(x64emu_t *emu, uintptr_t fnc);
void vFuddiiddiiddiip(x64emu_t *emu, uintptr_t fnc);
void vFuuiiiiuuiiiiiii(x64emu_t *emu, uintptr_t fnc);
void vFfffffffffffffff(x64emu_t *emu, uintptr_t fnc);
void uFpppppppppppppppp(x64emu_t *emu, uintptr_t fnc);
void vFppuiiiiipuiiiiiiii(x64emu_t *emu, uintptr_t fnc);
void pFipppppppppppppppppppppp(x64emu_t *emu, uintptr_t fnc);

#if defined(HAVE_LD80BITS)
void DFD(x64emu_t *emu, uintptr_t fnc);
void DFDD(x64emu_t *emu, uintptr_t fnc);
void DFDp(x64emu_t *emu, uintptr_t fnc);
#endif

#if !defined(HAVE_LD80BITS)
void KFK(x64emu_t *emu, uintptr_t fnc);
void KFKK(x64emu_t *emu, uintptr_t fnc);
void KFKp(x64emu_t *emu, uintptr_t fnc);
#endif

void iFEv(x64emu_t *emu, uintptr_t fnc);
void pFEv(x64emu_t *emu, uintptr_t fnc);
void iFEvpp(x64emu_t *emu, uintptr_t fnc);
void iFEpvpp(x64emu_t *emu, uintptr_t fnc);
void iFEpvpV(x64emu_t *emu, uintptr_t fnc);

#endif //__WRAPPER_H_
