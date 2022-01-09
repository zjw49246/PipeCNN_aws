// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
`timescale 1ns/1ps
module memWrite_control_s_axi
#(parameter
    C_S_AXI_ADDR_WIDTH = 7,
    C_S_AXI_DATA_WIDTH = 32
)(
    input  wire                          ACLK,
    input  wire                          ARESET,
    input  wire                          ACLK_EN,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] AWADDR,
    input  wire                          AWVALID,
    output wire                          AWREADY,
    input  wire [C_S_AXI_DATA_WIDTH-1:0] WDATA,
    input  wire [C_S_AXI_DATA_WIDTH/8-1:0] WSTRB,
    input  wire                          WVALID,
    output wire                          WREADY,
    output wire [1:0]                    BRESP,
    output wire                          BVALID,
    input  wire                          BREADY,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] ARADDR,
    input  wire                          ARVALID,
    output wire                          ARREADY,
    output wire [C_S_AXI_DATA_WIDTH-1:0] RDATA,
    output wire [1:0]                    RRESP,
    output wire                          RVALID,
    input  wire                          RREADY,
    output wire                          interrupt,
    output wire [7:0]                    out_dim1,
    output wire [7:0]                    out_dim2,
    output wire [15:0]                   out_dim3,
    output wire [15:0]                   out_dim1xbatch,
    output wire [31:0]                   out_dim1x2xbatch,
    output wire [7:0]                    batch_indx_dim1,
    output wire [7:0]                    batch_indx_dim2,
    output wire [7:0]                    padd_offset,
    output wire [7:0]                    pool_on,
    output wire [7:0]                    pool_size,
    output wire [7:0]                    pool_stride,
    output wire [63:0]                   top,
    output wire                          ap_start,
    input  wire                          ap_done,
    input  wire                          ap_ready,
    output wire                          ap_continue,
    input  wire                          ap_idle,
    output wire                          event_start
);
//------------------------Address Info-------------------
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 4  - ap_continue (Read/Write/SC)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - enable ap_done interrupt (Read/Write)
//        bit 1  - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - ap_done (COR/TOW)
//        bit 1  - ap_ready (COR/TOW)
//        others - reserved
// 0x10 : Data signal of out_dim1
//        bit 7~0 - out_dim1[7:0] (Read/Write)
//        others  - reserved
// 0x14 : reserved
// 0x18 : Data signal of out_dim2
//        bit 7~0 - out_dim2[7:0] (Read/Write)
//        others  - reserved
// 0x1c : reserved
// 0x20 : Data signal of out_dim3
//        bit 15~0 - out_dim3[15:0] (Read/Write)
//        others   - reserved
// 0x24 : reserved
// 0x28 : Data signal of out_dim1xbatch
//        bit 15~0 - out_dim1xbatch[15:0] (Read/Write)
//        others   - reserved
// 0x2c : reserved
// 0x30 : Data signal of out_dim1x2xbatch
//        bit 31~0 - out_dim1x2xbatch[31:0] (Read/Write)
// 0x34 : reserved
// 0x38 : Data signal of batch_indx_dim1
//        bit 7~0 - batch_indx_dim1[7:0] (Read/Write)
//        others  - reserved
// 0x3c : reserved
// 0x40 : Data signal of batch_indx_dim2
//        bit 7~0 - batch_indx_dim2[7:0] (Read/Write)
//        others  - reserved
// 0x44 : reserved
// 0x48 : Data signal of padd_offset
//        bit 7~0 - padd_offset[7:0] (Read/Write)
//        others  - reserved
// 0x4c : reserved
// 0x50 : Data signal of pool_on
//        bit 7~0 - pool_on[7:0] (Read/Write)
//        others  - reserved
// 0x54 : reserved
// 0x58 : Data signal of pool_size
//        bit 7~0 - pool_size[7:0] (Read/Write)
//        others  - reserved
// 0x5c : reserved
// 0x60 : Data signal of pool_stride
//        bit 7~0 - pool_stride[7:0] (Read/Write)
//        others  - reserved
// 0x64 : reserved
// 0x68 : Data signal of top
//        bit 31~0 - top[31:0] (Read/Write)
// 0x6c : Data signal of top
//        bit 31~0 - top[63:32] (Read/Write)
// 0x70 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

//------------------------Parameter----------------------
localparam
    ADDR_AP_CTRL                 = 7'h00,
    ADDR_GIE                     = 7'h04,
    ADDR_IER                     = 7'h08,
    ADDR_ISR                     = 7'h0c,
    ADDR_OUT_DIM1_DATA_0         = 7'h10,
    ADDR_OUT_DIM1_CTRL           = 7'h14,
    ADDR_OUT_DIM2_DATA_0         = 7'h18,
    ADDR_OUT_DIM2_CTRL           = 7'h1c,
    ADDR_OUT_DIM3_DATA_0         = 7'h20,
    ADDR_OUT_DIM3_CTRL           = 7'h24,
    ADDR_OUT_DIM1XBATCH_DATA_0   = 7'h28,
    ADDR_OUT_DIM1XBATCH_CTRL     = 7'h2c,
    ADDR_OUT_DIM1X2XBATCH_DATA_0 = 7'h30,
    ADDR_OUT_DIM1X2XBATCH_CTRL   = 7'h34,
    ADDR_BATCH_INDX_DIM1_DATA_0  = 7'h38,
    ADDR_BATCH_INDX_DIM1_CTRL    = 7'h3c,
    ADDR_BATCH_INDX_DIM2_DATA_0  = 7'h40,
    ADDR_BATCH_INDX_DIM2_CTRL    = 7'h44,
    ADDR_PADD_OFFSET_DATA_0      = 7'h48,
    ADDR_PADD_OFFSET_CTRL        = 7'h4c,
    ADDR_POOL_ON_DATA_0          = 7'h50,
    ADDR_POOL_ON_CTRL            = 7'h54,
    ADDR_POOL_SIZE_DATA_0        = 7'h58,
    ADDR_POOL_SIZE_CTRL          = 7'h5c,
    ADDR_POOL_STRIDE_DATA_0      = 7'h60,
    ADDR_POOL_STRIDE_CTRL        = 7'h64,
    ADDR_TOP_DATA_0              = 7'h68,
    ADDR_TOP_DATA_1              = 7'h6c,
    ADDR_TOP_CTRL                = 7'h70,
    WRIDLE                       = 2'd0,
    WRDATA                       = 2'd1,
    WRRESP                       = 2'd2,
    WRRESET                      = 2'd3,
    RDIDLE                       = 2'd0,
    RDDATA                       = 2'd1,
    RDRESET                      = 2'd2,
    ADDR_BITS                = 7;

//------------------------Local signal-------------------
    reg  [1:0]                    wstate = WRRESET;
    reg  [1:0]                    wnext;
    reg  [ADDR_BITS-1:0]          waddr;
    wire [C_S_AXI_DATA_WIDTH-1:0] wmask;
    wire                          aw_hs;
    wire                          w_hs;
    reg  [1:0]                    rstate = RDRESET;
    reg  [1:0]                    rnext;
    reg  [C_S_AXI_DATA_WIDTH-1:0] rdata;
    wire                          ar_hs;
    wire [ADDR_BITS-1:0]          raddr;
    // internal registers
    reg                           int_event_start = 1'b0;
    reg                           int_ap_idle;
    reg                           int_ap_continue;
    reg                           int_ap_ready;
    wire                          int_ap_done;
    reg                           int_ap_start = 1'b0;
    reg                           int_auto_restart = 1'b0;
    reg                           int_gie = 1'b0;
    reg  [1:0]                    int_ier = 2'b0;
    reg  [1:0]                    int_isr = 2'b0;
    reg  [7:0]                    int_out_dim1 = 'b0;
    reg  [7:0]                    int_out_dim2 = 'b0;
    reg  [15:0]                   int_out_dim3 = 'b0;
    reg  [15:0]                   int_out_dim1xbatch = 'b0;
    reg  [31:0]                   int_out_dim1x2xbatch = 'b0;
    reg  [7:0]                    int_batch_indx_dim1 = 'b0;
    reg  [7:0]                    int_batch_indx_dim2 = 'b0;
    reg  [7:0]                    int_padd_offset = 'b0;
    reg  [7:0]                    int_pool_on = 'b0;
    reg  [7:0]                    int_pool_size = 'b0;
    reg  [7:0]                    int_pool_stride = 'b0;
    reg  [63:0]                   int_top = 'b0;

//------------------------Instantiation------------------


//------------------------AXI write fsm------------------
assign AWREADY = (wstate == WRIDLE);
assign WREADY  = (wstate == WRDATA);
assign BRESP   = 2'b00;  // OKAY
assign BVALID  = (wstate == WRRESP);
assign wmask   = { {8{WSTRB[3]}}, {8{WSTRB[2]}}, {8{WSTRB[1]}}, {8{WSTRB[0]}} };
assign aw_hs   = AWVALID & AWREADY;
assign w_hs    = WVALID & WREADY;

// wstate
always @(posedge ACLK) begin
    if (ARESET)
        wstate <= WRRESET;
    else if (ACLK_EN)
        wstate <= wnext;
end

// wnext
always @(*) begin
    case (wstate)
        WRIDLE:
            if (AWVALID)
                wnext = WRDATA;
            else
                wnext = WRIDLE;
        WRDATA:
            if (WVALID)
                wnext = WRRESP;
            else
                wnext = WRDATA;
        WRRESP:
            if (BREADY)
                wnext = WRIDLE;
            else
                wnext = WRRESP;
        default:
            wnext = WRIDLE;
    endcase
end

// waddr
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (aw_hs)
            waddr <= AWADDR[ADDR_BITS-1:0];
    end
end

//------------------------AXI read fsm-------------------
assign ARREADY = (rstate == RDIDLE);
assign RDATA   = rdata;
assign RRESP   = 2'b00;  // OKAY
assign RVALID  = (rstate == RDDATA);
assign ar_hs   = ARVALID & ARREADY;
assign raddr   = ARADDR[ADDR_BITS-1:0];

// rstate
always @(posedge ACLK) begin
    if (ARESET)
        rstate <= RDRESET;
    else if (ACLK_EN)
        rstate <= rnext;
end

// rnext
always @(*) begin
    case (rstate)
        RDIDLE:
            if (ARVALID)
                rnext = RDDATA;
            else
                rnext = RDIDLE;
        RDDATA:
            if (RREADY & RVALID)
                rnext = RDIDLE;
            else
                rnext = RDDATA;
        default:
            rnext = RDIDLE;
    endcase
end

// rdata
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (ar_hs) begin
            rdata <= 'b0;
            case (raddr)
                ADDR_AP_CTRL: begin
                    rdata[0] <= int_ap_start;
                    rdata[1] <= int_ap_done;
                    rdata[2] <= int_ap_idle;
                    rdata[3] <= int_ap_ready;
                    rdata[4] <= int_ap_continue;
                    rdata[7] <= int_auto_restart;
                end
                ADDR_GIE: begin
                    rdata <= int_gie;
                end
                ADDR_IER: begin
                    rdata <= int_ier;
                end
                ADDR_ISR: begin
                    rdata <= int_isr;
                end
                ADDR_OUT_DIM1_DATA_0: begin
                    rdata <= int_out_dim1[7:0];
                end
                ADDR_OUT_DIM2_DATA_0: begin
                    rdata <= int_out_dim2[7:0];
                end
                ADDR_OUT_DIM3_DATA_0: begin
                    rdata <= int_out_dim3[15:0];
                end
                ADDR_OUT_DIM1XBATCH_DATA_0: begin
                    rdata <= int_out_dim1xbatch[15:0];
                end
                ADDR_OUT_DIM1X2XBATCH_DATA_0: begin
                    rdata <= int_out_dim1x2xbatch[31:0];
                end
                ADDR_BATCH_INDX_DIM1_DATA_0: begin
                    rdata <= int_batch_indx_dim1[7:0];
                end
                ADDR_BATCH_INDX_DIM2_DATA_0: begin
                    rdata <= int_batch_indx_dim2[7:0];
                end
                ADDR_PADD_OFFSET_DATA_0: begin
                    rdata <= int_padd_offset[7:0];
                end
                ADDR_POOL_ON_DATA_0: begin
                    rdata <= int_pool_on[7:0];
                end
                ADDR_POOL_SIZE_DATA_0: begin
                    rdata <= int_pool_size[7:0];
                end
                ADDR_POOL_STRIDE_DATA_0: begin
                    rdata <= int_pool_stride[7:0];
                end
                ADDR_TOP_DATA_0: begin
                    rdata <= int_top[31:0];
                end
                ADDR_TOP_DATA_1: begin
                    rdata <= int_top[63:32];
                end
            endcase
        end
    end
end


//------------------------Register logic-----------------
assign interrupt        = int_gie & (|int_isr);
assign event_start      = int_event_start;
assign ap_start         = int_ap_start;
assign int_ap_done      = ap_done;
assign ap_continue      = int_ap_continue;
assign out_dim1         = int_out_dim1;
assign out_dim2         = int_out_dim2;
assign out_dim3         = int_out_dim3;
assign out_dim1xbatch   = int_out_dim1xbatch;
assign out_dim1x2xbatch = int_out_dim1x2xbatch;
assign batch_indx_dim1  = int_batch_indx_dim1;
assign batch_indx_dim2  = int_batch_indx_dim2;
assign padd_offset      = int_padd_offset;
assign pool_on          = int_pool_on;
assign pool_size        = int_pool_size;
assign pool_stride      = int_pool_stride;
assign top              = int_top;
// int_event_start
always @(posedge ACLK) begin
    if (ARESET)
        int_event_start <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AP_CTRL && WSTRB[0] && WDATA[0])
            int_event_start <= 1'b1;
        else
            int_event_start <= 1'b0; // self clear
    end
end

// int_ap_start
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_start <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AP_CTRL && WSTRB[0] && WDATA[0])
            int_ap_start <= 1'b1;
        else if (ap_ready)
            int_ap_start <= int_auto_restart; // clear on handshake/auto restart
    end
end

// int_ap_idle
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_idle <= 1'b0;
    else if (ACLK_EN) begin
            int_ap_idle <= ap_idle;
    end
end

// int_ap_ready
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_ready <= 1'b0;
    else if (ACLK_EN) begin
            int_ap_ready <= ap_ready;
    end
end

// int_ap_continue
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_continue <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AP_CTRL && WSTRB[0] && WDATA[4])
            int_ap_continue <= 1'b1;
        else if (ap_done & ~int_ap_continue & int_auto_restart)
            int_ap_continue <= 1'b1; // auto restart
        else
            int_ap_continue <= 1'b0; // self clear
    end
end

// int_auto_restart
always @(posedge ACLK) begin
    if (ARESET)
        int_auto_restart <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AP_CTRL && WSTRB[0])
            int_auto_restart <=  WDATA[7];
    end
end

// int_gie
always @(posedge ACLK) begin
    if (ARESET)
        int_gie <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_GIE && WSTRB[0])
            int_gie <= WDATA[0];
    end
end

// int_ier
always @(posedge ACLK) begin
    if (ARESET)
        int_ier <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_IER && WSTRB[0])
            int_ier <= WDATA[1:0];
    end
end

// int_isr[0]
always @(posedge ACLK) begin
    if (ARESET)
        int_isr[0] <= 1'b0;
    else if (ACLK_EN) begin
        if (int_ier[0] & ap_done)
            int_isr[0] <= 1'b1;
        else if (w_hs && waddr == ADDR_ISR && WSTRB[0])
            int_isr[0] <= int_isr[0] ^ WDATA[0]; // toggle on write
    end
end

// int_isr[1]
always @(posedge ACLK) begin
    if (ARESET)
        int_isr[1] <= 1'b0;
    else if (ACLK_EN) begin
        if (int_ier[1] & ap_ready)
            int_isr[1] <= 1'b1;
        else if (w_hs && waddr == ADDR_ISR && WSTRB[0])
            int_isr[1] <= int_isr[1] ^ WDATA[1]; // toggle on write
    end
end

// int_out_dim1[7:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_out_dim1[7:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_OUT_DIM1_DATA_0)
            int_out_dim1[7:0] <= (WDATA[31:0] & wmask) | (int_out_dim1[7:0] & ~wmask);
    end
end

// int_out_dim2[7:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_out_dim2[7:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_OUT_DIM2_DATA_0)
            int_out_dim2[7:0] <= (WDATA[31:0] & wmask) | (int_out_dim2[7:0] & ~wmask);
    end
end

// int_out_dim3[15:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_out_dim3[15:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_OUT_DIM3_DATA_0)
            int_out_dim3[15:0] <= (WDATA[31:0] & wmask) | (int_out_dim3[15:0] & ~wmask);
    end
end

// int_out_dim1xbatch[15:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_out_dim1xbatch[15:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_OUT_DIM1XBATCH_DATA_0)
            int_out_dim1xbatch[15:0] <= (WDATA[31:0] & wmask) | (int_out_dim1xbatch[15:0] & ~wmask);
    end
end

// int_out_dim1x2xbatch[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_out_dim1x2xbatch[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_OUT_DIM1X2XBATCH_DATA_0)
            int_out_dim1x2xbatch[31:0] <= (WDATA[31:0] & wmask) | (int_out_dim1x2xbatch[31:0] & ~wmask);
    end
end

// int_batch_indx_dim1[7:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_batch_indx_dim1[7:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_BATCH_INDX_DIM1_DATA_0)
            int_batch_indx_dim1[7:0] <= (WDATA[31:0] & wmask) | (int_batch_indx_dim1[7:0] & ~wmask);
    end
end

// int_batch_indx_dim2[7:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_batch_indx_dim2[7:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_BATCH_INDX_DIM2_DATA_0)
            int_batch_indx_dim2[7:0] <= (WDATA[31:0] & wmask) | (int_batch_indx_dim2[7:0] & ~wmask);
    end
end

// int_padd_offset[7:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_padd_offset[7:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_PADD_OFFSET_DATA_0)
            int_padd_offset[7:0] <= (WDATA[31:0] & wmask) | (int_padd_offset[7:0] & ~wmask);
    end
end

// int_pool_on[7:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_pool_on[7:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_POOL_ON_DATA_0)
            int_pool_on[7:0] <= (WDATA[31:0] & wmask) | (int_pool_on[7:0] & ~wmask);
    end
end

// int_pool_size[7:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_pool_size[7:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_POOL_SIZE_DATA_0)
            int_pool_size[7:0] <= (WDATA[31:0] & wmask) | (int_pool_size[7:0] & ~wmask);
    end
end

// int_pool_stride[7:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_pool_stride[7:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_POOL_STRIDE_DATA_0)
            int_pool_stride[7:0] <= (WDATA[31:0] & wmask) | (int_pool_stride[7:0] & ~wmask);
    end
end

// int_top[31:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_top[31:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_TOP_DATA_0)
            int_top[31:0] <= (WDATA[31:0] & wmask) | (int_top[31:0] & ~wmask);
    end
end

// int_top[63:32]
always @(posedge ACLK) begin
    if (ARESET)
        int_top[63:32] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_TOP_DATA_1)
            int_top[63:32] <= (WDATA[31:0] & wmask) | (int_top[63:32] & ~wmask);
    end
end


//------------------------Memory logic-------------------

endmodule
