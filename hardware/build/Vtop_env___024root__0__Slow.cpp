// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_env.h for the primary calling header

#include "Vtop_env__pch.h"

VL_ATTR_COLD void Vtop_env___024root___eval_static__TOP(Vtop_env___024root* vlSelf);
void Vtop_env___024root___timing_ready(Vtop_env___024root* vlSelf);

VL_ATTR_COLD void Vtop_env___024root___eval_static(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_static\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_env___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[12U] = 1U;
    vlSelfRef.__Vtrigprevexpr___TOP__top_env__DOT__clk__0 
        = vlSelfRef.top_env__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top_env__DOT__rst_n__0 
        = vlSelfRef.top_env__DOT__rst_n;
    Vtop_env___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((1U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtop_env___024root___eval_static__TOP(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_static__TOP\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top_env__DOT__apb_in = 0ULL;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->top_env__DOT__monitor_core_active__Vstatic__ccr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8603366455629949750ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_env__DOT__start__Vstatic__vid[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7896835461378050040ull);
    }
    vlSelf->top_env__DOT__start__Vstatic__start_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9739962781515241712ull);
}

VL_ATTR_COLD void Vtop_env___024root___eval_initial__TOP(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_initial__TOP\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top_env__DOT__core_u__DOT__thread_unit_info[0U] = 0U;
    vlSelfRef.top_env__DOT__core_u__DOT__thread_unit_info[1U] = 0U;
    vlSelfRef.top_env__DOT__core_u__DOT__thread_unit_info[2U] = 0U;
    vlSelfRef.top_env__DOT__core_u__DOT__thread_unit_info[3U] = 0U;
}

VL_ATTR_COLD void Vtop_env___024root___eval_final(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_final\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_env___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop_env___024root___eval_phase__stl(Vtop_env___024root* vlSelf);

VL_ATTR_COLD void Vtop_env___024root___eval_settle(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_settle\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop_env___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb/top_env.sv", 12, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop_env___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtop_env___024root___eval_triggers_vec__stl(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_triggers_vec__stl\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtop_env___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_env___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop_env___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop_env___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*2:0*/, 32> Vtop_env__ConstPool__TABLE_ha9fa4975_0;
extern const VlUnpacked<CData/*2:0*/, 64> Vtop_env__ConstPool__TABLE_he55b8d58_0;
extern const VlUnpacked<CData/*2:0*/, 128> Vtop_env__ConstPool__TABLE_h32ba3bf1_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vtop_env__ConstPool__TABLE_h5bd57765_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vtop_env__ConstPool__TABLE_he15e1bad_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vtop_env__ConstPool__TABLE_h8135a89d_0;

VL_ATTR_COLD void Vtop_env___024root___stl_sequent__TOP__0(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___stl_sequent__TOP__0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*4:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*4:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*5:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    CData/*4:0*/ __Vtableidx7;
    __Vtableidx7 = 0;
    CData/*5:0*/ __Vtableidx8;
    __Vtableidx8 = 0;
    CData/*6:0*/ __Vtableidx9;
    __Vtableidx9 = 0;
    CData/*5:0*/ __Vtableidx10;
    __Vtableidx10 = 0;
    CData/*6:0*/ __Vtableidx11;
    __Vtableidx11 = 0;
    CData/*5:0*/ __Vtableidx12;
    __Vtableidx12 = 0;
    CData/*6:0*/ __Vtableidx13;
    __Vtableidx13 = 0;
    CData/*5:0*/ __Vtableidx14;
    __Vtableidx14 = 0;
    CData/*6:0*/ __Vtableidx15;
    __Vtableidx15 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    // Body
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid 
        = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid_ff) 
           & (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__data_valid_o 
        = ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__state)) 
           | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__re 
        = (1U & ((~ (IData)((0ULL != (0x0000000000000016ULL 
                                      & vlSelfRef.top_env__DOT__apb_in)))) 
                 & (IData)((vlSelfRef.top_env__DOT__apb_in 
                            >> 5U))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2 = (IData)(
                                                       ((0ULL 
                                                         != 
                                                         (0x00000c0000000000ULL 
                                                          & vlSelfRef.top_env__DOT__apb_in)) 
                                                        | (0x20U 
                                                           < 
                                                           (0x0000007fU 
                                                            & (IData)(
                                                                      (vlSelfRef.top_env__DOT__apb_in 
                                                                       >> 0x0000002aU))))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_i 
        = ((2U < (0x0000000fU & ((IData)(8U) - (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)))) 
           & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata) 
              | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__make_it_done)));
    __VdfgRegularize_h6e95ff9d_0_1 = (0U == (0x0000001fU 
                                             & (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                                [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                                                >> 0x00000019U)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_8 = ((2U 
                                                 < 
                                                 (0x0000000fU 
                                                  & ((IData)(8U) 
                                                     - (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)))) 
                                                & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o 
        = (IData)((((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)) 
                    & (0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_op_type_ff))) 
                   & (0x02000000U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_ff))));
    vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[0U] 
        = (1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs2)) 
                   << 1U));
    vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[1U] 
        = (1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs2)) 
                   << 1U));
    vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[2U] 
        = (1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs2)) 
                   << 1U));
    vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[3U] 
        = (1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs2)) 
                   << 1U));
    vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[0U] 
        = (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1)) 
            << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1_valid)));
    vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[1U] 
        = (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1)) 
            << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1_valid)));
    vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[2U] 
        = (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1)) 
            << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1_valid)));
    vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[3U] 
        = (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1)) 
            << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1_valid)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__is_req_from_tu 
        = ((((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
             << 3U) | ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                       << 2U)) | (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                                   << 1U) | (1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__addr_i 
        = (((((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit) 
                  << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit) 
                            << 2U)) | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit) 
                                        << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit))) 
               << 0x0000000cU) | (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit) 
                                     << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit) 
                                               << 2U)) 
                                   | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit) 
                                       << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit))) 
                                  << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit))) 
                                              << 4U) 
                                             | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit) 
                                                  << 3U) 
                                                 | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit) 
                                                    << 2U)) 
                                                | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit))))) 
            << 0x00000010U) | (((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit))) 
                                 << 0x0000000cU) | 
                                (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit))) 
                                 << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit) 
                                                << 3U) 
                                               | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit) 
                                                  << 2U)) 
                                              | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit))) 
                                             << 4U) 
                                            | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit))))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                                [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q] 
                                                >> 0x0000001eU);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i 
        = (((((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit) 
                  << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit) 
                            << 2U)) | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit) 
                                        << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit))) 
               << 0x0000000cU) | (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit) 
                                     << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit) 
                                               << 2U)) 
                                   | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit) 
                                       << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit))) 
                                  << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit))) 
                                              << 4U) 
                                             | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit) 
                                                  << 3U) 
                                                 | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit) 
                                                    << 2U)) 
                                                | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit))))) 
            << 0x00000010U) | (((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit))) 
                                 << 0x0000000cU) | 
                                (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit))) 
                                 << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit) 
                                                << 3U) 
                                               | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit) 
                                                  << 2U)) 
                                              | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit))) 
                                             << 4U) 
                                            | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit))))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i 
        = (((((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit) 
                  << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit) 
                            << 2U)) | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit) 
                                        << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit))) 
               << 0x0000000cU) | (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit) 
                                     << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit) 
                                               << 2U)) 
                                   | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit) 
                                       << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit))) 
                                  << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit))) 
                                              << 4U) 
                                             | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit) 
                                                  << 3U) 
                                                 | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit) 
                                                    << 2U)) 
                                                | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit))))) 
            << 0x00000010U) | (((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit))) 
                                 << 0x0000000cU) | 
                                (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit))) 
                                 << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit) 
                                                << 3U) 
                                               | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit) 
                                                  << 2U)) 
                                              | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit))) 
                                             << 4U) 
                                            | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit))))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i 
        = (((((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit) 
                  << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit) 
                            << 2U)) | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit) 
                                        << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit))) 
               << 0x0000000cU) | (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit) 
                                     << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit) 
                                               << 2U)) 
                                   | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit) 
                                       << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit))) 
                                  << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit))) 
                                              << 4U) 
                                             | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit) 
                                                  << 3U) 
                                                 | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit) 
                                                    << 2U)) 
                                                | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit))))) 
            << 0x00000010U) | (((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit))) 
                                 << 0x0000000cU) | 
                                (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit))) 
                                 << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit) 
                                                << 3U) 
                                               | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit) 
                                                  << 2U)) 
                                              | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit))) 
                                             << 4U) 
                                            | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit))))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i 
        = (((((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit) 
                  << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit) 
                            << 2U)) | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit) 
                                        << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit))) 
               << 0x0000000cU) | (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit) 
                                     << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit) 
                                               << 2U)) 
                                   | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit) 
                                       << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit))) 
                                  << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit))) 
                                              << 4U) 
                                             | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit) 
                                                  << 3U) 
                                                 | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit) 
                                                    << 2U)) 
                                                | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit) 
                                                    << 1U) 
                                                   | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit))))) 
            << 0x00000010U) | (((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit))) 
                                 << 0x0000000cU) | 
                                (((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit) 
                                    << 3U) | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit) 
                                              << 2U)) 
                                  | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit) 
                                      << 1U) | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit))) 
                                 << 8U)) | ((((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit) 
                                                << 3U) 
                                               | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit) 
                                                  << 2U)) 
                                              | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit) 
                                                  << 1U) 
                                                 | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit))) 
                                             << 4U) 
                                            | ((((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit) 
                                                 << 3U) 
                                                | ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit) 
                                                   << 2U)) 
                                               | (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit) 
                                                   << 1U) 
                                                  | (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit))))));
    __Vtableidx7 = ((0x00000010U & ((IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 3U)) 
                                    << 4U)) | ((8U 
                                                & ((IData)(
                                                           (vlSelfRef.top_env__DOT__apb_in 
                                                            >> 5U)) 
                                                   << 3U)) 
                                               | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__next_state 
        = Vtop_env__ConstPool__TABLE_ha9fa4975_0[__Vtableidx7];
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__we 
        = (IData)(((0x0000000000000030ULL == (0x0000000000000030ULL 
                                              & vlSelfRef.top_env__DOT__apb_in)) 
                   & (~ (0U != (3U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                              >> 1U)))))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
        = (vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff 
           & (- (IData)((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range 
        = ((0x10U <= (0x0000007fU & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000002aU)))) 
           & (0x20U >= (0x0000007fU & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                               >> 0x0000002aU)))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready 
        = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_valid_ff) 
           & (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__thread_states[0U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state;
    vlSelfRef.top_env__DOT__core_u__DOT__thread_states[1U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state;
    vlSelfRef.top_env__DOT__core_u__DOT__thread_states[2U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state;
    vlSelfRef.top_env__DOT__core_u__DOT__thread_states[3U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state;
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o 
        = ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__state)) 
           | (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
        = (vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_ff 
           & (- (IData)((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type 
        = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_op_type_ff) 
           & (- (IData)((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__store_inst 
        = ((0U != (0x0000000fU & ((IData)(8U) - (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)))) 
           & ((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__stop_load_pc_ff)) 
              & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__data_valid_o)));
    __Vtableidx2 = (0x00000010U | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_i) 
                                    << 3U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__next_state 
        = Vtop_env__ConstPool__TABLE_he55b8d58_0[__Vtableidx2];
    vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs2 
        = vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr
        [vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr];
    vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1 
        = vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr
        [vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr];
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i 
        = ((0U == ((((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                     << 3U) | ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                               << 2U)) | (((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                                           << 1U) | 
                                          (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state))))) 
           & (0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__is_req_from_tu)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__f_cmd_valid 
        = ((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
           & (2U == (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__l_cmd_valid 
        = ((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
           & (1U == (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__s_cmd_valid 
        = ((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
           & (3U == (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.top_env__DOT__core_u__DOT__vid_arr[0U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[0U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__vid_arr[1U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[1U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__vid_arr[2U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[2U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__vid_arr[3U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[3U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__pslverr 
        = (IData)(((0x0000000000000028ULL == (0x0000000000000028ULL 
                                              & vlSelfRef.top_env__DOT__apb_in)) 
                   & ((0U != (3U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                            >> 1U)))) 
                      | ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2) 
                         & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__we) 
                            | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__re))))));
    if ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__we) 
          & (0ULL == (0x00000c0000000000ULL & vlSelfRef.top_env__DOT__apb_in))) 
         & (1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__next_state)))) {
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb 
            = (0x0000000fU & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                      >> 6U)));
        vlSelf->__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask = 0;
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask 
            = ((0xffffff00U & vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask) 
               | ((1U & (IData)(vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb))
                   ? 0x000000ffU : 0U));
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask 
            = ((0xffff00ffU & vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask) 
               | (((2U & (IData)(vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb))
                    ? 0x000000ffU : 0U) << 8U));
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask 
            = ((0xff00ffffU & vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask) 
               | (((4U & (IData)(vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb))
                    ? 0x000000ffU : 0U) << 0x00000010U));
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask 
            = ((0x00ffffffU & vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask) 
               | (((8U & (IData)(vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb))
                    ? 0x000000ffU : 0U) << 0x00000018U));
        vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__Vfuncout 
            = vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask;
        vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
            = vlSelfRef.__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__Vfuncout;
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata = 0U;
    }
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[0U] = (IData)(
                                                           (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                             [
                                                                             (0x0000001fU 
                                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[1U] = (IData)(
                                                           ((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                              << 0x00000020U) 
                                                             | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                               [
                                                                               (0x0000001fU 
                                                                                & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))) 
                                                            >> 0x00000020U));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[2U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
        [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                         >> 0x00000015U))];
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[0U] = (IData)(
                                                           (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                             [
                                                                             (0x0000001fU 
                                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[1U] = (IData)(
                                                           ((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                              << 0x00000020U) 
                                                             | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                               [
                                                                               (0x0000001fU 
                                                                                & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))) 
                                                            >> 0x00000020U));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[2U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
        [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                         >> 0x00000015U))];
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[0U] = (IData)(
                                                           (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                             [
                                                                             (0x0000001fU 
                                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[1U] = (IData)(
                                                           ((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                              << 0x00000020U) 
                                                             | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                               [
                                                                               (0x0000001fU 
                                                                                & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))) 
                                                            >> 0x00000020U));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[2U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
        [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                         >> 0x00000015U))];
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[0U] = (IData)(
                                                           (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                             [
                                                                             (0x0000001fU 
                                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[1U] = (IData)(
                                                           ((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                              [
                                                                              (0x0000001fU 
                                                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x00000010U))])) 
                                                              << 0x00000020U) 
                                                             | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                               [
                                                                               (0x0000001fU 
                                                                                & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                                >> 0x0000000bU))]))) 
                                                            >> 0x00000020U));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[2U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
        [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                         >> 0x00000015U))];
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr 
        = (3U & ((((IData)((vlSelfRef.top_env__DOT__apb_in 
                            >> 0x0000002aU)) - (IData)(0x10U)) 
                  >> 2U) & (- (IData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range)))));
    __Vtableidx9 = (((((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev)) 
                       & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)) 
                      << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result) 
                                << 3U)) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state 
        = Vtop_env__ConstPool__TABLE_h32ba3bf1_0[__Vtableidx9];
    __Vtableidx11 = (((((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev)) 
                        & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)) 
                       << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result) 
                                 << 3U)) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state 
        = Vtop_env__ConstPool__TABLE_h32ba3bf1_0[__Vtableidx11];
    __Vtableidx13 = (((((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev)) 
                        & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)) 
                       << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result) 
                                 << 3U)) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state 
        = Vtop_env__ConstPool__TABLE_h32ba3bf1_0[__Vtableidx13];
    __Vtableidx15 = (((((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev)) 
                        & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)) 
                       << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result) 
                                 << 3U)) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state 
        = Vtop_env__ConstPool__TABLE_h32ba3bf1_0[__Vtableidx15];
    __Vtableidx5 = ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_active) 
                      & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__thread_sel_d1) 
                         != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr))) 
                     << 4U) | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o) 
                                << 3U) | (((0U != vlSelfRef.top_env__DOT__core_u__DOT__thread_states
                                            [vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr]) 
                                           << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__state))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state 
        = Vtop_env__ConstPool__TABLE_h5bd57765_0[__Vtableidx5];
    if ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state))) {
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x000007ffffffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | ((QData)((IData)(((0x40000000U 
                                        & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                        ? 0U : ((0x20000000U 
                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                 ? 
                                                ((0x10000000U 
                                                  & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                  ? 
                                                 ((0x08000000U 
                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                   ? 0x0dU
                                                   : 0x0cU)
                                                  : 
                                                 ((0x08000000U 
                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                   ? 0x0bU
                                                   : 0x0aU))
                                                 : 
                                                ((0x10000000U 
                                                  & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                  ? 
                                                 ((0x08000000U 
                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)
                                                   ? 9U
                                                   : 8U)
                                                  : 0U))))) 
                      << 0x0000002bU));
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x0000780000000007ULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | (((QData)((IData)((0x000fffffU 
                                        & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                           >> 6U)))) 
                       << 0x00000017U) | ((QData)((IData)(
                                                          (7U 
                                                           & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                              >> 3U)))) 
                                          << 3U)));
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x00007ffffffffff8ULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | (IData)((IData)((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd))));
        } else if ((2U & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
            if ((1U & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                    = ((0x000007ffffffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                       | ((QData)((IData)(((0U == (0x0000001fU 
                                                   & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                      >> 0x00000019U)))
                                            ? 3U : 
                                           ((1U == 
                                             (0x0000001fU 
                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                 >> 0x00000019U)))
                                             ? 6U : 
                                            ((2U == 
                                              (0x0000001fU 
                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                  >> 0x00000019U)))
                                              ? 7U : 0U))))) 
                          << 0x0000002bU));
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                    = ((0x000078000fffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                       | ((QData)((IData)(((0x00007c00U 
                                            & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd) 
                                           | (0x000003e0U 
                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                 >> 0x0000000aU))))) 
                          << 0x0000001cU));
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                    = ((0x00007ffff07fffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                       | ((QData)((IData)((0x0000001fU 
                                           & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                              >> 0x00000014U)))) 
                          << 0x00000017U));
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                    = ((0x00007fffff800000ULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                       | (IData)((IData)((0x00001ff8U 
                                          & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                             << 3U)))));
            } else {
                vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                    = (0x000007ffffffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command);
            }
        } else if ((1U & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x000007ffffffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | ((QData)((IData)(((0U == (0x0000001fU 
                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                  >> 0x00000019U)))
                                        ? 2U : ((1U 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                     >> 0x00000019U)))
                                                 ? 5U
                                                 : 0U)))) 
                      << 0x0000002bU));
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x00007800007fffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | ((QData)((IData)(((0x000f8000U 
                                        & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd) 
                                       | (0x0000001fU 
                                          & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                             >> 0x00000014U))))) 
                      << 0x00000017U));
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x00007fffff800000ULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | (IData)((IData)((0x0003fff8U & 
                                      (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                       << 3U)))));
        } else {
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x000007ffffffffffULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | ((QData)((IData)(((0U == (0x0000001fU 
                                               & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                  >> 0x00000019U)))
                                        ? 4U : ((1U 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                     >> 0x00000019U)))
                                                 ? 1U
                                                 : 0U)))) 
                      << 0x0000002bU));
            vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command 
                = ((0x0000780000000000ULL & vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command) 
                   | (((QData)((IData)((0x0000001fU 
                                        & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                           >> 0x00000014U)))) 
                       << 0x00000017U) | (QData)((IData)(
                                                         (0x007ffff8U 
                                                          & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd 
                                                             << 3U))))));
        }
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command = 0ULL;
    }
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd 
        = ((- (IData)((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))) 
           & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op 
        = (IData)(((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                   & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op 
        = (IData)(((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                   & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
        = ((- (IData)((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))) 
           & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
        = ((- (IData)((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))) 
           & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd);
    __Vtableidx3 = ((((~ ((~ ((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_prev)) 
                              & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i))) 
                          & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__i_with_delay))) 
                      & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i)) 
                     << 4U) | ((((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o)) 
                                 & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata)) 
                                << 3U) | (((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
                                           << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state 
        = Vtop_env__ConstPool__TABLE_he15e1bad_0[__Vtableidx3];
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_load 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_1) 
           & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__l_cmd_valid));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_store 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_1) 
           & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__s_cmd_valid));
    vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__no_fpu_cmd_valid 
        = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__l_cmd_valid) 
           | (((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
               & (0U == (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0))) 
              | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__s_cmd_valid)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__wdata_masked 
        = (vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
           & (IData)((vlSelfRef.top_env__DOT__apb_in 
                      >> 0x0000000aU)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9 = ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff) 
                                                & (1U 
                                                   == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__lsu_ready_i 
        = ((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr)) 
           & (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__lsu_ready_i 
        = ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr)) 
           & (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__lsu_ready_i 
        = ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr)) 
           & (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__lsu_ready_i 
        = ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr)) 
           & (3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10 = ((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff)) 
                                                 & (3U 
                                                    == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2 
        = (0x0000001fU & ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                           >> 0x0000000fU) & (- (IData)(
                                                        (3U 
                                                         == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))))));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1 
        = (0x0000001fU & ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))
                           ? (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                              >> 0x0000000aU) : ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                                                  >> 0x0000000fU) 
                                                 & (- (IData)(
                                                              (1U 
                                                               == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)))))));
    vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__q_data_give 
        = ((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
           & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i 
        = (1U & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9)
                  ? ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1) 
                     & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs2))
                  : ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state)) 
                     & ((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff)) 
                        & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1)))));
    vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[0U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
    __Vtableidx8 = ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__lsu_ready_i) 
                      << 5U) | (((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state)) 
                                 << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op) 
                                           << 3U))) 
                    | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                        << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__next_thread_state 
        = Vtop_env__ConstPool__TABLE_h8135a89d_0[__Vtableidx8];
    vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[1U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
    __Vtableidx10 = ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__lsu_ready_i) 
                       << 5U) | (((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state)) 
                                  << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op) 
                                            << 3U))) 
                     | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                         << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__next_thread_state 
        = Vtop_env__ConstPool__TABLE_h8135a89d_0[__Vtableidx10];
    vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[2U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
    __Vtableidx12 = ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__lsu_ready_i) 
                       << 5U) | (((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state)) 
                                  << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op) 
                                            << 3U))) 
                     | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                         << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__next_thread_state 
        = Vtop_env__ConstPool__TABLE_h8135a89d_0[__Vtableidx12];
    vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[3U] 
        = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
    __Vtableidx14 = ((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__lsu_ready_i) 
                       << 5U) | (((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state)) 
                                  << 4U) | ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op) 
                                            << 3U))) 
                     | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                         << 2U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state)));
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__next_thread_state 
        = Vtop_env__ConstPool__TABLE_h8135a89d_0[__Vtableidx14];
    if ((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        if (((0U == (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                                    >> 0x00000019U))) 
             || (1U == (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                                       >> 0x00000019U))))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x00007fffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x00007fffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x00007fffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x00007fffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x00007fffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x00007fffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x00007fffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x00007fffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x00007fffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
        } else {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
        }
    } else if ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        if ((0U == (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                                   >> 0x00000019U)))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x000003ffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x000003ffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x000003ffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x000003ffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x000003ffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x000003ffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = ((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U]) 
                   | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                << 0x00000020U) | (QData)((IData)(
                                                                  (0x000003ffU 
                                                                   & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                      << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd))))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(
                                                                   (0x000003ffU 
                                                                    & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(
                                                                (0x000003ffU 
                                                                 & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd)))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | (0xfffffff8U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U]));
        } else if ((1U == (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                                          >> 0x00000019U)))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (1U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
        } else if ((2U == (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                                          >> 0x00000019U)))) {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (5U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (5U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (5U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                = (5U | ((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                    [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                         << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2])))) 
                    >> 0x0000001dU) | ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                  [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                   [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                                                >> 0x00000020U)) 
                                       << 3U));
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                = ((IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                              [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1])) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                                [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]))) 
                            >> 0x00000020U)) >> 0x0000001dU);
        } else {
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
            vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
        }
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] = 0U;
    }
    __Vtableidx6 = (0x00000010U | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i) 
                                    << 3U) | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__state)));
    vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__next_state 
        = Vtop_env__ConstPool__TABLE_he55b8d58_0[__Vtableidx6];
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_or 
        = ((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U])
            ? ((0U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                             >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                           << 0x0000001dU) 
                                          | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             >> 3U)) 
                                         + ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             << 0x0000001dU) 
                                            | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                               >> 3U)))
                : ((2U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                 >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                               << 0x0000001dU) 
                                              | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 >> 3U)) 
                                             * ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 << 0x0000001dU) 
                                                | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                   >> 3U)))
                    : ((1U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 1U))) ? VL_SHIFTL_III(32,32,32, 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                  >> 3U)), 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                                  >> 3U)))
                        : 0U))) : 0U);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_rr 
        = (1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U]);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_or 
        = ((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U])
            ? ((0U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                             >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                           << 0x0000001dU) 
                                          | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             >> 3U)) 
                                         + ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             << 0x0000001dU) 
                                            | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                               >> 3U)))
                : ((2U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                 >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                               << 0x0000001dU) 
                                              | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 >> 3U)) 
                                             * ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 << 0x0000001dU) 
                                                | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                   >> 3U)))
                    : ((1U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 1U))) ? VL_SHIFTL_III(32,32,32, 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                  >> 3U)), 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                                  >> 3U)))
                        : 0U))) : 0U);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_rr 
        = (1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U]);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_or 
        = ((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U])
            ? ((0U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                             >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                           << 0x0000001dU) 
                                          | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             >> 3U)) 
                                         + ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             << 0x0000001dU) 
                                            | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                               >> 3U)))
                : ((2U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                 >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                               << 0x0000001dU) 
                                              | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 >> 3U)) 
                                             * ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 << 0x0000001dU) 
                                                | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                   >> 3U)))
                    : ((1U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 1U))) ? VL_SHIFTL_III(32,32,32, 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                  >> 3U)), 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                                  >> 3U)))
                        : 0U))) : 0U);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_rr 
        = (1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U]);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_or 
        = ((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U])
            ? ((0U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                             >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                           << 0x0000001dU) 
                                          | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             >> 3U)) 
                                         + ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                             << 0x0000001dU) 
                                            | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                               >> 3U)))
                : ((2U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                 >> 1U))) ? (((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                               << 0x0000001dU) 
                                              | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 >> 3U)) 
                                             * ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                 << 0x0000001dU) 
                                                | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                   >> 3U)))
                    : ((1U == (3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 1U))) ? VL_SHIFTL_III(32,32,32, 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                  >> 3U)), 
                                                              ((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                                                << 0x0000001dU) 
                                                               | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                                                  >> 3U)))
                        : 0U))) : 0U);
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_rr 
        = (1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U]);
}

