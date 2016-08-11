	component monitor is
		port (
			clk_clk            : in  std_logic                     := 'X';             -- clk
			dmem_addr_export   : out std_logic_vector(31 downto 0);                    -- export
			dmem_clk_export    : out std_logic;                                        -- export
			dmem_rd_export     : in  std_logic_vector(31 downto 0) := (others => 'X'); -- export
			dmem_wd_export     : out std_logic_vector(31 downto 0);                    -- export
			dmem_we_export     : out std_logic;                                        -- export
			imem_addr_export   : out std_logic_vector(31 downto 0);                    -- export
			imem_clk_export    : out std_logic;                                        -- export
			imem_rd_export     : in  std_logic_vector(31 downto 0) := (others => 'X'); -- export
			imem_wd_export     : out std_logic_vector(31 downto 0);                    -- export
			imem_we_export     : out std_logic;                                        -- export
			iport3_data_export : out std_logic_vector(31 downto 0);                    -- export
			oport3_data_export : in  std_logic_vector(31 downto 0) := (others => 'X'); -- export
			prg_mode_export    : out std_logic;                                        -- export
			reset_reset_n      : in  std_logic                     := 'X';             -- reset_n
			rst_export         : out std_logic;                                        -- export
			uart_rxd           : in  std_logic                     := 'X';             -- rxd
			uart_txd           : out std_logic                                         -- txd
		);
	end component monitor;

	u0 : component monitor
		port map (
			clk_clk            => CONNECTED_TO_clk_clk,            --         clk.clk
			dmem_addr_export   => CONNECTED_TO_dmem_addr_export,   --   dmem_addr.export
			dmem_clk_export    => CONNECTED_TO_dmem_clk_export,    --    dmem_clk.export
			dmem_rd_export     => CONNECTED_TO_dmem_rd_export,     --     dmem_rd.export
			dmem_wd_export     => CONNECTED_TO_dmem_wd_export,     --     dmem_wd.export
			dmem_we_export     => CONNECTED_TO_dmem_we_export,     --     dmem_we.export
			imem_addr_export   => CONNECTED_TO_imem_addr_export,   --   imem_addr.export
			imem_clk_export    => CONNECTED_TO_imem_clk_export,    --    imem_clk.export
			imem_rd_export     => CONNECTED_TO_imem_rd_export,     --     imem_rd.export
			imem_wd_export     => CONNECTED_TO_imem_wd_export,     --     imem_wd.export
			imem_we_export     => CONNECTED_TO_imem_we_export,     --     imem_we.export
			iport3_data_export => CONNECTED_TO_iport3_data_export, -- iport3_data.export
			oport3_data_export => CONNECTED_TO_oport3_data_export, -- oport3_data.export
			prg_mode_export    => CONNECTED_TO_prg_mode_export,    --    prg_mode.export
			reset_reset_n      => CONNECTED_TO_reset_reset_n,      --       reset.reset_n
			rst_export         => CONNECTED_TO_rst_export,         --         rst.export
			uart_rxd           => CONNECTED_TO_uart_rxd,           --        uart.rxd
			uart_txd           => CONNECTED_TO_uart_txd            --            .txd
		);

