// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_OUT8(a0_r,7,0);
        VL_OUT8(einstr,4,0);
        VL_OUT8(rs1,4,0);
        VL_OUT8(rs2,4,0);
        VL_OUT8(done_LW,0,0);
        VL_OUT8(done_SW,0,0);
        VL_OUT8(done_ALUWB,0,0);
        VL_OUT8(done_ecall,0,0);
        VL_OUT8(done_ebreak,0,0);
        VL_OUT8(mcause,3,0);
        VL_OUT8(done_beq,0,0);
        VL_OUT8(IRWrite,0,0);
        VL_OUT8(PCWrite,0,0);
        VL_OUT8(zero,0,0);
        VL_OUT8(aluControl,3,0);
        VL_OUT8(ALUSrcB,1,0);
        VL_OUT8(state_out,3,0);
        VL_OUT8(MemWrite,0,0);
        VL_OUT8(AdrSrc,0,0);
        VL_OUT8(immSrc,1,0);
        VL_OUT8(ALUSrcA,1,0);
        VL_OUT8(ResultSrc,1,0);
        VL_OUT8(regWrite,0,0);
        VL_OUT8(PCUpdate,0,0);
        VL_OUT8(rd,4,0);
        CData/*0:0*/ top__DOT__trap_entry_sig;
        CData/*0:0*/ top__DOT__mret_sig;
        CData/*1:0*/ top__DOT__PCSrc;
        CData/*1:0*/ top__DOT__ctrl__DOT__AluOp;
        CData/*0:0*/ top__DOT__ctrl__DOT__branch;
        CData/*3:0*/ top__DOT__ctrl__DOT__mcause_next;
        CData/*3:0*/ top__DOT__ctrl__DOT__current_state;
        CData/*3:0*/ top__DOT__ctrl__DOT__next_state;
        CData/*6:0*/ __Vtableidx1;
        CData/*6:0*/ __Vtableidx2;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT(meminstr,31,0);
        VL_OUT(aluOut,31,0);
        VL_OUT(SrcBout,31,0);
        VL_OUT(SrcAout,31,0);
        VL_OUT(rd1,31,0);
        VL_OUT(rd2,31,0);
        VL_OUT(ResultOut,31,0);
        VL_OUT(out_A,31,0);
        VL_OUT(WriteData,31,0);
        VL_OUT(immext,31,0);
        VL_OUT(instr,31,0);
        VL_OUT(pcdata_out,31,0);
        VL_OUT(pcout,31,0);
        VL_OUT(oldpcout,31,0);
        VL_OUT(alupcOut,31,0);
        VL_OUT(Adr,31,0);
        IData/*31:0*/ top__DOT__trap_pc_sig;
        IData/*31:0*/ top__DOT__mem__DOT__i;
        IData/*31:0*/ top__DOT__regfile__DOT__i;
        IData/*31:0*/ top__DOT__csr_file__DOT__mstatus;
        IData/*31:0*/ top__DOT__csr_file__DOT__mtvec;
        IData/*31:0*/ top__DOT__csr_file__DOT__mepc;
        IData/*31:0*/ top__DOT__csr_file__DOT__mcause;
    };
    struct {
        IData/*31:0*/ top__DOT__ctrl__DOT__saved_pc;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 32768> top__DOT__mem__DOT__RAM;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile__DOT__rf;
        VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
