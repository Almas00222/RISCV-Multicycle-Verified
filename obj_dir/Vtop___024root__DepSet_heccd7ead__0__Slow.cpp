// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
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
}

extern const VlWide<9>/*287:0*/ Vtop__ConstPool__CONST_h78da40d2_0;

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__mem__DOT__i = 0U;
    while (VL_GTS_III(32, 0x8000U, vlSelfRef.top__DOT__mem__DOT__i)) {
        vlSelfRef.top__DOT__mem__DOT__RAM[(0x7fffU 
                                           & vlSelfRef.top__DOT__mem__DOT__i)] = 0U;
        vlSelfRef.top__DOT__mem__DOT__i = ((IData)(1U) 
                                           + vlSelfRef.top__DOT__mem__DOT__i);
    }
    VL_READMEM_N(true, 32, 32768, 0, VL_CVT_PACK_STR_NW(9, Vtop__ConstPool__CONST_h78da40d2_0)
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
    vlSelfRef.top__DOT__csr_file__DOT__mstatus = 0x1800U;
    vlSelfRef.top__DOT__csr_file__DOT__mtvec = 0x80000004U;
    vlSelfRef.top__DOT__csr_file__DOT__mepc = 0U;
    vlSelfRef.top__DOT__csr_file__DOT__mcause = 0U;
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

extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_hbdd954da_0;
void Vtop___024root____Vdpiimwrap_top__DOT__ctrl__DOT__check_TOP(CData/*7:0*/ a0, CData/*7:0*/ mcause);
extern const VlUnpacked<CData/*3:0*/, 128> Vtop__ConstPool__TABLE_h35a41688_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rd = (0x1fU & (vlSelfRef.oldpcout >> 7U));
    vlSelfRef.state_out = vlSelfRef.top__DOT__ctrl__DOT__current_state;
    vlSelfRef.rs1 = (0x1fU & (vlSelfRef.oldpcout >> 0xfU));
    vlSelfRef.einstr = (0x1fU & (vlSelfRef.oldpcout 
                                 >> 0x14U));
    vlSelfRef.__Vtableidx1 = (0x7fU & vlSelfRef.oldpcout);
    vlSelfRef.immSrc = Vtop__ConstPool__TABLE_hbdd954da_0
        [vlSelfRef.__Vtableidx1];
    vlSelfRef.a0_r = (0xffU & vlSelfRef.top__DOT__regfile__DOT__rf
                      [0xaU]);
    vlSelfRef.rd1 = ((0U == (IData)(vlSelfRef.rs1))
                      ? 0U : vlSelfRef.top__DOT__regfile__DOT__rf
                     [vlSelfRef.rs1]);
    vlSelfRef.rs2 = vlSelfRef.einstr;
    vlSelfRef.rd2 = ((0U == (IData)(vlSelfRef.einstr))
                      ? 0U : vlSelfRef.top__DOT__regfile__DOT__rf
                     [vlSelfRef.einstr]);
    vlSelfRef.top__DOT__ctrl__DOT__next_state = 0U;
    vlSelfRef.top__DOT__ctrl__DOT__mcause_next = vlSelfRef.mcause;
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
                    if (((0x23U == (0x7fU & vlSelfRef.oldpcout)) 
                         & (0U != (3U & vlSelfRef.alupcOut)))) {
                        vlSelfRef.top__DOT__ctrl__DOT__mcause_next = 6U;
                    }
                }
            }
        } else if ((2U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
                if (((3U == (0x7fU & vlSelfRef.oldpcout)) 
                     & (0U != (3U & vlSelfRef.alupcOut)))) {
                    vlSelfRef.top__DOT__ctrl__DOT__mcause_next = 4U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            if (((0x73U == (0x7fU & vlSelfRef.oldpcout)) 
                 & (0U == (IData)(vlSelfRef.einstr)))) {
                vlSelfRef.top__DOT__ctrl__DOT__mcause_next = 0xbU;
            } else if (((0x73U == (0x7fU & vlSelfRef.oldpcout)) 
                        & (1U == (IData)(vlSelfRef.einstr)))) {
                vlSelfRef.top__DOT__ctrl__DOT__mcause_next = 3U;
            }
        } else {
            vlSelfRef.top__DOT__ctrl__DOT__mcause_next = 0U;
        }
    }
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
    vlSelfRef.top__DOT__ctrl__DOT__branch = 0U;
    vlSelfRef.IRWrite = 0U;
    vlSelfRef.MemWrite = 0U;
    vlSelfRef.PCWrite = 0U;
    vlSelfRef.AdrSrc = 0U;
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
    vlSelfRef.top__DOT__trap_entry_sig = 0U;
    vlSelfRef.top__DOT__trap_pc_sig = 0U;
    vlSelfRef.top__DOT__mret_sig = 0U;
    vlSelfRef.top__DOT__PCSrc = 0U;
    if ((8U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
        vlSelfRef.top__DOT__ctrl__DOT__next_state = 
            ((4U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))
              ? 0U : ((2U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))
                       ? 0U : 7U));
    } else if ((4U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
        vlSelfRef.top__DOT__ctrl__DOT__next_state = 
            ((2U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))
              ? ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))
                  ? 0U : 7U) : ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))
                                 ? ((0U != (3U & vlSelfRef.alupcOut))
                                     ? 0xbU : 0U) : 0U));
    } else if ((2U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
        if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            vlSelfRef.top__DOT__ctrl__DOT__next_state 
                = ((0U != (3U & vlSelfRef.alupcOut))
                    ? 0xbU : 4U);
        } else if ((3U == (0x7fU & vlSelfRef.oldpcout))) {
            vlSelfRef.top__DOT__ctrl__DOT__next_state = 3U;
        } else if ((0x23U == (0x7fU & vlSelfRef.oldpcout))) {
            vlSelfRef.top__DOT__ctrl__DOT__next_state = 5U;
        }
    } else {
        vlSelfRef.top__DOT__ctrl__DOT__next_state = 
            ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))
              ? (((0x73U == (0x7fU & vlSelfRef.oldpcout)) 
                  & ((0U == (IData)(vlSelfRef.einstr)) 
                     | (1U == (IData)(vlSelfRef.einstr))))
                  ? 0xbU : (((0x73U == (0x7fU & vlSelfRef.oldpcout)) 
                             & (2U == (IData)(vlSelfRef.einstr)))
                             ? 0xcU : (((3U == (0x7fU 
                                                & vlSelfRef.oldpcout)) 
                                        | (0x23U == 
                                           (0x7fU & vlSelfRef.oldpcout)))
                                        ? 2U : ((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelfRef.oldpcout))
                                                 ? 6U
                                                 : 
                                                ((0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.oldpcout))
                                                  ? 0xaU
                                                  : 
                                                 ((0x13U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelfRef.oldpcout))
                                                   ? 8U
                                                   : 
                                                  ((0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.oldpcout))
                                                    ? 9U
                                                    : 0U)))))))
              : 1U);
    }
    if ((8U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
        if ((4U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            if ((2U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
                vlSelfRef.top__DOT__ctrl__DOT__branch = 0U;
                vlSelfRef.IRWrite = 0U;
                vlSelfRef.MemWrite = 0U;
                vlSelfRef.PCWrite = 0U;
                vlSelfRef.AdrSrc = 0U;
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
            } else if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
                vlSelfRef.top__DOT__ctrl__DOT__branch = 0U;
                vlSelfRef.IRWrite = 0U;
                vlSelfRef.MemWrite = 0U;
                vlSelfRef.PCWrite = 0U;
                vlSelfRef.AdrSrc = 0U;
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
                vlSelfRef.top__DOT__mret_sig = 1U;
                vlSelfRef.top__DOT__PCSrc = 3U;
                vlSelfRef.PCUpdate = 1U;
            }
        } else if ((2U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__ctrl__DOT__current_state))) {
                vlSelfRef.top__DOT__trap_entry_sig = 1U;
                vlSelfRef.top__DOT__trap_pc_sig = vlSelfRef.top__DOT__ctrl__DOT__saved_pc;
                vlSelfRef.top__DOT__PCSrc = 2U;
                vlSelfRef.PCUpdate = 1U;
                if (((0xbU == (IData)(vlSelfRef.mcause)) 
                     | (3U == (IData)(vlSelfRef.mcause)))) {
                    vlSelfRef.done_ecall = (0xbU == (IData)(vlSelfRef.mcause));
                    vlSelfRef.done_ebreak = (3U == (IData)(vlSelfRef.mcause));
                }
                Vtop___024root____Vdpiimwrap_top__DOT__ctrl__DOT__check_TOP(vlSelfRef.a0_r, (IData)(vlSelfRef.mcause));
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
            if ((0U == (3U & vlSelfRef.alupcOut))) {
                vlSelfRef.MemWrite = 1U;
                vlSelfRef.done_SW = 1U;
            }
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
    vlSelfRef.__Vtableidx2 = (((0x40U & (vlSelfRef.oldpcout 
                                         << 1U)) | 
                               (0x20U & (vlSelfRef.oldpcout 
                                         >> 0x19U))) 
                              | ((0x1cU & (vlSelfRef.oldpcout 
                                           >> 0xaU)) 
                                 | (IData)(vlSelfRef.top__DOT__ctrl__DOT__AluOp)));
    vlSelfRef.aluControl = Vtop__ConstPool__TABLE_h35a41688_0
        [vlSelfRef.__Vtableidx2];
    vlSelfRef.aluOut = ((8U & (IData)(vlSelfRef.aluControl))
                         ? ((4U & (IData)(vlSelfRef.aluControl))
                             ? 0U : ((2U & (IData)(vlSelfRef.aluControl))
                                      ? 0U : ((1U & (IData)(vlSelfRef.aluControl))
                                               ? VL_SHIFTRS_III(32,32,5, vlSelfRef.SrcAout, 
                                                                (0x1fU 
                                                                 & vlSelfRef.SrcBout))
                                               : (vlSelfRef.SrcAout 
                                                  >> 
                                                  (0x1fU 
                                                   & vlSelfRef.SrcBout)))))
                         : ((4U & (IData)(vlSelfRef.aluControl))
                             ? ((2U & (IData)(vlSelfRef.aluControl))
                                 ? ((1U & (IData)(vlSelfRef.aluControl))
                                     ? (vlSelfRef.SrcAout 
                                        << (0x1fU & vlSelfRef.SrcBout))
                                     : (vlSelfRef.SrcAout 
                                        < vlSelfRef.SrcBout))
                                 : ((1U & (IData)(vlSelfRef.aluControl))
                                     ? VL_LTS_III(32, vlSelfRef.SrcAout, vlSelfRef.SrcBout)
                                     : (vlSelfRef.SrcAout 
                                        ^ vlSelfRef.SrcBout)))
                             : ((2U & (IData)(vlSelfRef.aluControl))
                                 ? ((1U & (IData)(vlSelfRef.aluControl))
                                     ? (vlSelfRef.SrcAout 
                                        | vlSelfRef.SrcBout)
                                     : (vlSelfRef.SrcAout 
                                        & vlSelfRef.SrcBout))
                                 : ((1U & (IData)(vlSelfRef.aluControl))
                                     ? (vlSelfRef.SrcAout 
                                        - vlSelfRef.SrcBout)
                                     : (vlSelfRef.SrcAout 
                                        + vlSelfRef.SrcBout)))));
    vlSelfRef.zero = (0U == vlSelfRef.aluOut);
    vlSelfRef.ResultOut = ((2U & (IData)(vlSelfRef.ResultSrc))
                            ? ((1U & (IData)(vlSelfRef.ResultSrc))
                                ? ((0x300U == (vlSelfRef.oldpcout 
                                               >> 0x14U))
                                    ? vlSelfRef.top__DOT__csr_file__DOT__mstatus
                                    : ((0x305U == (vlSelfRef.oldpcout 
                                                   >> 0x14U))
                                        ? vlSelfRef.top__DOT__csr_file__DOT__mtvec
                                        : ((0x341U 
                                            == (vlSelfRef.oldpcout 
                                                >> 0x14U))
                                            ? vlSelfRef.top__DOT__csr_file__DOT__mepc
                                            : ((0x342U 
                                                == 
                                                (vlSelfRef.oldpcout 
                                                 >> 0x14U))
                                                ? vlSelfRef.top__DOT__csr_file__DOT__mcause
                                                : 0U))))
                                : vlSelfRef.aluOut)
                            : ((1U & (IData)(vlSelfRef.ResultSrc))
                                ? vlSelfRef.pcdata_out
                                : vlSelfRef.alupcOut));
    vlSelfRef.PCWrite = (((IData)(vlSelfRef.zero) & (IData)(vlSelfRef.top__DOT__ctrl__DOT__branch)) 
                         | (IData)(vlSelfRef.PCUpdate));
    vlSelfRef.Adr = ((IData)(vlSelfRef.AdrSrc) ? vlSelfRef.ResultOut
                      : vlSelfRef.pcout);
    vlSelfRef.meminstr = vlSelfRef.top__DOT__mem__DOT__RAM
        [(0x7fffU & (vlSelfRef.Adr >> 2U))];
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
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->a0_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10609512055453410243ull);
    vlSelf->einstr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9949080810886720546ull);
    vlSelf->meminstr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7737354207632777992ull);
    vlSelf->rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10211807078052224816ull);
    vlSelf->rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 392999376545494891ull);
    vlSelf->aluOut = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14127704142194359740ull);
    vlSelf->done_LW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14398331097036821129ull);
    vlSelf->done_SW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6185458038022065825ull);
    vlSelf->done_ALUWB = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9852553515879372679ull);
    vlSelf->done_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11029980450714703986ull);
    vlSelf->done_ebreak = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16088307856726096434ull);
    vlSelf->mcause = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16155705988360301293ull);
    vlSelf->done_beq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11637277983468752799ull);
    vlSelf->SrcBout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4457485679041005038ull);
    vlSelf->SrcAout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4885819868761760879ull);
    vlSelf->IRWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7021792388536529238ull);
    vlSelf->PCWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5049867245517871442ull);
    vlSelf->zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10977623970759875275ull);
    vlSelf->aluControl = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4196393585441991743ull);
    vlSelf->rd1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17799039119707404610ull);
    vlSelf->ALUSrcB = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9734336927073461080ull);
    vlSelf->rd2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2192887466570307254ull);
    vlSelf->state_out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16606792248447486632ull);
    vlSelf->ResultOut = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2378364664761479279ull);
    vlSelf->out_A = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4622712308912541322ull);
    vlSelf->MemWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6222392603918024337ull);
    vlSelf->AdrSrc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2445725712452279387ull);
    vlSelf->immSrc = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4894350503001750606ull);
    vlSelf->ALUSrcA = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13925654647321695299ull);
    vlSelf->ResultSrc = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2013901377351345292ull);
    vlSelf->regWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 491965822040281149ull);
    vlSelf->WriteData = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11254409076074583820ull);
    vlSelf->immext = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12903128583594743664ull);
    vlSelf->instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 682939282188807998ull);
    vlSelf->pcdata_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10228772938302877288ull);
    vlSelf->pcout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8847072256216935429ull);
    vlSelf->oldpcout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17239322413986662059ull);
    vlSelf->alupcOut = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14854808646453319148ull);
    vlSelf->Adr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9835380547535747127ull);
    vlSelf->PCUpdate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6279084686125224792ull);
    vlSelf->rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10303652599525973633ull);
    vlSelf->top__DOT__trap_entry_sig = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16762477408237769156ull);
    vlSelf->top__DOT__trap_pc_sig = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15699410896312765860ull);
    vlSelf->top__DOT__mret_sig = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5814593137499753342ull);
    vlSelf->top__DOT__PCSrc = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16393859846596586319ull);
    for (int __Vi0 = 0; __Vi0 < 32768; ++__Vi0) {
        vlSelf->top__DOT__mem__DOT__RAM[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8223382214102425535ull);
    }
    vlSelf->top__DOT__mem__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14783101309445953307ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13817763600422858175ull);
    }
    vlSelf->top__DOT__regfile__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 359023935312308890ull);
    vlSelf->top__DOT__csr_file__DOT__mstatus = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9243236759243020876ull);
    vlSelf->top__DOT__csr_file__DOT__mtvec = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4326776596953901489ull);
    vlSelf->top__DOT__csr_file__DOT__mepc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16314108940703746349ull);
    vlSelf->top__DOT__csr_file__DOT__mcause = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8775787988484342662ull);
    vlSelf->top__DOT__ctrl__DOT__AluOp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16887618103599544084ull);
    vlSelf->top__DOT__ctrl__DOT__branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8974239807218080815ull);
    vlSelf->top__DOT__ctrl__DOT__mcause_next = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6362621806783722777ull);
    vlSelf->top__DOT__ctrl__DOT__current_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 992541622123536085ull);
    vlSelf->top__DOT__ctrl__DOT__next_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6043663484500188800ull);
    vlSelf->top__DOT__ctrl__DOT__saved_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14568474224799150704ull);
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtableidx2 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3495601893105415319ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
