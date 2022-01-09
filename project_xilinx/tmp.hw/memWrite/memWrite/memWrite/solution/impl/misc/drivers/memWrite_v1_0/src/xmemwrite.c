// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmemwrite.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMemwrite_CfgInitialize(XMemwrite *InstancePtr, XMemwrite_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMemwrite_Start(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMemwrite_IsDone(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMemwrite_IsIdle(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMemwrite_IsReady(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMemwrite_Continue(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_AP_CTRL, Data | 0x10);
}

void XMemwrite_EnableAutoRestart(XMemwrite *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMemwrite_DisableAutoRestart(XMemwrite *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_AP_CTRL, 0);
}

void XMemwrite_Set_out_dim1(XMemwrite *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_OUT_DIM1_DATA, Data);
}

u32 XMemwrite_Get_out_dim1(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_OUT_DIM1_DATA);
    return Data;
}

void XMemwrite_Set_out_dim2(XMemwrite *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_OUT_DIM2_DATA, Data);
}

u32 XMemwrite_Get_out_dim2(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_OUT_DIM2_DATA);
    return Data;
}

void XMemwrite_Set_out_dim3(XMemwrite *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_OUT_DIM3_DATA, Data);
}

u32 XMemwrite_Get_out_dim3(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_OUT_DIM3_DATA);
    return Data;
}

void XMemwrite_Set_out_dim1xbatch(XMemwrite *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_OUT_DIM1XBATCH_DATA, Data);
}

u32 XMemwrite_Get_out_dim1xbatch(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_OUT_DIM1XBATCH_DATA);
    return Data;
}

void XMemwrite_Set_out_dim1x2xbatch(XMemwrite *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_OUT_DIM1X2XBATCH_DATA, Data);
}

u32 XMemwrite_Get_out_dim1x2xbatch(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_OUT_DIM1X2XBATCH_DATA);
    return Data;
}

void XMemwrite_Set_batch_indx_dim1(XMemwrite *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_BATCH_INDX_DIM1_DATA, Data);
}

u32 XMemwrite_Get_batch_indx_dim1(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_BATCH_INDX_DIM1_DATA);
    return Data;
}

void XMemwrite_Set_batch_indx_dim2(XMemwrite *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_BATCH_INDX_DIM2_DATA, Data);
}

u32 XMemwrite_Get_batch_indx_dim2(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_BATCH_INDX_DIM2_DATA);
    return Data;
}

void XMemwrite_Set_padd_offset(XMemwrite *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_PADD_OFFSET_DATA, Data);
}

u32 XMemwrite_Get_padd_offset(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_PADD_OFFSET_DATA);
    return Data;
}

void XMemwrite_Set_pool_on(XMemwrite *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_POOL_ON_DATA, Data);
}

u32 XMemwrite_Get_pool_on(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_POOL_ON_DATA);
    return Data;
}

void XMemwrite_Set_pool_size(XMemwrite *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_POOL_SIZE_DATA, Data);
}

u32 XMemwrite_Get_pool_size(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_POOL_SIZE_DATA);
    return Data;
}

void XMemwrite_Set_pool_stride(XMemwrite *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_POOL_STRIDE_DATA, Data);
}

u32 XMemwrite_Get_pool_stride(XMemwrite *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_POOL_STRIDE_DATA);
    return Data;
}

void XMemwrite_Set_top(XMemwrite *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_TOP_DATA, (u32)(Data));
    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_TOP_DATA + 4, (u32)(Data >> 32));
}

u64 XMemwrite_Get_top(XMemwrite *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_TOP_DATA);
    Data += (u64)XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_TOP_DATA + 4) << 32;
    return Data;
}

void XMemwrite_InterruptGlobalEnable(XMemwrite *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_GIE, 1);
}

void XMemwrite_InterruptGlobalDisable(XMemwrite *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_GIE, 0);
}

void XMemwrite_InterruptEnable(XMemwrite *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_IER);
    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_IER, Register | Mask);
}

void XMemwrite_InterruptDisable(XMemwrite *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_IER);
    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMemwrite_InterruptClear(XMemwrite *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemwrite_WriteReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_ISR, Mask);
}

u32 XMemwrite_InterruptGetEnabled(XMemwrite *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_IER);
}

u32 XMemwrite_InterruptGetStatus(XMemwrite *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMemwrite_ReadReg(InstancePtr->Control_BaseAddress, XMEMWRITE_CONTROL_ADDR_ISR);
}

