`default_nettype none

module mips (
  input   wire          clk,
  input   wire          rst,
  output  wire  [31:0]  pc,
  input   wire  [31:0]  instr,
  output  wire          memwrite,
  output  wire  [31:0]  aluout,
  output  wire  [31:0]  writedata,
  input   wire  [31:0]  readdata,
  input   wire  [4:0]   dbg_ra,
  output  wire  [31:0]  dbg_rd);

  wire        zero, memtoreg, pcsrc, alusrc, regdst, regwrite, jump;
  wire  [2:0] alucontrol;

  controller c(
    .op(instr[31:26]), 
    .funct(instr[5:0]), 
    .zero(zero), 
    .memtoreg(memtoreg), 
    .memwrite(memwrite),
    .pcsrc(pcsrc), 
    .alusrc(alusrc), 
    .regdst(regdst), 
    .regwrite(regwrite), 
    .jump(jump), 
    .alucontrol(alucontrol));

  datapath dp(
    .clk(clk),
    .rst(rst),
    .memtoreg(memtoreg),
    .pcsrc(pcsrc),
    .alusrc(alusrc),
    .regdst(regdst),
    .regwrite(regwrite),
    .jump(jump),
    .alucontrol(alucontrol),
    .zero(zero),
    .pc(pc),
    .instr(instr),
    .aluout(aluout),
    .writedata(writedata),
    .readdata(readdata),
    .dbg_ra(dbg_ra),
    .dbg_rd(dbg_rd));

endmodule
