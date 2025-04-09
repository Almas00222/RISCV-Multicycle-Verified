// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

extern const VlWide<12>/*383:0*/ Vtop__ConstPool__CONST_hbfe5c43d_0;

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_READMEM_N(true, 32, 2048, 0, VL_CVT_PACK_STR_NW(12, Vtop__ConstPool__CONST_hbfe5c43d_0)
                 ,  &(vlSelfRef.top__DOT__mem__DOT__RAM)
                 , 0, ~0ULL);
    vlSelfRef.top__DOT__regfile__DOT__rf[0U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[1U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[2U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[3U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[4U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[5U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[6U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[7U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[8U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[9U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0xaU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0xbU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0xcU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0xdU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0xeU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0xfU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x10U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x11U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x12U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x13U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x14U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x15U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x16U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x17U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x18U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x19U] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x1aU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x1bU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x1cU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x1dU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x1eU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__rf[0x1fU] = 0U;
    vlSelfRef.top__DOT__regfile__DOT__i = 0x20U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

extern const VlUnpacked<CData/*3:0*/, 2048> Vtop__ConstPool__TABLE_h101ca81a_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_hd402514e_0;
void Vtop___024root____Vdpiimwrap_top__DOT__ctrl__DOT__check_TOP(CData/*7:0*/ a0, CData/*7:0*/ mcause);
extern const VlUnpacked<CData/*2:0*/, 64> Vtop__ConstPool__TABLE_he07a7065_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rd = (0x1fU & (vlSelfRef.oldpcout >> 7U));
    vlSelfRef.state_out = vlSelfRef.top__DOT__ctrl__DOT__current_state;
    vlSelfRef.__Vtableidx2 = ((0x7f0U & (vlSelfRef.oldpcout 
                                         << 4U)) | (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state));
    vlSelfRef.top__DOT__ctrl__DOT__next_state = Vtop__ConstPool__TABLE_h101ca81a_0
        [vlSelfRef.__Vtableidx2];
    vlSelfRef.rs1 = (0x1fU & (vlSelfRef.oldpcout >> 0xfU));
    vlSelfRef.__Vtableidx1 = (0x7fU & vlSelfRef.oldpcout);
    vlSelfRef.immSrc = Vtop__ConstPool__TABLE_hd402514e_0
        [vlSelfRef.__Vtableidx1];
    vlSelfRef.a0_r = (0xffU & vlSelfRef.top__DOT__regfile__DOT__rf
                      [0xaU]);
    vlSelfRef.einstr = (0x1fU & (vlSelfRef.oldpcout 
                                 >> 0x14U));
    vlSelfRef.rd1 = ((0U == (IData)(vlSelfRef.rs1))
                      ? 0U : vlSelfRef.top__DOT__regfile__DOT__rf
                     [vlSelfRef.rs1]);
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

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vm_traceActivitySetAll\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0_r = VL_RAND_RESET_I(8);
    vlSelf->einstr = VL_RAND_RESET_I(5);
    vlSelf->meminstr = VL_RAND_RESET_I(32);
    vlSelf->rs1 = VL_RAND_RESET_I(5);
    vlSelf->rs2 = VL_RAND_RESET_I(5);
    vlSelf->aluOut = VL_RAND_RESET_I(32);
    vlSelf->done_LW = VL_RAND_RESET_I(1);
    vlSelf->done_SW = VL_RAND_RESET_I(1);
    vlSelf->done_ALUWB = VL_RAND_RESET_I(1);
    vlSelf->done_ecall = VL_RAND_RESET_I(1);
    vlSelf->done_ebreak = VL_RAND_RESET_I(1);
    vlSelf->mcause = VL_RAND_RESET_I(4);
    vlSelf->done_beq = VL_RAND_RESET_I(1);
    vlSelf->SrcBout = VL_RAND_RESET_I(32);
    vlSelf->SrcAout = VL_RAND_RESET_I(32);
    vlSelf->IRWrite = VL_RAND_RESET_I(1);
    vlSelf->PCWrite = VL_RAND_RESET_I(1);
    vlSelf->zero = VL_RAND_RESET_I(1);
    vlSelf->aluControl = VL_RAND_RESET_I(3);
    vlSelf->rd1 = VL_RAND_RESET_I(32);
    vlSelf->ALUSrcB = VL_RAND_RESET_I(2);
    vlSelf->rd2 = VL_RAND_RESET_I(32);
    vlSelf->state_out = VL_RAND_RESET_I(4);
    vlSelf->ResultOut = VL_RAND_RESET_I(32);
    vlSelf->out_A = VL_RAND_RESET_I(32);
    vlSelf->MemWrite = VL_RAND_RESET_I(1);
    vlSelf->AdrSrc = VL_RAND_RESET_I(1);
    vlSelf->immSrc = VL_RAND_RESET_I(2);
    vlSelf->ALUSrcA = VL_RAND_RESET_I(2);
    vlSelf->ResultSrc = VL_RAND_RESET_I(2);
    vlSelf->regWrite = VL_RAND_RESET_I(1);
    vlSelf->WriteData = VL_RAND_RESET_I(32);
    vlSelf->immext = VL_RAND_RESET_I(32);
    vlSelf->instr = VL_RAND_RESET_I(32);
    vlSelf->pcdata_out = VL_RAND_RESET_I(32);
    vlSelf->pcout = VL_RAND_RESET_I(32);
    vlSelf->oldpcout = VL_RAND_RESET_I(32);
    vlSelf->alupcOut = VL_RAND_RESET_I(32);
    vlSelf->Adr = VL_RAND_RESET_I(32);
    vlSelf->PCUpdate = VL_RAND_RESET_I(1);
    vlSelf->rd = VL_RAND_RESET_I(5);
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->top__DOT__mem__DOT__RAM[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__regfile__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ctrl__DOT__AluOp = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ctrl__DOT__branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ctrl__DOT__current_state = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__ctrl__DOT__next_state = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__alutrans__DOT__sum = VL_RAND_RESET_I(32);
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtableidx2 = 0;
    vlSelf->__Vtableidx3 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
