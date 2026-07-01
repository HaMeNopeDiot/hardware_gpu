// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_env.h for the primary calling header

#include "Vtop_env__pch.h"

void Vtop_env___024root____Vdpiexp_top_env__DOT__read_data_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ &read_data_mem__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__read_data_mem_TOP\n"); );
    // Body
    read_data_mem__Vfuncrtn = vlSymsp->TOP.top_env__DOT__ahb_lsu_mem_u__DOT__mem
        [(0x0000ffffU & address)];
}

void Vtop_env___024root____Vdpiexp_top_env__DOT__write_data_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ data, CData/*0:0*/ &write_data_mem__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__write_data_mem_TOP\n"); );
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    write_data_mem__Vfuncrtn = 0;
    vlSymsp->TOP.top_env__DOT__ahb_lsu_mem_u__DOT__mem[(0x0000ffffU 
                                                        & address)] 
        = data;
}

void Vtop_env___024root____Vdpiexp_top_env__DOT__read_fetcher_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ &read_fetcher_mem__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__read_fetcher_mem_TOP\n"); );
    // Body
    read_fetcher_mem__Vfuncrtn = vlSymsp->TOP.top_env__DOT__ahb_fet_mem_u__DOT__mem
        [(0x0000ffffU & address)];
}

void Vtop_env___024root____Vdpiexp_top_env__DOT__write_fetcher_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ data, CData/*0:0*/ &write_fetcher_mem__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__write_fetcher_mem_TOP\n"); );
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    write_fetcher_mem__Vfuncrtn = 0;
    vlSymsp->TOP.top_env__DOT__ahb_fet_mem_u__DOT__mem[(0x0000ffffU 
                                                        & address)] 
        = data;
}

void Vtop_env___024root____Vdpiexp_top_env__DOT__load_vertex_shader_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, CData/*0:0*/ &load_vertex_shader_mem__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__load_vertex_shader_mem_TOP\n"); );
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    load_vertex_shader_mem__Vfuncrtn = 0;
    VL_READMEM_N(true, 32, 65536, 0, "../hardware/mem/vertex_shader.mem"s
                 ,  &(vlSymsp->TOP.top_env__DOT__ahb_fet_mem_u__DOT__mem)
                 , 0, ~0ULL);
}

void Vtop_env___024root____Vdpiexp_top_env__DOT__load_vertex_buffer_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, CData/*0:0*/ &load_vertex_buffer_mem__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__load_vertex_buffer_mem_TOP\n"); );
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    load_vertex_buffer_mem__Vfuncrtn = 0;
    VL_READMEM_N(true, 32, 65536, 0, "../hardware/mem/vertex_buffer.mem"s
                 ,  &(vlSymsp->TOP.top_env__DOT__ahb_lsu_mem_u__DOT__mem)
                 , 0, ~0ULL);
}

VlCoroutine Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0(Vtop_env___024root* vlSelf);

void Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP(Vtop_env__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP\n"); );
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.top_env__DOT__start__Vstatic__vid[0U] = 0U;
    vlSymsp->TOP.top_env__DOT__start__Vstatic__vid[1U] = 1U;
    vlSymsp->TOP.top_env__DOT__start__Vstatic__vid[2U] = 2U;
    vlSymsp->TOP.top_env__DOT__start__Vstatic__vid[3U] = 3U;
    vlSymsp->TOP.top_env__DOT__start__Vstatic__start_pc = 0U;
    Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0((&vlSymsp->TOP));
    vlSymsp->TOP.__Vm_traceActivity[2U] = 1U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 1U;
}

