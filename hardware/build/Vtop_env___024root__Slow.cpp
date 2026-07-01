// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_env.h for the primary calling header

#include "Vtop_env__pch.h"

void Vtop_env___024root___ctor_var_reset(Vtop_env___024root* vlSelf);

Vtop_env___024root::Vtop_env___024root(Vtop_env__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtop_env___024root___ctor_var_reset(this);
}

void Vtop_env___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_env___024root::~Vtop_env___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
