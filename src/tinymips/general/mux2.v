`default_nettype none

module mux2 # (parameter WIDTH = 32) (
  input wire [WIDTH-1:0]  d0,
  input wire [WIDTH-1:0]  d1,
  input wire              s,
  output wire [WIDTH-1:0] y);

  assign y = s ? d1 : d0;
endmodule