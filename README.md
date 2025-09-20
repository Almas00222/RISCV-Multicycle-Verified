# RISC-V Multicycle Processor - Verified Implementation

A complete implementation of a RISC-V multicycle processor in Verilog, featuring comprehensive verification through the official RISC-V test suite and waveform analysis capabilities.

## Project Overview

This project implements a multicycle RISC-V processor that supports the RV32I base integer instruction set. The design follows a traditional multicycle architecture where each instruction executes over multiple clock cycles, allowing for resource sharing and simplified control logic.

### Key Features

- **Complete RV32I Support**: Implements all base integer instructions including R-type, I-type, load/store, branch, jump, and system instructions
- **Multicycle Architecture**: Optimized design with shared functional units across multiple clock cycles
- **Comprehensive Verification**: Integration with official RISC-V test suite for thorough validation
- **Waveform Analysis**: VCD file generation for detailed signal analysis and debugging
- **Modular Design**: Clean separation of components (ALU, Control Unit, Register File, etc.)

## Architecture

The processor follows a classic multicycle datapath with the following main components:

### Core Components

- **ALU (`rtl/ALU.v`)**: Arithmetic Logic Unit supporting all RV32I operations
- **Control Unit (`rtl/Control_Unit.v`)**: State machine-based controller managing instruction execution
- **Register File (`rtl/Reg_file.v`)**: 32-register file with dual read ports and one write port
- **Instruction Memory (`rtl/instrmemory.v`)**: Combined instruction and data memory
- **Top Module (`rtl/top.v`)**: Main processor integration with all components

### Supporting Modules

- **Decoder (`rtl/decoder.v`)**: Instruction decoding and immediate generation
- **ALU Decoder (`rtl/ALUdec.v`)**: ALU operation selection logic
- **Flip-Flops (`rtl/dff_*.v`)**: Clock-enabled and standard D flip-flops for state storage

### Multicycle States

The processor operates through multiple states for each instruction:
1. **Fetch**: Instruction fetch from memory
2. **Decode**: Instruction decode and register file read
3. **Execute**: ALU operation or address calculation
4. **Memory**: Memory access for load/store instructions
5. **Writeback**: Register file write for result storage

## Supported Instructions

### R-Type Instructions
- `ADD`, `SUB`, `AND`, `OR`, `XOR`, `SLT`, `SLL`, `SRL`

### I-Type Instructions
- `ADDI`, `SLTI`, `SLLI`, `SRLI`, `ORI`, `XORI`

### Load/Store Instructions
- `LW` (Load Word), `SW` (Store Word)

### Branch Instructions
- `BEQ` (Branch if Equal)

### Jump Instructions
- `JAL` (Jump and Link)

### System Instructions
- `ECALL`, `EBREAK`

## Prerequisites

### Required Tools

1. **Verilator** (>= 4.0): Verilog simulator and compiler
   ```bash
   # Ubuntu/Debian
   sudo apt-get install verilator
   
   # macOS (Homebrew)
   brew install verilator
   ```

2. **GCC**: C++ compiler for testbench compilation
   ```bash
   # Ubuntu/Debian
   sudo apt-get install build-essential
   ```

3. **Python 3**: For test conversion utilities
   ```bash
   # Ubuntu/Debian
   sudo apt-get install python3
   ```

4. **GTKWave** (Optional): For waveform viewing
   ```bash
   # Ubuntu/Debian
   sudo apt-get install gtkwave
   ```

### Optional: RISC-V Test Suite

To run the official RISC-V tests, initialize the submodule:
```bash
git submodule update --init --recursive
```

## Build and Run

### Basic Build

1. **Prepare directories**:
   ```bash
   make prepare-directories
   ```

2. **Build and run simulation**:
   ```bash
   make all
   ```

This will:
- Compile the Verilog modules using Verilator
- Build the C++ testbench
- Run the simulation
- Generate `waveform.vcd` for analysis
- Output results to `results/` directory

### Running Specific Tests

1. **List available tests**:
   ```bash
   make rv-test
   ```

2. **Select and run a specific test**:
   The `rv-test` target will prompt you to enter a test name from the available RISC-V tests.

3. **View results**:
   Test results are saved in the `results/` directory with the format `{test_name}-result.txt`.

### Waveform Analysis

After running a simulation:
```bash
gtkwave waveform.vcd
```

This opens the VCD file in GTKWave for detailed signal analysis and debugging.

## File Structure

```
├── rtl/                    # Verilog RTL source files
│   ├── top.v              # Top-level processor module
│   ├── ALU.v              # Arithmetic Logic Unit
│   ├── Control_Unit.v     # Main control logic
│   ├── Reg_file.v         # Register file
│   ├── instrmemory.v      # Instruction/Data memory
│   ├── decoder.v          # Instruction decoder
│   ├── ALUdec.v           # ALU control decoder
│   ├── dff_en.v           # Enabled D flip-flop
│   └── dff_clk.v          # Standard D flip-flop
├── test/                   # Test infrastructure
│   ├── tb/                # Testbench files
│   │   ├── testbench.cpp  # Main C++ testbench
│   │   └── dpi_functions.c # DPI interface functions
│   └── converter.py       # Test file converter
├── results/               # Test results output
├── instructions/          # Converted instruction files
├── riscv-tests/           # Official RISC-V test suite (submodule)
└── Makefile              # Build configuration
```

## Usage Examples

### Basic Simulation
```bash
# Clean previous build
make clean

# Build and run with default test
make all
```

### Running Load/Store Tests
```bash
make rv-test
# Enter: rv32ui-p-lw (when prompted)
```

### Debugging with Waveforms
```bash
make all
gtkwave waveform.vcd
# Navigate to signals in the hierarchy
# Add relevant signals to view timing relationships
```

### Custom Instruction Testing
1. Add your instruction hex codes to `instructions/` directory
2. Modify the testbench to load your instruction file
3. Run simulation and analyze results

## Development and Testing

### Adding New Instructions

1. **Update Control Unit**: Add new states and control signals in `Control_Unit.v`
2. **Modify ALU**: Add operation support in `ALU.v` if needed
3. **Update Decoder**: Add instruction decoding logic in `decoder.v`
4. **Test**: Use RISC-V test suite to verify implementation

### Debugging Tips

1. **Use Waveforms**: Always generate and analyze VCD files for timing issues
2. **Check Control Signals**: Verify control unit state transitions
3. **Monitor Register File**: Check register read/write operations
4. **Validate Memory Access**: Ensure correct address generation and data flow

## Test Results Interpretation

Test output shows:
- `PASS`: Instruction executed correctly
- `UNDEFINED value stored in a0 register`: Expected behavior for test framework
- Cycle count and simulation completion status

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes with appropriate tests
4. Ensure all existing tests still pass
5. Submit a pull request

## License

This project is educational and follows standard academic use guidelines. Please check with the original authors for specific licensing terms.

## Acknowledgments

- RISC-V International for the instruction set architecture
- RISC-V test suite contributors for comprehensive verification tests
- Verilator development team for the simulation framework