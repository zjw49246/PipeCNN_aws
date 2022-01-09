// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmemread.h"

extern XMemread_Config XMemread_ConfigTable[];

XMemread_Config *XMemread_LookupConfig(u16 DeviceId) {
	XMemread_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMEMREAD_NUM_INSTANCES; Index++) {
		if (XMemread_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMemread_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMemread_Initialize(XMemread *InstancePtr, u16 DeviceId) {
	XMemread_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMemread_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMemread_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

