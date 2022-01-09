// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xcoreconv.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XCoreconv_CfgInitialize(XCoreconv *InstancePtr, XCoreconv_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XCoreconv_Start(XCoreconv *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_AP_CTRL) & 0x80;
    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XCoreconv_IsDone(XCoreconv *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XCoreconv_IsIdle(XCoreconv *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XCoreconv_IsReady(XCoreconv *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XCoreconv_Continue(XCoreconv *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_AP_CTRL) & 0x80;
    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_AP_CTRL, Data | 0x10);
}

void XCoreconv_EnableAutoRestart(XCoreconv *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XCoreconv_DisableAutoRestart(XCoreconv *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_AP_CTRL, 0);
}

void XCoreconv_Set_output_num(XCoreconv *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_OUTPUT_NUM_DATA, Data);
}

u32 XCoreconv_Get_output_num(XCoreconv *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_OUTPUT_NUM_DATA);
    return Data;
}

void XCoreconv_Set_conv_loop_cnt(XCoreconv *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_CONV_LOOP_CNT_DATA, Data);
}

u32 XCoreconv_Get_conv_loop_cnt(XCoreconv *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_CONV_LOOP_CNT_DATA);
    return Data;
}

void XCoreconv_Set_contol(XCoreconv *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_CONTOL_DATA, Data);
}

u32 XCoreconv_Get_contol(XCoreconv *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_CONTOL_DATA);
    return Data;
}

void XCoreconv_Set_frac_w(XCoreconv *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_FRAC_W_DATA, Data);
}

u32 XCoreconv_Get_frac_w(XCoreconv *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_FRAC_W_DATA);
    return Data;
}

void XCoreconv_Set_frac_din(XCoreconv *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_FRAC_DIN_DATA, Data);
}

u32 XCoreconv_Get_frac_din(XCoreconv *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_FRAC_DIN_DATA);
    return Data;
}

void XCoreconv_Set_frac_dout(XCoreconv *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_FRAC_DOUT_DATA, Data);
}

u32 XCoreconv_Get_frac_dout(XCoreconv *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_FRAC_DOUT_DATA);
    return Data;
}

void XCoreconv_InterruptGlobalEnable(XCoreconv *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_GIE, 1);
}

void XCoreconv_InterruptGlobalDisable(XCoreconv *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_GIE, 0);
}

void XCoreconv_InterruptEnable(XCoreconv *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_IER);
    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_IER, Register | Mask);
}

void XCoreconv_InterruptDisable(XCoreconv *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_IER);
    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_IER, Register & (~Mask));
}

void XCoreconv_InterruptClear(XCoreconv *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCoreconv_WriteReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_ISR, Mask);
}

u32 XCoreconv_InterruptGetEnabled(XCoreconv *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_IER);
}

u32 XCoreconv_InterruptGetStatus(XCoreconv *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCoreconv_ReadReg(InstancePtr->Control_BaseAddress, XCORECONV_CONTROL_ADDR_ISR);
}

