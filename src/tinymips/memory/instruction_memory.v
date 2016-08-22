`default_nettype none

/// instruction memory (ROM) ///

module instruction_memory(
  //  prg_mode 1: program mode, 0: run mode
  input wire  prg_mode,  //
  //  program rom
  input wire  clk,  // posedge
  input wire  [31:0]  addr,
  output wire [31:0]  rd,
  // for nios programmer
  input wire  prg_clk,
  input wire  prg_we,
  input wire  [31:0]  prg_addr,
  output wire [31:0]  prg_rd,
  input wire  [31:0]  prg_wd);

  dualport_ram  instruction_ram(
    // instruction ROM
    .clock_a    (clk),
    .wren_a     (1'b0),
    .address_a  (addr[12:2]),
    .data_a     (32'h00000000),
    .q_a        (rd),
    // <-> monitor server
    .clock_b    (prg_clk),
    .wren_b     (prg_we),
    .address_b  (prg_addr[12:2]),
    .data_b     (prg_wd),
    .q_b        (prg_rd));
    
endmodule

