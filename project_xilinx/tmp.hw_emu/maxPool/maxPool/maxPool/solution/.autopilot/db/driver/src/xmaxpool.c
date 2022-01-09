// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmaxpool.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMaxpool_CfgInitialize(XMaxpool *InstancePtr, XMaxpool_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMaxpool_Start(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMaxpool_IsDone(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMaxpool_IsIdle(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMaxpool_IsReady(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMaxpool_Continue(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_AP_CTRL, Data | 0x10);
}

void XMaxpool_EnableAutoRestart(XMaxpool *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMaxpool_DisableAutoRestart(XMaxpool *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_AP_CTRL, 0);
}

void XMaxpool_Set_conv_x(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_CONV_X_DATA, Data);
}

u32 XMaxpool_Get_conv_x(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_CONV_X_DATA);
    return Data;
}

void XMaxpool_Set_conv_xy(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_CONV_XY_DATA, Data);
}

u32 XMaxpool_Get_conv_xy(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_CONV_XY_DATA);
    return Data;
}

void XMaxpool_Set_pool_dim1(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_DIM1_DATA, Data);
}

u32 XMaxpool_Get_pool_dim1(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_DIM1_DATA);
    return Data;
}

void XMaxpool_Set_pool_dim3(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_DIM3_DATA, Data);
}

u32 XMaxpool_Get_pool_dim3(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_DIM3_DATA);
    return Data;
}

void XMaxpool_Set_pool_dim1x2(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_DIM1X2_DATA, Data);
}

u32 XMaxpool_Get_pool_dim1x2(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_DIM1X2_DATA);
    return Data;
}

void XMaxpool_Set_pool_size(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_SIZE_DATA, Data);
}

u32 XMaxpool_Get_pool_size(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_SIZE_DATA);
    return Data;
}

void XMaxpool_Set_pool_stride(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_STRIDE_DATA, Data);
}

u32 XMaxpool_Get_pool_stride(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_STRIDE_DATA);
    return Data;
}

void XMaxpool_Set_padd_offset(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_PADD_OFFSET_DATA, Data);
}

u32 XMaxpool_Get_padd_offset(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_PADD_OFFSET_DATA);
    return Data;
}

void XMaxpool_Set_pool_times(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_TIMES_DATA, Data);
}

u32 XMaxpool_Get_pool_times(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_TIMES_DATA);
    return Data;
}

void XMaxpool_Set_pool_group(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_GROUP_DATA, Data);
}

u32 XMaxpool_Get_pool_group(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_GROUP_DATA);
    return Data;
}

void XMaxpool_Set_pool_y_bound(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_Y_BOUND_DATA, Data);
}

u32 XMaxpool_Get_pool_y_bound(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_Y_BOUND_DATA);
    return Data;
}

void XMaxpool_Set_item_loop_bound(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_ITEM_LOOP_BOUND_DATA, Data);
}

u32 XMaxpool_Get_item_loop_bound(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_ITEM_LOOP_BOUND_DATA);
    return Data;
}

void XMaxpool_Set_load_data_bound(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_LOAD_DATA_BOUND_DATA, Data);
}

u32 XMaxpool_Get_load_data_bound(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_LOAD_DATA_BOUND_DATA);
    return Data;
}

void XMaxpool_Set_write_back_bound(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_WRITE_BACK_BOUND_DATA, Data);
}

u32 XMaxpool_Get_write_back_bound(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_WRITE_BACK_BOUND_DATA);
    return Data;
}

void XMaxpool_Set_pool_win_num_x(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_WIN_NUM_X_DATA, Data);
}

u32 XMaxpool_Get_pool_win_num_x(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_POOL_WIN_NUM_X_DATA);
    return Data;
}

void XMaxpool_Set_win_size_x(XMaxpool *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_WIN_SIZE_X_DATA, Data);
}

u32 XMaxpool_Get_win_size_x(XMaxpool *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_WIN_SIZE_X_DATA);
    return Data;
}

void XMaxpool_Set_bottom(XMaxpool *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_BOTTOM_DATA, (u32)(Data));
    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_BOTTOM_DATA + 4, (u32)(Data >> 32));
}

u64 XMaxpool_Get_bottom(XMaxpool *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_BOTTOM_DATA);
    Data += (u64)XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_BOTTOM_DATA + 4) << 32;
    return Data;
}

void XMaxpool_Set_top(XMaxpool *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_TOP_DATA, (u32)(Data));
    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_TOP_DATA + 4, (u32)(Data >> 32));
}

u64 XMaxpool_Get_top(XMaxpool *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_TOP_DATA);
    Data += (u64)XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_TOP_DATA + 4) << 32;
    return Data;
}

void XMaxpool_InterruptGlobalEnable(XMaxpool *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_GIE, 1);
}

void XMaxpool_InterruptGlobalDisable(XMaxpool *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_GIE, 0);
}

void XMaxpool_InterruptEnable(XMaxpool *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_IER);
    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_IER, Register | Mask);
}

void XMaxpool_InterruptDisable(XMaxpool *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_IER);
    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMaxpool_InterruptClear(XMaxpool *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMaxpool_WriteReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_ISR, Mask);
}

u32 XMaxpool_InterruptGetEnabled(XMaxpool *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_IER);
}

u32 XMaxpool_InterruptGetStatus(XMaxpool *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMaxpool_ReadReg(InstancePtr->Control_BaseAddress, XMAXPOOL_CONTROL_ADDR_ISR);
}

