
VERILATOR=verilator
OBJ_DIR=obj_dir
TOP=top


# Don't change these
COMPILED_RTL_LIBRARY=$(OBJ_DIR)/Vtop__ALL.a $(OBJ_DIR)/verilated.o $(OBJ_DIR)/verilated_threads.o $(OBJ_DIR)/verilated_vcd_c.o $(OBJ_DIR)/verilated_timing.o
WRAPPER_EXTERN_CPP = src/wrapper.cpp
WRAPPER_EXTERN_HPP = src/wrapper.h



compile: compile_verilator_sources
	gcc -o main src/main.c $(COMPILED_RTL_LIBRARY) -pthread -lpthread -latomic -lstdc++ \
			-lm -I/usr/share/verilator/include -I/usr/share/verilator/include/vltstd    \
			/usr/share/verilator/include/verilated_dpi.cpp

compile_verilator_sources: generate_verilator_sources
	make -C $(OBJ_DIR) -f Vtop.mk

.PHONY: generate_verilator_sources
generate_verilator_sources:
	$(VERILATOR) -cc --timing --trace -f rtl.f --top-module top
	cat $(WRAPPER_EXTERN_CPP) >> $(OBJ_DIR)/Vtop.cpp
	cat $(WRAPPER_EXTERN_HPP) >> $(OBJ_DIR)/Vtop.h

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)