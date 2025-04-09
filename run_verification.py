#!/usr/bin/env python3
import os
import subprocess
import argparse
import sys
import glob
import time

def run_command(command, verbose=True):
    """Run a shell command and return the result."""
    if verbose:
        print(f"Running: {command}")
    
    try:
        process = subprocess.Popen(
            command, 
            shell=True, 
            stdout=subprocess.PIPE, 
            stderr=subprocess.PIPE,
            text=True
        )
        stdout, stderr = process.communicate()
        
        if process.returncode != 0:
            print(f"Command failed with exit code {process.returncode}")
            print(f"Error output:\n{stderr}")
            return False, stdout, stderr
        
        return True, stdout, stderr
    
    except Exception as e:
        print(f"Exception running command: {e}")
        return False, "", str(e)

def verify_test(dump_file, output_dir, verbose=True):
    """Run complete verification flow for a single test."""
    # Extract test name
    test_name = os.path.basename(dump_file).replace('.dump', '')
    
    # Step 1: Process the dump file
    if verbose:
        print(f"\n===== Processing dump file: {test_name} =====")
    
    dump_cmd = f"python3 dump_processor.py --file {dump_file}"
    success, stdout, stderr = run_command(dump_cmd, verbose)
    if not success:
        return False, f"Failed to process dump file: {test_name}"
    
    # Step 2: Compile DPI functions
    if verbose:
        print("\n===== Compiling DPI functions =====")
    
    compile_cmd = "gcc -c -o ./dpi_functions.o ./test/tb/dpi_functions.c"
    success, stdout, stderr = run_command(compile_cmd, verbose)
    if not success:
        return False, f"Failed to compile DPI functions for test: {test_name}"
    
    # Step 3: Run Verilator
    if verbose:
        print("\n===== Running Verilator =====")
    
    verilator_cmd = "verilator --assert --Wall --cc --trace  ./rtl/top.v ./rtl/dff_en.v ./rtl/instrmemory.v ./rtl/dff_clk.v ./rtl/Reg_file.v ./rtl/decoder.v ./rtl/Control_Unit.v ./rtl/ALU.v ./rtl/ALUdec.v --exe ./test/tb/tb_test_env.cpp ./test/tb/dpi_functions.c"
    success, stdout, stderr = run_command(verilator_cmd, verbose)
    if not success:
        return False, f"Verilator failed for test: {test_name}"
    
    # Step 4: Make
    if verbose:
        print("\n===== Running Make =====")
    
    make_cmd = "make -C obj_dir -f Vtop.mk"
    success, stdout, stderr = run_command(make_cmd, verbose)
    if not success:
        return False, f"Make failed for test: {test_name}"
    
    # Step 5: Run simulation
    if verbose:
        print("\n===== Running Simulation =====")
    
    # Create a results directory if it doesn't exist
    results_dir = os.path.join(output_dir, "results")
    os.makedirs(results_dir, exist_ok=True)
    
    # Prepare result file path
    result_file = os.path.join(results_dir, f"{test_name}_result.txt")
    
    # Run the simulation and capture output
    sim_cmd = f"./obj_dir/Vtop | tee {result_file}"
    success, stdout, stderr = run_command(sim_cmd, verbose)
    
    # Analyze the simulation result
    if "PASS" in stdout:
        test_result = "PASS"
    elif "FAIL" in stdout:
        test_result = "FAIL"
    else:
        test_result = "UNDEFINED"
    
    # Step 6: Clean up
    if verbose:
        print("\n===== Cleaning up =====")
    
    cleanup_cmd = "rm -r ./obj_dir dpi_functions.o"
    run_command(cleanup_cmd, verbose)
    
    # Write summary to results file
    with open(os.path.join(results_dir, "summary.txt"), "a") as f:
        f.write(f"{test_name}: {test_result}\n")
    
    return True, f"Test {test_name} completed with result: {test_result}"

def main():
    parser = argparse.ArgumentParser(description='Run RISC-V verification tests.')
    parser.add_argument('--dump-dir', default='/home/almas/riscv-tests/isa',
                       help='Directory containing dump files')
    parser.add_argument('--output-dir', default='/home/almas/MultiCycleLast',
                       help='Output directory for results')
    parser.add_argument('--test', help='Run a specific test file')
    parser.add_argument('--quiet', action='store_true', help='Reduce output verbosity')
    parser.add_argument('--list', action='store_true', help='List available tests without running')
    
    args = parser.parse_args()
    
    # Find all available dump files
    dump_files = glob.glob(os.path.join(args.dump_dir, "**", "*.dump"), recursive=True)
    
    if not dump_files:
        print(f"No .dump files found in {args.dump_dir}")
        return
    
    if args.list:
        print("Available test files:")
        for i, file_path in enumerate(dump_files):
            print(f"{i+1}. {os.path.basename(file_path)}")
        return
    
    # Create output directory if it doesn't exist
    os.makedirs(args.output_dir, exist_ok=True)
    
    # Clear summary file
    summary_path = os.path.join(args.output_dir, "results", "summary.txt")
    if os.path.exists(summary_path):
        os.remove(summary_path)
    
    if args.test:
        # Run a specific test
        if os.path.isfile(args.test):
            test_path = args.test
        else:
            # Try to find the test in the dump directory
            matching_files = [f for f in dump_files if os.path.basename(f) == args.test or 
                              os.path.basename(f).startswith(args.test)]
            
            if not matching_files:
                print(f"Test file not found: {args.test}")
                return
            
            test_path = matching_files[0]
        
        success, message = verify_test(test_path, args.output_dir, not args.quiet)
        print(message)
    else:
        # Show menu of tests
        print("Available tests:")
        for i, file_path in enumerate(dump_files):
            print(f"{i+1}. {os.path.basename(file_path)}")
        
        try:
            selection = input("\nEnter test number to run (or 'a' for all, 'q' to quit): ")
            
            if selection.lower() == 'q':
                return
            elif selection.lower() == 'a':
                # Run all tests
                for file_path in dump_files:
                    success, message = verify_test(file_path, args.output_dir, not args.quiet)
                    print(message)
            else:
                idx = int(selection) - 1
                if 0 <= idx < len(dump_files):
                    success, message = verify_test(dump_files[idx], args.output_dir, not args.quiet)
                    print(message)
                else:
                    print("Invalid selection")
                    
        except ValueError:
            print("Please enter a number or 'a' for all tests")
            return

if __name__ == "__main__":
    main()
