// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__top__DOT__mem__DOT__RAM__v0;
    __VdlyVal__top__DOT__mem__DOT__RAM__v0 = 0;
    SData/*10:0*/ __VdlyDim0__top__DOT__mem__DOT__RAM__v0;
    __VdlyDim0__top__DOT__mem__DOT__RAM__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__mem__DOT__RAM__v0;
    __VdlySet__top__DOT__mem__DOT__RAM__v0 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regfile__DOT__rf__v0;
    __VdlyVal__top__DOT__regfile__DOT__rf__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regfile__DOT__rf__v0;
    __VdlyDim0__top__DOT__regfile__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regfile__DOT__rf__v0;
    __VdlySet__top__DOT__regfile__DOT__rf__v0 = 0;
    // Body
    __VdlySet__top__DOT__mem__DOT__RAM__v0 = 0U;
    __VdlySet__top__DOT__regfile__DOT__rf__v0 = 0U;
    if (vlSelfRef.MemWrite) {
        __VdlyVal__top__DOT__mem__DOT__RAM__v0 = vlSelfRef.WriteData;
        __VdlyDim0__top__DOT__mem__DOT__RAM__v0 = (0x7ffU 
                                                   & (vlSelfRef.Adr 
                                                      >> 2U));
        __VdlySet__top__DOT__mem__DOT__RAM__v0 = 1U;
    }
    if (((IData)(vlSelfRef.regWrite) & (0U != (IData)(vlSelfRef.rd)))) {
        __VdlyVal__top__DOT__regfile__DOT__rf__v0 = vlSelfRef.ResultOut;
        __VdlyDim0__top__DOT__regfile__DOT__rf__v0 
            = vlSelfRef.rd;
        __VdlySet__top__DOT__regfile__DOT__rf__v0 = 1U;
    }
    if (__VdlySet__top__DOT__mem__DOT__RAM__v0) {
        vlSelfRef.top__DOT__mem__DOT__RAM[__VdlyDim0__top__DOT__mem__DOT__RAM__v0] 
            = __VdlyVal__top__DOT__mem__DOT__RAM__v0;
    }
    if (__VdlySet__top__DOT__regfile__DOT__rf__v0) {
        vlSelfRef.top__DOT__regfile__DOT__rf[__VdlyDim0__top__DOT__regfile__DOT__rf__v0] 
            = __VdlyVal__top__DOT__regfile__DOT__rf__v0;
    }
    vlSelfRef.a0_r = (0xffU & vlSelfRef.top__DOT__regfile__DOT__rf
                      [0xaU]);
}

