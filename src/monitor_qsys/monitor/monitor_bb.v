
module monitor (
	clk_clk,
	dmem_addr_export,
	dmem_clk_export,
	dmem_rd_export,
	dmem_wd_export,
	dmem_we_export,
	imem_addr_export,
	imem_clk_export,
	imem_rd_export,
	imem_wd_export,
	imem_we_export,
	iport3_data_export,
	oport3_data_export,
	prg_mode_export,
	reset_reset_n,
	rst_export,
	uart_rxd,
	uart_txd);	

	input		clk_clk;
	output	[31:0]	dmem_addr_export;
	output		dmem_clk_export;
	input	[31:0]	dmem_rd_export;
	output	[31:0]	dmem_wd_export;
	output		dmem_we_export;
	output	[31:0]	imem_addr_export;
	output		imem_clk_export;
	input	[31:0]	imem_rd_export;
	output	[31:0]	imem_wd_export;
	output		imem_we_export;
	output	[31:0]	iport3_data_export;
	input	[31:0]	oport3_data_export;
	output		prg_mode_export;
	input		reset_reset_n;
	output		rst_export;
	input		uart_rxd;
	output		uart_txd;
endmodule
