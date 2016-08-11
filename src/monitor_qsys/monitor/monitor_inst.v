	monitor u0 (
		.clk_clk            (<connected-to-clk_clk>),            //         clk.clk
		.dmem_addr_export   (<connected-to-dmem_addr_export>),   //   dmem_addr.export
		.dmem_clk_export    (<connected-to-dmem_clk_export>),    //    dmem_clk.export
		.dmem_rd_export     (<connected-to-dmem_rd_export>),     //     dmem_rd.export
		.dmem_wd_export     (<connected-to-dmem_wd_export>),     //     dmem_wd.export
		.dmem_we_export     (<connected-to-dmem_we_export>),     //     dmem_we.export
		.imem_addr_export   (<connected-to-imem_addr_export>),   //   imem_addr.export
		.imem_clk_export    (<connected-to-imem_clk_export>),    //    imem_clk.export
		.imem_rd_export     (<connected-to-imem_rd_export>),     //     imem_rd.export
		.imem_wd_export     (<connected-to-imem_wd_export>),     //     imem_wd.export
		.imem_we_export     (<connected-to-imem_we_export>),     //     imem_we.export
		.iport3_data_export (<connected-to-iport3_data_export>), // iport3_data.export
		.oport3_data_export (<connected-to-oport3_data_export>), // oport3_data.export
		.prg_mode_export    (<connected-to-prg_mode_export>),    //    prg_mode.export
		.reset_reset_n      (<connected-to-reset_reset_n>),      //       reset.reset_n
		.rst_export         (<connected-to-rst_export>),         //         rst.export
		.uart_rxd           (<connected-to-uart_rxd>),           //        uart.rxd
		.uart_txd           (<connected-to-uart_txd>)            //            .txd
	);

