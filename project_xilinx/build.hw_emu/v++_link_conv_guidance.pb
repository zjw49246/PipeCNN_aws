
�
v++_link_conv$58a81a98-9579-4d89-ac2e-e2c6478cef96�v++ --xp param:compiler.lockFlowCritSlackThreshold=0 --xp vivado_param:hd.routingContainmentAreaExpansion=true --xp vivado_param:hd.supportClockNetCrossDiffReconfigurablePartitions=1 --xp vivado_param:bitstream.enablePR=4123 --xp vivado_param:physynth.ultraRAMOptOutput=false --xp vivado_prop:run.__KERNEL__.{STEPS.SYNTH_DESIGN.ARGS.MAX_URAM_CASCADE_HEIGHT}={1} --xp vivado_param:synth.elaboration.rodinMoreOptions={rt::set_parameter disableOregPackingUram true}  -t hw_emu --platform /home/zhoujw/FPGA/aws-fpga/Vitis/aws_platform/xilinx_aws-vu9p-f1_shell-v04261818_201920_2/xilinx_aws-vu9p-f1_shell-v04261818_201920_2.xpfm --save-temps -g --profile_kernel data:all:all:all --profile_kernel stall:all:all:all --define VGG16 --temp_dir ./build.hw_emu -l -obuild.hw_emu/conv.xclbin tmp.hw_emu/memRead.xo tmp.hw_emu/coreConv.xo tmp.hw_emu/memWrite.xo tmp.hw_emu/maxPool.xo --config config_sp.u50 *b"^/home/zhoujw/FPGA/PipeCNN/project_xilinx/build.hw_emu/reports/link/v++_link_conv_guidance.html2S"O/home/zhoujw/FPGA/PipeCNN/project_xilinx/build.hw_emu/v++_link_conv_guidance.pbB�
config_sp.u50�kernel_frequency=0:300

[connectivity]
#sp=<compute_unit_name>.<interface_name>:<sptag[min:max]>
#sp=DataLoad_1.A_in:HBM[0]
#sp=DataLoad_1.C_in:HBM[2]
#sp=DataStore_1.B_out:HBM[1]
#sp=DataStore_1.D_out:HBM[3]

#stream_connect=<cu_name>.<output_port>:<cu_name>.<input_port>:[<fifo_depth>]
stream_connect=memRead_1.bias_out:coreConv_1.bias_in
stream_connect=memRead_1.weight_out:coreConv_1.weight_in
stream_connect=memRead_1.data_out:coreConv_1.data_in
##VGG connection
#stream_connect=coreConv_1.conv_out:memWrite_1.conv_in
##ResNet connection
stream_connect=coreConv_1.conv_out:batchNorm_1.conv_in
stream_connect=coreConv_1.bypass_out:memWrite_1.bypass_in
stream_connect=batchNorm_1.bn_out:memWrite_1.bn_in


##used for pipelined pooling
#stream_connect=memWrite_1.pool_sync_out:maxPool_1.pool_sync_in

#nk=<kernal_name>:#:<cu_name1>.<cu_name2>...<cu_name#>
#nk=DataLoad:1:DataLoad_1
#nk=DataStore:1:DataStore_1

[vivado]
##dump all waveforms
prop=fileset.sim_1.xsim.elaborate.debug_level=all