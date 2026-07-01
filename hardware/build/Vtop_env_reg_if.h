// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_env.h for the primary calling header

#ifndef VERILATED_VTOP_ENV_REG_IF_H_
#define VERILATED_VTOP_ENV_REG_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop_env__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_env_reg_if final {
  public:

    // DESIGN SPECIFIC STATE
    QData/*32:0*/ rs1;
    QData/*32:0*/ rs2;
    QData/*32:0*/ rd;

    // INTERNAL VARIABLES
    Vtop_env__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop_env_reg_if();
    ~Vtop_env_reg_if();
    void ctor(Vtop_env__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_env_reg_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtop_env_reg_if* obj);

#endif  // guard
