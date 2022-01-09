; ModuleID = '/home/zhoujw/FPGA/PipeCNN/project_xilinx/tmp.hw/memRead/memRead/memRead/solution/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%struct.lane_data = type { [4 x i8] }
%struct.channel_vec = type { [2 x %struct.lane_data] }
%struct.channel_scal = type { [2 x i8] }
%"class.hls::stream" = type { %"struct.hls::axis" }
%"struct.hls::axis" = type { %struct.ap_uint, %struct.ap_uint.0, %struct.ap_uint.0, %struct.ap_uint.3, %struct.ap_uint.3, %struct.ap_uint.3, %struct.ap_uint.3 }
%struct.ap_uint = type { %struct.ap_int_base }
%struct.ap_int_base = type { %struct.ssdm_int }
%struct.ssdm_int = type { i16 }
%struct.ap_uint.0 = type { %struct.ap_int_base.1 }
%struct.ap_int_base.1 = type { %struct.ssdm_int.2 }
%struct.ssdm_int.2 = type { i2 }
%struct.ap_uint.3 = type { %struct.ap_int_base.4 }
%struct.ap_int_base.4 = type { %struct.ssdm_int.5 }
%struct.ssdm_int.5 = type { i1 }
%"class.hls::stream.6" = type { %"struct.hls::axis.7" }
%"struct.hls::axis.7" = type { %struct.ap_uint.8, %struct.ap_uint.11, %struct.ap_uint.11, %struct.ap_uint.3, %struct.ap_uint.3, %struct.ap_uint.3, %struct.ap_uint.3 }
%struct.ap_uint.8 = type { %struct.ap_int_base.9 }
%struct.ap_int_base.9 = type { %struct.ssdm_int.10 }
%struct.ssdm_int.10 = type { i64 }
%struct.ap_uint.11 = type { %struct.ap_int_base.12 }
%struct.ap_int_base.12 = type { %struct.ssdm_int.13 }
%struct.ssdm_int.13 = type { i8 }

; Function Attrs: noinline
define void @apatb_memRead_ir(i8 %data_dim1, i8 %data_dim2, i16 %data_dim1xdim2, i8 %weight_dim1, i8 %weight_dim2, i16 %weight_dim3, i16 %weight_dim4_div_lane, i8 %weight_dim1x2, i32 %weight_dim1x2x3, i8 %conv_x, i8 %stride, i8 %padding, i8 %split, i8 %group_num_x, i8 %group_num_y, i8 %group_rem_size_x, i32 %group_rem_size_xyz, i8 %win_size_x, i8 %win_size_y, i32 %win_size_xyz, %struct.lane_data* %bottom, %struct.channel_vec* %weights, %struct.channel_scal* %bias, %"class.hls::stream"* %bias_out, %"class.hls::stream.6"* %weight_out, %"class.hls::stream.6"* %data_out) local_unnamed_addr #0 {
entry:
  %bottom_copy = alloca %struct.lane_data, align 512
  %weights_copy = alloca %struct.channel_vec, align 512
  %bias_copy = alloca %struct.channel_scal, align 512
  %bias_out_copy = alloca %"class.hls::stream", align 512
  %weight_out_copy = alloca %"class.hls::stream.6", align 512
  %data_out_copy = alloca %"class.hls::stream.6", align 512
  call fastcc void @copy_in(%struct.lane_data* %bottom, %struct.lane_data* nonnull align 512 %bottom_copy, %struct.channel_vec* %weights, %struct.channel_vec* nonnull align 512 %weights_copy, %struct.channel_scal* %bias, %struct.channel_scal* nonnull align 512 %bias_copy, %"class.hls::stream"* %bias_out, %"class.hls::stream"* nonnull align 512 %bias_out_copy, %"class.hls::stream.6"* %weight_out, %"class.hls::stream.6"* nonnull align 512 %weight_out_copy, %"class.hls::stream.6"* %data_out, %"class.hls::stream.6"* nonnull align 512 %data_out_copy)
  call void @apatb_memRead_hw(i8 %data_dim1, i8 %data_dim2, i16 %data_dim1xdim2, i8 %weight_dim1, i8 %weight_dim2, i16 %weight_dim3, i16 %weight_dim4_div_lane, i8 %weight_dim1x2, i32 %weight_dim1x2x3, i8 %conv_x, i8 %stride, i8 %padding, i8 %split, i8 %group_num_x, i8 %group_num_y, i8 %group_rem_size_x, i32 %group_rem_size_xyz, i8 %win_size_x, i8 %win_size_y, i32 %win_size_xyz, %struct.lane_data* %bottom_copy, %struct.channel_vec* %weights_copy, %struct.channel_scal* %bias_copy, %"class.hls::stream"* %bias_out_copy, %"class.hls::stream.6"* %weight_out_copy, %"class.hls::stream.6"* %data_out_copy)
  call fastcc void @copy_out(%struct.lane_data* %bottom, %struct.lane_data* nonnull align 512 %bottom_copy, %struct.channel_vec* %weights, %struct.channel_vec* nonnull align 512 %weights_copy, %struct.channel_scal* %bias, %struct.channel_scal* nonnull align 512 %bias_copy, %"class.hls::stream"* %bias_out, %"class.hls::stream"* nonnull align 512 %bias_out_copy, %"class.hls::stream.6"* %weight_out, %"class.hls::stream.6"* nonnull align 512 %weight_out_copy, %"class.hls::stream.6"* %data_out, %"class.hls::stream.6"* nonnull align 512 %data_out_copy)
  ret void
}

; Function Attrs: noinline
define internal fastcc void @copy_in(%struct.lane_data*, %struct.lane_data* noalias align 512, %struct.channel_vec*, %struct.channel_vec* noalias align 512, %struct.channel_scal*, %struct.channel_scal* noalias align 512, %"class.hls::stream"*, %"class.hls::stream"* noalias align 512, %"class.hls::stream.6"*, %"class.hls::stream.6"* noalias align 512, %"class.hls::stream.6"*, %"class.hls::stream.6"* noalias align 512) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0struct.lane_data(%struct.lane_data* align 512 %1, %struct.lane_data* %0)
  call fastcc void @onebyonecpy_hls.p0struct.channel_vec(%struct.channel_vec* align 512 %3, %struct.channel_vec* %2)
  call fastcc void @onebyonecpy_hls.p0struct.channel_scal(%struct.channel_scal* align 512 %5, %struct.channel_scal* %4)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream"(%"class.hls::stream"* align 512 %7, %"class.hls::stream"* %6)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream.6"(%"class.hls::stream.6"* align 512 %9, %"class.hls::stream.6"* %8)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream.6"(%"class.hls::stream.6"* align 512 %11, %"class.hls::stream.6"* %10)
  ret void
}

; Function Attrs: noinline
define internal fastcc void @onebyonecpy_hls.p0struct.lane_data(%struct.lane_data* noalias align 512, %struct.lane_data* noalias) unnamed_addr #2 {
entry:
  %2 = icmp eq %struct.lane_data* %0, null
  %3 = icmp eq %struct.lane_data* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = getelementptr inbounds %struct.lane_data, %struct.lane_data* %1, i32 0, i32 0, i32 0
  %6 = call i1 @fpga_fifo_exist_4(i8* %5)
  br i1 %6, label %7, label %8

; <label>:7:                                      ; preds = %copy
  call fastcc void @streamcpy_hls.p0struct.lane_data(%struct.lane_data* nonnull align 512 %0, %struct.lane_data* nonnull %1)
  br label %ret

; <label>:8:                                      ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %8
  %for.loop.idx4 = phi i64 [ 0, %8 ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr2 = getelementptr %struct.lane_data, %struct.lane_data* %0, i32 0, i32 0, i64 %for.loop.idx4
  %src.addr3 = getelementptr %struct.lane_data, %struct.lane_data* %1, i32 0, i32 0, i64 %for.loop.idx4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %dst.addr2, i8* align 1 %src.addr3, i64 1, i1 false)
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx4, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 4
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %7, %entry
  ret void
}