void Vtop_env___024root____VbeforeTrig_ha024b98c__0(Vtop_env___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_2__0(Vtop_env___024root* vlSelf, QData/*45:0*/ __Vintraval_h063a14d0__0);
VlCoroutine Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_3__0(Vtop_env___024root* vlSelf, QData/*45:0*/ __Vintraval_h063a14d0__1);
VlCoroutine Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_4__0(Vtop_env___024root* vlSelf, QData/*45:0*/ __Vintraval_h063a14d0__2);
VlCoroutine Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_5__0(Vtop_env___024root* vlSelf, QData/*45:0*/ __Vintraval_h063a14d0__3);

VlCoroutine Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vtask_top_env__DOT____VforkTask_0__0__unnamedblk2__DOT__i;
    __Vtask_top_env__DOT____VforkTask_0__0__unnamedblk2__DOT__i = 0;
    CData/*6:0*/ __Vtask_top_env__DOT__apb_write__1__addr;
    __Vtask_top_env__DOT__apb_write__1__addr = 0;
    IData/*31:0*/ __Vtask_top_env__DOT__apb_write__1__data;
    __Vtask_top_env__DOT__apb_write__1__data = 0;
    CData/*3:0*/ __Vtask_top_env__DOT__apb_write__1__strb;
    __Vtask_top_env__DOT__apb_write__1__strb = 0;
    CData/*0:0*/ __Vtask_top_env__DOT__apb_write__1__make_space;
    __Vtask_top_env__DOT__apb_write__1__make_space = 0;
    CData/*6:0*/ __Vtask_top_env__DOT__apb_write__3__addr;
    __Vtask_top_env__DOT__apb_write__3__addr = 0;
    IData/*31:0*/ __Vtask_top_env__DOT__apb_write__3__data;
    __Vtask_top_env__DOT__apb_write__3__data = 0;
    CData/*3:0*/ __Vtask_top_env__DOT__apb_write__3__strb;
    __Vtask_top_env__DOT__apb_write__3__strb = 0;
    CData/*0:0*/ __Vtask_top_env__DOT__apb_write__3__make_space;
    __Vtask_top_env__DOT__apb_write__3__make_space = 0;
    CData/*6:0*/ __Vtask_top_env__DOT__apb_write__5__addr;
    __Vtask_top_env__DOT__apb_write__5__addr = 0;
    IData/*31:0*/ __Vtask_top_env__DOT__apb_write__5__data;
    __Vtask_top_env__DOT__apb_write__5__data = 0;
    CData/*3:0*/ __Vtask_top_env__DOT__apb_write__5__strb;
    __Vtask_top_env__DOT__apb_write__5__strb = 0;
    CData/*0:0*/ __Vtask_top_env__DOT__apb_write__5__make_space;
    __Vtask_top_env__DOT__apb_write__5__make_space = 0;
    CData/*6:0*/ __Vtask_top_env__DOT__apb_read__8__addr;
    __Vtask_top_env__DOT__apb_read__8__addr = 0;
    CData/*0:0*/ __Vtask_top_env__DOT__apb_read__8__make_space;
    __Vtask_top_env__DOT__apb_read__8__make_space = 0;
    // Body
    co_await vlSelfRef.__VdlySched.delay(0xffffffffffffffffULL, 
                                         nullptr, "tb/top_env.sv", 
                                         202);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    __Vtask_top_env__DOT____VforkTask_0__0__unnamedblk2__DOT__i = 0U;
    __Vtask_top_env__DOT____VforkTask_0__0__unnamedblk2__DOT__i = 0U;
    while ((4U > __Vtask_top_env__DOT____VforkTask_0__0__unnamedblk2__DOT__i)) {
        __Vtask_top_env__DOT__apb_write__1__make_space = 0U;
        __Vtask_top_env__DOT__apb_write__1__strb = 0x0fU;
        __Vtask_top_env__DOT__apb_write__1__data = vlSelfRef.top_env__DOT__start__Vstatic__vid
            [(3U & __Vtask_top_env__DOT____VforkTask_0__0__unnamedblk2__DOT__i)];
        __Vtask_top_env__DOT__apb_write__1__addr = 0x10U;
        Vtop_env___024root____VbeforeTrig_ha024b98c__0(vlSelf, 
                                                       "@(posedge top_env.clk)");
        co_await vlSelfRef.__VtrigSched_ha024b98c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_env.clk)", 
                                                             "tb/top_env.sv", 
                                                             127);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        vlSelfRef.top_env__DOT__apb_in = ((0x000000000000001fULL 
                                           & vlSelfRef.top_env__DOT__apb_in) 
                                          | (((QData)((IData)(__Vtask_top_env__DOT__apb_write__1__addr)) 
                                              << 0x0000002aU) 
                                             | (((QData)((IData)(__Vtask_top_env__DOT__apb_write__1__data)) 
                                                 << 0x0000000aU) 
                                                | ((QData)((IData)(
                                                                   (1U 
                                                                    | ((IData)(__Vtask_top_env__DOT__apb_write__1__strb) 
                                                                       << 1U)))) 
                                                   << 5U))));
        vlSelfRef.top_env__DOT__apb_in = (0x0000000000000010ULL 
                                          | (0x0001ffffffffffe7ULL 
                                             & vlSelfRef.top_env__DOT__apb_in));
        Vtop_env___024root____VbeforeTrig_ha024b98c__0(vlSelf, 
                                                       "@(posedge top_env.clk)");
        co_await vlSelfRef.__VtrigSched_ha024b98c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_env.clk)", 
                                                             "tb/top_env.sv", 
                                                             134);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        vlSelfRef.top_env__DOT__apb_in = (8ULL | vlSelfRef.top_env__DOT__apb_in);
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "tb/top_env.sv", 
                                             136);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        if (VL_UNLIKELY((vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__pslverr))) {
            VL_WRITEF_NX("SLVERR\n",0);
        }
        if (__Vtask_top_env__DOT__apb_write__1__make_space) {
            vlSelfRef.__VnbaEventTrigger = 1U;
            QData/*45:0*/ __Vintraval_h063a14d0__0;
            __Vintraval_h063a14d0__0 = 0;
            __Vintraval_h063a14d0__0 = 0ULL;
            Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_2__0(vlSelf, __Vintraval_h063a14d0__0);
            vlSelfRef.__Vm_traceActivity[4U] = 1U;
        }
        __Vtask_top_env__DOT____VforkTask_0__0__unnamedblk2__DOT__i 
            = ((IData)(1U) + __Vtask_top_env__DOT____VforkTask_0__0__unnamedblk2__DOT__i);
    }
    __Vtask_top_env__DOT__apb_write__3__make_space = 0U;
    __Vtask_top_env__DOT__apb_write__3__strb = 0x0fU;
    __Vtask_top_env__DOT__apb_write__3__data = vlSelfRef.top_env__DOT__start__Vstatic__start_pc;
    __Vtask_top_env__DOT__apb_write__3__addr = 8U;
    Vtop_env___024root____VbeforeTrig_ha024b98c__0(vlSelf, 
                                                   "@(posedge top_env.clk)");
    co_await vlSelfRef.__VtrigSched_ha024b98c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_env.clk)", 
                                                         "tb/top_env.sv", 
                                                         127);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.top_env__DOT__apb_in = ((0x000000000000001fULL 
                                       & vlSelfRef.top_env__DOT__apb_in) 
                                      | (((QData)((IData)(__Vtask_top_env__DOT__apb_write__3__addr)) 
                                          << 0x0000002aU) 
                                         | (((QData)((IData)(__Vtask_top_env__DOT__apb_write__3__data)) 
                                             << 0x0000000aU) 
                                            | ((QData)((IData)(
                                                               (1U 
                                                                | ((IData)(__Vtask_top_env__DOT__apb_write__3__strb) 
                                                                   << 1U)))) 
                                               << 5U))));
    vlSelfRef.top_env__DOT__apb_in = (0x0000000000000010ULL 
                                      | (0x0001ffffffffffe7ULL 
                                         & vlSelfRef.top_env__DOT__apb_in));
    Vtop_env___024root____VbeforeTrig_ha024b98c__0(vlSelf, 
                                                   "@(posedge top_env.clk)");
    co_await vlSelfRef.__VtrigSched_ha024b98c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_env.clk)", 
                                                         "tb/top_env.sv", 
                                                         134);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.top_env__DOT__apb_in = (8ULL | vlSelfRef.top_env__DOT__apb_in);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "tb/top_env.sv", 
                                         136);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    if (VL_UNLIKELY((vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__pslverr))) {
        VL_WRITEF_NX("SLVERR\n",0);
    }
    if (__Vtask_top_env__DOT__apb_write__3__make_space) {
        vlSelfRef.__VnbaEventTrigger = 1U;
        QData/*45:0*/ __Vintraval_h063a14d0__1;
        __Vintraval_h063a14d0__1 = 0;
        __Vintraval_h063a14d0__1 = 0ULL;
        Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_3__0(vlSelf, __Vintraval_h063a14d0__1);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    __Vtask_top_env__DOT__apb_write__5__make_space = 0U;
    __Vtask_top_env__DOT__apb_write__5__strb = 0x0fU;
    __Vtask_top_env__DOT__apb_write__5__data = 1U;
    __Vtask_top_env__DOT__apb_write__5__addr = 0U;
    Vtop_env___024root____VbeforeTrig_ha024b98c__0(vlSelf, 
                                                   "@(posedge top_env.clk)");
    co_await vlSelfRef.__VtrigSched_ha024b98c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_env.clk)", 
                                                         "tb/top_env.sv", 
                                                         127);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.top_env__DOT__apb_in = ((0x000000000000001fULL 
                                       & vlSelfRef.top_env__DOT__apb_in) 
                                      | (((QData)((IData)(__Vtask_top_env__DOT__apb_write__5__addr)) 
                                          << 0x0000002aU) 
                                         | (((QData)((IData)(__Vtask_top_env__DOT__apb_write__5__data)) 
                                             << 0x0000000aU) 
                                            | ((QData)((IData)(
                                                               (1U 
                                                                | ((IData)(__Vtask_top_env__DOT__apb_write__5__strb) 
                                                                   << 1U)))) 
                                               << 5U))));
    vlSelfRef.top_env__DOT__apb_in = (0x0000000000000010ULL 
                                      | (0x0001ffffffffffe7ULL 
                                         & vlSelfRef.top_env__DOT__apb_in));
    Vtop_env___024root____VbeforeTrig_ha024b98c__0(vlSelf, 
                                                   "@(posedge top_env.clk)");
    co_await vlSelfRef.__VtrigSched_ha024b98c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_env.clk)", 
                                                         "tb/top_env.sv", 
                                                         134);
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.top_env__DOT__apb_in = (8ULL | vlSelfRef.top_env__DOT__apb_in);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "tb/top_env.sv", 
                                         136);
    if (VL_UNLIKELY((vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__pslverr))) {
        VL_WRITEF_NX("SLVERR\n",0);
    }
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    if (__Vtask_top_env__DOT__apb_write__5__make_space) {
        vlSelfRef.__VnbaEventTrigger = 1U;
        QData/*45:0*/ __Vintraval_h063a14d0__2;
        __Vintraval_h063a14d0__2 = 0;
        __Vintraval_h063a14d0__2 = 0ULL;
        Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_4__0(vlSelf, __Vintraval_h063a14d0__2);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    vlSelfRef.top_env__DOT__active = 1U;
    while (vlSelfRef.top_env__DOT__active) {
        __Vtask_top_env__DOT__apb_read__8__make_space = 0U;
        __Vtask_top_env__DOT__apb_read__8__addr = 0U;
        Vtop_env___024root____VbeforeTrig_ha024b98c__0(vlSelf, 
                                                       "@(posedge top_env.clk)");
        co_await vlSelfRef.__VtrigSched_ha024b98c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_env.clk)", 
                                                             "tb/top_env.sv", 
                                                             153);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "tb/top_env.sv", 
                                             154);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        vlSelfRef.top_env__DOT__apb_in = ((0x000003ffffffffffULL 
                                           & vlSelfRef.top_env__DOT__apb_in) 
                                          | ((QData)((IData)(__Vtask_top_env__DOT__apb_read__8__addr)) 
                                             << 0x0000002aU));
        vlSelfRef.top_env__DOT__apb_in = (0x0000000000000020ULL 
                                          | (0x0001ffffffffffc7ULL 
                                             & vlSelfRef.top_env__DOT__apb_in));
        Vtop_env___024root____VbeforeTrig_ha024b98c__0(vlSelf, 
                                                       "@(posedge top_env.clk)");
        co_await vlSelfRef.__VtrigSched_ha024b98c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_env.clk)", 
                                                             "tb/top_env.sv", 
                                                             159);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "tb/top_env.sv", 
                                             160);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        vlSelfRef.top_env__DOT__apb_in = (8ULL | vlSelfRef.top_env__DOT__apb_in);
        if (__Vtask_top_env__DOT__apb_read__8__make_space) {
            Vtop_env___024root____VbeforeTrig_ha024b98c__0(vlSelf, 
                                                           "@(posedge top_env.clk)");
            vlSelfRef.__Vm_traceActivity[7U] = 1U;
            co_await vlSelfRef.__VtrigSched_ha024b98c__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge top_env.clk)", 
                                                                 "tb/top_env.sv", 
                                                                 167);
            vlSelfRef.__Vm_traceActivity[3U] = 1U;
            vlSelfRef.__VnbaEventTrigger = 1U;
            QData/*45:0*/ __Vintraval_h063a14d0__3;
            __Vintraval_h063a14d0__3 = 0;
            __Vintraval_h063a14d0__3 = 0ULL;
            Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_5__0(vlSelf, __Vintraval_h063a14d0__3);
        }
        vlSelfRef.top_env__DOT__monitor_core_active__Vstatic__ccr 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__prdata;
        if ((1U & vlSelfRef.top_env__DOT__monitor_core_active__Vstatic__ccr)) {
            vlSelfRef.top_env__DOT__active = 0U;
        }
    }
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_return;
}

