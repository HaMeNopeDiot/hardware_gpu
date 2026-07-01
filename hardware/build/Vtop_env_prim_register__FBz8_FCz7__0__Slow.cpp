// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_env.h for the primary calling header

#include "Vtop_env__pch.h"

VL_ATTR_COLD void Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
        = ((- (IData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_8))) 
           | (vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
              & (- (IData)((8U == (0x0000007fU & (IData)(
                                                         (vlSymsp->TOP.top_env__DOT__apb_in 
                                                          >> 0x0000002aU))))))));
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
        = ((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_8)
            ? ((IData)(4U) + vlSymsp->TOP.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__addr_i)
            : vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__wdata_masked);
}

VL_ATTR_COLD void Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
        = (vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
           & (- (IData)(((0U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr)) 
                         & (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range)))));
}

VL_ATTR_COLD void Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
        = (vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
           & (- (IData)(((1U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr)) 
                         & (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range)))));
}

VL_ATTR_COLD void Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
        = (vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
           & (- (IData)(((2U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr)) 
                         & (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range)))));
}

VL_ATTR_COLD void Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
        = (vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
           & (- (IData)(((3U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr)) 
                         & (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range)))));
}

VL_ATTR_COLD void Vtop_env_prim_register__FBz8_FCz7___ctor_var_reset(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___ctor_var_reset\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12890271867161903902ull);
    vlSelf->wedata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17962641173281731757ull);
    vlSelf->rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10065165116613087284ull);
    vlSelf->__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17240273116869115903ull);
    vlSelf->__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14996137386694607101ull);
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit = 0;
    vlSelf->g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit = 0;
}
