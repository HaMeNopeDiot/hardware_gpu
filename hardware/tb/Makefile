# Makefile

# defaults
SIM ?= verilator
TOPLEVEL_LANG ?= verilog

# SIM_ARGS += -Wno-WIDTHTRUNC

SIM_DIR = sim
VCD_PATH = $(SIM_DIR)/output.vcd

COMPILE_ARGS += -Wno-WIDTHTRUNC \
				-Wno-WIDTHEXPAND \
				-Wno-USERWARN \
				-Wno-ASCRANGE \
				-Wno-SPLITVAR \
				-Wno-UNSIGNED \
				-Wno-UNOPTFLAT \
				-j 5 --timing \
				--timescale 1ns/1ps \
				-DTAG_TYPE="logic[3:0]"


FPU_ROOT_PATH = ../cvfpu

FPU_PWD = $(FPU_ROOT_PATH)/src
MAIN_PWD = ../rtl

VERILOG_SOURCES +=  $(FPU_PWD)/common_cells/src/cf_math_pkg.sv \
					$(FPU_PWD)/fpnew_pkg.sv \
					$(FPU_PWD)/fpnew_top.sv \
					$(MAIN_PWD)/utils/base_pkg.sv \
					$(MAIN_PWD)/fpu_dummy.sv \
					$(MAIN_PWD)/handshake_fpu_pkg.sv \
					$(MAIN_PWD)/tu_pkg.sv \
					$(MAIN_PWD)/tu_fpu_fsm.sv \
					$(MAIN_PWD)/tu_regfile.sv \
					$(MAIN_PWD)/tu_alu.sv \
					$(MAIN_PWD)/thread_unit.sv \
					$(MAIN_PWD)/interfaces/reg_if.sv \
					$(MAIN_PWD)/interfaces/simple_bus_if.sv \
					$(MAIN_PWD)/interfaces/simple_hndh_if.sv \
					$(MAIN_PWD)/interfaces/ahb4_bus_if.sv \
					$(MAIN_PWD)/utils/ahb_pkg.sv \
					$(MAIN_PWD)/utils/ahb_master.sv \
					$(MAIN_PWD)/core_decoder.sv \
					$(MAIN_PWD)/core_lsu_fsm_pkg.sv \
					$(MAIN_PWD)/core_lsu.sv \
					$(MAIN_PWD)/core_arbiter.sv \
					$(MAIN_PWD)/core.sv

VERILOG_INCLUDE_DIRS += $(FPU_PWD) \
						$(FPU_PWD)/common_cells/src \
						$(FPU_PWD)/common_cells/include \
						$(FPU_ROOT_PATH)/vendor/openc910/C910_RTL_FACTORY/gen_rtl/vfdsu/rtl/ \
						$(FPU_ROOT_PATH)/vendor/openc910/C910_RTL_FACTORY/gen_rtl/clk/rtl/

# use VHDL_SOURCES for VHDL files

# COCOTB_TOPLEVEL is the name of the toplevel module in your Verilog or VHDL file
COCOTB_TOPLEVEL = core#thread_unit#fpnew_top

# COCOTB_TEST_MODULES is the basename of the Python test file(s)
COCOTB_TEST_MODULES = core_top

COCOTB_HDL_TIMEUNIT = 1ns
COCOTB_HDL_TIMEPRECISION = 100ps


SIM_CMD_PREFIX += WAVES=1
EXTRA_ARGS += --trace-structs --trace-vcd --trace --timescale 1ns/1ps
# include cocotb's make rules to take care of the simulator setup
include $(shell cocotb-config --makefiles)/Makefile.sim

run_all: sim
	mv dump.vcd $(VCD_PATH)