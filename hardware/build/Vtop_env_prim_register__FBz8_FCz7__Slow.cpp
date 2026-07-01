// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_env.h for the primary calling header

#include "Vtop_env__pch.h"

void Vtop_env_prim_register__FBz8_FCz7___ctor_var_reset(Vtop_env_prim_register__FBz8_FCz7* vlSelf);

Vtop_env_prim_register__FBz8_FCz7::Vtop_env_prim_register__FBz8_FCz7() = default;
Vtop_env_prim_register__FBz8_FCz7::~Vtop_env_prim_register__FBz8_FCz7() = default;

void Vtop_env_prim_register__FBz8_FCz7::ctor(Vtop_env__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_env_prim_register__FBz8_FCz7___ctor_var_reset(this);
}

void Vtop_env_prim_register__FBz8_FCz7::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_env_prim_register__FBz8_FCz7::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
