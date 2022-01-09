#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_gmem0 "../tv/cdatafile/c.memRead.autotvin_gmem0.dat"
#define AUTOTB_TVOUT_gmem0 "../tv/cdatafile/c.memRead.autotvout_gmem0.dat"
// wrapc file define:
#define AUTOTB_TVIN_gmem1 "../tv/cdatafile/c.memRead.autotvin_gmem1.dat"
#define AUTOTB_TVOUT_gmem1 "../tv/cdatafile/c.memRead.autotvout_gmem1.dat"
// wrapc file define:
#define AUTOTB_TVIN_gmem2 "../tv/cdatafile/c.memRead.autotvin_gmem2.dat"
#define AUTOTB_TVOUT_gmem2 "../tv/cdatafile/c.memRead.autotvout_gmem2.dat"
// wrapc file define:
#define AUTOTB_TVIN_data_dim1 "../tv/cdatafile/c.memRead.autotvin_data_dim1.dat"
#define AUTOTB_TVOUT_data_dim1 "../tv/cdatafile/c.memRead.autotvout_data_dim1.dat"
// wrapc file define:
#define AUTOTB_TVIN_data_dim2 "../tv/cdatafile/c.memRead.autotvin_data_dim2.dat"
#define AUTOTB_TVOUT_data_dim2 "../tv/cdatafile/c.memRead.autotvout_data_dim2.dat"
// wrapc file define:
#define AUTOTB_TVIN_data_dim1xdim2 "../tv/cdatafile/c.memRead.autotvin_data_dim1xdim2.dat"
#define AUTOTB_TVOUT_data_dim1xdim2 "../tv/cdatafile/c.memRead.autotvout_data_dim1xdim2.dat"
// wrapc file define:
#define AUTOTB_TVIN_weight_dim1 "../tv/cdatafile/c.memRead.autotvin_weight_dim1.dat"
#define AUTOTB_TVOUT_weight_dim1 "../tv/cdatafile/c.memRead.autotvout_weight_dim1.dat"
// wrapc file define:
#define AUTOTB_TVIN_weight_dim2 "../tv/cdatafile/c.memRead.autotvin_weight_dim2.dat"
#define AUTOTB_TVOUT_weight_dim2 "../tv/cdatafile/c.memRead.autotvout_weight_dim2.dat"
// wrapc file define:
#define AUTOTB_TVIN_weight_dim3 "../tv/cdatafile/c.memRead.autotvin_weight_dim3.dat"
#define AUTOTB_TVOUT_weight_dim3 "../tv/cdatafile/c.memRead.autotvout_weight_dim3.dat"
// wrapc file define:
#define AUTOTB_TVIN_weight_dim4_div_lane "../tv/cdatafile/c.memRead.autotvin_weight_dim4_div_lane.dat"
#define AUTOTB_TVOUT_weight_dim4_div_lane "../tv/cdatafile/c.memRead.autotvout_weight_dim4_div_lane.dat"
// wrapc file define:
#define AUTOTB_TVIN_weight_dim1x2 "../tv/cdatafile/c.memRead.autotvin_weight_dim1x2.dat"
#define AUTOTB_TVOUT_weight_dim1x2 "../tv/cdatafile/c.memRead.autotvout_weight_dim1x2.dat"
// wrapc file define:
#define AUTOTB_TVIN_weight_dim1x2x3 "../tv/cdatafile/c.memRead.autotvin_weight_dim1x2x3.dat"
#define AUTOTB_TVOUT_weight_dim1x2x3 "../tv/cdatafile/c.memRead.autotvout_weight_dim1x2x3.dat"
// wrapc file define:
#define AUTOTB_TVIN_conv_x "../tv/cdatafile/c.memRead.autotvin_conv_x.dat"
#define AUTOTB_TVOUT_conv_x "../tv/cdatafile/c.memRead.autotvout_conv_x.dat"
// wrapc file define:
#define AUTOTB_TVIN_stride "../tv/cdatafile/c.memRead.autotvin_stride.dat"
#define AUTOTB_TVOUT_stride "../tv/cdatafile/c.memRead.autotvout_stride.dat"
// wrapc file define:
#define AUTOTB_TVIN_padding "../tv/cdatafile/c.memRead.autotvin_padding.dat"
#define AUTOTB_TVOUT_padding "../tv/cdatafile/c.memRead.autotvout_padding.dat"
// wrapc file define:
#define AUTOTB_TVIN_split "../tv/cdatafile/c.memRead.autotvin_split.dat"
#define AUTOTB_TVOUT_split "../tv/cdatafile/c.memRead.autotvout_split.dat"
// wrapc file define:
#define AUTOTB_TVIN_group_num_x "../tv/cdatafile/c.memRead.autotvin_group_num_x.dat"
#define AUTOTB_TVOUT_group_num_x "../tv/cdatafile/c.memRead.autotvout_group_num_x.dat"
// wrapc file define:
#define AUTOTB_TVIN_group_num_y "../tv/cdatafile/c.memRead.autotvin_group_num_y.dat"
#define AUTOTB_TVOUT_group_num_y "../tv/cdatafile/c.memRead.autotvout_group_num_y.dat"
// wrapc file define:
#define AUTOTB_TVIN_group_rem_size_x "../tv/cdatafile/c.memRead.autotvin_group_rem_size_x.dat"
#define AUTOTB_TVOUT_group_rem_size_x "../tv/cdatafile/c.memRead.autotvout_group_rem_size_x.dat"
// wrapc file define:
#define AUTOTB_TVIN_group_rem_size_xyz "../tv/cdatafile/c.memRead.autotvin_group_rem_size_xyz.dat"
#define AUTOTB_TVOUT_group_rem_size_xyz "../tv/cdatafile/c.memRead.autotvout_group_rem_size_xyz.dat"
// wrapc file define:
#define AUTOTB_TVIN_win_size_x "../tv/cdatafile/c.memRead.autotvin_win_size_x.dat"
#define AUTOTB_TVOUT_win_size_x "../tv/cdatafile/c.memRead.autotvout_win_size_x.dat"
// wrapc file define:
#define AUTOTB_TVIN_win_size_y "../tv/cdatafile/c.memRead.autotvin_win_size_y.dat"
#define AUTOTB_TVOUT_win_size_y "../tv/cdatafile/c.memRead.autotvout_win_size_y.dat"
// wrapc file define:
#define AUTOTB_TVIN_win_size_xyz "../tv/cdatafile/c.memRead.autotvin_win_size_xyz.dat"
#define AUTOTB_TVOUT_win_size_xyz "../tv/cdatafile/c.memRead.autotvout_win_size_xyz.dat"
// wrapc file define:
#define AUTOTB_TVIN_bottom "../tv/cdatafile/c.memRead.autotvin_bottom.dat"
#define AUTOTB_TVOUT_bottom "../tv/cdatafile/c.memRead.autotvout_bottom.dat"
// wrapc file define:
#define AUTOTB_TVIN_weights "../tv/cdatafile/c.memRead.autotvin_weights.dat"
#define AUTOTB_TVOUT_weights "../tv/cdatafile/c.memRead.autotvout_weights.dat"
// wrapc file define:
#define AUTOTB_TVIN_bias "../tv/cdatafile/c.memRead.autotvin_bias.dat"
#define AUTOTB_TVOUT_bias "../tv/cdatafile/c.memRead.autotvout_bias.dat"
// wrapc file define:
#define AUTOTB_TVIN_bias_out_V_data_V "../tv/cdatafile/c.memRead.autotvin_bias_out_V_data_V.dat"
#define AUTOTB_TVOUT_bias_out_V_data_V "../tv/cdatafile/c.memRead.autotvout_bias_out_V_data_V.dat"
#define AUTOTB_TVIN_bias_out_V_keep_V "../tv/cdatafile/c.memRead.autotvin_bias_out_V_keep_V.dat"
#define AUTOTB_TVOUT_bias_out_V_keep_V "../tv/cdatafile/c.memRead.autotvout_bias_out_V_keep_V.dat"
#define AUTOTB_TVIN_bias_out_V_strb_V "../tv/cdatafile/c.memRead.autotvin_bias_out_V_strb_V.dat"
#define AUTOTB_TVOUT_bias_out_V_strb_V "../tv/cdatafile/c.memRead.autotvout_bias_out_V_strb_V.dat"
#define AUTOTB_TVIN_bias_out_V_last_V "../tv/cdatafile/c.memRead.autotvin_bias_out_V_last_V.dat"
#define AUTOTB_TVOUT_bias_out_V_last_V "../tv/cdatafile/c.memRead.autotvout_bias_out_V_last_V.dat"
#define WRAPC_STREAM_SIZE_OUT_bias_out_V_data_V "../tv/stream_size/stream_size_out_bias_out_V_data_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_bias_out_V_data_V "../tv/stream_size/stream_egress_status_bias_out_V_data_V.dat"
#define WRAPC_STREAM_SIZE_OUT_bias_out_V_keep_V "../tv/stream_size/stream_size_out_bias_out_V_keep_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_bias_out_V_keep_V "../tv/stream_size/stream_egress_status_bias_out_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_OUT_bias_out_V_strb_V "../tv/stream_size/stream_size_out_bias_out_V_strb_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_bias_out_V_strb_V "../tv/stream_size/stream_egress_status_bias_out_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_OUT_bias_out_V_last_V "../tv/stream_size/stream_size_out_bias_out_V_last_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_bias_out_V_last_V "../tv/stream_size/stream_egress_status_bias_out_V_last_V.dat"
// wrapc file define:
#define AUTOTB_TVIN_weight_out_V_data_V "../tv/cdatafile/c.memRead.autotvin_weight_out_V_data_V.dat"
#define AUTOTB_TVOUT_weight_out_V_data_V "../tv/cdatafile/c.memRead.autotvout_weight_out_V_data_V.dat"
#define AUTOTB_TVIN_weight_out_V_keep_V "../tv/cdatafile/c.memRead.autotvin_weight_out_V_keep_V.dat"
#define AUTOTB_TVOUT_weight_out_V_keep_V "../tv/cdatafile/c.memRead.autotvout_weight_out_V_keep_V.dat"
#define AUTOTB_TVIN_weight_out_V_strb_V "../tv/cdatafile/c.memRead.autotvin_weight_out_V_strb_V.dat"
#define AUTOTB_TVOUT_weight_out_V_strb_V "../tv/cdatafile/c.memRead.autotvout_weight_out_V_strb_V.dat"
#define AUTOTB_TVIN_weight_out_V_last_V "../tv/cdatafile/c.memRead.autotvin_weight_out_V_last_V.dat"
#define AUTOTB_TVOUT_weight_out_V_last_V "../tv/cdatafile/c.memRead.autotvout_weight_out_V_last_V.dat"
#define WRAPC_STREAM_SIZE_OUT_weight_out_V_data_V "../tv/stream_size/stream_size_out_weight_out_V_data_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_weight_out_V_data_V "../tv/stream_size/stream_egress_status_weight_out_V_data_V.dat"
#define WRAPC_STREAM_SIZE_OUT_weight_out_V_keep_V "../tv/stream_size/stream_size_out_weight_out_V_keep_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_weight_out_V_keep_V "../tv/stream_size/stream_egress_status_weight_out_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_OUT_weight_out_V_strb_V "../tv/stream_size/stream_size_out_weight_out_V_strb_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_weight_out_V_strb_V "../tv/stream_size/stream_egress_status_weight_out_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_OUT_weight_out_V_last_V "../tv/stream_size/stream_size_out_weight_out_V_last_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_weight_out_V_last_V "../tv/stream_size/stream_egress_status_weight_out_V_last_V.dat"
// wrapc file define:
#define AUTOTB_TVIN_data_out_V_data_V "../tv/cdatafile/c.memRead.autotvin_data_out_V_data_V.dat"
#define AUTOTB_TVOUT_data_out_V_data_V "../tv/cdatafile/c.memRead.autotvout_data_out_V_data_V.dat"
#define AUTOTB_TVIN_data_out_V_keep_V "../tv/cdatafile/c.memRead.autotvin_data_out_V_keep_V.dat"
#define AUTOTB_TVOUT_data_out_V_keep_V "../tv/cdatafile/c.memRead.autotvout_data_out_V_keep_V.dat"
#define AUTOTB_TVIN_data_out_V_strb_V "../tv/cdatafile/c.memRead.autotvin_data_out_V_strb_V.dat"
#define AUTOTB_TVOUT_data_out_V_strb_V "../tv/cdatafile/c.memRead.autotvout_data_out_V_strb_V.dat"
#define AUTOTB_TVIN_data_out_V_last_V "../tv/cdatafile/c.memRead.autotvin_data_out_V_last_V.dat"
#define AUTOTB_TVOUT_data_out_V_last_V "../tv/cdatafile/c.memRead.autotvout_data_out_V_last_V.dat"
#define WRAPC_STREAM_SIZE_OUT_data_out_V_data_V "../tv/stream_size/stream_size_out_data_out_V_data_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_data_out_V_data_V "../tv/stream_size/stream_egress_status_data_out_V_data_V.dat"
#define WRAPC_STREAM_SIZE_OUT_data_out_V_keep_V "../tv/stream_size/stream_size_out_data_out_V_keep_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_data_out_V_keep_V "../tv/stream_size/stream_egress_status_data_out_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_OUT_data_out_V_strb_V "../tv/stream_size/stream_size_out_data_out_V_strb_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_data_out_V_strb_V "../tv/stream_size/stream_egress_status_data_out_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_OUT_data_out_V_last_V "../tv/stream_size/stream_size_out_data_out_V_last_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_data_out_V_last_V "../tv/stream_size/stream_egress_status_data_out_V_last_V.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_gmem0 "../tv/rtldatafile/rtl.memRead.autotvout_gmem0.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_gmem1 "../tv/rtldatafile/rtl.memRead.autotvout_gmem1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_gmem2 "../tv/rtldatafile/rtl.memRead.autotvout_gmem2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_data_dim1 "../tv/rtldatafile/rtl.memRead.autotvout_data_dim1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_data_dim2 "../tv/rtldatafile/rtl.memRead.autotvout_data_dim2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_data_dim1xdim2 "../tv/rtldatafile/rtl.memRead.autotvout_data_dim1xdim2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_weight_dim1 "../tv/rtldatafile/rtl.memRead.autotvout_weight_dim1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_weight_dim2 "../tv/rtldatafile/rtl.memRead.autotvout_weight_dim2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_weight_dim3 "../tv/rtldatafile/rtl.memRead.autotvout_weight_dim3.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_weight_dim4_div_lane "../tv/rtldatafile/rtl.memRead.autotvout_weight_dim4_div_lane.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_weight_dim1x2 "../tv/rtldatafile/rtl.memRead.autotvout_weight_dim1x2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_weight_dim1x2x3 "../tv/rtldatafile/rtl.memRead.autotvout_weight_dim1x2x3.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_conv_x "../tv/rtldatafile/rtl.memRead.autotvout_conv_x.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_stride "../tv/rtldatafile/rtl.memRead.autotvout_stride.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_padding "../tv/rtldatafile/rtl.memRead.autotvout_padding.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_split "../tv/rtldatafile/rtl.memRead.autotvout_split.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_group_num_x "../tv/rtldatafile/rtl.memRead.autotvout_group_num_x.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_group_num_y "../tv/rtldatafile/rtl.memRead.autotvout_group_num_y.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_group_rem_size_x "../tv/rtldatafile/rtl.memRead.autotvout_group_rem_size_x.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_group_rem_size_xyz "../tv/rtldatafile/rtl.memRead.autotvout_group_rem_size_xyz.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_win_size_x "../tv/rtldatafile/rtl.memRead.autotvout_win_size_x.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_win_size_y "../tv/rtldatafile/rtl.memRead.autotvout_win_size_y.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_win_size_xyz "../tv/rtldatafile/rtl.memRead.autotvout_win_size_xyz.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_bottom "../tv/rtldatafile/rtl.memRead.autotvout_bottom.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_weights "../tv/rtldatafile/rtl.memRead.autotvout_weights.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_bias "../tv/rtldatafile/rtl.memRead.autotvout_bias.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_bias_out_V_data_V "../tv/rtldatafile/rtl.memRead.autotvout_bias_out_V_data_V.dat"
#define AUTOTB_TVOUT_PC_bias_out_V_keep_V "../tv/rtldatafile/rtl.memRead.autotvout_bias_out_V_keep_V.dat"
#define AUTOTB_TVOUT_PC_bias_out_V_strb_V "../tv/rtldatafile/rtl.memRead.autotvout_bias_out_V_strb_V.dat"
#define AUTOTB_TVOUT_PC_bias_out_V_last_V "../tv/rtldatafile/rtl.memRead.autotvout_bias_out_V_last_V.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_weight_out_V_data_V "../tv/rtldatafile/rtl.memRead.autotvout_weight_out_V_data_V.dat"
#define AUTOTB_TVOUT_PC_weight_out_V_keep_V "../tv/rtldatafile/rtl.memRead.autotvout_weight_out_V_keep_V.dat"
#define AUTOTB_TVOUT_PC_weight_out_V_strb_V "../tv/rtldatafile/rtl.memRead.autotvout_weight_out_V_strb_V.dat"
#define AUTOTB_TVOUT_PC_weight_out_V_last_V "../tv/rtldatafile/rtl.memRead.autotvout_weight_out_V_last_V.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_data_out_V_data_V "../tv/rtldatafile/rtl.memRead.autotvout_data_out_V_data_V.dat"
#define AUTOTB_TVOUT_PC_data_out_V_keep_V "../tv/rtldatafile/rtl.memRead.autotvout_data_out_V_keep_V.dat"
#define AUTOTB_TVOUT_PC_data_out_V_strb_V "../tv/rtldatafile/rtl.memRead.autotvout_data_out_V_strb_V.dat"
#define AUTOTB_TVOUT_PC_data_out_V_last_V "../tv/rtldatafile/rtl.memRead.autotvout_data_out_V_last_V.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  gmem0_depth = 0;
  gmem1_depth = 0;
  gmem2_depth = 0;
  data_dim1_depth = 0;
  data_dim2_depth = 0;
  data_dim1xdim2_depth = 0;
  weight_dim1_depth = 0;
  weight_dim2_depth = 0;
  weight_dim3_depth = 0;
  weight_dim4_div_lane_depth = 0;
  weight_dim1x2_depth = 0;
  weight_dim1x2x3_depth = 0;
  conv_x_depth = 0;
  stride_depth = 0;
  padding_depth = 0;
  split_depth = 0;
  group_num_x_depth = 0;
  group_num_y_depth = 0;
  group_rem_size_x_depth = 0;
  group_rem_size_xyz_depth = 0;
  win_size_x_depth = 0;
  win_size_y_depth = 0;
  win_size_xyz_depth = 0;
  bottom_depth = 0;
  weights_depth = 0;
  bias_depth = 0;
  bias_out_V_data_V_depth = 0;
  bias_out_V_keep_V_depth = 0;
  bias_out_V_strb_V_depth = 0;
  bias_out_V_last_V_depth = 0;
  weight_out_V_data_V_depth = 0;
  weight_out_V_keep_V_depth = 0;
  weight_out_V_strb_V_depth = 0;
  weight_out_V_last_V_depth = 0;
  data_out_V_data_V_depth = 0;
  data_out_V_keep_V_depth = 0;
  data_out_V_strb_V_depth = 0;
  data_out_V_last_V_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{gmem0 " << gmem0_depth << "}\n";
  total_list << "{gmem1 " << gmem1_depth << "}\n";
  total_list << "{gmem2 " << gmem2_depth << "}\n";
  total_list << "{data_dim1 " << data_dim1_depth << "}\n";
  total_list << "{data_dim2 " << data_dim2_depth << "}\n";
  total_list << "{data_dim1xdim2 " << data_dim1xdim2_depth << "}\n";
  total_list << "{weight_dim1 " << weight_dim1_depth << "}\n";
  total_list << "{weight_dim2 " << weight_dim2_depth << "}\n";
  total_list << "{weight_dim3 " << weight_dim3_depth << "}\n";
  total_list << "{weight_dim4_div_lane " << weight_dim4_div_lane_depth << "}\n";
  total_list << "{weight_dim1x2 " << weight_dim1x2_depth << "}\n";
  total_list << "{weight_dim1x2x3 " << weight_dim1x2x3_depth << "}\n";
  total_list << "{conv_x " << conv_x_depth << "}\n";
  total_list << "{stride " << stride_depth << "}\n";
  total_list << "{padding " << padding_depth << "}\n";
  total_list << "{split " << split_depth << "}\n";
  total_list << "{group_num_x " << group_num_x_depth << "}\n";
  total_list << "{group_num_y " << group_num_y_depth << "}\n";
  total_list << "{group_rem_size_x " << group_rem_size_x_depth << "}\n";
  total_list << "{group_rem_size_xyz " << group_rem_size_xyz_depth << "}\n";
  total_list << "{win_size_x " << win_size_x_depth << "}\n";
  total_list << "{win_size_y " << win_size_y_depth << "}\n";
  total_list << "{win_size_xyz " << win_size_xyz_depth << "}\n";
  total_list << "{bottom " << bottom_depth << "}\n";
  total_list << "{weights " << weights_depth << "}\n";
  total_list << "{bias " << bias_depth << "}\n";
  total_list << "{bias_out_V_data_V " << bias_out_V_data_V_depth << "}\n";
  total_list << "{bias_out_V_keep_V " << bias_out_V_keep_V_depth << "}\n";
  total_list << "{bias_out_V_strb_V " << bias_out_V_strb_V_depth << "}\n";
  total_list << "{bias_out_V_last_V " << bias_out_V_last_V_depth << "}\n";
  total_list << "{weight_out_V_data_V " << weight_out_V_data_V_depth << "}\n";
  total_list << "{weight_out_V_keep_V " << weight_out_V_keep_V_depth << "}\n";
  total_list << "{weight_out_V_strb_V " << weight_out_V_strb_V_depth << "}\n";
  total_list << "{weight_out_V_last_V " << weight_out_V_last_V_depth << "}\n";
  total_list << "{data_out_V_data_V " << data_out_V_data_V_depth << "}\n";
  total_list << "{data_out_V_keep_V " << data_out_V_keep_V_depth << "}\n";
  total_list << "{data_out_V_strb_V " << data_out_V_strb_V_depth << "}\n";
  total_list << "{data_out_V_last_V " << data_out_V_last_V_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int gmem0_depth;
    int gmem1_depth;
    int gmem2_depth;
    int data_dim1_depth;
    int data_dim2_depth;
    int data_dim1xdim2_depth;
    int weight_dim1_depth;
    int weight_dim2_depth;
    int weight_dim3_depth;
    int weight_dim4_div_lane_depth;
    int weight_dim1x2_depth;
    int weight_dim1x2x3_depth;
    int conv_x_depth;
    int stride_depth;
    int padding_depth;
    int split_depth;
    int group_num_x_depth;
    int group_num_y_depth;
    int group_rem_size_x_depth;
    int group_rem_size_xyz_depth;
    int win_size_x_depth;
    int win_size_y_depth;
    int win_size_xyz_depth;
    int bottom_depth;
    int weights_depth;
    int bias_depth;
    int bias_out_V_data_V_depth;
    int bias_out_V_keep_V_depth;
    int bias_out_V_strb_V_depth;
    int bias_out_V_last_V_depth;
    int weight_out_V_data_V_depth;
    int weight_out_V_keep_V_depth;
    int weight_out_V_strb_V_depth;
    int weight_out_V_last_V_depth;
    int data_out_V_data_V_depth;
    int data_out_V_keep_V_depth;
    int data_out_V_strb_V_depth;
    int data_out_V_last_V_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static void RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool no_x = false;
  bool err = false;

  no_x = false;
  // search and replace 'X' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('X', 0);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
  no_x = false;
  // search and replace 'x' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('x', 2);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
}
struct __cosim_s8__ { char data[8]; };
struct __cosim_s10__ { char data[16]; };
extern "C" void memRead_hw_stub_wrapper(char, char, short, char, char, short, short, char, int, char, char, char, char, char, char, char, int, char, char, int, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_memRead_hw(char __xlx_apatb_param_data_dim1, char __xlx_apatb_param_data_dim2, short __xlx_apatb_param_data_dim1xdim2, char __xlx_apatb_param_weight_dim1, char __xlx_apatb_param_weight_dim2, short __xlx_apatb_param_weight_dim3, short __xlx_apatb_param_weight_dim4_div_lane, char __xlx_apatb_param_weight_dim1x2, int __xlx_apatb_param_weight_dim1x2x3, char __xlx_apatb_param_conv_x, char __xlx_apatb_param_stride, char __xlx_apatb_param_padding, char __xlx_apatb_param_split, char __xlx_apatb_param_group_num_x, char __xlx_apatb_param_group_num_y, char __xlx_apatb_param_group_rem_size_x, int __xlx_apatb_param_group_rem_size_xyz, char __xlx_apatb_param_win_size_x, char __xlx_apatb_param_win_size_y, int __xlx_apatb_param_win_size_xyz, volatile void * __xlx_apatb_param_bottom, volatile void * __xlx_apatb_param_weights, volatile void * __xlx_apatb_param_bias, volatile void * __xlx_apatb_param_bias_out, volatile void * __xlx_apatb_param_weight_out, volatile void * __xlx_apatb_param_data_out) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;{sc_bv<64> xlx_stream_bias_out_pc_buffer;
unsigned xlx_stream_bias_out_size = 0;

          std::vector<sc_bv<16> > bias_out_V_data_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_bias_out_V_data_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > bias_out_V_data_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "bias_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              bias_out_V_data_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_bias_out_size=bias_out_V_data_V_pc_buffer.size();
bias_out_V_data_V_pc_buffer_Copy=bias_out_V_data_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<16> > bias_out_V_keep_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_bias_out_V_keep_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > bias_out_V_keep_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "bias_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              bias_out_V_keep_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_bias_out_size=bias_out_V_keep_V_pc_buffer.size();
bias_out_V_keep_V_pc_buffer_Copy=bias_out_V_keep_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<16> > bias_out_V_strb_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_bias_out_V_strb_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > bias_out_V_strb_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "bias_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              bias_out_V_strb_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_bias_out_size=bias_out_V_strb_V_pc_buffer.size();
bias_out_V_strb_V_pc_buffer_Copy=bias_out_V_strb_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<16> > bias_out_V_last_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_bias_out_V_last_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > bias_out_V_last_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "bias_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              bias_out_V_last_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_bias_out_size=bias_out_V_last_V_pc_buffer.size();
bias_out_V_last_V_pc_buffer_Copy=bias_out_V_last_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (int j = 0, e = xlx_stream_bias_out_size; j != e; ++j) {
xlx_stream_bias_out_pc_buffer.range(15, 0) = bias_out_V_data_V_pc_buffer_Copy[j];
xlx_stream_bias_out_pc_buffer.range(23, 16) = bias_out_V_keep_V_pc_buffer_Copy[j];
xlx_stream_bias_out_pc_buffer.range(31, 24) = bias_out_V_strb_V_pc_buffer_Copy[j];
xlx_stream_bias_out_pc_buffer.range(47, 40) = bias_out_V_last_V_pc_buffer_Copy[j];
__cosim_s8__ xlx_stream_elt;
((long long*)&xlx_stream_elt)[0] = xlx_stream_bias_out_pc_buffer.to_int64();
((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_out)->write(xlx_stream_elt);
}}{sc_bv<128> xlx_stream_weight_out_pc_buffer;
unsigned xlx_stream_weight_out_size = 0;

          std::vector<sc_bv<64> > weight_out_V_data_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_weight_out_V_data_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > weight_out_V_data_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "weight_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              weight_out_V_data_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_weight_out_size=weight_out_V_data_V_pc_buffer.size();
weight_out_V_data_V_pc_buffer_Copy=weight_out_V_data_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<64> > weight_out_V_keep_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_weight_out_V_keep_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > weight_out_V_keep_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "weight_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              weight_out_V_keep_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_weight_out_size=weight_out_V_keep_V_pc_buffer.size();
weight_out_V_keep_V_pc_buffer_Copy=weight_out_V_keep_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<64> > weight_out_V_strb_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_weight_out_V_strb_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > weight_out_V_strb_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "weight_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              weight_out_V_strb_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_weight_out_size=weight_out_V_strb_V_pc_buffer.size();
weight_out_V_strb_V_pc_buffer_Copy=weight_out_V_strb_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<64> > weight_out_V_last_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_weight_out_V_last_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > weight_out_V_last_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "weight_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              weight_out_V_last_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_weight_out_size=weight_out_V_last_V_pc_buffer.size();
weight_out_V_last_V_pc_buffer_Copy=weight_out_V_last_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (int j = 0, e = xlx_stream_weight_out_size; j != e; ++j) {
xlx_stream_weight_out_pc_buffer.range(63, 0) = weight_out_V_data_V_pc_buffer_Copy[j];
xlx_stream_weight_out_pc_buffer.range(71, 64) = weight_out_V_keep_V_pc_buffer_Copy[j];
xlx_stream_weight_out_pc_buffer.range(79, 72) = weight_out_V_strb_V_pc_buffer_Copy[j];
xlx_stream_weight_out_pc_buffer.range(95, 88) = weight_out_V_last_V_pc_buffer_Copy[j];
__cosim_s10__ xlx_stream_elt;
((long long*)&xlx_stream_elt)[0*2+0] = xlx_stream_weight_out_pc_buffer.range(63,0).to_int64();
((long long*)&xlx_stream_elt)[0*2+1] = xlx_stream_weight_out_pc_buffer.range(127,64).to_int64();
((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_out)->write(xlx_stream_elt);
}}{sc_bv<128> xlx_stream_data_out_pc_buffer;
unsigned xlx_stream_data_out_size = 0;

          std::vector<sc_bv<64> > data_out_V_data_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_data_out_V_data_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > data_out_V_data_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "data_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              data_out_V_data_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_data_out_size=data_out_V_data_V_pc_buffer.size();
data_out_V_data_V_pc_buffer_Copy=data_out_V_data_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<64> > data_out_V_keep_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_data_out_V_keep_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > data_out_V_keep_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "data_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              data_out_V_keep_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_data_out_size=data_out_V_keep_V_pc_buffer.size();
data_out_V_keep_V_pc_buffer_Copy=data_out_V_keep_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<64> > data_out_V_strb_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_data_out_V_strb_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > data_out_V_strb_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "data_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              data_out_V_strb_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_data_out_size=data_out_V_strb_V_pc_buffer.size();
data_out_V_strb_V_pc_buffer_Copy=data_out_V_strb_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<64> > data_out_V_last_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_data_out_V_last_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > data_out_V_last_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "data_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              data_out_V_last_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_data_out_size=data_out_V_last_V_pc_buffer.size();
data_out_V_last_V_pc_buffer_Copy=data_out_V_last_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (int j = 0, e = xlx_stream_data_out_size; j != e; ++j) {
xlx_stream_data_out_pc_buffer.range(63, 0) = data_out_V_data_V_pc_buffer_Copy[j];
xlx_stream_data_out_pc_buffer.range(71, 64) = data_out_V_keep_V_pc_buffer_Copy[j];
xlx_stream_data_out_pc_buffer.range(79, 72) = data_out_V_strb_V_pc_buffer_Copy[j];
xlx_stream_data_out_pc_buffer.range(95, 88) = data_out_V_last_V_pc_buffer_Copy[j];
__cosim_s10__ xlx_stream_elt;
((long long*)&xlx_stream_elt)[0*2+0] = xlx_stream_data_out_pc_buffer.range(63,0).to_int64();
((long long*)&xlx_stream_elt)[0*2+1] = xlx_stream_data_out_pc_buffer.range(127,64).to_int64();
((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_out)->write(xlx_stream_elt);
}}
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static AESL_FILE_HANDLER aesl_fh;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
//gmem0
aesl_fh.touch(AUTOTB_TVIN_gmem0);
aesl_fh.touch(AUTOTB_TVOUT_gmem0);
//gmem1
aesl_fh.touch(AUTOTB_TVIN_gmem1);
aesl_fh.touch(AUTOTB_TVOUT_gmem1);
//gmem2
aesl_fh.touch(AUTOTB_TVIN_gmem2);
aesl_fh.touch(AUTOTB_TVOUT_gmem2);
//data_dim1
aesl_fh.touch(AUTOTB_TVIN_data_dim1);
aesl_fh.touch(AUTOTB_TVOUT_data_dim1);
//data_dim2
aesl_fh.touch(AUTOTB_TVIN_data_dim2);
aesl_fh.touch(AUTOTB_TVOUT_data_dim2);
//data_dim1xdim2
aesl_fh.touch(AUTOTB_TVIN_data_dim1xdim2);
aesl_fh.touch(AUTOTB_TVOUT_data_dim1xdim2);
//weight_dim1
aesl_fh.touch(AUTOTB_TVIN_weight_dim1);
aesl_fh.touch(AUTOTB_TVOUT_weight_dim1);
//weight_dim2
aesl_fh.touch(AUTOTB_TVIN_weight_dim2);
aesl_fh.touch(AUTOTB_TVOUT_weight_dim2);
//weight_dim3
aesl_fh.touch(AUTOTB_TVIN_weight_dim3);
aesl_fh.touch(AUTOTB_TVOUT_weight_dim3);
//weight_dim4_div_lane
aesl_fh.touch(AUTOTB_TVIN_weight_dim4_div_lane);
aesl_fh.touch(AUTOTB_TVOUT_weight_dim4_div_lane);
//weight_dim1x2
aesl_fh.touch(AUTOTB_TVIN_weight_dim1x2);
aesl_fh.touch(AUTOTB_TVOUT_weight_dim1x2);
//weight_dim1x2x3
aesl_fh.touch(AUTOTB_TVIN_weight_dim1x2x3);
aesl_fh.touch(AUTOTB_TVOUT_weight_dim1x2x3);
//conv_x
aesl_fh.touch(AUTOTB_TVIN_conv_x);
aesl_fh.touch(AUTOTB_TVOUT_conv_x);
//stride
aesl_fh.touch(AUTOTB_TVIN_stride);
aesl_fh.touch(AUTOTB_TVOUT_stride);
//padding
aesl_fh.touch(AUTOTB_TVIN_padding);
aesl_fh.touch(AUTOTB_TVOUT_padding);
//split
aesl_fh.touch(AUTOTB_TVIN_split);
aesl_fh.touch(AUTOTB_TVOUT_split);
//group_num_x
aesl_fh.touch(AUTOTB_TVIN_group_num_x);
aesl_fh.touch(AUTOTB_TVOUT_group_num_x);
//group_num_y
aesl_fh.touch(AUTOTB_TVIN_group_num_y);
aesl_fh.touch(AUTOTB_TVOUT_group_num_y);
//group_rem_size_x
aesl_fh.touch(AUTOTB_TVIN_group_rem_size_x);
aesl_fh.touch(AUTOTB_TVOUT_group_rem_size_x);
//group_rem_size_xyz
aesl_fh.touch(AUTOTB_TVIN_group_rem_size_xyz);
aesl_fh.touch(AUTOTB_TVOUT_group_rem_size_xyz);
//win_size_x
aesl_fh.touch(AUTOTB_TVIN_win_size_x);
aesl_fh.touch(AUTOTB_TVOUT_win_size_x);
//win_size_y
aesl_fh.touch(AUTOTB_TVIN_win_size_y);
aesl_fh.touch(AUTOTB_TVOUT_win_size_y);
//win_size_xyz
aesl_fh.touch(AUTOTB_TVIN_win_size_xyz);
aesl_fh.touch(AUTOTB_TVOUT_win_size_xyz);
//bottom
aesl_fh.touch(AUTOTB_TVIN_bottom);
aesl_fh.touch(AUTOTB_TVOUT_bottom);
//weights
aesl_fh.touch(AUTOTB_TVIN_weights);
aesl_fh.touch(AUTOTB_TVOUT_weights);
//bias
aesl_fh.touch(AUTOTB_TVIN_bias);
aesl_fh.touch(AUTOTB_TVOUT_bias);
//bias_out
aesl_fh.touch(AUTOTB_TVIN_bias_out_V_data_V);
aesl_fh.touch(AUTOTB_TVOUT_bias_out_V_data_V);
aesl_fh.touch(AUTOTB_TVIN_bias_out_V_keep_V);
aesl_fh.touch(AUTOTB_TVOUT_bias_out_V_keep_V);
aesl_fh.touch(AUTOTB_TVIN_bias_out_V_strb_V);
aesl_fh.touch(AUTOTB_TVOUT_bias_out_V_strb_V);
aesl_fh.touch(AUTOTB_TVIN_bias_out_V_last_V);
aesl_fh.touch(AUTOTB_TVOUT_bias_out_V_last_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_bias_out_V_data_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_bias_out_V_data_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_bias_out_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_bias_out_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_bias_out_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_bias_out_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_bias_out_V_last_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_bias_out_V_last_V);
//weight_out
aesl_fh.touch(AUTOTB_TVIN_weight_out_V_data_V);
aesl_fh.touch(AUTOTB_TVOUT_weight_out_V_data_V);
aesl_fh.touch(AUTOTB_TVIN_weight_out_V_keep_V);
aesl_fh.touch(AUTOTB_TVOUT_weight_out_V_keep_V);
aesl_fh.touch(AUTOTB_TVIN_weight_out_V_strb_V);
aesl_fh.touch(AUTOTB_TVOUT_weight_out_V_strb_V);
aesl_fh.touch(AUTOTB_TVIN_weight_out_V_last_V);
aesl_fh.touch(AUTOTB_TVOUT_weight_out_V_last_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_weight_out_V_data_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_weight_out_V_data_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_weight_out_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_weight_out_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_weight_out_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_weight_out_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_weight_out_V_last_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_weight_out_V_last_V);
//data_out
aesl_fh.touch(AUTOTB_TVIN_data_out_V_data_V);
aesl_fh.touch(AUTOTB_TVOUT_data_out_V_data_V);
aesl_fh.touch(AUTOTB_TVIN_data_out_V_keep_V);
aesl_fh.touch(AUTOTB_TVOUT_data_out_V_keep_V);
aesl_fh.touch(AUTOTB_TVIN_data_out_V_strb_V);
aesl_fh.touch(AUTOTB_TVOUT_data_out_V_strb_V);
aesl_fh.touch(AUTOTB_TVIN_data_out_V_last_V);
aesl_fh.touch(AUTOTB_TVOUT_data_out_V_last_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_data_out_V_data_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_data_out_V_data_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_data_out_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_data_out_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_data_out_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_data_out_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_data_out_V_last_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_data_out_V_last_V);
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_bottom = 0;
// print gmem0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_gmem0, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_bottom = 0*4;
  if (__xlx_apatb_param_bottom) {
    for (int j = 0  - 0, e = 1 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_bottom)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_gmem0, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(1, &tcl_file.gmem0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_gmem0, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_weights = 0;
// print gmem1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_gmem1, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_weights = 0*8;
  if (__xlx_apatb_param_weights) {
    for (int j = 0  - 0, e = 1 - 0; j != e; ++j) {
sc_bv<64> __xlx_tmp_lv = ((long long*)__xlx_apatb_param_weights)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_gmem1, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(1, &tcl_file.gmem1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_gmem1, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_bias = 0;
// print gmem2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_gmem2, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_bias = 0*2;
  if (__xlx_apatb_param_bias) {
    for (int j = 0  - 0, e = 1 - 0; j != e; ++j) {
sc_bv<16> __xlx_tmp_lv = ((short*)__xlx_apatb_param_bias)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_gmem2, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(1, &tcl_file.gmem2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_gmem2, __xlx_sprintf_buffer.data());
}
// print data_dim1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_data_dim1, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_data_dim1);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_data_dim1, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.data_dim1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_data_dim1, __xlx_sprintf_buffer.data());
}
// print data_dim2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_data_dim2, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_data_dim2);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_data_dim2, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.data_dim2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_data_dim2, __xlx_sprintf_buffer.data());
}
// print data_dim1xdim2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_data_dim1xdim2, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_data_dim1xdim2);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_data_dim1xdim2, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.data_dim1xdim2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_data_dim1xdim2, __xlx_sprintf_buffer.data());
}
// print weight_dim1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weight_dim1, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_weight_dim1);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_weight_dim1, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.weight_dim1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weight_dim1, __xlx_sprintf_buffer.data());
}
// print weight_dim2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weight_dim2, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_weight_dim2);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_weight_dim2, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.weight_dim2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weight_dim2, __xlx_sprintf_buffer.data());
}
// print weight_dim3 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weight_dim3, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_weight_dim3);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_weight_dim3, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.weight_dim3_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weight_dim3, __xlx_sprintf_buffer.data());
}
// print weight_dim4_div_lane Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weight_dim4_div_lane, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_weight_dim4_div_lane);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_weight_dim4_div_lane, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.weight_dim4_div_lane_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weight_dim4_div_lane, __xlx_sprintf_buffer.data());
}
// print weight_dim1x2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weight_dim1x2, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_weight_dim1x2);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_weight_dim1x2, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.weight_dim1x2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weight_dim1x2, __xlx_sprintf_buffer.data());
}
// print weight_dim1x2x3 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weight_dim1x2x3, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_weight_dim1x2x3);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_weight_dim1x2x3, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.weight_dim1x2x3_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weight_dim1x2x3, __xlx_sprintf_buffer.data());
}
// print conv_x Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_conv_x, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_conv_x);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_conv_x, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.conv_x_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_conv_x, __xlx_sprintf_buffer.data());
}
// print stride Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_stride, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_stride);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_stride, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.stride_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_stride, __xlx_sprintf_buffer.data());
}
// print padding Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_padding, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_padding);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_padding, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.padding_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_padding, __xlx_sprintf_buffer.data());
}
// print split Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_split, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_split);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_split, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.split_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_split, __xlx_sprintf_buffer.data());
}
// print group_num_x Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_group_num_x, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_group_num_x);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_group_num_x, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.group_num_x_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_group_num_x, __xlx_sprintf_buffer.data());
}
// print group_num_y Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_group_num_y, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_group_num_y);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_group_num_y, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.group_num_y_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_group_num_y, __xlx_sprintf_buffer.data());
}
// print group_rem_size_x Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_group_rem_size_x, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_group_rem_size_x);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_group_rem_size_x, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.group_rem_size_x_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_group_rem_size_x, __xlx_sprintf_buffer.data());
}
// print group_rem_size_xyz Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_group_rem_size_xyz, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_group_rem_size_xyz);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_group_rem_size_xyz, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.group_rem_size_xyz_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_group_rem_size_xyz, __xlx_sprintf_buffer.data());
}
// print win_size_x Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_win_size_x, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_win_size_x);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_win_size_x, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.win_size_x_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_win_size_x, __xlx_sprintf_buffer.data());
}
// print win_size_y Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_win_size_y, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_win_size_y);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_win_size_y, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.win_size_y_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_win_size_y, __xlx_sprintf_buffer.data());
}
// print win_size_xyz Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_win_size_xyz, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_win_size_xyz);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_win_size_xyz, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.win_size_xyz_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_win_size_xyz, __xlx_sprintf_buffer.data());
}
// print bottom Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_bottom, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = __xlx_offset_byte_param_bottom;

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_bottom, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.bottom_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_bottom, __xlx_sprintf_buffer.data());
}
// print weights Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weights, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = __xlx_offset_byte_param_weights;

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_weights, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.weights_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weights, __xlx_sprintf_buffer.data());
}
// print bias Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_bias, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = __xlx_offset_byte_param_bias;

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_bias, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.bias_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_bias, __xlx_sprintf_buffer.data());
}
std::vector<__cosim_s8__> __xlx_apatb_param_bias_out_stream_buf;
long __xlx_apatb_param_bias_out_stream_buf_size = ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_out)->size();
std::vector<__cosim_s10__> __xlx_apatb_param_weight_out_stream_buf;
long __xlx_apatb_param_weight_out_stream_buf_size = ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_out)->size();
std::vector<__cosim_s10__> __xlx_apatb_param_data_out_stream_buf;
long __xlx_apatb_param_data_out_stream_buf_size = ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_out)->size();
CodeState = CALL_C_DUT;
memRead_hw_stub_wrapper(__xlx_apatb_param_data_dim1, __xlx_apatb_param_data_dim2, __xlx_apatb_param_data_dim1xdim2, __xlx_apatb_param_weight_dim1, __xlx_apatb_param_weight_dim2, __xlx_apatb_param_weight_dim3, __xlx_apatb_param_weight_dim4_div_lane, __xlx_apatb_param_weight_dim1x2, __xlx_apatb_param_weight_dim1x2x3, __xlx_apatb_param_conv_x, __xlx_apatb_param_stride, __xlx_apatb_param_padding, __xlx_apatb_param_split, __xlx_apatb_param_group_num_x, __xlx_apatb_param_group_num_y, __xlx_apatb_param_group_rem_size_x, __xlx_apatb_param_group_rem_size_xyz, __xlx_apatb_param_win_size_x, __xlx_apatb_param_win_size_y, __xlx_apatb_param_win_size_xyz, __xlx_apatb_param_bottom, __xlx_apatb_param_weights, __xlx_apatb_param_bias, __xlx_apatb_param_bias_out, __xlx_apatb_param_weight_out, __xlx_apatb_param_data_out);
CodeState = DUMP_OUTPUTS;