void Vtop_env___024root____VbeforeTrig_h8674f324__0(Vtop_env___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_5__0(Vtop_env___024root* vlSelf, QData/*45:0*/ __Vintraval_h063a14d0__3) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_5__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_env___024root____VbeforeTrig_h8674f324__0(vlSelf, 
                                                   "@([event] __VnbaEvent)");
    co_await vlSelfRef.__VtrigSched_h8674f324__0.trigger(0U, 
                                                         nullptr, 
                                                         "@([event] __VnbaEvent)", 
                                                         "tb/top_env.sv", 
                                                         112);
    vlSelfRef.__Vm_traceActivity[8U] = 1U;
    vlSelfRef.top_env__DOT__apb_in = ((7ULL & vlSelfRef.top_env__DOT__apb_in) 
                                      | (__Vintraval_h063a14d0__3 
                                         << 3U));
    vlSelfRef.__Vm_traceActivity[8U] = 1U;
    co_return;
}

VlCoroutine Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_4__0(Vtop_env___024root* vlSelf, QData/*45:0*/ __Vintraval_h063a14d0__2) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_4__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_env___024root____VbeforeTrig_h8674f324__0(vlSelf, 
                                                   "@([event] __VnbaEvent)");
    co_await vlSelfRef.__VtrigSched_h8674f324__0.trigger(0U, 
                                                         nullptr, 
                                                         "@([event] __VnbaEvent)", 
                                                         "tb/top_env.sv", 
                                                         112);
    vlSelfRef.__Vm_traceActivity[9U] = 1U;
    vlSelfRef.top_env__DOT__apb_in = ((7ULL & vlSelfRef.top_env__DOT__apb_in) 
                                      | (__Vintraval_h063a14d0__2 
                                         << 3U));
    vlSelfRef.__Vm_traceActivity[9U] = 1U;
    co_return;
}

VlCoroutine Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_3__0(Vtop_env___024root* vlSelf, QData/*45:0*/ __Vintraval_h063a14d0__1) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_3__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_env___024root____VbeforeTrig_h8674f324__0(vlSelf, 
                                                   "@([event] __VnbaEvent)");
    co_await vlSelfRef.__VtrigSched_h8674f324__0.trigger(0U, 
                                                         nullptr, 
                                                         "@([event] __VnbaEvent)", 
                                                         "tb/top_env.sv", 
                                                         112);
    vlSelfRef.__Vm_traceActivity[10U] = 1U;
    vlSelfRef.top_env__DOT__apb_in = ((7ULL & vlSelfRef.top_env__DOT__apb_in) 
                                      | (__Vintraval_h063a14d0__1 
                                         << 3U));
    vlSelfRef.__Vm_traceActivity[10U] = 1U;
    co_return;
}

VlCoroutine Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_2__0(Vtop_env___024root* vlSelf, QData/*45:0*/ __Vintraval_h063a14d0__0) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP____Vfork_1__0____Vfork_2__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_env___024root____VbeforeTrig_h8674f324__0(vlSelf, 
                                                   "@([event] __VnbaEvent)");
    co_await vlSelfRef.__VtrigSched_h8674f324__0.trigger(0U, 
                                                         nullptr, 
                                                         "@([event] __VnbaEvent)", 
                                                         "tb/top_env.sv", 
                                                         112);
    vlSelfRef.__Vm_traceActivity[11U] = 1U;
    vlSelfRef.top_env__DOT__apb_in = ((7ULL & vlSelfRef.top_env__DOT__apb_in) 
                                      | (__Vintraval_h063a14d0__0 
                                         << 3U));
    vlSelfRef.__Vm_traceActivity[11U] = 1U;
    co_return;
}

void Vtop_env___024root____Vdpiexp_top_env__DOT__is_done_TOP(Vtop_env__Syms* __restrict vlSymsp, CData/*0:0*/ &is_done__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vdpiexp_top_env__DOT__is_done_TOP\n"); );
    // Body
    is_done__Vfuncrtn = ((~ (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata)) 
                         & (IData)(vlSymsp->TOP.top_env__DOT__edge_detector_u__DOT__g_catch__DOT__sig_d1));
}

VL_ATTR_COLD void Vtop_env___024root___eval_initial__TOP(Vtop_env___024root* vlSelf);
VlCoroutine Vtop_env___024root___eval_initial__TOP__Vtiming__0(Vtop_env___024root* vlSelf);
VlCoroutine Vtop_env___024root___eval_initial__TOP__Vtiming__1(Vtop_env___024root* vlSelf);

void Vtop_env___024root___eval_initial(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_initial\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_env___024root___eval_initial__TOP(vlSelf);
    Vtop_env___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtop_env___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VlCoroutine Vtop_env___024root___eval_initial__TOP__Vtiming__0(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("top_env.vcd"s);
    vlSymsp->_traceDumpOpen();
    vlSelfRef.top_env__DOT__clk = 0U;
    vlSelfRef.top_env__DOT__rst_n = 0U;
    co_await vlSelfRef.__VdlySched.delay(3ULL, nullptr, 
                                         "tb/top_env.sv", 
                                         236);
    vlSelfRef.top_env__DOT__rst_n = 1U;
    co_return;
}

VlCoroutine Vtop_env___024root___eval_initial__TOP__Vtiming__1(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb/top_env.sv", 
                                             38);
        vlSelfRef.top_env__DOT__clk = (1U & (~ (IData)(vlSelfRef.top_env__DOT__clk)));
    }
    co_return;
}

void Vtop_env___024root___eval_triggers_vec__act(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_triggers_vec__act\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VactTriggered[1U]) 
                                     | (IData)((IData)(vlSelfRef.__Vdpi_export_trigger)));
    vlSelfRef.__Vdpi_export_trigger = 0U;
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((vlSelfRef.__VnbaEvent.isFired() 
                                                       << 3U) 
                                                      | (vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                         << 2U)) 
                                                     | ((((~ (IData)(vlSelfRef.top_env__DOT__rst_n)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top_env__DOT__rst_n__0)) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.top_env__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top_env__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__top_env__DOT__clk__0 
        = vlSelfRef.top_env__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top_env__DOT__rst_n__0 
        = vlSelfRef.top_env__DOT__rst_n;
    vlSelfRef.__VnbaEvent.clearFired();
}

bool Vtop_env___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

void Vtop_env___024root___nba_sequent__TOP__0(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___nba_sequent__TOP__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0;
    __VdlyVal__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0 = 0;
    SData/*15:0*/ __VdlyDim0__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0;
    __VdlyDim0__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0;
    __VdlySet__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0 = 0;
    // Body
    vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0U;
    vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0U;
    vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0U;
    vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0U;
    vlSelfRef.__VdlySet__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0 = 0U;
    __VdlySet__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0 = 0U;
    if (((~ ((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w)) 
             | (0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w)))) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__wr_en))) {
        vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w;
        vlSelfRef.__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w;
        vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 1U;
    }
    vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1 = 1U;
    vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    if (((~ ((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w)) 
             | (0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w)))) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__wr_en))) {
        vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w;
        vlSelfRef.__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w;
        vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 1U;
    }
    vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1 = 1U;
    vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    if (((~ ((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w)) 
             | (0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w)))) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__wr_en))) {
        vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w;
        vlSelfRef.__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w;
        vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 1U;
    }
    vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1 = 1U;
    vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    if (((~ ((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w)) 
             | (0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w)))) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__wr_en))) {
        vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w;
        vlSelfRef.__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w;
        vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 1U;
    }
    vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1 = 1U;
    vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    if (vlSelfRef.top_env__DOT__ahb_fet_mem_u__DOT__do_write) {
        vlSelfRef.__VdlyVal__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata;
        vlSelfRef.__VdlyDim0__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0 
            = vlSelfRef.top_env__DOT__ahb_fet_mem_u__DOT__address;
        vlSelfRef.__VdlySet__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0 = 1U;
    }
    if (vlSelfRef.top_env__DOT__ahb_lsu_mem_u__DOT__do_write) {
        __VdlyVal__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata;
        __VdlyDim0__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0 
            = vlSelfRef.top_env__DOT__ahb_lsu_mem_u__DOT__address;
        __VdlySet__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0 = 1U;
    }
    vlSelfRef.top_env__DOT__lsu_ahb_i__BRA__31__03a0__KET__ 
        = vlSelfRef.top_env__DOT__ahb_lsu_mem_u__DOT__mem
        [(0x0000ffffU & vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__haddr)];
    if (__VdlySet__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0) {
        vlSelfRef.top_env__DOT__ahb_lsu_mem_u__DOT__mem[__VdlyDim0__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0] 
            = __VdlyVal__top_env__DOT__ahb_lsu_mem_u__DOT__mem__v0;
    }
}

