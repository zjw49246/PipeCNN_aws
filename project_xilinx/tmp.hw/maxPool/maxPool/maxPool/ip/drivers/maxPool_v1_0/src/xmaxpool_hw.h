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
// 0x10 : Data signal of conv_x
//        bit 7~0 - conv_x[7:0] (Read/Write)
//        others  - reserved
// 0x14 : reserved
// 0x18 : Data signal of conv_xy
//        bit 15~0 - conv_xy[15:0] (Read/Write)
//        others   - reserved
// 0x1c : reserved
// 0x20 : Data signal of pool_dim1
//        bit 7~0 - pool_dim1[7:0] (Read/Write)
//        others  - reserved
// 0x24 : reserved
// 0x28 : Data signal of pool_dim3
//        bit 15~0 - pool_dim3[15:0] (Read/Write)
//        others   - reserved
// 0x2c : reserved
// 0x30 : Data signal of pool_dim1x2
//        bit 15~0 - pool_dim1x2[15:0] (Read/Write)
//        others   - reserved
// 0x34 : reserved
// 0x38 : Data signal of pool_size
//        bit 7~0 - pool_size[7:0] (Read/Write)
//        others  - reserved
// 0x3c : reserved
// 0x40 : Data signal of pool_stride
//        bit 7~0 - pool_stride[7:0] (Read/Write)
//        others  - reserved
// 0x44 : reserved
// 0x48 : Data signal of padd_offset
//        bit 7~0 - padd_offset[7:0] (Read/Write)
//        others  - reserved
// 0x4c : reserved
// 0x50 : Data signal of pool_times
//        bit 15~0 - pool_times[15:0] (Read/Write)
//        others   - reserved
// 0x54 : reserved
// 0x58 : Data signal of pool_group
//        bit 15~0 - pool_group[15:0] (Read/Write)
//        others   - reserved
// 0x5c : reserved
// 0x60 : Data signal of pool_y_bound
//        bit 15~0 - pool_y_bound[15:0] (Read/Write)
//        others   - reserved
// 0x64 : reserved
// 0x68 : Data signal of item_loop_bound
//        bit 15~0 - item_loop_bound[15:0] (Read/Write)
//        others   - reserved
// 0x6c : reserved
// 0x70 : Data signal of load_data_bound
//        bit 15~0 - load_data_bound[15:0] (Read/Write)
//        others   - reserved
// 0x74 : reserved
// 0x78 : Data signal of write_back_bound
//        bit 15~0 - write_back_bound[15:0] (Read/Write)
//        others   - reserved
// 0x7c : reserved
// 0x80 : Data signal of pool_win_num_x
//        bit 7~0 - pool_win_num_x[7:0] (Read/Write)
//        others  - reserved
// 0x84 : reserved
// 0x88 : Data signal of win_size_x
//        bit 7~0 - win_size_x[7:0] (Read/Write)
//        others  - reserved
// 0x8c : reserved
// 0x90 : Data signal of bottom
//        bit 31~0 - bottom[31:0] (Read/Write)
// 0x94 : Data signal of bottom
//        bit 31~0 - bottom[63:32] (Read/Write)
// 0x98 : reserved
// 0x9c : Data signal of top
//        bit 31~0 - top[31:0] (Read/Write)
// 0xa0 : Data signal of top
//        bit 31~0 - top[63:32] (Read/Write)
// 0xa4 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XMAXPOOL_CONTROL_ADDR_AP_CTRL               0x00
#define XMAXPOOL_CONTROL_ADDR_GIE                   0x04
#define XMAXPOOL_CONTROL_ADDR_IER                   0x08
#define XMAXPOOL_CONTROL_ADDR_ISR                   0x0c
#define XMAXPOOL_CONTROL_ADDR_CONV_X_DATA           0x10
#define XMAXPOOL_CONTROL_BITS_CONV_X_DATA           8
#define XMAXPOOL_CONTROL_ADDR_CONV_XY_DATA          0x18
#define XMAXPOOL_CONTROL_BITS_CONV_XY_DATA          16
#define XMAXPOOL_CONTROL_ADDR_POOL_DIM1_DATA        0x20
#define XMAXPOOL_CONTROL_BITS_POOL_DIM1_DATA        8
#define XMAXPOOL_CONTROL_ADDR_POOL_DIM3_DATA        0x28
#define XMAXPOOL_CONTROL_BITS_POOL_DIM3_DATA        16
#define XMAXPOOL_CONTROL_ADDR_POOL_DIM1X2_DATA      0x30
#define XMAXPOOL_CONTROL_BITS_POOL_DIM1X2_DATA      16
#define XMAXPOOL_CONTROL_ADDR_POOL_SIZE_DATA        0x38
#define XMAXPOOL_CONTROL_BITS_POOL_SIZE_DATA        8
#define XMAXPOOL_CONTROL_ADDR_POOL_STRIDE_DATA      0x40
#define XMAXPOOL_CONTROL_BITS_POOL_STRIDE_DATA      8
#define XMAXPOOL_CONTROL_ADDR_PADD_OFFSET_DATA      0x48
#define XMAXPOOL_CONTROL_BITS_PADD_OFFSET_DATA      8
#define XMAXPOOL_CONTROL_ADDR_POOL_TIMES_DATA       0x50
#define XMAXPOOL_CONTROL_BITS_POOL_TIMES_DATA       16
#define XMAXPOOL_CONTROL_ADDR_POOL_GROUP_DATA       0x58
#define XMAXPOOL_CONTROL_BITS_POOL_GROUP_DATA       16
#define XMAXPOOL_CONTROL_ADDR_POOL_Y_BOUND_DATA     0x60
#define XMAXPOOL_CONTROL_BITS_POOL_Y_BOUND_DATA     16
#define XMAXPOOL_CONTROL_ADDR_ITEM_LOOP_BOUND_DATA  0x68
#define XMAXPOOL_CONTROL_BITS_ITEM_LOOP_BOUND_DATA  16
#define XMAXPOOL_CONTROL_ADDR_LOAD_DATA_BOUND_DATA  0x70
#define XMAXPOOL_CONTROL_BITS_LOAD_DATA_BOUND_DATA  16
#define XMAXPOOL_CONTROL_ADDR_WRITE_BACK_BOUND_DATA 0x78
#define XMAXPOOL_CONTROL_BITS_WRITE_BACK_BOUND_DATA 16
#define XMAXPOOL_CONTROL_ADDR_POOL_WIN_NUM_X_DATA   0x80
#define XMAXPOOL_CONTROL_BITS_POOL_WIN_NUM_X_DATA   8
#define XMAXPOOL_CONTROL_ADDR_WIN_SIZE_X_DATA       0x88
#define XMAXPOOL_CONTROL_BITS_WIN_SIZE_X_DATA       8
#define XMAXPOOL_CONTROL_ADDR_BOTTOM_DATA           0x90
#define XMAXPOOL_CONTROL_BITS_BOTTOM_DATA           64
#define XMAXPOOL_CONTROL_ADDR_TOP_DATA              0x9c
#define XMAXPOOL_CONTROL_BITS_TOP_DATA              64

