`default_nettype none

module sl2(
  input wire [31:0]  a,
  output wire [31:0] y);

  // 2-bit left shift
  assign y = {a[29:0], 2'b00};
endmodule
