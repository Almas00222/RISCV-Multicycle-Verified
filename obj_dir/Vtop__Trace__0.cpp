// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.top__DOT__regfile__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+1,(vlSelfRef.top__DOT__regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.top__DOT__regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.top__DOT__regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.top__DOT__regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.top__DOT__regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.top__DOT__regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.top__DOT__regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.top__DOT__regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.top__DOT__regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.top__DOT__regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.top__DOT__regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.top__DOT__regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.top__DOT__regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.top__DOT__regfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.top__DOT__regfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__regfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__regfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__regfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.top__DOT__regfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__regfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.top__DOT__regfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.top__DOT__regfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__regfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__regfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__regfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__regfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__regfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__regfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__regfile__DOT__rf[31]),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__alutrans__DOT__sum),32);
        bufp->chgCData(oldp+34,(vlSelfRef.top__DOT__ctrl__DOT__AluOp),2);
        bufp->chgBit(oldp+35,(vlSelfRef.top__DOT__ctrl__DOT__branch));
        bufp->chgCData(oldp+36,(vlSelfRef.top__DOT__ctrl__DOT__current_state),4);
        bufp->chgCData(oldp+37,(vlSelfRef.top__DOT__ctrl__DOT__next_state),4);
    }
    bufp->chgBit(oldp+38,(vlSelfRef.clk));
    bufp->chgBit(oldp+39,(vlSelfRef.rst));
    bufp->chgCData(oldp+40,(vlSelfRef.a0_r),8);
    bufp->chgCData(oldp+41,(vlSelfRef.einstr),5);
    bufp->chgIData(oldp+42,(vlSelfRef.meminstr),32);
    bufp->chgCData(oldp+43,(vlSelfRef.rs1),5);
    bufp->chgCData(oldp+44,(vlSelfRef.rs2),5);
    bufp->chgIData(oldp+45,(vlSelfRef.aluOut),32);
    bufp->chgBit(oldp+46,(vlSelfRef.done_LW));
    bufp->chgBit(oldp+47,(vlSelfRef.done_SW));
    bufp->chgBit(oldp+48,(vlSelfRef.done_ALUWB));
    bufp->chgBit(oldp+49,(vlSelfRef.done_ecall));
    bufp->chgBit(oldp+50,(vlSelfRef.done_ebreak));
    bufp->chgCData(oldp+51,(vlSelfRef.mcause),4);
    bufp->chgBit(oldp+52,(vlSelfRef.done_beq));
    bufp->chgIData(oldp+53,(vlSelfRef.SrcBout),32);
    bufp->chgIData(oldp+54,(vlSelfRef.SrcAout),32);
    bufp->chgBit(oldp+55,(vlSelfRef.IRWrite));
    bufp->chgBit(oldp+56,(vlSelfRef.PCWrite));
    bufp->chgBit(oldp+57,(vlSelfRef.zero));
    bufp->chgCData(oldp+58,(vlSelfRef.aluControl),3);
    bufp->chgIData(oldp+59,(vlSelfRef.rd1),32);
    bufp->chgCData(oldp+60,(vlSelfRef.ALUSrcB),2);
    bufp->chgIData(oldp+61,(vlSelfRef.rd2),32);
    bufp->chgCData(oldp+62,(vlSelfRef.state_out),4);
    bufp->chgIData(oldp+63,(vlSelfRef.ResultOut),32);
    bufp->chgIData(oldp+64,(vlSelfRef.out_A),32);
    bufp->chgBit(oldp+65,(vlSelfRef.MemWrite));
    bufp->chgBit(oldp+66,(vlSelfRef.AdrSrc));
    bufp->chgCData(oldp+67,(vlSelfRef.immSrc),2);
    bufp->chgCData(oldp+68,(vlSelfRef.ALUSrcA),2);
    bufp->chgCData(oldp+69,(vlSelfRef.ResultSrc),2);
    bufp->chgBit(oldp+70,(vlSelfRef.regWrite));
    bufp->chgIData(oldp+71,(vlSelfRef.WriteData),32);
    bufp->chgIData(oldp+72,(vlSelfRef.immext),32);
    bufp->chgIData(oldp+73,(vlSelfRef.instr),32);
    bufp->chgIData(oldp+74,(vlSelfRef.pcdata_out),32);
    bufp->chgIData(oldp+75,(vlSelfRef.pcout),32);
    bufp->chgIData(oldp+76,(vlSelfRef.oldpcout),32);
    bufp->chgIData(oldp+77,(vlSelfRef.alupcOut),32);
    bufp->chgIData(oldp+78,(vlSelfRef.Adr),32);
    bufp->chgBit(oldp+79,(vlSelfRef.PCUpdate));
    bufp->chgCData(oldp+80,(vlSelfRef.rd),5);
    bufp->chgIData(oldp+81,(((1U & (IData)(vlSelfRef.aluControl))
                              ? (~ vlSelfRef.SrcBout)
                              : vlSelfRef.SrcBout)),32);
    bufp->chgBit(oldp+82,((1U & ((IData)((0U == (6U 
                                                 & (IData)(vlSelfRef.aluControl)))) 
                                 | (IData)((0U == (3U 
                                                   & (IData)(vlSelfRef.aluControl))))))));
    bufp->chgBit(oldp+83,((1U & ((~ ((IData)(vlSelfRef.aluControl) 
                                     ^ ((vlSelfRef.SrcAout 
                                         ^ vlSelfRef.SrcBout) 
                                        >> 0x1fU))) 
                                 & (((vlSelfRef.SrcAout 
                                      ^ vlSelfRef.top__DOT__alutrans__DOT__sum) 
                                     >> 0x1fU) & ((IData)(
                                                          (0U 
                                                           == 
                                                           (6U 
                                                            & (IData)(vlSelfRef.aluControl)))) 
                                                  | (IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSelfRef.aluControl))))))))));
    bufp->chgCData(oldp+84,((0x7fU & vlSelfRef.oldpcout)),7);
    bufp->chgBit(oldp+85,((1U & (vlSelfRef.oldpcout 
                                 >> 0x1eU))));
    bufp->chgCData(oldp+86,((7U & (vlSelfRef.oldpcout 
                                   >> 0xcU))),3);
    bufp->chgBit(oldp+87,((1U & (vlSelfRef.oldpcout 
                                 >> 5U))));
    bufp->chgBit(oldp+88,((IData)((0x40000020U == (0x40000020U 
                                                   & vlSelfRef.oldpcout)))));
    bufp->chgIData(oldp+89,((vlSelfRef.oldpcout >> 7U)),25);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