extern const VlUnpacked<CData/*3:0*/, 2048> Vtop__ConstPool__TABLE_h101ca81a_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_hd402514e_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rst) {
        vlSelfRef.pcdata_out = 0U;
        vlSelfRef.alupcOut = 0U;
        vlSelfRef.out_A = 0U;
        vlSelfRef.top__DOT__ctrl__DOT__current_state = 0U;
        vlSelfRef.instr = 0U;
        vlSelfRef.oldpcout = 0U;
        vlSelfRef.WriteData = 0U;
        vlSelfRef.pcout = 0U;
    } else {
        vlSelfRef.pcdata_out = vlSelfRef.meminstr;
        vlSelfRef.alupcOut = vlSelfRef.aluOut;
        vlSelfRef.out_A = vlSelfRef.rd1;
        vlSelfRef.top__DOT__ctrl__DOT__current_state 
            = vlSelfRef.top__DOT__ctrl__DOT__next_state;
        vlSelfRef.instr = vlSelfRef.pcout;
        if (vlSelfRef.IRWrite) {
            vlSelfRef.oldpcout = vlSelfRef.meminstr;
        }
        vlSelfRef.WriteData = vlSelfRef.rd2;
        if (vlSelfRef.PCWrite) {
            vlSelfRef.pcout = vlSelfRef.ResultOut;
        }
    }
    vlSelfRef.state_out = vlSelfRef.top__DOT__ctrl__DOT__current_state;
    vlSelfRef.rd = (0x1fU & (vlSelfRef.oldpcout >> 7U));
    vlSelfRef.__Vtableidx2 = ((0x7f0U & (vlSelfRef.oldpcout 
                                         << 4U)) | (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state));
    vlSelfRef.top__DOT__ctrl__DOT__next_state = Vtop__ConstPool__TABLE_h101ca81a_0
        [vlSelfRef.__Vtableidx2];
    vlSelfRef.rs1 = (0x1fU & (vlSelfRef.oldpcout >> 0xfU));
    vlSelfRef.__Vtableidx1 = (0x7fU & vlSelfRef.oldpcout);
    vlSelfRef.immSrc = Vtop__ConstPool__TABLE_hd402514e_0
        [vlSelfRef.__Vtableidx1];
    vlSelfRef.einstr = (0x1fU & (vlSelfRef.oldpcout 
                                 >> 0x14U));
    vlSelfRef.immext = ((2U & (IData)(vlSelfRef.immSrc))
                         ? ((1U & (IData)(vlSelfRef.immSrc))
                             ? (((- (IData)((vlSelfRef.oldpcout 
                                             >> 0x1fU))) 
                                 << 0x14U) | (((0xff000U 
                                                & vlSelfRef.oldpcout) 
                                               | (0x800U 
                                                  & (vlSelfRef.oldpcout 
                                                     >> 9U))) 
                                              | (0x7feU 
                                                 & (vlSelfRef.oldpcout 
                                                    >> 0x14U))))
                             : (((- (IData)((vlSelfRef.oldpcout 
                                             >> 0x1fU))) 
                                 << 0xcU) | ((0x800U 
                                              & (vlSelfRef.oldpcout 
                                                 << 4U)) 
                                             | ((0x7e0U 
                                                 & (vlSelfRef.oldpcout 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelfRef.oldpcout 
                                                      >> 7U))))))
                         : ((1U & (IData)(vlSelfRef.immSrc))
                             ? (((- (IData)((vlSelfRef.oldpcout 
                                             >> 0x1fU))) 
                                 << 0xcU) | ((0xfe0U 
                                              & (vlSelfRef.oldpcout 
                                                 >> 0x14U)) 
                                             | (0x1fU 
                                                & (vlSelfRef.oldpcout 
                                                   >> 7U))))
                             : (((- (IData)((vlSelfRef.oldpcout 
                                             >> 0x1fU))) 
                                 << 0xcU) | (vlSelfRef.oldpcout 
                                             >> 0x14U))));
    vlSelfRef.rs2 = vlSelfRef.einstr;
}

