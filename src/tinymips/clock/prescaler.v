`default_nettype none

module prescaler #(parameter WIDTH = 20) (
  input wire  clk_in,
  output wire clk_out
  );
  
  reg [WIDTH-1:0] cnt;
  
  assign clk_out = cnt[WIDTH-1];
  
  always @(posedge clk_in) begin
    cnt <= cnt + 1'b1;
  end
endmodule
