`default_nettype none

module datapath (
  input wire          clk,
  input wire          rst,
  input wire          memtoreg,
  input wire          pcsrc,
  input wire          alusrc,
  input wire          regdst,
  input wire          regwrite,
  input wire          jump,
  input wire  [2:0]   alucontrol,
  output wire         zero,
  output wire [31:0]  pc,
  input wire  [31:0]  instr,
  output wire [31:0]  aluout,
  output wire [31:0]  writedata,
  input wire  [31:0]  readdata,
  //
  input wire  [4:0]   dbg_ra,
  output wire [31:0]  dbg_rd);

  wire  [4:0]   writereg;
  wire  [31:0]  pcnext, pcnextbr, pcplus4, pcbranch;
  wire  [31:0]  signimm, signimmsh;
  wire  [31:0]  srca, srcb;
  wire  [31:0]  result;

  // next PC
  flopr #(32) pcreg(
    .clk(clk),
    .rst(rst),
    .d(pcnext),
    .q(pc));
    
  adder pcadd1(
    .a(pc),
    .b(32'b100),
    .y(pcplus4));

  sl2 immsh(
    .a(signimm), 
    .y(signimmsh));
  
  adder pcadd2(
    .a(pcplus4),
    .b(signimmsh), 
    .y(pcbranch));
  
  mux2 #(32) pcbrmux(
    .d0(pcplus4),
    .d1(pcbranch),
    .s(pcsrc),
    .y(pcnextbr));
  
  mux2 #(32) pcmux(
    .d0(pcnextbr),
    .d1({pcplus4[31:28], instr[25:0], 2'b00}),
    .s(jump),
    .y(pcnext));

  // register files
  regfile rf( 
    .clk(clk),
    .we3(regwrite),
    .ra1(instr[25:21]),
    .ra2(instr[20:16]),
    .wa3(writereg),
    .wd3(result),
    .rd1(srca),
    .rd2(writedata),
    .dbg_ra(dbg_ra),
    .dbg_rd(dbg_rd));

  mux2 #(5) wrmux(
    .d0(instr[20:16]), 
    .d1(instr[15:11]), 
    .s(regdst), 
    .y(writereg));

  mux2 #(32) resmux(
    .d0(aluout),
    .d1(readdata),
    .s(memtoreg),
    .y(result));

  signext se(
    .a(instr[15:0]),
    .y(signimm));

  // ALU
  mux2 #(32) srcbmux(
    .d0(writedata),
    .d1(signimm),
    .s(alusrc),
    .y(srcb));
    
  alu alu(
    .srca(srca),
    .srcb(srcb),
    .alucontrol(alucontrol),
    .aluout(aluout),
    .zero(zero));

endmodule