VL_ATTR_COLD void Vtop_env___024root___stl_sequent__TOP__1(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___stl_sequent__TOP__1\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[0U] 
        = vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[1U] 
        = vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[2U] 
        = vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata;
    vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[3U] 
        = vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata;
}

VL_ATTR_COLD void Vtop_env___024root___stl_sequent__TOP__2(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___stl_sequent__TOP__2\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.rd) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_stall))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w 
            = (IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.rd 
                       >> 1U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_rd_addr));
    } else if (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_or;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                              >> 0x00000014U));
    } else if ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_or;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                              >> 0x00000014U));
    } else if ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                               ? (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U) : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)));
    } else if ((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                 & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state)))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w 
            = VL_SHIFTL_III(32,32,32, (0x000fffffU 
                                       & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd), 0x0000000cU);
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd 
                              >> 0x00000014U));
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & 0U);
    }
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__wr_en 
        = (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.rd) 
            & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_stall)) 
           || (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))
                ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_rr)
                : ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))
                    ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_rr)
                    : ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state)) 
                       || (IData)((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                                    & (0U == (0x3e000000U 
                                              & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                                   & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state))))))));
    if (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.rd) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_stall))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w 
            = (IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.rd 
                       >> 1U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_rd_addr));
    } else if (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_or;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                              >> 0x00000014U));
    } else if ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_or;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                              >> 0x00000014U));
    } else if ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                               ? (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U) : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)));
    } else if ((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                 & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state)))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w 
            = VL_SHIFTL_III(32,32,32, (0x000fffffU 
                                       & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd), 0x0000000cU);
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd 
                              >> 0x00000014U));
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & 0U);
    }
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__wr_en 
        = (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.rd) 
            & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_stall)) 
           || (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))
                ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_rr)
                : ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))
                    ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_rr)
                    : ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state)) 
                       || (IData)((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                                    & (0U == (0x3e000000U 
                                              & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                                   & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state))))))));
    if (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.rd) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_stall))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w 
            = (IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.rd 
                       >> 1U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_rd_addr));
    } else if (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_or;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                              >> 0x00000014U));
    } else if ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_or;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                              >> 0x00000014U));
    } else if ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                               ? (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U) : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)));
    } else if ((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                 & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state)))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w 
            = VL_SHIFTL_III(32,32,32, (0x000fffffU 
                                       & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd), 0x0000000cU);
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd 
                              >> 0x00000014U));
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & 0U);
    }
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__wr_en 
        = (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.rd) 
            & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_stall)) 
           || (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))
                ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_rr)
                : ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))
                    ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_rr)
                    : ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state)) 
                       || (IData)((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                                    & (0U == (0x3e000000U 
                                              & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                                   & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state))))))));
    if (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.rd) 
         & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_stall))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w 
            = (IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.rd 
                       >> 1U));
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_rd_addr));
    } else if (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_or;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd 
                              >> 0x00000014U));
    } else if ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w 
            = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_or;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd 
                              >> 0x00000014U));
    } else if ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                               ? (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                  >> 6U) : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)));
    } else if ((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                 & (0U == (0x3e000000U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state)))) {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w 
            = VL_SHIFTL_III(32,32,32, (0x000fffffU 
                                       & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd), 0x0000000cU);
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd 
                              >> 0x00000014U));
    } else {
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w = 0U;
        vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w 
            = (0x0000001fU & 0U);
    }
    vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__wr_en 
        = (((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.rd) 
            & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_stall)) 
           || (((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                & (~ ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op) 
                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op))))
                ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_rr)
                : ((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))
                    ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_rr)
                    : ((4U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state)) 
                       || (IData)((((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type)) 
                                    & (0U == (0x3e000000U 
                                              & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd))) 
                                   & (1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state))))))));
}

