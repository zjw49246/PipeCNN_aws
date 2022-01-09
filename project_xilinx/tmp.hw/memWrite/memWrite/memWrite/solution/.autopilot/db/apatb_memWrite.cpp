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
#define AUTOTB_TVIN_gmem0 "../tv/cdatafile/c.memWrite.autotvin_gmem0.dat"
#define AUTOTB_TVOUT_gmem0 "../tv/cdatafile/c.memWrite.autotvout_gmem0.dat"
// wrapc file define:
#define AUTOTB_TVIN_out_dim1 "../tv/cdatafile/c.memWrite.autotvin_out_dim1.dat"
#define AUTOTB_TVOUT_out_dim1 "../tv/cdatafile/c.memWrite.autotvout_out_dim1.dat"
// wrapc file define:
#define AUTOTB_TVIN_out_dim2 "../tv/cdatafile/c.memWrite.autotvin_out_dim2.dat"
#define AUTOTB_TVOUT_out_dim2 "../tv/cdatafile/c.memWrite.autotvout_out_dim2.dat"
// wrapc file define:
#define AUTOTB_TVIN_out_dim3 "../tv/cdatafile/c.memWrite.autotvin_out_dim3.dat"
#define AUTOTB_TVOUT_out_dim3 "../tv/cdatafile/c.memWrite.autotvout_out_dim3.dat"
// wrapc file define:
#define AUTOTB_TVIN_out_dim1xbatch "../tv/cdatafile/c.memWrite.autotvin_out_dim1xbatch.dat"
#define AUTOTB_TVOUT_out_dim1xbatch "../tv/cdatafile/c.memWrite.autotvout_out_dim1xbatch.dat"
// wrapc file define:
#define AUTOTB_TVIN_out_dim1x2xbatch "../tv/cdatafile/c.memWrite.autotvin_out_dim1x2xbatch.dat"
#define AUTOTB_TVOUT_out_dim1x2xbatch "../tv/cdatafile/c.memWrite.autotvout_out_dim1x2xbatch.dat"
// wrapc file define:
#define AUTOTB_TVIN_batch_indx_dim1 "../tv/cdatafile/c.memWrite.autotvin_batch_indx_dim1.dat"
#define AUTOTB_TVOUT_batch_indx_dim1 "../tv/cdatafile/c.memWrite.autotvout_batch_indx_dim1.dat"
// wrapc file define:
#define AUTOTB_TVIN_batch_indx_dim2 "../tv/cdatafile/c.memWrite.autotvin_batch_indx_dim2.dat"
#define AUTOTB_TVOUT_batch_indx_dim2 "../tv/cdatafile/c.memWrite.autotvout_batch_indx_dim2.dat"
// wrapc file define:
#define AUTOTB_TVIN_padd_offset "../tv/cdatafile/c.memWrite.autotvin_padd_offset.dat"
#define AUTOTB_TVOUT_padd_offset "../tv/cdatafile/c.memWrite.autotvout_padd_offset.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_on "../tv/cdatafile/c.memWrite.autotvin_pool_on.dat"
#define AUTOTB_TVOUT_pool_on "../tv/cdatafile/c.memWrite.autotvout_pool_on.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_size "../tv/cdatafile/c.memWrite.autotvin_pool_size.dat"
#define AUTOTB_TVOUT_pool_size "../tv/cdatafile/c.memWrite.autotvout_pool_size.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_stride "../tv/cdatafile/c.memWrite.autotvin_pool_stride.dat"
#define AUTOTB_TVOUT_pool_stride "../tv/cdatafile/c.memWrite.autotvout_pool_stride.dat"
// wrapc file define:
#define AUTOTB_TVIN_top "../tv/cdatafile/c.memWrite.autotvin_top.dat"
#define AUTOTB_TVOUT_top "../tv/cdatafile/c.memWrite.autotvout_top.dat"
// wrapc file define:
#define AUTOTB_TVIN_conv_in_V_data_V "../tv/cdatafile/c.memWrite.autotvin_conv_in_V_data_V.dat"
#define AUTOTB_TVOUT_conv_in_V_data_V "../tv/cdatafile/c.memWrite.autotvout_conv_in_V_data_V.dat"
#define AUTOTB_TVIN_conv_in_V_keep_V "../tv/cdatafile/c.memWrite.autotvin_conv_in_V_keep_V.dat"
#define AUTOTB_TVOUT_conv_in_V_keep_V "../tv/cdatafile/c.memWrite.autotvout_conv_in_V_keep_V.dat"
#define AUTOTB_TVIN_conv_in_V_strb_V "../tv/cdatafile/c.memWrite.autotvin_conv_in_V_strb_V.dat"
#define AUTOTB_TVOUT_conv_in_V_strb_V "../tv/cdatafile/c.memWrite.autotvout_conv_in_V_strb_V.dat"
#define AUTOTB_TVIN_conv_in_V_last_V "../tv/cdatafile/c.memWrite.autotvin_conv_in_V_last_V.dat"
#define AUTOTB_TVOUT_conv_in_V_last_V "../tv/cdatafile/c.memWrite.autotvout_conv_in_V_last_V.dat"
#define WRAPC_STREAM_SIZE_IN_conv_in_V_data_V "../tv/stream_size/stream_size_in_conv_in_V_data_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_conv_in_V_data_V "../tv/stream_size/stream_ingress_status_conv_in_V_data_V.dat"
#define WRAPC_STREAM_SIZE_IN_conv_in_V_keep_V "../tv/stream_size/stream_size_in_conv_in_V_keep_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_conv_in_V_keep_V "../tv/stream_size/stream_ingress_status_conv_in_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_IN_conv_in_V_strb_V "../tv/stream_size/stream_size_in_conv_in_V_strb_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_conv_in_V_strb_V "../tv/stream_size/stream_ingress_status_conv_in_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_IN_conv_in_V_last_V "../tv/stream_size/stream_size_in_conv_in_V_last_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_conv_in_V_last_V "../tv/stream_size/stream_ingress_status_conv_in_V_last_V.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_gmem0 "../tv/rtldatafile/rtl.memWrite.autotvout_gmem0.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_out_dim1 "../tv/rtldatafile/rtl.memWrite.autotvout_out_dim1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_out_dim2 "../tv/rtldatafile/rtl.memWrite.autotvout_out_dim2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_out_dim3 "../tv/rtldatafile/rtl.memWrite.autotvout_out_dim3.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_out_dim1xbatch "../tv/rtldatafile/rtl.memWrite.autotvout_out_dim1xbatch.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_out_dim1x2xbatch "../tv/rtldatafile/rtl.memWrite.autotvout_out_dim1x2xbatch.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_batch_indx_dim1 "../tv/rtldatafile/rtl.memWrite.autotvout_batch_indx_dim1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_batch_indx_dim2 "../tv/rtldatafile/rtl.memWrite.autotvout_batch_indx_dim2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_padd_offset "../tv/rtldatafile/rtl.memWrite.autotvout_padd_offset.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_on "../tv/rtldatafile/rtl.memWrite.autotvout_pool_on.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_size "../tv/rtldatafile/rtl.memWrite.autotvout_pool_size.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_stride "../tv/rtldatafile/rtl.memWrite.autotvout_pool_stride.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_top "../tv/rtldatafile/rtl.memWrite.autotvout_top.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_conv_in_V_data_V "../tv/rtldatafile/rtl.memWrite.autotvout_conv_in_V_data_V.dat"
#define AUTOTB_TVOUT_PC_conv_in_V_keep_V "../tv/rtldatafile/rtl.memWrite.autotvout_conv_in_V_keep_V.dat"
#define AUTOTB_TVOUT_PC_conv_in_V_strb_V "../tv/rtldatafile/rtl.memWrite.autotvout_conv_in_V_strb_V.dat"
#define AUTOTB_TVOUT_PC_conv_in_V_last_V "../tv/rtldatafile/rtl.memWrite.autotvout_conv_in_V_last_V.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  gmem0_depth = 0;
  out_dim1_depth = 0;
  out_dim2_depth = 0;
  out_dim3_depth = 0;
  out_dim1xbatch_depth = 0;
  out_dim1x2xbatch_depth = 0;
  batch_indx_dim1_depth = 0;
  batch_indx_dim2_depth = 0;
  padd_offset_depth = 0;
  pool_on_depth = 0;
  pool_size_depth = 0;
  pool_stride_depth = 0;
  top_depth = 0;
  conv_in_V_data_V_depth = 0;
  conv_in_V_keep_V_depth = 0;
  conv_in_V_strb_V_depth = 0;
  conv_in_V_last_V_depth = 0;
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
  total_list << "{out_dim1 " << out_dim1_depth << "}\n";
  total_list << "{out_dim2 " << out_dim2_depth << "}\n";
  total_list << "{out_dim3 " << out_dim3_depth << "}\n";
  total_list << "{out_dim1xbatch " << out_dim1xbatch_depth << "}\n";
  total_list << "{out_dim1x2xbatch " << out_dim1x2xbatch_depth << "}\n";
  total_list << "{batch_indx_dim1 " << batch_indx_dim1_depth << "}\n";
  total_list << "{batch_indx_dim2 " << batch_indx_dim2_depth << "}\n";
  total_list << "{padd_offset " << padd_offset_depth << "}\n";
  total_list << "{pool_on " << pool_on_depth << "}\n";
  total_list << "{pool_size " << pool_size_depth << "}\n";
  total_list << "{pool_stride " << pool_stride_depth << "}\n";
  total_list << "{top " << top_depth << "}\n";
  total_list << "{conv_in_V_data_V " << conv_in_V_data_V_depth << "}\n";
  total_list << "{conv_in_V_keep_V " << conv_in_V_keep_V_depth << "}\n";
  total_list << "{conv_in_V_strb_V " << conv_in_V_strb_V_depth << "}\n";
  total_list << "{conv_in_V_last_V " << conv_in_V_last_V_depth << "}\n";
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
    int out_dim1_depth;
    int out_dim2_depth;
    int out_dim3_depth;
    int out_dim1xbatch_depth;
    int out_dim1x2xbatch_depth;
    int batch_indx_dim1_depth;
    int batch_indx_dim2_depth;
    int padd_offset_depth;
    int pool_on_depth;
    int pool_size_depth;
    int pool_stride_depth;
    int top_depth;
    int conv_in_V_data_V_depth;
    int conv_in_V_keep_V_depth;
    int conv_in_V_strb_V_depth;
    int conv_in_V_last_V_depth;
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
extern "C" void memWrite_hw_stub_wrapper(char, char, short, short, int, char, char, char, char, char, char, volatile void *, volatile void *);

