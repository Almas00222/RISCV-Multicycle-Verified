# RISC-V Multicycle — Verified 🧪

A compact RISC-V multicycle CPU in Verilog with a Verilator-based test workflow. Pick a test, press build, capture results, and peek at waveforms. Everything’s wired for you — just follow the steps below. 🚀

---

## What you get 🧰

- Multicycle RISC-V CPU (modular RTL)
- Verilator simulation with tracing (`--trace`)
- Official [riscv-tests](https://github.com/riscv-software-src/riscv-tests) integration (git submodule)
- One-command test selection ➜ one-command build+run ➜ auto-saved results

---

## Zero-to-results in minutes ⏱️

```bash
# 1) Clone (with submodules) 👇
git clone --recursive https://github.com/Almas00222/RISCV-Multicycle-Verified.git
cd RISCV-Multicycle-Verified

# If you forgot --recursive:
git submodule update --init --recursive

# 2) Create folders used by the flow 📂
make prepare-directories

# 3) Pick a test interactively (lists available ones, then prompts you) 📝
make rv-test

# 4) Build + simulate 🏃
make all

# 5) Optional: open the waveform 👀
gtkwave waveform.vcd
```

Outputs:
- Results: `results/<your-test>-result.txt`
- Waveform: `waveform.vcd` (if emitted by the testbench)

If you didn’t select a test, results go to `results/unknown_test-result.txt`.

---

## Requirements ⚙️

- Verilator
- GCC / G++ (Linux: `build-essential`)
- Python 3
- make
- Optional: GTKWave (view `.vcd`)

Install examples:

- Ubuntu/Debian:
  ```bash
  sudo apt update
  sudo apt install -y verilator build-essential python3 make gtkwave
  ```

- macOS (Homebrew):
  ```bash
  brew install verilator gcc python make gtkwave
  ```

- Windows:
  - Use WSL (Ubuntu recommended), then follow the Ubuntu steps.

Confirm tools:
```bash
verilator --version
python3 --version
make --version
gcc --version
```

---

## Repository map 🗺️

```
├── Makefile
├── .test                      # Auto-created: remembers your chosen test (just the name, no extension)
├── instructions/              # Generated .hex programs
├── results/                   # Simulation logs per test
├── riscv-tests/               # Official ISA tests (git submodule)
├── rtl/                       # CPU RTL
│   ├── top.v
│   ├── dff_en.v
│   ├── dff_clk.v
│   ├── Control_Unit.v
│   ├── ALU.v
│   ├── ALUdec.v
│   ├── decoder.v
│   ├── Reg_file.v
│   └── instrmemory.v
└── test/
    ├── converter.py           # Converts riscv-tests *.dump -> *.hex
    └── tb/
        ├── testbench.cpp      # Verilator C++ testbench
        └── dpi_functions.c    # DPI helper functions
```

---

## Make targets you’ll use 🛠️

- make prepare-directories
  - Creates `instructions/` and `results/`.

- make rv-test
  - Lists `riscv-tests/isa/*.dump`.
  - Prompts you for a test name (e.g., `rv32ui-p-addi`).
  - Writes the name to `.test`.
  - Converts `.dump` ➜ `.hex` via `test/converter.py`.

- make all
  - Compiles DPI helpers.
  - Runs Verilator (`--assert --Wall --cc --trace`) with RTL + testbench.
  - Builds the simulator and executes it.
  - Saves output to `results/<test>-result.txt` (or `unknown_test-result.txt`).

- make clean
  - Removes `obj_dir/`, `dpi_functions.o`, and `waveform.vcd`.

---

## Non-interactive mode (no prompts) 🧭

Already know the test? Do this:

```bash
echo "rv32ui-p-addi" > .test
python3 ./test/converter.py ./riscv-tests/isa/rv32ui-p-addi.dump ./instructions/rv32ui-p-addi.hex
make all
```

Then inspect:
```bash
sed -n '1,120p' results/rv32ui-p-addi-result.txt
```

---

## Add your own program 🧩

- If you have a riscv-tests-style `.dump`:
  ```bash
  python3 ./test/converter.py path/to/your.dump ./instructions/your.hex
  echo "your" > .test
  make all
  ```

- If you have an ELF:
  - Generate a disassembly (e.g., `objdump -d your.elf > your.dump`) then convert with `converter.py` as above.

- If you already have a `.hex` matching the ROM format:
  ```bash
  cp your.hex ./instructions/your.hex
  echo "your" > .test
  make all
  ```

---

## What’s happening behind the curtain 🧠

- The Makefile compiles `test/tb/dpi_functions.c`, Verilates the RTL, links in `testbench.cpp`, and builds `obj_dir/Vtop`.
- `make rv-test` writes your selection to `.test` and produces `instructions/<test>.hex`.
- The simulator runs and prints status/info. Output is tee’d into `results/<test>-result.txt`.
- If tracing is active in the testbench, `waveform.vcd` is produced for GTKWave.

---

## Troubleshooting 🔧

- “No tests listed in make rv-test”
  - Initialize submodules:
    ```bash
    git submodule update --init --recursive
    ```
  - Ensure `.dump` files exist under `riscv-tests/isa/`.

- Build issues with Verilator
  - Check versions and path:
    ```bash
    verilator --version
    ```
  - Try a clean rebuild:
    ```bash
    make clean
    make all
    ```

- No results file for my chosen test
  - Ensure `.test` contains only the test name (no `.dump` or `.hex` extension).
  - Re-run selection:
    ```bash
    make rv-test
    make all
    ```

- Waveform missing
  - The Makefile passes `--trace`; ensure the testbench emits a VCD.
  - Then:
    ```bash
    make clean
    make all
    gtkwave waveform.vcd
    ```

- Permission denied when running `obj_dir/Vtop`
  ```bash
  chmod +x obj_dir/Vtop
  ```

- On Windows
  - Use WSL (Ubuntu). Verify file paths don’t include Windows-style separators.

---

## Pro tips 💡

- Speed up C++ build:
  ```bash
  export MAKEFLAGS=-j"$(nproc)"   # Linux
  ```
- Switch tests quickly:
  ```bash
  echo "rv32ui-p-sub" > .test
  python3 ./test/converter.py ./riscv-tests/isa/rv32ui-p-sub.dump ./instructions/rv32ui-p-sub.hex
  make all
  ```
- Keep things tidy:
  ```bash
  make clean
  ```

---

## CPU modules at a glance 🔍

- `top.v` — integrates datapath, control, memories
- `Control_Unit.v` — multicycle FSM and control signaling
- `decoder.v` — instruction field extraction
- `ALUdec.v` — ALU operation selection
- `ALU.v` — arithmetic/logic operations
- `Reg_file.v` — 32x register file
- `instrmemory.v` — ROM fed by your generated `.hex`
- `dff_en.v`, `dff_clk.v` — flip-flop primitives

Test infrastructure:
- `testbench.cpp` — drives the DUT and logs outputs
- `dpi_functions.c` — DPI/C glue for I/O
- `converter.py` — `.dump` ➜ `.hex` program image

---

## Contributing 🤝

- Issues and PRs welcome.
- Flow:
  1) Fork
  2) Create a branch
  3) Implement + test
  4) `make all` and inspect `results/`
  5) Open a PR

---

Happy building, simulating, and waveform-watching! 🖥️📈
