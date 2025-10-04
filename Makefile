RTL_FILES = ./rtl/top.v ./rtl/dff_en.v ./rtl/dff_clk.v ./rtl/Control_Unit.v ./rtl/ALU.v ./rtl/ALUdec.v ./rtl/decoder.v ./rtl/Reg_file.v ./rtl/instrmemory.v ./rtl/CSR.v
TB_FILES = ./test/tb/testbench.cpp ./test/tb/dpi_functions.c

TEST = .test

all:
	gcc -c -o ./dpi_functions.o ./test/tb/dpi_functions.c
	verilator --assert --Wall --cc --trace $(RTL_FILES) --exe $(TB_FILES)
	$(MAKE) -C obj_dir -f Vtop.mk
	if [ -f $(TEST) ]; then \
		test_name=$$(cat $(TEST)) && ./obj_dir/Vtop +MEMFILE=instructions/$$test_name.hex | tee ./results/$$test_name-result.txt; \
	else \
		./obj_dir/Vtop | tee ./results/unknown_test-result.txt; \
	fi

prepare-directories:
	mkdir -p ./results
	mkdir -p ./instructions
	
rv-test:
	@echo "Available tests:"
	@ls -1 ./riscv-tests/isa/*.dump | sed 's|.*/||' | sed 's|\.dump$$||'
	@echo ""
	@read -p "Enter test name: " test_name; \
	echo $$test_name > $(TEST); \
	python3 ./test/converter.py ./riscv-tests/isa/$$test_name.dump ./instructions/$$test_name.hex


clean:
	rm -rf obj_dir
	rm -rf dpi_functions.o
	rm -rf waveform.vcd
