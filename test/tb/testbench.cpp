#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <verilated.h>
#include <verilated_vcd_c.h>  // Required for VCD dump

#include "Vtop.h"

#define MAX_SIM_TIME 10000
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

// Reset function for DUT
void dut_reset(Vtop *dut, vluint64_t &sim_time) {
    if (sim_time < 100) {
        dut->rst = 1;
    } else {
        dut->rst = 0;
    }
}

int main(int argc, char** argv, char** env) {
    Verilated::commandArgs(argc, argv);
    
    Vtop *dut = new Vtop;
    
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 99); 
    m_trace->open("waveform.vcd");
    
    // Print simulation information
    std::cout << "Starting simulation...\n";
    std::cout << "VCD waveform file: waveform.vcd\n";
    
    // Main simulation loop
    while (sim_time < MAX_SIM_TIME) {
        dut->clk ^= 1;
        
        dut_reset(dut, sim_time);
        
        dut->eval();
        
        m_trace->dump(sim_time);
        
        if (dut->clk == 1) {
            posedge_cnt++;
            
        }
        
        sim_time++;
    }
    
    m_trace->close();
    delete m_trace;
    delete dut;
    
    std::cout << "Simulation complete. Total cycles: " << posedge_cnt << "\n";
    std::cout << "To view waveforms, run: gtkwave waveform.vcd\n";
    
    exit(EXIT_SUCCESS);
}
