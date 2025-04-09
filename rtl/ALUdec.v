module ALUdec(
	input [2:0] funct3,
	input opb5,
	input funct7b5,
	input [1:0] aluop,
	output reg [2:0] aluselect
);
	
	wire RtypeSub;
	assign RtypeSub = funct7b5 & opb5;
	
	always @(*) begin
    case (aluop)
        2'b00: begin
            aluselect = 3'b000;
        end
        2'b01: begin
            aluselect = 3'b001;
        end
        default: begin
            case (funct3)
                3'b000: begin
                    if (RtypeSub) begin
                        aluselect = 3'b001; // SUB
                    end else begin
                        aluselect = 3'b000; // ADD, ADDI
                    end
                end
                3'b010: begin
                    aluselect = 3'b101; // SLT, SLTI
                end
                3'b110: begin
                    aluselect = 3'b011;  // OR, ORI
                end
                3'b111: begin
                    aluselect = 3'b010; // AND, ANDI
                end
                default: begin
                    aluselect = 3'bxxx;
                end
            endcase
        end
    endcase
end
endmodule
