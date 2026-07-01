// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop_env__Syms.h"


void Vtop_env___024root__trace_chg_0_sub_0(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop_env___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root__trace_chg_0\n"); );
    // Body
    Vtop_env___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_env___024root*>(voidSelf);
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop_env___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop_env___024root__trace_chg_dtype____0(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 4>& __VdtypeVar);
void Vtop_env___024root__trace_chg_dtype____1(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*1:0*/, 4>& __VdtypeVar);
void Vtop_env___024root__trace_chg_dtype____2(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 8>& __VdtypeVar);
void Vtop_env___024root__trace_chg_dtype____3(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);
void Vtop_env___024root__trace_chg_dtype____4(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<SData/*9:0*/, 4>& __VdtypeVar);

void Vtop_env___024root__trace_chg_0_sub_0(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root__trace_chg_0_sub_0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_17;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_33;
    VlWide<3>/*95:0*/ __Vtemp_34;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__pslverr));
        bufp->chgBit(oldp+1,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__we));
        bufp->chgBit(oldp+2,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__re));
        bufp->chgBit(oldp+3,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2) 
                              & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__re))));
        bufp->chgBit(oldp+4,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2) 
                              & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__we))));
        bufp->chgBit(oldp+5,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2) 
                              & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__we) 
                                 | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__re)))));
        bufp->chgBit(oldp+6,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range));
        bufp->chgCData(oldp+7,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr),2);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[12U])))) {
        bufp->chgIData(oldp+8,(vlSelfRef.top_env__DOT__start__Vstatic__vid[0]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top_env__DOT__start__Vstatic__vid[1]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.top_env__DOT__start__Vstatic__vid[2]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.top_env__DOT__start__Vstatic__vid[3]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.top_env__DOT__start__Vstatic__start_pc),32);
    }
    if (VL_UNLIKELY((((((((((((vlSelfRef.__Vm_traceActivity[2U] 
                               | vlSelfRef.__Vm_traceActivity[3U]) 
                              | vlSelfRef.__Vm_traceActivity[4U]) 
                             | vlSelfRef.__Vm_traceActivity[5U]) 
                            | vlSelfRef.__Vm_traceActivity[6U]) 
                           | vlSelfRef.__Vm_traceActivity[7U]) 
                          | vlSelfRef.__Vm_traceActivity[8U]) 
                         | vlSelfRef.__Vm_traceActivity[9U]) 
                        | vlSelfRef.__Vm_traceActivity[10U]) 
                       | vlSelfRef.__Vm_traceActivity[11U]) 
                      | vlSelfRef.__Vm_traceActivity[12U])))) {
        bufp->chgQData(oldp+13,(vlSelfRef.top_env__DOT__apb_in),49);
        bufp->chgCData(oldp+15,((0x0000007fU & (IData)(
                                                       (vlSelfRef.top_env__DOT__apb_in 
                                                        >> 0x0000002aU)))),7);
        bufp->chgIData(oldp+16,((IData)((vlSelfRef.top_env__DOT__apb_in 
                                         >> 0x0000000aU))),32);
        bufp->chgCData(oldp+17,((0x0000000fU & (IData)(
                                                       (vlSelfRef.top_env__DOT__apb_in 
                                                        >> 6U)))),4);
        bufp->chgBit(oldp+18,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 5U)))));
        bufp->chgBit(oldp+19,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 4U)))));
        bufp->chgBit(oldp+20,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 3U)))));
        bufp->chgCData(oldp+21,((7U & (IData)(vlSelfRef.top_env__DOT__apb_in))),3);
        bufp->chgBit(oldp+22,((0U != (3U & (IData)(
                                                   (vlSelfRef.top_env__DOT__apb_in 
                                                    >> 1U))))));
        bufp->chgBit(oldp+23,((0U != (3U & (IData)(
                                                   (vlSelfRef.top_env__DOT__apb_in 
                                                    >> 0x0000002aU))))));
        bufp->chgBit(oldp+24,((0x20U < (0x0000007fU 
                                        & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                                   >> 0x0000002aU))))));
        bufp->chgBit(oldp+25,((IData)((0x0000000000000028ULL 
                                       == (0x0000000000000028ULL 
                                           & vlSelfRef.top_env__DOT__apb_in)))));
        bufp->chgBit(oldp+26,((0U == (0x0000007fU & (IData)(
                                                            (vlSelfRef.top_env__DOT__apb_in 
                                                             >> 0x0000002aU))))));
        bufp->chgBit(oldp+27,((8U == (0x0000007fU & (IData)(
                                                            (vlSelfRef.top_env__DOT__apb_in 
                                                             >> 0x0000002aU))))));
        bufp->chgBit(oldp+28,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000000aU)))));
        bufp->chgBit(oldp+29,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000014U)))));
        bufp->chgBit(oldp+30,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000015U)))));
        bufp->chgBit(oldp+31,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000016U)))));
        bufp->chgBit(oldp+32,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000017U)))));
        bufp->chgBit(oldp+33,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000018U)))));
        bufp->chgBit(oldp+34,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000019U)))));
        bufp->chgBit(oldp+35,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000001aU)))));
        bufp->chgBit(oldp+36,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000001bU)))));
        bufp->chgBit(oldp+37,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000001cU)))));
        bufp->chgBit(oldp+38,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000001dU)))));
        bufp->chgBit(oldp+39,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000000bU)))));
        bufp->chgBit(oldp+40,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000001eU)))));
        bufp->chgBit(oldp+41,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000001fU)))));
        bufp->chgBit(oldp+42,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000020U)))));
        bufp->chgBit(oldp+43,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000021U)))));
        bufp->chgBit(oldp+44,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000022U)))));
        bufp->chgBit(oldp+45,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000023U)))));
        bufp->chgBit(oldp+46,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000024U)))));
        bufp->chgBit(oldp+47,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000025U)))));
        bufp->chgBit(oldp+48,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000026U)))));
        bufp->chgBit(oldp+49,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000027U)))));
        bufp->chgBit(oldp+50,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000000cU)))));
        bufp->chgBit(oldp+51,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000028U)))));
        bufp->chgBit(oldp+52,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000029U)))));
        bufp->chgBit(oldp+53,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000000dU)))));
        bufp->chgBit(oldp+54,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000000eU)))));
        bufp->chgBit(oldp+55,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x0000000fU)))));
        bufp->chgBit(oldp+56,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000010U)))));
        bufp->chgBit(oldp+57,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000011U)))));
        bufp->chgBit(oldp+58,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000012U)))));
        bufp->chgBit(oldp+59,((1U & (IData)((vlSelfRef.top_env__DOT__apb_in 
                                             >> 0x00000013U)))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[13U]))) {
        __Vtemp_1[0U] = (IData)((((QData)((IData)((0x00000010U 
                                                   | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwrite) 
                                                       << 6U) 
                                                      | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hburst))))) 
                                  << 0x00000027U) | 
                                 (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hprot)) 
                                   << 0x00000023U) 
                                  | (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans)) 
                                      << 0x00000021U) 
                                     | (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hmastlock)) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata)))))));
        __Vtemp_1[1U] = ((vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__haddr 
                          << 0x0000000eU) | (IData)(
                                                    ((((QData)((IData)(
                                                                       (0x00000010U 
                                                                        | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwrite) 
                                                                            << 6U) 
                                                                           | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hburst))))) 
                                                       << 0x00000027U) 
                                                      | (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hprot)) 
                                                          << 0x00000023U) 
                                                         | (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans)) 
                                                             << 0x00000021U) 
                                                            | (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hmastlock)) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata)))))) 
                                                     >> 0x00000020U)));
        __Vtemp_1[2U] = (vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__haddr 
                         >> 0x00000012U);
        bufp->chgWData(oldp+60,(__Vtemp_1),78);
        bufp->chgQData(oldp+63,((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__prdata)) 
                                  << 2U) | (QData)((IData)(
                                                           (2U 
                                                            | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__pslverr)))))),34);
        bufp->chgBit(oldp+65,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata));
        bufp->chgBit(oldp+66,(((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata)) 
                               & (IData)(vlSelfRef.top_env__DOT__edge_detector_u__DOT__g_catch__DOT__sig_d1))));
        bufp->chgCData(oldp+67,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans),2);
        bufp->chgIData(oldp+68,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata),32);
        bufp->chgBit(oldp+69,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwrite));
        bufp->chgSData(oldp+70,(vlSelfRef.top_env__DOT__ahb_fet_mem_u__DOT__address),16);
        bufp->chgBit(oldp+71,(vlSelfRef.top_env__DOT__ahb_fet_mem_u__DOT__do_write));
        bufp->chgSData(oldp+72,((0x0000ffffU & vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__haddr)),16);
        bufp->chgCData(oldp+73,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans),2);
        bufp->chgIData(oldp+74,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata),32);
        bufp->chgBit(oldp+75,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwrite));
        bufp->chgSData(oldp+76,(vlSelfRef.top_env__DOT__ahb_lsu_mem_u__DOT__address),16);
        bufp->chgBit(oldp+77,(vlSelfRef.top_env__DOT__ahb_lsu_mem_u__DOT__do_write));
        bufp->chgIData(oldp+78,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__haddr),32);
        bufp->chgCData(oldp+79,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hburst),3);
        bufp->chgCData(oldp+80,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hprot),4);
        bufp->chgCData(oldp+81,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans),2);
        bufp->chgBit(oldp+82,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hmastlock));
        bufp->chgCData(oldp+83,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hburst),3);
        bufp->chgCData(oldp+84,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hprot),4);
        bufp->chgCData(oldp+85,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans),2);
        bufp->chgBit(oldp+86,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hmastlock));
        bufp->chgIData(oldp+87,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__prdata),32);
        bufp->chgIData(oldp+88,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd),30);
        bufp->chgCData(oldp+89,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type),2);
        bufp->chgIData(oldp+90,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd),31);
        bufp->chgBit(oldp+91,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready));
        bufp->chgBit(oldp+92,(((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_ff) 
                               & (2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)))));
        bufp->chgBit(oldp+93,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid));
        bufp->chgBit(oldp+94,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__is_req_from_tu))));
        bufp->chgIData(oldp+95,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q
                                [vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q]),32);
        bufp->chgBit(oldp+96,((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len))));
        bufp->chgBit(oldp+97,((1U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state))));
        bufp->chgBit(oldp+98,((2U < (0x0000000fU & 
                                     ((IData)(8U) - (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len))))));
        Vtop_env___024root__trace_chg_dtype____0(vlSelf, bufp, 99, vlSelfRef.top_env__DOT__core_u__DOT__vid_arr);
        bufp->chgBit(oldp+103,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o));
        bufp->chgCData(oldp+104,(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr),2);
        bufp->chgCData(oldp+105,(vlSelfRef.top_env__DOT__core_u__DOT__thread_sel_d1),2);
        bufp->chgBit(oldp+106,(((IData)(vlSelfRef.top_env__DOT__core_u__DOT__thread_sel_d1) 
                                != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr))));
        bufp->chgQData(oldp+107,(vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[0U]),33);
        bufp->chgQData(oldp+109,(vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[1U]),33);
        bufp->chgQData(oldp+111,(vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[2U]),33);
        bufp->chgQData(oldp+113,(vlSelfRef.top_env__DOT__core_u__DOT__rs1_arr[3U]),33);
        bufp->chgQData(oldp+115,(vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[0U]),33);
        bufp->chgQData(oldp+117,(vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[1U]),33);
        bufp->chgQData(oldp+119,(vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[2U]),33);
        bufp->chgQData(oldp+121,(vlSelfRef.top_env__DOT__core_u__DOT__rs2_arr[3U]),33);
        Vtop_env___024root__trace_chg_dtype____1(vlSelf, bufp, 123, vlSelfRef.top_env__DOT__core_u__DOT__thread_states);
        bufp->chgBit(oldp+127,(vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[0]));
        bufp->chgBit(oldp+128,(vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[1]));
        bufp->chgBit(oldp+129,(vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[2]));
        bufp->chgBit(oldp+130,(vlSelfRef.top_env__DOT__core_u__DOT__lsu_r2_thread[3]));
        bufp->chgBit(oldp+131,((0U != vlSelfRef.top_env__DOT__core_u__DOT__thread_states
                                [vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr])));
        bufp->chgBit(oldp+132,((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state))));
        bufp->chgCData(oldp+133,(((((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                                    << 3U) | ((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                                              << 2U)) 
                                  | (((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state)) 
                                      << 1U) | (2U 
                                                == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state))))),4);
        bufp->chgBit(oldp+134,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i));
        bufp->chgBit(oldp+135,((1U == vlSelfRef.top_env__DOT__core_u__DOT__thread_states
                                [vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr])));
        bufp->chgBit(oldp+136,((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr))));
        bufp->chgCData(oldp+137,(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__is_req_from_tu),4);
        bufp->chgIData(oldp+138,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata),32);
        bufp->chgCData(oldp+139,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__next_state),3);
        bufp->chgCData(oldp+140,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__state),3);
        bufp->chgBit(oldp+141,((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__next_state))));
        bufp->chgIData(oldp+142,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata),32);
        bufp->chgIData(oldp+143,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[0]),32);
        bufp->chgIData(oldp+144,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[1]),32);
        bufp->chgIData(oldp+145,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[2]),32);
        bufp->chgIData(oldp+146,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata[3]),32);
        bufp->chgIData(oldp+147,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata),32);
        bufp->chgIData(oldp+148,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[0]),32);
        bufp->chgIData(oldp+149,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[1]),32);
        bufp->chgIData(oldp+150,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[2]),32);
        bufp->chgIData(oldp+151,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata[3]),32);
        bufp->chgIData(oldp+152,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata
                                 [vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr]),32);
        bufp->chgIData(oldp+153,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__wdata_masked),32);
        bufp->chgBit(oldp+154,(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata));
        bufp->chgBit(oldp+155,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__l_cmd_valid));
        bufp->chgBit(oldp+156,(((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)) 
                                & (0U == (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)))));
        bufp->chgBit(oldp+157,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__s_cmd_valid));
        bufp->chgBit(oldp+158,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__f_cmd_valid));
        bufp->chgBit(oldp+159,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_load));
        bufp->chgBit(oldp+160,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_store));
        bufp->chgBit(oldp+161,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__i_with_delay));
        bufp->chgBit(oldp+162,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_prev));
        bufp->chgBit(oldp+163,(((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_prev)) 
                                & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i))));
        bufp->chgBit(oldp+164,(((~ ((~ ((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_prev)) 
                                        & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i))) 
                                    & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__i_with_delay))) 
                                & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i))));
        bufp->chgBit(oldp+165,(((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o)) 
                                & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata))));
        bufp->chgCData(oldp+166,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state),2);
        bufp->chgCData(oldp+167,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state),2);
        bufp->chgBit(oldp+168,((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state))));
        bufp->chgBit(oldp+169,((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state))));
        bufp->chgBit(oldp+170,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state))));
        bufp->chgBit(oldp+171,((2U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state))));
        bufp->chgIData(oldp+172,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff),31);
        bufp->chgBit(oldp+173,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_valid_ff));
        bufp->chgBit(oldp+174,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_ff));
        bufp->chgBit(oldp+175,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid_ff));
        bufp->chgIData(oldp+176,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_ff),30);
        bufp->chgCData(oldp+177,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_op_type_ff),2);
        bufp->chgBit(oldp+178,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__no_fpu_cmd_valid));
        bufp->chgIData(oldp+179,((vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__cmd_idx_ff 
                                  & (- (IData)((2U 
                                                == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__state)))))),32);
        bufp->chgIData(oldp+180,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__cmd_idx_ff),32);
        bufp->chgQData(oldp+181,(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command),47);
        bufp->chgCData(oldp+183,((0x0000000fU & ((IData)(8U) 
                                                 - (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len)))),4);
        bufp->chgBit(oldp+184,((2U >= (0x0000000fU 
                                       & ((IData)(8U) 
                                          - (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len))))));
        bufp->chgBit(oldp+185,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__stop_load_pc_ff));
        bufp->chgBit(oldp+186,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__data_valid_o));
        bufp->chgBit(oldp+187,((1U & (~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__stop_load_pc_ff)))));
        bufp->chgBit(oldp+188,(((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__stop_load_pc_ff)) 
                                & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__data_valid_o))));
        bufp->chgBit(oldp+189,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__q_data_give));
        bufp->chgIData(oldp+190,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__pc_i_ff),32);
        bufp->chgBit(oldp+191,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__make_it_done));
        bufp->chgBit(oldp+192,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__en_i_prev));
        bufp->chgBit(oldp+193,(((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__en_i_prev)) 
                                & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata))));
        Vtop_env___024root__trace_chg_dtype____2(vlSelf, bufp, 194, vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q);
        bufp->chgCData(oldp+202,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q),3);
        bufp->chgCData(oldp+203,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q),3);
        bufp->chgCData(oldp+204,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len),4);
        bufp->chgBit(oldp+205,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len))));
        bufp->chgBit(oldp+206,((0U == (0x0000000fU 
                                       & ((IData)(8U) 
                                          - (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len))))));
        bufp->chgBit(oldp+207,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__store_inst));
        bufp->chgCData(oldp+208,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__state),3);
        bufp->chgIData(oldp+209,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata_i),32);
        bufp->chgBit(oldp+210,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_ff));
        bufp->chgIData(oldp+211,((IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1 
                                          >> 1U))),32);
        bufp->chgIData(oldp+212,((IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs2 
                                          >> 1U))),32);
        bufp->chgBit(oldp+213,((1U & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1))));
        bufp->chgBit(oldp+214,((1U & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs2))));
        bufp->chgBit(oldp+215,(((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o) 
                                & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10))));
        bufp->chgBit(oldp+216,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_active));
        bufp->chgBit(oldp+217,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff));
        bufp->chgBit(oldp+218,(((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_active) 
                                & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__thread_sel_d1) 
                                   != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr)))));
        bufp->chgBit(oldp+219,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o));
        bufp->chgCData(oldp+220,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__state),2);
        bufp->chgCData(oldp+221,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state),2);
        bufp->chgBit(oldp+222,((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state))));
        bufp->chgBit(oldp+223,((1U & (~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff)))));
        bufp->chgBit(oldp+224,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff));
        bufp->chgIData(oldp+225,((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff) 
                                   & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1))
                                   ? (IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1 
                                              >> 1U))
                                   : ((IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1 
                                               >> 1U)) 
                                      & (- (IData)(
                                                   ((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1) 
                                                    & ((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff)) 
                                                       & (1U 
                                                          == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state))))))))),32);
        bufp->chgIData(oldp+226,(((IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs2 
                                           >> 1U)) 
                                  & (- (IData)(((IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs2) 
                                                & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9)))))),32);
        bufp->chgBit(oldp+227,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i));
        bufp->chgCData(oldp+228,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__state),3);
        bufp->chgCData(oldp+229,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__next_state),3);
        bufp->chgBit(oldp+230,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__next_state))));
        bufp->chgIData(oldp+231,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata_i),32);
        bufp->chgBit(oldp+232,(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_ff));
        bufp->chgBit(oldp+233,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__lsu_ready_i));
        bufp->chgIData(oldp+234,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i),32);
        bufp->chgCData(oldp+235,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state),2);
        bufp->chgIData(oldp+236,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1),32);
        bufp->chgIData(oldp+237,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs2),32);
        bufp->chgBit(oldp+238,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1_valid));
        bufp->chgBit(oldp+239,((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))));
        bufp->chgBit(oldp+240,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))));
        bufp->chgBit(oldp+241,((3U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type))));
        bufp->chgIData(oldp+242,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd),30);
        bufp->chgIData(oldp+243,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd),30);
        bufp->chgIData(oldp+244,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd),30);
        bufp->chgBit(oldp+245,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op));
        bufp->chgBit(oldp+246,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op));
        bufp->chgCData(oldp+247,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state),3);
        bufp->chgBit(oldp+248,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state))));
        bufp->chgCData(oldp+249,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__next_thread_state),2);
        bufp->chgBit(oldp+250,((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state))));
        bufp->chgBit(oldp+251,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_stall));
        bufp->chgCData(oldp+252,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_rd_addr),5);
        bufp->chgBit(oldp+253,((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state))));
        bufp->chgCData(oldp+254,((0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                                                  ? 
                                                 (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 6U)
                                                  : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)))),5);
        bufp->chgCData(oldp+255,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1),5);
        bufp->chgCData(oldp+256,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2),5);
        bufp->chgBit(oldp+257,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result));
        bufp->chgBit(oldp+258,(((~ (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev)) 
                                & (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready))));
        bufp->chgCData(oldp+259,((7U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd)),3);
        bufp->chgCData(oldp+260,((0x0000000fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                 >> 0x0000001bU))),4);
        bufp->chgBit(oldp+261,((1U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                      >> 0x0000001aU))));
        bufp->chgCData(oldp+262,((7U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                        >> 3U))),3);
        bufp->chgCData(oldp+263,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r),5);
        bufp->chgBit(oldp+264,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev));
        bufp->chgCData(oldp+265,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state),3);
        bufp->chgBit(oldp+266,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load));
        bufp->chgCData(oldp+267,((0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                 >> 0x00000015U))),5);
        bufp->chgCData(oldp+268,((0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                 >> 0x00000010U))),5);
        bufp->chgCData(oldp+269,((0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                 >> 0x0000000bU))),5);
        bufp->chgBit(oldp+270,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__lsu_ready_i));
        bufp->chgIData(oldp+271,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i),32);
        bufp->chgCData(oldp+272,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state),2);
        bufp->chgIData(oldp+273,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1),32);
        bufp->chgIData(oldp+274,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs2),32);
        bufp->chgBit(oldp+275,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1_valid));
        bufp->chgCData(oldp+276,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state),3);
        bufp->chgBit(oldp+277,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state))));
        bufp->chgCData(oldp+278,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__next_thread_state),2);
        bufp->chgBit(oldp+279,((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state))));
        bufp->chgBit(oldp+280,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_stall));
        bufp->chgCData(oldp+281,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_rd_addr),5);
        bufp->chgBit(oldp+282,((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state))));
        bufp->chgCData(oldp+283,((0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                                                  ? 
                                                 (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 6U)
                                                  : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)))),5);
        bufp->chgBit(oldp+284,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result));
        bufp->chgCData(oldp+285,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r),5);
        bufp->chgCData(oldp+286,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state),3);
        bufp->chgBit(oldp+287,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load));
        bufp->chgBit(oldp+288,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__lsu_ready_i));
        bufp->chgIData(oldp+289,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i),32);
        bufp->chgCData(oldp+290,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state),2);
        bufp->chgIData(oldp+291,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1),32);
        bufp->chgIData(oldp+292,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs2),32);
        bufp->chgBit(oldp+293,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1_valid));
        bufp->chgCData(oldp+294,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state),3);
        bufp->chgBit(oldp+295,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state))));
        bufp->chgCData(oldp+296,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__next_thread_state),2);
        bufp->chgBit(oldp+297,((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state))));
        bufp->chgBit(oldp+298,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_stall));
        bufp->chgCData(oldp+299,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_rd_addr),5);
        bufp->chgBit(oldp+300,((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state))));
        bufp->chgCData(oldp+301,((0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                                                  ? 
                                                 (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 6U)
                                                  : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)))),5);
        bufp->chgBit(oldp+302,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result));
        bufp->chgCData(oldp+303,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r),5);
        bufp->chgCData(oldp+304,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state),3);
        bufp->chgBit(oldp+305,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load));
        bufp->chgBit(oldp+306,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__lsu_ready_i));
        bufp->chgIData(oldp+307,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i),32);
        bufp->chgCData(oldp+308,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state),2);
        bufp->chgIData(oldp+309,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1),32);
        bufp->chgIData(oldp+310,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs2),32);
        bufp->chgBit(oldp+311,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1_valid));
        bufp->chgCData(oldp+312,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state),3);
        bufp->chgBit(oldp+313,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state))));
        bufp->chgCData(oldp+314,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__next_thread_state),2);
        bufp->chgBit(oldp+315,((1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state))));
        bufp->chgBit(oldp+316,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_stall));
        bufp->chgCData(oldp+317,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_rd_addr),5);
        bufp->chgBit(oldp+318,((0U != (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state))));
        bufp->chgCData(oldp+319,((0x0000001fU & ((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready)
                                                  ? 
                                                 (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 6U)
                                                  : (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r)))),5);
        bufp->chgBit(oldp+320,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result));
        bufp->chgCData(oldp+321,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r),5);
        bufp->chgCData(oldp+322,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state),3);
        bufp->chgBit(oldp+323,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load));
        bufp->chgBit(oldp+324,(vlSelfRef.top_env__DOT__edge_detector_u__DOT__g_catch__DOT__sig_d1));
        bufp->chgQData(oldp+325,((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1)) 
                                   << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1_valid)))),33);
        bufp->chgQData(oldp+327,((1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs2)) 
                                          << 1U))),33);
        bufp->chgQData(oldp+329,((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1)) 
                                   << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1_valid)))),33);
        bufp->chgQData(oldp+331,((1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs2)) 
                                          << 1U))),33);
        bufp->chgQData(oldp+333,((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1)) 
                                   << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1_valid)))),33);
        bufp->chgQData(oldp+335,((1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs2)) 
                                          << 1U))),33);
        bufp->chgQData(oldp+337,((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1)) 
                                   << 1U) | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1_valid)))),33);
        bufp->chgQData(oldp+339,((1ULL | ((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs2)) 
                                          << 1U))),33);
        bufp->chgQData(oldp+341,(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs1),33);
        bufp->chgQData(oldp+343,(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rs2),33);
        bufp->chgBit(oldp+345,((1U & vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)));
        bufp->chgBit(oldp+346,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+347,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000aU))));
        bufp->chgBit(oldp+348,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+349,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000bU))));
        bufp->chgBit(oldp+350,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+351,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000cU))));
        bufp->chgBit(oldp+352,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+353,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000dU))));
        bufp->chgBit(oldp+354,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+355,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000eU))));
        bufp->chgBit(oldp+356,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+357,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000fU))));
        bufp->chgBit(oldp+358,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+359,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000010U))));
        bufp->chgBit(oldp+360,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+361,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000011U))));
        bufp->chgBit(oldp+362,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+363,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000012U))));
        bufp->chgBit(oldp+364,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+365,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000013U))));
        bufp->chgBit(oldp+366,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+367,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 1U))));
        bufp->chgBit(oldp+368,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+369,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000014U))));
        bufp->chgBit(oldp+370,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+371,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000015U))));
        bufp->chgBit(oldp+372,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+373,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000016U))));
        bufp->chgBit(oldp+374,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+375,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000017U))));
        bufp->chgBit(oldp+376,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+377,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000018U))));
        bufp->chgBit(oldp+378,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+379,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000019U))));
        bufp->chgBit(oldp+380,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+381,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001aU))));
        bufp->chgBit(oldp+382,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+383,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001bU))));
        bufp->chgBit(oldp+384,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+385,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001cU))));
        bufp->chgBit(oldp+386,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+387,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001dU))));
        bufp->chgBit(oldp+388,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+389,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 2U))));
        bufp->chgBit(oldp+390,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+391,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001eU))));
        bufp->chgBit(oldp+392,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+393,((vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                >> 0x0000001fU)));
        bufp->chgBit(oldp+394,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+395,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 3U))));
        bufp->chgBit(oldp+396,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+397,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 4U))));
        bufp->chgBit(oldp+398,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+399,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 5U))));
        bufp->chgBit(oldp+400,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+401,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 6U))));
        bufp->chgBit(oldp+402,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+403,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 7U))));
        bufp->chgBit(oldp+404,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+405,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 8U))));
        bufp->chgBit(oldp+406,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+407,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 9U))));
        bufp->chgBit(oldp+408,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit));
        bufp->chgIData(oldp+409,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata),32);
        bufp->chgBit(oldp+410,((1U & vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)));
        bufp->chgBit(oldp+411,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+412,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000aU))));
        bufp->chgBit(oldp+413,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+414,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000bU))));
        bufp->chgBit(oldp+415,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+416,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000cU))));
        bufp->chgBit(oldp+417,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+418,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000dU))));
        bufp->chgBit(oldp+419,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+420,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000eU))));
        bufp->chgBit(oldp+421,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+422,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000fU))));
        bufp->chgBit(oldp+423,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+424,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000010U))));
        bufp->chgBit(oldp+425,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+426,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000011U))));
        bufp->chgBit(oldp+427,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+428,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000012U))));
        bufp->chgBit(oldp+429,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+430,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000013U))));
        bufp->chgBit(oldp+431,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+432,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 1U))));
        bufp->chgBit(oldp+433,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+434,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000014U))));
        bufp->chgBit(oldp+435,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+436,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000015U))));
        bufp->chgBit(oldp+437,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+438,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000016U))));
        bufp->chgBit(oldp+439,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+440,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000017U))));
        bufp->chgBit(oldp+441,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+442,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000018U))));
        bufp->chgBit(oldp+443,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+444,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000019U))));
        bufp->chgBit(oldp+445,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+446,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001aU))));
        bufp->chgBit(oldp+447,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+448,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001bU))));
        bufp->chgBit(oldp+449,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+450,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001cU))));
        bufp->chgBit(oldp+451,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+452,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001dU))));
        bufp->chgBit(oldp+453,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+454,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 2U))));
        bufp->chgBit(oldp+455,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+456,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001eU))));
        bufp->chgBit(oldp+457,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+458,((vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                >> 0x0000001fU)));
        bufp->chgBit(oldp+459,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+460,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 3U))));
        bufp->chgBit(oldp+461,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+462,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 4U))));
        bufp->chgBit(oldp+463,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+464,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 5U))));
        bufp->chgBit(oldp+465,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+466,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 6U))));
        bufp->chgBit(oldp+467,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+468,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 7U))));
        bufp->chgBit(oldp+469,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+470,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 8U))));
        bufp->chgBit(oldp+471,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+472,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 9U))));
        bufp->chgBit(oldp+473,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit));
        bufp->chgIData(oldp+474,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata),32);
        bufp->chgBit(oldp+475,((1U & vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)));
        bufp->chgBit(oldp+476,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+477,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000aU))));
        bufp->chgBit(oldp+478,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+479,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000bU))));
        bufp->chgBit(oldp+480,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+481,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000cU))));
        bufp->chgBit(oldp+482,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+483,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000dU))));
        bufp->chgBit(oldp+484,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+485,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000eU))));
        bufp->chgBit(oldp+486,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+487,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000fU))));
        bufp->chgBit(oldp+488,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+489,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000010U))));
        bufp->chgBit(oldp+490,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+491,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000011U))));
        bufp->chgBit(oldp+492,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+493,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000012U))));
        bufp->chgBit(oldp+494,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+495,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000013U))));
        bufp->chgBit(oldp+496,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+497,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 1U))));
        bufp->chgBit(oldp+498,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+499,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000014U))));
        bufp->chgBit(oldp+500,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+501,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000015U))));
        bufp->chgBit(oldp+502,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+503,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000016U))));
        bufp->chgBit(oldp+504,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+505,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000017U))));
        bufp->chgBit(oldp+506,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+507,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000018U))));
        bufp->chgBit(oldp+508,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+509,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000019U))));
        bufp->chgBit(oldp+510,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+511,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001aU))));
        bufp->chgBit(oldp+512,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+513,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001bU))));
        bufp->chgBit(oldp+514,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+515,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001cU))));
        bufp->chgBit(oldp+516,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+517,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001dU))));
        bufp->chgBit(oldp+518,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+519,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 2U))));
        bufp->chgBit(oldp+520,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+521,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001eU))));
        bufp->chgBit(oldp+522,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+523,((vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                >> 0x0000001fU)));
        bufp->chgBit(oldp+524,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+525,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 3U))));
        bufp->chgBit(oldp+526,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+527,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 4U))));
        bufp->chgBit(oldp+528,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+529,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 5U))));
        bufp->chgBit(oldp+530,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+531,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 6U))));
        bufp->chgBit(oldp+532,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+533,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 7U))));
        bufp->chgBit(oldp+534,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+535,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 8U))));
        bufp->chgBit(oldp+536,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+537,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 9U))));
        bufp->chgBit(oldp+538,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit));
        bufp->chgIData(oldp+539,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata),32);
        bufp->chgBit(oldp+540,((1U & vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)));
        bufp->chgBit(oldp+541,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+542,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000aU))));
        bufp->chgBit(oldp+543,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+544,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000bU))));
        bufp->chgBit(oldp+545,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+546,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000cU))));
        bufp->chgBit(oldp+547,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+548,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000dU))));
        bufp->chgBit(oldp+549,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+550,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000eU))));
        bufp->chgBit(oldp+551,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+552,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000fU))));
        bufp->chgBit(oldp+553,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+554,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000010U))));
        bufp->chgBit(oldp+555,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+556,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000011U))));
        bufp->chgBit(oldp+557,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+558,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000012U))));
        bufp->chgBit(oldp+559,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+560,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000013U))));
        bufp->chgBit(oldp+561,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+562,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 1U))));
        bufp->chgBit(oldp+563,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+564,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000014U))));
        bufp->chgBit(oldp+565,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+566,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000015U))));
        bufp->chgBit(oldp+567,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+568,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000016U))));
        bufp->chgBit(oldp+569,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+570,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000017U))));
        bufp->chgBit(oldp+571,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+572,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000018U))));
        bufp->chgBit(oldp+573,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+574,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000019U))));
        bufp->chgBit(oldp+575,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+576,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001aU))));
        bufp->chgBit(oldp+577,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+578,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001bU))));
        bufp->chgBit(oldp+579,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+580,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001cU))));
        bufp->chgBit(oldp+581,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+582,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001dU))));
        bufp->chgBit(oldp+583,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+584,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 2U))));
        bufp->chgBit(oldp+585,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+586,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001eU))));
        bufp->chgBit(oldp+587,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+588,((vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                >> 0x0000001fU)));
        bufp->chgBit(oldp+589,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+590,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 3U))));
        bufp->chgBit(oldp+591,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+592,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 4U))));
        bufp->chgBit(oldp+593,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+594,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 5U))));
        bufp->chgBit(oldp+595,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+596,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 6U))));
        bufp->chgBit(oldp+597,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+598,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 7U))));
        bufp->chgBit(oldp+599,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+600,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 8U))));
        bufp->chgBit(oldp+601,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+602,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 9U))));
        bufp->chgBit(oldp+603,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit));
        bufp->chgIData(oldp+604,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata),32);
        bufp->chgBit(oldp+605,((1U & vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata)));
        bufp->chgBit(oldp+606,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__0__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+607,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000aU))));
        bufp->chgBit(oldp+608,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__10__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+609,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000bU))));
        bufp->chgBit(oldp+610,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__11__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+611,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000cU))));
        bufp->chgBit(oldp+612,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__12__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+613,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000dU))));
        bufp->chgBit(oldp+614,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__13__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+615,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000eU))));
        bufp->chgBit(oldp+616,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__14__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+617,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000000fU))));
        bufp->chgBit(oldp+618,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__15__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+619,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000010U))));
        bufp->chgBit(oldp+620,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__16__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+621,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000011U))));
        bufp->chgBit(oldp+622,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__17__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+623,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000012U))));
        bufp->chgBit(oldp+624,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__18__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+625,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000013U))));
        bufp->chgBit(oldp+626,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__19__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+627,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 1U))));
        bufp->chgBit(oldp+628,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__1__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+629,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000014U))));
        bufp->chgBit(oldp+630,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__20__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+631,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000015U))));
        bufp->chgBit(oldp+632,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__21__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+633,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000016U))));
        bufp->chgBit(oldp+634,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__22__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+635,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000017U))));
        bufp->chgBit(oldp+636,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__23__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+637,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000018U))));
        bufp->chgBit(oldp+638,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__24__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+639,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x00000019U))));
        bufp->chgBit(oldp+640,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__25__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+641,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001aU))));
        bufp->chgBit(oldp+642,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__26__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+643,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001bU))));
        bufp->chgBit(oldp+644,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__27__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+645,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001cU))));
        bufp->chgBit(oldp+646,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__28__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+647,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001dU))));
        bufp->chgBit(oldp+648,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__29__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+649,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 2U))));
        bufp->chgBit(oldp+650,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__2__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+651,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 0x0000001eU))));
        bufp->chgBit(oldp+652,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__30__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+653,((vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                >> 0x0000001fU)));
        bufp->chgBit(oldp+654,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__31__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+655,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 3U))));
        bufp->chgBit(oldp+656,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__3__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+657,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 4U))));
        bufp->chgBit(oldp+658,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__4__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+659,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 5U))));
        bufp->chgBit(oldp+660,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__5__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+661,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 6U))));
        bufp->chgBit(oldp+662,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__6__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+663,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 7U))));
        bufp->chgBit(oldp+664,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__7__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+665,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 8U))));
        bufp->chgBit(oldp+666,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__8__KET____DOT__bit_u__rbit));
        bufp->chgBit(oldp+667,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wedata 
                                      >> 9U))));
        bufp->chgBit(oldp+668,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg.g_fields__BRA__0__KET____DOT__field_u__DOT____Vcellout__g_bits__BRA__9__KET____DOT__bit_u__rbit));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[13U] 
                      | vlSelfRef.__Vm_traceActivity[14U])))) {
        bufp->chgIData(oldp+669,((vlSelfRef.top_env__DOT__fet_ahb_i__BRA__31__03a0__KET__ 
                                  & (- (IData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__data_valid_o))))),32);
        bufp->chgIData(oldp+670,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x00000015U))]),32);
        bufp->chgIData(oldp+671,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x00000010U))]),32);
        bufp->chgIData(oldp+672,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x0000000bU))]),32);
        bufp->chgIData(oldp+673,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1]),32);
        bufp->chgIData(oldp+674,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]),32);
        bufp->chgIData(oldp+675,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x00000015U))]),32);
        bufp->chgIData(oldp+676,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x00000010U))]),32);
        bufp->chgIData(oldp+677,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x0000000bU))]),32);
        bufp->chgIData(oldp+678,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1]),32);
        bufp->chgIData(oldp+679,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]),32);
        bufp->chgIData(oldp+680,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x00000015U))]),32);
        bufp->chgIData(oldp+681,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x00000010U))]),32);
        bufp->chgIData(oldp+682,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x0000000bU))]),32);
        bufp->chgIData(oldp+683,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1]),32);
        bufp->chgIData(oldp+684,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]),32);
        bufp->chgIData(oldp+685,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x00000015U))]),32);
        bufp->chgIData(oldp+686,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x00000010U))]),32);
        bufp->chgIData(oldp+687,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                  >> 0x0000000bU))]),32);
        bufp->chgIData(oldp+688,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1]),32);
        bufp->chgIData(oldp+689,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                 [vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2]),32);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[13U] 
                       | vlSelfRef.__Vm_traceActivity[14U]) 
                      | vlSelfRef.__Vm_traceActivity[15U])))) {
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready) {
            if ((2U == (0x0000000fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                       >> 0x0000001bU)))) {
                __Vtemp_5[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[0U];
                __Vtemp_5[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[1U];
                __Vtemp_5[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[2U];
            } else {
                __Vtemp_5[0U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                    [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                     >> 0x00000015U))];
                __Vtemp_5[1U] = (IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                          [
                                                          (0x0000001fU 
                                                           & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                              >> 0x0000000bU))])) 
                                          << 0x00000020U) 
                                         | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                           [
                                                           (0x0000001fU 
                                                            & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                               >> 0x00000010U))]))));
                __Vtemp_5[2U] = (IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                           [
                                                           (0x0000001fU 
                                                            & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                               >> 0x0000000bU))])) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x00000010U))]))) 
                                         >> 0x00000020U));
            }
        } else {
            __Vtemp_5[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[0U];
            __Vtemp_5[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[1U];
            __Vtemp_5[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[2U];
        }
        bufp->chgWData(oldp+690,(__Vtemp_5),96);
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready) {
            if ((2U == (0x0000000fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                       >> 0x0000001bU)))) {
                __Vtemp_9[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[0U];
                __Vtemp_9[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[1U];
                __Vtemp_9[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[2U];
            } else {
                __Vtemp_9[0U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                    [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                     >> 0x00000015U))];
                __Vtemp_9[1U] = (IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                          [
                                                          (0x0000001fU 
                                                           & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                              >> 0x0000000bU))])) 
                                          << 0x00000020U) 
                                         | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                           [
                                                           (0x0000001fU 
                                                            & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                               >> 0x00000010U))]))));
                __Vtemp_9[2U] = (IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                           [
                                                           (0x0000001fU 
                                                            & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                               >> 0x0000000bU))])) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x00000010U))]))) 
                                         >> 0x00000020U));
            }
        } else {
            __Vtemp_9[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[0U];
            __Vtemp_9[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[1U];
            __Vtemp_9[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6[2U];
        }
        bufp->chgWData(oldp+693,(__Vtemp_9),96);
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready) {
            if ((2U == (0x0000000fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                       >> 0x0000001bU)))) {
                __Vtemp_13[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[0U];
                __Vtemp_13[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[1U];
                __Vtemp_13[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[2U];
            } else {
                __Vtemp_13[0U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                    [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                     >> 0x00000015U))];
                __Vtemp_13[1U] = (IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                           [
                                                           (0x0000001fU 
                                                            & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                               >> 0x0000000bU))])) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x00000010U))]))));
                __Vtemp_13[2U] = (IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x0000000bU))])) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                             [
                                                             (0x0000001fU 
                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                 >> 0x00000010U))]))) 
                                          >> 0x00000020U));
            }
        } else {
            __Vtemp_13[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[0U];
            __Vtemp_13[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[1U];
            __Vtemp_13[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[2U];
        }
        bufp->chgWData(oldp+696,(__Vtemp_13),96);
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready) {
            if ((2U == (0x0000000fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                       >> 0x0000001bU)))) {
                __Vtemp_17[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[0U];
                __Vtemp_17[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[1U];
                __Vtemp_17[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[2U];
            } else {
                __Vtemp_17[0U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                    [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                     >> 0x00000015U))];
                __Vtemp_17[1U] = (IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                           [
                                                           (0x0000001fU 
                                                            & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                               >> 0x0000000bU))])) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x00000010U))]))));
                __Vtemp_17[2U] = (IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x0000000bU))])) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                             [
                                                             (0x0000001fU 
                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                 >> 0x00000010U))]))) 
                                          >> 0x00000020U));
            }
        } else {
            __Vtemp_17[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[0U];
            __Vtemp_17[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[1U];
            __Vtemp_17[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_5[2U];
        }
        bufp->chgWData(oldp+699,(__Vtemp_17),96);
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready) {
            if ((2U == (0x0000000fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                       >> 0x0000001bU)))) {
                __Vtemp_21[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[0U];
                __Vtemp_21[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[1U];
                __Vtemp_21[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[2U];
            } else {
                __Vtemp_21[0U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                    [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                     >> 0x00000015U))];
                __Vtemp_21[1U] = (IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                           [
                                                           (0x0000001fU 
                                                            & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                               >> 0x0000000bU))])) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x00000010U))]))));
                __Vtemp_21[2U] = (IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x0000000bU))])) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                             [
                                                             (0x0000001fU 
                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                 >> 0x00000010U))]))) 
                                          >> 0x00000020U));
            }
        } else {
            __Vtemp_21[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[0U];
            __Vtemp_21[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[1U];
            __Vtemp_21[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[2U];
        }
        bufp->chgWData(oldp+702,(__Vtemp_21),96);
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready) {
            if ((2U == (0x0000000fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                       >> 0x0000001bU)))) {
                __Vtemp_25[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[0U];
                __Vtemp_25[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[1U];
                __Vtemp_25[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[2U];
            } else {
                __Vtemp_25[0U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                    [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                     >> 0x00000015U))];
                __Vtemp_25[1U] = (IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                           [
                                                           (0x0000001fU 
                                                            & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                               >> 0x0000000bU))])) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x00000010U))]))));
                __Vtemp_25[2U] = (IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x0000000bU))])) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                             [
                                                             (0x0000001fU 
                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                 >> 0x00000010U))]))) 
                                          >> 0x00000020U));
            }
        } else {
            __Vtemp_25[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[0U];
            __Vtemp_25[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[1U];
            __Vtemp_25[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4[2U];
        }
        bufp->chgWData(oldp+705,(__Vtemp_25),96);
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready) {
            if ((2U == (0x0000000fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                       >> 0x0000001bU)))) {
                __Vtemp_29[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[0U];
                __Vtemp_29[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[1U];
                __Vtemp_29[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[2U];
            } else {
                __Vtemp_29[0U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                    [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                     >> 0x00000015U))];
                __Vtemp_29[1U] = (IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                           [
                                                           (0x0000001fU 
                                                            & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                               >> 0x0000000bU))])) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x00000010U))]))));
                __Vtemp_29[2U] = (IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x0000000bU))])) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                             [
                                                             (0x0000001fU 
                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                 >> 0x00000010U))]))) 
                                          >> 0x00000020U));
            }
        } else {
            __Vtemp_29[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[0U];
            __Vtemp_29[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[1U];
            __Vtemp_29[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[2U];
        }
        bufp->chgWData(oldp+708,(__Vtemp_29),96);
        if (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready) {
            if ((2U == (0x0000000fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                       >> 0x0000001bU)))) {
                __Vtemp_33[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[0U];
                __Vtemp_33[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[1U];
                __Vtemp_33[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[2U];
            } else {
                __Vtemp_33[0U] = vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                    [(0x0000001fU & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                     >> 0x00000015U))];
                __Vtemp_33[1U] = (IData)((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                           [
                                                           (0x0000001fU 
                                                            & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                               >> 0x0000000bU))])) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x00000010U))]))));
                __Vtemp_33[2U] = (IData)(((((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                            [
                                                            (0x0000001fU 
                                                             & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                >> 0x0000000bU))])) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf
                                                             [
                                                             (0x0000001fU 
                                                              & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd 
                                                                 >> 0x00000010U))]))) 
                                          >> 0x00000020U));
            }
        } else {
            __Vtemp_33[0U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[0U];
            __Vtemp_33[1U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[1U];
            __Vtemp_33[2U] = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3[2U];
        }
        bufp->chgWData(oldp+711,(__Vtemp_33),96);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[14U]))) {
        bufp->chgQData(oldp+714,((0x0000000200000000ULL 
                                  | (QData)((IData)(vlSelfRef.top_env__DOT__fet_ahb_i__BRA__31__03a0__KET__)))),34);
        bufp->chgIData(oldp+716,(vlSelfRef.top_env__DOT__fet_ahb_i__BRA__31__03a0__KET__),32);
        Vtop_env___024root__trace_chg_dtype____3(vlSelf, bufp, 717, vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf);
        Vtop_env___024root__trace_chg_dtype____3(vlSelf, bufp, 749, vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf);
        Vtop_env___024root__trace_chg_dtype____3(vlSelf, bufp, 781, vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf);
        Vtop_env___024root__trace_chg_dtype____3(vlSelf, bufp, 813, vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[15U]))) {
        bufp->chgIData(oldp+845,((IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.rd 
                                          >> 1U))),32);
        bufp->chgBit(oldp+846,((1U & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.rd))));
        bufp->chgIData(oldp+847,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_or),32);
        bufp->chgBit(oldp+848,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_rr));
        bufp->chgBit(oldp+849,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__wr_en));
        bufp->chgCData(oldp+850,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w),5);
        bufp->chgIData(oldp+851,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w),32);
        bufp->chgWData(oldp+852,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct),67);
        bufp->chgCData(oldp+855,((3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                        >> 1U))),2);
        bufp->chgIData(oldp+856,(((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                   << 0x0000001dU) 
                                  | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                     >> 3U))),32);
        bufp->chgIData(oldp+857,(((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                   << 0x0000001dU) 
                                  | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 3U))),32);
        bufp->chgBit(oldp+858,((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct[0U])));
        bufp->chgBit(oldp+859,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w))));
        bufp->chgBit(oldp+860,((0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w))));
        bufp->chgBit(oldp+861,(((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w)) 
                                | (0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w)))));
        bufp->chgIData(oldp+862,((IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.rd 
                                          >> 1U))),32);
        bufp->chgBit(oldp+863,((1U & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.rd))));
        bufp->chgIData(oldp+864,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_or),32);
        bufp->chgBit(oldp+865,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_rr));
        bufp->chgBit(oldp+866,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__wr_en));
        bufp->chgCData(oldp+867,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w),5);
        bufp->chgIData(oldp+868,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w),32);
        bufp->chgWData(oldp+869,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct),67);
        bufp->chgCData(oldp+872,((3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                        >> 1U))),2);
        bufp->chgIData(oldp+873,(((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                   << 0x0000001dU) 
                                  | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                     >> 3U))),32);
        bufp->chgIData(oldp+874,(((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                   << 0x0000001dU) 
                                  | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 3U))),32);
        bufp->chgBit(oldp+875,((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct[0U])));
        bufp->chgBit(oldp+876,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w))));
        bufp->chgBit(oldp+877,((0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w))));
        bufp->chgBit(oldp+878,(((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w)) 
                                | (0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w)))));
        bufp->chgIData(oldp+879,((IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.rd 
                                          >> 1U))),32);
        bufp->chgBit(oldp+880,((1U & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.rd))));
        bufp->chgIData(oldp+881,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_or),32);
        bufp->chgBit(oldp+882,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_rr));
        bufp->chgBit(oldp+883,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__wr_en));
        bufp->chgCData(oldp+884,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w),5);
        bufp->chgIData(oldp+885,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w),32);
        bufp->chgWData(oldp+886,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct),67);
        bufp->chgCData(oldp+889,((3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                        >> 1U))),2);
        bufp->chgIData(oldp+890,(((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                   << 0x0000001dU) 
                                  | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                     >> 3U))),32);
        bufp->chgIData(oldp+891,(((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                   << 0x0000001dU) 
                                  | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 3U))),32);
        bufp->chgBit(oldp+892,((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct[0U])));
        bufp->chgBit(oldp+893,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w))));
        bufp->chgBit(oldp+894,((0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w))));
        bufp->chgBit(oldp+895,(((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w)) 
                                | (0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w)))));
        bufp->chgIData(oldp+896,((IData)((vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.rd 
                                          >> 1U))),32);
        bufp->chgBit(oldp+897,((1U & (IData)(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.rd))));
        bufp->chgIData(oldp+898,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_or),32);
        bufp->chgBit(oldp+899,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_rr));
        bufp->chgBit(oldp+900,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__wr_en));
        bufp->chgCData(oldp+901,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w),5);
        bufp->chgIData(oldp+902,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w),32);
        bufp->chgWData(oldp+903,(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct),67);
        bufp->chgCData(oldp+906,((3U & (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                        >> 1U))),2);
        bufp->chgIData(oldp+907,(((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[2U] 
                                   << 0x0000001dU) 
                                  | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                     >> 3U))),32);
        bufp->chgIData(oldp+908,(((vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[1U] 
                                   << 0x0000001dU) 
                                  | (vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U] 
                                     >> 3U))),32);
        bufp->chgBit(oldp+909,((1U & vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct[0U])));
        bufp->chgBit(oldp+910,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w))));
        bufp->chgBit(oldp+911,((0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w))));
        bufp->chgBit(oldp+912,(((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w)) 
                                | (0x1fU == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w)))));
        bufp->chgQData(oldp+913,(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__.rd),33);
        bufp->chgQData(oldp+915,(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__.rd),33);
        bufp->chgQData(oldp+917,(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__.rd),33);
        bufp->chgQData(oldp+919,(vlSymsp->TOP__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__.rd),33);
        bufp->chgQData(oldp+921,(vlSymsp->TOP__top_env__DOT__core_u__DOT__rl_if.rd),33);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[16U]))) {
        bufp->chgSData(oldp+923,((0x0000ffffU & vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__haddr)),16);
        bufp->chgIData(oldp+924,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__haddr),32);
        bufp->chgIData(oldp+925,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__addr_i),32);
        bufp->chgIData(oldp+926,(vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata),32);
        bufp->chgBit(oldp+927,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_i));
        bufp->chgCData(oldp+928,(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__next_state),3);
        bufp->chgBit(oldp+929,((0U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__next_state))));
        bufp->chgBit(oldp+930,((1U & vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata)));
        bufp->chgBit(oldp+931,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x0000000aU))));
        bufp->chgBit(oldp+932,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x0000000bU))));
        bufp->chgBit(oldp+933,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x0000000cU))));
        bufp->chgBit(oldp+934,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x0000000dU))));
        bufp->chgBit(oldp+935,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x0000000eU))));
        bufp->chgBit(oldp+936,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x0000000fU))));
        bufp->chgBit(oldp+937,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x00000010U))));
        bufp->chgBit(oldp+938,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x00000011U))));
        bufp->chgBit(oldp+939,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x00000012U))));
        bufp->chgBit(oldp+940,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x00000013U))));
        bufp->chgBit(oldp+941,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 1U))));
        bufp->chgBit(oldp+942,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x00000014U))));
        bufp->chgBit(oldp+943,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x00000015U))));
        bufp->chgBit(oldp+944,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x00000016U))));
        bufp->chgBit(oldp+945,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x00000017U))));
        bufp->chgBit(oldp+946,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x00000018U))));
        bufp->chgBit(oldp+947,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x00000019U))));
        bufp->chgBit(oldp+948,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x0000001aU))));
        bufp->chgBit(oldp+949,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x0000001bU))));
        bufp->chgBit(oldp+950,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x0000001cU))));
        bufp->chgBit(oldp+951,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x0000001dU))));
        bufp->chgBit(oldp+952,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 2U))));
        bufp->chgBit(oldp+953,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 0x0000001eU))));
        bufp->chgBit(oldp+954,((vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                >> 0x0000001fU)));
        bufp->chgBit(oldp+955,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 3U))));
        bufp->chgBit(oldp+956,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 4U))));
        bufp->chgBit(oldp+957,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 5U))));
        bufp->chgBit(oldp+958,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 6U))));
        bufp->chgBit(oldp+959,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 7U))));
        bufp->chgBit(oldp+960,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 8U))));
        bufp->chgBit(oldp+961,((1U & (vlSymsp->TOP__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg.__PVT__g_fields__BRA__0__KET____DOT__field_u__DOT__wdata 
                                      >> 9U))));
    }
    bufp->chgBit(oldp+962,(vlSelfRef.top_env__DOT__clk));
    bufp->chgBit(oldp+963,(vlSelfRef.top_env__DOT__rst_n));
    __Vtemp_34[0U] = (IData)((((QData)((IData)((0x00000010U 
                                                | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwrite) 
                                                    << 6U) 
                                                   | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hburst))))) 
                               << 0x00000027U) | (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hprot)) 
                                                   << 0x00000023U) 
                                                  | (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans)) 
                                                      << 0x00000021U) 
                                                     | (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hmastlock)) 
                                                         << 0x00000020U) 
                                                        | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata)))))));
    __Vtemp_34[1U] = ((vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__haddr 
                       << 0x0000000eU) | (IData)(((
                                                   ((QData)((IData)(
                                                                    (0x00000010U 
                                                                     | (((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwrite) 
                                                                         << 6U) 
                                                                        | (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hburst))))) 
                                                    << 0x00000027U) 
                                                   | (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hprot)) 
                                                       << 0x00000023U) 
                                                      | (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans)) 
                                                          << 0x00000021U) 
                                                         | (((QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hmastlock)) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata)))))) 
                                                  >> 0x00000020U)));
    __Vtemp_34[2U] = (vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__haddr 
                      >> 0x00000012U);
    bufp->chgWData(oldp+964,(__Vtemp_34),78);
    bufp->chgQData(oldp+967,((0x0000000200000000ULL 
                              | (QData)((IData)(vlSelfRef.top_env__DOT__lsu_ahb_i__BRA__31__03a0__KET__)))),34);
    bufp->chgBit(oldp+969,(vlSelfRef.top_env__DOT__active));
    bufp->chgSData(oldp+970,(vlSelfRef.top_env__DOT__core_u__DOT__thread_unit_info
                             [vlSelfRef.top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr]),10);
    bufp->chgIData(oldp+971,(vlSelfRef.top_env__DOT__monitor_core_active__Vstatic__ccr),32);
    bufp->chgIData(oldp+972,(vlSelfRef.top_env__DOT__lsu_ahb_i__BRA__31__03a0__KET__),32);
    Vtop_env___024root__trace_chg_dtype____4(vlSelf, bufp, 973, vlSelfRef.top_env__DOT__core_u__DOT__thread_unit_info);
    bufp->chgIData(oldp+977,(((0U == (0x0000007fU & (IData)(
                                                            (vlSelfRef.top_env__DOT__apb_in 
                                                             >> 0x0000002aU))))
                               ? (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata)
                               : ((8U == (0x0000007fU 
                                          & (IData)(
                                                    (vlSelfRef.top_env__DOT__apb_in 
                                                     >> 0x0000002aU))))
                                   ? vlSelfRef.top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__addr_i
                                   : (vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata
                                      [vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr] 
                                      & (- (IData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range))))))),32);
    bufp->chgBit(oldp+978,((((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__we) 
                             & (0ULL == (0x00000c0000000000ULL 
                                         & vlSelfRef.top_env__DOT__apb_in))) 
                            & (1U == (IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__next_state)))));
    bufp->chgIData(oldp+979,(((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o)
                               ? 1U : (vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
                                       & (- (IData)(
                                                    (0U 
                                                     == 
                                                     (0x0000007fU 
                                                      & (IData)(
                                                                (vlSelfRef.top_env__DOT__apb_in 
                                                                 >> 0x0000002aU))))))))),32);
    bufp->chgIData(oldp+980,(((- (IData)((0U == (0x0000007fU 
                                                 & (IData)(
                                                           (vlSelfRef.top_env__DOT__apb_in 
                                                            >> 0x0000002aU)))))) 
                              & vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__wdata_masked)),32);
    bufp->chgBit(oldp+981,((IData)(((0ULL == (0x0001fc0000000000ULL 
                                              & vlSelfRef.top_env__DOT__apb_in)) 
                                    & vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__wdata_masked))));
    bufp->chgBit(oldp+982,(((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o)
                             ? 1U : (1U & (vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
                                           & (- (IData)(
                                                        (0U 
                                                         == 
                                                         (0x0000007fU 
                                                          & (IData)(
                                                                    (vlSelfRef.top_env__DOT__apb_in 
                                                                     >> 0x0000002aU)))))))))));
    bufp->chgBit(oldp+983,(((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o)
                             ? 1U : (1U & (vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata 
                                           & (- (IData)(
                                                        (0U 
                                                         == 
                                                         (0x0000007fU 
                                                          & (IData)(
                                                                    (vlSelfRef.top_env__DOT__apb_in 
                                                                     >> 0x0000002aU)))))))))));
    bufp->chgBit(oldp+984,((IData)(((0ULL == (0x0001fc0000000000ULL 
                                              & vlSelfRef.top_env__DOT__apb_in)) 
                                    & vlSelfRef.top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__wdata_masked))));
    bufp->chgIData(oldp+985,(((- (IData)((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10))) 
                              & (vlSelfRef.top_env__DOT__lsu_ahb_i__BRA__31__03a0__KET__ 
                                 & (- (IData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o)))))),32);
    bufp->chgIData(oldp+986,((vlSelfRef.top_env__DOT__lsu_ahb_i__BRA__31__03a0__KET__ 
                              & (- (IData)((IData)(vlSelfRef.top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o))))),32);
}

