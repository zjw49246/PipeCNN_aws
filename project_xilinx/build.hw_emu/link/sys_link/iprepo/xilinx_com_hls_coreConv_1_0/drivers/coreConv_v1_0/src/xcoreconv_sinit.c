// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xcoreconv.h"

extern XCoreconv_Config XCoreconv_ConfigTable[];

XCoreconv_Config *XCoreconv_LookupConfig(u16 DeviceId) {
	XCoreconv_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XCORECONV_NUM_INSTANCES; Index++) {
		if (XCoreconv_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XCoreconv_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XCoreconv_Initialize(XCoreconv *InstancePtr, u16 DeviceId) {
	XCoreconv_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XCoreconv_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XCoreconv_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

