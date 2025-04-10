RTL_FILES = ./rtl/top.v ./rtl/dff_en.v ./rtl/dff_clk.v ./rtl/Control_Unit.v ./rtl/ALU.v ./rtl/ALUdec.v ./rtl/decoder.v ./rtl/Reg_file.v ./rtl/instrmemory.v
TB_FILES = ./test/tb/testbench.cpp ./test/tb/dpi_functions.c

all:
	gcc -c -o ./dpi_functions.o ./test/tb/dpi_functions.c
	verilator --assert --Wall --cc --trace $(RTL_FILES) --exe $(TB_FILES)
	$(MAKE) -C obj_dir -f Vtop.mk
	./obj_dir/Vtop | tee ./results/res.txt

test-rv:
	mkdir -p ./results
	gcc -c -o ./dpi_functions.o ./test/tb/dpi_functions.c
	verilator --assert --Wall --cc --trace $(RTL_FILES) --exe $(TB_FILES)
	$(MAKE) -C obj_dir -f Vtop.mk
	./obj_dir/Vtop | tee ./results/$(TEST).txt

clean:
	rm -rf obj_dir
	rm -rf dpi_functions.o
	rm -rf ./results/*.txt
