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
extern "C" void maxPool(short*, char*, char, short, char, short, short, char, char, char, short, short, short, short, short, short, char, char, int, int);
extern "C" void apatb_maxPool_hw(char __xlx_apatb_param_conv_x, short __xlx_apatb_param_conv_xy, char __xlx_apatb_param_pool_dim1, short __xlx_apatb_param_pool_dim3, short __xlx_apatb_param_pool_dim1x2, char __xlx_apatb_param_pool_size, char __xlx_apatb_param_pool_stride, char __xlx_apatb_param_padd_offset, short __xlx_apatb_param_pool_times, short __xlx_apatb_param_pool_group, short __xlx_apatb_param_pool_y_bound, short __xlx_apatb_param_item_loop_bound, short __xlx_apatb_param_load_data_bound, short __xlx_apatb_param_write_back_bound, char __xlx_apatb_param_pool_win_num_x, char __xlx_apatb_param_win_size_x, volatile void * __xlx_apatb_param_bottom, volatile void * __xlx_apatb_param_top) {
  // Collect __xlx_bottom__tmp_vec
  vector<sc_bv<16> >__xlx_bottom__tmp_vec;
  for (int j = 0, e = 1; j != e; ++j) {
    __xlx_bottom__tmp_vec.push_back(((short*)__xlx_apatb_param_bottom)[j]);
  }
  int __xlx_size_param_bottom = 1;
  int __xlx_offset_param_bottom = 0;
  int __xlx_offset_byte_param_bottom = 0*2;
  short* __xlx_bottom__input_buffer= new short[__xlx_bottom__tmp_vec.size()];
  for (int i = 0; i < __xlx_bottom__tmp_vec.size(); ++i) {
    __xlx_bottom__input_buffer[i] = __xlx_bottom__tmp_vec[i].range(15, 0).to_uint64();
  }
  // Collect __xlx_top__tmp_vec
  vector<sc_bv<8> >__xlx_top__tmp_vec;
  for (int j = 0, e = 1; j != e; ++j) {
    __xlx_top__tmp_vec.push_back(((char*)__xlx_apatb_param_top)[j]);
  }
  int __xlx_size_param_top = 1;
  int __xlx_offset_param_top = 0;
  int __xlx_offset_byte_param_top = 0*1;
  char* __xlx_top__input_buffer= new char[__xlx_top__tmp_vec.size()];
  for (int i = 0; i < __xlx_top__tmp_vec.size(); ++i) {
    __xlx_top__input_buffer[i] = __xlx_top__tmp_vec[i].range(7, 0).to_uint64();
  }
  // DUT call
  maxPool(__xlx_bottom__input_buffer, __xlx_top__input_buffer, __xlx_apatb_param_conv_x, __xlx_apatb_param_conv_xy, __xlx_apatb_param_pool_dim1, __xlx_apatb_param_pool_dim3, __xlx_apatb_param_pool_dim1x2, __xlx_apatb_param_pool_size, __xlx_apatb_param_pool_stride, __xlx_apatb_param_padd_offset, __xlx_apatb_param_pool_times, __xlx_apatb_param_pool_group, __xlx_apatb_param_pool_y_bound, __xlx_apatb_param_item_loop_bound, __xlx_apatb_param_load_data_bound, __xlx_apatb_param_write_back_bound, __xlx_apatb_param_pool_win_num_x, __xlx_apatb_param_win_size_x, __xlx_offset_byte_param_bottom, __xlx_offset_byte_param_top);
// print __xlx_apatb_param_bottom
  sc_bv<16>*__xlx_bottom_output_buffer = new sc_bv<16>[__xlx_size_param_bottom];
  for (int i = 0; i < __xlx_size_param_bottom; ++i) {
    __xlx_bottom_output_buffer[i] = __xlx_bottom__input_buffer[i+__xlx_offset_param_bottom];
  }
  for (int i = 0; i < __xlx_size_param_bottom; ++i) {
    ((short*)__xlx_apatb_param_bottom)[i] = __xlx_bottom_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_top
  sc_bv<8>*__xlx_top_output_buffer = new sc_bv<8>[__xlx_size_param_top];
  for (int i = 0; i < __xlx_size_param_top; ++i) {
    __xlx_top_output_buffer[i] = __xlx_top__input_buffer[i+__xlx_offset_param_top];
  }
  for (int i = 0; i < __xlx_size_param_top; ++i) {
    ((char*)__xlx_apatb_param_top)[i] = __xlx_top_output_buffer[i].to_uint64();
  }
}