void Vtop_env___024root__trace_chg_dtype____0(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 4>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root__trace_chg_dtype____0\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
}

void Vtop_env___024root__trace_chg_dtype____1(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*1:0*/, 4>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root__trace_chg_dtype____1\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,(__VdtypeVar[0U]),2);
    bufp->chgCData(oldp+1,(__VdtypeVar[1U]),2);
    bufp->chgCData(oldp+2,(__VdtypeVar[2U]),2);
    bufp->chgCData(oldp+3,(__VdtypeVar[3U]),2);
}

void Vtop_env___024root__trace_chg_dtype____2(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root__trace_chg_dtype____2\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),32);
}

void Vtop_env___024root__trace_chg_dtype____3(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root__trace_chg_dtype____3\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[31]),32);
}

void Vtop_env___024root__trace_chg_dtype____4(Vtop_env___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<SData/*9:0*/, 4>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root__trace_chg_dtype____4\n"); );
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgSData(oldp+0,(__VdtypeVar[0U]),10);
    bufp->chgSData(oldp+1,(__VdtypeVar[1U]),10);
    bufp->chgSData(oldp+2,(__VdtypeVar[2U]),10);
    bufp->chgSData(oldp+3,(__VdtypeVar[3U]),10);
}

void Vtop_env___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_env___024root__trace_cleanup\n"); );
    // Body
    Vtop_env___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_env___024root*>(voidSelf);
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[9U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[10U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[11U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[12U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[13U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[14U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[15U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[16U] = 0U;
}
