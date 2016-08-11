`default_nettype none

module ram (
  input wire  clk,
  input wire  we,
  input wire  [31:0]  addr,
  output reg  [31:0]  rd,
  input wire  [31:0]  wd);
  
  reg   [31:0] word_data[2047:0]; // 
  wire  [10:0] word_addr;

  assign word_addr = addr[12:2]; // byte address -> word address

  always @(posedge clk) begin
    if (we) begin
      word_data[word_addr] <= wd;
    end
    rd <= word_data[word_addr];
  end
  
endmodule
