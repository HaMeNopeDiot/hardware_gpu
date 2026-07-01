// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_env.h for the primary calling header

#include "Vtop_env__pch.h"

void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET____0(Vtop_env_reg_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET____0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rd = (vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rd 
                    & (- (QData)((IData)((3U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr))))));
}

void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET____0(Vtop_env_reg_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET____0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rd = (vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rd 
                    & (- (QData)((IData)((2U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr))))));
}

void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET____0(Vtop_env_reg_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET____0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rd = (vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rd 
                    & (- (QData)((IData)((1U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr))))));
}

void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET____0(Vtop_env_reg_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET____0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rd = (vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rd 
                    & (- (QData)((IData)((0U == (IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr))))));
}

void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rl_if__0(Vtop_env_reg_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rl_if__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rd = (((QData)((IData)(((- (IData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_10))) 
                                      & (vlSymsp->TOP.top_env__DOT__lsu_ahb_i__BRA__31__03a0__KET__ 
                                         & (- (IData)((IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o))))))) 
                     << 1U) | (QData)((IData)(((IData)(vlSymsp->TOP.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o) 
                                               & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_10)))));
}

std::string VL_TO_STRING(const Vtop_env_reg_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtop_env_reg_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->vlNamep : "null");
}
