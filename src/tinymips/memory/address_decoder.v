`default_nettype none

module address_decoder(
  input wire          we,
  input wire  [31:0]  addr,
  //
  output reg          dataram_we,
  output reg  [7:0]   ioport_we,
  output wire         rd_sel,         // 0: read dataram, 1: read io device
  output wire [2:0]   ioport_rd_sel   // 0, 1, 2, 3: read oport_0,1,2,3; 4, 5, 6, 7: read iport_0,1,2,3
  );
  
  /// addr : 00000000_00000000_00Mxxxxx_xxxPPP00
  assign rd_sel = addr[13];         // bit M in addr (M = 0: ram, M = 1: ioport)
  assign ioport_rd_sel = addr[4:2]; // 3-bit PPP in addr
  
  always @ (*) begin
    casex ({we, addr})
      33'h1_0000_2000 : {dataram_we, ioport_we} = 9'b0_0000_0001; // oport0 
      33'h1_0000_2004 : {dataram_we, ioport_we} = 9'b0_0000_0010; // oport1
      33'h1_0000_2008 : {dataram_we, ioport_we} = 9'b0_0000_0100; // oport2
      33'h1_0000_200c : {dataram_we, ioport_we} = 9'b0_0000_1000; // oport3
      33'h1_0000_2010 : {dataram_we, ioport_we} = 9'b0_0001_0000; // iport0
      33'h1_0000_2014 : {dataram_we, ioport_we} = 9'b0_0010_0000; // iport1
      33'h1_0000_2018 : {dataram_we, ioport_we} = 9'b0_0100_0000; // iport2
      33'h1_0000_201c : {dataram_we, ioport_we} = 9'b0_1000_0000; // iport3
      //
      33'h1_0000_1xxx : {dataram_we, ioport_we} = 9'b1_0000_0000; // dataram
      33'h1_0000_0xxx : {dataram_we, ioport_we} = 9'b1_0000_0000; // dataram
      //
      default         : {dataram_we, ioport_we} = 9'b0_0000_0000;
    endcase
  end
  
endmodule

