`default_nettype none

module maindec  (
  input wire [5:0]  op,
  output wire       memtoreg,
  output wire       memwrite,
  output wire       branch,
  output wire       alusrc,
  output wire       regdst,
  output wire       regwrite,
  output wire       jump,
  output wire [1:0] aluop);
  
  reg[8:0] controls;

  assign {regwrite, regdst, alusrc, branch, memwrite, memtoreg, jump, aluop} 
    = controls;
  
  always @ (*)
    case (op)
      6'b000000: controls = 9'b110000010; // Rtyp
      6'b100011: controls = 9'b101001000; // LW
      6'b101011: controls = 9'b001010000; // SW
      6'b000100: controls = 9'b000100001; // BEQ
      6'b001000: controls = 9'b101000000; // ADDI
      6'b000010: controls = 9'b000000100; // J
      default:   controls = 9'bxxxxxxxxx; // ???      
    endcase
  
endmodule