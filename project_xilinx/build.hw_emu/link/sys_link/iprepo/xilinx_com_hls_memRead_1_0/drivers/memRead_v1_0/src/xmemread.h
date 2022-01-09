// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMEMREAD_H
#define XMEMREAD_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xmemread_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XMemread_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XMemread;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMemread_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMemread_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMemread_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMemread_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XMemread_Initialize(XMemread *InstancePtr, u16 DeviceId);
XMemread_Config* XMemread_LookupConfig(u16 DeviceId);
int XMemread_CfgInitialize(XMemread *InstancePtr, XMemread_Config *ConfigPtr);
#else
int XMemread_Initialize(XMemread *InstancePtr, const char* InstanceName);
int XMemread_Release(XMemread *InstancePtr);
#endif

void XMemread_Start(XMemread *InstancePtr);
u32 XMemread_IsDone(XMemread *InstancePtr);
u32 XMemread_IsIdle(XMemread *InstancePtr);
u32 XMemread_IsReady(XMemread *InstancePtr);
void XMemread_Continue(XMemread *InstancePtr);
void XMemread_EnableAutoRestart(XMemread *InstancePtr);
void XMemread_DisableAutoRestart(XMemread *InstancePtr);

void XMemread_Set_data_dim1(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_data_dim1(XMemread *InstancePtr);
void XMemread_Set_data_dim2(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_data_dim2(XMemread *InstancePtr);
void XMemread_Set_data_dim1xdim2(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_data_dim1xdim2(XMemread *InstancePtr);
void XMemread_Set_weight_dim1(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_weight_dim1(XMemread *InstancePtr);
void XMemread_Set_weight_dim2(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_weight_dim2(XMemread *InstancePtr);
void XMemread_Set_weight_dim3(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_weight_dim3(XMemread *InstancePtr);
void XMemread_Set_weight_dim4_div_lane(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_weight_dim4_div_lane(XMemread *InstancePtr);
void XMemread_Set_weight_dim1x2(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_weight_dim1x2(XMemread *InstancePtr);
void XMemread_Set_weight_dim1x2x3(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_weight_dim1x2x3(XMemread *InstancePtr);
void XMemread_Set_conv_x(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_conv_x(XMemread *InstancePtr);
void XMemread_Set_stride(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_stride(XMemread *InstancePtr);
void XMemread_Set_padding(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_padding(XMemread *InstancePtr);
void XMemread_Set_split(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_split(XMemread *InstancePtr);
void XMemread_Set_group_num_x(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_group_num_x(XMemread *InstancePtr);
void XMemread_Set_group_num_y(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_group_num_y(XMemread *InstancePtr);
void XMemread_Set_group_rem_size_x(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_group_rem_size_x(XMemread *InstancePtr);
void XMemread_Set_group_rem_size_xyz(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_group_rem_size_xyz(XMemread *InstancePtr);
void XMemread_Set_win_size_x(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_win_size_x(XMemread *InstancePtr);
void XMemread_Set_win_size_y(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_win_size_y(XMemread *InstancePtr);
void XMemread_Set_win_size_xyz(XMemread *InstancePtr, u32 Data);
u32 XMemread_Get_win_size_xyz(XMemread *InstancePtr);
void XMemread_Set_bottom(XMemread *InstancePtr, u64 Data);
u64 XMemread_Get_bottom(XMemread *InstancePtr);
void XMemread_Set_weights(XMemread *InstancePtr, u64 Data);
u64 XMemread_Get_weights(XMemread *InstancePtr);
void XMemread_Set_bias(XMemread *InstancePtr, u64 Data);
u64 XMemread_Get_bias(XMemread *InstancePtr);

void XMemread_InterruptGlobalEnable(XMemread *InstancePtr);
void XMemread_InterruptGlobalDisable(XMemread *InstancePtr);
void XMemread_InterruptEnable(XMemread *InstancePtr, u32 Mask);
void XMemread_InterruptDisable(XMemread *InstancePtr, u32 Mask);
void XMemread_InterruptClear(XMemread *InstancePtr, u32 Mask);
u32 XMemread_InterruptGetEnabled(XMemread *InstancePtr);
u32 XMemread_InterruptGetStatus(XMemread *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
