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
#define AUTOTB_TVIN_gmem0 "../tv/cdatafile/c.maxPool.autotvin_gmem0.dat"
#define AUTOTB_TVOUT_gmem0 "../tv/cdatafile/c.maxPool.autotvout_gmem0.dat"
// wrapc file define:
#define AUTOTB_TVIN_gmem1 "../tv/cdatafile/c.maxPool.autotvin_gmem1.dat"
#define AUTOTB_TVOUT_gmem1 "../tv/cdatafile/c.maxPool.autotvout_gmem1.dat"
// wrapc file define:
#define AUTOTB_TVIN_conv_x "../tv/cdatafile/c.maxPool.autotvin_conv_x.dat"
#define AUTOTB_TVOUT_conv_x "../tv/cdatafile/c.maxPool.autotvout_conv_x.dat"
// wrapc file define:
#define AUTOTB_TVIN_conv_xy "../tv/cdatafile/c.maxPool.autotvin_conv_xy.dat"
#define AUTOTB_TVOUT_conv_xy "../tv/cdatafile/c.maxPool.autotvout_conv_xy.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_dim1 "../tv/cdatafile/c.maxPool.autotvin_pool_dim1.dat"
#define AUTOTB_TVOUT_pool_dim1 "../tv/cdatafile/c.maxPool.autotvout_pool_dim1.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_dim3 "../tv/cdatafile/c.maxPool.autotvin_pool_dim3.dat"
#define AUTOTB_TVOUT_pool_dim3 "../tv/cdatafile/c.maxPool.autotvout_pool_dim3.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_dim1x2 "../tv/cdatafile/c.maxPool.autotvin_pool_dim1x2.dat"
#define AUTOTB_TVOUT_pool_dim1x2 "../tv/cdatafile/c.maxPool.autotvout_pool_dim1x2.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_size "../tv/cdatafile/c.maxPool.autotvin_pool_size.dat"
#define AUTOTB_TVOUT_pool_size "../tv/cdatafile/c.maxPool.autotvout_pool_size.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_stride "../tv/cdatafile/c.maxPool.autotvin_pool_stride.dat"
#define AUTOTB_TVOUT_pool_stride "../tv/cdatafile/c.maxPool.autotvout_pool_stride.dat"
// wrapc file define:
#define AUTOTB_TVIN_padd_offset "../tv/cdatafile/c.maxPool.autotvin_padd_offset.dat"
#define AUTOTB_TVOUT_padd_offset "../tv/cdatafile/c.maxPool.autotvout_padd_offset.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_times "../tv/cdatafile/c.maxPool.autotvin_pool_times.dat"
#define AUTOTB_TVOUT_pool_times "../tv/cdatafile/c.maxPool.autotvout_pool_times.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_group "../tv/cdatafile/c.maxPool.autotvin_pool_group.dat"
#define AUTOTB_TVOUT_pool_group "../tv/cdatafile/c.maxPool.autotvout_pool_group.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_y_bound "../tv/cdatafile/c.maxPool.autotvin_pool_y_bound.dat"
#define AUTOTB_TVOUT_pool_y_bound "../tv/cdatafile/c.maxPool.autotvout_pool_y_bound.dat"
// wrapc file define:
#define AUTOTB_TVIN_item_loop_bound "../tv/cdatafile/c.maxPool.autotvin_item_loop_bound.dat"
#define AUTOTB_TVOUT_item_loop_bound "../tv/cdatafile/c.maxPool.autotvout_item_loop_bound.dat"
// wrapc file define:
#define AUTOTB_TVIN_load_data_bound "../tv/cdatafile/c.maxPool.autotvin_load_data_bound.dat"
#define AUTOTB_TVOUT_load_data_bound "../tv/cdatafile/c.maxPool.autotvout_load_data_bound.dat"
// wrapc file define:
#define AUTOTB_TVIN_write_back_bound "../tv/cdatafile/c.maxPool.autotvin_write_back_bound.dat"
#define AUTOTB_TVOUT_write_back_bound "../tv/cdatafile/c.maxPool.autotvout_write_back_bound.dat"
// wrapc file define:
#define AUTOTB_TVIN_pool_win_num_x "../tv/cdatafile/c.maxPool.autotvin_pool_win_num_x.dat"
#define AUTOTB_TVOUT_pool_win_num_x "../tv/cdatafile/c.maxPool.autotvout_pool_win_num_x.dat"
// wrapc file define:
#define AUTOTB_TVIN_win_size_x "../tv/cdatafile/c.maxPool.autotvin_win_size_x.dat"
#define AUTOTB_TVOUT_win_size_x "../tv/cdatafile/c.maxPool.autotvout_win_size_x.dat"
// wrapc file define:
#define AUTOTB_TVIN_bottom "../tv/cdatafile/c.maxPool.autotvin_bottom.dat"
#define AUTOTB_TVOUT_bottom "../tv/cdatafile/c.maxPool.autotvout_bottom.dat"
// wrapc file define:
#define AUTOTB_TVIN_top "../tv/cdatafile/c.maxPool.autotvin_top.dat"
#define AUTOTB_TVOUT_top "../tv/cdatafile/c.maxPool.autotvout_top.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_gmem0 "../tv/rtldatafile/rtl.maxPool.autotvout_gmem0.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_gmem1 "../tv/rtldatafile/rtl.maxPool.autotvout_gmem1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_conv_x "../tv/rtldatafile/rtl.maxPool.autotvout_conv_x.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_conv_xy "../tv/rtldatafile/rtl.maxPool.autotvout_conv_xy.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_dim1 "../tv/rtldatafile/rtl.maxPool.autotvout_pool_dim1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_dim3 "../tv/rtldatafile/rtl.maxPool.autotvout_pool_dim3.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_dim1x2 "../tv/rtldatafile/rtl.maxPool.autotvout_pool_dim1x2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_size "../tv/rtldatafile/rtl.maxPool.autotvout_pool_size.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_stride "../tv/rtldatafile/rtl.maxPool.autotvout_pool_stride.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_padd_offset "../tv/rtldatafile/rtl.maxPool.autotvout_padd_offset.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_times "../tv/rtldatafile/rtl.maxPool.autotvout_pool_times.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_group "../tv/rtldatafile/rtl.maxPool.autotvout_pool_group.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_y_bound "../tv/rtldatafile/rtl.maxPool.autotvout_pool_y_bound.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_item_loop_bound "../tv/rtldatafile/rtl.maxPool.autotvout_item_loop_bound.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_load_data_bound "../tv/rtldatafile/rtl.maxPool.autotvout_load_data_bound.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_write_back_bound "../tv/rtldatafile/rtl.maxPool.autotvout_write_back_bound.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pool_win_num_x "../tv/rtldatafile/rtl.maxPool.autotvout_pool_win_num_x.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_win_size_x "../tv/rtldatafile/rtl.maxPool.autotvout_win_size_x.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_bottom "../tv/rtldatafile/rtl.maxPool.autotvout_bottom.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_top "../tv/rtldatafile/rtl.maxPool.autotvout_top.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  gmem0_depth = 0;
  gmem1_depth = 0;
  conv_x_depth = 0;
  conv_xy_depth = 0;
  pool_dim1_depth = 0;
  pool_dim3_depth = 0;
  pool_dim1x2_depth = 0;
  pool_size_depth = 0;
  pool_stride_depth = 0;
  padd_offset_depth = 0;
  pool_times_depth = 0;
  pool_group_depth = 0;
  pool_y_bound_depth = 0;
  item_loop_bound_depth = 0;
  load_data_bound_depth = 0;
  write_back_bound_depth = 0;
  pool_win_num_x_depth = 0;
  win_size_x_depth = 0;
  bottom_depth = 0;
  top_depth = 0;
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
  total_list << "{conv_x " << conv_x_depth << "}\n";
  total_list << "{conv_xy " << conv_xy_depth << "}\n";
  total_list << "{pool_dim1 " << pool_dim1_depth << "}\n";
  total_list << "{pool_dim3 " << pool_dim3_depth << "}\n";
  total_list << "{pool_dim1x2 " << pool_dim1x2_depth << "}\n";
  total_list << "{pool_size " << pool_size_depth << "}\n";
  total_list << "{pool_stride " << pool_stride_depth << "}\n";
  total_list << "{padd_offset " << padd_offset_depth << "}\n";
  total_list << "{pool_times " << pool_times_depth << "}\n";
  total_list << "{pool_group " << pool_group_depth << "}\n";
  total_list << "{pool_y_bound " << pool_y_bound_depth << "}\n";
  total_list << "{item_loop_bound " << item_loop_bound_depth << "}\n";
  total_list << "{load_data_bound " << load_data_bound_depth << "}\n";
  total_list << "{write_back_bound " << write_back_bound_depth << "}\n";
  total_list << "{pool_win_num_x " << pool_win_num_x_depth << "}\n";
  total_list << "{win_size_x " << win_size_x_depth << "}\n";
  total_list << "{bottom " << bottom_depth << "}\n";
  total_list << "{top " << top_depth << "}\n";
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
    int conv_x_depth;
    int conv_xy_depth;
    int pool_dim1_depth;
    int pool_dim3_depth;
    int pool_dim1x2_depth;
    int pool_size_depth;
    int pool_stride_depth;
    int padd_offset_depth;
    int pool_times_depth;
    int pool_group_depth;
    int pool_y_bound_depth;
    int item_loop_bound_depth;
    int load_data_bound_depth;
    int write_back_bound_depth;
    int pool_win_num_x_depth;
    int win_size_x_depth;
    int bottom_depth;
    int top_depth;
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
extern "C" void maxPool_hw_stub_wrapper(char, short, char, short, short, char, char, char, short, short, short, short, short, short, char, char, volatile void *, volatile void *);

