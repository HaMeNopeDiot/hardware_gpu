# Makefile

# defaults
SIM ?= verilator
TOPLEVEL_LANG ?= verilog

# SIM_ARGS += -Wno-WIDTHTRUNC

SIM_DIR = sim
VCD_PATH = $(SIM_DIR)/output.vcd

COMPILE_ARGS += -Wno-WIDTHTRUNC \
				-Wno-WIDTHEXPAND \
				-Wno-WIDTHEXPAND \
				-Wno-USERWARN \
				-Wno-ASCRANGE \
				-Wno-SPLITVAR \
				-Wno-UNSIGNED \
				-Wno-UNOPTFLAT \
				-j 5 --timing \
				--timescale 1ns/1ps \
				-DTagType="logic[1:0]"

PWD = ../src

ROOT_PATH = ..

VERILOG_SOURCES +=  $(PWD)/common_cells/src/cf_math_pkg.sv \
					$(PWD)/fpnew_pkg.sv \
					$(PWD)/fpnew_top.sv

VERILOG_INCLUDE_DIRS += $(PWD) \
						$(PWD)/common_cells/src \
						$(PWD)/common_cells/include \
						$(ROOT_PATH)/vendor/openc910/C910_RTL_FACTORY/gen_rtl/vfdsu/rtl/ \
						$(ROOT_PATH)/vendor/openc910/C910_RTL_FACTORY/gen_rtl/clk/rtl/

# use VHDL_SOURCES for VHDL files

# COCOTB_TOPLEVEL is the name of the toplevel module in your Verilog or VHDL file
COCOTB_TOPLEVEL = fpnew_top

# COCOTB_TEST_MODULES is the basename of the Python test file(s)
COCOTB_TEST_MODULES = fpnew_top

COCOTB_HDL_TIMEUNIT = 1ns
COCOTB_HDL_TIMEPRECISION = 100ps


SIM_CMD_PREFIX += WAVES=1
EXTRA_ARGS += --trace-structs --trace-vcd --trace --timescale 1ns/1ps
# include cocotb's make rules to take care of the simulator setup
include $(shell cocotb-config --makefiles)/Makefile.sim

run_all: sim
	mv dump.vcd $(VCD_PATH)