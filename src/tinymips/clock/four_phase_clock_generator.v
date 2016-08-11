`default_nettype none

module four_phase_clock_generator(
  input wire rst, 
  input wire pause,
  input wire clk_in,  //  ~_~_~_~_
  output wire phase0, //  ~~~~____
  output wire phase1, //  __~~~~__
  output wire phase2, //  ____~~~~
  output wire phase3  //  ~~____~~
  );
  
  reg [1:0] cnt;
  
  assign phase0 = cnt[1];
  assign phase1 = cnt[0];
  assign phase2 = ~cnt[1];
  assign phase3 = ~cnt[0];
  
  always @(posedge clk_in, posedge rst) begin
    if (rst) begin
      cnt <= 2'b00;
    end else if (pause) begin
      cnt <= cnt;
    end else begin
      case (cnt)
        2'b10   : cnt <=2'b11;
        2'b11   : cnt <=2'b01;
        2'b01   : cnt <=2'b00;
        2'b00   : cnt <=2'b10;
        default : cnt <=2'b00;
      endcase
    end
  end
  
endmodule
