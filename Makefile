
VERILATOR=verilator
OBJ_DIR=build
TOP=top_env


# Don't change these
COMPILED_RTL_LIBRARY=$(OBJ_DIR)/Vtop_env__ALL.a $(OBJ_DIR)/verilated.o $(OBJ_DIR)/verilated_threads.o $(OBJ_DIR)/verilated_vcd_c.o $(OBJ_DIR)/verilated_timing.o
WRAPPER_EXTERN_CPP = mesa/src/simulation/wrapper.cpp
WRAPPER_EXTERN_HPP = mesa/src/simulation/wrapper.h

project:
	make -C hardware regen_sources sim_build
	make -C mesa all
