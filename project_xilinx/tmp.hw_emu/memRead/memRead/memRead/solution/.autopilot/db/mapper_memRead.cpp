#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
unsigned int ap_apatb_bias_out_V_cap_bc;
static AESL_RUNTIME_BC __xlx_bias_out_V_size_Reader("../tv/stream_size/stream_size_out_bias_out_V.dat");
unsigned int ap_apatb_weight_out_V_cap_bc;
static AESL_RUNTIME_BC __xlx_weight_out_V_size_Reader("../tv/stream_size/stream_size_out_weight_out_V.dat");
unsigned int ap_apatb_data_out_V_cap_bc;
static AESL_RUNTIME_BC __xlx_data_out_V_size_Reader("../tv/stream_size/stream_size_out_data_out_V.dat");
struct __cosim_s8__ { char data[8]; };
struct __cosim_s10__ { char data[16]; };
extern "C" void memRead(int*, long long*, short*, char, char, short, char, char, short, short, char, int, char, char, char, char, char, char, char, int, char, char, int, int, int, int, __cosim_s8__*, __cosim_s10__*, __cosim_s10__*);
extern "C" void apatb_memRead_hw(char __xlx_apatb_param_data_dim1, char __xlx_apatb_param_data_dim2, short __xlx_apatb_param_data_dim1xdim2, char __xlx_apatb_param_weight_dim1, char __xlx_apatb_param_weight_dim2, short __xlx_apatb_param_weight_dim3, short __xlx_apatb_param_weight_dim4_div_lane, char __xlx_apatb_param_weight_dim1x2, int __xlx_apatb_param_weight_dim1x2x3, char __xlx_apatb_param_conv_x, char __xlx_apatb_param_stride, char __xlx_apatb_param_padding, char __xlx_apatb_param_split, char __xlx_apatb_param_group_num_x, char __xlx_apatb_param_group_num_y, char __xlx_apatb_param_group_rem_size_x, int __xlx_apatb_param_group_rem_size_xyz, char __xlx_apatb_param_win_size_x, char __xlx_apatb_param_win_size_y, int __xlx_apatb_param_win_size_xyz, volatile void * __xlx_apatb_param_bottom, volatile void * __xlx_apatb_param_weights, volatile void * __xlx_apatb_param_bias, volatile void * __xlx_apatb_param_bias_out, volatile void * __xlx_apatb_param_weight_out, volatile void * __xlx_apatb_param_data_out) {
  // Collect __xlx_bottom__tmp_vec
  vector<sc_bv<32> >__xlx_bottom__tmp_vec;
  for (int j = 0, e = 1; j != e; ++j) {
    __xlx_bottom__tmp_vec.push_back(((int*)__xlx_apatb_param_bottom)[j]);
  }
  int __xlx_size_param_bottom = 1;
  int __xlx_offset_param_bottom = 0;
  int __xlx_offset_byte_param_bottom = 0*4;
  int* __xlx_bottom__input_buffer= new int[__xlx_bottom__tmp_vec.size()];
  for (int i = 0; i < __xlx_bottom__tmp_vec.size(); ++i) {
    __xlx_bottom__input_buffer[i] = __xlx_bottom__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_weights__tmp_vec
  vector<sc_bv<64> >__xlx_weights__tmp_vec;
  for (int j = 0, e = 1; j != e; ++j) {
    __xlx_weights__tmp_vec.push_back(((long long*)__xlx_apatb_param_weights)[j]);
  }
  int __xlx_size_param_weights = 1;
  int __xlx_offset_param_weights = 0;
  int __xlx_offset_byte_param_weights = 0*8;
  long long* __xlx_weights__input_buffer= new long long[__xlx_weights__tmp_vec.size()];
  for (int i = 0; i < __xlx_weights__tmp_vec.size(); ++i) {
    __xlx_weights__input_buffer[i] = __xlx_weights__tmp_vec[i].range(63, 0).to_uint64();
  }
  // Collect __xlx_bias__tmp_vec
  vector<sc_bv<16> >__xlx_bias__tmp_vec;
  for (int j = 0, e = 1; j != e; ++j) {
    __xlx_bias__tmp_vec.push_back(((short*)__xlx_apatb_param_bias)[j]);
  }
  int __xlx_size_param_bias = 1;
  int __xlx_offset_param_bias = 0;
  int __xlx_offset_byte_param_bias = 0*2;
  short* __xlx_bias__input_buffer= new short[__xlx_bias__tmp_vec.size()];
  for (int i = 0; i < __xlx_bias__tmp_vec.size(); ++i) {
    __xlx_bias__input_buffer[i] = __xlx_bias__tmp_vec[i].range(15, 0).to_uint64();
  }
  //Create input buffer for bias_out
  ap_apatb_bias_out_V_cap_bc = __xlx_bias_out_V_size_Reader.read_size();
  __cosim_s8__* __xlx_bias_out_input_buffer= new __cosim_s8__[ap_apatb_bias_out_V_cap_bc];
  //Create input buffer for weight_out
  ap_apatb_weight_out_V_cap_bc = __xlx_weight_out_V_size_Reader.read_size();
  __cosim_s10__* __xlx_weight_out_input_buffer= new __cosim_s10__[ap_apatb_weight_out_V_cap_bc];
  //Create input buffer for data_out
  ap_apatb_data_out_V_cap_bc = __xlx_data_out_V_size_Reader.read_size();
  __cosim_s10__* __xlx_data_out_input_buffer= new __cosim_s10__[ap_apatb_data_out_V_cap_bc];
  // DUT call
  memRead(__xlx_bottom__input_buffer, __xlx_weights__input_buffer, __xlx_bias__input_buffer, __xlx_apatb_param_data_dim1, __xlx_apatb_param_data_dim2, __xlx_apatb_param_data_dim1xdim2, __xlx_apatb_param_weight_dim1, __xlx_apatb_param_weight_dim2, __xlx_apatb_param_weight_dim3, __xlx_apatb_param_weight_dim4_div_lane, __xlx_apatb_param_weight_dim1x2, __xlx_apatb_param_weight_dim1x2x3, __xlx_apatb_param_conv_x, __xlx_apatb_param_stride, __xlx_apatb_param_padding, __xlx_apatb_param_split, __xlx_apatb_param_group_num_x, __xlx_apatb_param_group_num_y, __xlx_apatb_param_group_rem_size_x, __xlx_apatb_param_group_rem_size_xyz, __xlx_apatb_param_win_size_x, __xlx_apatb_param_win_size_y, __xlx_apatb_param_win_size_xyz, __xlx_offset_byte_param_bottom, __xlx_offset_byte_param_weights, __xlx_offset_byte_param_bias, __xlx_bias_out_input_buffer, __xlx_weight_out_input_buffer, __xlx_data_out_input_buffer);
// print __xlx_apatb_param_bottom
  sc_bv<32>*__xlx_bottom_output_buffer = new sc_bv<32>[__xlx_size_param_bottom];
  for (int i = 0; i < __xlx_size_param_bottom; ++i) {
    __xlx_bottom_output_buffer[i] = __xlx_bottom__input_buffer[i+__xlx_offset_param_bottom];
  }
  for (int i = 0; i < __xlx_size_param_bottom; ++i) {
    ((int*)__xlx_apatb_param_bottom)[i] = __xlx_bottom_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_weights
  sc_bv<64>*__xlx_weights_output_buffer = new sc_bv<64>[__xlx_size_param_weights];
  for (int i = 0; i < __xlx_size_param_weights; ++i) {
    __xlx_weights_output_buffer[i] = __xlx_weights__input_buffer[i+__xlx_offset_param_weights];
  }
  for (int i = 0; i < __xlx_size_param_weights; ++i) {
    ((long long*)__xlx_apatb_param_weights)[i] = __xlx_weights_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_bias
  sc_bv<16>*__xlx_bias_output_buffer = new sc_bv<16>[__xlx_size_param_bias];
  for (int i = 0; i < __xlx_size_param_bias; ++i) {
    __xlx_bias_output_buffer[i] = __xlx_bias__input_buffer[i+__xlx_offset_param_bias];
  }
  for (int i = 0; i < __xlx_size_param_bias; ++i) {
    ((short*)__xlx_apatb_param_bias)[i] = __xlx_bias_output_buffer[i].to_uint64();
  }
  for (unsigned i = 0; i <ap_apatb_bias_out_V_cap_bc; ++i)
    ((hls::stream<__cosim_s8__>*)__xlx_apatb_param_bias_out)->write(__xlx_bias_out_input_buffer[i]);
  for (unsigned i = 0; i <ap_apatb_weight_out_V_cap_bc; ++i)
    ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_weight_out)->write(__xlx_weight_out_input_buffer[i]);
  for (unsigned i = 0; i <ap_apatb_data_out_V_cap_bc; ++i)
    ((hls::stream<__cosim_s10__>*)__xlx_apatb_param_data_out)->write(__xlx_data_out_input_buffer[i]);
}
