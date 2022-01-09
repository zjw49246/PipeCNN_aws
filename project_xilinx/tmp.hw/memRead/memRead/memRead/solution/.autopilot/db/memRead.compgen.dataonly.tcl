# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_control {
data_dim1 { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 16
	offset_end 23
}
data_dim2 { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
data_dim1xdim2 { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 32
	offset_end 39
}
weight_dim1 { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 40
	offset_end 47
}
weight_dim2 { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 48
	offset_end 55
}
weight_dim3 { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 56
	offset_end 63
}
weight_dim4_div_lane { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 64
	offset_end 71
}
weight_dim1x2 { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 72
	offset_end 79
}
weight_dim1x2x3 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 80
	offset_end 87
}
conv_x { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 88
	offset_end 95
}
stride { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 96
	offset_end 103
}
padding { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 104
	offset_end 111
}
split { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 112
	offset_end 119
}
group_num_x { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 120
	offset_end 127
}
group_num_y { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 128
	offset_end 135
}
group_rem_size_x { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 136
	offset_end 143
}
group_rem_size_xyz { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 144
	offset_end 151
}
win_size_x { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 152
	offset_end 159
}
win_size_y { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 160
	offset_end 167
}
win_size_xyz { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 168
	offset_end 175
}
bottom { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 176
	offset_end 187
}
weights { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 188
	offset_end 199
}
bias { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 200
	offset_end 211
}
ap_start { }
ap_done { }
ap_ready { }
ap_continue { }
ap_idle { }
event_start { }
}
dict set axilite_register_dict control $port_control


