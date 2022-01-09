// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMEMWRITE_H
#define XMEMWRITE_H

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
#include "xmemwrite_hw.h"

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
} XMemwrite_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XMemwrite;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMemwrite_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMemwrite_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMemwrite_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMemwrite_ReadReg(BaseAddress, RegOffset) \
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
int XMemwrite_Initialize(XMemwrite *InstancePtr, u16 DeviceId);
XMemwrite_Config* XMemwrite_LookupConfig(u16 DeviceId);
int XMemwrite_CfgInitialize(XMemwrite *InstancePtr, XMemwrite_Config *ConfigPtr);
#else
int XMemwrite_Initialize(XMemwrite *InstancePtr, const char* InstanceName);
int XMemwrite_Release(XMemwrite *InstancePtr);
#endif

void XMemwrite_Start(XMemwrite *InstancePtr);
u32 XMemwrite_IsDone(XMemwrite *InstancePtr);
u32 XMemwrite_IsIdle(XMemwrite *InstancePtr);
u32 XMemwrite_IsReady(XMemwrite *InstancePtr);
void XMemwrite_Continue(XMemwrite *InstancePtr);
void XMemwrite_EnableAutoRestart(XMemwrite *InstancePtr);
void XMemwrite_DisableAutoRestart(XMemwrite *InstancePtr);

void XMemwrite_Set_out_dim1(XMemwrite *InstancePtr, u32 Data);
u32 XMemwrite_Get_out_dim1(XMemwrite *InstancePtr);
void XMemwrite_Set_out_dim2(XMemwrite *InstancePtr, u32 Data);
u32 XMemwrite_Get_out_dim2(XMemwrite *InstancePtr);
void XMemwrite_Set_out_dim3(XMemwrite *InstancePtr, u32 Data);
u32 XMemwrite_Get_out_dim3(XMemwrite *InstancePtr);
void XMemwrite_Set_out_dim1xbatch(XMemwrite *InstancePtr, u32 Data);
u32 XMemwrite_Get_out_dim1xbatch(XMemwrite *InstancePtr);
void XMemwrite_Set_out_dim1x2xbatch(XMemwrite *InstancePtr, u32 Data);
u32 XMemwrite_Get_out_dim1x2xbatch(XMemwrite *InstancePtr);
void XMemwrite_Set_batch_indx_dim1(XMemwrite *InstancePtr, u32 Data);
u32 XMemwrite_Get_batch_indx_dim1(XMemwrite *InstancePtr);
void XMemwrite_Set_batch_indx_dim2(XMemwrite *InstancePtr, u32 Data);
u32 XMemwrite_Get_batch_indx_dim2(XMemwrite *InstancePtr);
void XMemwrite_Set_padd_offset(XMemwrite *InstancePtr, u32 Data);
u32 XMemwrite_Get_padd_offset(XMemwrite *InstancePtr);
void XMemwrite_Set_pool_on(XMemwrite *InstancePtr, u32 Data);
u32 XMemwrite_Get_pool_on(XMemwrite *InstancePtr);
void XMemwrite_Set_pool_size(XMemwrite *InstancePtr, u32 Data);
u32 XMemwrite_Get_pool_size(XMemwrite *InstancePtr);
void XMemwrite_Set_pool_stride(XMemwrite *InstancePtr, u32 Data);
u32 XMemwrite_Get_pool_stride(XMemwrite *InstancePtr);
void XMemwrite_Set_top(XMemwrite *InstancePtr, u64 Data);
u64 XMemwrite_Get_top(XMemwrite *InstancePtr);

void XMemwrite_InterruptGlobalEnable(XMemwrite *InstancePtr);
void XMemwrite_InterruptGlobalDisable(XMemwrite *InstancePtr);
void XMemwrite_InterruptEnable(XMemwrite *InstancePtr, u32 Mask);
void XMemwrite_InterruptDisable(XMemwrite *InstancePtr, u32 Mask);
void XMemwrite_InterruptClear(XMemwrite *InstancePtr, u32 Mask);
u32 XMemwrite_InterruptGetEnabled(XMemwrite *InstancePtr);
u32 XMemwrite_InterruptGetStatus(XMemwrite *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
