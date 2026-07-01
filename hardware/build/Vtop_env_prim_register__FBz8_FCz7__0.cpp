// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_env.h for the primary calling header

#include "Vtop_env__pch.h"

void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_env__DOT__rst_n) {
        if ((1U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit 
                = (1U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata);
        }
        if ((2U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 1U));
        }
        if ((4U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 2U));
        }
        if ((8U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 3U));
        }
        if ((0x00000010U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 4U));
        }
        if ((0x00000020U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 5U));
        }
        if ((0x00000040U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 6U));
        }
        if ((0x00000080U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 7U));
        }
        if ((0x00000100U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 8U));
        }
        if ((0x00000200U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 9U));
        }
        if ((0x00000400U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x0000000aU));
        }
        if ((0x00000800U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x0000000bU));
        }
        if ((0x00001000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x0000000cU));
        }
        if ((0x00002000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x0000000dU));
        }
        if ((0x00004000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x0000000eU));
        }
        if ((0x00008000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x0000000fU));
        }
        if ((0x00010000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x00000010U));
        }
        if ((0x00020000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x00000011U));
        }
        if ((0x00040000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x00000012U));
        }
        if ((0x00080000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x00000013U));
        }
        if ((0x00100000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x00000014U));
        }
        if ((0x00200000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x00000015U));
        }
        if ((0x00400000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x00000016U));
        }
        if ((0x00800000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x00000017U));
        }
        if ((0x01000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x00000018U));
        }
        if ((0x02000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x00000019U));
        }
        if ((0x04000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x0000001aU));
        }
        if ((0x08000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x0000001bU));
        }
        if ((0x10000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x0000001cU));
        }
        if ((0x20000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x0000001dU));
        }
        if ((0x40000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit 
                = (1U & (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                         >> 0x0000001eU));
        }
        if ((vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
             >> 0x0000001fU)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit 
                = (vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                   >> 0x0000001fU);
        }
    } else {
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit = 0U;
    }
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
        = ((- (IData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_8))) 
           | (vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
              & (- (IData)((8U == (0x0000007fU & (IData)(
                                                         (vlSymsp->TOP.top_env__DOT__apb_in 
                                                          >> 0x0000002aU))))))));
}

void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__1(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__1\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
        = ((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_8)
            ? ((IData)(4U) + vlSymsp->TOP.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__addr_i)
            : vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__wdata_masked);
}

void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_env__DOT__rst_n) {
        if ((1U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000aU)));
        }
        if ((2U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000bU)));
        }
        if ((4U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000cU)));
        }
        if ((8U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000dU)));
        }
        if ((0x00000010U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000eU)));
        }
        if ((0x00000020U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000fU)));
        }
        if ((0x00000040U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000010U)));
        }
        if ((0x00000080U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000011U)));
        }
        if ((0x00000100U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000012U)));
        }
        if ((0x00000200U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000013U)));
        }
        if ((0x00000400U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000014U)));
        }
        if ((0x00000800U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000015U)));
        }
        if ((0x00001000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000016U)));
        }
        if ((0x00002000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000017U)));
        }
        if ((0x00004000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000018U)));
        }
        if ((0x00008000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000019U)));
        }
        if ((0x00010000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001aU)));
        }
        if ((0x00020000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001bU)));
        }
        if ((0x00040000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001cU)));
        }
        if ((0x00080000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001dU)));
        }
        if ((0x00100000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001eU)));
        }
        if ((0x00200000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001fU)));
        }
        if ((0x00400000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000020U)));
        }
        if ((0x00800000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000021U)));
        }
        if ((0x01000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000022U)));
        }
        if ((0x02000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000023U)));
        }
        if ((0x04000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000024U)));
        }
        if ((0x08000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000025U)));
        }
        if ((0x10000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000026U)));
        }
        if ((0x20000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000027U)));
        }
        if ((0x40000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000028U)));
        }
        if ((vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
             >> 0x0000001fU)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000029U)));
        }
    } else {
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit = 0U;
    }
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
        = (vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
           & (- (IData)(((0U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr)) 
                         & (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range)))));
}