extern const VlUnpacked<CData/*0:0*/, 256> Vtop_env__ConstPool__TABLE_h41e64ba3_0;
extern const VlUnpacked<CData/*3:0*/, 256> Vtop_env__ConstPool__TABLE_h3d053a1e_0;
extern const VlUnpacked<CData/*2:0*/, 32> Vtop_env__ConstPool__TABLE_ha9fa4975_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vtop_env__ConstPool__TABLE_h5bd57765_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vtop_env__ConstPool__TABLE_h19d1b899_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtop_env__ConstPool__TABLE_h5803a092_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtop_env__ConstPool__TABLE_h34638ffc_0;
extern const VlUnpacked<CData/*2:0*/, 64> Vtop_env__ConstPool__TABLE_he55b8d58_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vtop_env__ConstPool__TABLE_he15e1bad_0;
extern const VlUnpacked<CData/*2:0*/, 128> Vtop_env__ConstPool__TABLE_h32ba3bf1_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vtop_env__ConstPool__TABLE_h8135a89d_0;

void Vtop_env___024root___nba_sequent__TOP__1(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___nba_sequent__TOP__1\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*4:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*5:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*4:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*5:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    CData/*4:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    CData/*5:0*/ __Vtableidx8;
    __Vtableidx8 = 0;
    CData/*6:0*/ __Vtableidx9;
    __Vtableidx9 = 0;
    CData/*5:0*/ __Vtableidx10;
    __Vtableidx10 = 0;
    CData/*6:0*/ __Vtableidx11;
    __Vtableidx11 = 0;
    CData/*5:0*/ __Vtableidx12;
    __Vtableidx12 = 0;
    CData/*6:0*/ __Vtableidx13;
    __Vtableidx13 = 0;
    CData/*5:0*/ __Vtableidx14;
    __Vtableidx14 = 0;
    CData/*6:0*/ __Vtableidx15;
    __Vtableidx15 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    CData/*1:0*/ __Vdly__top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr;
    __Vdly__top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr = 0;
    CData/*2:0*/ __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q;
    __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q = 0;
    CData/*2:0*/ __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q;
    __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q = 0;
    CData/*3:0*/ __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len;
    __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len = 0;
    CData/*1:0*/ __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans;
    __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans = 0;
    CData/*1:0*/ __Vdly__top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans;
    __Vdly__top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans = 0;
    IData/*31:0*/ __VdlyVal__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0;
    __VdlyVal__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0 = 0;
    CData/*2:0*/ __VdlyDim0__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0;
    __VdlyDim0__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0 = 0;
    CData/*0:0*/ __VdlySet__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0;
    __VdlySet__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0 = 0;
    CData/*0:0*/ __VdlySet__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v1;
    __VdlySet__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v1 = 0;
    // Body
    __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q 
        = vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q;
    __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans 
        = vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans;
    __Vdly__top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans 
        = vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans;
    __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q 
        = vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q;
    __VdlySet__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0 = 0U;
    __VdlySet__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v1 = 0U;
    __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len 
        = vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len;
    __Vdly__top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr 
        = vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr;
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_stall 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
            | ((~ (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.rd)) 
               & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_stall))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_stall 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
            | ((~ (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.rd)) 
               & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_stall))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_stall 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
            | ((~ (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.rd)) 
               & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_stall))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_stall 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
            | ((~ (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.rd)) 
               & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_stall))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_active 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid) 
            | ((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__is_req_from_tu)) 
               & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_active))));
    __Vtableidx1 = (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len) 
                     << 4U) | ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__q_data_give) 
                                 << 3U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__store_inst) 
                                           << 2U)) 
                               | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata) 
                                   << 1U) | (IData)(vlSelfRef.top_env__DOT__rst_n))));
    if (Vtop_env__ConstPool__TABLE_h41e64ba3_0[__Vtableidx1]) {
        __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len 
            = Vtop_env__ConstPool__TABLE_h3d053a1e_0
            [__Vtableidx1];
    }
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1_valid 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) && 
           ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state))
             ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1_valid)
             : ((1U & (~ ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                          | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))))) 
                || (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_rr))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1_valid 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) && 
           ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state))
             ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1_valid)
             : ((1U & (~ ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                          | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))))) 
                || (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_rr))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1_valid 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) && 
           ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state))
             ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1_valid)
             : ((1U & (~ ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                          | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))))) 
                || (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_rr))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1_valid 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) && 
           ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state))
             ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1_valid)
             : ((1U & (~ ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                          | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))))) 
                || (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_rr))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hburst = 0U;
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hburst = 0U;
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hmastlock 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__next_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hmastlock 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__next_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_prev 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__i_with_delay 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_load) 
             | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_store)) 
            | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__f_cmd_valid)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__stop_load_pc_ff 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (2U >= (0x0000000fU & ((IData)(8U) - (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & 
           (4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__en_i_prev 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata));
    vlSelfRef.top_env__DOT__edge_detector_u__DOT__g_catch__DOT__sig_d1 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata));
    vlSelfRef.top_env__DOT__ahb_fet_mem_u__DOT__do_write 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) && 
           ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwrite) 
            & (0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans))));
    vlSelfRef.top_env__DOT__ahb_lsu_mem_u__DOT__do_write 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) && 
           ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwrite) 
            & (0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans))));
    if (vlSelfRef.top_env__DOT__rst_n) {
        if (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__store_inst) {
            __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q 
                = ((7U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q))
                    ? 0U : (7U & ((IData)(1U) + (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q))));
            __VdlyVal__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0 
                = (vlSelfRef.top_env__DOT__fet_ahb_i__BRA__31__03a0__KET__ 
                   & (- (IData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__data_valid_o))));
            __VdlyDim0__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0 
                = vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q;
            __VdlySet__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0 = 1U;
        }
        __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans 
            = (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_i) 
                & (0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans)))
                ? 2U : (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_i) 
                         & ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans)) 
                            | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans))))
                         ? 3U : 0U));
        __Vdly__top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans 
            = (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i) 
                & (0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans)))
                ? 2U : (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i) 
                         & ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans)) 
                            | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans))))
                         ? 3U : 0U));
        if (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__q_data_give) {
            __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q 
                = ((7U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q))
                    ? 0U : (7U & ((IData)(1U) + (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q))));
        }
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q 
            = __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len 
            = __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len;
        if (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__make_it_done) 
             & (~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata)))) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__make_it_done = 0U;
        }
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_rd_addr 
                = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                  >> 0x00000014U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_rd_addr 
                = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                  >> 0x00000014U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_rd_addr 
                = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                  >> 0x00000014U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_rd_addr 
                = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                  >> 0x00000014U));
        } else {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_rd_addr 
                = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_rd_addr));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_rd_addr 
                = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_rd_addr));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_rd_addr 
                = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_rd_addr));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_rd_addr 
                = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_rd_addr));
        }
        __Vdly__top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr 
            = (3U & ((1U == vlSelfRef.top_env__DOT__core_u__DOT__thread_states
                      [vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr])
                      ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr)
                      : ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr))
                          ? 0U : ((IData)(1U) + (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr)))));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1 
            = ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state))
                ? vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1
                : (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                    | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))
                    ? vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_or
                    : vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1]));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1 
            = ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state))
                ? vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1
                : (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                    | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))
                    ? vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_or
                    : vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1]));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1 
            = ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state))
                ? vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1
                : (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                    | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))
                    ? vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_or
                    : vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1]));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1 
            = ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state))
                ? vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1
                : (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                    | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))
                    ? vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_or
                    : vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1]));
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__cmd_idx_ff 
            = ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state))
                ? ((IData)(1U) + vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__cmd_idx_ff)
                : vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__cmd_idx_ff);
        if ((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__next_state))) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hprot = 0x0eU;
        }
        if ((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__next_state))) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hprot = 0x0eU;
        }
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__state 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__next_state;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__pc_i_ff 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__addr_i;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state;
        vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__state 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__next_state;
        if (((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state)) 
             | (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state)))) {
            if (vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__f_cmd_valid) {
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff 
                    = ((0x001fffffU & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff) 
                       | (((0x000003c0U & (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                           [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                                           >> 0x00000013U)) 
                           | ((0x00000020U & (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                              [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                                              >> 0x00000018U)) 
                              | (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                                [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                                                >> 0x00000014U)))) 
                          << 0x00000015U));
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff 
                    = ((0x7fe00007U & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff) 
                       | (((0x0003fff8U & (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                           [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                                           >> 2U)) 
                           | (3U & vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                              [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q])) 
                          << 3U));
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff 
                    = ((0x7ffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff) 
                       | (((7U == (0x0000000fU & (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                                  [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                                                  >> 0x00000019U))) 
                           | (6U == (0x0000000fU & 
                                     (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                      [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                                      >> 0x00000019U))))
                           ? 1U : (7U & (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                         [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                                         >> 2U))));
            } else {
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff = 0U;
            }
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_valid_ff 
                = vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__f_cmd_valid;
            if (vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__no_fpu_cmd_valid) {
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_ff 
                    = (0x3fffffffU & vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                       [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q]);
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_op_type_ff 
                    = (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                       [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                       >> 0x0000001eU);
            } else {
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_ff = 0U;
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_op_type_ff = 0U;
            }
        } else if ((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state))) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_valid_ff = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_ff = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_op_type_ff = 0U;
        }
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r 
                = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r 
                = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r 
                = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r 
                = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U));
        } else {
            if ((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state))) {
                vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = 0U;
            }
            if ((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state))) {
                vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = 0U;
            }
            if ((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state))) {
                vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = 0U;
            }
            if ((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state))) {
                vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = 0U;
            }
        }
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__state 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state;
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__state 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__next_state;
        vlSelfRef.top_env__DOT__core_u__DOT__thread_sel_d1 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr;
        vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr 
            = __Vdly__top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr;
        if (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__re) 
             & (0ULL == (0x00000c0000000000ULL & vlSelfRef.top_env__DOT__apb_in)))) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__prdata 
                = ((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                  >> 3U))) ? 0U : (
                                                   (0U 
                                                    == 
                                                    (0x0000007fU 
                                                     & (IData)(
                                                               (vlSelfRef.top_env__DOT__apb_in 
                                                                >> 0x0000002aU))))
                                                    ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata)
                                                    : 
                                                   ((8U 
                                                     == 
                                                     (0x0000007fU 
                                                      & (IData)(
                                                                (vlSelfRef.top_env__DOT__apb_in 
                                                                 >> 0x0000002aU))))
                                                     ? vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__addr_i
                                                     : 
                                                    (vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata
                                                     [vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr] 
                                                     & (- (IData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range)))))));
        }
        if ((1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs2 
                = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2];
        }
        if ((1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs2 
                = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2];
        }
        if ((1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs2 
                = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2];
        }
        if ((1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs2 
                = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2];
        }
    } else {
        __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q = 0U;
        __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans = 0U;
        __Vdly__top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans = 0U;
        __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q = 0U;
        __VdlySet__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v1 = 1U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q 
            = __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len 
            = __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__make_it_done = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_rd_addr = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_rd_addr = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_rd_addr = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_rd_addr = 0U;
        __Vdly__top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1 = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1 = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1 = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1 = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__cmd_idx_ff = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hprot = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hprot = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__pc_i_ff = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_valid_ff = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__thread_sel_d1 = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr 
            = __Vdly__top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr;
        vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__prdata = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs2 = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs2 = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs2 = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs2 = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_ff = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_op_type_ff = 0U;
    }
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q 
        = __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q;
    if (__VdlySet__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0) {
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q[__VdlyDim0__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0] 
            = __VdlyVal__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v0;
    }
    if (__VdlySet__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q__v1) {
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q[1U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q[2U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q[3U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q[4U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q[5U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q[6U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q[7U] = 0U;
    }
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans 
        = __Vdly__top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans;
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans 
        = __Vdly__top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans;
    vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[0U] 
        = (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1)) 
            << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1_valid)));
    vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[1U] 
        = (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1)) 
            << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1_valid)));
    vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[2U] 
        = (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1)) 
            << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1_valid)));
    vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[3U] 
        = (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1)) 
            << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1_valid)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__data_valid_o 
        = ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__state)) 
           | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__state)));
    __Vtableidx7 = ((0x00000010U & ((IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 3U)) 
                                    << 4U)) | ((8U 
                                                & ((IData)(
                                                           (vlSelfRef.top_env__DOT__apb_in 
                                                            >> 5U)) 
                                                   << 3U)) 
                                               | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__next_state 
        = Vtop_env__ConstPool__TABLE_ha9fa4975_0[__Vtableidx7];
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o 
        = ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__state)) 
           | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[0U] 
        = (1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs2)) 
                   << 1U));
    vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[1U] 
        = (1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs2)) 
                   << 1U));
    vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[2U] 
        = (1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs2)) 
                   << 1U));
    vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[3U] 
        = (1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs2)) 
                   << 1U));
    __VdfgRegularize_h6e95ff9d_0_1 = (0U == (0x0000001fU 
                                             & (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                                [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                                                >> 0x00000019U)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                                [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                                                >> 0x0000001eU);
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwrite = 0U;
    if (vlSelfRef.top_env__DOT__rst_n) {
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata 
            = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_ff)
                ? vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata_i
                : 0U);
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata_i = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_ff 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_i;
        vlSelfRef.top_env__DOT__ahb_fet_mem_u__DOT__address 
            = (0x0000ffffU & vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__haddr);
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata 
            = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_ff)
                ? vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata_i
                : 0U);
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_ff 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i;
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwrite 
            = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i) 
               & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff));
        vlSelfRef.top_env__DOT__ahb_lsu_mem_u__DOT__address 
            = (0x0000ffffU & vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__haddr);
        if (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o)
              ? 1U : (1U & (vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
                            & (- (IData)((0U == (0x0000007fU 
                                                 & (IData)(
                                                           (vlSelfRef.top_env__DOT__apb_in 
                                                            >> 0x0000002aU)))))))))) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata 
                = (IData)(((0ULL == (0x0001fc0000000000ULL 
                                     & vlSelfRef.top_env__DOT__apb_in)) 
                           & vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__wdata_masked));
        }
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__next_thread_state;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__next_thread_state;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__next_thread_state;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__next_thread_state;
        if (vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata_i 
                = ((IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs2 
                            >> 1U)) & (- (IData)(((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs2) 
                                                  & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9)))));
            vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__haddr 
                = (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff) 
                    & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1))
                    ? (IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1 
                               >> 1U)) : ((IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1 
                                                   >> 1U)) 
                                          & (- (IData)(
                                                       ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1) 
                                                        & ((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff)) 
                                                           & (1U 
                                                              == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state))))))));
        } else {
            vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata_i = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__haddr = 0U;
        }
        if (vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff 
                = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_ff) 
                   & (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)));
        }
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state 
            = vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state;
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata_i = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_ff = 0U;
        vlSelfRef.top_env__DOT__ahb_fet_mem_u__DOT__address = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_ff = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwrite = 0U;
        vlSelfRef.top_env__DOT__ahb_lsu_mem_u__DOT__address = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata_i = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__haddr = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state = 0U;
    }
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__store_inst 
        = ((0U != (0x0000000fU & ((IData)(8U) - (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)))) 
           & ((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__stop_load_pc_ff)) 
              & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__data_valid_o)));
    if ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__we) 
          & (0ULL == (0x00000c0000000000ULL & vlSelfRef.top_env__DOT__apb_in))) 
         & (1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__next_state)))) {
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb 
            = (0x0000000fU & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                      >> 6U)));
        vlSelf->__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask = 0;
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask 
            = ((0xffffff00U & vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask) 
               | ((1U & (IData)(vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb))
                   ? 0x000000ffU : 0U));
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask 
            = ((0xffff00ffU & vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask) 
               | (((2U & (IData)(vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb))
                    ? 0x000000ffU : 0U) << 8U));
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask 
            = ((0xff00ffffU & vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask) 
               | (((4U & (IData)(vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb))
                    ? 0x000000ffU : 0U) << 0x00000010U));
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask 
            = ((0x00ffffffU & vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask) 
               | (((8U & (IData)(vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb))
                    ? 0x000000ffU : 0U) << 0x00000018U));
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__Vfuncout 
            = vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask;
        vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
            = vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__Vfuncout;
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata = 0U;
    }
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__f_cmd_valid 
        = ((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
           & (2U == (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__l_cmd_valid 
        = ((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
           & (1U == (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__s_cmd_valid 
        = ((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
           & (3U == (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs2 
        = vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr
        [vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr];
    vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1 
        = vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr
        [vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr];
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8 = ((2U 
                                                 < 
                                                 (0x0000000fU 
                                                  & ((IData)(8U) 
                                                     - (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)))) 
                                                & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata));
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__wdata_masked 
        = (vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
           & (IData)((vlSelfRef.top_env__DOT__apb_in 
                      >> 0x0000000aU)));
    vlSelfRef.top_env__DOT__core_u__DOT__thread_states[0U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state;
    vlSelfRef.top_env__DOT__core_u__DOT__thread_states[1U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state;
    vlSelfRef.top_env__DOT__core_u__DOT__thread_states[2U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state;
    vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__is_req_from_tu 
        = ((((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
             << 3U) | ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                       << 2U)) | (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                                   << 1U) | (1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state))));
    vlSelfRef.top_env__DOT__core_u__DOT__thread_states[3U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state;
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__no_fpu_cmd_valid 
        = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__l_cmd_valid) 
           | (((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
               & (0U == (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0))) 
              | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__s_cmd_valid)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i 
        = ((0U == ((((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                     << 3U) | ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                               << 2U)) | (((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                                           << 1U) | 
                                          (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state))))) 
           & (0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__is_req_from_tu)));
    __Vtableidx5 = ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_active) 
                      & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__thread_sel_d1) 
                         != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr))) 
                     << 4U) | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o) 
                                << 3U) | (((0U != vlSelfRef.top_env__DOT__core_u__DOT__thread_states
                                            [vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr]) 
                                           << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__state))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state 
        = Vtop_env__ConstPool__TABLE_h5bd57765_0[__Vtableidx5];
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__lsu_ready_i 
        = ((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr)) 
           & (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__lsu_ready_i 
        = ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr)) 
           & (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__lsu_ready_i 
        = ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr)) 
           & (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__lsu_ready_i 
        = ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr)) 
           & (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9 = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff) 
                                                & (1U 
                                                   == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10 = ((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff)) 
                                                 & (3U 
                                                    == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    __Vtableidx4 = ((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state)) 
                      << 5U) | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_store) 
                                 << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_load) 
                                           << 3U))) 
                    | (((1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state)) 
                        << 2U) | (((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state)) 
                                   << 1U) | (IData)(vlSelfRef.top_env__DOT__rst_n))));
    if ((1U & Vtop_env__ConstPool__TABLE_h19d1b899_0
         [__Vtableidx4])) {
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_ff 
            = Vtop_env__ConstPool__TABLE_h5803a092_0
            [__Vtableidx4];
    }
    if ((2U & Vtop_env__ConstPool__TABLE_h19d1b899_0
         [__Vtableidx4])) {
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid_ff 
            = Vtop_env__ConstPool__TABLE_h34638ffc_0
            [__Vtableidx4];
    }
    vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[0U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
    vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[1U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
    vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[2U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
    vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[3U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i 
        = (1U & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9)
                  ? ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1) 
                     & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs2))
                  : ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)) 
                     & ((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff)) 
                        & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1)))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_store 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_1) 
           & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__s_cmd_valid));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_load 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_1) 
           & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__l_cmd_valid));
    __Vtableidx6 = (0x00000010U | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i) 
                                    << 3U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__next_state 
        = Vtop_env__ConstPool__TABLE_he55b8d58_0[__Vtableidx6];
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid 
        = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid_ff) 
           & (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o 
        = (IData)((((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)) 
                    & (0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_op_type_ff))) 
                   & (0x02000000U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_ff))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
        = (vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff 
           & (- (IData)((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready 
        = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_valid_ff) 
           & (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
        = (vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_ff 
           & (- (IData)((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type 
        = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_op_type_ff) 
           & (- (IData)((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)))));
    __Vtableidx3 = ((((~ ((~ ((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_prev)) 
                              & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i))) 
                          & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__i_with_delay))) 
                      & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i)) 
                     << 4U) | ((((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o)) 
                                 & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata)) 
                                << 3U) | (((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
                                           << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state 
        = Vtop_env__ConstPool__TABLE_he15e1bad_0[__Vtableidx3];
    __Vtableidx9 = (((((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev)) 
                       & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)) 
                      << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result) 
                                << 3U)) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state 
        = Vtop_env__ConstPool__TABLE_h32ba3bf1_0[__Vtableidx9];
    __Vtableidx11 = (((((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev)) 
                        & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)) 
                       << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result) 
                                 << 3U)) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state 
        = Vtop_env__ConstPool__TABLE_h32ba3bf1_0[__Vtableidx11];
    __Vtableidx13 = (((((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev)) 
                        & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)) 
                       << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result) 
                                 << 3U)) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state 
        = Vtop_env__ConstPool__TABLE_h32ba3bf1_0[__Vtableidx13];
    __Vtableidx15 = (((((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev)) 
                        & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)) 
                       << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result) 
                                 << 3U)) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state 
        = Vtop_env__ConstPool__TABLE_h32ba3bf1_0[__Vtableidx15];
    if ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state))) {
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x000007ffffffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | ((QData)((IData)(((0x40000000U 
                                        & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                        ? 0U : ((0x20000000U 
                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                 ? 
                                                ((0x10000000U 
                                                  & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                  ? 
                                                 ((0x08000000U 
                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                   ? 0x0dU
                                                   : 0x0cU)
                                                  : 
                                                 ((0x08000000U 
                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                   ? 0x0bU
                                                   : 0x0aU))
                                                 : 
                                                ((0x10000000U 
                                                  & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                  ? 
                                                 ((0x08000000U 
                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                   ? 9U
                                                   : 8U)
                                                  : 0U))))) 
                      << 0x0000002bU));
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x0000780000000007ULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | (((QData)((IData)((0x000fffffU 
                                        & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                           >> 6U)))) 
                       << 0x00000017U) | ((QData)((IData)(
                                                          (7U 
                                                           & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                              >> 3U)))) 
                                          << 3U)));
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x00007ffffffffff8ULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | (IData)((IData)((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd))));
        } else if ((2U & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
            if ((1U & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                    = ((0x000007ffffffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                       | ((QData)((IData)(((0U == (0x0000001fU 
                                                   & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                      >> 0x00000019U)))
                                            ? 3U : 
                                           ((1U == 
                                             (0x0000001fU 
                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                 >> 0x00000019U)))
                                             ? 6U : 
                                            ((2U == 
                                              (0x0000001fU 
                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                  >> 0x00000019U)))
                                              ? 7U : 0U))))) 
                          << 0x0000002bU));
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                    = ((0x000078000fffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                       | ((QData)((IData)(((0x00007c00U 
                                            & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd) 
                                           | (0x000003e0U 
                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                 >> 0x0000000aU))))) 
                          << 0x0000001cU));
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                    = ((0x00007ffff07fffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                       | ((QData)((IData)((0x0000001fU 
                                           & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                              >> 0x00000014U)))) 
                          << 0x00000017U));
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                    = ((0x00007fffff800000ULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                       | (IData)((IData)((0x00001ff8U 
                                          & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                             << 3U)))));
            } else {
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                    = (0x000007ffffffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command);
            }
        } else if ((1U & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x000007ffffffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | ((QData)((IData)(((0U == (0x0000001fU 
                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                  >> 0x00000019U)))
                                        ? 2U : ((1U 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                     >> 0x00000019U)))
                                                 ? 5U
                                                 : 0U)))) 
                      << 0x0000002bU));
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x00007800007fffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | ((QData)((IData)(((0x000f8000U 
                                        & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd) 
                                       | (0x0000001fU 
                                          & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                             >> 0x00000014U))))) 
                      << 0x00000017U));
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x00007fffff800000ULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | (IData)((IData)((0x0003fff8U & 
                                      (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                       << 3U)))));
        } else {
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x000007ffffffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | ((QData)((IData)(((0U == (0x0000001fU 
                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                  >> 0x00000019U)))
                                        ? 4U : ((1U 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                     >> 0x00000019U)))
                                                 ? 1U
                                                 : 0U)))) 
                      << 0x0000002bU));
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x0000780000000000ULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | (((QData)((IData)((0x0000001fU 
                                        & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                           >> 0x00000014U)))) 
                       << 0x00000017U) | (QData)((IData)(
                                                         (0x007ffff8U 
                                                          & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                             << 3U))))));
        }
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command = 0ULL;
    }
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd 
        = ((- (IData)((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))) 
           & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op 
        = (IData)(((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                   & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op 
        = (IData)(((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                   & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
        = ((- (IData)((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))) 
           & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
        = ((- (IData)((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))) 
           & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd);
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__q_data_give 
        = ((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
           & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state)));
    __Vtableidx8 = ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__lsu_ready_i) 
                      << 5U) | (((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state)) 
                                 << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op) 
                                           << 3U))) 
                    | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                        << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__next_thread_state 
        = Vtop_env__ConstPool__TABLE_h8135a89d_0[__Vtableidx8];
    __Vtableidx10 = ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__lsu_ready_i) 
                       << 5U) | (((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state)) 
                                  << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op) 
                                            << 3U))) 
                     | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                         << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__next_thread_state 
        = Vtop_env__ConstPool__TABLE_h8135a89d_0[__Vtableidx10];
    __Vtableidx12 = ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__lsu_ready_i) 
                       << 5U) | (((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state)) 
                                  << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op) 
                                            << 3U))) 
                     | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                         << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__next_thread_state 
        = Vtop_env__ConstPool__TABLE_h8135a89d_0[__Vtableidx12];
    __Vtableidx14 = ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__lsu_ready_i) 
                       << 5U) | (((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state)) 
                                  << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op) 
                                            << 3U))) 
                     | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                         << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__next_thread_state 
        = Vtop_env__ConstPool__TABLE_h8135a89d_0[__Vtableidx14];
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2 
        = (0x0000001fU & ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                           >> 0x0000000fU) & (- (IData)(
                                                        (3U 
                                                         == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1 
        = (0x0000001fU & ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))
                           ? (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                              >> 0x0000000aU) : ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                                                  >> 0x0000000fU) 
                                                 & (- (IData)(
                                                              (1U 
                                                               == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))))));
}

