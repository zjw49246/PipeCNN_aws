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
// 0x10 : Data signal of data_dim1
//        bit 7~0 - data_dim1[7:0] (Read/Write)
//        others  - reserved
// 0x14 : reserved
// 0x18 : Data signal of data_dim2
//        bit 7~0 - data_dim2[7:0] (Read/Write)
//        others  - reserved
// 0x1c : reserved
// 0x20 : Data signal of data_dim1xdim2
//        bit 15~0 - data_dim1xdim2[15:0] (Read/Write)
//        others   - reserved
// 0x24 : reserved
// 0x28 : Data signal of weight_dim1
//        bit 7~0 - weight_dim1[7:0] (Read/Write)
//        others  - reserved
// 0x2c : reserved
// 0x30 : Data signal of weight_dim2
//        bit 7~0 - weight_dim2[7:0] (Read/Write)
//        others  - reserved
// 0x34 : reserved
// 0x38 : Data signal of weight_dim3
//        bit 15~0 - weight_dim3[15:0] (Read/Write)
//        others   - reserved
// 0x3c : reserved
// 0x40 : Data signal of weight_dim4_div_lane
//        bit 15~0 - weight_dim4_div_lane[15:0] (Read/Write)
//        others   - reserved
// 0x44 : reserved
// 0x48 : Data signal of weight_dim1x2
//        bit 7~0 - weight_dim1x2[7:0] (Read/Write)
//        others  - reserved
// 0x4c : reserved
// 0x50 : Data signal of weight_dim1x2x3
//        bit 31~0 - weight_dim1x2x3[31:0] (Read/Write)
// 0x54 : reserved
// 0x58 : Data signal of conv_x
//        bit 7~0 - conv_x[7:0] (Read/Write)
//        others  - reserved
// 0x5c : reserved
// 0x60 : Data signal of stride
//        bit 7~0 - stride[7:0] (Read/Write)
//        others  - reserved
// 0x64 : reserved
// 0x68 : Data signal of padding
//        bit 7~0 - padding[7:0] (Read/Write)
//        others  - reserved
// 0x6c : reserved
// 0x70 : Data signal of split
//        bit 7~0 - split[7:0] (Read/Write)
//        others  - reserved
// 0x74 : reserved
// 0x78 : Data signal of group_num_x
//        bit 7~0 - group_num_x[7:0] (Read/Write)
//        others  - reserved
// 0x7c : reserved
// 0x80 : Data signal of group_num_y
//        bit 7~0 - group_num_y[7:0] (Read/Write)
//        others  - reserved
// 0x84 : reserved
// 0x88 : Data signal of group_rem_size_x
//        bit 7~0 - group_rem_size_x[7:0] (Read/Write)
//        others  - reserved
// 0x8c : reserved
// 0x90 : Data signal of group_rem_size_xyz
//        bit 31~0 - group_rem_size_xyz[31:0] (Read/Write)
// 0x94 : reserved
// 0x98 : Data signal of win_size_x
//        bit 7~0 - win_size_x[7:0] (Read/Write)
//        others  - reserved
// 0x9c : reserved
// 0xa0 : Data signal of win_size_y
//        bit 7~0 - win_size_y[7:0] (Read/Write)
//        others  - reserved
// 0xa4 : reserved
// 0xa8 : Data signal of win_size_xyz
//        bit 31~0 - win_size_xyz[31:0] (Read/Write)
// 0xac : reserved
// 0xb0 : Data signal of bottom
//        bit 31~0 - bottom[31:0] (Read/Write)
// 0xb4 : Data signal of bottom
//        bit 31~0 - bottom[63:32] (Read/Write)
// 0xb8 : reserved
// 0xbc : Data signal of weights
//        bit 31~0 - weights[31:0] (Read/Write)
// 0xc0 : Data signal of weights
//        bit 31~0 - weights[63:32] (Read/Write)
// 0xc4 : reserved
// 0xc8 : Data signal of bias
//        bit 31~0 - bias[31:0] (Read/Write)
// 0xcc : Data signal of bias
//        bit 31~0 - bias[63:32] (Read/Write)
// 0xd0 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XMEMREAD_CONTROL_ADDR_AP_CTRL                   0x00
#define XMEMREAD_CONTROL_ADDR_GIE                       0x04
#define XMEMREAD_CONTROL_ADDR_IER                       0x08
#define XMEMREAD_CONTROL_ADDR_ISR                       0x0c
#define XMEMREAD_CONTROL_ADDR_DATA_DIM1_DATA            0x10
#define XMEMREAD_CONTROL_BITS_DATA_DIM1_DATA            8
#define XMEMREAD_CONTROL_ADDR_DATA_DIM2_DATA            0x18
#define XMEMREAD_CONTROL_BITS_DATA_DIM2_DATA            8
#define XMEMREAD_CONTROL_ADDR_DATA_DIM1XDIM2_DATA       0x20
#define XMEMREAD_CONTROL_BITS_DATA_DIM1XDIM2_DATA       16
#define XMEMREAD_CONTROL_ADDR_WEIGHT_DIM1_DATA          0x28
#define XMEMREAD_CONTROL_BITS_WEIGHT_DIM1_DATA          8
#define XMEMREAD_CONTROL_ADDR_WEIGHT_DIM2_DATA          0x30
#define XMEMREAD_CONTROL_BITS_WEIGHT_DIM2_DATA          8
#define XMEMREAD_CONTROL_ADDR_WEIGHT_DIM3_DATA          0x38
#define XMEMREAD_CONTROL_BITS_WEIGHT_DIM3_DATA          16
#define XMEMREAD_CONTROL_ADDR_WEIGHT_DIM4_DIV_LANE_DATA 0x40
#define XMEMREAD_CONTROL_BITS_WEIGHT_DIM4_DIV_LANE_DATA 16
#define XMEMREAD_CONTROL_ADDR_WEIGHT_DIM1X2_DATA        0x48
#define XMEMREAD_CONTROL_BITS_WEIGHT_DIM1X2_DATA        8
#define XMEMREAD_CONTROL_ADDR_WEIGHT_DIM1X2X3_DATA      0x50
#define XMEMREAD_CONTROL_BITS_WEIGHT_DIM1X2X3_DATA      32
#define XMEMREAD_CONTROL_ADDR_CONV_X_DATA               0x58
#define XMEMREAD_CONTROL_BITS_CONV_X_DATA               8
#define XMEMREAD_CONTROL_ADDR_STRIDE_DATA               0x60
#define XMEMREAD_CONTROL_BITS_STRIDE_DATA               8
#define XMEMREAD_CONTROL_ADDR_PADDING_DATA              0x68
#define XMEMREAD_CONTROL_BITS_PADDING_DATA              8
#define XMEMREAD_CONTROL_ADDR_SPLIT_DATA                0x70
#define XMEMREAD_CONTROL_BITS_SPLIT_DATA                8
#define XMEMREAD_CONTROL_ADDR_GROUP_NUM_X_DATA          0x78
#define XMEMREAD_CONTROL_BITS_GROUP_NUM_X_DATA          8
#define XMEMREAD_CONTROL_ADDR_GROUP_NUM_Y_DATA          0x80
#define XMEMREAD_CONTROL_BITS_GROUP_NUM_Y_DATA          8
#define XMEMREAD_CONTROL_ADDR_GROUP_REM_SIZE_X_DATA     0x88
#define XMEMREAD_CONTROL_BITS_GROUP_REM_SIZE_X_DATA     8
#define XMEMREAD_CONTROL_ADDR_GROUP_REM_SIZE_XYZ_DATA   0x90
#define XMEMREAD_CONTROL_BITS_GROUP_REM_SIZE_XYZ_DATA   32
#define XMEMREAD_CONTROL_ADDR_WIN_SIZE_X_DATA           0x98
#define XMEMREAD_CONTROL_BITS_WIN_SIZE_X_DATA           8
#define XMEMREAD_CONTROL_ADDR_WIN_SIZE_Y_DATA           0xa0
#define XMEMREAD_CONTROL_BITS_WIN_SIZE_Y_DATA           8
#define XMEMREAD_CONTROL_ADDR_WIN_SIZE_XYZ_DATA         0xa8
#define XMEMREAD_CONTROL_BITS_WIN_SIZE_XYZ_DATA         32
#define XMEMREAD_CONTROL_ADDR_BOTTOM_DATA               0xb0
#define XMEMREAD_CONTROL_BITS_BOTTOM_DATA               64
#define XMEMREAD_CONTROL_ADDR_WEIGHTS_DATA              0xbc
#define XMEMREAD_CONTROL_BITS_WEIGHTS_DATA              64
#define XMEMREAD_CONTROL_ADDR_BIAS_DATA                 0xc8
#define XMEMREAD_CONTROL_BITS_BIAS_DATA                 64