declare i1 @fpga_fifo_exist_4(i8*) local_unnamed_addr

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.lane_data(%struct.lane_data* noalias nocapture align 512, %struct.lane_data* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.lane_data
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.lane_data* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_4(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.lane_data* %2 to i8*
  %6 = bitcast %struct.lane_data* %1 to i8*
  call void @fpga_fifo_pop_4(i8* %5, i8* %6)
  %7 = load volatile %struct.lane_data, %struct.lane_data* %2
  %8 = bitcast %struct.lane_data* %2 to i8*
  %9 = bitcast %struct.lane_data* %0 to i8*
  call void @fpga_fifo_push_4(i8* %8, i8* %9)
  br label %empty, !llvm.loop !5

ret:                                              ; preds = %empty
  %10 = getelementptr inbounds %struct.lane_data, %struct.lane_data* %1, i32 0, i32 0, i32 0
  %11 = getelementptr inbounds %struct.lane_data, %struct.lane_data* %0, i32 0, i32 0, i32 0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 4, i1 false)
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #4

; Function Attrs: noinline
define internal fastcc void @onebyonecpy_hls.p0struct.channel_vec(%struct.channel_vec* noalias align 512, %struct.channel_vec* noalias) unnamed_addr #2 {
entry:
  %2 = icmp eq %struct.channel_vec* %0, null
  %3 = icmp eq %struct.channel_vec* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = getelementptr inbounds %struct.channel_vec, %struct.channel_vec* %1, i32 0, i32 0, i32 0, i32 0, i32 0
  %6 = call i1 @fpga_fifo_exist_8(i8* %5)
  br i1 %6, label %7, label %8

; <label>:7:                                      ; preds = %copy
  call fastcc void @streamcpy_hls.p0struct.channel_vec(%struct.channel_vec* nonnull align 512 %0, %struct.channel_vec* nonnull %1)
  br label %ret

; <label>:8:                                      ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop.head, %8
  %for.loop.idx17 = phi i64 [ 0, %8 ], [ %for.loop.idx.next, %for.loop.head ]
  %dst.addr10 = getelementptr %struct.channel_vec, %struct.channel_vec* %0, i32 0, i32 0, i64 %for.loop.idx17
  %src.addr11 = getelementptr %struct.channel_vec, %struct.channel_vec* %1, i32 0, i32 0, i64 %for.loop.idx17
  %9 = getelementptr %struct.channel_vec, %struct.channel_vec* %1, i32 0, i32 0, i64 %for.loop.idx17, i32 0, i32 0
  %10 = call i1 @fpga_fifo_exist_4(i8* %9)
  br i1 %10, label %11, label %12

; <label>:11:                                     ; preds = %for.loop
  call fastcc void @streamcpy_hls.p0struct.lane_data(%struct.lane_data* %dst.addr10, %struct.lane_data* %src.addr11)
  br label %for.loop.head

; <label>:12:                                     ; preds = %for.loop
  br label %for.loop4

for.loop4:                                        ; preds = %for.loop4, %12
  %for.loop.idx616 = phi i64 [ 0, %12 ], [ %for.loop.idx6.next, %for.loop4 ]
  %dst.addr814 = getelementptr %struct.channel_vec, %struct.channel_vec* %0, i32 0, i32 0, i64 %for.loop.idx17, i32 0, i64 %for.loop.idx616
  %src.addr915 = getelementptr %struct.channel_vec, %struct.channel_vec* %1, i32 0, i32 0, i64 %for.loop.idx17, i32 0, i64 %for.loop.idx616
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %dst.addr814, i8* align 1 %src.addr915, i64 1, i1 false)
  %for.loop.idx6.next = add nuw nsw i64 %for.loop.idx616, 1
  %exitcond = icmp ne i64 %for.loop.idx6.next, 4
  br i1 %exitcond, label %for.loop4, label %for.loop.head

for.loop.head:                                    ; preds = %for.loop4, %11
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx17, 1
  %exitcond19 = icmp ne i64 %for.loop.idx.next, 2
  br i1 %exitcond19, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.head, %7, %entry
  ret void
}

declare i1 @fpga_fifo_exist_8(i8*) local_unnamed_addr

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.channel_vec(%struct.channel_vec* noalias nocapture align 512, %struct.channel_vec* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.channel_vec
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.channel_vec* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_8(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.channel_vec* %2 to i8*
  %6 = bitcast %struct.channel_vec* %1 to i8*
  call void @fpga_fifo_pop_8(i8* %5, i8* %6)
  %7 = load volatile %struct.channel_vec, %struct.channel_vec* %2
  %8 = bitcast %struct.channel_vec* %2 to i8*
  %9 = bitcast %struct.channel_vec* %0 to i8*
  call void @fpga_fifo_push_8(i8* %8, i8* %9)
  br label %empty, !llvm.loop !7

ret:                                              ; preds = %empty
  %10 = getelementptr inbounds %struct.channel_vec, %struct.channel_vec* %1, i32 0, i32 0, i32 0, i32 0, i32 0
  %11 = getelementptr inbounds %struct.channel_vec, %struct.channel_vec* %0, i32 0, i32 0, i32 0, i32 0, i32 0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 8, i1 false)
  ret void
}

; Function Attrs: noinline
define internal fastcc void @onebyonecpy_hls.p0struct.channel_scal(%struct.channel_scal* noalias align 512, %struct.channel_scal* noalias) unnamed_addr #2 {
entry:
  %2 = icmp eq %struct.channel_scal* %0, null
  %3 = icmp eq %struct.channel_scal* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = getelementptr inbounds %struct.channel_scal, %struct.channel_scal* %1, i32 0, i32 0, i32 0
  %6 = call i1 @fpga_fifo_exist_2(i8* %5)
  br i1 %6, label %7, label %8

; <label>:7:                                      ; preds = %copy
  call fastcc void @streamcpy_hls.p0struct.channel_scal(%struct.channel_scal* nonnull align 512 %0, %struct.channel_scal* nonnull %1)
  br label %ret

; <label>:8:                                      ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %8
  %for.loop.idx4 = phi i64 [ 0, %8 ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr2 = getelementptr %struct.channel_scal, %struct.channel_scal* %0, i32 0, i32 0, i64 %for.loop.idx4
  %src.addr3 = getelementptr %struct.channel_scal, %struct.channel_scal* %1, i32 0, i32 0, i64 %for.loop.idx4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %dst.addr2, i8* align 1 %src.addr3, i64 1, i1 false)
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx4, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 2
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %7, %entry
  ret void
}

declare i1 @fpga_fifo_exist_2(i8*) local_unnamed_addr

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.channel_scal(%struct.channel_scal* noalias nocapture align 512, %struct.channel_scal* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.channel_scal
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.channel_scal* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_2(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.channel_scal* %2 to i8*
  %6 = bitcast %struct.channel_scal* %1 to i8*
  call void @fpga_fifo_pop_2(i8* %5, i8* %6)
  %7 = load volatile %struct.channel_scal, %struct.channel_scal* %2
  %8 = bitcast %struct.channel_scal* %2 to i8*
  %9 = bitcast %struct.channel_scal* %0 to i8*
  call void @fpga_fifo_push_2(i8* %8, i8* %9)
  br label %empty, !llvm.loop !8

ret:                                              ; preds = %empty
  %10 = getelementptr inbounds %struct.channel_scal, %struct.channel_scal* %1, i32 0, i32 0, i32 0
  %11 = getelementptr inbounds %struct.channel_scal, %struct.channel_scal* %0, i32 0, i32 0, i32 0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 2, i1 false)
  ret void
}

; Function Attrs: noinline
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream"(%"class.hls::stream"* noalias align 512, %"class.hls::stream"* noalias) unnamed_addr #2 {
entry:
  %2 = icmp eq %"class.hls::stream"* %0, null
  %3 = icmp eq %"class.hls::stream"* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = bitcast %"class.hls::stream"* %1 to i8*
  %6 = call i1 @fpga_fifo_exist_8(i8* %5)
  br i1 %6, label %7, label %8

; <label>:7:                                      ; preds = %copy
  call fastcc void @"streamcpy_hls.p0class.hls::stream"(%"class.hls::stream"* nonnull align 512 %0, %"class.hls::stream"* nonnull %1)
  br label %ret

; <label>:8:                                      ; preds = %copy
  %.0.02 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 0
  %.01.03 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 0
  %9 = call i1 @fpga_fifo_exist_2(i8* %5)
  br i1 %9, label %10, label %11

; <label>:10:                                     ; preds = %8
  call fastcc void @streamcpy_hls.p0struct.ap_uint(%struct.ap_uint* align 512 %.01.03, %struct.ap_uint* %.0.02)
  br label %19