extern "C" void apatb_maxPool_hw(char __xlx_apatb_param_conv_x, short __xlx_apatb_param_conv_xy, char __xlx_apatb_param_pool_dim1, short __xlx_apatb_param_pool_dim3, short __xlx_apatb_param_pool_dim1x2, char __xlx_apatb_param_pool_size, char __xlx_apatb_param_pool_stride, char __xlx_apatb_param_padd_offset, short __xlx_apatb_param_pool_times, short __xlx_apatb_param_pool_group, short __xlx_apatb_param_pool_y_bound, short __xlx_apatb_param_item_loop_bound, short __xlx_apatb_param_load_data_bound, short __xlx_apatb_param_write_back_bound, char __xlx_apatb_param_pool_win_num_x, char __xlx_apatb_param_win_size_x, volatile void * __xlx_apatb_param_bottom, volatile void * __xlx_apatb_param_top) {
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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_gmem1);
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
          std::vector<sc_bv<8> > gmem1_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "gmem1");
  
            // push token into output port buffer
            if (AESL_token != "") {
              gmem1_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {
            ((char*)__xlx_apatb_param_top)[j] = gmem1_pc_buffer[i].to_int64();
          }}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
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
//conv_x
aesl_fh.touch(AUTOTB_TVIN_conv_x);
aesl_fh.touch(AUTOTB_TVOUT_conv_x);
//conv_xy
aesl_fh.touch(AUTOTB_TVIN_conv_xy);
aesl_fh.touch(AUTOTB_TVOUT_conv_xy);
//pool_dim1
aesl_fh.touch(AUTOTB_TVIN_pool_dim1);
aesl_fh.touch(AUTOTB_TVOUT_pool_dim1);
//pool_dim3
aesl_fh.touch(AUTOTB_TVIN_pool_dim3);
aesl_fh.touch(AUTOTB_TVOUT_pool_dim3);
//pool_dim1x2
aesl_fh.touch(AUTOTB_TVIN_pool_dim1x2);
aesl_fh.touch(AUTOTB_TVOUT_pool_dim1x2);
//pool_size
aesl_fh.touch(AUTOTB_TVIN_pool_size);
aesl_fh.touch(AUTOTB_TVOUT_pool_size);
//pool_stride
aesl_fh.touch(AUTOTB_TVIN_pool_stride);
aesl_fh.touch(AUTOTB_TVOUT_pool_stride);
//padd_offset
aesl_fh.touch(AUTOTB_TVIN_padd_offset);
aesl_fh.touch(AUTOTB_TVOUT_padd_offset);
//pool_times
aesl_fh.touch(AUTOTB_TVIN_pool_times);
aesl_fh.touch(AUTOTB_TVOUT_pool_times);
//pool_group
aesl_fh.touch(AUTOTB_TVIN_pool_group);
aesl_fh.touch(AUTOTB_TVOUT_pool_group);
//pool_y_bound
aesl_fh.touch(AUTOTB_TVIN_pool_y_bound);
aesl_fh.touch(AUTOTB_TVOUT_pool_y_bound);
//item_loop_bound
aesl_fh.touch(AUTOTB_TVIN_item_loop_bound);
aesl_fh.touch(AUTOTB_TVOUT_item_loop_bound);
//load_data_bound
aesl_fh.touch(AUTOTB_TVIN_load_data_bound);
aesl_fh.touch(AUTOTB_TVOUT_load_data_bound);
//write_back_bound
aesl_fh.touch(AUTOTB_TVIN_write_back_bound);
aesl_fh.touch(AUTOTB_TVOUT_write_back_bound);
//pool_win_num_x
aesl_fh.touch(AUTOTB_TVIN_pool_win_num_x);
aesl_fh.touch(AUTOTB_TVOUT_pool_win_num_x);
//win_size_x
aesl_fh.touch(AUTOTB_TVIN_win_size_x);
aesl_fh.touch(AUTOTB_TVOUT_win_size_x);
//bottom
aesl_fh.touch(AUTOTB_TVIN_bottom);
aesl_fh.touch(AUTOTB_TVOUT_bottom);
//top
aesl_fh.touch(AUTOTB_TVIN_top);
aesl_fh.touch(AUTOTB_TVOUT_top);
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_bottom = 0;
// print gmem0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_gmem0, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_bottom = 0*2;
  if (__xlx_apatb_param_bottom) {
    for (int j = 0  - 0, e = 1 - 0; j != e; ++j) {
sc_bv<16> __xlx_tmp_lv = ((short*)__xlx_apatb_param_bottom)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_gmem0, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(1, &tcl_file.gmem0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_gmem0, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_top = 0;
// print gmem1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_gmem1, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_top = 0*1;
  if (__xlx_apatb_param_top) {
    for (int j = 0  - 0, e = 1 - 0; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)__xlx_apatb_param_top)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_gmem1, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(1, &tcl_file.gmem1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_gmem1, __xlx_sprintf_buffer.data());
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
// print conv_xy Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_conv_xy, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_conv_xy);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_conv_xy, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.conv_xy_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_conv_xy, __xlx_sprintf_buffer.data());
}
// print pool_dim1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_pool_dim1, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_pool_dim1);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_pool_dim1, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.pool_dim1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_pool_dim1, __xlx_sprintf_buffer.data());
}
// print pool_dim3 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_pool_dim3, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_pool_dim3);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_pool_dim3, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.pool_dim3_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_pool_dim3, __xlx_sprintf_buffer.data());
}
// print pool_dim1x2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_pool_dim1x2, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_pool_dim1x2);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_pool_dim1x2, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.pool_dim1x2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_pool_dim1x2, __xlx_sprintf_buffer.data());
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
// print pool_times Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_pool_times, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_pool_times);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_pool_times, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.pool_times_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_pool_times, __xlx_sprintf_buffer.data());
}
// print pool_group Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_pool_group, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_pool_group);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_pool_group, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.pool_group_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_pool_group, __xlx_sprintf_buffer.data());
}
// print pool_y_bound Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_pool_y_bound, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_pool_y_bound);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_pool_y_bound, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.pool_y_bound_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_pool_y_bound, __xlx_sprintf_buffer.data());
}
// print item_loop_bound Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_item_loop_bound, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_item_loop_bound);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_item_loop_bound, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.item_loop_bound_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_item_loop_bound, __xlx_sprintf_buffer.data());
}
// print load_data_bound Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_load_data_bound, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_load_data_bound);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_load_data_bound, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.load_data_bound_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_load_data_bound, __xlx_sprintf_buffer.data());
}
// print write_back_bound Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_write_back_bound, __xlx_sprintf_buffer.data());
  {
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_write_back_bound);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_write_back_bound, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.write_back_bound_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_write_back_bound, __xlx_sprintf_buffer.data());
}
// print pool_win_num_x Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_pool_win_num_x, __xlx_sprintf_buffer.data());
  {
    sc_bv<8> __xlx_tmp_lv = *((char*)&__xlx_apatb_param_pool_win_num_x);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_pool_win_num_x, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.pool_win_num_x_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_pool_win_num_x, __xlx_sprintf_buffer.data());
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
CodeState = CALL_C_DUT;
maxPool_hw_stub_wrapper(__xlx_apatb_param_conv_x, __xlx_apatb_param_conv_xy, __xlx_apatb_param_pool_dim1, __xlx_apatb_param_pool_dim3, __xlx_apatb_param_pool_dim1x2, __xlx_apatb_param_pool_size, __xlx_apatb_param_pool_stride, __xlx_apatb_param_padd_offset, __xlx_apatb_param_pool_times, __xlx_apatb_param_pool_group, __xlx_apatb_param_pool_y_bound, __xlx_apatb_param_item_loop_bound, __xlx_apatb_param_load_data_bound, __xlx_apatb_param_write_back_bound, __xlx_apatb_param_pool_win_num_x, __xlx_apatb_param_win_size_x, __xlx_apatb_param_bottom, __xlx_apatb_param_top);
CodeState = DUMP_OUTPUTS;
// print gmem1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_gmem1, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_top = 0*1;
  if (__xlx_apatb_param_top) {
    for (int j = 0  - 0, e = 1 - 0; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)__xlx_apatb_param_top)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_gmem1, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(1, &tcl_file.gmem1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_gmem1, __xlx_sprintf_buffer.data());
}
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
