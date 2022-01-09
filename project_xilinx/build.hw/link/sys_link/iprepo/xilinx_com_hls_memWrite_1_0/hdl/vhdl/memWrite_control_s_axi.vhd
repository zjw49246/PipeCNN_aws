-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
-- Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

entity memWrite_control_s_axi is
generic (
    C_S_AXI_ADDR_WIDTH    : INTEGER := 7;
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
    out_dim1              :out  STD_LOGIC_VECTOR(7 downto 0);
    out_dim2              :out  STD_LOGIC_VECTOR(7 downto 0);
    out_dim3              :out  STD_LOGIC_VECTOR(15 downto 0);
    out_dim1xbatch        :out  STD_LOGIC_VECTOR(15 downto 0);
    out_dim1x2xbatch      :out  STD_LOGIC_VECTOR(31 downto 0);
    batch_indx_dim1       :out  STD_LOGIC_VECTOR(7 downto 0);
    batch_indx_dim2       :out  STD_LOGIC_VECTOR(7 downto 0);
    padd_offset           :out  STD_LOGIC_VECTOR(7 downto 0);
    pool_on               :out  STD_LOGIC_VECTOR(7 downto 0);
    pool_size             :out  STD_LOGIC_VECTOR(7 downto 0);
    pool_stride           :out  STD_LOGIC_VECTOR(7 downto 0);
    top                   :out  STD_LOGIC_VECTOR(63 downto 0);
    ap_start              :out  STD_LOGIC;
    ap_done               :in   STD_LOGIC;
    ap_ready              :in   STD_LOGIC;
    ap_continue           :out  STD_LOGIC;
    ap_idle               :in   STD_LOGIC;
    event_start           :out  STD_LOGIC
);
end entity memWrite_control_s_axi;

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
-- 0x10 : Data signal of out_dim1
--        bit 7~0 - out_dim1[7:0] (Read/Write)
--        others  - reserved
-- 0x14 : reserved
-- 0x18 : Data signal of out_dim2
--        bit 7~0 - out_dim2[7:0] (Read/Write)
--        others  - reserved
-- 0x1c : reserved
-- 0x20 : Data signal of out_dim3
--        bit 15~0 - out_dim3[15:0] (Read/Write)
--        others   - reserved
-- 0x24 : reserved
-- 0x28 : Data signal of out_dim1xbatch
--        bit 15~0 - out_dim1xbatch[15:0] (Read/Write)
--        others   - reserved
-- 0x2c : reserved
-- 0x30 : Data signal of out_dim1x2xbatch
--        bit 31~0 - out_dim1x2xbatch[31:0] (Read/Write)
-- 0x34 : reserved
-- 0x38 : Data signal of batch_indx_dim1
--        bit 7~0 - batch_indx_dim1[7:0] (Read/Write)
--        others  - reserved
-- 0x3c : reserved
-- 0x40 : Data signal of batch_indx_dim2
--        bit 7~0 - batch_indx_dim2[7:0] (Read/Write)
--        others  - reserved
-- 0x44 : reserved
-- 0x48 : Data signal of padd_offset
--        bit 7~0 - padd_offset[7:0] (Read/Write)
--        others  - reserved
-- 0x4c : reserved
-- 0x50 : Data signal of pool_on
--        bit 7~0 - pool_on[7:0] (Read/Write)
--        others  - reserved
-- 0x54 : reserved
-- 0x58 : Data signal of pool_size
--        bit 7~0 - pool_size[7:0] (Read/Write)
--        others  - reserved
-- 0x5c : reserved
-- 0x60 : Data signal of pool_stride
--        bit 7~0 - pool_stride[7:0] (Read/Write)
--        others  - reserved
-- 0x64 : reserved
-- 0x68 : Data signal of top
--        bit 31~0 - top[31:0] (Read/Write)
-- 0x6c : Data signal of top
--        bit 31~0 - top[63:32] (Read/Write)
-- 0x70 : reserved
-- (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

architecture behave of memWrite_control_s_axi is
    type states is (wridle, wrdata, wrresp, wrreset, rdidle, rddata, rdreset);  -- read and write fsm states
    signal wstate  : states := wrreset;
    signal rstate  : states := rdreset;
    signal wnext, rnext: states;
    constant ADDR_AP_CTRL                 : INTEGER := 16#00#;
    constant ADDR_GIE                     : INTEGER := 16#04#;
    constant ADDR_IER                     : INTEGER := 16#08#;
    constant ADDR_ISR                     : INTEGER := 16#0c#;
    constant ADDR_OUT_DIM1_DATA_0         : INTEGER := 16#10#;
    constant ADDR_OUT_DIM1_CTRL           : INTEGER := 16#14#;
    constant ADDR_OUT_DIM2_DATA_0         : INTEGER := 16#18#;
    constant ADDR_OUT_DIM2_CTRL           : INTEGER := 16#1c#;
    constant ADDR_OUT_DIM3_DATA_0         : INTEGER := 16#20#;
    constant ADDR_OUT_DIM3_CTRL           : INTEGER := 16#24#;
    constant ADDR_OUT_DIM1XBATCH_DATA_0   : INTEGER := 16#28#;
    constant ADDR_OUT_DIM1XBATCH_CTRL     : INTEGER := 16#2c#;
    constant ADDR_OUT_DIM1X2XBATCH_DATA_0 : INTEGER := 16#30#;
    constant ADDR_OUT_DIM1X2XBATCH_CTRL   : INTEGER := 16#34#;
    constant ADDR_BATCH_INDX_DIM1_DATA_0  : INTEGER := 16#38#;
    constant ADDR_BATCH_INDX_DIM1_CTRL    : INTEGER := 16#3c#;
    constant ADDR_BATCH_INDX_DIM2_DATA_0  : INTEGER := 16#40#;
    constant ADDR_BATCH_INDX_DIM2_CTRL    : INTEGER := 16#44#;
    constant ADDR_PADD_OFFSET_DATA_0      : INTEGER := 16#48#;
    constant ADDR_PADD_OFFSET_CTRL        : INTEGER := 16#4c#;
    constant ADDR_POOL_ON_DATA_0          : INTEGER := 16#50#;
    constant ADDR_POOL_ON_CTRL            : INTEGER := 16#54#;
    constant ADDR_POOL_SIZE_DATA_0        : INTEGER := 16#58#;
    constant ADDR_POOL_SIZE_CTRL          : INTEGER := 16#5c#;
    constant ADDR_POOL_STRIDE_DATA_0      : INTEGER := 16#60#;
    constant ADDR_POOL_STRIDE_CTRL        : INTEGER := 16#64#;
    constant ADDR_TOP_DATA_0              : INTEGER := 16#68#;
    constant ADDR_TOP_DATA_1              : INTEGER := 16#6c#;
    constant ADDR_TOP_CTRL                : INTEGER := 16#70#;
    constant ADDR_BITS         : INTEGER := 7;

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
    signal int_out_dim1        : UNSIGNED(7 downto 0) := (others => '0');
    signal int_out_dim2        : UNSIGNED(7 downto 0) := (others => '0');
    signal int_out_dim3        : UNSIGNED(15 downto 0) := (others => '0');
    signal int_out_dim1xbatch  : UNSIGNED(15 downto 0) := (others => '0');
    signal int_out_dim1x2xbatch : UNSIGNED(31 downto 0) := (others => '0');
    signal int_batch_indx_dim1 : UNSIGNED(7 downto 0) := (others => '0');
    signal int_batch_indx_dim2 : UNSIGNED(7 downto 0) := (others => '0');
    signal int_padd_offset     : UNSIGNED(7 downto 0) := (others => '0');
    signal int_pool_on         : UNSIGNED(7 downto 0) := (others => '0');
    signal int_pool_size       : UNSIGNED(7 downto 0) := (others => '0');
    signal int_pool_stride     : UNSIGNED(7 downto 0) := (others => '0');
    signal int_top             : UNSIGNED(63 downto 0) := (others => '0');


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
                    when ADDR_OUT_DIM1_DATA_0 =>
                        rdata_data <= RESIZE(int_out_dim1(7 downto 0), 32);
                    when ADDR_OUT_DIM2_DATA_0 =>
                        rdata_data <= RESIZE(int_out_dim2(7 downto 0), 32);
                    when ADDR_OUT_DIM3_DATA_0 =>
                        rdata_data <= RESIZE(int_out_dim3(15 downto 0), 32);
                    when ADDR_OUT_DIM1XBATCH_DATA_0 =>
                        rdata_data <= RESIZE(int_out_dim1xbatch(15 downto 0), 32);
                    when ADDR_OUT_DIM1X2XBATCH_DATA_0 =>
                        rdata_data <= RESIZE(int_out_dim1x2xbatch(31 downto 0), 32);
                    when ADDR_BATCH_INDX_DIM1_DATA_0 =>
                        rdata_data <= RESIZE(int_batch_indx_dim1(7 downto 0), 32);
                    when ADDR_BATCH_INDX_DIM2_DATA_0 =>
                        rdata_data <= RESIZE(int_batch_indx_dim2(7 downto 0), 32);
                    when ADDR_PADD_OFFSET_DATA_0 =>
                        rdata_data <= RESIZE(int_padd_offset(7 downto 0), 32);
                    when ADDR_POOL_ON_DATA_0 =>
                        rdata_data <= RESIZE(int_pool_on(7 downto 0), 32);
                    when ADDR_POOL_SIZE_DATA_0 =>
                        rdata_data <= RESIZE(int_pool_size(7 downto 0), 32);
                    when ADDR_POOL_STRIDE_DATA_0 =>
                        rdata_data <= RESIZE(int_pool_stride(7 downto 0), 32);
                    when ADDR_TOP_DATA_0 =>
                        rdata_data <= RESIZE(int_top(31 downto 0), 32);
                    when ADDR_TOP_DATA_1 =>
                        rdata_data <= RESIZE(int_top(63 downto 32), 32);
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
    out_dim1             <= STD_LOGIC_VECTOR(int_out_dim1);
    out_dim2             <= STD_LOGIC_VECTOR(int_out_dim2);
    out_dim3             <= STD_LOGIC_VECTOR(int_out_dim3);
    out_dim1xbatch       <= STD_LOGIC_VECTOR(int_out_dim1xbatch);
    out_dim1x2xbatch     <= STD_LOGIC_VECTOR(int_out_dim1x2xbatch);
    batch_indx_dim1      <= STD_LOGIC_VECTOR(int_batch_indx_dim1);
    batch_indx_dim2      <= STD_LOGIC_VECTOR(int_batch_indx_dim2);
    padd_offset          <= STD_LOGIC_VECTOR(int_padd_offset);
    pool_on              <= STD_LOGIC_VECTOR(int_pool_on);
    pool_size            <= STD_LOGIC_VECTOR(int_pool_size);
    pool_stride          <= STD_LOGIC_VECTOR(int_pool_stride);
    top                  <= STD_LOGIC_VECTOR(int_top);

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
                if (w_hs = '1' and waddr = ADDR_OUT_DIM1_DATA_0) then
                    int_out_dim1(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_out_dim1(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_OUT_DIM2_DATA_0) then
                    int_out_dim2(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_out_dim2(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_OUT_DIM3_DATA_0) then
                    int_out_dim3(15 downto 0) <= (UNSIGNED(WDATA(15 downto 0)) and wmask(15 downto 0)) or ((not wmask(15 downto 0)) and int_out_dim3(15 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_OUT_DIM1XBATCH_DATA_0) then
                    int_out_dim1xbatch(15 downto 0) <= (UNSIGNED(WDATA(15 downto 0)) and wmask(15 downto 0)) or ((not wmask(15 downto 0)) and int_out_dim1xbatch(15 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_OUT_DIM1X2XBATCH_DATA_0) then
                    int_out_dim1x2xbatch(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_out_dim1x2xbatch(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_BATCH_INDX_DIM1_DATA_0) then
                    int_batch_indx_dim1(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_batch_indx_dim1(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_BATCH_INDX_DIM2_DATA_0) then
                    int_batch_indx_dim2(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_batch_indx_dim2(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_PADD_OFFSET_DATA_0) then
                    int_padd_offset(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_padd_offset(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_POOL_ON_DATA_0) then
                    int_pool_on(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_pool_on(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_POOL_SIZE_DATA_0) then
                    int_pool_size(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_pool_size(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_POOL_STRIDE_DATA_0) then
                    int_pool_stride(7 downto 0) <= (UNSIGNED(WDATA(7 downto 0)) and wmask(7 downto 0)) or ((not wmask(7 downto 0)) and int_pool_stride(7 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_TOP_DATA_0) then
                    int_top(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_top(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_TOP_DATA_1) then
                    int_top(63 downto 32) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_top(63 downto 32));
                end if;
            end if;
        end if;
    end process;


-- ----------------------- Memory logic ------------------

end architecture behave;
