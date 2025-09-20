# RISC-V Multicycle Processor with Verification

A comprehensive RISC-V multicycle processor implementation in Verilog with extensive verification infrastructure using the official RISC-V test suite.

## Overview

This project implements a multicycle RISC-V processor that supports a subset of the RV32I instruction set architecture. The design follows a traditional multicycle datapath with separate phases for instruction fetch, decode, execute, memory access, and writeback. The processor is verified against the official RISC-V test suite to ensure correctness and compliance.

## Architecture

### Key Components

- **`top.v`**: Top-level module integrating all processor components
- **`Control_Unit.v`**: Finite State Machine (FSM) based control unit managing instruction execution phases
- **`ALU.v`**: 32-bit Arithmetic Logic Unit supporting arithmetic and logical operations
- **`ALUdec.v`**: ALU control decoder generating ALU operation codes
- **`Reg_file.v`**: 32-register register file (x0-x31) with dual read ports and one write port
- **`decoder.v`**: Instruction decoder with immediate extension logic
- **`instrmemory.v`**: Unified instruction and data memory (Harvard-style access)
- **`dff_en.v`** / **`dff_clk.v`**: Edge-triggered flip-flops with enable signals

### Multicycle Datapath States

The processor operates through multiple clock cycles per instruction:

1. **S0 (Fetch)**: Fetch instruction from memory using PC
2. **S1 (Decode)**: Decode instruction and read registers
3. **S2 (Memory Address)**: Calculate memory addresses for load/store
4. **S3 (Memory Read)**: Read data from memory (load instructions)
5. **S4 (Memory Writeback)**: Write loaded data to register file
6. **S5 (Memory Write)**: Write data to memory (store instructions)
7. **S6 (Execute)**: Execute R-type operations
8. **S7 (ALU Writeback)**: Write ALU result to register file
9. **S8 (I-type Execute)**: Execute immediate operations
10. **S9 (Jump)**: Handle JAL instructions
11. **S10 (Branch)**: Handle branch instructions

## Supported Instruction Set

### R-Type Instructions
- `ADD` - Add registers
- `SUB` - Subtract registers
- `AND` - Bitwise AND
- `OR` - Bitwise OR
- `XOR` - Bitwise XOR
- `SLT` - Set less than
- `SLL` - Shift left logical
- `SRL` - Shift right logical

### I-Type Instructions
- `ADDI` - Add immediate
- `SLTI` - Set less than immediate
- `ORI` - OR immediate
- `XORI` - XOR immediate
- `SLLI` - Shift left logical immediate
- `SRLI` - Shift right logical immediate

### Load/Store Instructions
- `LW` - Load word
- `SW` - Store word

### Control Flow Instructions
- `BEQ` - Branch if equal
- `JAL` - Jump and link

### System Instructions
- `ECALL` - Environment call
- `EBREAK` - Environment break

## Prerequisites

### Required Tools
- **Verilator**: Verilog simulator (version 4.0 or later)
- **GCC**: C++ compiler for testbench compilation
- **Python 3**: For test conversion utilities
- **Make**: Build system
- **GTKWave**: Waveform viewer (optional, for debugging)

### Installation on Ubuntu/Debian
```bash
sudo apt update
sudo apt install verilator gcc python3 make gtkwave
```

### Installation on macOS
```bash
brew install verilator gcc python3 make gtkwave
```

## Quick Start

### 1. Clone the Repository
```bash
git clone https://github.com/Almas00222/RISCV-Multicycle-Verified.git
cd RISCV-Multicycle-Verified
```

### 2. Initialize Submodules
```bash
git submodule update --init --recursive
```

### 3. Build and Run
```bash
# Prepare output directories
make prepare-directories

# Run simulation with default test
make

# Or run with a specific test
make rv-test
```

## Build System

The project uses a Makefile-based build system with the following targets:

### Primary Targets

- **`make`**: Build and run simulation with the current test
- **`make rv-test`**: Interactive test selection and execution
- **`make prepare-directories`**: Create necessary output directories
- **`make clean`**: Remove build artifacts

### Build Process

1. **C Compilation**: Compile DPI functions (`dpi_functions.c`)
2. **Verilator**: Generate C++ simulation model from Verilog sources
3. **Simulation**: Execute testbench and generate results
4. **Output**: Test results saved to `./results/` directory

## Testing and Verification

### Test Infrastructure

The processor is verified using the official RISC-V test suite with the following components:

- **RISC-V Tests**: Official compliance tests from `riscv-software-src/riscv-tests`
- **Test Converter**: Python script (`test/converter.py`) converts assembly dumps to hex format
- **Testbench**: C++ testbench (`test/tb/testbench.cpp`) using Verilator
- **DPI Functions**: C functions (`test/tb/dpi_functions.c`) for result checking

