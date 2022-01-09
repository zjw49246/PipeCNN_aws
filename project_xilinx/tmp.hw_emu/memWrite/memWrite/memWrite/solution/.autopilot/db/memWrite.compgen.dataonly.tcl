# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_control {
out_dim1 { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 16
	offset_end 23
}
out_dim2 { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
out_dim3 { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 32
	offset_end 39
}
out_dim1xbatch { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 40
	offset_end 47
}
out_dim1x2xbatch { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 48
	offset_end 55
}
batch_indx_dim1 { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 56
	offset_end 63
}
batch_indx_dim2 { 
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
pool_on { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 80
	offset_end 87
}
pool_size { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 88
	offset_end 95
}
pool_stride { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 96
	offset_end 103
}
top { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 104
	offset_end 115
}
ap_start { }
ap_done { }
ap_ready { }
ap_continue { }
ap_idle { }
event_start { }
}
dict set axilite_register_dict control $port_control


