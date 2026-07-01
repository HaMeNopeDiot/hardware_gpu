// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP_ENV__DPI_H_
#define VERILATED_VTOP_ENV__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI EXPORTS
    // DPI export at tb/top_env.sv:222:16
    extern svLogic is_done();
    // DPI export at tb/top_env.sv:102:20
    extern svLogic load_vertex_buffer_mem();
    // DPI export at tb/top_env.sv:97:20
    extern svLogic load_vertex_shader_mem();
    // DPI export at tb/top_env.sv:76:24
    extern int read_data_mem(int address);
    // DPI export at tb/top_env.sv:86:24
    extern int read_fetcher_mem(int address);
    // DPI export at tb/top_env.sv:189:6
    extern void start();
    // DPI export at tb/top_env.sv:81:20
    extern svLogic write_data_mem(int address, int data);
    // DPI export at tb/top_env.sv:91:20
    extern svLogic write_fetcher_mem(int address, int data);

#ifdef __cplusplus
}
#endif

#endif  // guard