void Vtop_env___024root___nba_sequent__TOP__2(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___nba_sequent__TOP__2\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[0U] 
        = vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata;
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i 
        = (((((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit) 
                  << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit) 
                            << 2U)) | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit) 
                                        << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit))) 
               << 0x0000000cU) | (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit) 
                                     << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit) 
                                               << 2U)) 
                                   | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit) 
                                       << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit))) 
                                  << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit))) 
                                              << 4U) 
                                             | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit) 
                                                  << 3U) 
                                                 | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit) 
                                                    << 2U)) 
                                                | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit))))) 
            << 0x00000010U) | (((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit))) 
                                 << 0x0000000cU) | 
                                (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit))) 
                                 << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit) 
                                                << 3U) 
                                               | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit) 
                                                  << 2U)) 
                                              | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit))) 
                                             << 4U) 
                                            | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit))))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[1U] 
        = vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata;
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i 
        = (((((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit) 
                  << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit) 
                            << 2U)) | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit) 
                                        << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit))) 
               << 0x0000000cU) | (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit) 
                                     << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit) 
                                               << 2U)) 
                                   | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit) 
                                       << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit))) 
                                  << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit))) 
                                              << 4U) 
                                             | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit) 
                                                  << 3U) 
                                                 | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit) 
                                                    << 2U)) 
                                                | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit))))) 
            << 0x00000010U) | (((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit))) 
                                 << 0x0000000cU) | 
                                (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit))) 
                                 << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit) 
                                                << 3U) 
                                               | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit) 
                                                  << 2U)) 
                                              | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit))) 
                                             << 4U) 
                                            | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit))))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[2U] 
        = vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata;
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i 
        = (((((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit) 
                  << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit) 
                            << 2U)) | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit) 
                                        << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit))) 
               << 0x0000000cU) | (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit) 
                                     << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit) 
                                               << 2U)) 
                                   | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit) 
                                       << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit))) 
                                  << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit))) 
                                              << 4U) 
                                             | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit) 
                                                  << 3U) 
                                                 | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit) 
                                                    << 2U)) 
                                                | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit))))) 
            << 0x00000010U) | (((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit))) 
                                 << 0x0000000cU) | 
                                (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit))) 
                                 << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit) 
                                                << 3U) 
                                               | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit) 
                                                  << 2U)) 
                                              | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit))) 
                                             << 4U) 
                                            | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit))))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[3U] 
        = vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata;
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i 
        = (((((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit) 
                  << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit) 
                            << 2U)) | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit) 
                                        << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit))) 
               << 0x0000000cU) | (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit) 
                                     << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit) 
                                               << 2U)) 
                                   | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit) 
                                       << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit))) 
                                  << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit))) 
                                              << 4U) 
                                             | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit) 
                                                  << 3U) 
                                                 | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit) 
                                                    << 2U)) 
                                                | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit))))) 
            << 0x00000010U) | (((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit))) 
                                 << 0x0000000cU) | 
                                (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit))) 
                                 << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit) 
                                                << 3U) 
                                               | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit) 
                                                  << 2U)) 
                                              | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit))) 
                                             << 4U) 
                                            | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit))))));
    vlSelfRef.top_env__DOT__core_u__DOT__vid_arr[0U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[0U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__vid_arr[1U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[1U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__vid_arr[2U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[2U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__vid_arr[3U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[3U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
}

void Vtop_env___024root___nba_sequent__TOP__3(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___nba_sequent__TOP__3\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[vlSelfRef.__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0] 
            = vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
    }
    if (vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[31U] 
            = vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2;
    }
    if (vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[vlSelfRef.__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0] 
            = vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
    }
    if (vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[31U] 
            = vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2;
    }
    if (vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[vlSelfRef.__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0] 
            = vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
    }
    if (vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[31U] 
            = vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2;
    }
    if (vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[vlSelfRef.__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0] 
            = vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
    }
    if (vlSelfRef.__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[31U] 
            = vlSelfRef.__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2;
    }
    vlSelfRef.top_env__DOT__fet_ahb_i__BRA__31__03a0__KET__ 
        = vlSelfRef.top_env__DOT__ahb_fet_mem_u__DOT__mem
        [(0x0000ffffU & vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__haddr)];
    if (vlSelfRef.__VdlySet__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0) {
        vlSelfRef.top_env__DOT__ahb_fet_mem_u__DOT__mem[vlSelfRef.__VdlyDim0__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0] 
            = vlSelfRef.__VdlyVal__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0;
    }
}

void Vtop_env___024root___nba_comb__TOP__0(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___nba_comb__TOP__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[0U] = (IData)(
                                                           (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                             [
                                                                             (0x0000001fU 
                                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[1U] = (IData)(
                                                           ((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                              << 0x00000020U) 
                                                             | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                               [
                                                                               (0x0000001fU 
                                                                                & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))) 
                                                            >> 0x00000020U));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[2U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
        [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                         >> 0x00000015U))];
    if ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        if (((0U == (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                                    >> 0x00000019U))) 
             || (1U == (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                                       >> 0x00000019U))))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x00007fffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x00007fffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x00007fffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x00007fffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x00007fffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x00007fffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x00007fffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x00007fffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
        } else {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
        }
    } else if ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        if ((0U == (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                                   >> 0x00000019U)))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x000003ffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x000003ffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x000003ffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x000003ffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x000003ffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x000003ffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x000003ffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x000003ffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
        } else if ((1U == (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                                          >> 0x00000019U)))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
        } else if ((2U == (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                                          >> 0x00000019U)))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (5U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (5U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (5U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (5U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
        } else {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
        }
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
    }
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[0U] = (IData)(
                                                           (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                             [
                                                                             (0x0000001fU 
                                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[1U] = (IData)(
                                                           ((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                              << 0x00000020U) 
                                                             | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                               [
                                                                               (0x0000001fU 
                                                                                & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))) 
                                                            >> 0x00000020U));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[2U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
        [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                         >> 0x00000015U))];
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[0U] = (IData)(
                                                           (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                             [
                                                                             (0x0000001fU 
                                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[1U] = (IData)(
                                                           ((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                              << 0x00000020U) 
                                                             | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                               [
                                                                               (0x0000001fU 
                                                                                & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))) 
                                                            >> 0x00000020U));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[2U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
        [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                         >> 0x00000015U))];
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[0U] = (IData)(
                                                           (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                             [
                                                                             (0x0000001fU 
                                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[1U] = (IData)(
                                                           ((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                              << 0x00000020U) 
                                                             | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                               [
                                                                               (0x0000001fU 
                                                                                & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))) 
                                                            >> 0x00000020U));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[2U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
        [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                         >> 0x00000015U))];
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_or 
        = ((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U])
            ? ((0U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                             >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                           << 0x0000001dU) 
                                          | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             >> 3U)) 
                                         + ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             << 0x0000001dU) 
                                            | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                               >> 3U)))
                : ((2U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                 >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                               << 0x0000001dU) 
                                              | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 >> 3U)) 
                                             * ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 << 0x0000001dU) 
                                                | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                   >> 3U)))
                    : ((1U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 1U))) ? VL_SHIFTL_III(32,32,32, 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                  >> 3U)), 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                                  >> 3U)))
                        : 0U))) : 0U);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_rr 
        = (1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U]);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_or 
        = ((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U])
            ? ((0U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                             >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                           << 0x0000001dU) 
                                          | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             >> 3U)) 
                                         + ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             << 0x0000001dU) 
                                            | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                               >> 3U)))
                : ((2U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                 >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                               << 0x0000001dU) 
                                              | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 >> 3U)) 
                                             * ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 << 0x0000001dU) 
                                                | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                   >> 3U)))
                    : ((1U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 1U))) ? VL_SHIFTL_III(32,32,32, 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                  >> 3U)), 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                                  >> 3U)))
                        : 0U))) : 0U);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_rr 
        = (1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U]);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_or 
        = ((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U])
            ? ((0U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                             >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                           << 0x0000001dU) 
                                          | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             >> 3U)) 
                                         + ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             << 0x0000001dU) 
                                            | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                               >> 3U)))
                : ((2U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                 >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                               << 0x0000001dU) 
                                              | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 >> 3U)) 
                                             * ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 << 0x0000001dU) 
                                                | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                   >> 3U)))
                    : ((1U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 1U))) ? VL_SHIFTL_III(32,32,32, 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                  >> 3U)), 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                                  >> 3U)))
                        : 0U))) : 0U);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_rr 
        = (1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U]);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_or 
        = ((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U])
            ? ((0U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                             >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                           << 0x0000001dU) 
                                          | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             >> 3U)) 
                                         + ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             << 0x0000001dU) 
                                            | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                               >> 3U)))
                : ((2U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                 >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                               << 0x0000001dU) 
                                              | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 >> 3U)) 
                                             * ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 << 0x0000001dU) 
                                                | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                   >> 3U)))
                    : ((1U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 1U))) ? VL_SHIFTL_III(32,32,32, 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                  >> 3U)), 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                                  >> 3U)))
                        : 0U))) : 0U);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_rr 
        = (1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U]);
}

