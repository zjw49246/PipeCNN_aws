; ModuleID = '/home/zhoujw/FPGA/PipeCNN/project_xilinx/tmp.hw_emu/maxPool/maxPool/maxPool/solution/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%struct.channel_scal = type { [2 x i8] }

; Function Attrs: noinline
define void @apatb_maxPool_ir(i8 %conv_x, i16 %conv_xy, i8 %pool_dim1, i16 %pool_dim3, i16 %pool_dim1x2, i8 %pool_size, i8 %pool_stride, i8 %padd_offset, i16 %pool_times, i16 %pool_group, i16 %pool_y_bound, i16 %item_loop_bound, i16 %load_data_bound, i16 %write_back_bound, i8 %pool_win_num_x, i8 %win_size_x, %struct.channel_scal* %bottom, i8* %top) local_unnamed_addr #0 {
entry:
  %bottom_copy = alloca %struct.channel_scal, align 512
  %top_copy = alloca i8, align 512
  call fastcc void @copy_in(%struct.channel_scal* %bottom, %struct.channel_scal* nonnull align 512 %bottom_copy, i8* %top, i8* nonnull align 512 %top_copy)
  call void @apatb_maxPool_hw(i8 %conv_x, i16 %conv_xy, i8 %pool_dim1, i16 %pool_dim3, i16 %pool_dim1x2, i8 %pool_size, i8 %pool_stride, i8 %padd_offset, i16 %pool_times, i16 %pool_group, i16 %pool_y_bound, i16 %item_loop_bound, i16 %load_data_bound, i16 %write_back_bound, i8 %pool_win_num_x, i8 %win_size_x, %struct.channel_scal* %bottom_copy, i8* %top_copy)
  call fastcc void @copy_out(%struct.channel_scal* %bottom, %struct.channel_scal* nonnull align 512 %bottom_copy, i8* %top, i8* nonnull align 512 %top_copy)
  ret void
}

; Function Attrs: noinline
define internal fastcc void @copy_in(%struct.channel_scal*, %struct.channel_scal* noalias align 512, i8* readonly, i8* noalias align 512) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0struct.channel_scal(%struct.channel_scal* align 512 %1, %struct.channel_scal* %0)
  call fastcc void @onebyonecpy_hls.p0i8(i8* align 512 %3, i8* %2)
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
  br label %empty, !llvm.loop !5

ret:                                              ; preds = %empty
  %10 = getelementptr inbounds %struct.channel_scal, %struct.channel_scal* %1, i32 0, i32 0, i32 0
  %11 = getelementptr inbounds %struct.channel_scal, %struct.channel_scal* %0, i32 0, i32 0, i32 0
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %11, i8* align 1 %10, i64 2, i1 false)
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #4

; Function Attrs: argmemonly noinline
define internal fastcc void @onebyonecpy_hls.p0i8(i8* noalias align 512, i8* noalias readonly) unnamed_addr #5 {
entry:
  %2 = icmp eq i8* %0, null
  %3 = icmp eq i8* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* nonnull align 1 %0, i8* nonnull align 1 %1, i64 1, i1 false)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: noinline
define internal fastcc void @copy_out(%struct.channel_scal*, %struct.channel_scal* noalias align 512, i8*, i8* noalias readonly align 512) unnamed_addr #6 {
entry:
  call fastcc void @onebyonecpy_hls.p0struct.channel_scal(%struct.channel_scal* %0, %struct.channel_scal* align 512 %1)
  call fastcc void @onebyonecpy_hls.p0i8(i8* %2, i8* align 512 %3)
  ret void
}

declare void @apatb_maxPool_hw(i8, i16, i8, i16, i16, i8, i8, i8, i16, i16, i16, i16, i16, i16, i8, i8, %struct.channel_scal*, i8*)

define void @maxPool_hw_stub_wrapper(i8, i16, i8, i16, i16, i8, i8, i8, i16, i16, i16, i16, i16, i16, i8, i8, %struct.channel_scal*, i8*) #7 {
entry:
  call void @copy_out(%struct.channel_scal* null, %struct.channel_scal* %16, i8* null, i8* %17)
  call void @maxPool_hw_stub(i8 %0, i16 %1, i8 %2, i16 %3, i16 %4, i8 %5, i8 %6, i8 %7, i16 %8, i16 %9, i16 %10, i16 %11, i16 %12, i16 %13, i8 %14, i8 %15, %struct.channel_scal* %16, i8* %17)
  call void @copy_in(%struct.channel_scal* null, %struct.channel_scal* %16, i8* null, i8* %17)
  ret void
}

declare void @maxPool_hw_stub(i8, i16, i8, i16, i16, i8, i8, i8, i16, i16, i16, i16, i16, i16, i8, i8, %struct.channel_scal*, i8*)

declare i1 @fpga_fifo_not_empty_2(i8*)

declare void @fpga_fifo_pop_2(i8*, i8*)

declare void @fpga_fifo_push_2(i8*, i8*)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { noinline "fpga.wrapper.func"="copyin" }
attributes #2 = { noinline "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline "fpga.wrapper.func"="streamcpy_hls" }
attributes #4 = { argmemonly nounwind }
attributes #5 = { argmemonly noinline "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #6 = { noinline "fpga.wrapper.func"="copyout" }
attributes #7 = { "fpga.wrapper.func"="stub" }

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
