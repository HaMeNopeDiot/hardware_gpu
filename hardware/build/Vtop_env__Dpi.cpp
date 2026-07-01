// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions
//
// Verilator compiles this file in when DPI functions are used.
// If you have multiple Verilated designs with the same DPI exported
// function names, you will get multiple definition link errors from here.
// This is an unfortunate result of the DPI specification.
// To solve this, either
//    1. Call Vtop_env::{export_function} instead,
//       and do not even bother to compile this file
// or 2. Compile all __Dpi.cpp files in the same compiler run,
//       and #ifdefs already inserted here will sort everything out.

#include "Vtop_env__Dpi.h"
#include "Vtop_env.h"

#ifndef VL_DPIDECL_is_done_
#define VL_DPIDECL_is_done_
svLogic is_done() {
    // DPI export at tb/top_env.sv:222:16
    return Vtop_env::is_done();
}
#endif

#ifndef VL_DPIDECL_load_vertex_buffer_mem_
#define VL_DPIDECL_load_vertex_buffer_mem_
svLogic load_vertex_buffer_mem() {
    // DPI export at tb/top_env.sv:102:20
    return Vtop_env::load_vertex_buffer_mem();
}
#endif

#ifndef VL_DPIDECL_load_vertex_shader_mem_
#define VL_DPIDECL_load_vertex_shader_mem_
svLogic load_vertex_shader_mem() {
    // DPI export at tb/top_env.sv:97:20
    return Vtop_env::load_vertex_shader_mem();
}
#endif

#ifndef VL_DPIDECL_read_data_mem_
#define VL_DPIDECL_read_data_mem_
int read_data_mem(int address) {
    // DPI export at tb/top_env.sv:76:24
    return Vtop_env::read_data_mem(address);
}
#endif

#ifndef VL_DPIDECL_read_fetcher_mem_
#define VL_DPIDECL_read_fetcher_mem_
int read_fetcher_mem(int address) {
    // DPI export at tb/top_env.sv:86:24
    return Vtop_env::read_fetcher_mem(address);
}
#endif

#ifndef VL_DPIDECL_start_
#define VL_DPIDECL_start_
void start() {
    // DPI export at tb/top_env.sv:189:6
    return Vtop_env::start();
}
#endif

#ifndef VL_DPIDECL_write_data_mem_
#define VL_DPIDECL_write_data_mem_
svLogic write_data_mem(int address, int data) {
    // DPI export at tb/top_env.sv:81:20
    return Vtop_env::write_data_mem(address, data);
}
#endif

#ifndef VL_DPIDECL_write_fetcher_mem_
#define VL_DPIDECL_write_fetcher_mem_
svLogic write_fetcher_mem(int address, int data) {
    // DPI export at tb/top_env.sv:91:20
    return Vtop_env::write_fetcher_mem(address, data);
}
#endif

