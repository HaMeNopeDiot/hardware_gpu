// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop_env__pch.h"

void Vtop_env___024root____Vdpiexp_top_env__DOT__is_done_TOP(Vtop_env__Syms* __restrict vlSymsp, CData/*0:0*/ &is_done__Vfuncrtn);
void Vtop_env___024root____Vdpiexp_top_env__DOT__load_vertex_buffer_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, CData/*0:0*/ &load_vertex_buffer_mem__Vfuncrtn);
void Vtop_env___024root____Vdpiexp_top_env__DOT__load_vertex_shader_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, CData/*0:0*/ &load_vertex_shader_mem__Vfuncrtn);
void Vtop_env___024root____Vdpiexp_top_env__DOT__read_data_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ &read_data_mem__Vfuncrtn);
void Vtop_env___024root____Vdpiexp_top_env__DOT__read_fetcher_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ &read_fetcher_mem__Vfuncrtn);
void Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP(Vtop_env__Syms* __restrict vlSymsp);
void Vtop_env___024root____Vdpiexp_top_env__DOT__write_data_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ data, CData/*0:0*/ &write_data_mem__Vfuncrtn);
void Vtop_env___024root____Vdpiexp_top_env__DOT__write_fetcher_mem_TOP(Vtop_env__Syms* __restrict vlSymsp, IData/*31:0*/ address, IData/*31:0*/ data, CData/*0:0*/ &write_fetcher_mem__Vfuncrtn);

Vtop_env__Syms::Vtop_env__Syms(VerilatedContext* contextp, const char* namep, Vtop_env* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(894);
    // Setup sub module instances
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.ctor(this, "top_env.core_u.core_csrm_hndl_u.core_csrm_u.gen_vid_regs[0].vid_reg");
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.ctor(this, "top_env.core_u.core_csrm_hndl_u.core_csrm_u.gen_vid_regs[1].vid_reg");
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.ctor(this, "top_env.core_u.core_csrm_hndl_u.core_csrm_u.gen_vid_regs[2].vid_reg");
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.ctor(this, "top_env.core_u.core_csrm_hndl_u.core_csrm_u.gen_vid_regs[3].vid_reg");
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.ctor(this, "top_env.core_u.core_csrm_hndl_u.core_csrm_u.pc_reg");
    TOP__top_env__DOT__core_u__DOT__rl_if.ctor(this, "top_env.core_u.rl_if");
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.ctor(this, "top_env.core_u.rt_if[0]");
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.ctor(this, "top_env.core_u.rt_if[1]");
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.ctor(this, "top_env.core_u.rt_if[2]");
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.ctor(this, "top_env.core_u.rt_if[3]");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg = &TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg;
    TOP.__PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg = &TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg;
    TOP.__PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg = &TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg;
    TOP.__PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg = &TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg;
    TOP.__PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg = &TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg;
    TOP.__PVT__top_env__DOT__core_u__DOT__rl_if = &TOP__top_env__DOT__core_u__DOT__rl_if;
    TOP.__PVT__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__ = &TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__;
    TOP.__PVT__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__ = &TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__;
    TOP.__PVT__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__ = &TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__;
    TOP.__PVT__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__ = &TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__Vconfigure(true);
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__Vconfigure(false);
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__Vconfigure(false);
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__Vconfigure(false);
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__Vconfigure(false);
    TOP__top_env__DOT__core_u__DOT__rl_if.__Vconfigure(true);
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.__Vconfigure(false);
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.__Vconfigure(false);
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.__Vconfigure(false);
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.__Vconfigure(false);
    // Setup scopes
    __Vscopep_top_env = new VerilatedScope{this, "top_env", "top_env", "<null>", -12, VerilatedScope::SCOPE_OTHER};
    // Setup export functions - final: 0
    __Vscopep_top_env->exportInsert(0, "is_done", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__is_done_TOP));
    __Vscopep_top_env->exportInsert(0, "load_vertex_buffer_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__load_vertex_buffer_mem_TOP));
    __Vscopep_top_env->exportInsert(0, "load_vertex_shader_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__load_vertex_shader_mem_TOP));
    __Vscopep_top_env->exportInsert(0, "read_data_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__read_data_mem_TOP));
    __Vscopep_top_env->exportInsert(0, "read_fetcher_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__read_fetcher_mem_TOP));
    __Vscopep_top_env->exportInsert(0, "start", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP));
    __Vscopep_top_env->exportInsert(0, "write_data_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__write_data_mem_TOP));
    __Vscopep_top_env->exportInsert(0, "write_fetcher_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__write_fetcher_mem_TOP));
    // Setup export functions - final: 1
    __Vscopep_top_env->exportInsert(1, "is_done", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__is_done_TOP));
    __Vscopep_top_env->exportInsert(1, "load_vertex_buffer_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__load_vertex_buffer_mem_TOP));
    __Vscopep_top_env->exportInsert(1, "load_vertex_shader_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__load_vertex_shader_mem_TOP));
    __Vscopep_top_env->exportInsert(1, "read_data_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__read_data_mem_TOP));
    __Vscopep_top_env->exportInsert(1, "read_fetcher_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__read_fetcher_mem_TOP));
    __Vscopep_top_env->exportInsert(1, "start", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__start_TOP));
    __Vscopep_top_env->exportInsert(1, "write_data_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__write_data_mem_TOP));
    __Vscopep_top_env->exportInsert(1, "write_fetcher_mem", (void*)(&Vtop_env___024root____Vdpiexp_top_env__DOT__write_fetcher_mem_TOP));
}

Vtop_env__Syms::~Vtop_env__Syms() {
    if (__Vm_dumping) _traceDumpClose();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_top_env, __Vscopep_top_env = nullptr);
    // Tear down sub module instances
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.dtor();
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.dtor();
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.dtor();
    TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.dtor();
    TOP__top_env__DOT__core_u__DOT__rl_if.dtor();
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.dtor();
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.dtor();
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.dtor();
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.dtor();
    TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.dtor();
}

void Vtop_env__Syms::_traceDump() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vtop_env__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        const std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vtop_env__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}
