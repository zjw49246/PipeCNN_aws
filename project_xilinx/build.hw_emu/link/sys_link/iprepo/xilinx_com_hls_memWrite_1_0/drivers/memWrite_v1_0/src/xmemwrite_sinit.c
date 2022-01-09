// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmemwrite.h"

extern XMemwrite_Config XMemwrite_ConfigTable[];

XMemwrite_Config *XMemwrite_LookupConfig(u16 DeviceId) {
	XMemwrite_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMEMWRITE_NUM_INSTANCES; Index++) {
		if (XMemwrite_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMemwrite_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMemwrite_Initialize(XMemwrite *InstancePtr, u16 DeviceId) {
	XMemwrite_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMemwrite_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMemwrite_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

