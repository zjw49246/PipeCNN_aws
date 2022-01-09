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
#define AUTOTB_TVIN_output_num "../tv/cdatafile/c.coreConv.autotvin_output_num.dat"
#define AUTOTB_TVOUT_output_num "../tv/cdatafile/c.coreConv.autotvout_output_num.dat"
// wrapc file define:
#define AUTOTB_TVIN_conv_loop_cnt "../tv/cdatafile/c.coreConv.autotvin_conv_loop_cnt.dat"
#define AUTOTB_TVOUT_conv_loop_cnt "../tv/cdatafile/c.coreConv.autotvout_conv_loop_cnt.dat"
// wrapc file define:
#define AUTOTB_TVIN_contol "../tv/cdatafile/c.coreConv.autotvin_contol.dat"
#define AUTOTB_TVOUT_contol "../tv/cdatafile/c.coreConv.autotvout_contol.dat"
// wrapc file define:
#define AUTOTB_TVIN_frac_w "../tv/cdatafile/c.coreConv.autotvin_frac_w.dat"
#define AUTOTB_TVOUT_frac_w "../tv/cdatafile/c.coreConv.autotvout_frac_w.dat"
// wrapc file define:
#define AUTOTB_TVIN_frac_din "../tv/cdatafile/c.coreConv.autotvin_frac_din.dat"
#define AUTOTB_TVOUT_frac_din "../tv/cdatafile/c.coreConv.autotvout_frac_din.dat"
// wrapc file define:
#define AUTOTB_TVIN_frac_dout "../tv/cdatafile/c.coreConv.autotvin_frac_dout.dat"
#define AUTOTB_TVOUT_frac_dout "../tv/cdatafile/c.coreConv.autotvout_frac_dout.dat"
// wrapc file define:
#define AUTOTB_TVIN_bias_in_V_data_V "../tv/cdatafile/c.coreConv.autotvin_bias_in_V_data_V.dat"
#define AUTOTB_TVOUT_bias_in_V_data_V "../tv/cdatafile/c.coreConv.autotvout_bias_in_V_data_V.dat"
#define AUTOTB_TVIN_bias_in_V_keep_V "../tv/cdatafile/c.coreConv.autotvin_bias_in_V_keep_V.dat"
#define AUTOTB_TVOUT_bias_in_V_keep_V "../tv/cdatafile/c.coreConv.autotvout_bias_in_V_keep_V.dat"
#define AUTOTB_TVIN_bias_in_V_strb_V "../tv/cdatafile/c.coreConv.autotvin_bias_in_V_strb_V.dat"
#define AUTOTB_TVOUT_bias_in_V_strb_V "../tv/cdatafile/c.coreConv.autotvout_bias_in_V_strb_V.dat"
#define AUTOTB_TVIN_bias_in_V_last_V "../tv/cdatafile/c.coreConv.autotvin_bias_in_V_last_V.dat"
#define AUTOTB_TVOUT_bias_in_V_last_V "../tv/cdatafile/c.coreConv.autotvout_bias_in_V_last_V.dat"
#define WRAPC_STREAM_SIZE_IN_bias_in_V_data_V "../tv/stream_size/stream_size_in_bias_in_V_data_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_bias_in_V_data_V "../tv/stream_size/stream_ingress_status_bias_in_V_data_V.dat"
#define WRAPC_STREAM_SIZE_IN_bias_in_V_keep_V "../tv/stream_size/stream_size_in_bias_in_V_keep_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_bias_in_V_keep_V "../tv/stream_size/stream_ingress_status_bias_in_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_IN_bias_in_V_strb_V "../tv/stream_size/stream_size_in_bias_in_V_strb_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_bias_in_V_strb_V "../tv/stream_size/stream_ingress_status_bias_in_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_IN_bias_in_V_last_V "../tv/stream_size/stream_size_in_bias_in_V_last_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_bias_in_V_last_V "../tv/stream_size/stream_ingress_status_bias_in_V_last_V.dat"
// wrapc file define:
#define AUTOTB_TVIN_weight_in_V_data_V "../tv/cdatafile/c.coreConv.autotvin_weight_in_V_data_V.dat"
#define AUTOTB_TVOUT_weight_in_V_data_V "../tv/cdatafile/c.coreConv.autotvout_weight_in_V_data_V.dat"
#define AUTOTB_TVIN_weight_in_V_keep_V "../tv/cdatafile/c.coreConv.autotvin_weight_in_V_keep_V.dat"
#define AUTOTB_TVOUT_weight_in_V_keep_V "../tv/cdatafile/c.coreConv.autotvout_weight_in_V_keep_V.dat"
#define AUTOTB_TVIN_weight_in_V_strb_V "../tv/cdatafile/c.coreConv.autotvin_weight_in_V_strb_V.dat"
#define AUTOTB_TVOUT_weight_in_V_strb_V "../tv/cdatafile/c.coreConv.autotvout_weight_in_V_strb_V.dat"
#define AUTOTB_TVIN_weight_in_V_last_V "../tv/cdatafile/c.coreConv.autotvin_weight_in_V_last_V.dat"
#define AUTOTB_TVOUT_weight_in_V_last_V "../tv/cdatafile/c.coreConv.autotvout_weight_in_V_last_V.dat"
#define WRAPC_STREAM_SIZE_IN_weight_in_V_data_V "../tv/stream_size/stream_size_in_weight_in_V_data_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_weight_in_V_data_V "../tv/stream_size/stream_ingress_status_weight_in_V_data_V.dat"
#define WRAPC_STREAM_SIZE_IN_weight_in_V_keep_V "../tv/stream_size/stream_size_in_weight_in_V_keep_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_weight_in_V_keep_V "../tv/stream_size/stream_ingress_status_weight_in_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_IN_weight_in_V_strb_V "../tv/stream_size/stream_size_in_weight_in_V_strb_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_weight_in_V_strb_V "../tv/stream_size/stream_ingress_status_weight_in_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_IN_weight_in_V_last_V "../tv/stream_size/stream_size_in_weight_in_V_last_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_weight_in_V_last_V "../tv/stream_size/stream_ingress_status_weight_in_V_last_V.dat"
// wrapc file define:
#define AUTOTB_TVIN_data_in_V_data_V "../tv/cdatafile/c.coreConv.autotvin_data_in_V_data_V.dat"
#define AUTOTB_TVOUT_data_in_V_data_V "../tv/cdatafile/c.coreConv.autotvout_data_in_V_data_V.dat"
#define AUTOTB_TVIN_data_in_V_keep_V "../tv/cdatafile/c.coreConv.autotvin_data_in_V_keep_V.dat"
#define AUTOTB_TVOUT_data_in_V_keep_V "../tv/cdatafile/c.coreConv.autotvout_data_in_V_keep_V.dat"
#define AUTOTB_TVIN_data_in_V_strb_V "../tv/cdatafile/c.coreConv.autotvin_data_in_V_strb_V.dat"
#define AUTOTB_TVOUT_data_in_V_strb_V "../tv/cdatafile/c.coreConv.autotvout_data_in_V_strb_V.dat"
#define AUTOTB_TVIN_data_in_V_last_V "../tv/cdatafile/c.coreConv.autotvin_data_in_V_last_V.dat"
#define AUTOTB_TVOUT_data_in_V_last_V "../tv/cdatafile/c.coreConv.autotvout_data_in_V_last_V.dat"
#define WRAPC_STREAM_SIZE_IN_data_in_V_data_V "../tv/stream_size/stream_size_in_data_in_V_data_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_data_in_V_data_V "../tv/stream_size/stream_ingress_status_data_in_V_data_V.dat"
#define WRAPC_STREAM_SIZE_IN_data_in_V_keep_V "../tv/stream_size/stream_size_in_data_in_V_keep_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_data_in_V_keep_V "../tv/stream_size/stream_ingress_status_data_in_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_IN_data_in_V_strb_V "../tv/stream_size/stream_size_in_data_in_V_strb_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_data_in_V_strb_V "../tv/stream_size/stream_ingress_status_data_in_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_IN_data_in_V_last_V "../tv/stream_size/stream_size_in_data_in_V_last_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_data_in_V_last_V "../tv/stream_size/stream_ingress_status_data_in_V_last_V.dat"
// wrapc file define:
#define AUTOTB_TVIN_conv_out_V_data_V "../tv/cdatafile/c.coreConv.autotvin_conv_out_V_data_V.dat"
#define AUTOTB_TVOUT_conv_out_V_data_V "../tv/cdatafile/c.coreConv.autotvout_conv_out_V_data_V.dat"
#define AUTOTB_TVIN_conv_out_V_keep_V "../tv/cdatafile/c.coreConv.autotvin_conv_out_V_keep_V.dat"
#define AUTOTB_TVOUT_conv_out_V_keep_V "../tv/cdatafile/c.coreConv.autotvout_conv_out_V_keep_V.dat"
#define AUTOTB_TVIN_conv_out_V_strb_V "../tv/cdatafile/c.coreConv.autotvin_conv_out_V_strb_V.dat"
#define AUTOTB_TVOUT_conv_out_V_strb_V "../tv/cdatafile/c.coreConv.autotvout_conv_out_V_strb_V.dat"
#define AUTOTB_TVIN_conv_out_V_last_V "../tv/cdatafile/c.coreConv.autotvin_conv_out_V_last_V.dat"
#define AUTOTB_TVOUT_conv_out_V_last_V "../tv/cdatafile/c.coreConv.autotvout_conv_out_V_last_V.dat"
#define WRAPC_STREAM_SIZE_OUT_conv_out_V_data_V "../tv/stream_size/stream_size_out_conv_out_V_data_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_conv_out_V_data_V "../tv/stream_size/stream_egress_status_conv_out_V_data_V.dat"
#define WRAPC_STREAM_SIZE_OUT_conv_out_V_keep_V "../tv/stream_size/stream_size_out_conv_out_V_keep_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_conv_out_V_keep_V "../tv/stream_size/stream_egress_status_conv_out_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_OUT_conv_out_V_strb_V "../tv/stream_size/stream_size_out_conv_out_V_strb_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_conv_out_V_strb_V "../tv/stream_size/stream_egress_status_conv_out_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_OUT_conv_out_V_last_V "../tv/stream_size/stream_size_out_conv_out_V_last_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_conv_out_V_last_V "../tv/stream_size/stream_egress_status_conv_out_V_last_V.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_output_num "../tv/rtldatafile/rtl.coreConv.autotvout_output_num.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_conv_loop_cnt "../tv/rtldatafile/rtl.coreConv.autotvout_conv_loop_cnt.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_contol "../tv/rtldatafile/rtl.coreConv.autotvout_contol.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_frac_w "../tv/rtldatafile/rtl.coreConv.autotvout_frac_w.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_frac_din "../tv/rtldatafile/rtl.coreConv.autotvout_frac_din.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_frac_dout "../tv/rtldatafile/rtl.coreConv.autotvout_frac_dout.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_bias_in_V_data_V "../tv/rtldatafile/rtl.coreConv.autotvout_bias_in_V_data_V.dat"
#define AUTOTB_TVOUT_PC_bias_in_V_keep_V "../tv/rtldatafile/rtl.coreConv.autotvout_bias_in_V_keep_V.dat"
#define AUTOTB_TVOUT_PC_bias_in_V_strb_V "../tv/rtldatafile/rtl.coreConv.autotvout_bias_in_V_strb_V.dat"
#define AUTOTB_TVOUT_PC_bias_in_V_last_V "../tv/rtldatafile/rtl.coreConv.autotvout_bias_in_V_last_V.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_weight_in_V_data_V "../tv/rtldatafile/rtl.coreConv.autotvout_weight_in_V_data_V.dat"
#define AUTOTB_TVOUT_PC_weight_in_V_keep_V "../tv/rtldatafile/rtl.coreConv.autotvout_weight_in_V_keep_V.dat"
#define AUTOTB_TVOUT_PC_weight_in_V_strb_V "../tv/rtldatafile/rtl.coreConv.autotvout_weight_in_V_strb_V.dat"
#define AUTOTB_TVOUT_PC_weight_in_V_last_V "../tv/rtldatafile/rtl.coreConv.autotvout_weight_in_V_last_V.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_data_in_V_data_V "../tv/rtldatafile/rtl.coreConv.autotvout_data_in_V_data_V.dat"
#define AUTOTB_TVOUT_PC_data_in_V_keep_V "../tv/rtldatafile/rtl.coreConv.autotvout_data_in_V_keep_V.dat"
#define AUTOTB_TVOUT_PC_data_in_V_strb_V "../tv/rtldatafile/rtl.coreConv.autotvout_data_in_V_strb_V.dat"
#define AUTOTB_TVOUT_PC_data_in_V_last_V "../tv/rtldatafile/rtl.coreConv.autotvout_data_in_V_last_V.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_conv_out_V_data_V "../tv/rtldatafile/rtl.coreConv.autotvout_conv_out_V_data_V.dat"
#define AUTOTB_TVOUT_PC_conv_out_V_keep_V "../tv/rtldatafile/rtl.coreConv.autotvout_conv_out_V_keep_V.dat"
#define AUTOTB_TVOUT_PC_conv_out_V_strb_V "../tv/rtldatafile/rtl.coreConv.autotvout_conv_out_V_strb_V.dat"
#define AUTOTB_TVOUT_PC_conv_out_V_last_V "../tv/rtldatafile/rtl.coreConv.autotvout_conv_out_V_last_V.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  output_num_depth = 0;
  conv_loop_cnt_depth = 0;
  contol_depth = 0;
  frac_w_depth = 0;
  frac_din_depth = 0;
  frac_dout_depth = 0;
  bias_in_V_data_V_depth = 0;
  bias_in_V_keep_V_depth = 0;
  bias_in_V_strb_V_depth = 0;
  bias_in_V_last_V_depth = 0;
  weight_in_V_data_V_depth = 0;
  weight_in_V_keep_V_depth = 0;
  weight_in_V_strb_V_depth = 0;
  weight_in_V_last_V_depth = 0;
  data_in_V_data_V_depth = 0;
  data_in_V_keep_V_depth = 0;
  data_in_V_strb_V_depth = 0;
  data_in_V_last_V_depth = 0;
  conv_out_V_data_V_depth = 0;
  conv_out_V_keep_V_depth = 0;
  conv_out_V_strb_V_depth = 0;
  conv_out_V_last_V_depth = 0;
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
  total_list << "{output_num " << output_num_depth << "}\n";
  total_list << "{conv_loop_cnt " << conv_loop_cnt_depth << "}\n";
  total_list << "{contol " << contol_depth << "}\n";
  total_list << "{frac_w " << frac_w_depth << "}\n";
  total_list << "{frac_din " << frac_din_depth << "}\n";
  total_list << "{frac_dout " << frac_dout_depth << "}\n";
  total_list << "{bias_in_V_data_V " << bias_in_V_data_V_depth << "}\n";
  total_list << "{bias_in_V_keep_V " << bias_in_V_keep_V_depth << "}\n";
  total_list << "{bias_in_V_strb_V " << bias_in_V_strb_V_depth << "}\n";
  total_list << "{bias_in_V_last_V " << bias_in_V_last_V_depth << "}\n";
  total_list << "{weight_in_V_data_V " << weight_in_V_data_V_depth << "}\n";
  total_list << "{weight_in_V_keep_V " << weight_in_V_keep_V_depth << "}\n";
  total_list << "{weight_in_V_strb_V " << weight_in_V_strb_V_depth << "}\n";
  total_list << "{weight_in_V_last_V " << weight_in_V_last_V_depth << "}\n";
  total_list << "{data_in_V_data_V " << data_in_V_data_V_depth << "}\n";
  total_list << "{data_in_V_keep_V " << data_in_V_keep_V_depth << "}\n";
  total_list << "{data_in_V_strb_V " << data_in_V_strb_V_depth << "}\n";
  total_list << "{data_in_V_last_V " << data_in_V_last_V_depth << "}\n";
  total_list << "{conv_out_V_data_V " << conv_out_V_data_V_depth << "}\n";
  total_list << "{conv_out_V_keep_V " << conv_out_V_keep_V_depth << "}\n";
  total_list << "{conv_out_V_strb_V " << conv_out_V_strb_V_depth << "}\n";
  total_list << "{conv_out_V_last_V " << conv_out_V_last_V_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int output_num_depth;
    int conv_loop_cnt_depth;
    int contol_depth;
    int frac_w_depth;
    int frac_din_depth;
    int frac_dout_depth;
    int bias_in_V_data_V_depth;
    int bias_in_V_keep_V_depth;
    int bias_in_V_strb_V_depth;
    int bias_in_V_last_V_depth;
    int weight_in_V_data_V_depth;
    int weight_in_V_keep_V_depth;
    int weight_in_V_strb_V_depth;
    int weight_in_V_last_V_depth;
    int data_in_V_data_V_depth;
    int data_in_V_keep_V_depth;
    int data_in_V_strb_V_depth;
    int data_in_V_last_V_depth;
    int conv_out_V_data_V_depth;
    int conv_out_V_keep_V_depth;
    int conv_out_V_strb_V_depth;
    int conv_out_V_last_V_depth;
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
extern "C" void coreConv_hw_stub_wrapper(int, int, int, char, char, char, volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_coreConv_hw(int __xlx_apatb_param_output_num, int __xlx_apatb_param_conv_loop_cnt, int __xlx_apatb_param_contol, char __xlx_apatb_param_frac_w, char __xlx_apatb_param_frac_din, char __xlx_apatb_param_frac_dout, volatile void * __xlx_apatb_param_bias_in, volatile void * __xlx_apatb_param_weight_in, volatile void * __xlx_apatb_param_data_in, volatile void * __xlx_apatb_param_conv_out) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;long __xlx_apatb_param_bias_in_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_bias_in_V_data_V);
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
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_bias_in_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_bias_in_stream_buf_final_size; ++i)((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_in)->read();
long __xlx_apatb_param_weight_in_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_weight_in_V_data_V);
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
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_weight_in_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_weight_in_stream_buf_final_size; ++i)((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_in)->read();
long __xlx_apatb_param_data_in_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_data_in_V_data_V);
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
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_data_in_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_data_in_stream_buf_final_size; ++i)((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_in)->read();
{sc_bv<64> xlx_stream_conv_out_pc_buffer;
unsigned xlx_stream_conv_out_size = 0;

          std::vector<sc_bv<16> > conv_out_V_data_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_conv_out_V_data_V);
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
          std::vector<sc_bv<16> > conv_out_V_data_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "conv_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              conv_out_V_data_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_conv_out_size=conv_out_V_data_V_pc_buffer.size();
conv_out_V_data_V_pc_buffer_Copy=conv_out_V_data_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<16> > conv_out_V_keep_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_conv_out_V_keep_V);
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
          std::vector<sc_bv<16> > conv_out_V_keep_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "conv_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              conv_out_V_keep_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_conv_out_size=conv_out_V_keep_V_pc_buffer.size();