void Vtop___024root____Vdpiimwrap_top__DOT__ctrl__DOT__check_TOP(CData/*7:0*/ a0, CData/*7:0*/ mcause);
extern const VlUnpacked<CData/*2:0*/, 64> Vtop__ConstPool__TABLE_he07a7065_0;

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rd1 = ((0U == (IData)(vlSelfRef.rs1))
                      ? 0U : vlSelfRef.top__DOT__regfile__DOT__rf
                     [vlSelfRef.rs1]);
    vlSelfRef.rd2 = ((0U == (IData)(vlSelfRef.einstr))
                      ? 0U : vlSelfRef.top__DOT__regfile__DOT__rf
                     [vlSelfRef.einstr]);
    vlSelfRef.top__DOT__ctrl__DOT__branch = 0U;
    vlSelfRef.IRWrite = 0U;
    vlSelfRef.MemWrite = 0U;
    vlSelfRef.PCWrite = 0U;
    vlSelfRef.AdrSrc = 0U;
    vlSelfRef.mcause = 0U;
    vlSelfRef.aluControl = 0U;
    vlSelfRef.ALUSrcB = 0U;
    vlSelfRef.ALUSrcA = 0U;
    vlSelfRef.ResultSrc = 0U;
    vlSelfRef.regWrite = 0U;
    vlSelfRef.PCUpdate = 0U;
    vlSelfRef.top__DOT__ctrl__DOT__AluOp = 0U;
    vlSelfRef.done_LW = 0U;
    vlSelfRef.done_SW = 0U;
    vlSelfRef.done_ALUWB = 0U;
    vlSelfRef.done_beq = 0U;
    vlSelfRef.done_ecall = 0U;
    vlSelfRef.done_ebreak = 0U;
    if ((8U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
        if ((4U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            vlSelfRef.mcause = 0U;
            vlSelfRef.top__DOT__ctrl__DOT__branch = 0U;
            vlSelfRef.IRWrite = 0U;
            vlSelfRef.MemWrite = 0U;
            vlSelfRef.PCWrite = 0U;
            vlSelfRef.AdrSrc = 0U;
            vlSelfRef.aluControl = 0U;
            vlSelfRef.ALUSrcB = 0U;
            vlSelfRef.ALUSrcA = 0U;
            vlSelfRef.ResultSrc = 0U;
            vlSelfRef.regWrite = 0U;
            vlSelfRef.PCUpdate = 0U;
            vlSelfRef.top__DOT__ctrl__DOT__AluOp = 0U;
            vlSelfRef.done_LW = 0U;
            vlSelfRef.done_SW = 0U;
            vlSelfRef.done_ALUWB = 0U;
            vlSelfRef.done_beq = 0U;
            vlSelfRef.done_ecall = 0U;
            vlSelfRef.done_ebreak = 0U;
        } else if ((2U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
                vlSelfRef.mcause = 0U;
                vlSelfRef.top__DOT__ctrl__DOT__branch = 0U;
                vlSelfRef.IRWrite = 0U;
                vlSelfRef.MemWrite = 0U;
                vlSelfRef.PCWrite = 0U;
                vlSelfRef.AdrSrc = 0U;
                vlSelfRef.aluControl = 0U;
                vlSelfRef.ALUSrcB = 0U;
                vlSelfRef.ALUSrcA = 0U;
                vlSelfRef.ResultSrc = 0U;
                vlSelfRef.regWrite = 0U;
                vlSelfRef.PCUpdate = 0U;
                vlSelfRef.top__DOT__ctrl__DOT__AluOp = 0U;
                vlSelfRef.done_LW = 0U;
                vlSelfRef.done_SW = 0U;
                vlSelfRef.done_ALUWB = 0U;
                vlSelfRef.done_beq = 0U;
                vlSelfRef.done_ecall = 0U;
                vlSelfRef.done_ebreak = 0U;
            } else {
                vlSelfRef.ALUSrcA = 2U;
                vlSelfRef.ALUSrcB = 0U;
                vlSelfRef.ResultSrc = 0U;
                vlSelfRef.top__DOT__ctrl__DOT__AluOp = 1U;
                vlSelfRef.top__DOT__ctrl__DOT__branch = 1U;
                vlSelfRef.done_beq = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            vlSelfRef.ALUSrcA = 1U;
            vlSelfRef.ALUSrcB = 2U;
            vlSelfRef.PCUpdate = 1U;
        } else {
            vlSelfRef.ALUSrcA = 2U;
            vlSelfRef.ALUSrcB = 1U;
            vlSelfRef.top__DOT__ctrl__DOT__AluOp = 2U;
        }
    } else if ((4U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
        if ((2U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
                vlSelfRef.regWrite = 1U;
                vlSelfRef.done_ALUWB = 1U;
            } else {
                vlSelfRef.ALUSrcA = 2U;
                vlSelfRef.top__DOT__ctrl__DOT__AluOp = 2U;
            }
        } else if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            vlSelfRef.AdrSrc = 1U;
            vlSelfRef.MemWrite = 1U;
            vlSelfRef.done_SW = 1U;
        } else {
            vlSelfRef.ResultSrc = 1U;
            vlSelfRef.regWrite = 1U;
            vlSelfRef.done_LW = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
        if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            vlSelfRef.AdrSrc = 1U;
        } else {
            vlSelfRef.ALUSrcA = 2U;
            vlSelfRef.ALUSrcB = 1U;
        }
    } else if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
        vlSelfRef.ALUSrcA = 1U;
        vlSelfRef.ALUSrcB = 1U;
        if (((0x73U == (0x7fU & vlSelfRef.oldpcout)) 
             & (0U == (IData)(vlSelfRef.einstr)))) {
            vlSelfRef.mcause = 0xbU;
            vlSelfRef.done_ecall = 1U;
        } else if (((0x73U == (0x7fU & vlSelfRef.oldpcout)) 
                    & (1U == (IData)(vlSelfRef.einstr)))) {
            vlSelfRef.mcause = 3U;
            vlSelfRef.done_ebreak = 1U;
        }
        Vtop___024root____Vdpiimwrap_top__DOT__ctrl__DOT__check_TOP(vlSelfRef.a0_r, (IData)(vlSelfRef.mcause));
    } else {
        vlSelfRef.AdrSrc = 0U;
        vlSelfRef.IRWrite = 1U;
        vlSelfRef.ALUSrcA = 0U;
        vlSelfRef.ALUSrcB = 2U;
        vlSelfRef.top__DOT__ctrl__DOT__AluOp = 0U;
        vlSelfRef.ResultSrc = 2U;
        vlSelfRef.PCUpdate = 1U;
    }
    vlSelfRef.SrcBout = ((0U == (IData)(vlSelfRef.ALUSrcB))
                          ? vlSelfRef.WriteData : (
                                                   (1U 
                                                    == (IData)(vlSelfRef.ALUSrcB))
                                                    ? vlSelfRef.immext
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelfRef.ALUSrcB))
                                                     ? 4U
                                                     : 0U)));
    vlSelfRef.SrcAout = ((0U == (IData)(vlSelfRef.ALUSrcA))
                          ? vlSelfRef.pcout : ((1U 
                                                == (IData)(vlSelfRef.ALUSrcA))
                                                ? vlSelfRef.instr
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.ALUSrcA))
                                                    ? vlSelfRef.out_A
                                                    : 0U)));
    vlSelfRef.__Vtableidx3 = (((IData)((0x40000020U 
                                        == (0x40000020U 
                                            & vlSelfRef.oldpcout))) 
                               << 5U) | ((0x1cU & (vlSelfRef.oldpcout 
                                                   >> 0xaU)) 
                                         | (IData)(vlSelfRef.top__DOT__ctrl__DOT__AluOp)));
    vlSelfRef.aluControl = Vtop__ConstPool__TABLE_he07a7065_0
        [vlSelfRef.__Vtableidx3];
    vlSelfRef.top__DOT__alutrans__DOT__sum = (vlSelfRef.SrcAout 
                                              + (((1U 
                                                   & (IData)(vlSelfRef.aluControl))
                                                   ? 
                                                  (~ vlSelfRef.SrcBout)
                                                   : vlSelfRef.SrcBout) 
                                                 + 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.aluControl))
                                                   ? 1U
                                                   : 0U)));
    vlSelfRef.aluOut = ((4U & (IData)(vlSelfRef.aluControl))
                         ? ((2U & (IData)(vlSelfRef.aluControl))
                             ? ((1U & (IData)(vlSelfRef.aluControl))
                                 ? (vlSelfRef.SrcAout 
                                    >> (0x1fU & vlSelfRef.SrcBout))
                                 : (vlSelfRef.SrcAout 
                                    << (0x1fU & vlSelfRef.SrcBout)))
                             : ((1U & (IData)(vlSelfRef.aluControl))
                                 ? (1U & ((vlSelfRef.top__DOT__alutrans__DOT__sum 
                                           >> 0x1fU) 
                                          ^ ((~ ((IData)(vlSelfRef.aluControl) 
                                                 ^ 
                                                 ((vlSelfRef.SrcAout 
                                                   ^ vlSelfRef.SrcBout) 
                                                  >> 0x1fU))) 
                                             & (((vlSelfRef.SrcAout 
                                                  ^ vlSelfRef.top__DOT__alutrans__DOT__sum) 
                                                 >> 0x1fU) 
                                                & ((IData)(
                                                           (0U 
                                                            == 
                                                            (6U 
                                                             & (IData)(vlSelfRef.aluControl)))) 
                                                   | (IData)(
                                                             (0U 
                                                              == 
                                                              (3U 
                                                               & (IData)(vlSelfRef.aluControl)))))))))
                                 : (vlSelfRef.SrcAout 
                                    ^ vlSelfRef.SrcBout)))
                         : ((2U & (IData)(vlSelfRef.aluControl))
                             ? ((1U & (IData)(vlSelfRef.aluControl))
                                 ? (vlSelfRef.SrcAout 
                                    | vlSelfRef.SrcBout)
                                 : (vlSelfRef.SrcAout 
                                    + vlSelfRef.SrcBout))
                             : vlSelfRef.top__DOT__alutrans__DOT__sum));
    vlSelfRef.zero = (0U == vlSelfRef.aluOut);
    vlSelfRef.ResultOut = ((0U == (IData)(vlSelfRef.ResultSrc))
                            ? vlSelfRef.alupcOut : 
                           ((1U == (IData)(vlSelfRef.ResultSrc))
                             ? vlSelfRef.pcdata_out
                             : ((2U == (IData)(vlSelfRef.ResultSrc))
                                 ? vlSelfRef.aluOut
                                 : 0U)));
    vlSelfRef.PCWrite = (((IData)(vlSelfRef.zero) & (IData)(vlSelfRef.top__DOT__ctrl__DOT__branch)) 
                         | (IData)(vlSelfRef.PCUpdate));
    vlSelfRef.Adr = ((IData)(vlSelfRef.AdrSrc) ? vlSelfRef.ResultOut
                      : vlSelfRef.pcout);
    vlSelfRef.meminstr = vlSelfRef.top__DOT__mem__DOT__RAM
        [(0x7ffU & (vlSelfRef.Adr >> 2U))];
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/top.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