//********************** dump C output stream *******************
long __xlx_apatb_param_bias_out_stream_buf_final_size = ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_out)->size() - __xlx_apatb_param_bias_out_stream_buf_size;
{
  while (!((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_out)->empty())
    __xlx_apatb_param_bias_out_stream_buf.push_back(((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_out)->read());
  for (int i = 0; i < __xlx_apatb_param_bias_out_stream_buf.size(); ++i)
    ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_out)->write(__xlx_apatb_param_bias_out_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_bias_out_V_data_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_bias_out_V_keep_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_bias_out_V_strb_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_bias_out_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_bias_out_stream_buf_final_size; j != e; ++j) {
sc_bv<64> __xlx_tmp_lv = ((long long*)&__xlx_apatb_param_bias_out_stream_buf[__xlx_apatb_param_bias_out_stream_buf_size+j])[0];
sc_bv<16> __xlx_tmp_0_lv = __xlx_tmp_lv.range(15, 0);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_0_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_bias_out_V_data_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_1_lv = __xlx_tmp_lv.range(23, 16);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_1_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_bias_out_V_keep_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_2_lv = __xlx_tmp_lv.range(31, 24);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_2_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_bias_out_V_strb_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_4_lv = __xlx_tmp_lv.range(47, 40);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_4_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_bias_out_V_last_V, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_bias_out_stream_buf_final_size, &tcl_file.bias_out_V_data_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_bias_out_V_data_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_bias_out_stream_buf_final_size, &tcl_file.bias_out_V_keep_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_bias_out_V_keep_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_bias_out_stream_buf_final_size, &tcl_file.bias_out_V_strb_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_bias_out_V_strb_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_bias_out_stream_buf_final_size, &tcl_file.bias_out_V_last_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_bias_out_V_last_V, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_data_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_bias_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_data_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_data_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_keep_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_bias_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_keep_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_keep_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_strb_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_bias_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_strb_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_strb_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_last_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_bias_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_last_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_bias_out_V_last_V, __xlx_sprintf_buffer.data());
}
//********************** dump C output stream *******************
long __xlx_apatb_param_weight_out_stream_buf_final_size = ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_out)->size() - __xlx_apatb_param_weight_out_stream_buf_size;
{
  while (!((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_out)->empty())
    __xlx_apatb_param_weight_out_stream_buf.push_back(((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_out)->read());
  for (int i = 0; i < __xlx_apatb_param_weight_out_stream_buf.size(); ++i)
    ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_out)->write(__xlx_apatb_param_weight_out_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_weight_out_V_data_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_weight_out_V_keep_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_weight_out_V_strb_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_weight_out_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_weight_out_stream_buf_final_size; j != e; ++j) {
sc_bv<128> __xlx_tmp_lv;
__xlx_tmp_lv.range(63,0) = ((long long*)&__xlx_apatb_param_weight_out_stream_buf[__xlx_apatb_param_weight_out_stream_buf_size+j])[0*2+0];
__xlx_tmp_lv.range(127,64) = ((long long*)&__xlx_apatb_param_weight_out_stream_buf[__xlx_apatb_param_weight_out_stream_buf_size+j])[0*2+1];
sc_bv<64> __xlx_tmp_0_lv = __xlx_tmp_lv.range(63, 0);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_0_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_weight_out_V_data_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_1_lv = __xlx_tmp_lv.range(71, 64);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_1_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_weight_out_V_keep_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_2_lv = __xlx_tmp_lv.range(79, 72);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_2_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_weight_out_V_strb_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_4_lv = __xlx_tmp_lv.range(95, 88);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_4_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_weight_out_V_last_V, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_weight_out_stream_buf_final_size, &tcl_file.weight_out_V_data_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_weight_out_V_data_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_weight_out_stream_buf_final_size, &tcl_file.weight_out_V_keep_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_weight_out_V_keep_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_weight_out_stream_buf_final_size, &tcl_file.weight_out_V_strb_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_weight_out_V_strb_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_weight_out_stream_buf_final_size, &tcl_file.weight_out_V_last_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_weight_out_V_last_V, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_data_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_weight_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_data_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_data_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_keep_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_weight_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_keep_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_keep_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_strb_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_weight_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_strb_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_strb_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_last_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_weight_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_last_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_weight_out_V_last_V, __xlx_sprintf_buffer.data());
}
//********************** dump C output stream *******************
long __xlx_apatb_param_data_out_stream_buf_final_size = ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_out)->size() - __xlx_apatb_param_data_out_stream_buf_size;
{
  while (!((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_out)->empty())
    __xlx_apatb_param_data_out_stream_buf.push_back(((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_out)->read());
  for (int i = 0; i < __xlx_apatb_param_data_out_stream_buf.size(); ++i)
    ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_out)->write(__xlx_apatb_param_data_out_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_data_out_V_data_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_data_out_V_keep_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_data_out_V_strb_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_data_out_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_data_out_stream_buf_final_size; j != e; ++j) {
sc_bv<128> __xlx_tmp_lv;
__xlx_tmp_lv.range(63,0) = ((long long*)&__xlx_apatb_param_data_out_stream_buf[__xlx_apatb_param_data_out_stream_buf_size+j])[0*2+0];
__xlx_tmp_lv.range(127,64) = ((long long*)&__xlx_apatb_param_data_out_stream_buf[__xlx_apatb_param_data_out_stream_buf_size+j])[0*2+1];
sc_bv<64> __xlx_tmp_0_lv = __xlx_tmp_lv.range(63, 0);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_0_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_data_out_V_data_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_1_lv = __xlx_tmp_lv.range(71, 64);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_1_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_data_out_V_keep_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_2_lv = __xlx_tmp_lv.range(79, 72);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_2_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_data_out_V_strb_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_4_lv = __xlx_tmp_lv.range(95, 88);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_4_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_data_out_V_last_V, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_data_out_stream_buf_final_size, &tcl_file.data_out_V_data_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_data_out_V_data_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_data_out_stream_buf_final_size, &tcl_file.data_out_V_keep_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_data_out_V_keep_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_data_out_stream_buf_final_size, &tcl_file.data_out_V_strb_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_data_out_V_strb_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_data_out_stream_buf_final_size, &tcl_file.data_out_V_last_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_data_out_V_last_V, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_data_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_data_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_data_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_data_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_keep_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_data_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_keep_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_keep_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_strb_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_data_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_strb_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_strb_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_last_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_data_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_last_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_data_out_V_last_V, __xlx_sprintf_buffer.data());
}CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