void Vtop_env___024root___nba_comb__TOP__1(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___nba_comb__TOP__1\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.rd) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_stall))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_rd_addr));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w 
            = (IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.rd 
                       >> 1U));
    } else if (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_or;
    } else if ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_or;
    } else if ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                               ? (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U) : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w = 0U;
    } else if ((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                 & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state)))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w 
            = VL_SHIFTL_III(32,32,32, (0x000fffffU 
                                       & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd), 0x0000000cU);
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & 0U);
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w = 0U;
    }
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__wr_en 
        = (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.rd) 
            & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_stall)) 
           || (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))
                ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_rr)
                : ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))
                    ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_rr)
                    : ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state)) 
                       || (IData)((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                                    & (0U == (0x3e000000U 
                                              & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                                   & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state))))))));
    if (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.rd) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_stall))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_rd_addr));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w 
            = (IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.rd 
                       >> 1U));
    } else if (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_or;
    } else if ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_or;
    } else if ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                               ? (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U) : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w = 0U;
    } else if ((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                 & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state)))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w 
            = VL_SHIFTL_III(32,32,32, (0x000fffffU 
                                       & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd), 0x0000000cU);
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & 0U);
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w = 0U;
    }
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__wr_en 
        = (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.rd) 
            & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_stall)) 
           || (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))
                ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_rr)
                : ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))
                    ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_rr)
                    : ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state)) 
                       || (IData)((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                                    & (0U == (0x3e000000U 
                                              & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                                   & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state))))))));
    if (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.rd) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_stall))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_rd_addr));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w 
            = (IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.rd 
                       >> 1U));
    } else if (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_or;
    } else if ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_or;
    } else if ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                               ? (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U) : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w = 0U;
    } else if ((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                 & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state)))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w 
            = VL_SHIFTL_III(32,32,32, (0x000fffffU 
                                       & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd), 0x0000000cU);
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & 0U);
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w = 0U;
    }
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__wr_en 
        = (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.rd) 
            & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_stall)) 
           || (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))
                ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_rr)
                : ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))
                    ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_rr)
                    : ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state)) 
                       || (IData)((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                                    & (0U == (0x3e000000U 
                                              & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                                   & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state))))))));
    if (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.rd) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_stall))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_rd_addr));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w 
            = (IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.rd 
                       >> 1U));
    } else if (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_or;
    } else if ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_or;
    } else if ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                               ? (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U) : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w = 0U;
    } else if ((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                 & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state)))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd 
                              >> 0x00000014U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w 
            = VL_SHIFTL_III(32,32,32, (0x000fffffU 
                                       & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd), 0x0000000cU);
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & 0U);
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w = 0U;
    }
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__wr_en 
        = (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.rd) 
            & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_stall)) 
           || (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))
                ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_rr)
                : ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))
                    ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_rr)
                    : ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state)) 
                       || (IData)((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                                    & (0U == (0x3e000000U 
                                              & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                                   & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state))))))));
}

