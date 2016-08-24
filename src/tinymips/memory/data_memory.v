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

  
  wire          dataram_we;
  wire  [3:0]   ioport_we;
  wire          rd_sel;
  wire  [1:0]   ioport_rd_sel;
  
  wire  [31:0]  dataram_rd;
  
  wire  [31:0]  io0_rd;
  wire  [31:0]  io1_rd;
  wire  [31:0]  io2_rd;
  wire  [31:0]  io3_rd;
  wire  [31:0]  io_rd;
  
  
  // *** address decoder for memory mapped io *** //
  address_decoder address_decoder(
    .we             (we),
    .addr           (addr),
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
    .y(rd)
    );
    
  // select ioport you read
  mux4 # (32) mux4(
    .s(ioport_rd_sel),
    .d0(io0_rd),
    .d1(io1_rd),
    .d2(io2_rd),
    .d3(io3_rd),
    .y(io_rd)
    );
    
  // *** data ram *** //
  dualport_ram data_ram(
    // data ram
    .clock_a    (clk),
    .wren_a     (dataram_we),
    .address_a  (addr[12:2]),
    .data_a     (wd),
    .q_a        (dataram_rd),
    // <-> monitor server
    .clock_b    (prg_clk),
    .wren_b     (prg_we),
    .address_b  (prg_addr[12:2]),
    .data_b     (prg_wd),
    .q_b        (prg_rd));
    
    
  // *** output devices *** //  
  io_device io_device0(
    .clk    (clk),
    .we     (ioport_we[0]),
    .wd     (wd),
    .rd     (io0_rd),
    .iport  (iport0),
    .oport  (oport0)
  );

  io_device io_device1(
    .clk    (clk),
    .we     (ioport_we[1]),
    .wd     (wd),
    .rd     (io1_rd),
    .iport  (iport1),
    .oport  (oport1)
  );

  io_device io_device2(
    .clk    (clk),
    .we     (ioport_we[2]),
    .wd     (wd),
    .rd     (io2_rd),
    .iport  (iport2),
    .oport  (oport2)
  );

  io_device io_device3(
    .clk    (clk),
    .we     (ioport_we[3]),
    .wd     (wd),
    .rd     (io3_rd),
    .iport  (iport3),
    .oport  (oport3)
  );
  
endmodule