### Running Tests

#### Interactive Test Selection
```bash
make rv-test
```
This will:
1. Display available tests
2. Prompt for test selection
3. Convert test to hex format
4. Run simulation
5. Display results

#### Available Test Categories
- **rv32ui-p-***: RV32 user-level integer tests
- **rv32mi-p-***: RV32 machine-level integer tests
- **rv64ui-p-***: RV64 user-level integer tests
- **rv64mi-p-***: RV64 machine-level integer tests

### Test Results

Test results are automatically saved to `./results/` with the format:
```
[test_name]-result.txt
```

Results show:
- **PASS**: Test completed successfully
- **FAIL**: Test failed (a0 register = 1)
- **UNDEFINED**: Unexpected value in a0 register

### Waveform Analysis

VCD waveform files are generated for each simulation:
```bash
gtkwave waveform.vcd
```

## Directory Structure

```
RISCV-Multicycle-Verified/
├── rtl/                    # RTL source files
│   ├── top.v              # Top-level module
│   ├── Control_Unit.v     # FSM control unit
│   ├── ALU.v              # Arithmetic Logic Unit
│   ├── ALUdec.v           # ALU decoder
│   ├── Reg_file.v         # Register file
│   ├── decoder.v          # Instruction decoder
│   ├── instrmemory.v      # Instruction/data memory
│   ├── dff_en.v           # Enabled flip-flop
│   └── dff_clk.v          # Clock flip-flop
├── test/                  # Test infrastructure
│   ├── tb/                # Testbench files
│   │   ├── testbench.cpp  # Main C++ testbench
│   │   └── dpi_functions.c # DPI utility functions
│   └── converter.py       # Test format converter
├── riscv-tests/           # Official RISC-V test suite (submodule)
├── instructions/          # Converted test hex files
├── results/               # Test execution results
├── Makefile               # Build system
└── README.md              # This file
```

## Design Details

### Control Unit FSM

The control unit implements a finite state machine with states corresponding to different phases of instruction execution. Key control signals include:

- **PCWrite**: Enable PC update
- **IRWrite**: Enable instruction register write
- **RegWrite**: Enable register file write
- **MemWrite**: Enable memory write
- **ALUSrcA/B**: ALU input source selection
- **ResultSrc**: Result multiplexer selection
- **AdrSrc**: Address source selection

### Memory Organization

- **Address Space**: 32-bit byte-addressable
- **Memory Size**: 2048 words (8KB)
- **Access Pattern**: Word-aligned (32-bit) access
- **Initialization**: Hex file loaded at startup

### Register File

- **Registers**: 32 × 32-bit registers (x0-x31)
- **x0 Hardwired**: Always reads zero
- **x10 (a0)**: Used for test result communication
- **Ports**: 2 read ports, 1 write port

## Debugging and Development

### Simulation Control

Key simulation parameters in `testbench.cpp`:
- **MAX_SIM_TIME**: Maximum simulation cycles (default: 10000)
- **Reset Duration**: Reset active for first 100 time units

### Debug Outputs

The top-level module exposes various debug signals:
- **state_out**: Current FSM state
- **aluOut**: ALU result
- **done_***: Instruction completion flags
- **mcause**: Exception cause code

### Adding New Instructions

To add support for new instructions:

1. **Update Converter**: Add instruction pattern to `test/converter.py`
2. **Modify Control Unit**: Add new states and control signals
3. **Extend ALU**: Add new operations if required
4. **Update Decoder**: Handle new instruction formats

## Performance Characteristics

- **Clock Cycles per Instruction (CPI)**: Varies by instruction type
  - Load: 5 cycles
  - Store: 4 cycles
  - R-type: 4 cycles
  - I-type: 4 cycles
  - Branch: 3 cycles
  - Jump: 3 cycles

- **Critical Path**: Typically through ALU or memory access
- **Maximum Frequency**: Depends on synthesis tool and target technology

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests for new functionality
5. Ensure all existing tests pass
6. Submit a pull request

## License

This project is open source. Please refer to the LICENSE file for specific terms.

## References

- [RISC-V Specification](https://riscv.org/specifications/)
- [RISC-V Test Suite](https://github.com/riscv-software-src/riscv-tests)
- [Verilator Documentation](https://verilator.org/guide/latest/)
- [Computer Organization and Design RISC-V Edition](https://www.elsevier.com/books/computer-organization-and-design-risc-v-edition/patterson/978-0-12-812275-4)

## Contact

For questions or issues, please open a GitHub issue or contact the repository maintainer.