; <label>:11:                                     ; preds = %8
  %.0.0.04 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 0, i32 0
  %.01.0.05 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 0, i32 0
  %12 = call i1 @fpga_fifo_exist_2(i8* %5)
  br i1 %12, label %13, label %14

; <label>:13:                                     ; preds = %11
  call fastcc void @streamcpy_hls.p0struct.ap_int_base(%struct.ap_int_base* align 512 %.01.0.05, %struct.ap_int_base* %.0.0.04)
  br label %19

; <label>:14:                                     ; preds = %11
  %.0.0.0.06 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 0, i32 0, i32 0
  %.01.0.0.07 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 0, i32 0, i32 0
  %15 = call i1 @fpga_fifo_exist_2(i8* %5)
  br i1 %15, label %16, label %17

; <label>:16:                                     ; preds = %14
  call fastcc void @streamcpy_hls.p0struct.ssdm_int(%struct.ssdm_int* align 512 %.01.0.0.07, %struct.ssdm_int* %.0.0.0.06)
  br label %19

; <label>:17:                                     ; preds = %14
  %18 = bitcast %"class.hls::stream"* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %18, i8* align 1 %5, i64 2, i1 false)
  br label %19

; <label>:19:                                     ; preds = %17, %16, %13, %10
  %.0.110 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 1
  %.01.111 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 1
  %20 = bitcast %struct.ap_uint.0* %.0.110 to i8*
  %21 = call i1 @fpga_fifo_exist_1(i8* %20)
  br i1 %21, label %22, label %23

; <label>:22:                                     ; preds = %19
  call fastcc void @streamcpy_hls.p0struct.ap_uint.0(%struct.ap_uint.0* %.01.111, %struct.ap_uint.0* %.0.110)
  br label %34

; <label>:23:                                     ; preds = %19
  %.0.1.012 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 1, i32 0
  %.01.1.013 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 1, i32 0
  %24 = bitcast %struct.ap_int_base.1* %.0.1.012 to i8*
  %25 = call i1 @fpga_fifo_exist_1(i8* %24)
  br i1 %25, label %26, label %27

; <label>:26:                                     ; preds = %23
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.1(%struct.ap_int_base.1* %.01.1.013, %struct.ap_int_base.1* %.0.1.012)
  br label %34

; <label>:27:                                     ; preds = %23
  %.0.1.0.014 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 1, i32 0, i32 0
  %.01.1.0.015 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 1, i32 0, i32 0
  %28 = bitcast %struct.ssdm_int.2* %.0.1.0.014 to i8*
  %29 = call i1 @fpga_fifo_exist_1(i8* %28)
  br i1 %29, label %30, label %31

; <label>:30:                                     ; preds = %27
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.2(%struct.ssdm_int.2* %.01.1.0.015, %struct.ssdm_int.2* %.0.1.0.014)
  br label %34

; <label>:31:                                     ; preds = %27
  %.01.1.0.0.017.gep59 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 1, i32 0, i32 0, i32 0
  %32 = bitcast i2* %.01.1.0.0.017.gep59 to i8*
  %.0.1.0.0.016.gep60 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 1, i32 0, i32 0, i32 0
  %33 = bitcast i2* %.0.1.0.0.016.gep60 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %32, i8* align 1 %33, i64 1, i1 false)
  br label %34

; <label>:34:                                     ; preds = %31, %30, %26, %22
  %.0.218 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 2
  %.01.219 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 2
  %35 = bitcast %struct.ap_uint.0* %.0.218 to i8*
  %36 = call i1 @fpga_fifo_exist_1(i8* %35)
  br i1 %36, label %37, label %38

; <label>:37:                                     ; preds = %34
  call fastcc void @streamcpy_hls.p0struct.ap_uint.0(%struct.ap_uint.0* %.01.219, %struct.ap_uint.0* %.0.218)
  br label %49

; <label>:38:                                     ; preds = %34
  %.0.2.020 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 2, i32 0
  %.01.2.021 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 2, i32 0
  %39 = bitcast %struct.ap_int_base.1* %.0.2.020 to i8*
  %40 = call i1 @fpga_fifo_exist_1(i8* %39)
  br i1 %40, label %41, label %42

; <label>:41:                                     ; preds = %38
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.1(%struct.ap_int_base.1* %.01.2.021, %struct.ap_int_base.1* %.0.2.020)
  br label %49

; <label>:42:                                     ; preds = %38
  %.0.2.0.022 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 2, i32 0, i32 0
  %.01.2.0.023 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 2, i32 0, i32 0
  %43 = bitcast %struct.ssdm_int.2* %.0.2.0.022 to i8*
  %44 = call i1 @fpga_fifo_exist_1(i8* %43)
  br i1 %44, label %45, label %46

; <label>:45:                                     ; preds = %42
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.2(%struct.ssdm_int.2* %.01.2.0.023, %struct.ssdm_int.2* %.0.2.0.022)
  br label %49

; <label>:46:                                     ; preds = %42
  %.01.2.0.0.025.gep61 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 2, i32 0, i32 0, i32 0
  %47 = bitcast i2* %.01.2.0.0.025.gep61 to i8*
  %.0.2.0.0.024.gep62 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 2, i32 0, i32 0, i32 0
  %48 = bitcast i2* %.0.2.0.0.024.gep62 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %47, i8* align 1 %48, i64 1, i1 false)
  br label %49

; <label>:49:                                     ; preds = %46, %45, %41, %37
  %.0.326 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 3
  %.01.327 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 3
  %50 = bitcast %struct.ap_uint.3* %.0.326 to i8*
  %51 = call i1 @fpga_fifo_exist_1(i8* %50)
  br i1 %51, label %52, label %53

; <label>:52:                                     ; preds = %49
  call fastcc void @streamcpy_hls.p0struct.ap_uint.3(%struct.ap_uint.3* %.01.327, %struct.ap_uint.3* %.0.326)
  br label %64

; <label>:53:                                     ; preds = %49
  %.0.3.028 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 3, i32 0
  %.01.3.029 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 3, i32 0
  %54 = bitcast %struct.ap_int_base.4* %.0.3.028 to i8*
  %55 = call i1 @fpga_fifo_exist_1(i8* %54)
  br i1 %55, label %56, label %57

; <label>:56:                                     ; preds = %53
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.4(%struct.ap_int_base.4* %.01.3.029, %struct.ap_int_base.4* %.0.3.028)
  br label %64

; <label>:57:                                     ; preds = %53
  %.0.3.0.030 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 3, i32 0, i32 0
  %.01.3.0.031 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 3, i32 0, i32 0
  %58 = bitcast %struct.ssdm_int.5* %.0.3.0.030 to i8*
  %59 = call i1 @fpga_fifo_exist_1(i8* %58)
  br i1 %59, label %60, label %61

; <label>:60:                                     ; preds = %57
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.5(%struct.ssdm_int.5* %.01.3.0.031, %struct.ssdm_int.5* %.0.3.0.030)
  br label %64

; <label>:61:                                     ; preds = %57
  %.01.3.0.0.033.gep63 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 3, i32 0, i32 0, i32 0
  %62 = bitcast i1* %.01.3.0.0.033.gep63 to i8*
  %.0.3.0.0.032.gep64 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 3, i32 0, i32 0, i32 0
  %63 = bitcast i1* %.0.3.0.0.032.gep64 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %62, i8* align 1 %63, i64 1, i1 false)
  br label %64

; <label>:64:                                     ; preds = %61, %60, %56, %52
  %.0.434 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 4
  %.01.435 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 4
  %65 = bitcast %struct.ap_uint.3* %.0.434 to i8*
  %66 = call i1 @fpga_fifo_exist_1(i8* %65)
  br i1 %66, label %67, label %68

; <label>:67:                                     ; preds = %64
  call fastcc void @streamcpy_hls.p0struct.ap_uint.3(%struct.ap_uint.3* %.01.435, %struct.ap_uint.3* %.0.434)
  br label %79

; <label>:68:                                     ; preds = %64
  %.0.4.036 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 4, i32 0
  %.01.4.037 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 4, i32 0
  %69 = bitcast %struct.ap_int_base.4* %.0.4.036 to i8*
  %70 = call i1 @fpga_fifo_exist_1(i8* %69)
  br i1 %70, label %71, label %72

