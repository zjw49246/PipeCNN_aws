-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
-- Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

entity memRead_control_s_axi is
generic (
    C_S_AXI_ADDR_WIDTH    : INTEGER := 8;
    C_S_AXI_DATA_WIDTH    : INTEGER := 32);
port (
    ACLK                  :in   STD_LOGIC;
    ARESET                :in   STD_LOGIC;
    ACLK_EN               :in   STD_LOGIC;
    AWADDR                :in   STD_LOGIC_VECTOR(C_S_AXI_ADDR_WIDTH-1 downto 0);
    AWVALID               :in   STD_LOGIC;
    AWREADY               :out  STD_LOGIC;
    WDATA                 :in   STD_LOGIC_VECTOR(C_S_AXI_DATA_WIDTH-1 downto 0);
    WSTRB                 :in   STD_LOGIC_VECTOR(C_S_AXI_DATA_WIDTH/8-1 downto 0);
    WVALID                :in   STD_LOGIC;
    WREADY                :out  STD_LOGIC;
    BRESP                 :out  STD_LOGIC_VECTOR(1 downto 0);
    BVALID                :out  STD_LOGIC;
    BREADY                :in   STD_LOGIC;
    ARADDR                :in   STD_LOGIC_VECTOR(C_S_AXI_ADDR_WIDTH-1 downto 0);
    ARVALID               :in   STD_LOGIC;
    ARREADY               :out  STD_LOGIC;
    RDATA                 :out  STD_LOGIC_VECTOR(C_S_AXI_DATA_WIDTH-1 downto 0);
    RRESP                 :out  STD_LOGIC_VECTOR(1 downto 0);
    RVALID                :out  STD_LOGIC;
    RREADY                :in   STD_LOGIC;
    interrupt             :out  STD_LOGIC;
    data_dim1             :out  STD_LOGIC_VECTOR(7 downto 0);
    data_dim2             :out  STD_LOGIC_VECTOR(7 downto 0);
    data_dim1xdim2        :out  STD_LOGIC_VECTOR(15 downto 0);
    weight_dim1           :out  STD_LOGIC_VECTOR(7 downto 0);
    weight_dim2           :out  STD_LOGIC_VECTOR(7 downto 0);
    weight_dim3           :out  STD_LOGIC_VECTOR(15 downto 0);
    weight_dim4_div_lane  :out  STD_LOGIC_VECTOR(15 downto 0);
    weight_dim1x2         :out  STD_LOGIC_VECTOR(7 downto 0);
    weight_dim1x2x3       :out  STD_LOGIC_VECTOR(31 downto 0);
    conv_x                :out  STD_LOGIC_VECTOR(7 downto 0);
    stride                :out  STD_LOGIC_VECTOR(7 downto 0);
    padding               :out  STD_LOGIC_VECTOR(7 downto 0);
    split                 :out  STD_LOGIC_VECTOR(7 downto 0);
    group_num_x           :out  STD_LOGIC_VECTOR(7 downto 0);
    group_num_y           :out  STD_LOGIC_VECTOR(7 downto 0);
    group_rem_size_x      :out  STD_LOGIC_VECTOR(7 downto 0);
    group_rem_size_xyz    :out  STD_LOGIC_VECTOR(31 downto 0);
    win_size_x            :out  STD_LOGIC_VECTOR(7 downto 0);
    win_size_y            :out  STD_LOGIC_VECTOR(7 downto 0);
    win_size_xyz          :out  STD_LOGIC_VECTOR(31 downto 0);
    bottom                :out  STD_LOGIC_VECTOR(63 downto 0);
    weights               :out  STD_LOGIC_VECTOR(63 downto 0);
    bias                  :out  STD_LOGIC_VECTOR(63 downto 0);
    ap_start              :out  STD_LOGIC;
    ap_done               :in   STD_LOGIC;
    ap_ready              :in   STD_LOGIC;
    ap_continue           :out  STD_LOGIC;
    ap_idle               :in   STD_LOGIC;
    event_start           :out  STD_LOGIC
);
end entity memRead_control_s_axi;

