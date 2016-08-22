`default_nettype none

module address_decoder(
  input wire          we,
  input wire  [31:0]  addr,
  //
  output reg          dataram_we,
  output reg  [3:0]   ioport_we,      // 0001, 0010, 0100, 1000: write-enable ioport0,1,2,3
  output wire         rd_sel,         // 0: read dataram, 1: read io device
  output wire [1:0]   ioport_rd_sel   // 00, 01, 10, 11: read ioport0,1,2,3;
  );
  
  /// addr : 00000000_00000000_00Mxxxxx_xxxxPP00
  assign rd_sel = addr[13];         // bit M in addr (M = 0: ram, M = 1: ioport)
  assign ioport_rd_sel = addr[4:2]; // 3-bit PPP in addr
  
  always @ (*) begin
    casex ({we, addr})
      33'h1_0000_2000 : {dataram_we, ioport_we} = 5'b0_0001; // ioport0 
      33'h1_0000_2004 : {dataram_we, ioport_we} = 5'b0_0010; // ioport1
      33'h1_0000_2008 : {dataram_we, ioport_we} = 5'b0_0100; // ioport2
      33'h1_0000_200c : {dataram_we, ioport_we} = 5'b0_1000; // ioport3
      //
      33'h1_0000_1xxx : {dataram_we, ioport_we} = 5'b1_0000; // dataram
      33'h1_0000_0xxx : {dataram_we, ioport_we} = 5'b1_0000; // dataram
      //
      default         : {dataram_we, ioport_we} = 5'b0_0000;
    endcase
  end
  
endmodule

