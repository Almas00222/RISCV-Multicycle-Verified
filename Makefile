RTL_FILES = ./rtl/top.v ./rtl/dff_en.v ./rtl/dff_clk.v ./rtl/Control_Unit.v ./rtl/ALU.v ./rtl/ALUdec.v ./rtl/decoder.v ./rtl/Reg_file.v ./rtl/instrmemory.v
TB_FILES = ./test/tb/testbench.cpp ./test/tb/dpi_functions.c

TEST = .test

all:
	gcc -c -o ./dpi_functions.o ./test/tb/dpi_functions.c
	verilator --assert --Wall --cc --trace $(RTL_FILES) --exe $(TB_FILES)
	$(MAKE) -C obj_dir -f Vtop.mk
	./obj_dir/Vtop | tee ./results/$$test.txt; \

prepare-directories:
	mkdir -p ./results
	mkdir -p ./instructions
	
rv-test:
	@read -p "Enter test name: " test_name; \
	echo $$test_name > $(TEST); \
	python3 converter.py ./riscv-tests/isa/$$test_name.dump ./instructions/$$test_name.hex


clean:
	rm -rf obj_dir
	rm -rf dpi_functions.o
	rm -rf waveform.vcd