void Vtop_env___024root___nba_sequent__TOP__4(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___nba_sequent__TOP__4\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__haddr 
        = ((IData)(vlSelfRef.top_env__DOT__rst_n) ? 
           ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_i)
             ? vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__addr_i
             : 0U) : 0U);
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_i 
        = ((2U < (0x0000000fU & ((IData)(8U) - (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)))) 
           & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata) 
              | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__make_it_done)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__addr_i 
        = (((((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit) 
                  << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit) 
                            << 2U)) | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit) 
                                        << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit))) 
               << 0x0000000cU) | (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit) 
                                     << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit) 
                                               << 2U)) 
                                   | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit) 
                                       << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit))) 
                                  << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit))) 
                                              << 4U) 
                                             | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit) 
                                                  << 3U) 
                                                 | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit) 
                                                    << 2U)) 
                                                | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit))))) 
            << 0x00000010U) | (((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit))) 
                                 << 0x0000000cU) | 
                                (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit))) 
                                 << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit) 
                                                << 3U) 
                                               | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit) 
                                                  << 2U)) 
                                              | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit))) 
                                             << 4U) 
                                            | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit))))));
    __Vtableidx2 = (0x00000010U | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_i) 
                                    << 3U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__next_state 
        = Vtop_env__ConstPool__TABLE_he55b8d58_0[__Vtableidx2];
}