void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_env__DOT__rst_n) {
        if ((1U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000aU)));
        }
        if ((2U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000bU)));
        }
        if ((4U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000cU)));
        }
        if ((8U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000dU)));
        }
        if ((0x00000010U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000eU)));
        }
        if ((0x00000020U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000fU)));
        }
        if ((0x00000040U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000010U)));
        }
        if ((0x00000080U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000011U)));
        }
        if ((0x00000100U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000012U)));
        }
        if ((0x00000200U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000013U)));
        }
        if ((0x00000400U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000014U)));
        }
        if ((0x00000800U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000015U)));
        }
        if ((0x00001000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000016U)));
        }
        if ((0x00002000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000017U)));
        }
        if ((0x00004000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000018U)));
        }
        if ((0x00008000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000019U)));
        }
        if ((0x00010000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001aU)));
        }
        if ((0x00020000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001bU)));
        }
        if ((0x00040000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001cU)));
        }
        if ((0x00080000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001dU)));
        }
        if ((0x00100000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001eU)));
        }
        if ((0x00200000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001fU)));
        }
        if ((0x00400000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000020U)));
        }
        if ((0x00800000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000021U)));
        }
        if ((0x01000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000022U)));
        }
        if ((0x02000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000023U)));
        }
        if ((0x04000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000024U)));
        }
        if ((0x08000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000025U)));
        }
        if ((0x10000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000026U)));
        }
        if ((0x20000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000027U)));
        }
        if ((0x40000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000028U)));
        }
        if ((vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
             >> 0x0000001fU)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000029U)));
        }
    } else {
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit = 0U;
    }
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
        = (vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
           & (- (IData)(((1U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr)) 
                         & (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range)))));
}

void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_env__DOT__rst_n) {
        if ((1U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000aU)));
        }
        if ((2U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000bU)));
        }
        if ((4U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000cU)));
        }
        if ((8U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000dU)));
        }
        if ((0x00000010U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000eU)));
        }
        if ((0x00000020U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000fU)));
        }
        if ((0x00000040U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000010U)));
        }
        if ((0x00000080U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000011U)));
        }
        if ((0x00000100U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000012U)));
        }
        if ((0x00000200U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000013U)));
        }
        if ((0x00000400U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000014U)));
        }
        if ((0x00000800U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000015U)));
        }
        if ((0x00001000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000016U)));
        }
        if ((0x00002000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000017U)));
        }
        if ((0x00004000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000018U)));
        }
        if ((0x00008000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000019U)));
        }
        if ((0x00010000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001aU)));
        }
        if ((0x00020000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001bU)));
        }
        if ((0x00040000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001cU)));
        }
        if ((0x00080000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001dU)));
        }
        if ((0x00100000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001eU)));
        }
        if ((0x00200000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001fU)));
        }
        if ((0x00400000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000020U)));
        }
        if ((0x00800000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000021U)));
        }
        if ((0x01000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000022U)));
        }
        if ((0x02000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000023U)));
        }
        if ((0x04000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000024U)));
        }
        if ((0x08000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000025U)));
        }
        if ((0x10000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000026U)));
        }
        if ((0x20000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000027U)));
        }
        if ((0x40000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000028U)));
        }
        if ((vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
             >> 0x0000001fU)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000029U)));
        }
    } else {
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit = 0U;
    }
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
        = (vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
           & (- (IData)(((2U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr)) 
                         & (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range)))));
}

void Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_env_prim_register__FBz8_FCz7___nba_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_env__DOT__rst_n) {
        if ((1U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000aU)));
        }
        if ((2U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000bU)));
        }
        if ((4U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000cU)));
        }
        if ((8U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000dU)));
        }
        if ((0x00000010U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000eU)));
        }
        if ((0x00000020U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000000fU)));
        }
        if ((0x00000040U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000010U)));
        }
        if ((0x00000080U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000011U)));
        }
        if ((0x00000100U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000012U)));
        }
        if ((0x00000200U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000013U)));
        }
        if ((0x00000400U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000014U)));
        }
        if ((0x00000800U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000015U)));
        }
        if ((0x00001000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000016U)));
        }
        if ((0x00002000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000017U)));
        }
        if ((0x00004000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000018U)));
        }
        if ((0x00008000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000019U)));
        }
        if ((0x00010000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001aU)));
        }
        if ((0x00020000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001bU)));
        }
        if ((0x00040000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001cU)));
        }
        if ((0x00080000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001dU)));
        }
        if ((0x00100000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001eU)));
        }
        if ((0x00200000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x0000001fU)));
        }
        if ((0x00400000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000020U)));
        }
        if ((0x00800000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000021U)));
        }
        if ((0x01000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000022U)));
        }
        if ((0x02000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000023U)));
        }
        if ((0x04000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000024U)));
        }
        if ((0x08000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000025U)));
        }
        if ((0x10000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000026U)));
        }
        if ((0x20000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000027U)));
        }
        if ((0x40000000U & vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000028U)));
        }
        if ((vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
             >> 0x0000001fU)) {
            vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit 
                = (1U & (IData)((vlSymsp->TOP.top_env__DOT__apb_in 
                                 >> 0x00000029U)));
        }
    } else {
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit = 0U;
        vlSelfRef.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit = 0U;
    }
    vlSelfRef.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
        = (vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
           & (- (IData)(((3U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr)) 
                         & (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range)))));
}
