import re
import sys

# Define target instructions by their opcodes and function codes
target_instruction_patterns = {
    # R-type
    'add':    lambda x: (x & 0x7F) == 0x33 and ((x >> 12) & 0x7) == 0x0 and ((x >> 25) & 0x7F) == 0x00,
    'sub':    lambda x: (x & 0x7F) == 0x33 and ((x >> 12) & 0x7) == 0x0 and ((x >> 25) & 0x7F) == 0x20,
    'and':    lambda x: (x & 0x7F) == 0x33 and ((x >> 12) & 0x7) == 0x7 and ((x >> 25) & 0x7F) == 0x00,
    'or':     lambda x: (x & 0x7F) == 0x33 and ((x >> 12) & 0x7) == 0x6 and ((x >> 25) & 0x7F) == 0x00,
    'xor':    lambda x: (x & 0x7F) == 0x33 and ((x >> 12) & 0x7) == 0x4 and ((x >> 25) & 0x7F) == 0x00,
    'slt':    lambda x: (x & 0x7F) == 0x33 and ((x >> 12) & 0x7) == 0x2 and ((x >> 25) & 0x7F) == 0x00,
    'sll':    lambda x: (x & 0x7F) == 0x33 and ((x >> 12) & 0x7) == 0x1 and ((x >> 25) & 0x7F) == 0x00,
    'srl':    lambda x: (x & 0x7F) == 0x33 and ((x >> 12) & 0x7) == 0x5 and ((x >> 25) & 0x7F) == 0x00,
    
    # I-type
    'addi':   lambda x: (x & 0x7F) == 0x13 and ((x >> 12) & 0x7) == 0x0,
    'slti':   lambda x: (x & 0x7F) == 0x13 and ((x >> 12) & 0x7) == 0x2,
    'slli':   lambda x: (x & 0x7F) == 0x13 and ((x >> 12) & 0x7) == 0x1 and ((x >> 25) & 0x7F) == 0x00,
    'srli':   lambda x: (x & 0x7F) == 0x13 and ((x >> 12) & 0x7) == 0x5 and ((x >> 25) & 0x7F) == 0x00,
    'ori':    lambda x: (x & 0x7F) == 0x13 and ((x >> 12) & 0x7) == 0x6,
    'xori':   lambda x: (x & 0x7F) == 0x13 and ((x >> 12) & 0x7) == 0x4,
    
    # Load/Store
    'lw':     lambda x: (x & 0x7F) == 0x03 and ((x >> 12) & 0x7) == 0x2,
    'sw':     lambda x: (x & 0x7F) == 0x23 and ((x >> 12) & 0x7) == 0x2,
    
    # Branch
    'beq':    lambda x: (x & 0x7F) == 0x63 and ((x >> 12) & 0x7) == 0x0,
    
    # Jump
    'jal':    lambda x: (x & 0x7F) == 0x6F,
    
    # System
    'ecall':  lambda x: x == 0x73,  # 0x00000073
    'ebreak': lambda x: x == 0x100073,  # 0x00100073
}

def extract_instructions(input_file, output_file):
    # Regular expression to match instruction lines
    pattern = re.compile(r'^\s*([0-9a-f]+):\s+([0-9a-f]+)\s+(.+)')
    
    try:
        with open(input_file, 'r') as f:
            lines = f.readlines()
    except FileNotFoundError:
        print(f"Error: Input file '{input_file}' not found.")
        sys.exit(1)
    
    extracted_lines = []
    
    for line in lines:
        match = pattern.match(line)
        if match:
            address = match.group(1)
            machine_code_hex = match.group(2)
            instruction_text = match.group(3).strip()
            
            # Convert hex instruction to integer
            try:
                machine_code_int = int(machine_code_hex, 16)
            except ValueError:
                continue
            
            # Check if this instruction matches any of our target patterns
            for instr_name, pattern_func in target_instruction_patterns.items():
                if pattern_func(machine_code_int):
                    extracted_lines.append(f"{machine_code_hex}  // {instruction_text}")
                    break
    
    # Write the extracted instructions to the output file
    try:
        with open(output_file, 'w') as f:
            for line in extracted_lines:
                f.write(line + '\n')
        print(f"Extracted {len(extracted_lines)} instructions to {output_file}")
    except:
        print(f"Error: Could not write to output file '{output_file}'.")
        sys.exit(1)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python extract_instructions.py input_file [output_file]")
        sys.exit(1)
    
    input_file = sys.argv[1]
    
    # Use a default output filename if none is provided
    if len(sys.argv) >= 3:
        output_file = sys.argv[2]
    else:
        # Create output filename based on input filename
        if '/' in input_file:
            base_name = input_file.split('/')[-1]
        else:
            base_name = input_file
        output_file = f"{base_name}_filtered.txt"
    
    extract_instructions(input_file, output_file)
