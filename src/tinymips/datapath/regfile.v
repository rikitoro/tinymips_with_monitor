`default_nettype none

module regfile (
  input wire          clk,
  input               we3,
  input wire  [4:0]   ra1,
  input wire  [4:0]   ra2,
  input wire  [4:0]   wa3,
  input wire  [31:0]  wd3,
  output wire [31:0]  rd1,
  output wire [31:0]  rd2,
  // for debug (register monitor);
  input wire  [4:0]   dbg_ra,
  output wire [31:0]  dbg_rd);
  
  reg [31:0]  rf[31:0];

  assign rd1 = (ra1 != 0) ? rf[ra1] : 0;
  assign rd2 = (ra2 != 0) ? rf[ra2] : 0;

  // debug (register monitor)
  assign dbg_rd = (dbg_ra != 0) ? rf[dbg_ra] : 0;
  //
  
  always @(posedge clk) begin
    if (we3) begin
      rf[wa3] <= wd3;
    end
  end
  
endmodule
