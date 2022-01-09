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
// 0x10 : Data signal of output_num
//        bit 31~0 - output_num[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of conv_loop_cnt
//        bit 31~0 - conv_loop_cnt[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of contol
//        bit 31~0 - contol[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of frac_w
//        bit 7~0 - frac_w[7:0] (Read/Write)
//        others  - reserved
// 0x2c : reserved
// 0x30 : Data signal of frac_din
//        bit 7~0 - frac_din[7:0] (Read/Write)
//        others  - reserved
// 0x34 : reserved
// 0x38 : Data signal of frac_dout
//        bit 7~0 - frac_dout[7:0] (Read/Write)
//        others  - reserved
// 0x3c : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XCORECONV_CONTROL_ADDR_AP_CTRL            0x00
#define XCORECONV_CONTROL_ADDR_GIE                0x04
#define XCORECONV_CONTROL_ADDR_IER                0x08
#define XCORECONV_CONTROL_ADDR_ISR                0x0c
#define XCORECONV_CONTROL_ADDR_OUTPUT_NUM_DATA    0x10
#define XCORECONV_CONTROL_BITS_OUTPUT_NUM_DATA    32
#define XCORECONV_CONTROL_ADDR_CONV_LOOP_CNT_DATA 0x18
#define XCORECONV_CONTROL_BITS_CONV_LOOP_CNT_DATA 32
#define XCORECONV_CONTROL_ADDR_CONTOL_DATA        0x20
#define XCORECONV_CONTROL_BITS_CONTOL_DATA        32
#define XCORECONV_CONTROL_ADDR_FRAC_W_DATA        0x28
#define XCORECONV_CONTROL_BITS_FRAC_W_DATA        8
#define XCORECONV_CONTROL_ADDR_FRAC_DIN_DATA      0x30
#define XCORECONV_CONTROL_BITS_FRAC_DIN_DATA      8
#define XCORECONV_CONTROL_ADDR_FRAC_DOUT_DATA     0x38
#define XCORECONV_CONTROL_BITS_FRAC_DOUT_DATA     8

