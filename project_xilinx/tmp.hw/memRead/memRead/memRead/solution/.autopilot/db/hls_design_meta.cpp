#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst_n", 1, hls_in, -1, "", "", 1),
	Port_Property("event_done", 1, hls_out, -1, "", "", 1),
	Port_Property("m_axi_gmem0_AWVALID", 1, hls_out, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem0_AWREADY", 1, hls_in, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem0_AWADDR", 64, hls_out, 0, "m_axi", "ADDR", 1),
	Port_Property("m_axi_gmem0_AWID", 1, hls_out, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem0_AWLEN", 8, hls_out, 0, "m_axi", "LEN", 1),
	Port_Property("m_axi_gmem0_AWSIZE", 3, hls_out, 0, "m_axi", "SIZE", 1),
	Port_Property("m_axi_gmem0_AWBURST", 2, hls_out, 0, "m_axi", "BURST", 1),
	Port_Property("m_axi_gmem0_AWLOCK", 2, hls_out, 0, "m_axi", "LOCK", 1),
	Port_Property("m_axi_gmem0_AWCACHE", 4, hls_out, 0, "m_axi", "CACHE", 1),
	Port_Property("m_axi_gmem0_AWPROT", 3, hls_out, 0, "m_axi", "PROT", 1),
	Port_Property("m_axi_gmem0_AWQOS", 4, hls_out, 0, "m_axi", "QOS", 1),
	Port_Property("m_axi_gmem0_AWREGION", 4, hls_out, 0, "m_axi", "REGION", 1),
	Port_Property("m_axi_gmem0_AWUSER", 1, hls_out, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem0_WVALID", 1, hls_out, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem0_WREADY", 1, hls_in, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem0_WDATA", 32, hls_out, 0, "m_axi", "DATA", 1),
	Port_Property("m_axi_gmem0_WSTRB", 4, hls_out, 0, "m_axi", "STRB", 1),
	Port_Property("m_axi_gmem0_WLAST", 1, hls_out, 0, "m_axi", "LAST", 1),
	Port_Property("m_axi_gmem0_WID", 1, hls_out, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem0_WUSER", 1, hls_out, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem0_ARVALID", 1, hls_out, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem0_ARREADY", 1, hls_in, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem0_ARADDR", 64, hls_out, 0, "m_axi", "ADDR", 1),
	Port_Property("m_axi_gmem0_ARID", 1, hls_out, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem0_ARLEN", 8, hls_out, 0, "m_axi", "LEN", 1),
	Port_Property("m_axi_gmem0_ARSIZE", 3, hls_out, 0, "m_axi", "SIZE", 1),
	Port_Property("m_axi_gmem0_ARBURST", 2, hls_out, 0, "m_axi", "BURST", 1),
	Port_Property("m_axi_gmem0_ARLOCK", 2, hls_out, 0, "m_axi", "LOCK", 1),
	Port_Property("m_axi_gmem0_ARCACHE", 4, hls_out, 0, "m_axi", "CACHE", 1),
	Port_Property("m_axi_gmem0_ARPROT", 3, hls_out, 0, "m_axi", "PROT", 1),
	Port_Property("m_axi_gmem0_ARQOS", 4, hls_out, 0, "m_axi", "QOS", 1),
	Port_Property("m_axi_gmem0_ARREGION", 4, hls_out, 0, "m_axi", "REGION", 1),
	Port_Property("m_axi_gmem0_ARUSER", 1, hls_out, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem0_RVALID", 1, hls_in, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem0_RREADY", 1, hls_out, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem0_RDATA", 32, hls_in, 0, "m_axi", "DATA", 1),
	Port_Property("m_axi_gmem0_RLAST", 1, hls_in, 0, "m_axi", "LAST", 1),
	Port_Property("m_axi_gmem0_RID", 1, hls_in, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem0_RUSER", 1, hls_in, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem0_RRESP", 2, hls_in, 0, "m_axi", "RESP", 1),
	Port_Property("m_axi_gmem0_BVALID", 1, hls_in, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem0_BREADY", 1, hls_out, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem0_BRESP", 2, hls_in, 0, "m_axi", "RESP", 1),
	Port_Property("m_axi_gmem0_BID", 1, hls_in, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem0_BUSER", 1, hls_in, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem1_AWVALID", 1, hls_out, 1, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem1_AWREADY", 1, hls_in, 1, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem1_AWADDR", 64, hls_out, 1, "m_axi", "ADDR", 1),
	Port_Property("m_axi_gmem1_AWID", 1, hls_out, 1, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem1_AWLEN", 8, hls_out, 1, "m_axi", "LEN", 1),
	Port_Property("m_axi_gmem1_AWSIZE", 3, hls_out, 1, "m_axi", "SIZE", 1),
	Port_Property("m_axi_gmem1_AWBURST", 2, hls_out, 1, "m_axi", "BURST", 1),
	Port_Property("m_axi_gmem1_AWLOCK", 2, hls_out, 1, "m_axi", "LOCK", 1),
	Port_Property("m_axi_gmem1_AWCACHE", 4, hls_out, 1, "m_axi", "CACHE", 1),
	Port_Property("m_axi_gmem1_AWPROT", 3, hls_out, 1, "m_axi", "PROT", 1),
	Port_Property("m_axi_gmem1_AWQOS", 4, hls_out, 1, "m_axi", "QOS", 1),
	Port_Property("m_axi_gmem1_AWREGION", 4, hls_out, 1, "m_axi", "REGION", 1),
	Port_Property("m_axi_gmem1_AWUSER", 1, hls_out, 1, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem1_WVALID", 1, hls_out, 1, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem1_WREADY", 1, hls_in, 1, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem1_WDATA", 64, hls_out, 1, "m_axi", "DATA", 1),
	Port_Property("m_axi_gmem1_WSTRB", 8, hls_out, 1, "m_axi", "STRB", 1),
	Port_Property("m_axi_gmem1_WLAST", 1, hls_out, 1, "m_axi", "LAST", 1),
	Port_Property("m_axi_gmem1_WID", 1, hls_out, 1, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem1_WUSER", 1, hls_out, 1, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem1_ARVALID", 1, hls_out, 1, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem1_ARREADY", 1, hls_in, 1, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem1_ARADDR", 64, hls_out, 1, "m_axi", "ADDR", 1),
	Port_Property("m_axi_gmem1_ARID", 1, hls_out, 1, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem1_ARLEN", 8, hls_out, 1, "m_axi", "LEN", 1),
	Port_Property("m_axi_gmem1_ARSIZE", 3, hls_out, 1, "m_axi", "SIZE", 1),
	Port_Property("m_axi_gmem1_ARBURST", 2, hls_out, 1, "m_axi", "BURST", 1),
	Port_Property("m_axi_gmem1_ARLOCK", 2, hls_out, 1, "m_axi", "LOCK", 1),
	Port_Property("m_axi_gmem1_ARCACHE", 4, hls_out, 1, "m_axi", "CACHE", 1),
	Port_Property("m_axi_gmem1_ARPROT", 3, hls_out, 1, "m_axi", "PROT", 1),
	Port_Property("m_axi_gmem1_ARQOS", 4, hls_out, 1, "m_axi", "QOS", 1),
	Port_Property("m_axi_gmem1_ARREGION", 4, hls_out, 1, "m_axi", "REGION", 1),
	Port_Property("m_axi_gmem1_ARUSER", 1, hls_out, 1, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem1_RVALID", 1, hls_in, 1, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem1_RREADY", 1, hls_out, 1, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem1_RDATA", 64, hls_in, 1, "m_axi", "DATA", 1),
	Port_Property("m_axi_gmem1_RLAST", 1, hls_in, 1, "m_axi", "LAST", 1),
	Port_Property("m_axi_gmem1_RID", 1, hls_in, 1, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem1_RUSER", 1, hls_in, 1, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem1_RRESP", 2, hls_in, 1, "m_axi", "RESP", 1),
	Port_Property("m_axi_gmem1_BVALID", 1, hls_in, 1, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem1_BREADY", 1, hls_out, 1, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem1_BRESP", 2, hls_in, 1, "m_axi", "RESP", 1),
	Port_Property("m_axi_gmem1_BID", 1, hls_in, 1, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem1_BUSER", 1, hls_in, 1, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem2_AWVALID", 1, hls_out, 2, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem2_AWREADY", 1, hls_in, 2, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem2_AWADDR", 64, hls_out, 2, "m_axi", "ADDR", 1),
	Port_Property("m_axi_gmem2_AWID", 1, hls_out, 2, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem2_AWLEN", 8, hls_out, 2, "m_axi", "LEN", 1),
	Port_Property("m_axi_gmem2_AWSIZE", 3, hls_out, 2, "m_axi", "SIZE", 1),
	Port_Property("m_axi_gmem2_AWBURST", 2, hls_out, 2, "m_axi", "BURST", 1),
	Port_Property("m_axi_gmem2_AWLOCK", 2, hls_out, 2, "m_axi", "LOCK", 1),
	Port_Property("m_axi_gmem2_AWCACHE", 4, hls_out, 2, "m_axi", "CACHE", 1),
	Port_Property("m_axi_gmem2_AWPROT", 3, hls_out, 2, "m_axi", "PROT", 1),
	Port_Property("m_axi_gmem2_AWQOS", 4, hls_out, 2, "m_axi", "QOS", 1),
	Port_Property("m_axi_gmem2_AWREGION", 4, hls_out, 2, "m_axi", "REGION", 1),
	Port_Property("m_axi_gmem2_AWUSER", 1, hls_out, 2, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem2_WVALID", 1, hls_out, 2, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem2_WREADY", 1, hls_in, 2, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem2_WDATA", 32, hls_out, 2, "m_axi", "DATA", 1),
	Port_Property("m_axi_gmem2_WSTRB", 4, hls_out, 2, "m_axi", "STRB", 1),
	Port_Property("m_axi_gmem2_WLAST", 1, hls_out, 2, "m_axi", "LAST", 1),
	Port_Property("m_axi_gmem2_WID", 1, hls_out, 2, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem2_WUSER", 1, hls_out, 2, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem2_ARVALID", 1, hls_out, 2, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem2_ARREADY", 1, hls_in, 2, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem2_ARADDR", 64, hls_out, 2, "m_axi", "ADDR", 1),
	Port_Property("m_axi_gmem2_ARID", 1, hls_out, 2, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem2_ARLEN", 8, hls_out, 2, "m_axi", "LEN", 1),
	Port_Property("m_axi_gmem2_ARSIZE", 3, hls_out, 2, "m_axi", "SIZE", 1),
	Port_Property("m_axi_gmem2_ARBURST", 2, hls_out, 2, "m_axi", "BURST", 1),
	Port_Property("m_axi_gmem2_ARLOCK", 2, hls_out, 2, "m_axi", "LOCK", 1),
	Port_Property("m_axi_gmem2_ARCACHE", 4, hls_out, 2, "m_axi", "CACHE", 1),
	Port_Property("m_axi_gmem2_ARPROT", 3, hls_out, 2, "m_axi", "PROT", 1),
	Port_Property("m_axi_gmem2_ARQOS", 4, hls_out, 2, "m_axi", "QOS", 1),
	Port_Property("m_axi_gmem2_ARREGION", 4, hls_out, 2, "m_axi", "REGION", 1),
	Port_Property("m_axi_gmem2_ARUSER", 1, hls_out, 2, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem2_RVALID", 1, hls_in, 2, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem2_RREADY", 1, hls_out, 2, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem2_RDATA", 32, hls_in, 2, "m_axi", "DATA", 1),
	Port_Property("m_axi_gmem2_RLAST", 1, hls_in, 2, "m_axi", "LAST", 1),
	Port_Property("m_axi_gmem2_RID", 1, hls_in, 2, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem2_RUSER", 1, hls_in, 2, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem2_RRESP", 2, hls_in, 2, "m_axi", "RESP", 1),
	Port_Property("m_axi_gmem2_BVALID", 1, hls_in, 2, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem2_BREADY", 1, hls_out, 2, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem2_BRESP", 2, hls_in, 2, "m_axi", "RESP", 1),
	Port_Property("m_axi_gmem2_BID", 1, hls_in, 2, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem2_BUSER", 1, hls_in, 2, "m_axi", "USER", 1),
	Port_Property("bias_out_TDATA", 16, hls_out, 26, "axis", "out_data", 1),
	Port_Property("bias_out_TVALID", 1, hls_out, 29, "axis", "out_vld", 1),
	Port_Property("bias_out_TREADY", 1, hls_in, 29, "axis", "out_acc", 1),
	Port_Property("bias_out_TKEEP", 2, hls_out, 27, "axis", "out_data", 1),
	Port_Property("bias_out_TSTRB", 2, hls_out, 28, "axis", "out_data", 1),
	Port_Property("bias_out_TLAST", 1, hls_out, 29, "axis", "out_data", 1),
	Port_Property("weight_out_TDATA", 64, hls_out, 30, "axis", "out_data", 1),
	Port_Property("weight_out_TVALID", 1, hls_out, 33, "axis", "out_vld", 1),
	Port_Property("weight_out_TREADY", 1, hls_in, 33, "axis", "out_acc", 1),
	Port_Property("weight_out_TKEEP", 8, hls_out, 31, "axis", "out_data", 1),
	Port_Property("weight_out_TSTRB", 8, hls_out, 32, "axis", "out_data", 1),
	Port_Property("weight_out_TLAST", 1, hls_out, 33, "axis", "out_data", 1),
	Port_Property("data_out_TDATA", 64, hls_out, 34, "axis", "out_data", 1),
	Port_Property("data_out_TVALID", 1, hls_out, 37, "axis", "out_vld", 1),
	Port_Property("data_out_TREADY", 1, hls_in, 37, "axis", "out_acc", 1),
	Port_Property("data_out_TKEEP", 8, hls_out, 35, "axis", "out_data", 1),
	Port_Property("data_out_TSTRB", 8, hls_out, 36, "axis", "out_data", 1),
	Port_Property("data_out_TLAST", 1, hls_out, 37, "axis", "out_data", 1),
	Port_Property("s_axi_control_AWVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_AWREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_AWADDR", 8, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_WDATA", 32, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WSTRB", 4, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_ARVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_ARREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_ARADDR", 8, hls_in, -1, "", "", 1),
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
const char* HLS_Design_Meta::dut_name = "memRead";
