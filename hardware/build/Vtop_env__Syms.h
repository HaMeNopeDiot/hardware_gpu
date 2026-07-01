// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP_ENV__SYMS_H_
#define VERILATED_VTOP_ENV__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "Vtop_env.h"

// INCLUDE MODULE CLASSES
#include "Vtop_env___024root.h"
#include "Vtop_env_reg_if.h"
#include "Vtop_env_prim_register__FBz8_FCz7.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using Vtop_env__Vcb_is_done_t = void (*) (Vtop_env__Syms* __restrict vlSymsp, CData/*0:0*/ &is_done__Vfuncrtn);
using Vtop_env__Vcb_load_vertex_buffer_mem_t = void (*) (Vtop_env__Syms* __restrict vlSymsp, CData/*0:0*/ &load_vertex_buffer_mem__Vfuncrtn);
using Vtop_env__Vcb_load_vertex_shader_mem_t = void (*) (Vtop_env__Syms* __restrict vlSymsp, CData/*0:0*/ &load_vertex_shader_mem__Vfuncrtn);
using Vtop_env__Vcb_read_data_mem_t = void (*) (Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ &read_data_mem__Vfuncrtn);
using Vtop_env__Vcb_read_fetcher_mem_t = void (*) (Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ &read_fetcher_mem__Vfuncrtn);
using Vtop_env__Vcb_start_t = void (*) (Vtop_env__Syms* __restrict vlSymsp);
using Vtop_env__Vcb_write_data_mem_t = void (*) (Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ data, CData/*0:0*/ &write_data_mem__Vfuncrtn);
using Vtop_env__Vcb_write_fetcher_mem_t = void (*) (Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ data, CData/*0:0*/ &write_fetcher_mem__Vfuncrtn);

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtop_env__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop_env* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    std::vector<VlEvent*> __Vm_triggeredEvents;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop_env___024root             TOP;
    Vtop_env_prim_register__FBz8_FCz7 TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg;
    Vtop_env_prim_register__FBz8_FCz7 TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg;
    Vtop_env_prim_register__FBz8_FCz7 TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg;
    Vtop_env_prim_register__FBz8_FCz7 TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg;
    Vtop_env_prim_register__FBz8_FCz7 TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg;
    Vtop_env_reg_if                TOP__top_env__DOT__core_u__DOT__rl_if;
    Vtop_env_reg_if                TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__;
    Vtop_env_reg_if                TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__;
    Vtop_env_reg_if                TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__;
    Vtop_env_reg_if                TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_top_env;

    // CONSTRUCTORS
    Vtop_env__Syms(VerilatedContext* contextp, const char* namep, Vtop_env* modelp);
    ~Vtop_env__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
    void fireEvent(VlEvent& event) {
        if (VL_LIKELY(!event.isTriggered())) {
            __Vm_triggeredEvents.push_back(&event);
        }
        event.fire();
    }
    void clearTriggeredEvents() {
        for (const auto eventp : __Vm_triggeredEvents) eventp->clearTriggered();
        __Vm_triggeredEvents.clear();
    }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
