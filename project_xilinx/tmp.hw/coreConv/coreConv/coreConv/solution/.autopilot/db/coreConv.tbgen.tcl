set moduleName coreConv
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_chain
set isOneStateSeq 0
set ProfileFlag 1
set StallSigGenFlag 1
set isEnableWaveformDebug 1
set C_modelName {coreConv}
set C_modelType { void 0 }
set C_modelArgList {
	{ output_num int 32 regular {axi_slave 0}  }
	{ conv_loop_cnt int 32 regular {axi_slave 0}  }
	{ contol int 32 regular {axi_slave 0}  }
	{ frac_w int 8 regular {axi_slave 0}  }
	{ frac_din int 8 regular {axi_slave 0}  }
	{ frac_dout int 8 regular {axi_slave 0}  }
	{ bias_in_V_data_V int 16 regular {axi_s 0 volatile  { bias_in Data } }  }
	{ bias_in_V_keep_V int 2 regular {axi_s 0 volatile  { bias_in Keep } }  }
	{ bias_in_V_strb_V int 2 regular {axi_s 0 volatile  { bias_in Strb } }  }
	{ bias_in_V_last_V int 1 regular {axi_s 0 volatile  { bias_in Last } }  }
	{ weight_in_V_data_V int 64 regular {axi_s 0 volatile  { weight_in Data } }  }
	{ weight_in_V_keep_V int 8 regular {axi_s 0 volatile  { weight_in Keep } }  }
	{ weight_in_V_strb_V int 8 regular {axi_s 0 volatile  { weight_in Strb } }  }
	{ weight_in_V_last_V int 1 regular {axi_s 0 volatile  { weight_in Last } }  }
	{ data_in_V_data_V int 64 regular {axi_s 0 volatile  { data_in Data } }  }
	{ data_in_V_keep_V int 8 regular {axi_s 0 volatile  { data_in Keep } }  }
	{ data_in_V_strb_V int 8 regular {axi_s 0 volatile  { data_in Strb } }  }
	{ data_in_V_last_V int 1 regular {axi_s 0 volatile  { data_in Last } }  }
	{ conv_out_V_data_V int 16 regular {axi_s 1 volatile  { conv_out Data } }  }
	{ conv_out_V_keep_V int 2 regular {axi_s 1 volatile  { conv_out Keep } }  }
	{ conv_out_V_strb_V int 2 regular {axi_s 1 volatile  { conv_out Strb } }  }
	{ conv_out_V_last_V int 1 regular {axi_s 1 volatile  { conv_out Last } }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "output_num", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "output_num","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":16}, "offset_end" : {"in":23}} , 
 	{ "Name" : "conv_loop_cnt", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "conv_loop_cnt","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":24}, "offset_end" : {"in":31}} , 
 	{ "Name" : "contol", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "contol","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":32}, "offset_end" : {"in":39}} , 
 	{ "Name" : "frac_w", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "frac_w","cData": "char","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":40}, "offset_end" : {"in":47}} , 
 	{ "Name" : "frac_din", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "frac_din","cData": "char","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":48}, "offset_end" : {"in":55}} , 
 	{ "Name" : "frac_dout", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "frac_dout","cData": "char","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":56}, "offset_end" : {"in":63}} , 
 	{ "Name" : "bias_in_V_data_V", "interface" : "axis", "bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "bias_in.V.data.V","cData": "short","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "bias_in_V_keep_V", "interface" : "axis", "bitwidth" : 2, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "bias_in.V.keep.V","cData": "int2","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "bias_in_V_strb_V", "interface" : "axis", "bitwidth" : 2, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "bias_in.V.strb.V","cData": "int2","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "bias_in_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "bias_in.V.last.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "weight_in_V_data_V", "interface" : "axis", "bitwidth" : 64, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "weight_in.V.data.V","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "weight_in_V_keep_V", "interface" : "axis", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "weight_in.V.keep.V","cData": "char","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "weight_in_V_strb_V", "interface" : "axis", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "weight_in.V.strb.V","cData": "char","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "weight_in_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "weight_in.V.last.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "data_in_V_data_V", "interface" : "axis", "bitwidth" : 64, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "data_in.V.data.V","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "data_in_V_keep_V", "interface" : "axis", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "data_in.V.keep.V","cData": "char","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "data_in_V_strb_V", "interface" : "axis", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "data_in.V.strb.V","cData": "char","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "data_in_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "data_in.V.last.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "conv_out_V_data_V", "interface" : "axis", "bitwidth" : 16, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "conv_out.V.data.V","cData": "short","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "conv_out_V_keep_V", "interface" : "axis", "bitwidth" : 2, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "conv_out.V.keep.V","cData": "int2","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "conv_out_V_strb_V", "interface" : "axis", "bitwidth" : 2, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "conv_out.V.strb.V","cData": "int2","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "conv_out_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "conv_out.V.last.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 52
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ event_done sc_out sc_logic 1 signal -1 } 
	{ bias_in_TDATA sc_in sc_lv 16 signal 6 } 
	{ bias_in_TVALID sc_in sc_logic 1 invld 9 } 
	{ bias_in_TREADY sc_out sc_logic 1 inacc 9 } 
	{ bias_in_TKEEP sc_in sc_lv 2 signal 7 } 
	{ bias_in_TSTRB sc_in sc_lv 2 signal 8 } 
	{ bias_in_TLAST sc_in sc_lv 1 signal 9 } 
	{ weight_in_TDATA sc_in sc_lv 64 signal 10 } 
	{ weight_in_TVALID sc_in sc_logic 1 invld 13 } 
	{ weight_in_TREADY sc_out sc_logic 1 inacc 13 } 
	{ weight_in_TKEEP sc_in sc_lv 8 signal 11 } 
	{ weight_in_TSTRB sc_in sc_lv 8 signal 12 } 
	{ weight_in_TLAST sc_in sc_lv 1 signal 13 } 
	{ data_in_TDATA sc_in sc_lv 64 signal 14 } 
	{ data_in_TVALID sc_in sc_logic 1 invld 17 } 
	{ data_in_TREADY sc_out sc_logic 1 inacc 17 } 
	{ data_in_TKEEP sc_in sc_lv 8 signal 15 } 
	{ data_in_TSTRB sc_in sc_lv 8 signal 16 } 
	{ data_in_TLAST sc_in sc_lv 1 signal 17 } 
	{ conv_out_TDATA sc_out sc_lv 16 signal 18 } 
	{ conv_out_TVALID sc_out sc_logic 1 outvld 21 } 
	{ conv_out_TREADY sc_in sc_logic 1 outacc 21 } 
	{ conv_out_TKEEP sc_out sc_lv 2 signal 19 } 
	{ conv_out_TSTRB sc_out sc_lv 2 signal 20 } 
	{ conv_out_TLAST sc_out sc_lv 1 signal 21 } 
	{ s_axi_control_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_AWADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_control_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_control_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_ARADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_control_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_control_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
	{ event_start sc_out sc_logic 1 signal -1 } 
	{ stall_start_ext sc_out sc_logic 1 signal -1 } 
	{ stall_done_ext sc_out sc_logic 1 signal -1 } 
	{ stall_start_str sc_out sc_logic 1 signal -1 } 
	{ stall_done_str sc_out sc_logic 1 signal -1 } 
	{ stall_start_int sc_out sc_logic 1 signal -1 } 
	{ stall_done_int sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_control_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "AWADDR" },"address":[{"name":"coreConv","role":"start","value":"0","valid_bit":"0"},{"name":"coreConv","role":"continue","value":"0","valid_bit":"4"},{"name":"coreConv","role":"auto_start","value":"0","valid_bit":"7"},{"name":"output_num","role":"data","value":"16"},{"name":"conv_loop_cnt","role":"data","value":"24"},{"name":"contol","role":"data","value":"32"},{"name":"frac_w","role":"data","value":"40"},{"name":"frac_din","role":"data","value":"48"},{"name":"frac_dout","role":"data","value":"56"}] },
	{ "name": "s_axi_control_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWVALID" } },
	{ "name": "s_axi_control_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWREADY" } },
	{ "name": "s_axi_control_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WVALID" } },
	{ "name": "s_axi_control_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WREADY" } },
	{ "name": "s_axi_control_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "WDATA" } },
	{ "name": "s_axi_control_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "control", "role": "WSTRB" } },
	{ "name": "s_axi_control_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "ARADDR" },"address":[{"name":"coreConv","role":"start","value":"0","valid_bit":"0"},{"name":"coreConv","role":"done","value":"0","valid_bit":"1"},{"name":"coreConv","role":"idle","value":"0","valid_bit":"2"},{"name":"coreConv","role":"ready","value":"0","valid_bit":"3"},{"name":"coreConv","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_control_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARVALID" } },
	{ "name": "s_axi_control_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARREADY" } },
	{ "name": "s_axi_control_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RVALID" } },
	{ "name": "s_axi_control_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RREADY" } },
	{ "name": "s_axi_control_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "RDATA" } },
	{ "name": "s_axi_control_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "RRESP" } },
	{ "name": "s_axi_control_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BVALID" } },
	{ "name": "s_axi_control_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BREADY" } },
	{ "name": "s_axi_control_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "event_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "event_done", "role": "default" }} , 
 	{ "name": "bias_in_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "bias_in_V_data_V", "role": "default" }} , 
 	{ "name": "bias_in_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "bias_in_V_last_V", "role": "default" }} , 
 	{ "name": "bias_in_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "bias_in_V_last_V", "role": "default" }} , 
 	{ "name": "bias_in_TKEEP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "bias_in_V_keep_V", "role": "default" }} , 
 	{ "name": "bias_in_TSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "bias_in_V_strb_V", "role": "default" }} , 
 	{ "name": "bias_in_TLAST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "bias_in_V_last_V", "role": "default" }} , 
 	{ "name": "weight_in_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "weight_in_V_data_V", "role": "default" }} , 
 	{ "name": "weight_in_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "weight_in_V_last_V", "role": "default" }} , 
 	{ "name": "weight_in_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "weight_in_V_last_V", "role": "default" }} , 
 	{ "name": "weight_in_TKEEP", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "weight_in_V_keep_V", "role": "default" }} , 
 	{ "name": "weight_in_TSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "weight_in_V_strb_V", "role": "default" }} , 
 	{ "name": "weight_in_TLAST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "weight_in_V_last_V", "role": "default" }} , 
 	{ "name": "data_in_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "data_in_V_data_V", "role": "default" }} , 
 	{ "name": "data_in_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "data_in_V_last_V", "role": "default" }} , 
 	{ "name": "data_in_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "data_in_V_last_V", "role": "default" }} , 
 	{ "name": "data_in_TKEEP", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "data_in_V_keep_V", "role": "default" }} , 
 	{ "name": "data_in_TSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "data_in_V_strb_V", "role": "default" }} , 
 	{ "name": "data_in_TLAST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "data_in_V_last_V", "role": "default" }} , 
 	{ "name": "conv_out_TDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "conv_out_V_data_V", "role": "default" }} , 
 	{ "name": "conv_out_TVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "conv_out_V_last_V", "role": "default" }} , 
 	{ "name": "conv_out_TREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "conv_out_V_last_V", "role": "default" }} , 
 	{ "name": "conv_out_TKEEP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "conv_out_V_keep_V", "role": "default" }} , 
 	{ "name": "conv_out_TSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "conv_out_V_strb_V", "role": "default" }} , 
 	{ "name": "conv_out_TLAST", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_out_V_last_V", "role": "default" }} , 
 	{ "name": "event_start", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "event_start", "role": "default" }} , 
 	{ "name": "stall_start_ext", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stall_start_ext", "role": "default" }} , 
 	{ "name": "stall_done_ext", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stall_done_ext", "role": "default" }} , 
 	{ "name": "stall_start_str", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stall_start_str", "role": "default" }} , 
 	{ "name": "stall_done_str", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stall_done_str", "role": "default" }} , 
 	{ "name": "stall_start_int", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stall_start_int", "role": "default" }} , 
 	{ "name": "stall_done_int", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "stall_done_int", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"],
		"CDFG" : "coreConv",
		"Protocol" : "ap_ctrl_chain",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "output_num", "Type" : "None", "Direction" : "I"},
			{"Name" : "conv_loop_cnt", "Type" : "None", "Direction" : "I"},
			{"Name" : "contol", "Type" : "None", "Direction" : "I"},
			{"Name" : "frac_w", "Type" : "None", "Direction" : "I"},
			{"Name" : "frac_din", "Type" : "None", "Direction" : "I"},
			{"Name" : "frac_dout", "Type" : "None", "Direction" : "I"},
			{"Name" : "bias_in_V_data_V", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "bias_in_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "bias_in_V_keep_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "bias_in_V_strb_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "bias_in_V_last_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "weight_in_V_data_V", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "weight_in_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "weight_in_V_keep_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "weight_in_V_strb_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "weight_in_V_last_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "data_in_V_data_V", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "data_in_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "data_in_V_keep_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "data_in_V_strb_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "data_in_V_last_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "conv_out_V_data_V", "Type" : "Axis", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "conv_out_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "conv_out_V_keep_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "conv_out_V_strb_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "conv_out_V_last_V", "Type" : "Axis", "Direction" : "O"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.control_s_axi_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_32s_32s_32_2_1_U1", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_8s_8s_16_1_1_U2", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_8s_8s_16_1_1_U3", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_8s_8s_16_1_1_U4", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_8s_8s_16_1_1_U5", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mac_muladd_8s_8s_16s_17_4_1_U6", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mac_muladd_8s_8s_16s_17_4_1_U7", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mac_muladd_8s_8s_16s_17_4_1_U8", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mac_muladd_8s_8s_16s_17_4_1_U9", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_bias_in_V_data_V_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_bias_in_V_keep_V_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_bias_in_V_strb_V_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_bias_in_V_last_V_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_weight_in_V_data_V_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_weight_in_V_keep_V_U", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_weight_in_V_strb_V_U", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_weight_in_V_last_V_U", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_data_in_V_data_V_U", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_data_in_V_keep_V_U", "Parent" : "0"},
	{"ID" : "21", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_data_in_V_strb_V_U", "Parent" : "0"},
	{"ID" : "22", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_data_in_V_last_V_U", "Parent" : "0"},
	{"ID" : "23", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_conv_out_V_data_V_U", "Parent" : "0"},
	{"ID" : "24", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_conv_out_V_keep_V_U", "Parent" : "0"},
	{"ID" : "25", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_conv_out_V_strb_V_U", "Parent" : "0"},
	{"ID" : "26", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_conv_out_V_last_V_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	coreConv {
		output_num {Type I LastRead 0 FirstWrite -1}
		conv_loop_cnt {Type I LastRead 0 FirstWrite -1}
		contol {Type I LastRead 2 FirstWrite -1}
		frac_w {Type I LastRead 1 FirstWrite -1}
		frac_din {Type I LastRead 1 FirstWrite -1}
		frac_dout {Type I LastRead 1 FirstWrite -1}
		bias_in_V_data_V {Type I LastRead 3 FirstWrite -1}
		bias_in_V_keep_V {Type I LastRead 3 FirstWrite -1}
		bias_in_V_strb_V {Type I LastRead 3 FirstWrite -1}
		bias_in_V_last_V {Type I LastRead 3 FirstWrite -1}
		weight_in_V_data_V {Type I LastRead 3 FirstWrite -1}
		weight_in_V_keep_V {Type I LastRead 3 FirstWrite -1}
		weight_in_V_strb_V {Type I LastRead 3 FirstWrite -1}
		weight_in_V_last_V {Type I LastRead 3 FirstWrite -1}
		data_in_V_data_V {Type I LastRead 3 FirstWrite -1}
		data_in_V_keep_V {Type I LastRead 3 FirstWrite -1}
		data_in_V_strb_V {Type I LastRead 3 FirstWrite -1}
		data_in_V_last_V {Type I LastRead 3 FirstWrite -1}
		conv_out_V_data_V {Type O LastRead -1 FirstWrite 9}
		conv_out_V_keep_V {Type O LastRead -1 FirstWrite 9}
		conv_out_V_strb_V {Type O LastRead -1 FirstWrite 9}
		conv_out_V_last_V {Type O LastRead -1 FirstWrite 9}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	bias_in_V_data_V { axis {  { bias_in_TDATA in_data 0 16 } } }
	bias_in_V_keep_V { axis {  { bias_in_TKEEP in_data 0 2 } } }
	bias_in_V_strb_V { axis {  { bias_in_TSTRB in_data 0 2 } } }
	bias_in_V_last_V { axis {  { bias_in_TVALID in_vld 0 1 }  { bias_in_TREADY in_acc 1 1 }  { bias_in_TLAST in_data 0 1 } } }
	weight_in_V_data_V { axis {  { weight_in_TDATA in_data 0 64 } } }
	weight_in_V_keep_V { axis {  { weight_in_TKEEP in_data 0 8 } } }
	weight_in_V_strb_V { axis {  { weight_in_TSTRB in_data 0 8 } } }
	weight_in_V_last_V { axis {  { weight_in_TVALID in_vld 0 1 }  { weight_in_TREADY in_acc 1 1 }  { weight_in_TLAST in_data 0 1 } } }
	data_in_V_data_V { axis {  { data_in_TDATA in_data 0 64 } } }
	data_in_V_keep_V { axis {  { data_in_TKEEP in_data 0 8 } } }
	data_in_V_strb_V { axis {  { data_in_TSTRB in_data 0 8 } } }
	data_in_V_last_V { axis {  { data_in_TVALID in_vld 0 1 }  { data_in_TREADY in_acc 1 1 }  { data_in_TLAST in_data 0 1 } } }
	conv_out_V_data_V { axis {  { conv_out_TDATA out_data 1 16 } } }
	conv_out_V_keep_V { axis {  { conv_out_TKEEP out_data 1 2 } } }
	conv_out_V_strb_V { axis {  { conv_out_TSTRB out_data 1 2 } } }
	conv_out_V_last_V { axis {  { conv_out_TVALID out_vld 1 1 }  { conv_out_TREADY out_acc 0 1 }  { conv_out_TLAST out_data 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
