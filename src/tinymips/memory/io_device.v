`default_nettype none

module io_device(
  input wire          clk,
  input wire          we,
  input wire  [31:0]  wd,
  output wire [31:0]  rd,
  //
  input wire  [31:0]  iport,
  output wire [31:0]  oport
  );

  flopwe #(32) oport_register(
    .clk  (clk),
    .we   (we),
    .d    (wd),
    .q    (oport)
    );
  
  assign rd = iport;
  
endmodule
  

module input_device(
  input wire          clk,  // not effective
  input wire          we,   // not effective
  //
  input wire  [31:0]  wd,   // not effective
  output wire [31:0]  rd,
  //
  input wire  [31:0]  iport
  );
  
  assign rd = iport;

endmodule


module output_device(
  input wire          clk,
  input wire          we,
  //
  input wire  [31:0]  wd,
  output wire [31:0]  rd,
  //
  output wire [31:0]  oport
  );
  wire [31:0] q;
    
  flopwe #(32) u(
    .clk(clk),
    .we(we),
    .d(wd),
    .q(q)
    );
    
    assign rd = q;
    assign oport = q;

endmodule
