# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_control {
conv_x { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 16
	offset_end 23
}
conv_xy { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
pool_dim1 { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 32
	offset_end 39
}
pool_dim3 { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 40
	offset_end 47
}
pool_dim1x2 { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 48
	offset_end 55
}
pool_size { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 56
	offset_end 63
}
pool_stride { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 64
	offset_end 71
}
padd_offset { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 72
	offset_end 79
}
pool_times { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 80
	offset_end 87
}
pool_group { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 88
	offset_end 95
}
pool_y_bound { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 96
	offset_end 103
}
item_loop_bound { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 104
	offset_end 111
}
load_data_bound { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 112
	offset_end 119
}
write_back_bound { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 120
	offset_end 127
}
pool_win_num_x { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 128
	offset_end 135
}
win_size_x { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 136
	offset_end 143
}
bottom { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 144
	offset_end 155
}
top { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 156
	offset_end 167
}
ap_start { }
ap_done { }
ap_ready { }
ap_continue { }
ap_idle { }
event_start { }
}
dict set axilite_register_dict control $port_control


