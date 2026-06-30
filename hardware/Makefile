RTL_NAME_FILE = rtl

IGNORE_WARNINGS = -Wno-ASCRANGE -Wno-WIDTHEXPAND

LINT_DEFINES = -DLINT=1

lint:
	verilator --lint-only -Wall -f $(RTL_NAME_FILE).f $(IGNORE_WARNINGS)

.PHONY: lint

tb:
	cd tb/ && make && cd ../

.PHONY: tb

rebuild:
	cd tb/ && make clean && make && cd ../

.PHONY: rebuild

VERILATOR=verilator
OBJ_DIR=build
SIM_TOP=top_env

WRAPPER_EXTERN_CPP = sim/wrapper.cpp
WRAPPER_EXTERN_HPP = sim/wrapper.h

regen_sources:
	$(VERILATOR) -cc --timing --trace -f rtl_top.f --top-module $(SIM_TOP) -Mdir $(OBJ_DIR) $(LINT_DEFINES) $(IGNORE_WARNINGS)\
	    --CFLAGS "-shared -fPIC"
	cat $(WRAPPER_EXTERN_CPP) >> $(OBJ_DIR)/V$(SIM_TOP).cpp
	cat $(WRAPPER_EXTERN_HPP) >> $(OBJ_DIR)/V$(SIM_TOP).h

sim_build:
	make -C $(OBJ_DIR) -f V$(SIM_TOP).mk -j 5
	g++ -o $(OBJ_DIR)/verilated_dpi.so /usr/share/verilator/include/verilated_dpi.cpp -pthread -lpthread -latomic -shared -fPIC -lm -I/usr/share/verilator/include -I/usr/share/verilator/include/vltstd
