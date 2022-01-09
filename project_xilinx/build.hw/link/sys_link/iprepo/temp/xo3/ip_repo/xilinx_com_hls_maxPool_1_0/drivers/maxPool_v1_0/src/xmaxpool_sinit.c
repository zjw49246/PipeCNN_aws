// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmaxpool.h"

extern XMaxpool_Config XMaxpool_ConfigTable[];

XMaxpool_Config *XMaxpool_LookupConfig(u16 DeviceId) {
	XMaxpool_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMAXPOOL_NUM_INSTANCES; Index++) {
		if (XMaxpool_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMaxpool_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMaxpool_Initialize(XMaxpool *InstancePtr, u16 DeviceId) {
	XMaxpool_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMaxpool_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMaxpool_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