-- ------------------------Address Info-------------------
-- 0x00 : Control signals
--        bit 0  - ap_start (Read/Write/COH)
--        bit 1  - ap_done (Read)
--        bit 2  - ap_idle (Read)
--        bit 3  - ap_ready (Read)
--        bit 4  - ap_continue (Read/Write/SC)
--        bit 7  - auto_restart (Read/Write)
--        others - reserved
-- 0x04 : Global Interrupt Enable Register
--        bit 0  - Global Interrupt Enable (Read/Write)
--        others - reserved
-- 0x08 : IP Interrupt Enable Register (Read/Write)
--        bit 0  - enable ap_done interrupt (Read/Write)
--        bit 1  - enable ap_ready interrupt (Read/Write)
--        others - reserved
-- 0x0c : IP Interrupt Status Register (Read/TOW)
--        bit 0  - ap_done (COR/TOW)
--        bit 1  - ap_ready (COR/TOW)
--        others - reserved
-- 0x10 : Data signal of data_dim1
--        bit 7~0 - data_dim1[7:0] (Read/Write)
--        others  - reserved
-- 0x14 : reserved
-- 0x18 : Data signal of data_dim2
--        bit 7~0 - data_dim2[7:0] (Read/Write)
--        others  - reserved
-- 0x1c : reserved
-- 0x20 : Data signal of data_dim1xdim2
--        bit 15~0 - data_dim1xdim2[15:0] (Read/Write)
--        others   - reserved
-- 0x24 : reserved
-- 0x28 : Data signal of weight_dim1
--        bit 7~0 - weight_dim1[7:0] (Read/Write)
--        others  - reserved
-- 0x2c : reserved
-- 0x30 : Data signal of weight_dim2
--        bit 7~0 - weight_dim2[7:0] (Read/Write)
--        others  - reserved
-- 0x34 : reserved
-- 0x38 : Data signal of weight_dim3
--        bit 15~0 - weight_dim3[15:0] (Read/Write)
--        others   - reserved
-- 0x3c : reserved
-- 0x40 : Data signal of weight_dim4_div_lane
--        bit 15~0 - weight_dim4_div_lane[15:0] (Read/Write)
--        others   - reserved
-- 0x44 : reserved
-- 0x48 : Data signal of weight_dim1x2
--        bit 7~0 - weight_dim1x2[7:0] (Read/Write)
--        others  - reserved
-- 0x4c : reserved
-- 0x50 : Data signal of weight_dim1x2x3
--        bit 31~0 - weight_dim1x2x3[31:0] (Read/Write)
-- 0x54 : reserved
-- 0x58 : Data signal of conv_x
--        bit 7~0 - conv_x[7:0] (Read/Write)
--        others  - reserved
-- 0x5c : reserved
-- 0x60 : Data signal of stride
--        bit 7~0 - stride[7:0] (Read/Write)
--        others  - reserved
-- 0x64 : reserved
-- 0x68 : Data signal of padding
--        bit 7~0 - padding[7:0] (Read/Write)
--        others  - reserved
-- 0x6c : reserved
-- 0x70 : Data signal of split
--        bit 7~0 - split[7:0] (Read/Write)
--        others  - reserved
-- 0x74 : reserved
-- 0x78 : Data signal of group_num_x
--        bit 7~0 - group_num_x[7:0] (Read/Write)
--        others  - reserved
-- 0x7c : reserved
-- 0x80 : Data signal of group_num_y
--        bit 7~0 - group_num_y[7:0] (Read/Write)
--        others  - reserved
-- 0x84 : reserved
-- 0x88 : Data signal of group_rem_size_x
--        bit 7~0 - group_rem_size_x[7:0] (Read/Write)
--        others  - reserved
-- 0x8c : reserved
-- 0x90 : Data signal of group_rem_size_xyz
--        bit 31~0 - group_rem_size_xyz[31:0] (Read/Write)
-- 0x94 : reserved
-- 0x98 : Data signal of win_size_x
--        bit 7~0 - win_size_x[7:0] (Read/Write)
--        others  - reserved
-- 0x9c : reserved
-- 0xa0 : Data signal of win_size_y
--        bit 7~0 - win_size_y[7:0] (Read/Write)
--        others  - reserved
-- 0xa4 : reserved
-- 0xa8 : Data signal of win_size_xyz
--        bit 31~0 - win_size_xyz[31:0] (Read/Write)
-- 0xac : reserved
-- 0xb0 : Data signal of bottom
--        bit 31~0 - bottom[31:0] (Read/Write)
-- 0xb4 : Data signal of bottom
--        bit 31~0 - bottom[63:32] (Read/Write)
-- 0xb8 : reserved
-- 0xbc : Data signal of weights
--        bit 31~0 - weights[31:0] (Read/Write)
-- 0xc0 : Data signal of weights
--        bit 31~0 - weights[63:32] (Read/Write)
-- 0xc4 : reserved
-- 0xc8 : Data signal of bias
--        bit 31~0 - bias[31:0] (Read/Write)
-- 0xcc : Data signal of bias
--        bit 31~0 - bias[63:32] (Read/Write)
-- 0xd0 : reserved
-- (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

architecture behave of memRead_control_s_axi is
    type states is (wridle, wrdata, wrresp, wrreset, rdidle, rddata, rdreset);  -- read and write fsm states
    signal wstate  : states := wrreset;
    signal rstate  : states := rdreset;
    signal wnext, rnext: states;
    constant ADDR_AP_CTRL                     : INTEGER := 16#00#;
    constant ADDR_GIE                         : INTEGER := 16#04#;
    constant ADDR_IER                         : INTEGER := 16#08#;
    constant ADDR_ISR                         : INTEGER := 16#0c#;
    constant ADDR_DATA_DIM1_DATA_0            : INTEGER := 16#10#;
    constant ADDR_DATA_DIM1_CTRL              : INTEGER := 16#14#;
    constant ADDR_DATA_DIM2_DATA_0            : INTEGER := 16#18#;
    constant ADDR_DATA_DIM2_CTRL              : INTEGER := 16#1c#;
    constant ADDR_DATA_DIM1XDIM2_DATA_0       : INTEGER := 16#20#;
    constant ADDR_DATA_DIM1XDIM2_CTRL         : INTEGER := 16#24#;
    constant ADDR_WEIGHT_DIM1_DATA_0          : INTEGER := 16#28#;
    constant ADDR_WEIGHT_DIM1_CTRL            : INTEGER := 16#2c#;
    constant ADDR_WEIGHT_DIM2_DATA_0          : INTEGER := 16#30#;
    constant ADDR_WEIGHT_DIM2_CTRL            : INTEGER := 16#34#;
    constant ADDR_WEIGHT_DIM3_DATA_0          : INTEGER := 16#38#;
    constant ADDR_WEIGHT_DIM3_CTRL            : INTEGER := 16#3c#;
    constant ADDR_WEIGHT_DIM4_DIV_LANE_DATA_0 : INTEGER := 16#40#;
    constant ADDR_WEIGHT_DIM4_DIV_LANE_CTRL   : INTEGER := 16#44#;
    constant ADDR_WEIGHT_DIM1X2_DATA_0        : INTEGER := 16#48#;
    constant ADDR_WEIGHT_DIM1X2_CTRL          : INTEGER := 16#4c#;
    constant ADDR_WEIGHT_DIM1X2X3_DATA_0      : INTEGER := 16#50#;
    constant ADDR_WEIGHT_DIM1X2X3_CTRL        : INTEGER := 16#54#;
    constant ADDR_CONV_X_DATA_0               : INTEGER := 16#58#;
    constant ADDR_CONV_X_CTRL                 : INTEGER := 16#5c#;
    constant ADDR_STRIDE_DATA_0               : INTEGER := 16#60#;
    constant ADDR_STRIDE_CTRL                 : INTEGER := 16#64#;
    constant ADDR_PADDING_DATA_0              : INTEGER := 16#68#;
    constant ADDR_PADDING_CTRL                : INTEGER := 16#6c#;
    constant ADDR_SPLIT_DATA_0                : INTEGER := 16#70#;
    constant ADDR_SPLIT_CTRL                  : INTEGER := 16#74#;
    constant ADDR_GROUP_NUM_X_DATA_0          : INTEGER := 16#78#;
    constant ADDR_GROUP_NUM_X_CTRL            : INTEGER := 16#7c#;
    constant ADDR_GROUP_NUM_Y_DATA_0          : INTEGER := 16#80#;
    constant ADDR_GROUP_NUM_Y_CTRL            : INTEGER := 16#84#;
    constant ADDR_GROUP_REM_SIZE_X_DATA_0     : INTEGER := 16#88#;
    constant ADDR_GROUP_REM_SIZE_X_CTRL       : INTEGER := 16#8c#;
    constant ADDR_GROUP_REM_SIZE_XYZ_DATA_0   : INTEGER := 16#90#;
    constant ADDR_GROUP_REM_SIZE_XYZ_CTRL     : INTEGER := 16#94#;
    constant ADDR_WIN_SIZE_X_DATA_0           : INTEGER := 16#98#;
    constant ADDR_WIN_SIZE_X_CTRL             : INTEGER := 16#9c#;
    constant ADDR_WIN_SIZE_Y_DATA_0           : INTEGER := 16#a0#;
    constant ADDR_WIN_SIZE_Y_CTRL             : INTEGER := 16#a4#;
    constant ADDR_WIN_SIZE_XYZ_DATA_0         : INTEGER := 16#a8#;
    constant ADDR_WIN_SIZE_XYZ_CTRL           : INTEGER := 16#ac#;
    constant ADDR_BOTTOM_DATA_0               : INTEGER := 16#b0#;
    constant ADDR_BOTTOM_DATA_1               : INTEGER := 16#b4#;
    constant ADDR_BOTTOM_CTRL                 : INTEGER := 16#b8#;
    constant ADDR_WEIGHTS_DATA_0              : INTEGER := 16#bc#;
    constant ADDR_WEIGHTS_DATA_1              : INTEGER := 16#c0#;
    constant ADDR_WEIGHTS_CTRL                : INTEGER := 16#c4#;
    constant ADDR_BIAS_DATA_0                 : INTEGER := 16#c8#;
    constant ADDR_BIAS_DATA_1                 : INTEGER := 16#cc#;
    constant ADDR_BIAS_CTRL                   : INTEGER := 16#d0#;
    constant ADDR_BITS         : INTEGER := 8;

    signal waddr               : UNSIGNED(ADDR_BITS-1 downto 0);
    signal wmask               : UNSIGNED(C_S_AXI_DATA_WIDTH-1 downto 0);
    signal aw_hs               : STD_LOGIC;
    signal w_hs                : STD_LOGIC;
    signal rdata_data          : UNSIGNED(C_S_AXI_DATA_WIDTH-1 downto 0);
    signal ar_hs               : STD_LOGIC;
    signal raddr               : UNSIGNED(ADDR_BITS-1 downto 0);
    signal AWREADY_t           : STD_LOGIC;
    signal WREADY_t            : STD_LOGIC;
    signal ARREADY_t           : STD_LOGIC;
    signal RVALID_t            : STD_LOGIC;
    -- internal registers
    signal int_event_start     : STD_LOGIC := '0';
    signal int_ap_idle         : STD_LOGIC;
    signal int_ap_continue     : STD_LOGIC;
    signal int_ap_ready        : STD_LOGIC;
    signal int_ap_done         : STD_LOGIC;
    signal int_ap_start        : STD_LOGIC := '0';
    signal int_auto_restart    : STD_LOGIC := '0';
    signal int_gie             : STD_LOGIC := '0';
    signal int_ier             : UNSIGNED(1 downto 0) := (others => '0');
    signal int_isr             : UNSIGNED(1 downto 0) := (others => '0');
    signal int_data_dim1       : UNSIGNED(7 downto 0) := (others => '0');
    signal int_data_dim2       : UNSIGNED(7 downto 0) := (others => '0');
    signal int_data_dim1xdim2  : UNSIGNED(15 downto 0) := (others => '0');
    signal int_weight_dim1     : UNSIGNED(7 downto 0) := (others => '0');
    signal int_weight_dim2     : UNSIGNED(7 downto 0) := (others => '0');
    signal int_weight_dim3     : UNSIGNED(15 downto 0) := (others => '0');
    signal int_weight_dim4_div_lane : UNSIGNED(15 downto 0) := (others => '0');
    signal int_weight_dim1x2   : UNSIGNED(7 downto 0) := (others => '0');
    signal int_weight_dim1x2x3 : UNSIGNED(31 downto 0) := (others => '0');
    signal int_conv_x          : UNSIGNED(7 downto 0) := (others => '0');
    signal int_stride          : UNSIGNED(7 downto 0) := (others => '0');
    signal int_padding         : UNSIGNED(7 downto 0) := (others => '0');
    signal int_split           : UNSIGNED(7 downto 0) := (others => '0');
    signal int_group_num_x     : UNSIGNED(7 downto 0) := (others => '0');
    signal int_group_num_y     : UNSIGNED(7 downto 0) := (others => '0');
    signal int_group_rem_size_x : UNSIGNED(7 downto 0) := (others => '0');
    signal int_group_rem_size_xyz : UNSIGNED(31 downto 0) := (others => '0');
    signal int_win_size_x      : UNSIGNED(7 downto 0) := (others => '0');
    signal int_win_size_y      : UNSIGNED(7 downto 0) := (others => '0');
    signal int_win_size_xyz    : UNSIGNED(31 downto 0) := (others => '0');
    signal int_bottom          : UNSIGNED(63 downto 0) := (others => '0');
    signal int_weights         : UNSIGNED(63 downto 0) := (others => '0');
    signal int_bias            : UNSIGNED(63 downto 0) := (others => '0');


begin
-- ----------------------- Instantiation------------------


-- ----------------------- AXI WRITE ---------------------
    AWREADY_t <=  '1' when wstate = wridle else '0';
    AWREADY   <=  AWREADY_t;
    WREADY_t  <=  '1' when wstate = wrdata else '0';
    WREADY    <=  WREADY_t;
    BRESP     <=  "00";  -- OKAY
    BVALID    <=  '1' when wstate = wrresp else '0';
    wmask     <=  (31 downto 24 => WSTRB(3), 23 downto 16 => WSTRB(2), 15 downto 8 => WSTRB(1), 7 downto 0 => WSTRB(0));
    aw_hs     <=  AWVALID and AWREADY_t;
    w_hs      <=  WVALID and WREADY_t;

    -- write FSM
    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                wstate <= wrreset;
            elsif (ACLK_EN = '1') then
                wstate <= wnext;
            end if;
        end if;
    end process;

    process (wstate, AWVALID, WVALID, BREADY)
    begin
        case (wstate) is
        when wridle =>
            if (AWVALID = '1') then
                wnext <= wrdata;
            else
                wnext <= wridle;
            end if;
        when wrdata =>
            if (WVALID = '1') then
                wnext <= wrresp;
            else
                wnext <= wrdata;
            end if;
        when wrresp =>
            if (BREADY = '1') then
                wnext <= wridle;
            else
                wnext <= wrresp;
            end if;
        when others =>
            wnext <= wridle;
        end case;
    end process;

    waddr_proc : process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (aw_hs = '1') then
                    waddr <= UNSIGNED(AWADDR(ADDR_BITS-1 downto 0));
                end if;
            end if;
        end if;
    end process;

-- ----------------------- AXI READ ----------------------
    ARREADY_t <= '1' when (rstate = rdidle) else '0';
    ARREADY <= ARREADY_t;
    RDATA   <= STD_LOGIC_VECTOR(rdata_data);
    RRESP   <= "00";  -- OKAY
    RVALID_t  <= '1' when (rstate = rddata) else '0';
    RVALID    <= RVALID_t;
    ar_hs   <= ARVALID and ARREADY_t;
    raddr   <= UNSIGNED(ARADDR(ADDR_BITS-1 downto 0));

    -- read FSM
    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                rstate <= rdreset;
            elsif (ACLK_EN = '1') then
                rstate <= rnext;
            end if;
        end if;
    end process;

    process (rstate, ARVALID, RREADY, RVALID_t)
    begin
        case (rstate) is
        when rdidle =>
            if (ARVALID = '1') then
                rnext <= rddata;
            else
                rnext <= rdidle;
            end if;
        when rddata =>
            if (RREADY = '1' and RVALID_t = '1') then
                rnext <= rdidle;
            else
                rnext <= rddata;
            end if;
        when others =>
            rnext <= rdidle;
        end case;
    end process;

    rdata_proc : process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (ar_hs = '1') then
                    rdata_data <= (others => '0');
                    case (TO_INTEGER(raddr)) is
                    when ADDR_AP_CTRL =>
                        rdata_data(7) <= int_auto_restart;
                        rdata_data(4) <= int_ap_continue;
                        rdata_data(3) <= int_ap_ready;
                        rdata_data(2) <= int_ap_idle;
                        rdata_data(1) <= int_ap_done;
                        rdata_data(0) <= int_ap_start;
                    when ADDR_GIE =>
                        rdata_data(0) <= int_gie;
                    when ADDR_IER =>
                        rdata_data(1 downto 0) <= int_ier;
                    when ADDR_ISR =>
                        rdata_data(1 downto 0) <= int_isr;
                    when ADDR_DATA_DIM1_DATA_0 =>
                        rdata_data <= RESIZE(int_data_dim1(7 downto 0), 32);
                    when ADDR_DATA_DIM2_DATA_0 =>
                        rdata_data <= RESIZE(int_data_dim2(7 downto 0), 32);
                    when ADDR_DATA_DIM1XDIM2_DATA_0 =>
                        rdata_data <= RESIZE(int_data_dim1xdim2(15 downto 0), 32);
                    when ADDR_WEIGHT_DIM1_DATA_0 =>
                        rdata_data <= RESIZE(int_weight_dim1(7 downto 0), 32);
                    when ADDR_WEIGHT_DIM2_DATA_0 =>
                        rdata_data <= RESIZE(int_weight_dim2(7 downto 0), 32);
                    when ADDR_WEIGHT_DIM3_DATA_0 =>
                        rdata_data <= RESIZE(int_weight_dim3(15 downto 0), 32);
                    when ADDR_WEIGHT_DIM4_DIV_LANE_DATA_0 =>
                        rdata_data <= RESIZE(int_weight_dim4_div_lane(15 downto 0), 32);
                    when ADDR_WEIGHT_DIM1X2_DATA_0 =>
                        rdata_data <= RESIZE(int_weight_dim1x2(7 downto 0), 32);
                    when ADDR_WEIGHT_DIM1X2X3_DATA_0 =>
                        rdata_data <= RESIZE(int_weight_dim1x2x3(31 downto 0), 32);
                    when ADDR_CONV_X_DATA_0 =>
                        rdata_data <= RESIZE(int_conv_x(7 downto 0), 32);
                    when ADDR_STRIDE_DATA_0 =>
                        rdata_data <= RESIZE(int_stride(7 downto 0), 32);
                    when ADDR_PADDING_DATA_0 =>
                        rdata_data <= RESIZE(int_padding(7 downto 0), 32);
                    when ADDR_SPLIT_DATA_0 =>
                        rdata_data <= RESIZE(int_split(7 downto 0), 32);
                    when ADDR_GROUP_NUM_X_DATA_0 =>
                        rdata_data <= RESIZE(int_group_num_x(7 downto 0), 32);
                    when ADDR_GROUP_NUM_Y_DATA_0 =>
                        rdata_data <= RESIZE(int_group_num_y(7 downto 0), 32);
                    when ADDR_GROUP_REM_SIZE_X_DATA_0 =>
                        rdata_data <= RESIZE(int_group_rem_size_x(7 downto 0), 32);
                    when ADDR_GROUP_REM_SIZE_XYZ_DATA_0 =>
                        rdata_data <= RESIZE(int_group_rem_size_xyz(31 downto 0), 32);
                    when ADDR_WIN_SIZE_X_DATA_0 =>
                        rdata_data <= RESIZE(int_win_size_x(7 downto 0), 32);
                    when ADDR_WIN_SIZE_Y_DATA_0 =>
                        rdata_data <= RESIZE(int_win_size_y(7 downto 0), 32);
                    when ADDR_WIN_SIZE_XYZ_DATA_0 =>
                        rdata_data <= RESIZE(int_win_size_xyz(31 downto 0), 32);
                    when ADDR_BOTTOM_DATA_0 =>
                        rdata_data <= RESIZE(int_bottom(31 downto 0), 32);
                    when ADDR_BOTTOM_DATA_1 =>
                        rdata_data <= RESIZE(int_bottom(63 downto 32), 32);
                    when ADDR_WEIGHTS_DATA_0 =>
                        rdata_data <= RESIZE(int_weights(31 downto 0), 32);
                    when ADDR_WEIGHTS_DATA_1 =>
                        rdata_data <= RESIZE(int_weights(63 downto 32), 32);
                    when ADDR_BIAS_DATA_0 =>
                        rdata_data <= RESIZE(int_bias(31 downto 0), 32);
                    when ADDR_BIAS_DATA_1 =>
                        rdata_data <= RESIZE(int_bias(63 downto 32), 32);
                    when others =>
                        NULL;
                    end case;
                end if;
            end if;
        end if;
    end process;

-- ----------------------- Register logic ----------------
    interrupt            <= int_gie and (int_isr(0) or int_isr(1));
    event_start          <= int_event_start;
    ap_start             <= int_ap_start;
    int_ap_done          <= ap_done;
    ap_continue          <= int_ap_continue;
    data_dim1            <= STD_LOGIC_VECTOR(int_data_dim1);
    data_dim2            <= STD_LOGIC_VECTOR(int_data_dim2);
    data_dim1xdim2       <= STD_LOGIC_VECTOR(int_data_dim1xdim2);
    weight_dim1          <= STD_LOGIC_VECTOR(int_weight_dim1);
    weight_dim2          <= STD_LOGIC_VECTOR(int_weight_dim2);
    weight_dim3          <= STD_LOGIC_VECTOR(int_weight_dim3);
    weight_dim4_div_lane <= STD_LOGIC_VECTOR(int_weight_dim4_div_lane);
    weight_dim1x2        <= STD_LOGIC_VECTOR(int_weight_dim1x2);
    weight_dim1x2x3      <= STD_LOGIC_VECTOR(int_weight_dim1x2x3);
    conv_x               <= STD_LOGIC_VECTOR(int_conv_x);
    stride               <= STD_LOGIC_VECTOR(int_stride);
    padding              <= STD_LOGIC_VECTOR(int_padding);
    split                <= STD_LOGIC_VECTOR(int_split);
    group_num_x          <= STD_LOGIC_VECTOR(int_group_num_x);
    group_num_y          <= STD_LOGIC_VECTOR(int_group_num_y);
    group_rem_size_x     <= STD_LOGIC_VECTOR(int_group_rem_size_x);
    group_rem_size_xyz   <= STD_LOGIC_VECTOR(int_group_rem_size_xyz);
    win_size_x           <= STD_LOGIC_VECTOR(int_win_size_x);
    win_size_y           <= STD_LOGIC_VECTOR(int_win_size_y);
    win_size_xyz         <= STD_LOGIC_VECTOR(int_win_size_xyz);
    bottom               <= STD_LOGIC_VECTOR(int_bottom);
    weights              <= STD_LOGIC_VECTOR(int_weights);
    bias                 <= STD_LOGIC_VECTOR(int_bias);

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_event_start <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_AP_CTRL and WSTRB(0) = '1' and WDATA(0) = '1') then
                    int_event_start <= '1';
                else
                    int_event_start <= '0'; -- self clear
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_start <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_AP_CTRL and WSTRB(0) = '1' and WDATA(0) = '1') then
                    int_ap_start <= '1';
                elsif (ap_ready = '1') then
                    int_ap_start <= int_auto_restart; -- clear on handshake/auto restart
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_idle <= '0';
            elsif (ACLK_EN = '1') then
                if (true) then
                    int_ap_idle <= ap_idle;
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_ready <= '0';
            elsif (ACLK_EN = '1') then
                if (true) then
                    int_ap_ready <= ap_ready;
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_continue <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_AP_CTRL and WSTRB(0) = '1' and WDATA(4) = '1') then
                    int_ap_continue <= '1';
                elsif (ap_done = '1' and int_ap_continue = '0' and int_auto_restart = '1') then
                    int_ap_continue <= '1'; -- auto restart
                else
                    int_ap_continue <= '0'; -- self clear
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_auto_restart <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_AP_CTRL and WSTRB(0) = '1') then
                    int_auto_restart <= WDATA(7);
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_gie <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_GIE and WSTRB(0) = '1') then
                    int_gie <= WDATA(0);
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ier <= "00";
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_IER and WSTRB(0) = '1') then
                    int_ier <= UNSIGNED(WDATA(1 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_isr(0) <= '0';
            elsif (ACLK_EN = '1') then
                if (int_ier(0) = '1' and ap_done = '1') then
                    int_isr(0) <= '1';
                elsif (w_hs = '1' and waddr = ADDR_ISR and WSTRB(0) = '1') then
                    int_isr(0) <= int_isr(0) xor WDATA(0); -- toggle on write
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_isr(1) <= '0';
            elsif (ACLK_EN = '1') then
                if (int_ier(1) = '1' and ap_ready = '1') then
                    int_isr(1) <= '1';
                elsif (w_hs = '1' and waddr = ADDR_ISR and WSTRB(0) = '1') then
                    int_isr(1) <= int_isr(1) xor WDATA(1); -- toggle on write
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_DATA_DIM1_DATA_0) then
                    int_data_dim1(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_data_dim1(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_DATA_DIM2_DATA_0) then
                    int_data_dim2(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_data_dim2(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_DATA_DIM1XDIM2_DATA_0) then
                    int_data_dim1xdim2(15 downto 0) <= (UNSIGNED(WDATA(15 downto 0)) and wmask(15 downto 0)) or ((not wmask(15 downto 0)) and int_data_dim1xdim2(15 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_WEIGHT_DIM1_DATA_0) then
                    int_weight_dim1(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_weight_dim1(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_WEIGHT_DIM2_DATA_0) then
                    int_weight_dim2(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_weight_dim2(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_WEIGHT_DIM3_DATA_0) then
                    int_weight_dim3(15 downto 0) <= (UNSIGNED(WDATA(15 downto 0)) and wmask(15 downto 0)) or ((not wmask(15 downto 0)) and int_weight_dim3(15 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_WEIGHT_DIM4_DIV_LANE_DATA_0) then
                    int_weight_dim4_div_lane(15 downto 0) <= (UNSIGNED(WDATA(15 downto 0)) and wmask(15 downto 0)) or ((not wmask(15 downto 0)) and int_weight_dim4_div_lane(15 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_WEIGHT_DIM1X2_DATA_0) then
                    int_weight_dim1x2(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_weight_dim1x2(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_WEIGHT_DIM1X2X3_DATA_0) then
                    int_weight_dim1x2x3(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_weight_dim1x2x3(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_CONV_X_DATA_0) then
                    int_conv_x(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_conv_x(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_STRIDE_DATA_0) then
                    int_stride(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_stride(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_PADDING_DATA_0) then
                    int_padding(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_padding(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_SPLIT_DATA_0) then
                    int_split(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_split(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_GROUP_NUM_X_DATA_0) then
                    int_group_num_x(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_group_num_x(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_GROUP_NUM_Y_DATA_0) then
                    int_group_num_y(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_group_num_y(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_GROUP_REM_SIZE_X_DATA_0) then
                    int_group_rem_size_x(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_group_rem_size_x(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_GROUP_REM_SIZE_XYZ_DATA_0) then
                    int_group_rem_size_xyz(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_group_rem_size_xyz(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_WIN_SIZE_X_DATA_0) then
                    int_win_size_x(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_win_size_x(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_WIN_SIZE_Y_DATA_0) then
                    int_win_size_y(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_win_size_y(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_WIN_SIZE_XYZ_DATA_0) then
                    int_win_size_xyz(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_win_size_xyz(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_BOTTOM_DATA_0) then
                    int_bottom(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_bottom(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_BOTTOM_DATA_1) then
                    int_bottom(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_bottom(63 downto 32));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_WEIGHTS_DATA_0) then
                    int_weights(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_weights(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_WEIGHTS_DATA_1) then
                    int_weights(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_weights(63 downto 32));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_BIAS_DATA_0) then
                    int_bias(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_bias(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_BIAS_DATA_1) then
                    int_bias(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_bias(63 downto 32));
                end if;
            end if;
        end if;
    end process;


-- ----------------------- Memory logic ------------------

end architecture behave;
