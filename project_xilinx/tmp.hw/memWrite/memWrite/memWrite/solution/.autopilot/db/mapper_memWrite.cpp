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
unsigned int ap_apatb_conv_in_V_cap_bc;
static AESL_RUNTIME_BC __xlx_conv_in_V_size_Reader("../tv/stream_size/stream_size_in_conv_in_V.dat");
struct __cosim_s8__ { char data[8]; };
extern "C" void memWrite(char*, char, char, short, short, int, char, char, char, char, char, char, int, __cosim_s8__*);
extern "C" void apatb_memWrite_hw(char __xlx_apatb_param_out_dim1, char __xlx_apatb_param_out_dim2, short __xlx_apatb_param_out_dim3, short __xlx_apatb_param_out_dim1xbatch, int __xlx_apatb_param_out_dim1x2xbatch, char __xlx_apatb_param_batch_indx_dim1, char __xlx_apatb_param_batch_indx_dim2, char __xlx_apatb_param_padd_offset, char __xlx_apatb_param_pool_on, char __xlx_apatb_param_pool_size, char __xlx_apatb_param_pool_stride, volatile void * __xlx_apatb_param_top, volatile void * __xlx_apatb_param_conv_in) {
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
  // collect __xlx_conv_in_tmp_vec
  unsigned __xlx_conv_in_V_tmp_Count = 0;
  unsigned __xlx_conv_in_V_read_Size = __xlx_conv_in_V_size_Reader.read_size();
  vector<__cosim_s8__> __xlx_conv_in_tmp_vec;
  while (!((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_in)->empty() && __xlx_conv_in_V_tmp_Count < __xlx_conv_in_V_read_Size) {
    __xlx_conv_in_tmp_vec.push_back(((hls::stream<__cosim_s8__>*)__xlx_apatb_param_conv_in)->read());
    __xlx_conv_in_V_tmp_Count++;
  }
  ap_apatb_conv_in_V_cap_bc = __xlx_conv_in_tmp_vec.size();
  // store input buffer
  __cosim_s8__* __xlx_conv_in_input_buffer= new __cosim_s8__[__xlx_conv_in_tmp_vec.size()];
  for (int i = 0; i < __xlx_conv_in_tmp_vec.size(); ++i) {
    __xlx_conv_in_input_buffer[i] = __xlx_conv_in_tmp_vec[i];
  }
  // DUT call
  memWrite(__xlx_top__input_buffer, __xlx_apatb_param_out_dim1, __xlx_apatb_param_out_dim2, __xlx_apatb_param_out_dim3, __xlx_apatb_param_out_dim1xbatch, __xlx_apatb_param_out_dim1x2xbatch, __xlx_apatb_param_batch_indx_dim1, __xlx_apatb_param_batch_indx_dim2, __xlx_apatb_param_padd_offset, __xlx_apatb_param_pool_on, __xlx_apatb_param_pool_size, __xlx_apatb_param_pool_stride, __xlx_offset_byte_param_top, __xlx_conv_in_input_buffer);
// print __xlx_apatb_param_top
  sc_bv<8>*__xlx_top_output_buffer = new sc_bv<8>[__xlx_size_param_top];
  for (int i = 0; i < __xlx_size_param_top; ++i) {
    __xlx_top_output_buffer[i] = __xlx_top__input_buffer[i+__xlx_offset_param_top];
  }
  for (int i = 0; i < __xlx_size_param_top; ++i) {
    ((char*)__xlx_apatb_param_top)[i] = __xlx_top_output_buffer[i].to_uint64();
  }
}