conv_out_V_keep_V_pc_buffer_Copy=conv_out_V_keep_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<16> > conv_out_V_strb_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_conv_out_V_strb_V);
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
          std::vector<sc_bv<16> > conv_out_V_strb_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "conv_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              conv_out_V_strb_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_conv_out_size=conv_out_V_strb_V_pc_buffer.size();
conv_out_V_strb_V_pc_buffer_Copy=conv_out_V_strb_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<16> > conv_out_V_last_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_conv_out_V_last_V);
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
          std::vector<sc_bv<16> > conv_out_V_last_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "conv_out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              conv_out_V_last_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {xlx_stream_conv_out_size=conv_out_V_last_V_pc_buffer.size();
conv_out_V_last_V_pc_buffer_Copy=conv_out_V_last_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (int j = 0, e = xlx_stream_conv_out_size; j != e; ++j) {
xlx_stream_conv_out_pc_buffer.range(15, 0) = conv_out_V_data_V_pc_buffer_Copy[j];
xlx_stream_conv_out_pc_buffer.range(23, 16) = conv_out_V_keep_V_pc_buffer_Copy[j];
xlx_stream_conv_out_pc_buffer.range(31, 24) = conv_out_V_strb_V_pc_buffer_Copy[j];
xlx_stream_conv_out_pc_buffer.range(47, 40) = conv_out_V_last_V_pc_buffer_Copy[j];
__cosim_s8__ xlx_stream_elt;
((long long*)&xlx_stream_elt)[0] = xlx_stream_conv_out_pc_buffer.to_int64();
((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_out)->write(xlx_stream_elt);
}}
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static AESL_FILE_HANDLER aesl_fh;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
//output_num
aesl_fh.touch(AUTOTB_TVIN_output_num);
aesl_fh.touch(AUTOTB_TVOUT_output_num);
//conv_loop_cnt
aesl_fh.touch(AUTOTB_TVIN_conv_loop_cnt);
aesl_fh.touch(AUTOTB_TVOUT_conv_loop_cnt);
//contol
aesl_fh.touch(AUTOTB_TVIN_contol);
aesl_fh.touch(AUTOTB_TVOUT_contol);
//frac_w
aesl_fh.touch(AUTOTB_TVIN_frac_w);
aesl_fh.touch(AUTOTB_TVOUT_frac_w);
//frac_din
aesl_fh.touch(AUTOTB_TVIN_frac_din);
aesl_fh.touch(AUTOTB_TVOUT_frac_din);
//frac_dout
aesl_fh.touch(AUTOTB_TVIN_frac_dout);
aesl_fh.touch(AUTOTB_TVOUT_frac_dout);
//bias_in
aesl_fh.touch(AUTOTB_TVIN_bias_in_V_data_V);
aesl_fh.touch(AUTOTB_TVOUT_bias_in_V_data_V);
aesl_fh.touch(AUTOTB_TVIN_bias_in_V_keep_V);
aesl_fh.touch(AUTOTB_TVOUT_bias_in_V_keep_V);
aesl_fh.touch(AUTOTB_TVIN_bias_in_V_strb_V);
aesl_fh.touch(AUTOTB_TVOUT_bias_in_V_strb_V);
aesl_fh.touch(AUTOTB_TVIN_bias_in_V_last_V);
aesl_fh.touch(AUTOTB_TVOUT_bias_in_V_last_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_bias_in_V_data_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_data_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_bias_in_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_bias_in_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_bias_in_V_last_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_last_V);
//weight_in
aesl_fh.touch(AUTOTB_TVIN_weight_in_V_data_V);
aesl_fh.touch(AUTOTB_TVOUT_weight_in_V_data_V);
aesl_fh.touch(AUTOTB_TVIN_weight_in_V_keep_V);
aesl_fh.touch(AUTOTB_TVOUT_weight_in_V_keep_V);
aesl_fh.touch(AUTOTB_TVIN_weight_in_V_strb_V);
aesl_fh.touch(AUTOTB_TVOUT_weight_in_V_strb_V);
aesl_fh.touch(AUTOTB_TVIN_weight_in_V_last_V);
aesl_fh.touch(AUTOTB_TVOUT_weight_in_V_last_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_weight_in_V_data_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_data_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_weight_in_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_weight_in_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_weight_in_V_last_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_last_V);
//data_in
aesl_fh.touch(AUTOTB_TVIN_data_in_V_data_V);
aesl_fh.touch(AUTOTB_TVOUT_data_in_V_data_V);
aesl_fh.touch(AUTOTB_TVIN_data_in_V_keep_V);
aesl_fh.touch(AUTOTB_TVOUT_data_in_V_keep_V);
aesl_fh.touch(AUTOTB_TVIN_data_in_V_strb_V);
aesl_fh.touch(AUTOTB_TVOUT_data_in_V_strb_V);
aesl_fh.touch(AUTOTB_TVIN_data_in_V_last_V);
aesl_fh.touch(AUTOTB_TVOUT_data_in_V_last_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_data_in_V_data_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_data_in_V_data_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_data_in_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_data_in_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_data_in_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_data_in_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_data_in_V_last_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_data_in_V_last_V);
//conv_out
aesl_fh.touch(AUTOTB_TVIN_conv_out_V_data_V);
aesl_fh.touch(AUTOTB_TVOUT_conv_out_V_data_V);
aesl_fh.touch(AUTOTB_TVIN_conv_out_V_keep_V);
aesl_fh.touch(AUTOTB_TVOUT_conv_out_V_keep_V);
aesl_fh.touch(AUTOTB_TVIN_conv_out_V_strb_V);
aesl_fh.touch(AUTOTB_TVOUT_conv_out_V_strb_V);
aesl_fh.touch(AUTOTB_TVIN_conv_out_V_last_V);
aesl_fh.touch(AUTOTB_TVOUT_conv_out_V_last_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_conv_out_V_data_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_conv_out_V_data_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_conv_out_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_conv_out_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_conv_out_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_conv_out_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_conv_out_V_last_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_conv_out_V_last_V);
CodeState = DUMP_INPUTS;
// print output_num Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_output_num, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_output_num);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_output_num, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.output_num_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_output_num, __xlx_sprintf_buffer.data());
}
// print conv_loop_cnt Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_conv_loop_cnt, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_conv_loop_cnt);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_conv_loop_cnt, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.conv_loop_cnt_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_conv_loop_cnt, __xlx_sprintf_buffer.data());
}
// print contol Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_contol, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_contol);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_contol, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.contol_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_contol, __xlx_sprintf_buffer.data());
}
// print frac_w Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_frac_w, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_frac_w);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_frac_w, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.frac_w_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_frac_w, __xlx_sprintf_buffer.data());
}
// print frac_din Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_frac_din, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_frac_din);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_frac_din, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.frac_din_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_frac_din, __xlx_sprintf_buffer.data());
}
// print frac_dout Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_frac_dout, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_frac_dout);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_frac_dout, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.frac_dout_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_frac_dout, __xlx_sprintf_buffer.data());
}
std::vector<__cosim_s8__> __xlx_apatb_param_bias_in_stream_buf;
{
  while (!((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_in)->empty())
    __xlx_apatb_param_bias_in_stream_buf.push_back(((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_in)->read());
  for (int i = 0; i < __xlx_apatb_param_bias_in_stream_buf.size(); ++i)
    ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_in)->write(__xlx_apatb_param_bias_in_stream_buf[i]);
  }
long __xlx_apatb_param_bias_in_stream_buf_size = ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_in)->size();
std::vector<__cosim_s10__> __xlx_apatb_param_weight_in_stream_buf;
{
  while (!((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_in)->empty())
    __xlx_apatb_param_weight_in_stream_buf.push_back(((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_in)->read());
  for (int i = 0; i < __xlx_apatb_param_weight_in_stream_buf.size(); ++i)
    ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_in)->write(__xlx_apatb_param_weight_in_stream_buf[i]);
  }
long __xlx_apatb_param_weight_in_stream_buf_size = ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_in)->size();
std::vector<__cosim_s10__> __xlx_apatb_param_data_in_stream_buf;
{
  while (!((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_in)->empty())
    __xlx_apatb_param_data_in_stream_buf.push_back(((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_in)->read());
  for (int i = 0; i < __xlx_apatb_param_data_in_stream_buf.size(); ++i)
    ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_in)->write(__xlx_apatb_param_data_in_stream_buf[i]);
  }
long __xlx_apatb_param_data_in_stream_buf_size = ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_in)->size();
std::vector<__cosim_s8__> __xlx_apatb_param_conv_out_stream_buf;
long __xlx_apatb_param_conv_out_stream_buf_size = ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_out)->size();
CodeState = CALL_C_DUT;
coreConv_hw_stub_wrapper(__xlx_apatb_param_output_num, __xlx_apatb_param_conv_loop_cnt, __xlx_apatb_param_contol, __xlx_apatb_param_frac_w, __xlx_apatb_param_frac_din, __xlx_apatb_param_frac_dout, __xlx_apatb_param_bias_in, __xlx_apatb_param_weight_in, __xlx_apatb_param_data_in, __xlx_apatb_param_conv_out);
CodeState = DUMP_OUTPUTS;
long __xlx_apatb_param_bias_in_stream_buf_final_size = __xlx_apatb_param_bias_in_stream_buf_size - ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_in)->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_bias_in_V_data_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_bias_in_V_keep_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_bias_in_V_strb_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_bias_in_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_bias_in_stream_buf_final_size; j != e; ++j) {
sc_bv<64> __xlx_tmp_lv = ((long long*)&__xlx_apatb_param_bias_in_stream_buf[j])[0];
sc_bv<16> __xlx_tmp_0_lv = __xlx_tmp_lv.range(15, 0);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_0_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_bias_in_V_data_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_1_lv = __xlx_tmp_lv.range(23, 16);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_1_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_bias_in_V_keep_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_2_lv = __xlx_tmp_lv.range(31, 24);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_2_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_bias_in_V_strb_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_4_lv = __xlx_tmp_lv.range(47, 40);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_4_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_bias_in_V_last_V, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_bias_in_stream_buf_final_size, &tcl_file.bias_in_V_data_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_bias_in_V_data_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_bias_in_stream_buf_final_size, &tcl_file.bias_in_V_keep_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_bias_in_V_keep_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_bias_in_stream_buf_final_size, &tcl_file.bias_in_V_strb_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_bias_in_V_strb_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_bias_in_stream_buf_final_size, &tcl_file.bias_in_V_last_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_bias_in_V_last_V, __xlx_sprintf_buffer.data());

