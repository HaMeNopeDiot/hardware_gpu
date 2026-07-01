// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_env.h for the primary calling header

#include "Vtop_env__pch.h"

void Vtop_env_reg_if___ctor_var_reset(Vtop_env_reg_if* vlSelf);

Vtop_env_reg_if::Vtop_env_reg_if() = default;
Vtop_env_reg_if::~Vtop_env_reg_if() = default;

void Vtop_env_reg_if::ctor(Vtop_env__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_env_reg_if___ctor_var_reset(this);
}

void Vtop_env_reg_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_env_reg_if::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