VL_ATTR_COLD void Vtop_env___024root____Vm_traceActivitySetAll(Vtop_env___024root* vlSelf);
VL_ATTR_COLD void Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf);
VL_ATTR_COLD void Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf);
VL_ATTR_COLD void Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf);
VL_ATTR_COLD void Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf);
VL_ATTR_COLD void Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg__0(Vtop_env_prim_register__FBz8_FCz7* vlSelf);
void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rl_if__0(Vtop_env_reg_if* vlSelf);
void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET____0(Vtop_env_reg_if* vlSelf);
void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET____0(Vtop_env_reg_if* vlSelf);
void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET____0(Vtop_env_reg_if* vlSelf);
void Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET____0(Vtop_env_reg_if* vlSelf);

VL_ATTR_COLD void Vtop_env___024root___eval_stl(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_stl\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop_env___024root___stl_sequent__TOP__0(vlSelf);
        Vtop_env___024root____Vm_traceActivitySetAll(vlSelf);
        Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg));
        Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg));
        Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg));
        Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg));
        Vtop_env_prim_register__FBz8_FCz7___stl_sequent__TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg));
        Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rl_if__0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if));
        Vtop_env___024root___stl_sequent__TOP__1(vlSelf);
        Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET____0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__));
        Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET____0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__));
        Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET____0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__));
        Vtop_env_reg_if___nba_comb__TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET____0((&vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__));
        Vtop_env___024root___stl_sequent__TOP__2(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop_env___024root___eval_phase__stl(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___eval_phase__stl\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop_env___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_env___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop_env___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop_env___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop_env___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_env___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop_env___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge top_env.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge top_env.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([event] __VnbaEvent)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'act' trigger - DPI export trigger\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_env___024root____Vm_traceActivitySetAll(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root____Vm_traceActivitySetAll\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__Vm_traceActivity[7U] = 1U;
    vlSelfRef.__Vm_traceActivity[8U] = 1U;
    vlSelfRef.__Vm_traceActivity[9U] = 1U;
    vlSelfRef.__Vm_traceActivity[10U] = 1U;
    vlSelfRef.__Vm_traceActivity[11U] = 1U;
    vlSelfRef.__Vm_traceActivity[12U] = 1U;
    vlSelfRef.__Vm_traceActivity[13U] = 1U;
    vlSelfRef.__Vm_traceActivity[14U] = 1U;
    vlSelfRef.__Vm_traceActivity[15U] = 1U;
    vlSelfRef.__Vm_traceActivity[16U] = 1U;
}

VL_ATTR_COLD void Vtop_env___024root___ctor_var_reset(Vtop_env___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root___ctor_var_reset\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->top_env__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8187078311502698510ull);
    vlSelf->top_env__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17138348574490714879ull);
    vlSelf->top_env__DOT__lsu_ahb_i__BRA__31__03a0__KET__ = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2409408946911940304ull);
    vlSelf->top_env__DOT__fet_ahb_i__BRA__31__03a0__KET__ = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11361953210184335897ull);
    vlSelf->top_env__DOT__active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4396405618384972799ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__vid_arr[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3675652150217621964ull);
    }
    vlSelf->top_env__DOT__core_u__DOT__thread_sel_d1 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17297619128480853529ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__rs1_arr[__Vi0] = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 13374041163258797673ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__rs2_arr[__Vi0] = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 5686840214177223099ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__thread_unit_info[__Vi0] = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 5128824416623711803ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__thread_states[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9068650691900512707ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__lsu_r2_thread[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5489623897162237445ull);
    }
    vlSelf->top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9932373128879789155ull);
    vlSelf->top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__is_req_from_tu = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13398987096737803744ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__stop_load_pc_ff = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16137003991387028120ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__q_data_give = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4554402786753842470ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__pc_i_ff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1739310403218924234ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__make_it_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16753376724661990103ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__en_i_prev = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2206949087010116732ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17166154037985153987ull);
    }
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1088389966452656627ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13448338925169894690ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10438481103581101563ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__store_inst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3627194459654496115ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3729484307898421775ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__addr_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1120988903761873851ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__data_valid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11176882786774752134ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hburst = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8869107100055182252ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hprot = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17438098974387057218ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8115636012315418675ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8445181994426811454ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hmastlock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7633545340648552573ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7903988494720297055ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__haddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2845559902259303863ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14454636716616210670ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15043794965310651111ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4098982412560461867ull);
    vlSelf->top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_ff = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9094791559559508979ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12575077841831195376ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11851326708893711141ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11448913903873597452ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__l_cmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10637545217508574753ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__s_cmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6851952530838642194ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__f_cmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12207282466930225735ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5800360934709412170ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_store = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1814284128081561634ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__i_with_delay = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4899814730142590549ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_prev = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12487423997794190723ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4867907401428250364ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10216414658400540266ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff = VL_SCOPED_RAND_RESET_I(31, __VscopeHash, 4294861695417364287ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_valid_ff = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17989362681058419401ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_ff = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18439970937298331874ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid_ff = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18033536119869371495ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_ff = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 7597071395751063137ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_op_type_ff = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4929137999354022732ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__no_fpu_cmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11181999465897022118ull);
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__cmd_idx_ff = 0;
    vlSelf->top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command = VL_SCOPED_RAND_RESET_Q(47, __VscopeHash, 2013695940243051233ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3619450968598510943ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7989699155249558451ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5411705590956283601ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16063361888826747407ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15271828489302644057ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10357914557450765723ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hburst = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 454093437763956629ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hprot = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9226410994580149483ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1204730340528356142ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 156462124941671116ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hmastlock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12975940781895064781ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16180667605318647993ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__haddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4021666630444781512ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16579110231491144838ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8023740684302400365ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15939736785436870181ull);
    vlSelf->top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_ff = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14143687987343325061ull);
    vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__prdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14129652832142116356ull);
    vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16411410864249111000ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1552711082429674472ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9084419352491267972ull);
    }
    vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17474065087456922837ull);
    vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__wdata_masked = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14803548214146842738ull);
    vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5780851279724843604ull);
    vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata = 0;
    vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__pslverr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6062827393747914125ull);
    vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10844779292016062925ull);
    vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10205088472178754702ull);
    vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7068911383529007918ull);
    vlSelf->top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11373510580922519715ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 14561661767273331923ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13358639461288475508ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__lsu_ready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18365429654886428296ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd = VL_SCOPED_RAND_RESET_I(31, __VscopeHash, 475436727454171069ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14421219846213412986ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3135118435951564356ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10565721736865219832ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 12783226097276644060ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 3365036648547288838ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 9110393708546083411ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13938647478933413229ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15836591050920144929ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10762495714570099567ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__next_thread_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11329059295897620920ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10295843895605269589ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10958121793246546375ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13107306938074740493ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_or = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7582900144954752542ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10510121249335689510ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4503913648969696574ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3328116726221679952ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17011788910309664935ull);
    VL_SCOPED_RAND_RESET_W(67, vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct, __VscopeHash, 7296635321629184058ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1353393309261612798ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15492655007929170189ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14767136629238215360ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4344440016935655940ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14820079895000594533ull);
    }
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1110804777831311846ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4425339263866643656ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12283690775276510303ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8686114164702139412ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__lsu_ready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7384879804556642750ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6307071666690258666ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16671800562914150494ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16241858234272474687ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7277331533096095553ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__next_thread_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11513931075529972907ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13818037556135467566ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 738328506353062952ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2180648664296927150ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_or = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12672927739036251958ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14862046679486731275ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4875480072967613790ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5790132282484744894ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15965220158398684564ull);
    VL_SCOPED_RAND_RESET_W(67, vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct, __VscopeHash, 15436493347504815279ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10564331681862439043ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5293280874145053364ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12643781260624165902ull);
    }
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9037618806908004034ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6578803473748297800ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10497240109741032342ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__lsu_ready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5957287280235838757ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17951071707654167648ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2132339195156810051ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8109631333001756634ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2678397392348436043ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__next_thread_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16959414189820374737ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 38698419352953296ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8278864855558406302ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1333508804308857725ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_or = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7285151824822945516ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11868749924636724068ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5561547219553148206ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11259879320735583436ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1801316274014081803ull);
    VL_SCOPED_RAND_RESET_W(67, vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct, __VscopeHash, 3816207084196105184ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9275383322251155162ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13551026231284001816ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1903231051730712047ull);
    }
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2964992065154661709ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 478448094184383497ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17484708332127909414ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__lsu_ready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7212236204428326259ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14547480323862023618ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5733733143123119910ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17929223505838708341ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16684243840983377393ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__next_thread_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16367220638128747234ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11118907837718564210ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10791516062495302137ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5196183847179236892ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_or = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2091693691465367713ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1318347334852764272ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14417451022001800477ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1768570064581945786ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11748983583204441539ull);
    VL_SCOPED_RAND_RESET_W(67, vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct, __VscopeHash, 15638961301485977138ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2028067364612618201ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5771328500493773827ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6506776325132652708ull);
    }
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9369628943201828825ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16757218399054997650ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5667602381754157769ull);
    vlSelf->top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16827381805821502203ull);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->top_env__DOT__ahb_lsu_mem_u__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10248887073432235102ull);
    }
    vlSelf->top_env__DOT__ahb_lsu_mem_u__DOT__address = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5262848735465103722ull);
    vlSelf->top_env__DOT__ahb_lsu_mem_u__DOT__do_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18438681256299896383ull);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->top_env__DOT__ahb_fet_mem_u__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2238100786451801529ull);
    }
    vlSelf->top_env__DOT__ahb_fet_mem_u__DOT__address = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16497170535480770663ull);
    vlSelf->top_env__DOT__ahb_fet_mem_u__DOT__do_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6354510230998922771ull);
    vlSelf->top_env__DOT__edge_detector_u__DOT__g_catch__DOT__sig_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17703176105954147634ull);
    vlSelf->__Vdpi_export_trigger = 0;
    vlSelf->__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__Vfuncout = 0;
    vlSelf->__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb = 0;
    vlSelf->__Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_0 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_2 = 0;
    VL_ZERO_RESET_W(96, vlSelf->__VdfgRegularize_h6e95ff9d_0_3);
    VL_ZERO_RESET_W(96, vlSelf->__VdfgRegularize_h6e95ff9d_0_4);
    VL_ZERO_RESET_W(96, vlSelf->__VdfgRegularize_h6e95ff9d_0_5);
    VL_ZERO_RESET_W(96, vlSelf->__VdfgRegularize_h6e95ff9d_0_6);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_8 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_9 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_10 = 0;
    vlSelf->__VnbaEventTrigger = 0;
    vlSelf->__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1 = 0;
    vlSelf->__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2 = 0;
    vlSelf->__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1 = 0;
    vlSelf->__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2 = 0;
    vlSelf->__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1 = 0;
    vlSelf->__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2 = 0;
    vlSelf->__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0 = 0;
    vlSelf->__VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1 = 0;
    vlSelf->__VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2 = 0;
    vlSelf->__VdlyVal__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0 = 0;
    vlSelf->__VdlyDim0__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0 = 0;
    vlSelf->__VdlySet__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__top_env__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top_env__DOT__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 17; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
