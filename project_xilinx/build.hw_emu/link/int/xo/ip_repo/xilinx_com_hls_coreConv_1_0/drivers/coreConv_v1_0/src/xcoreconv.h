// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XCORECONV_H
#define XCORECONV_H

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
#include "xcoreconv_hw.h"

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
} XCoreconv_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XCoreconv;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XCoreconv_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XCoreconv_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XCoreconv_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XCoreconv_ReadReg(BaseAddress, RegOffset) \
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
int XCoreconv_Initialize(XCoreconv *InstancePtr, u16 DeviceId);
XCoreconv_Config* XCoreconv_LookupConfig(u16 DeviceId);
int XCoreconv_CfgInitialize(XCoreconv *InstancePtr, XCoreconv_Config *ConfigPtr);
#else
int XCoreconv_Initialize(XCoreconv *InstancePtr, const char* InstanceName);
int XCoreconv_Release(XCoreconv *InstancePtr);
#endif

void XCoreconv_Start(XCoreconv *InstancePtr);
u32 XCoreconv_IsDone(XCoreconv *InstancePtr);
u32 XCoreconv_IsIdle(XCoreconv *InstancePtr);
u32 XCoreconv_IsReady(XCoreconv *InstancePtr);
void XCoreconv_Continue(XCoreconv *InstancePtr);
void XCoreconv_EnableAutoRestart(XCoreconv *InstancePtr);
void XCoreconv_DisableAutoRestart(XCoreconv *InstancePtr);

void XCoreconv_Set_output_num(XCoreconv *InstancePtr, u32 Data);
u32 XCoreconv_Get_output_num(XCoreconv *InstancePtr);
void XCoreconv_Set_conv_loop_cnt(XCoreconv *InstancePtr, u32 Data);
u32 XCoreconv_Get_conv_loop_cnt(XCoreconv *InstancePtr);
void XCoreconv_Set_contol(XCoreconv *InstancePtr, u32 Data);
u32 XCoreconv_Get_contol(XCoreconv *InstancePtr);
void XCoreconv_Set_frac_w(XCoreconv *InstancePtr, u32 Data);
u32 XCoreconv_Get_frac_w(XCoreconv *InstancePtr);
void XCoreconv_Set_frac_din(XCoreconv *InstancePtr, u32 Data);
u32 XCoreconv_Get_frac_din(XCoreconv *InstancePtr);
void XCoreconv_Set_frac_dout(XCoreconv *InstancePtr, u32 Data);
u32 XCoreconv_Get_frac_dout(XCoreconv *InstancePtr);

void XCoreconv_InterruptGlobalEnable(XCoreconv *InstancePtr);
void XCoreconv_InterruptGlobalDisable(XCoreconv *InstancePtr);
void XCoreconv_InterruptEnable(XCoreconv *InstancePtr, u32 Mask);
void XCoreconv_InterruptDisable(XCoreconv *InstancePtr, u32 Mask);
void XCoreconv_InterruptClear(XCoreconv *InstancePtr, u32 Mask);
u32 XCoreconv_InterruptGetEnabled(XCoreconv *InstancePtr);
u32 XCoreconv_InterruptGetStatus(XCoreconv *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
