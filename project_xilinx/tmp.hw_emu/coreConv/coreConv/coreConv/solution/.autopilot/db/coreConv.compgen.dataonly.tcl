# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_control {
output_num { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 16
	offset_end 23
}
conv_loop_cnt { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
contol { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 32
	offset_end 39
}
frac_w { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 40
	offset_end 47
}
frac_din { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 48
	offset_end 55
}
frac_dout { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 56
	offset_end 63
}
ap_start { }
ap_done { }
ap_ready { }
ap_continue { }
ap_idle { }
event_start { }
}
dict set axilite_register_dict control $port_control