extern "C" void apatb_memWrite_hw(char __xlx_apatb_param_out_dim1, char __xlx_apatb_param_out_dim2, short __xlx_apatb_param_out_dim3, short __xlx_apatb_param_out_dim1xbatch, int __xlx_apatb_param_out_dim1x2xbatch, char __xlx_apatb_param_batch_indx_dim1, char __xlx_apatb_param_batch_indx_dim2, char __xlx_apatb_param_padd_offset, char __xlx_apatb_param_pool_on, char __xlx_apatb_param_pool_size, char __xlx_apatb_param_pool_stride, volatile void * __xlx_apatb_param_top, volatile void * __xlx_apatb_param_conv_in) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_gmem0);
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
          std::vector<sc_bv<8> > gmem0_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "gmem0");
  
            // push token into output port buffer
            if (AESL_token != "") {
              gmem0_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {
            ((char*)__xlx_apatb_param_top)[j] = gmem0_pc_buffer[i].to_int64();
          }}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_conv_in_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_conv_in_V_data_V);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_conv_in_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_conv_in_stream_buf_final_size; ++i)((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_in)->read();

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
//out_dim1
aesl_fh.touch(AUTOTB_TVIN_out_dim1);
aesl_fh.touch(AUTOTB_TVOUT_out_dim1);
//out_dim2
aesl_fh.touch(AUTOTB_TVIN_out_dim2);
aesl_fh.touch(AUTOTB_TVOUT_out_dim2);
//out_dim3
aesl_fh.touch(AUTOTB_TVIN_out_dim3);
aesl_fh.touch(AUTOTB_TVOUT_out_dim3);
//out_dim1xbatch
aesl_fh.touch(AUTOTB_TVIN_out_dim1xbatch);
aesl_fh.touch(AUTOTB_TVOUT_out_dim1xbatch);
//out_dim1x2xbatch
aesl_fh.touch(AUTOTB_TVIN_out_dim1x2xbatch);
aesl_fh.touch(AUTOTB_TVOUT_out_dim1x2xbatch);
//batch_indx_dim1
aesl_fh.touch(AUTOTB_TVIN_batch_indx_dim1);
aesl_fh.touch(AUTOTB_TVOUT_batch_indx_dim1);
//batch_indx_dim2
aesl_fh.touch(AUTOTB_TVIN_batch_indx_dim2);
aesl_fh.touch(AUTOTB_TVOUT_batch_indx_dim2);
//padd_offset
aesl_fh.touch(AUTOTB_TVIN_padd_offset);
aesl_fh.touch(AUTOTB_TVOUT_padd_offset);
//pool_on
aesl_fh.touch(AUTOTB_TVIN_pool_on);
aesl_fh.touch(AUTOTB_TVOUT_pool_on);
//pool_size
aesl_fh.touch(AUTOTB_TVIN_pool_size);
aesl_fh.touch(AUTOTB_TVOUT_pool_size);
//pool_stride
aesl_fh.touch(AUTOTB_TVIN_pool_stride);
aesl_fh.touch(AUTOTB_TVOUT_pool_stride);
//top
aesl_fh.touch(AUTOTB_TVIN_top);
aesl_fh.touch(AUTOTB_TVOUT_top);
//conv_in
aesl_fh.touch(AUTOTB_TVIN_conv_in_V_data_V);
aesl_fh.touch(AUTOTB_TVOUT_conv_in_V_data_V);
aesl_fh.touch(AUTOTB_TVIN_conv_in_V_keep_V);
aesl_fh.touch(AUTOTB_TVOUT_conv_in_V_keep_V);
aesl_fh.touch(AUTOTB_TVIN_conv_in_V_strb_V);
aesl_fh.touch(AUTOTB_TVOUT_conv_in_V_strb_V);
aesl_fh.touch(AUTOTB_TVIN_conv_in_V_last_V);
aesl_fh.touch(AUTOTB_TVOUT_conv_in_V_last_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_conv_in_V_data_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_data_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_conv_in_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_conv_in_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_conv_in_V_last_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_last_V);
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_top = 0;
// print gmem0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_gmem0, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_top = 0*1;
  if (__xlx_apatb_param_top) {
    for (int j = 0  - 0, e = 1 - 0; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)__xlx_apatb_param_top)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_gmem0, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(1, &tcl_file.gmem0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_gmem0, __xlx_sprintf_buffer.data());
}
// print out_dim1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_out_dim1, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_out_dim1);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_out_dim1, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.out_dim1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_out_dim1, __xlx_sprintf_buffer.data());
}
// print out_dim2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_out_dim2, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_out_dim2);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_out_dim2, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.out_dim2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_out_dim2, __xlx_sprintf_buffer.data());
}
// print out_dim3 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_out_dim3, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_out_dim3);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_out_dim3, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.out_dim3_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_out_dim3, __xlx_sprintf_buffer.data());
}
// print out_dim1xbatch Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_out_dim1xbatch, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_out_dim1xbatch);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_out_dim1xbatch, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.out_dim1xbatch_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_out_dim1xbatch, __xlx_sprintf_buffer.data());
}
// print out_dim1x2xbatch Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_out_dim1x2xbatch, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_out_dim1x2xbatch);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_out_dim1x2xbatch, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.out_dim1x2xbatch_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_out_dim1x2xbatch, __xlx_sprintf_buffer.data());
}
// print batch_indx_dim1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_batch_indx_dim1, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_batch_indx_dim1);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_batch_indx_dim1, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.batch_indx_dim1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_batch_indx_dim1, __xlx_sprintf_buffer.data());
}
// print batch_indx_dim2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_batch_indx_dim2, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_batch_indx_dim2);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_batch_indx_dim2, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.batch_indx_dim2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_batch_indx_dim2, __xlx_sprintf_buffer.data());
}
// print padd_offset Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_padd_offset, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_padd_offset);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_padd_offset, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.padd_offset_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_padd_offset, __xlx_sprintf_buffer.data());
}
// print pool_on Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_pool_on, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_pool_on);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_pool_on, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.pool_on_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_pool_on, __xlx_sprintf_buffer.data());
}
// print pool_size Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_pool_size, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_pool_size);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_pool_size, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.pool_size_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_pool_size, __xlx_sprintf_buffer.data());
}
// print pool_stride Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_pool_stride, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_pool_stride);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_pool_stride, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.pool_stride_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_pool_stride, __xlx_sprintf_buffer.data());
}
// print top Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_top, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = __xlx_offset_byte_param_top;

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_top, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.top_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_top, __xlx_sprintf_buffer.data());
}
std::vector<__cosim_s8__> __xlx_apatb_param_conv_in_stream_buf;
{
  while (!((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_in)->empty())
    __xlx_apatb_param_conv_in_stream_buf.push_back(((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_in)->read());
  for (int i = 0; i < __xlx_apatb_param_conv_in_stream_buf.size(); ++i)
    ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_in)->write(__xlx_apatb_param_conv_in_stream_buf[i]);
  }
long __xlx_apatb_param_conv_in_stream_buf_size = ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_in)->size();
CodeState = CALL_C_DUT;
memWrite_hw_stub_wrapper(__xlx_apatb_param_out_dim1, __xlx_apatb_param_out_dim2, __xlx_apatb_param_out_dim3, __xlx_apatb_param_out_dim1xbatch, __xlx_apatb_param_out_dim1x2xbatch, __xlx_apatb_param_batch_indx_dim1, __xlx_apatb_param_batch_indx_dim2, __xlx_apatb_param_padd_offset, __xlx_apatb_param_pool_on, __xlx_apatb_param_pool_size, __xlx_apatb_param_pool_stride, __xlx_apatb_param_top, __xlx_apatb_param_conv_in);
CodeState = DUMP_OUTPUTS;
// print gmem0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_gmem0, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_top = 0*1;
  if (__xlx_apatb_param_top) {
    for (int j = 0  - 0, e = 1 - 0; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)__xlx_apatb_param_top)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_gmem0, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(1, &tcl_file.gmem0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_gmem0, __xlx_sprintf_buffer.data());
}
long __xlx_apatb_param_conv_in_stream_buf_final_size = __xlx_apatb_param_conv_in_stream_buf_size - ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_in)->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_conv_in_V_data_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_conv_in_V_keep_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_conv_in_V_strb_V, __xlx_sprintf_buffer.data());
  
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_conv_in_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_conv_in_stream_buf_final_size; j != e; ++j) {
sc_bv<64> __xlx_tmp_lv = ((long long*)&__xlx_apatb_param_conv_in_stream_buf[j])[0];
sc_bv<16> __xlx_tmp_0_lv = __xlx_tmp_lv.range(15, 0);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_0_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_conv_in_V_data_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_1_lv = __xlx_tmp_lv.range(23, 16);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_1_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_conv_in_V_keep_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_2_lv = __xlx_tmp_lv.range(31, 24);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_2_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_conv_in_V_strb_V, __xlx_sprintf_buffer.data());
sc_bv<8> __xlx_tmp_4_lv = __xlx_tmp_lv.range(47, 40);
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_4_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_conv_in_V_last_V, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_conv_in_stream_buf_final_size, &tcl_file.conv_in_V_data_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_conv_in_V_data_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_conv_in_stream_buf_final_size, &tcl_file.conv_in_V_keep_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_conv_in_V_keep_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_conv_in_stream_buf_final_size, &tcl_file.conv_in_V_strb_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_conv_in_V_strb_V, __xlx_sprintf_buffer.data());
tcl_file.set_num(__xlx_apatb_param_conv_in_stream_buf_final_size, &tcl_file.conv_in_V_last_V_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_conv_in_V_last_V, __xlx_sprintf_buffer.data());