void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf);
void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf);
void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf);
void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf);
void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf);
void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rl_if__0(Vtop_env_reg_if* vlSelf);
void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET____0(Vtop_env_reg_if* vlSelf);
void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET____0(Vtop_env_reg_if* vlSelf);
void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET____0(Vtop_env_reg_if* vlSelf);
void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET____0(Vtop_env_reg_if* vlSelf);
void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__1(Vtop_env_prim_register__FBz8_FCz7* vlSelf);

void Vtop_env___024root___eval_nba(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_nba\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop_env___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop_env___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[13U] = 1U;
        Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg));
        Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg));
        Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg));
        Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg));
        Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg));
        Vtop_env___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop_env___024root___nba_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[14U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rl_if__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if));
        vlSelfRef.__Vm_traceActivity[15U] = 1U;
        Vtop_env___024root___nba_comb__TOP__0(vlSelf);
        Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET____0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__));
        Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET____0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__));
        Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET____0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__));
        Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET____0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__));
        Vtop_env___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop_env___024root___nba_sequent__TOP__4(vlSelf);
        vlSelfRef.__Vm_traceActivity[16U] = 1U;
        Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__1((&vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg));
    }
}

void Vtop_env___024root___timing_ready(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___timing_ready\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_ha024b98c__0.ready("@(posedge top_env.clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h8674f324__0.ready("@([event] __VnbaEvent)");
    }
}

void Vtop_env___024root___timing_resume(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___timing_resume\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_ha024b98c__0.moveToResumeQueue(
                                                          "@(posedge top_env.clk)");
    vlSelfRef.__VtrigSched_h8674f324__0.moveToResumeQueue(
                                                          "@([event] __VnbaEvent)");
    vlSelfRef.__VtrigSched_ha024b98c__0.resume("@(posedge top_env.clk)");
    vlSelfRef.__VtrigSched_h8674f324__0.resume("@([event] __VnbaEvent)");
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtop_env___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 2> &out, const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_env___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop_env___024root___eval_phase__act(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_phase__act\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop_env___024root___eval_triggers_vec__act(vlSelf);
    Vtop_env___024root___timing_ready(vlSelf);
    Vtop_env___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_env___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop_env___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtop_env___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtop_env___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop_env___024root___eval_phase__inact(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_phase__inact\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb/top_env.sv", 12, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtop_env___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 2> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((2U > n));
}

bool Vtop_env___024root___eval_phase__nba(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_phase__nba\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop_env___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop_env___024root___eval_nba(vlSelf);
        Vtop_env___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    if (vlSelfRef.__VnbaEventTrigger) {
        __VnbaExecute = 1U;
        vlSelfRef.__VnbaEventTrigger = 0U;
        vlSelfRef.__VnbaEvent.fire();
    }
    return (__VnbaExecute);
}

void Vtop_env___024root___eval(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop_env___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/top_env.sv", 12, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tb/top_env.sv", 12, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtop_env___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tb/top_env.sv", 12, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtop_env___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtop_env___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop_env___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vtop_env___024root____VbeforeTrig_ha024b98c__0(Vtop_env___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____VbeforeTrig_ha024b98c__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 2> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.top_env__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top_env__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__top_env__DOT__clk__0 
        = vlSelfRef.top_env__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_ha024b98c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha024b98c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha024b98c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha024b98c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha024b98c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha024b98c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha024b98c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha024b98c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha024b98c__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vtop_env___024root____VbeforeTrig_h8674f324__0(Vtop_env___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____VbeforeTrig_h8674f324__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 2> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((vlSelfRef.__VnbaEvent.isFired() 
                                  << 3U)));
    vlSelfRef.__VnbaEvent.clearFired();
    if ((8ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h8674f324__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h8674f324__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h8674f324__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h8674f324__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtop_env___024root___eval_debug_assertions(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_debug_assertions\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
