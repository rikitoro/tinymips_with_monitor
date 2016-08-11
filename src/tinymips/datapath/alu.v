`default_nettype none

module alu(
  input wire  [31:0] srca,
  input wire  [31:0] srcb,
  input wire  [2:0]  alucontrol,
  output wire [31:0] aluout,
  output wire        zero);

  reg [31:0] result;
  
  assign aluout = result;
  assign zero = (result == 32'b0) ? 1'b1 : 1'b0;
  

  always @ (*)
    case (alucontrol)
      3'b000: result = srca & srcb;            // A AND B
      3'b001: result = srca | srcb;            // A OR B
      3'b010: result = srca + srcb;            // A + B
      3'b011: result = 32'b0;            // not used
      3'b100: result = srca & ~srcb;           // A AND ~B
      3'b101: result = srca | ~srcb;           // A OR ~B
      3'b110: result = srca - srcb;            // A - B
      3'b111: result = {31'b0,(srca < srcb)};  // SLT
    endcase
    
  
endmodule