## Clock (100 MHz)
set_property PACKAGE_PIN W5 [get_ports CLK]
set_property IOSTANDARD LVCMOS33 [get_ports CLK]

#Buttons 
set_property PACKAGE_PIN U18 [get_ports {SW[0]}]						
	set_property IOSTANDARD LVCMOS33 [get_ports {SW[0]}]
set_property PACKAGE_PIN T18 [get_ports {SW[1]}]						
	set_property IOSTANDARD LVCMOS33 [get_ports {SW[1]}]
set_property PACKAGE_PIN T17 [get_ports {SW[2]}]						
	set_property IOSTANDARD LVCMOS33 [get_ports {SW[2]}]

### Switches (SW[2:0])
#set_property PACKAGE_PIN V17 [get_ports {SW[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {SW[0]}]

#set_property PACKAGE_PIN V16 [get_ports {SW[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {SW[1]}]

#set_property PACKAGE_PIN W16 [get_ports {SW[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {SW[2]}]

## Displays de 7 Segmentos (SEG[6:0])
set_property PACKAGE_PIN W7 [get_ports {SEG[6]}]
set_property PACKAGE_PIN W6 [get_ports {SEG[5]}]
set_property PACKAGE_PIN U8 [get_ports {SEG[4]}]
set_property PACKAGE_PIN V8 [get_ports {SEG[3]}]
set_property PACKAGE_PIN U5 [get_ports {SEG[2]}]
set_property PACKAGE_PIN V5 [get_ports {SEG[1]}]
set_property PACKAGE_PIN U7 [get_ports {SEG[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {SEG[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {SEG[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {SEG[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {SEG[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {SEG[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {SEG[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {SEG[0]}]

## Anodos dos Displays (AN[3:0])
set_property PACKAGE_PIN U2 [get_ports {AN[2]}]
set_property PACKAGE_PIN U4 [get_ports {AN[1]}]
set_property PACKAGE_PIN V4 [get_ports {AN[0]}]
set_property PACKAGE_PIN W4 [get_ports {AN[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {AN[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {AN[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {AN[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {AN[3]}]