// dump stream ingress status to file

// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_data_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_bias_in_stream_buf_final_size > 0) {
  long bias_in_V_data_V_stream_ingress_size = __xlx_apatb_param_bias_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_data_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_bias_in_stream_buf_final_size; j != e; j++) {
    bias_in_V_data_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_data_V, __xlx_sprintf_buffer.data());
  }
} else {
  long bias_in_V_data_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_data_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_data_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_keep_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_bias_in_stream_buf_final_size > 0) {
  long bias_in_V_keep_V_stream_ingress_size = __xlx_apatb_param_bias_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_keep_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_bias_in_stream_buf_final_size; j != e; j++) {
    bias_in_V_keep_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_keep_V, __xlx_sprintf_buffer.data());
  }
} else {
  long bias_in_V_keep_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_keep_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_keep_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_strb_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_bias_in_stream_buf_final_size > 0) {
  long bias_in_V_strb_V_stream_ingress_size = __xlx_apatb_param_bias_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_strb_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_bias_in_stream_buf_final_size; j != e; j++) {
    bias_in_V_strb_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_strb_V, __xlx_sprintf_buffer.data());
  }
} else {
  long bias_in_V_strb_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_strb_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_strb_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_last_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_bias_in_stream_buf_final_size > 0) {
  long bias_in_V_last_V_stream_ingress_size = __xlx_apatb_param_bias_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_bias_in_stream_buf_final_size; j != e; j++) {
    bias_in_V_last_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_last_V, __xlx_sprintf_buffer.data());
  }
} else {
  long bias_in_V_last_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", bias_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_last_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_bias_in_V_last_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_data_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_bias_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_data_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_data_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_keep_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_bias_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_keep_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_keep_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_strb_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_bias_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_strb_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_strb_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_last_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_bias_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_last_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_bias_in_V_last_V, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_weight_in_stream_buf_final_size = __xlx_apatb_param_weight_in_stream_buf_size - ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_in)->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weight_in_V_data_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weight_in_V_keep_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weight_in_V_strb_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weight_in_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_weight_in_stream_buf_final_size; j != e; ++j) {
sc_bv<128> __xlx_tmp_lv;
__xlx_tmp_lv.range(63,0) = ((long long*)&__xlx_apatb_param_weight_in_stream_buf[j])[0*2+0];
__xlx_tmp_lv.range(127,64) = ((long long*)&__xlx_apatb_param_weight_in_stream_buf[j])[0*2+1];
sc_bv<64> __xlx_tmp_0_lv = __xlx_tmp_lv.range(63, 0);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_0_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_weight_in_V_data_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_1_lv = __xlx_tmp_lv.range(71, 64);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_1_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_weight_in_V_keep_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_2_lv = __xlx_tmp_lv.range(79, 72);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_2_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_weight_in_V_strb_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_4_lv = __xlx_tmp_lv.range(95, 88);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_4_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_weight_in_V_last_V, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_weight_in_stream_buf_final_size, &tcl_file.weight_in_V_data_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weight_in_V_data_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_weight_in_stream_buf_final_size, &tcl_file.weight_in_V_keep_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weight_in_V_keep_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_weight_in_stream_buf_final_size, &tcl_file.weight_in_V_strb_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weight_in_V_strb_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_weight_in_stream_buf_final_size, &tcl_file.weight_in_V_last_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weight_in_V_last_V, __xlx_sprintf_buffer.data());