; <label>:71:                                     ; preds = %68
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.4(%struct.ap_int_base.4* %.01.4.037, %struct.ap_int_base.4* %.0.4.036)
  br label %79

; <label>:72:                                     ; preds = %68
  %.0.4.0.038 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 4, i32 0, i32 0
  %.01.4.0.039 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 4, i32 0, i32 0
  %73 = bitcast %struct.ssdm_int.5* %.0.4.0.038 to i8*
  %74 = call i1 @fpga_fifo_exist_1(i8* %73)
  br i1 %74, label %75, label %76

; <label>:75:                                     ; preds = %72
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.5(%struct.ssdm_int.5* %.01.4.0.039, %struct.ssdm_int.5* %.0.4.0.038)
  br label %79

; <label>:76:                                     ; preds = %72
  %.01.4.0.0.041.gep65 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 4, i32 0, i32 0, i32 0
  %77 = bitcast i1* %.01.4.0.0.041.gep65 to i8*
  %.0.4.0.0.040.gep66 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 4, i32 0, i32 0, i32 0
  %78 = bitcast i1* %.0.4.0.0.040.gep66 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %77, i8* align 1 %78, i64 1, i1 false)
  br label %79

; <label>:79:                                     ; preds = %76, %75, %71, %67
  %.0.542 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 5
  %.01.543 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 5
  %80 = bitcast %struct.ap_uint.3* %.0.542 to i8*
  %81 = call i1 @fpga_fifo_exist_1(i8* %80)
  br i1 %81, label %82, label %83

; <label>:82:                                     ; preds = %79
  call fastcc void @streamcpy_hls.p0struct.ap_uint.3(%struct.ap_uint.3* %.01.543, %struct.ap_uint.3* %.0.542)
  br label %94

; <label>:83:                                     ; preds = %79
  %.0.5.044 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 5, i32 0
  %.01.5.045 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 5, i32 0
  %84 = bitcast %struct.ap_int_base.4* %.0.5.044 to i8*
  %85 = call i1 @fpga_fifo_exist_1(i8* %84)
  br i1 %85, label %86, label %87

; <label>:86:                                     ; preds = %83
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.4(%struct.ap_int_base.4* %.01.5.045, %struct.ap_int_base.4* %.0.5.044)
  br label %94

; <label>:87:                                     ; preds = %83
  %.0.5.0.046 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 5, i32 0, i32 0
  %.01.5.0.047 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 5, i32 0, i32 0
  %88 = bitcast %struct.ssdm_int.5* %.0.5.0.046 to i8*
  %89 = call i1 @fpga_fifo_exist_1(i8* %88)
  br i1 %89, label %90, label %91

; <label>:90:                                     ; preds = %87
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.5(%struct.ssdm_int.5* %.01.5.0.047, %struct.ssdm_int.5* %.0.5.0.046)
  br label %94

; <label>:91:                                     ; preds = %87
  %.01.5.0.0.049.gep67 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 5, i32 0, i32 0, i32 0
  %92 = bitcast i1* %.01.5.0.0.049.gep67 to i8*
  %.0.5.0.0.048.gep68 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 5, i32 0, i32 0, i32 0
  %93 = bitcast i1* %.0.5.0.0.048.gep68 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %92, i8* align 1 %93, i64 1, i1 false)
  br label %94

; <label>:94:                                     ; preds = %91, %90, %86, %82
  %.0.650 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 6
  %.01.651 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 6
  %95 = bitcast %struct.ap_uint.3* %.0.650 to i8*
  %96 = call i1 @fpga_fifo_exist_1(i8* %95)
  br i1 %96, label %97, label %98

; <label>:97:                                     ; preds = %94
  call fastcc void @streamcpy_hls.p0struct.ap_uint.3(%struct.ap_uint.3* %.01.651, %struct.ap_uint.3* %.0.650)
  br label %ret

; <label>:98:                                     ; preds = %94
  %.0.6.052 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 6, i32 0
  %.01.6.053 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 6, i32 0
  %99 = bitcast %struct.ap_int_base.4* %.0.6.052 to i8*
  %100 = call i1 @fpga_fifo_exist_1(i8* %99)
  br i1 %100, label %101, label %102

; <label>:101:                                    ; preds = %98
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.4(%struct.ap_int_base.4* %.01.6.053, %struct.ap_int_base.4* %.0.6.052)
  br label %ret

; <label>:102:                                    ; preds = %98
  %.0.6.0.054 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 6, i32 0, i32 0
  %.01.6.0.055 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 6, i32 0, i32 0
  %103 = bitcast %struct.ssdm_int.5* %.0.6.0.054 to i8*
  %104 = call i1 @fpga_fifo_exist_1(i8* %103)
  br i1 %104, label %105, label %106

; <label>:105:                                    ; preds = %102
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.5(%struct.ssdm_int.5* %.01.6.0.055, %struct.ssdm_int.5* %.0.6.0.054)
  br label %ret

; <label>:106:                                    ; preds = %102
  %.01.6.0.0.057.gep69 = getelementptr %"class.hls::stream", %"class.hls::stream"* %0, i32 0, i32 0, i32 6, i32 0, i32 0, i32 0
  %107 = bitcast i1* %.01.6.0.0.057.gep69 to i8*
  %.0.6.0.0.056.gep70 = getelementptr %"class.hls::stream", %"class.hls::stream"* %1, i32 0, i32 0, i32 6, i32 0, i32 0, i32 0
  %108 = bitcast i1* %.0.6.0.0.056.gep70 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %107, i8* align 1 %108, i64 1, i1 false)
  br label %ret

