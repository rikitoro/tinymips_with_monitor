`default_nettype none

module hexdata_display(
  input wire  [3:0] hexdata,
  output wire [6:0] hex);
  
  reg[6:0] decoder;
  
  assign hex = ~decoder; // 7seg are active low
  
  always @ (*)
    case (hexdata)
      4'h0    : decoder = 7'b011_1111;
      4'h1    : decoder = 7'b000_0110;
      4'h2    : decoder = 7'b101_1011;
      4'h3    : decoder = 7'b100_1111;
      4'h4    : decoder = 7'b110_0110;
      4'h5    : decoder = 7'b110_1101;
      4'h6    : decoder = 7'b111_1101;
      4'h7    : decoder = 7'b010_0111;
      4'h8    : decoder = 7'b111_1111;
      4'h9    : decoder = 7'b110_1111;
      4'ha    : decoder = 7'b111_0111;
      4'hb    : decoder = 7'b111_1100;
      4'hc    : decoder = 7'b101_1000;
      4'hd    : decoder = 7'b101_1110;
      4'he    : decoder = 7'b111_1001;
      4'hf    : decoder = 7'b111_0001;
      default : decoder = 7'b000_0000;
    endcase
    
endmodule



module worddata_display(
  input wire [31:0] word,
  input wire        hl_sw,
  output wire [6:0] hex3,
  output wire [6:0] hex2,
  output wire [6:0] hex1,
  output wire [6:0] hex0);
  
  wire [15:0] halfword;
  
  assign halfword = (hl_sw == 1'b0) ? word[31:16] : word[15:0];
  
  hexdata_display u3(.hexdata(halfword[15:12]), .hex(hex3));
  hexdata_display u2(.hexdata(halfword[11:8]),  .hex(hex2));
  hexdata_display u1(.hexdata(halfword[7:4]),   .hex(hex1));
  hexdata_display u0(.hexdata(halfword[3:0]),   .hex(hex0));

endmodule
