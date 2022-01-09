#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst_n", 1, hls_in, -1, "", "", 1),
	Port_Property("event_done", 1, hls_out, -1, "", "", 1),
	Port_Property("bias_in_TDATA", 16, hls_in, 6, "axis", "in_data", 1),
	Port_Property("bias_in_TVALID", 1, hls_in, 9, "axis", "in_vld", 1),
	Port_Property("bias_in_TREADY", 1, hls_out, 9, "axis", "in_acc", 1),
	Port_Property("bias_in_TKEEP", 2, hls_in, 7, "axis", "in_data", 1),
	Port_Property("bias_in_TSTRB", 2, hls_in, 8, "axis", "in_data", 1),
	Port_Property("bias_in_TLAST", 1, hls_in, 9, "axis", "in_data", 1),
	Port_Property("weight_in_TDATA", 64, hls_in, 10, "axis", "in_data", 1),
	Port_Property("weight_in_TVALID", 1, hls_in, 13, "axis", "in_vld", 1),
	Port_Property("weight_in_TREADY", 1, hls_out, 13, "axis", "in_acc", 1),
	Port_Property("weight_in_TKEEP", 8, hls_in, 11, "axis", "in_data", 1),
	Port_Property("weight_in_TSTRB", 8, hls_in, 12, "axis", "in_data", 1),
	Port_Property("weight_in_TLAST", 1, hls_in, 13, "axis", "in_data", 1),
	Port_Property("data_in_TDATA", 64, hls_in, 14, "axis", "in_data", 1),
	Port_Property("data_in_TVALID", 1, hls_in, 17, "axis", "in_vld", 1),
	Port_Property("data_in_TREADY", 1, hls_out, 17, "axis", "in_acc", 1),
	Port_Property("data_in_TKEEP", 8, hls_in, 15, "axis", "in_data", 1),
	Port_Property("data_in_TSTRB", 8, hls_in, 16, "axis", "in_data", 1),
	Port_Property("data_in_TLAST", 1, hls_in, 17, "axis", "in_data", 1),
	Port_Property("conv_out_TDATA", 16, hls_out, 18, "axis", "out_data", 1),
	Port_Property("conv_out_TVALID", 1, hls_out, 21, "axis", "out_vld", 1),
	Port_Property("conv_out_TREADY", 1, hls_in, 21, "axis", "out_acc", 1),
	Port_Property("conv_out_TKEEP", 2, hls_out, 19, "axis", "out_data", 1),
	Port_Property("conv_out_TSTRB", 2, hls_out, 20, "axis", "out_data", 1),
	Port_Property("conv_out_TLAST", 1, hls_out, 21, "axis", "out_data", 1),
	Port_Property("s_axi_control_AWVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_AWREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_AWADDR", 6, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_WDATA", 32, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WSTRB", 4, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_ARVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_ARREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_ARADDR", 6, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_RVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_RREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_RDATA", 32, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_RRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_BVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_BREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_BRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("interrupt", 1, hls_out, -1, "", "", 1),
	Port_Property("event_start", 1, hls_out, -1, "", "", 1),
	Port_Property("stall_start_ext", 1, hls_out, -1, "", "", 1),
	Port_Property("stall_done_ext", 1, hls_out, -1, "", "", 1),
	Port_Property("stall_start_str", 1, hls_out, -1, "", "", 1),
	Port_Property("stall_done_str", 1, hls_out, -1, "", "", 1),
	Port_Property("stall_start_int", 1, hls_out, -1, "", "", 1),
	Port_Property("stall_done_int", 1, hls_out, -1, "", "", 1),
};
const char* HLS_Design_Meta::dut_name = "coreConv";