// dump stream ingress status to file

// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_data_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_weight_in_stream_buf_final_size > 0) {
  long weight_in_V_data_V_stream_ingress_size = __xlx_apatb_param_weight_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_data_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_weight_in_stream_buf_final_size; j != e; j++) {
    weight_in_V_data_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_data_V, __xlx_sprintf_buffer.data());
  }
} else {
  long weight_in_V_data_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_data_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_data_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_keep_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_weight_in_stream_buf_final_size > 0) {
  long weight_in_V_keep_V_stream_ingress_size = __xlx_apatb_param_weight_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_keep_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_weight_in_stream_buf_final_size; j != e; j++) {
    weight_in_V_keep_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_keep_V, __xlx_sprintf_buffer.data());
  }
} else {
  long weight_in_V_keep_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_keep_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_keep_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_strb_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_weight_in_stream_buf_final_size > 0) {
  long weight_in_V_strb_V_stream_ingress_size = __xlx_apatb_param_weight_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_strb_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_weight_in_stream_buf_final_size; j != e; j++) {
    weight_in_V_strb_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_strb_V, __xlx_sprintf_buffer.data());
  }
} else {
  long weight_in_V_strb_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_strb_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_strb_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_last_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_weight_in_stream_buf_final_size > 0) {
  long weight_in_V_last_V_stream_ingress_size = __xlx_apatb_param_weight_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_weight_in_stream_buf_final_size; j != e; j++) {
    weight_in_V_last_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_last_V, __xlx_sprintf_buffer.data());
  }
} else {
  long weight_in_V_last_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_last_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_in_V_last_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_data_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_weight_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_data_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_data_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_keep_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_weight_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_keep_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_keep_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_strb_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_weight_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_strb_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_strb_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_last_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_weight_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_last_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_in_V_last_V, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_data_in_stream_buf_final_size = __xlx_apatb_param_data_in_stream_buf_size - ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_in)->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_data_in_V_data_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_data_in_V_keep_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_data_in_V_strb_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_data_in_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_data_in_stream_buf_final_size; j != e; ++j) {
sc_bv<128> __xlx_tmp_lv;
__xlx_tmp_lv.range(63,0) = ((long long*)&__xlx_apatb_param_data_in_stream_buf[j])[0*2+0];
__xlx_tmp_lv.range(127,64) = ((long long*)&__xlx_apatb_param_data_in_stream_buf[j])[0*2+1];
sc_bv<64> __xlx_tmp_0_lv = __xlx_tmp_lv.range(63, 0);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_0_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_data_in_V_data_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_1_lv = __xlx_tmp_lv.range(71, 64);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_1_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_data_in_V_keep_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_2_lv = __xlx_tmp_lv.range(79, 72);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_2_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_data_in_V_strb_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_4_lv = __xlx_tmp_lv.range(95, 88);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_4_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_data_in_V_last_V, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_data_in_stream_buf_final_size, &tcl_file.data_in_V_data_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_data_in_V_data_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_data_in_stream_buf_final_size, &tcl_file.data_in_V_keep_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_data_in_V_keep_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_data_in_stream_buf_final_size, &tcl_file.data_in_V_strb_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_data_in_V_strb_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_data_in_stream_buf_final_size, &tcl_file.data_in_V_last_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_data_in_V_last_V, __xlx_sprintf_buffer.data());

