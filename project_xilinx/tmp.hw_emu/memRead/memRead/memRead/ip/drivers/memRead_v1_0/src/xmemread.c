// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmemread.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMemread_CfgInitialize(XMemread *InstancePtr, XMemread_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMemread_Start(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMemread_IsDone(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMemread_IsIdle(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMemread_IsReady(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMemread_Continue(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_AP_CTRL, Data | 0x10);
}

void XMemread_EnableAutoRestart(XMemread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMemread_DisableAutoRestart(XMemread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_AP_CTRL, 0);
}

void XMemread_Set_data_dim1(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_DATA_DIM1_DATA, Data);
}

u32 XMemread_Get_data_dim1(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_DATA_DIM1_DATA);
    return Data;
}

void XMemread_Set_data_dim2(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_DATA_DIM2_DATA, Data);
}

u32 XMemread_Get_data_dim2(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_DATA_DIM2_DATA);
    return Data;
}

void XMemread_Set_data_dim1xdim2(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_DATA_DIM1XDIM2_DATA, Data);
}

u32 XMemread_Get_data_dim1xdim2(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_DATA_DIM1XDIM2_DATA);
    return Data;
}

void XMemread_Set_weight_dim1(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM1_DATA, Data);
}

u32 XMemread_Get_weight_dim1(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM1_DATA);
    return Data;
}

void XMemread_Set_weight_dim2(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM2_DATA, Data);
}

u32 XMemread_Get_weight_dim2(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM2_DATA);
    return Data;
}

void XMemread_Set_weight_dim3(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM3_DATA, Data);
}

u32 XMemread_Get_weight_dim3(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM3_DATA);
    return Data;
}

void XMemread_Set_weight_dim4_div_lane(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM4_DIV_LANE_DATA, Data);
}

u32 XMemread_Get_weight_dim4_div_lane(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM4_DIV_LANE_DATA);
    return Data;
}

void XMemread_Set_weight_dim1x2(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM1X2_DATA, Data);
}

u32 XMemread_Get_weight_dim1x2(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM1X2_DATA);
    return Data;
}

void XMemread_Set_weight_dim1x2x3(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM1X2X3_DATA, Data);
}

u32 XMemread_Get_weight_dim1x2x3(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHT_DIM1X2X3_DATA);
    return Data;
}

void XMemread_Set_conv_x(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_CONV_X_DATA, Data);
}

u32 XMemread_Get_conv_x(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_CONV_X_DATA);
    return Data;
}

void XMemread_Set_stride(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_STRIDE_DATA, Data);
}

u32 XMemread_Get_stride(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_STRIDE_DATA);
    return Data;
}

void XMemread_Set_padding(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_PADDING_DATA, Data);
}

u32 XMemread_Get_padding(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_PADDING_DATA);
    return Data;
}

void XMemread_Set_split(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_SPLIT_DATA, Data);
}

u32 XMemread_Get_split(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_SPLIT_DATA);
    return Data;
}

void XMemread_Set_group_num_x(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_GROUP_NUM_X_DATA, Data);
}

u32 XMemread_Get_group_num_x(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_GROUP_NUM_X_DATA);
    return Data;
}

void XMemread_Set_group_num_y(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_GROUP_NUM_Y_DATA, Data);
}

u32 XMemread_Get_group_num_y(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_GROUP_NUM_Y_DATA);
    return Data;
}

void XMemread_Set_group_rem_size_x(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_GROUP_REM_SIZE_X_DATA, Data);
}

u32 XMemread_Get_group_rem_size_x(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_GROUP_REM_SIZE_X_DATA);
    return Data;
}

void XMemread_Set_group_rem_size_xyz(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_GROUP_REM_SIZE_XYZ_DATA, Data);
}

u32 XMemread_Get_group_rem_size_xyz(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_GROUP_REM_SIZE_XYZ_DATA);
    return Data;
}

void XMemread_Set_win_size_x(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WIN_SIZE_X_DATA, Data);
}

u32 XMemread_Get_win_size_x(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WIN_SIZE_X_DATA);
    return Data;
}

void XMemread_Set_win_size_y(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WIN_SIZE_Y_DATA, Data);
}

u32 XMemread_Get_win_size_y(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WIN_SIZE_Y_DATA);
    return Data;
}

void XMemread_Set_win_size_xyz(XMemread *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WIN_SIZE_XYZ_DATA, Data);
}

u32 XMemread_Get_win_size_xyz(XMemread *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WIN_SIZE_XYZ_DATA);
    return Data;
}

void XMemread_Set_bottom(XMemread *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_BOTTOM_DATA, (u32)(Data));
    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_BOTTOM_DATA + 4, (u32)(Data >> 32));
}

u64 XMemread_Get_bottom(XMemread *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_BOTTOM_DATA);
    Data += (u64)XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_BOTTOM_DATA + 4) << 32;
    return Data;
}

void XMemread_Set_weights(XMemread *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHTS_DATA, (u32)(Data));
    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHTS_DATA + 4, (u32)(Data >> 32));
}

u64 XMemread_Get_weights(XMemread *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHTS_DATA);
    Data += (u64)XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_WEIGHTS_DATA + 4) << 32;
    return Data;
}

void XMemread_Set_bias(XMemread *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_BIAS_DATA, (u32)(Data));
    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_BIAS_DATA + 4, (u32)(Data >> 32));
}

u64 XMemread_Get_bias(XMemread *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_BIAS_DATA);
    Data += (u64)XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_BIAS_DATA + 4) << 32;
    return Data;
}

void XMemread_InterruptGlobalEnable(XMemread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_GIE, 1);
}

void XMemread_InterruptGlobalDisable(XMemread *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_GIE, 0);
}

void XMemread_InterruptEnable(XMemread *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_IER);
    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_IER, Register | Mask);
}

void XMemread_InterruptDisable(XMemread *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_IER);
    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMemread_InterruptClear(XMemread *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMemread_WriteReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_ISR, Mask);
}

u32 XMemread_InterruptGetEnabled(XMemread *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_IER);
}

u32 XMemread_InterruptGetStatus(XMemread *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMemread_ReadReg(InstancePtr->Control_BaseAddress, XMEMREAD_CONTROL_ADDR_ISR);
}

