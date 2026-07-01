// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.

#include "Vtop_env.h"
#include "Vtop_env__Syms.h"
#include "verilated_dpi.h"


int Vtop_env::read_data_mem(int address) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root::read_data_mem\n"); );
    // Locals
    IData/*31:0*/ address__Vcvt;
    address__Vcvt = 0;
    IData/*31:0*/ read_data_mem__Vfuncrtn__Vcvt;
    read_data_mem__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) {
        __Vfuncnum = Verilated::exportFuncNum("read_data_mem");
    }
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    Vtop_env__Vcb_read_data_mem_t __Vcb = reinterpret_cast<Vtop_env__Vcb_read_data_mem_t>(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    address__Vcvt = (address);
    (*__Vcb)((Vtop_env__Syms*)(__Vscopep->symsp()), address__Vcvt, read_data_mem__Vfuncrtn__Vcvt);
    int read_data_mem__Vfuncrtn;
    read_data_mem__Vfuncrtn = read_data_mem__Vfuncrtn__Vcvt;
    return read_data_mem__Vfuncrtn;
}

svLogic Vtop_env::write_data_mem(int address, int data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root::write_data_mem\n"); );
    // Locals
    IData/*31:0*/ address__Vcvt;
    address__Vcvt = 0;
    IData/*31:0*/ data__Vcvt;
    data__Vcvt = 0;
    CData/*0:0*/ write_data_mem__Vfuncrtn__Vcvt;
    write_data_mem__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) {
        __Vfuncnum = Verilated::exportFuncNum("write_data_mem");
    }
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    Vtop_env__Vcb_write_data_mem_t __Vcb = reinterpret_cast<Vtop_env__Vcb_write_data_mem_t>(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    address__Vcvt = (address);
    data__Vcvt = (data);
    (*__Vcb)((Vtop_env__Syms*)(__Vscopep->symsp()), address__Vcvt, data__Vcvt, write_data_mem__Vfuncrtn__Vcvt);
    svLogic write_data_mem__Vfuncrtn;
    write_data_mem__Vfuncrtn = write_data_mem__Vfuncrtn__Vcvt;
    return write_data_mem__Vfuncrtn;
}

int Vtop_env::read_fetcher_mem(int address) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root::read_fetcher_mem\n"); );
    // Locals
    IData/*31:0*/ address__Vcvt;
    address__Vcvt = 0;
    IData/*31:0*/ read_fetcher_mem__Vfuncrtn__Vcvt;
    read_fetcher_mem__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) {
        __Vfuncnum = Verilated::exportFuncNum("read_fetcher_mem");
    }
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    Vtop_env__Vcb_read_fetcher_mem_t __Vcb = reinterpret_cast<Vtop_env__Vcb_read_fetcher_mem_t>(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    address__Vcvt = (address);
    (*__Vcb)((Vtop_env__Syms*)(__Vscopep->symsp()), address__Vcvt, read_fetcher_mem__Vfuncrtn__Vcvt);
    int read_fetcher_mem__Vfuncrtn;
    read_fetcher_mem__Vfuncrtn = read_fetcher_mem__Vfuncrtn__Vcvt;
    return read_fetcher_mem__Vfuncrtn;
}

svLogic Vtop_env::write_fetcher_mem(int address, int data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root::write_fetcher_mem\n"); );
    // Locals
    IData/*31:0*/ address__Vcvt;
    address__Vcvt = 0;
    IData/*31:0*/ data__Vcvt;
    data__Vcvt = 0;
    CData/*0:0*/ write_fetcher_mem__Vfuncrtn__Vcvt;
    write_fetcher_mem__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) {
        __Vfuncnum = Verilated::exportFuncNum("write_fetcher_mem");
    }
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    Vtop_env__Vcb_write_fetcher_mem_t __Vcb = reinterpret_cast<Vtop_env__Vcb_write_fetcher_mem_t>(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    address__Vcvt = (address);
    data__Vcvt = (data);
    (*__Vcb)((Vtop_env__Syms*)(__Vscopep->symsp()), address__Vcvt, data__Vcvt, write_fetcher_mem__Vfuncrtn__Vcvt);
    svLogic write_fetcher_mem__Vfuncrtn;
    write_fetcher_mem__Vfuncrtn = write_fetcher_mem__Vfuncrtn__Vcvt;
    return write_fetcher_mem__Vfuncrtn;
}

svLogic Vtop_env::load_vertex_shader_mem() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root::load_vertex_shader_mem\n"); );
    // Locals
    CData/*0:0*/ load_vertex_shader_mem__Vfuncrtn__Vcvt;
    load_vertex_shader_mem__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) {
        __Vfuncnum = Verilated::exportFuncNum("load_vertex_shader_mem");
    }
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    Vtop_env__Vcb_load_vertex_shader_mem_t __Vcb = reinterpret_cast<Vtop_env__Vcb_load_vertex_shader_mem_t>(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((Vtop_env__Syms*)(__Vscopep->symsp()), load_vertex_shader_mem__Vfuncrtn__Vcvt);
    svLogic load_vertex_shader_mem__Vfuncrtn;
    load_vertex_shader_mem__Vfuncrtn = load_vertex_shader_mem__Vfuncrtn__Vcvt;
    return load_vertex_shader_mem__Vfuncrtn;
}

svLogic Vtop_env::load_vertex_buffer_mem() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root::load_vertex_buffer_mem\n"); );
    // Locals
    CData/*0:0*/ load_vertex_buffer_mem__Vfuncrtn__Vcvt;
    load_vertex_buffer_mem__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) {
        __Vfuncnum = Verilated::exportFuncNum("load_vertex_buffer_mem");
    }
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    Vtop_env__Vcb_load_vertex_buffer_mem_t __Vcb = reinterpret_cast<Vtop_env__Vcb_load_vertex_buffer_mem_t>(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((Vtop_env__Syms*)(__Vscopep->symsp()), load_vertex_buffer_mem__Vfuncrtn__Vcvt);
    svLogic load_vertex_buffer_mem__Vfuncrtn;
    load_vertex_buffer_mem__Vfuncrtn = load_vertex_buffer_mem__Vfuncrtn__Vcvt;
    return load_vertex_buffer_mem__Vfuncrtn;
}

void Vtop_env::start() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root::start\n"); );
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) {
        __Vfuncnum = Verilated::exportFuncNum("start");
    }
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    Vtop_env__Vcb_start_t __Vcb = reinterpret_cast<Vtop_env__Vcb_start_t>(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((Vtop_env__Syms*)(__Vscopep->symsp()));
}

svLogic Vtop_env::is_done() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root::is_done\n"); );
    // Locals
    CData/*0:0*/ is_done__Vfuncrtn__Vcvt;
    is_done__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) {
        __Vfuncnum = Verilated::exportFuncNum("is_done");
    }
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    Vtop_env__Vcb_is_done_t __Vcb = reinterpret_cast<Vtop_env__Vcb_is_done_t>(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((Vtop_env__Syms*)(__Vscopep->symsp()), is_done__Vfuncrtn__Vcvt);
    svLogic is_done__Vfuncrtn;
    is_done__Vfuncrtn = is_done__Vfuncrtn__Vcvt;
    return is_done__Vfuncrtn;
}
