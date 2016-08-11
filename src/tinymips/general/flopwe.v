`default_nettype none

// flip flop with write-enable signal
module flopwe  # (parameter  WIDTH = 8) (
  input wire  clk,
  input wire  we,
  input wire [WIDTH-1:0] d,
  output reg [WIDTH-1:0] q);

  always @(posedge clk) begin
    if (we) begin
      q <= d;
    end
  end
  
endmodule
