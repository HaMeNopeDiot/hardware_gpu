// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_env.h for the primary calling header

#include "Vtop_env__pch.h"

VL_ATTR_COLD void Vtop_env_reg_if___ctor_var_reset(Vtop_env_reg_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtop_env_reg_if___ctor_var_reset\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->rs1 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 10211807078052224816ull);
    vlSelf->rs2 = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 392999376545494891ull);
    vlSelf->rd = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 10303652599525973633ull);
}