ret:                                              ; preds = %106, %105, %101, %97, %7, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @"streamcpy_hls.p0class.hls::stream"(%"class.hls::stream"* noalias nocapture align 512, %"class.hls::stream"* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %"class.hls::stream"
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %"class.hls::stream"* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_8(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %"class.hls::stream"* %2 to i8*
  %6 = bitcast %"class.hls::stream"* %1 to i8*
  call void @fpga_fifo_pop_8(i8* %5, i8* %6)
  %7 = load volatile %"class.hls::stream", %"class.hls::stream"* %2
  %8 = bitcast %"class.hls::stream"* %2 to i8*
  %9 = bitcast %"class.hls::stream"* %0 to i8*
  call void @fpga_fifo_push_8(i8* %8, i8* %9)
  br label %empty, !llvm.loop !9

ret:                                              ; preds = %empty
  %10 = bitcast %"class.hls::stream"* %1 to i8*
  %11 = bitcast %"class.hls::stream"* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 8, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ap_uint(%struct.ap_uint* noalias nocapture align 512, %struct.ap_uint* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ap_uint
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ap_uint* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_2(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ap_uint* %2 to i8*
  %6 = bitcast %struct.ap_uint* %1 to i8*
  call void @fpga_fifo_pop_2(i8* %5, i8* %6)
  %7 = load volatile %struct.ap_uint, %struct.ap_uint* %2
  %8 = bitcast %struct.ap_uint* %2 to i8*
  %9 = bitcast %struct.ap_uint* %0 to i8*
  call void @fpga_fifo_push_2(i8* %8, i8* %9)
  br label %empty, !llvm.loop !10

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ap_uint* %1 to i8*
  %11 = bitcast %struct.ap_uint* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 2, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ap_int_base(%struct.ap_int_base* noalias nocapture align 512, %struct.ap_int_base* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ap_int_base
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ap_int_base* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_2(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ap_int_base* %2 to i8*
  %6 = bitcast %struct.ap_int_base* %1 to i8*
  call void @fpga_fifo_pop_2(i8* %5, i8* %6)
  %7 = load volatile %struct.ap_int_base, %struct.ap_int_base* %2
  %8 = bitcast %struct.ap_int_base* %2 to i8*
  %9 = bitcast %struct.ap_int_base* %0 to i8*
  call void @fpga_fifo_push_2(i8* %8, i8* %9)
  br label %empty, !llvm.loop !11

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ap_int_base* %1 to i8*
  %11 = bitcast %struct.ap_int_base* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 2, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ssdm_int(%struct.ssdm_int* noalias nocapture align 512, %struct.ssdm_int* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ssdm_int
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ssdm_int* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_2(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ssdm_int* %2 to i8*
  %6 = bitcast %struct.ssdm_int* %1 to i8*
  call void @fpga_fifo_pop_2(i8* %5, i8* %6)
  %7 = load volatile %struct.ssdm_int, %struct.ssdm_int* %2
  %8 = bitcast %struct.ssdm_int* %2 to i8*
  %9 = bitcast %struct.ssdm_int* %0 to i8*
  call void @fpga_fifo_push_2(i8* %8, i8* %9)
  br label %empty, !llvm.loop !12

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ssdm_int* %1 to i8*
  %11 = bitcast %struct.ssdm_int* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 2, i1 false)
  ret void
}

declare i1 @fpga_fifo_exist_1(i8*) local_unnamed_addr

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ap_uint.0(%struct.ap_uint.0* noalias nocapture, %struct.ap_uint.0* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ap_uint.0
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ap_uint.0* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_1(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ap_uint.0* %2 to i8*
  %6 = bitcast %struct.ap_uint.0* %1 to i8*
  call void @fpga_fifo_pop_1(i8* %5, i8* %6)
  %7 = load volatile %struct.ap_uint.0, %struct.ap_uint.0* %2
  %8 = bitcast %struct.ap_uint.0* %2 to i8*
  %9 = bitcast %struct.ap_uint.0* %0 to i8*
  call void @fpga_fifo_push_1(i8* %8, i8* %9)
  br label %empty, !llvm.loop !13

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ap_uint.0* %1 to i8*
  %11 = bitcast %struct.ap_uint.0* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 1, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ap_int_base.1(%struct.ap_int_base.1* noalias nocapture, %struct.ap_int_base.1* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ap_int_base.1
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ap_int_base.1* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_1(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ap_int_base.1* %2 to i8*
  %6 = bitcast %struct.ap_int_base.1* %1 to i8*
  call void @fpga_fifo_pop_1(i8* %5, i8* %6)
  %7 = load volatile %struct.ap_int_base.1, %struct.ap_int_base.1* %2
  %8 = bitcast %struct.ap_int_base.1* %2 to i8*
  %9 = bitcast %struct.ap_int_base.1* %0 to i8*
  call void @fpga_fifo_push_1(i8* %8, i8* %9)
  br label %empty, !llvm.loop !14

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ap_int_base.1* %1 to i8*
  %11 = bitcast %struct.ap_int_base.1* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 1, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ssdm_int.2(%struct.ssdm_int.2* noalias nocapture, %struct.ssdm_int.2* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ssdm_int.2
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ssdm_int.2* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_1(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ssdm_int.2* %2 to i8*
  %6 = bitcast %struct.ssdm_int.2* %1 to i8*
  call void @fpga_fifo_pop_1(i8* %5, i8* %6)
  %7 = load volatile %struct.ssdm_int.2, %struct.ssdm_int.2* %2
  %8 = bitcast %struct.ssdm_int.2* %2 to i8*
  %9 = bitcast %struct.ssdm_int.2* %0 to i8*
  call void @fpga_fifo_push_1(i8* %8, i8* %9)
  br label %empty, !llvm.loop !15

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ssdm_int.2* %1 to i8*
  %11 = bitcast %struct.ssdm_int.2* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 1, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ap_uint.3(%struct.ap_uint.3* noalias nocapture, %struct.ap_uint.3* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ap_uint.3
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ap_uint.3* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_1(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ap_uint.3* %2 to i8*
  %6 = bitcast %struct.ap_uint.3* %1 to i8*
  call void @fpga_fifo_pop_1(i8* %5, i8* %6)
  %7 = load volatile %struct.ap_uint.3, %struct.ap_uint.3* %2
  %8 = bitcast %struct.ap_uint.3* %2 to i8*
  %9 = bitcast %struct.ap_uint.3* %0 to i8*
  call void @fpga_fifo_push_1(i8* %8, i8* %9)
  br label %empty, !llvm.loop !16

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ap_uint.3* %1 to i8*
  %11 = bitcast %struct.ap_uint.3* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 1, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ap_int_base.4(%struct.ap_int_base.4* noalias nocapture, %struct.ap_int_base.4* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ap_int_base.4
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ap_int_base.4* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_1(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ap_int_base.4* %2 to i8*
  %6 = bitcast %struct.ap_int_base.4* %1 to i8*
  call void @fpga_fifo_pop_1(i8* %5, i8* %6)
  %7 = load volatile %struct.ap_int_base.4, %struct.ap_int_base.4* %2
  %8 = bitcast %struct.ap_int_base.4* %2 to i8*
  %9 = bitcast %struct.ap_int_base.4* %0 to i8*
  call void @fpga_fifo_push_1(i8* %8, i8* %9)
  br label %empty, !llvm.loop !17

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ap_int_base.4* %1 to i8*
  %11 = bitcast %struct.ap_int_base.4* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 1, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ssdm_int.5(%struct.ssdm_int.5* noalias nocapture, %struct.ssdm_int.5* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ssdm_int.5
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ssdm_int.5* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_1(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ssdm_int.5* %2 to i8*
  %6 = bitcast %struct.ssdm_int.5* %1 to i8*
  call void @fpga_fifo_pop_1(i8* %5, i8* %6)
  %7 = load volatile %struct.ssdm_int.5, %struct.ssdm_int.5* %2
  %8 = bitcast %struct.ssdm_int.5* %2 to i8*
  %9 = bitcast %struct.ssdm_int.5* %0 to i8*
  call void @fpga_fifo_push_1(i8* %8, i8* %9)
  br label %empty, !llvm.loop !18

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ssdm_int.5* %1 to i8*
  %11 = bitcast %struct.ssdm_int.5* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 1, i1 false)
  ret void
}

; Function Attrs: noinline
define internal fastcc void @"onebyonecpy_hls.p0class.hls::stream.6"(%"class.hls::stream.6"* noalias align 512, %"class.hls::stream.6"* noalias) unnamed_addr #2 {
entry:
  %2 = icmp eq %"class.hls::stream.6"* %0, null
  %3 = icmp eq %"class.hls::stream.6"* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  %5 = bitcast %"class.hls::stream.6"* %1 to i8*
  %6 = call i1 @fpga_fifo_exist_16(i8* %5)
  br i1 %6, label %7, label %8

; <label>:7:                                      ; preds = %copy
  call fastcc void @"streamcpy_hls.p0class.hls::stream.6"(%"class.hls::stream.6"* nonnull align 512 %0, %"class.hls::stream.6"* nonnull %1)
  br label %ret

; <label>:8:                                      ; preds = %copy
  %.0.02 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 0
  %.01.03 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 0
  %9 = call i1 @fpga_fifo_exist_8(i8* %5)
  br i1 %9, label %10, label %11

; <label>:10:                                     ; preds = %8
  call fastcc void @streamcpy_hls.p0struct.ap_uint.8(%struct.ap_uint.8* align 512 %.01.03, %struct.ap_uint.8* %.0.02)
  br label %19

; <label>:11:                                     ; preds = %8
  %.0.0.04 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 0, i32 0
  %.01.0.05 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 0, i32 0
  %12 = call i1 @fpga_fifo_exist_8(i8* %5)
  br i1 %12, label %13, label %14

; <label>:13:                                     ; preds = %11
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.9(%struct.ap_int_base.9* align 512 %.01.0.05, %struct.ap_int_base.9* %.0.0.04)
  br label %19

; <label>:14:                                     ; preds = %11
  %.0.0.0.06 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 0, i32 0, i32 0
  %.01.0.0.07 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 0, i32 0, i32 0
  %15 = call i1 @fpga_fifo_exist_8(i8* %5)
  br i1 %15, label %16, label %17

; <label>:16:                                     ; preds = %14
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.10(%struct.ssdm_int.10* align 512 %.01.0.0.07, %struct.ssdm_int.10* %.0.0.0.06)
  br label %19

; <label>:17:                                     ; preds = %14
  %18 = bitcast %"class.hls::stream.6"* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %18, i8* align 1 %5, i64 8, i1 false)
  br label %19

; <label>:19:                                     ; preds = %17, %16, %13, %10
  %.0.110 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 1
  %.01.111 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 1
  %20 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 1, i32 0, i32 0, i32 0
  %21 = call i1 @fpga_fifo_exist_1(i8* %20)
  br i1 %21, label %22, label %23

; <label>:22:                                     ; preds = %19
  call fastcc void @streamcpy_hls.p0struct.ap_uint.11(%struct.ap_uint.11* %.01.111, %struct.ap_uint.11* %.0.110)
  br label %30

; <label>:23:                                     ; preds = %19
  %.0.1.012 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 1, i32 0
  %.01.1.013 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 1, i32 0
  %24 = call i1 @fpga_fifo_exist_1(i8* %20)
  br i1 %24, label %25, label %26

; <label>:25:                                     ; preds = %23
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.12(%struct.ap_int_base.12* %.01.1.013, %struct.ap_int_base.12* %.0.1.012)
  br label %30

; <label>:26:                                     ; preds = %23
  %.0.1.0.014 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 1, i32 0, i32 0
  %.01.1.0.015 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 1, i32 0, i32 0
  %27 = call i1 @fpga_fifo_exist_1(i8* %20)
  br i1 %27, label %28, label %29

; <label>:28:                                     ; preds = %26
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.13(%struct.ssdm_int.13* %.01.1.0.015, %struct.ssdm_int.13* %.0.1.0.014)
  br label %30

; <label>:29:                                     ; preds = %26
  %.01.1.0.0.017 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 1, i32 0, i32 0, i32 0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %.01.1.0.0.017, i8* align 1 %20, i64 1, i1 false)
  br label %30

; <label>:30:                                     ; preds = %29, %28, %25, %22
  %.0.218 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 2
  %.01.219 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 2
  %31 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 2, i32 0, i32 0, i32 0
  %32 = call i1 @fpga_fifo_exist_1(i8* %31)
  br i1 %32, label %33, label %34

; <label>:33:                                     ; preds = %30
  call fastcc void @streamcpy_hls.p0struct.ap_uint.11(%struct.ap_uint.11* %.01.219, %struct.ap_uint.11* %.0.218)
  br label %41

; <label>:34:                                     ; preds = %30
  %.0.2.020 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 2, i32 0
  %.01.2.021 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 2, i32 0
  %35 = call i1 @fpga_fifo_exist_1(i8* %31)
  br i1 %35, label %36, label %37

; <label>:36:                                     ; preds = %34
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.12(%struct.ap_int_base.12* %.01.2.021, %struct.ap_int_base.12* %.0.2.020)
  br label %41

; <label>:37:                                     ; preds = %34
  %.0.2.0.022 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 2, i32 0, i32 0
  %.01.2.0.023 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 2, i32 0, i32 0
  %38 = call i1 @fpga_fifo_exist_1(i8* %31)
  br i1 %38, label %39, label %40

; <label>:39:                                     ; preds = %37
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.13(%struct.ssdm_int.13* %.01.2.0.023, %struct.ssdm_int.13* %.0.2.0.022)
  br label %41

; <label>:40:                                     ; preds = %37
  %.01.2.0.0.025 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 2, i32 0, i32 0, i32 0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %.01.2.0.0.025, i8* align 1 %31, i64 1, i1 false)
  br label %41

; <label>:41:                                     ; preds = %40, %39, %36, %33
  %.0.326 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 3
  %.01.327 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 3
  %42 = bitcast %struct.ap_uint.3* %.0.326 to i8*
  %43 = call i1 @fpga_fifo_exist_1(i8* %42)
  br i1 %43, label %44, label %45

; <label>:44:                                     ; preds = %41
  call fastcc void @streamcpy_hls.p0struct.ap_uint.3(%struct.ap_uint.3* %.01.327, %struct.ap_uint.3* %.0.326)
  br label %56

; <label>:45:                                     ; preds = %41
  %.0.3.028 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 3, i32 0
  %.01.3.029 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 3, i32 0
  %46 = bitcast %struct.ap_int_base.4* %.0.3.028 to i8*
  %47 = call i1 @fpga_fifo_exist_1(i8* %46)
  br i1 %47, label %48, label %49

; <label>:48:                                     ; preds = %45
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.4(%struct.ap_int_base.4* %.01.3.029, %struct.ap_int_base.4* %.0.3.028)
  br label %56

; <label>:49:                                     ; preds = %45
  %.0.3.0.030 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 3, i32 0, i32 0
  %.01.3.0.031 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 3, i32 0, i32 0
  %50 = bitcast %struct.ssdm_int.5* %.0.3.0.030 to i8*
  %51 = call i1 @fpga_fifo_exist_1(i8* %50)
  br i1 %51, label %52, label %53

; <label>:52:                                     ; preds = %49
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.5(%struct.ssdm_int.5* %.01.3.0.031, %struct.ssdm_int.5* %.0.3.0.030)
  br label %56

; <label>:53:                                     ; preds = %49
  %.01.3.0.0.033.gep59 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 3, i32 0, i32 0, i32 0
  %54 = bitcast i1* %.01.3.0.0.033.gep59 to i8*
  %.0.3.0.0.032.gep60 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 3, i32 0, i32 0, i32 0
  %55 = bitcast i1* %.0.3.0.0.032.gep60 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %54, i8* align 1 %55, i64 1, i1 false)
  br label %56

; <label>:56:                                     ; preds = %53, %52, %48, %44
  %.0.434 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 4
  %.01.435 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 4
  %57 = bitcast %struct.ap_uint.3* %.0.434 to i8*
  %58 = call i1 @fpga_fifo_exist_1(i8* %57)
  br i1 %58, label %59, label %60

; <label>:59:                                     ; preds = %56
  call fastcc void @streamcpy_hls.p0struct.ap_uint.3(%struct.ap_uint.3* %.01.435, %struct.ap_uint.3* %.0.434)
  br label %71

; <label>:60:                                     ; preds = %56
  %.0.4.036 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 4, i32 0
  %.01.4.037 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 4, i32 0
  %61 = bitcast %struct.ap_int_base.4* %.0.4.036 to i8*
  %62 = call i1 @fpga_fifo_exist_1(i8* %61)
  br i1 %62, label %63, label %64

; <label>:63:                                     ; preds = %60
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.4(%struct.ap_int_base.4* %.01.4.037, %struct.ap_int_base.4* %.0.4.036)
  br label %71

; <label>:64:                                     ; preds = %60
  %.0.4.0.038 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 4, i32 0, i32 0
  %.01.4.0.039 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 4, i32 0, i32 0
  %65 = bitcast %struct.ssdm_int.5* %.0.4.0.038 to i8*
  %66 = call i1 @fpga_fifo_exist_1(i8* %65)
  br i1 %66, label %67, label %68

; <label>:67:                                     ; preds = %64
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.5(%struct.ssdm_int.5* %.01.4.0.039, %struct.ssdm_int.5* %.0.4.0.038)
  br label %71

; <label>:68:                                     ; preds = %64
  %.01.4.0.0.041.gep61 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 4, i32 0, i32 0, i32 0
  %69 = bitcast i1* %.01.4.0.0.041.gep61 to i8*
  %.0.4.0.0.040.gep62 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 4, i32 0, i32 0, i32 0
  %70 = bitcast i1* %.0.4.0.0.040.gep62 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %69, i8* align 1 %70, i64 1, i1 false)
  br label %71

; <label>:71:                                     ; preds = %68, %67, %63, %59
  %.0.542 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 5
  %.01.543 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 5
  %72 = bitcast %struct.ap_uint.3* %.0.542 to i8*
  %73 = call i1 @fpga_fifo_exist_1(i8* %72)
  br i1 %73, label %74, label %75

; <label>:74:                                     ; preds = %71
  call fastcc void @streamcpy_hls.p0struct.ap_uint.3(%struct.ap_uint.3* %.01.543, %struct.ap_uint.3* %.0.542)
  br label %86

; <label>:75:                                     ; preds = %71
  %.0.5.044 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 5, i32 0
  %.01.5.045 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 5, i32 0
  %76 = bitcast %struct.ap_int_base.4* %.0.5.044 to i8*
  %77 = call i1 @fpga_fifo_exist_1(i8* %76)
  br i1 %77, label %78, label %79

; <label>:78:                                     ; preds = %75
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.4(%struct.ap_int_base.4* %.01.5.045, %struct.ap_int_base.4* %.0.5.044)
  br label %86

; <label>:79:                                     ; preds = %75
  %.0.5.0.046 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 5, i32 0, i32 0
  %.01.5.0.047 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 5, i32 0, i32 0
  %80 = bitcast %struct.ssdm_int.5* %.0.5.0.046 to i8*
  %81 = call i1 @fpga_fifo_exist_1(i8* %80)
  br i1 %81, label %82, label %83

; <label>:82:                                     ; preds = %79
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.5(%struct.ssdm_int.5* %.01.5.0.047, %struct.ssdm_int.5* %.0.5.0.046)
  br label %86

; <label>:83:                                     ; preds = %79
  %.01.5.0.0.049.gep63 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 5, i32 0, i32 0, i32 0
  %84 = bitcast i1* %.01.5.0.0.049.gep63 to i8*
  %.0.5.0.0.048.gep64 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 5, i32 0, i32 0, i32 0
  %85 = bitcast i1* %.0.5.0.0.048.gep64 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %84, i8* align 1 %85, i64 1, i1 false)
  br label %86

; <label>:86:                                     ; preds = %83, %82, %78, %74
  %.0.650 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 6
  %.01.651 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 6
  %87 = bitcast %struct.ap_uint.3* %.0.650 to i8*
  %88 = call i1 @fpga_fifo_exist_1(i8* %87)
  br i1 %88, label %89, label %90

; <label>:89:                                     ; preds = %86
  call fastcc void @streamcpy_hls.p0struct.ap_uint.3(%struct.ap_uint.3* %.01.651, %struct.ap_uint.3* %.0.650)
  br label %ret

; <label>:90:                                     ; preds = %86
  %.0.6.052 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 6, i32 0
  %.01.6.053 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 6, i32 0
  %91 = bitcast %struct.ap_int_base.4* %.0.6.052 to i8*
  %92 = call i1 @fpga_fifo_exist_1(i8* %91)
  br i1 %92, label %93, label %94

; <label>:93:                                     ; preds = %90
  call fastcc void @streamcpy_hls.p0struct.ap_int_base.4(%struct.ap_int_base.4* %.01.6.053, %struct.ap_int_base.4* %.0.6.052)
  br label %ret

; <label>:94:                                     ; preds = %90
  %.0.6.0.054 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 6, i32 0, i32 0
  %.01.6.0.055 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 6, i32 0, i32 0
  %95 = bitcast %struct.ssdm_int.5* %.0.6.0.054 to i8*
  %96 = call i1 @fpga_fifo_exist_1(i8* %95)
  br i1 %96, label %97, label %98

; <label>:97:                                     ; preds = %94
  call fastcc void @streamcpy_hls.p0struct.ssdm_int.5(%struct.ssdm_int.5* %.01.6.0.055, %struct.ssdm_int.5* %.0.6.0.054)
  br label %ret

; <label>:98:                                     ; preds = %94
  %.01.6.0.0.057.gep65 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %0, i32 0, i32 0, i32 6, i32 0, i32 0, i32 0
  %99 = bitcast i1* %.01.6.0.0.057.gep65 to i8*
  %.0.6.0.0.056.gep66 = getelementptr %"class.hls::stream.6", %"class.hls::stream.6"* %1, i32 0, i32 0, i32 6, i32 0, i32 0, i32 0
  %100 = bitcast i1* %.0.6.0.0.056.gep66 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %99, i8* align 1 %100, i64 1, i1 false)
  br label %ret

ret:                                              ; preds = %98, %97, %93, %89, %7, %entry
  ret void
}

declare i1 @fpga_fifo_exist_16(i8*) local_unnamed_addr

; Function Attrs: argmemonly noinline
define internal fastcc void @"streamcpy_hls.p0class.hls::stream.6"(%"class.hls::stream.6"* noalias nocapture align 512, %"class.hls::stream.6"* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %"class.hls::stream.6"
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %"class.hls::stream.6"* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_16(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %"class.hls::stream.6"* %2 to i8*
  %6 = bitcast %"class.hls::stream.6"* %1 to i8*
  call void @fpga_fifo_pop_16(i8* %5, i8* %6)
  %7 = load volatile %"class.hls::stream.6", %"class.hls::stream.6"* %2
  %8 = bitcast %"class.hls::stream.6"* %2 to i8*
  %9 = bitcast %"class.hls::stream.6"* %0 to i8*
  call void @fpga_fifo_push_16(i8* %8, i8* %9)
  br label %empty, !llvm.loop !19

ret:                                              ; preds = %empty
  %10 = bitcast %"class.hls::stream.6"* %1 to i8*
  %11 = bitcast %"class.hls::stream.6"* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 16, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ap_uint.8(%struct.ap_uint.8* noalias nocapture align 512, %struct.ap_uint.8* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ap_uint.8
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ap_uint.8* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_8(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ap_uint.8* %2 to i8*
  %6 = bitcast %struct.ap_uint.8* %1 to i8*
  call void @fpga_fifo_pop_8(i8* %5, i8* %6)
  %7 = load volatile %struct.ap_uint.8, %struct.ap_uint.8* %2
  %8 = bitcast %struct.ap_uint.8* %2 to i8*
  %9 = bitcast %struct.ap_uint.8* %0 to i8*
  call void @fpga_fifo_push_8(i8* %8, i8* %9)
  br label %empty, !llvm.loop !20

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ap_uint.8* %1 to i8*
  %11 = bitcast %struct.ap_uint.8* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 8, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ap_int_base.9(%struct.ap_int_base.9* noalias nocapture align 512, %struct.ap_int_base.9* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ap_int_base.9
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ap_int_base.9* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_8(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ap_int_base.9* %2 to i8*
  %6 = bitcast %struct.ap_int_base.9* %1 to i8*
  call void @fpga_fifo_pop_8(i8* %5, i8* %6)
  %7 = load volatile %struct.ap_int_base.9, %struct.ap_int_base.9* %2
  %8 = bitcast %struct.ap_int_base.9* %2 to i8*
  %9 = bitcast %struct.ap_int_base.9* %0 to i8*
  call void @fpga_fifo_push_8(i8* %8, i8* %9)
  br label %empty, !llvm.loop !21

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ap_int_base.9* %1 to i8*
  %11 = bitcast %struct.ap_int_base.9* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 8, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ssdm_int.10(%struct.ssdm_int.10* noalias nocapture align 512, %struct.ssdm_int.10* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ssdm_int.10
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ssdm_int.10* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_8(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ssdm_int.10* %2 to i8*
  %6 = bitcast %struct.ssdm_int.10* %1 to i8*
  call void @fpga_fifo_pop_8(i8* %5, i8* %6)
  %7 = load volatile %struct.ssdm_int.10, %struct.ssdm_int.10* %2
  %8 = bitcast %struct.ssdm_int.10* %2 to i8*
  %9 = bitcast %struct.ssdm_int.10* %0 to i8*
  call void @fpga_fifo_push_8(i8* %8, i8* %9)
  br label %empty, !llvm.loop !22

ret:                                              ; preds = %empty
  %10 = bitcast %struct.ssdm_int.10* %1 to i8*
  %11 = bitcast %struct.ssdm_int.10* %0 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 8, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ap_uint.11(%struct.ap_uint.11* noalias nocapture, %struct.ap_uint.11* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ap_uint.11
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ap_uint.11* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_1(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ap_uint.11* %2 to i8*
  %6 = bitcast %struct.ap_uint.11* %1 to i8*
  call void @fpga_fifo_pop_1(i8* %5, i8* %6)
  %7 = load volatile %struct.ap_uint.11, %struct.ap_uint.11* %2
  %8 = bitcast %struct.ap_uint.11* %2 to i8*
  %9 = bitcast %struct.ap_uint.11* %0 to i8*
  call void @fpga_fifo_push_1(i8* %8, i8* %9)
  br label %empty, !llvm.loop !23

ret:                                              ; preds = %empty
  %10 = getelementptr inbounds %struct.ap_uint.11, %struct.ap_uint.11* %1, i32 0, i32 0, i32 0, i32 0
  %11 = getelementptr inbounds %struct.ap_uint.11, %struct.ap_uint.11* %0, i32 0, i32 0, i32 0, i32 0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 1, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ap_int_base.12(%struct.ap_int_base.12* noalias nocapture, %struct.ap_int_base.12* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ap_int_base.12
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ap_int_base.12* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_1(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ap_int_base.12* %2 to i8*
  %6 = bitcast %struct.ap_int_base.12* %1 to i8*
  call void @fpga_fifo_pop_1(i8* %5, i8* %6)
  %7 = load volatile %struct.ap_int_base.12, %struct.ap_int_base.12* %2
  %8 = bitcast %struct.ap_int_base.12* %2 to i8*
  %9 = bitcast %struct.ap_int_base.12* %0 to i8*
  call void @fpga_fifo_push_1(i8* %8, i8* %9)
  br label %empty, !llvm.loop !24

ret:                                              ; preds = %empty
  %10 = getelementptr inbounds %struct.ap_int_base.12, %struct.ap_int_base.12* %1, i32 0, i32 0, i32 0
  %11 = getelementptr inbounds %struct.ap_int_base.12, %struct.ap_int_base.12* %0, i32 0, i32 0, i32 0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 1, i1 false)
  ret void
}

; Function Attrs: argmemonly noinline
define internal fastcc void @streamcpy_hls.p0struct.ssdm_int.13(%struct.ssdm_int.13* noalias nocapture, %struct.ssdm_int.13* noalias nocapture) unnamed_addr #3 {
entry:
  %2 = alloca %struct.ssdm_int.13
  br label %empty

empty:                                            ; preds = %push, %entry
  %3 = bitcast %struct.ssdm_int.13* %1 to i8*
  %4 = call i1 @fpga_fifo_not_empty_1(i8* %3)
  br i1 %4, label %push, label %ret

push:                                             ; preds = %empty
  %5 = bitcast %struct.ssdm_int.13* %2 to i8*
  %6 = bitcast %struct.ssdm_int.13* %1 to i8*
  call void @fpga_fifo_pop_1(i8* %5, i8* %6)
  %7 = load volatile %struct.ssdm_int.13, %struct.ssdm_int.13* %2
  %8 = bitcast %struct.ssdm_int.13* %2 to i8*
  %9 = bitcast %struct.ssdm_int.13* %0 to i8*
  call void @fpga_fifo_push_1(i8* %8, i8* %9)
  br label %empty, !llvm.loop !25

ret:                                              ; preds = %empty
  %10 = getelementptr inbounds %struct.ssdm_int.13, %struct.ssdm_int.13* %1, i32 0, i32 0
  %11 = getelementptr inbounds %struct.ssdm_int.13, %struct.ssdm_int.13* %0, i32 0, i32 0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 1, i1 false)
  ret void
}

; Function Attrs: noinline
define internal fastcc void @copy_out(%struct.lane_data*, %struct.lane_data* noalias align 512, %struct.channel_vec*, %struct.channel_vec* noalias align 512, %struct.channel_scal*, %struct.channel_scal* noalias align 512, %"class.hls::stream"*, %"class.hls::stream"* noalias align 512, %"class.hls::stream.6"*, %"class.hls::stream.6"* noalias align 512, %"class.hls::stream.6"*, %"class.hls::stream.6"* noalias align 512) unnamed_addr #5 {
entry:
  call fastcc void @onebyonecpy_hls.p0struct.lane_data(%struct.lane_data* %0, %struct.lane_data* align 512 %1)
  call fastcc void @onebyonecpy_hls.p0struct.channel_vec(%struct.channel_vec* %2, %struct.channel_vec* align 512 %3)
  call fastcc void @onebyonecpy_hls.p0struct.channel_scal(%struct.channel_scal* %4, %struct.channel_scal* align 512 %5)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream"(%"class.hls::stream"* %6, %"class.hls::stream"* align 512 %7)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream.6"(%"class.hls::stream.6"* %8, %"class.hls::stream.6"* align 512 %9)
  call fastcc void @"onebyonecpy_hls.p0class.hls::stream.6"(%"class.hls::stream.6"* %10, %"class.hls::stream.6"* align 512 %11)
  ret void
}

declare void @apatb_memRead_hw(i8, i8, i16, i8, i8, i16, i16, i8, i32, i8, i8, i8, i8, i8, i8, i8, i32, i8, i8, i32, %struct.lane_data*, %struct.channel_vec*, %struct.channel_scal*, %"class.hls::stream"*, %"class.hls::stream.6"*, %"class.hls::stream.6"*)

define void @memRead_hw_stub_wrapper(i8, i8, i16, i8, i8, i16, i16, i8, i32, i8, i8, i8, i8, i8, i8, i8, i32, i8, i8, i32, %struct.lane_data*, %struct.channel_vec*, %struct.channel_scal*, %"class.hls::stream"*, %"class.hls::stream.6"*, %"class.hls::stream.6"*) #6 {
entry:
  call void @copy_out(%struct.lane_data* null, %struct.lane_data* %20, %struct.channel_vec* null, %struct.channel_vec* %21, %struct.channel_scal* null, %struct.channel_scal* %22, %"class.hls::stream"* null, %"class.hls::stream"* %23, %"class.hls::stream.6"* null, %"class.hls::stream.6"* %24, %"class.hls::stream.6"* null, %"class.hls::stream.6"* %25)
  call void @memRead_hw_stub(i8 %0, i8 %1, i16 %2, i8 %3, i8 %4, i16 %5, i16 %6, i8 %7, i32 %8, i8 %9, i8 %10, i8 %11, i8 %12, i8 %13, i8 %14, i8 %15, i32 %16, i8 %17, i8 %18, i32 %19, %struct.lane_data* %20, %struct.channel_vec* %21, %struct.channel_scal* %22, %"class.hls::stream"* %23, %"class.hls::stream.6"* %24, %"class.hls::stream.6"* %25)
  call void @copy_in(%struct.lane_data* null, %struct.lane_data* %20, %struct.channel_vec* null, %struct.channel_vec* %21, %struct.channel_scal* null, %struct.channel_scal* %22, %"class.hls::stream"* null, %"class.hls::stream"* %23, %"class.hls::stream.6"* null, %"class.hls::stream.6"* %24, %"class.hls::stream.6"* null, %"class.hls::stream.6"* %25)
  ret void
}

declare void @memRead_hw_stub(i8, i8, i16, i8, i8, i16, i16, i8, i32, i8, i8, i8, i8, i8, i8, i8, i32, i8, i8, i32, %struct.lane_data*, %struct.channel_vec*, %struct.channel_scal*, %"class.hls::stream"*, %"class.hls::stream.6"*, %"class.hls::stream.6"*)

declare i1 @fpga_fifo_not_empty_4(i8*)

declare i1 @fpga_fifo_not_empty_8(i8*)

declare i1 @fpga_fifo_not_empty_2(i8*)

declare i1 @fpga_fifo_not_empty_1(i8*)

declare i1 @fpga_fifo_not_empty_16(i8*)

declare void @fpga_fifo_pop_4(i8*, i8*)

declare void @fpga_fifo_pop_8(i8*, i8*)

declare void @fpga_fifo_pop_2(i8*, i8*)

declare void @fpga_fifo_pop_1(i8*, i8*)

declare void @fpga_fifo_pop_16(i8*, i8*)

declare void @fpga_fifo_push_4(i8*, i8*)

declare void @fpga_fifo_push_8(i8*, i8*)

declare void @fpga_fifo_push_2(i8*, i8*)

declare void @fpga_fifo_push_1(i8*, i8*)

declare void @fpga_fifo_push_16(i8*, i8*)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { noinline "fpga.wrapper.func"="copyin" }
attributes #2 = { noinline "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline "fpga.wrapper.func"="streamcpy_hls" }
attributes #4 = { argmemonly nounwind }
attributes #5 = { noinline "fpga.wrapper.func"="copyout" }
attributes #6 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.rotate.disable"}
!7 = distinct !{!7, !6}
!8 = distinct !{!8, !6}
!9 = distinct !{!9, !6}
!10 = distinct !{!10, !6}
!11 = distinct !{!11, !6}
!12 = distinct !{!12, !6}
!13 = distinct !{!13, !6}
!14 = distinct !{!14, !6}
!15 = distinct !{!15, !6}
!16 = distinct !{!16, !6}
!17 = distinct !{!17, !6}
!18 = distinct !{!18, !6}
!19 = distinct !{!19, !6}
!20 = distinct !{!20, !6}
!21 = distinct !{!21, !6}
!22 = distinct !{!22, !6}
!23 = distinct !{!23, !6}
!24 = distinct !{!24, !6}
!25 = distinct !{!25, !6}
