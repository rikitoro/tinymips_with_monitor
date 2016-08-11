`default_nettype none

/// data memory (RAM)///

module data_memory(
  // prg_mode 1: program mode, 0: run mode
  input wire  prg_mode, 
  //  data ram
  input wire  clk,
  input wire  we,
  input wire  [31:0]  addr,
  output wire [31:0]  rd,
  input wire  [31:0]  wd,
  //  for nios programmer
  input wire  prg_clk,
  input wire  prg_we,
  input wire  [31:0]  prg_addr,
  output wire [31:0]  prg_rd,
  input wire  [31:0]  prg_wd,
  // ioport
  output wire [31:0]  oport0,
  output wire [31:0]  oport1,
  output wire [31:0]  oport2,
  output wire [31:0]  oport3,
  input wire  [31:0]  iport0,
  input wire  [31:0]  iport1,
  input wire  [31:0]  iport2,
  input wire  [31:0]  iport3  
  );

  wire internal_clk;
  wire internal_we;
  wire [31:0] internal_addr;
  wire [31:0] internal_wd;
  wire [31:0] internal_rd;
  
  wire          dataram_we;
  wire  [7:0]   ioport_we;
  wire          rd_sel;
  wire  [2:0]   ioport_rd_sel;
  
  wire  [31:0]  dataram_rd;
  
  wire  [31:0]  io0_rd;
  wire  [31:0]  io1_rd;
  wire  [31:0]  io2_rd;
  wire  [31:0]  io3_rd;
  wire  [31:0]  io4_rd;
  wire  [31:0]  io5_rd;
  wire  [31:0]  io6_rd;
  wire  [31:0]  io7_rd;
  wire  [31:0]  io_rd;
  
  assign internal_clk   = (prg_mode == 1'b0) ? clk    : prg_clk;
  assign internal_we    = (prg_mode == 1'b0) ? we     : prg_we;
  assign internal_addr  = (prg_mode == 1'b0) ? addr   : prg_addr;
  assign internal_wd    = (prg_mode == 1'b0) ? wd     : prg_wd;
  
  assign rd             = (prg_mode == 1'b0) ? internal_rd : 32'b0;
  assign prg_rd         = (prg_mode == 1'b0) ? 32'b0       : internal_rd;
  
  // *** address decoder for memory mapped io *** //
  address_decoder address_decoder(
    .we             (internal_we),
    .addr           (internal_addr),
    //
    .dataram_we     (dataram_we),
    .ioport_we      (ioport_we),
    .rd_sel         (rd_sel),       
    .ioport_rd_sel  (ioport_rd_sel)
    );

  
  // select read data, memory or ioport
  mux2 # (32) mux2(
    .s(rd_sel),
    .d0(dataram_rd),
    .d1(io_rd),
    .y(internal_rd)
    );
    
  // select which ioport
  mux8 # (32) mux8(
    .s(ioport_rd_sel),
    .d0(io0_rd),
    .d1(io1_rd),
    .d2(io2_rd),
    .d3(io3_rd),
    .d4(io4_rd),
    .d5(io5_rd),
    .d6(io6_rd),
    .d7(io7_rd),
    .y(io_rd)
    );
    
  // *** data ram *** //
  ram dataram(
    .clk  (internal_clk),
    .we   (dataram_we),
    .addr (internal_addr),
    .rd   (dataram_rd),
    .wd   (internal_wd)
    );
    
  // *** output devices *** //  
  output_device output_device0(
    .clk    (internal_clk),
    .we     (ioport_we[0]),
    .wd     (internal_wd),
    .rd     (io0_rd),
    .oport  (oport0)
  );

  output_device output_device1(
    .clk    (internal_clk),
    .we     (ioport_we[1]),
    .wd     (internal_wd),
    .rd     (io1_rd),
    .oport  (oport1)
  );
  
  output_device output_device2(
    .clk    (internal_clk),
    .we     (ioport_we[2]),
    .wd     (internal_wd),
    .rd     (io2_rd),
    .oport  (oport2)
  );

  output_device output_device3(
    .clk    (internal_clk),
    .we     (ioport_we[3]),
    .wd     (internal_wd),
    .rd     (io3_rd),
    .oport  (oport3)
  );

  // *** input devices *** //
  input_device input_device0(
    .clk    (internal_clk),
    .we     (ioport_we[4]),
    .wd     (internal_wd),
    .rd     (io4_rd),
    .iport  (iport0)
  );


  input_device input_device1(
    .clk    (internal_clk),
    .we     (ioport_we[5]),
    .wd     (internal_wd),
    .rd     (io5_rd),
    .iport  (iport1)
  );

  input_device input_device2(
    .clk    (internal_clk),
    .we     (ioport_we[6]),
    .wd     (internal_wd),
    .rd     (io6_rd),
    .iport  (iport2)
  );

  input_device input_device3(
    .clk    (internal_clk),
    .we     (ioport_we[7]),
    .wd     (internal_wd),
    .rd     (io7_rd),
    .iport  (iport3)
  );
  
endmodule

