#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <verilated.h>
#include <verilated_vcd_c.h>  // Required for VCD dump

#include "Vtop.h"

// Define simulation parameters
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
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);
    
    // Create an instance of the design under test
    Vtop *dut = new Vtop;
    
    // Initialize waveform dumping
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 99);  // Trace 99 levels of hierarchy
    m_trace->open("waveform.vcd");
    
    // Print simulation information
    std::cout << "Starting simulation...\n";
    std::cout << "VCD waveform file: waveform.vcd\n";
    
    // Main simulation loop
    while (sim_time < MAX_SIM_TIME) {
        // Toggle clock
        dut->clk ^= 1;
        
        // Apply reset
        dut_reset(dut, sim_time);
        
        // Evaluate model
        dut->eval();
        
        // Dump waveforms
        m_trace->dump(sim_time);
        
        // Count positive edges of clock
        if (dut->clk == 1) {
            posedge_cnt++;
            
        }
        
        // Increment simulation time
        sim_time++;
    }
    
    // Clean up and exit
    m_trace->close();
    delete m_trace;
    delete dut;
    
    std::cout << "Simulation complete. Total cycles: " << posedge_cnt << "\n";
    std::cout << "To view waveforms, run: gtkwave waveform.vcd\n";
    
    exit(EXIT_SUCCESS);
}
