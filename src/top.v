`default_nettype none

module top(
  // <-> nios
  input wire        nonitor_clk,
  input wire        nonitor_rst_n,
  input wire        uart_rxd,
  output wire       uart_txd,
  // -> mips
  input wire        clk_src,
  input wire        rst_n,
  // mips <->
  input wire        dbg_sw,
  input wire  [4:0] dbg_ra,
  input wire        hl_sw,
  output wire [6:0] dbg_hex3,
  output wire [6:0] dbg_hex2,
  output wire [6:0] dbg_hex1,
  output wire [6:0] dbg_hex0,
  // clock 
  output wire       clk0,
  output wire       clk1,
  output wire       clk2,
  output wire       clk3,
  // io interface
  output wire [7:0] oport0_led,
  output wire [7:0] oport1_gpio,
  output wire [7:0] oport2_gpio,  
  input wire  [3:0] iport0_sw,
  input wire  [7:0] iport1_gpio,
  input wire  [7:0] iport2_gpio
  );

  
  // mips <-> imem
  wire  imem_clk;
  wire  [31:0]  imem_addr;
  wire  [31:0]  imem_rd;
  
  // mips <-> dmem
  wire  dmem_clk;
  wire  dmem_we;
  wire  [31:0]  dmem_addr;
  wire  [31:0]  dmem_rd;
  wire  [31:0]  dmem_wd;

  // nios -> imem, dmem
  wire  prg_mode;
  
  // nios -> mips
  wire  prg_rst;

  // nios <-> imem
  wire  prg_imem_clk;
  wire  prg_imem_we;
  wire  [31:0]  prg_imem_addr;
  wire  [31:0]  prg_imem_rd;
  wire  [31:0]  prg_imem_wd;
  
  // nios <-> dmem
  wire  prg_dmem_clk;
  wire  prg_dmem_we;
  wire  [31:0]  prg_dmem_addr;
  wire  [31:0]  prg_dmem_rd;
  wire  [31:0]  prg_dmem_wd;

  // ioport
  wire  [31:0]  oport0;
  wire  [31:0]  oport1;
  wire  [31:0]  oport2;
  wire  [31:0]  oport3;  
  wire  [31:0]  iport0;
  wire  [31:0]  iport1;
  wire  [31:0]  iport2;
  wire  [31:0]  iport3;
  wire  [31:0]  ioport_rd;
  // prescaled clock source
  wire          prescaled_clk_src;

  // clock
  wire          clk_phi0;
  wire          clk_phi1;
  wire          clk_phi2;
  wire          clk_phi3;
  
  // reset
  wire          reset;

  //
  wire  [31:0]  dbg_rd;
  
  //
  wire  [31:0]  display_data;
  



  // *** reset *** //
  assign reset = (~rst_n) | prg_rst;

  // *** clock generator *** //
  prescaler prescaler(
    .clk_in(clk_src),
    .clk_out(prescaled_clk_src)
  );

  four_phase_clock_generator clock_gen(
    .rst(reset), 
    .pause(prg_mode),
    .clk_in(prescaled_clk_src),  //  ~_~_~_~_
    .phase0(clk_phi0), //  ~~~~____
    .phase1(clk_phi1), //  __~~~~__
    .phase2(clk_phi2), //  ____~~~~
    .phase3(clk_phi3)  //  ~~____~~
  );
  
  // *** mips cpu *** //
  mips mips(
    .clk(clk_phi3),
    .rst(reset),
    .pc(imem_addr),
    .instr(imem_rd),
    .memwrite(dmem_we),
    .aluout(dmem_addr),
    .writedata(dmem_wd),
    .readdata(dmem_rd),
    .dbg_ra(dbg_ra),
    .dbg_rd(dbg_rd));

  // *** instruction memory *** //
  instruction_memory imem(
    .prg_mode(prg_mode),
    //  program rom
    .clk(clk_phi1),
    .addr(imem_addr),
    .rd(imem_rd),
    //
    .prg_clk(prg_imem_clk),
    .prg_we(prg_imem_we),
    .prg_addr(prg_imem_addr),
    .prg_rd(prg_imem_rd),
    .prg_wd(prg_imem_wd));

  // *** datamemory with io (memory mapped io) ***//  
  data_memory dmem(
    .prg_mode(prg_mode), 
    //  data ram
    .clk(clk_phi2),
    .we(dmem_we),
    .addr(dmem_addr),
    .rd(dmem_rd),
    .wd(dmem_wd),
    //
    .prg_clk  (prg_dmem_clk),
    .prg_we   (prg_dmem_we),
    .prg_addr (prg_dmem_addr),
    .prg_rd   (prg_dmem_rd),
    .prg_wd   (prg_dmem_wd),
    // ioport
    .oport0   (oport0),
    .oport1   (oport1),
    .oport2   (oport2),
    .oport3   (oport3),
    .iport0   (iport0),
    .iport1   (iport1),
    .iport2   (iport2),
    .iport3   (iport3)
    );

  
  // *** monitor on niosII *** //
  monitor monitor (
    .clk_clk                (nonitor_clk),      //             clk.clk
    .reset_reset_n          (nonitor_rst_n),    //           reset.reset_n
    //
    .imem_we_export         (prg_imem_we),      //         imem_we.export
    .imem_clk_export        (prg_imem_clk),     //        imem_clk.export
    .imem_addr_export       (prg_imem_addr),    //       imem_addr.export
    .imem_rd_export         (prg_imem_rd),      //         imem_rd.export
    .imem_wd_export         (prg_imem_wd),      //         imem_wd.export
    //
    .dmem_we_export         (prg_dmem_we),      //         dmem_we.export
    .dmem_clk_export        (prg_dmem_clk),     //        dmem_clk.export
    .dmem_addr_export       (prg_dmem_addr),    //       dmem_addr.export
    .dmem_rd_export         (prg_dmem_rd),      //         dmem_rd.export
    .dmem_wd_export         (prg_dmem_wd),      //         dmem_wd.export
    //
    .prg_mode_export        (prg_mode),         //        prg_mode.export
    .rst_export             (prg_rst),          //             rst.export
    //
    .iport3_data_export     (iport3),           //     iport3_data.export
    .oport3_data_export     (oport3),           //     oport3_data.export
    //
    .uart_rxd               (uart_rxd),         //            uart.rxd
    .uart_txd               (uart_txd)          //                .txd  
  );
  
  
  
  // *** DE0 interface *** //
  
  
  //for debug
  // clock display (7seg are active low)
  assign clk0 = ~clk_phi0; 
  assign clk1 = ~clk_phi1;
  assign clk2 = ~clk_phi2;
  assign clk3 = ~clk_phi3;
  
  
  // word display
  
  assign display_data = (dbg_sw == 1'b0)    ? dbg_rd    :
                        (dbg_ra[4] == 1'b0) ? ioport_rd :
                                              imem_addr ;

  // ioport_rd
  mux8 # (32) ioport_rd_mux(
    .s(dbg_ra[2:0]),
    .d0(oport0),
    .d1(oport1),
    .d2(oport2),
    .d3(oport3),
    .d4(iport0),
    .d5(iport1),
    .d6(iport2),
    .d7(iport3),
    .y(ioport_rd)
    );
  
  // dbg_rd
  worddata_display display(
  .word(display_data),
  .hl_sw(hl_sw),
  .hex3(dbg_hex3),
  .hex2(dbg_hex2),
  .hex1(dbg_hex1),
  .hex0(dbg_hex0));

  // SW and GPIO
  assign iport0 = {28'h00_00_00_0, iport0_sw};  // SW3-0
  assign iport1 = {24'h00_00_00, iport1_gpio};  // GPIO_1 pin 5 , 7 , 9 , 2 , 4 , 6 , 8 , 10
  assign iport2 = {24'h00_00_00, iport2_gpio};  // GPIO_1 pin 31, 33, 35, 32, 34, 36, 38, 40
  
  // LED and GPIO
  assign oport0_led   = oport0[7:0];            // LED7-0
  assign oport1_gpio  = oport1[7:0];            // GPIO_1 pin 13, 15, 17, 19, 14, 16, 18, 20
  assign oport2_gpio  = oport2[7:0];            // GPIO_1 pin 21, 23, 25, 27, 22, 24, 26, 28

endmodule
