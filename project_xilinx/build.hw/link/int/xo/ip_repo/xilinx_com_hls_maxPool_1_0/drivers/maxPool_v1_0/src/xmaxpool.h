// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMAXPOOL_H
#define XMAXPOOL_H

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
#include "xmaxpool_hw.h"

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
} XMaxpool_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XMaxpool;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMaxpool_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMaxpool_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMaxpool_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMaxpool_ReadReg(BaseAddress, RegOffset) \
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
int XMaxpool_Initialize(XMaxpool *InstancePtr, u16 DeviceId);
XMaxpool_Config* XMaxpool_LookupConfig(u16 DeviceId);
int XMaxpool_CfgInitialize(XMaxpool *InstancePtr, XMaxpool_Config *ConfigPtr);
#else
int XMaxpool_Initialize(XMaxpool *InstancePtr, const char* InstanceName);
int XMaxpool_Release(XMaxpool *InstancePtr);
#endif

void XMaxpool_Start(XMaxpool *InstancePtr);
u32 XMaxpool_IsDone(XMaxpool *InstancePtr);
u32 XMaxpool_IsIdle(XMaxpool *InstancePtr);
u32 XMaxpool_IsReady(XMaxpool *InstancePtr);
void XMaxpool_Continue(XMaxpool *InstancePtr);
void XMaxpool_EnableAutoRestart(XMaxpool *InstancePtr);
void XMaxpool_DisableAutoRestart(XMaxpool *InstancePtr);

void XMaxpool_Set_conv_x(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_conv_x(XMaxpool *InstancePtr);
void XMaxpool_Set_conv_xy(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_conv_xy(XMaxpool *InstancePtr);
void XMaxpool_Set_pool_dim1(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_pool_dim1(XMaxpool *InstancePtr);
void XMaxpool_Set_pool_dim3(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_pool_dim3(XMaxpool *InstancePtr);
void XMaxpool_Set_pool_dim1x2(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_pool_dim1x2(XMaxpool *InstancePtr);
void XMaxpool_Set_pool_size(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_pool_size(XMaxpool *InstancePtr);
void XMaxpool_Set_pool_stride(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_pool_stride(XMaxpool *InstancePtr);
void XMaxpool_Set_padd_offset(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_padd_offset(XMaxpool *InstancePtr);
void XMaxpool_Set_pool_times(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_pool_times(XMaxpool *InstancePtr);
void XMaxpool_Set_pool_group(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_pool_group(XMaxpool *InstancePtr);
void XMaxpool_Set_pool_y_bound(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_pool_y_bound(XMaxpool *InstancePtr);
void XMaxpool_Set_item_loop_bound(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_item_loop_bound(XMaxpool *InstancePtr);
void XMaxpool_Set_load_data_bound(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_load_data_bound(XMaxpool *InstancePtr);
void XMaxpool_Set_write_back_bound(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_write_back_bound(XMaxpool *InstancePtr);
void XMaxpool_Set_pool_win_num_x(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_pool_win_num_x(XMaxpool *InstancePtr);
void XMaxpool_Set_win_size_x(XMaxpool *InstancePtr, u32 Data);
u32 XMaxpool_Get_win_size_x(XMaxpool *InstancePtr);
void XMaxpool_Set_bottom(XMaxpool *InstancePtr, u64 Data);
u64 XMaxpool_Get_bottom(XMaxpool *InstancePtr);
void XMaxpool_Set_top(XMaxpool *InstancePtr, u64 Data);
u64 XMaxpool_Get_top(XMaxpool *InstancePtr);

void XMaxpool_InterruptGlobalEnable(XMaxpool *InstancePtr);
void XMaxpool_InterruptGlobalDisable(XMaxpool *InstancePtr);
void XMaxpool_InterruptEnable(XMaxpool *InstancePtr, u32 Mask);
void XMaxpool_InterruptDisable(XMaxpool *InstancePtr, u32 Mask);
void XMaxpool_InterruptClear(XMaxpool *InstancePtr, u32 Mask);
u32 XMaxpool_InterruptGetEnabled(XMaxpool *InstancePtr);
u32 XMaxpool_InterruptGetStatus(XMaxpool *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
