module ALUdec(
    input [2:0] funct3,
    input opb5,
    input funct7b5,
    input [1:0] aluop,
    output reg [3:0] aluselect
);
    
    localparam [3:0] ALU_ADD  = 4'b0000;
    localparam [3:0] ALU_SUB  = 4'b0001;
    localparam [3:0] ALU_AND  = 4'b0010;
    localparam [3:0] ALU_OR   = 4'b0011;
    localparam [3:0] ALU_XOR  = 4'b0100;
    localparam [3:0] ALU_SLT  = 4'b0101;
    localparam [3:0] ALU_SLTU = 4'b0110;
    localparam [3:0] ALU_SLL  = 4'b0111;
    localparam [3:0] ALU_SRL  = 4'b1000;
    localparam [3:0] ALU_SRA  = 4'b1001;

    always @(*) begin
        case (aluop)
            2'b00: begin
                aluselect = ALU_ADD;
            end
            2'b01: begin
                aluselect = ALU_SUB;
            end
            default: begin
                case (funct3)
                    3'b000: begin
                        if (funct7b5 && opb5) begin
                            aluselect = ALU_SUB; // SUB
                        end else begin
                            aluselect = ALU_ADD; // ADD, ADDI
                        end
                    end
                    3'b001: begin
                        aluselect = ALU_SLL; // SLL, SLLI
                    end
                    3'b010: begin
                        aluselect = ALU_SLT; // SLT, SLTI
                    end
                    3'b011: begin
                        aluselect = ALU_SLTU; // SLTU, SLTIU
                    end
                    3'b100: begin
                        aluselect = ALU_XOR; // XOR, XORI
                    end
                    3'b101: begin
                        aluselect = funct7b5 ? ALU_SRA : ALU_SRL; // SRL/SRA
                    end
                    3'b110: begin
                        aluselect = ALU_OR;  // OR, ORI
                    end
                    3'b111: begin
                        aluselect = ALU_AND; // AND, ANDI
                    end
                    default: begin
                        aluselect = ALU_ADD;
                    end
                endcase
            end
        endcase
    end
endmodule

