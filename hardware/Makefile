RTL_NAME_FILE = rtl


LINT_DEFINES = -DLINT=1

lint:
	verilator --lint-only -Wall -f $(RTL_NAME_FILE).f $(IGNORE_WARNINGS) $(LINT_DEFINES)

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

mesa: regen_sources sim_build

FPU_ROOT_PATH = cvfpu
FPU_PWD = $(FPU_ROOT_PATH)/src


IGNORE_WARNINGS = -Wno-WIDTHTRUNC \
				-Wno-WIDTHEXPAND \
				-Wno-USERWARN \
				-Wno-ASCRANGE \
				-Wno-SPLITVAR \
				-Wno-UNSIGNED \
				-Wno-UNOPTFLAT

.PHONY: regen_sources
regen_sources:
	$(VERILATOR) -cc --timing --trace --trace-structs -f rtl_core.f --top-module $(SIM_TOP) -Mdir $(OBJ_DIR) $(IGNORE_WARNINGS)\
	    --CFLAGS "-shared -fPIC" \
		-I$(FPU_PWD) \
		-I$(FPU_PWD)/common_cells/src \
		-I$(FPU_PWD)/common_cells/include \
		-I$(FPU_ROOT_PATH)/vendor/openc910/C910_RTL_FACTORY/gen_rtl/vfdsu/rtl/ \
		-I$(FPU_ROOT_PATH)/vendor/openc910/C910_RTL_FACTORY/gen_rtl/clk/rtl/

.PHONY: sim_build
sim_build:
	make -C $(OBJ_DIR) -f V$(SIM_TOP).mk -j 5
	g++ -o $(OBJ_DIR)/verilated_dpi.so /usr/share/verilator/include/verilated_dpi.cpp -pthread -lpthread -latomic -shared -fPIC -lm -I/usr/share/verilator/include -I/usr/share/verilator/include/vltstd