// dump stream ingress status to file

// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_data_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_conv_in_stream_buf_final_size > 0) {
  long conv_in_V_data_V_stream_ingress_size = __xlx_apatb_param_conv_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_data_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_conv_in_stream_buf_final_size; j != e; j++) {
    conv_in_V_data_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_data_V, __xlx_sprintf_buffer.data());
  }
} else {
  long conv_in_V_data_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_data_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_data_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_keep_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_conv_in_stream_buf_final_size > 0) {
  long conv_in_V_keep_V_stream_ingress_size = __xlx_apatb_param_conv_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_keep_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_conv_in_stream_buf_final_size; j != e; j++) {
    conv_in_V_keep_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_keep_V, __xlx_sprintf_buffer.data());
  }
} else {
  long conv_in_V_keep_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_keep_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_keep_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_strb_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_conv_in_stream_buf_final_size > 0) {
  long conv_in_V_strb_V_stream_ingress_size = __xlx_apatb_param_conv_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_strb_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_conv_in_stream_buf_final_size; j != e; j++) {
    conv_in_V_strb_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_strb_V, __xlx_sprintf_buffer.data());
  }
} else {
  long conv_in_V_strb_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_strb_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_strb_V, __xlx_sprintf_buffer.data());
}
// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_last_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_conv_in_stream_buf_final_size > 0) {
  long conv_in_V_last_V_stream_ingress_size = __xlx_apatb_param_conv_in_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_conv_in_stream_buf_final_size; j != e; j++) {
    conv_in_V_last_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_last_V, __xlx_sprintf_buffer.data());
  }
} else {
  long conv_in_V_last_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", conv_in_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_last_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_conv_in_V_last_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_data_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_conv_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_data_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_data_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_keep_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_conv_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_keep_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_keep_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_strb_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_conv_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_strb_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_strb_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_last_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_conv_in_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_last_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_conv_in_V_last_V, __xlx_sprintf_buffer.data());
}CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