// dump stream ingress status to file

// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_data_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_data_in_stream_buf_final_size > 0) {
  long data_in_V_data_V_stream_ingress_size = __xlx_apatb_param_data_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_data_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_data_in_stream_buf_final_size; j != e; j++) {
    data_in_V_data_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_data_V, __xlx_sprintf_buffer.data());
  }
} else {
  long data_in_V_data_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_data_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_data_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_keep_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_data_in_stream_buf_final_size > 0) {
  long data_in_V_keep_V_stream_ingress_size = __xlx_apatb_param_data_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_keep_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_data_in_stream_buf_final_size; j != e; j++) {
    data_in_V_keep_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_keep_V, __xlx_sprintf_buffer.data());
  }
} else {
  long data_in_V_keep_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_keep_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_keep_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_strb_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_data_in_stream_buf_final_size > 0) {
  long data_in_V_strb_V_stream_ingress_size = __xlx_apatb_param_data_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_strb_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_data_in_stream_buf_final_size; j != e; j++) {
    data_in_V_strb_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_strb_V, __xlx_sprintf_buffer.data());
  }
} else {
  long data_in_V_strb_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_strb_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_strb_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_last_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_data_in_stream_buf_final_size > 0) {
  long data_in_V_last_V_stream_ingress_size = __xlx_apatb_param_data_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_data_in_stream_buf_final_size; j != e; j++) {
    data_in_V_last_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_last_V, __xlx_sprintf_buffer.data());
  }
} else {
  long data_in_V_last_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", data_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_last_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_data_in_V_last_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_data_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_data_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_data_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_data_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_keep_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_data_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_keep_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_keep_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_strb_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_data_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_strb_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_strb_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_last_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_data_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_last_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_data_in_V_last_V, __xlx_sprintf_buffer.data());
}
//********************** dump C output stream *******************
long __xlx_apatb_param_conv_out_stream_buf_final_size = ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_out)->size() - __xlx_apatb_param_conv_out_stream_buf_size;
{
  while (!((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_out)->empty())
    __xlx_apatb_param_conv_out_stream_buf.push_back(((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_out)->read());
  for (int i = 0; i < __xlx_apatb_param_conv_out_stream_buf.size(); ++i)
    ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_out)->write(__xlx_apatb_param_conv_out_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_conv_out_V_data_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_conv_out_V_keep_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_conv_out_V_strb_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_conv_out_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_conv_out_stream_buf_final_size; j != e; ++j) {
sc_bv<64> __xlx_tmp_lv = ((long long*)&__xlx_apatb_param_conv_out_stream_buf[__xlx_apatb_param_conv_out_stream_buf_size+j])[0];
sc_bv<16> __xlx_tmp_0_lv = __xlx_tmp_lv.range(15, 0);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_0_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_conv_out_V_data_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_1_lv = __xlx_tmp_lv.range(23, 16);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_1_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_conv_out_V_keep_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_2_lv = __xlx_tmp_lv.range(31, 24);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_2_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_conv_out_V_strb_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_4_lv = __xlx_tmp_lv.range(47, 40);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_4_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_conv_out_V_last_V, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_conv_out_stream_buf_final_size, &tcl_file.conv_out_V_data_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_conv_out_V_data_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_conv_out_stream_buf_final_size, &tcl_file.conv_out_V_keep_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_conv_out_V_keep_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_conv_out_stream_buf_final_size, &tcl_file.conv_out_V_strb_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_conv_out_V_strb_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_conv_out_stream_buf_final_size, &tcl_file.conv_out_V_last_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_conv_out_V_last_V, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_data_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_conv_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_data_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_data_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_keep_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_conv_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_keep_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_keep_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_strb_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_conv_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_strb_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_strb_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_last_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_conv_out_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_last_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_conv_out_V_last_V, __xlx_sprintf_buffer.data());
}CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
