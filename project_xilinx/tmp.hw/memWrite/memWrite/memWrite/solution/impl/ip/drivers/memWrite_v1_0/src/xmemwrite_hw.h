// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
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

#define XMEMWRITE_CONTROL_ADDR_AP_CTRL               0x00
#define XMEMWRITE_CONTROL_ADDR_GIE                   0x04
#define XMEMWRITE_CONTROL_ADDR_IER                   0x08
#define XMEMWRITE_CONTROL_ADDR_ISR                   0x0c
#define XMEMWRITE_CONTROL_ADDR_OUT_DIM1_DATA         0x10
#define XMEMWRITE_CONTROL_BITS_OUT_DIM1_DATA         8
#define XMEMWRITE_CONTROL_ADDR_OUT_DIM2_DATA         0x18
#define XMEMWRITE_CONTROL_BITS_OUT_DIM2_DATA         8
#define XMEMWRITE_CONTROL_ADDR_OUT_DIM3_DATA         0x20
#define XMEMWRITE_CONTROL_BITS_OUT_DIM3_DATA         16
#define XMEMWRITE_CONTROL_ADDR_OUT_DIM1XBATCH_DATA   0x28
#define XMEMWRITE_CONTROL_BITS_OUT_DIM1XBATCH_DATA   16
#define XMEMWRITE_CONTROL_ADDR_OUT_DIM1X2XBATCH_DATA 0x30
#define XMEMWRITE_CONTROL_BITS_OUT_DIM1X2XBATCH_DATA 32
#define XMEMWRITE_CONTROL_ADDR_BATCH_INDX_DIM1_DATA  0x38
#define XMEMWRITE_CONTROL_BITS_BATCH_INDX_DIM1_DATA  8
#define XMEMWRITE_CONTROL_ADDR_BATCH_INDX_DIM2_DATA  0x40
#define XMEMWRITE_CONTROL_BITS_BATCH_INDX_DIM2_DATA  8
#define XMEMWRITE_CONTROL_ADDR_PADD_OFFSET_DATA      0x48
#define XMEMWRITE_CONTROL_BITS_PADD_OFFSET_DATA      8
#define XMEMWRITE_CONTROL_ADDR_POOL_ON_DATA          0x50
#define XMEMWRITE_CONTROL_BITS_POOL_ON_DATA          8
#define XMEMWRITE_CONTROL_ADDR_POOL_SIZE_DATA        0x58
#define XMEMWRITE_CONTROL_BITS_POOL_SIZE_DATA        8
#define XMEMWRITE_CONTROL_ADDR_POOL_STRIDE_DATA      0x60
#define XMEMWRITE_CONTROL_BITS_POOL_STRIDE_DATA      8
#define XMEMWRITE_CONTROL_ADDR_TOP_DATA              0x68
#define XMEMWRITE_CONTROL_BITS_TOP_DATA              64

