// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_env.h for the primary calling header

#ifndef VERILATED_VTOP_ENV___024ROOT_H_
#define VERILATED_VTOP_ENV___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtop_env_prim_register__FBz8_FCz7;
class Vtop_env_reg_if;


class Vtop_env__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_env___024root final {
  public:
    // CELLS
    Vtop_env_reg_if* __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__;
    Vtop_env_reg_if* __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__;
    Vtop_env_reg_if* __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__;
    Vtop_env_reg_if* __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__;
    Vtop_env_reg_if* __PVT__top_env__DOT__core_u__DOT__rl_if;
    Vtop_env_prim_register__FBz8_FCz7* __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg;
    Vtop_env_prim_register__FBz8_FCz7* __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg;
    Vtop_env_prim_register__FBz8_FCz7* __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg;
    Vtop_env_prim_register__FBz8_FCz7* __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg;
    Vtop_env_prim_register__FBz8_FCz7* __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ top_env__DOT__clk;
        CData/*0:0*/ top_env__DOT__rst_n;
        CData/*0:0*/ top_env__DOT__active;
        CData/*1:0*/ top_env__DOT__core_u__DOT__thread_sel_d1;
        CData/*1:0*/ top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__thread_ptr;
        CData/*3:0*/ top_env__DOT__core_u__DOT__core_arbitrage_u__DOT__is_req_from_tu;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__stop_load_pc_ff;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__q_data_give;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__make_it_done;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__en_i_prev;
        CData/*2:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_ptr_q;
        CData/*2:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__next_inst_ptr_q;
        CData/*3:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_buf_len;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__store_inst;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_i;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__data_valid_o;
        CData/*2:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hburst;
        CData/*3:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hprot;
        CData/*1:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__htrans;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwrite;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hmastlock;
        CData/*2:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__state;
        CData/*2:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__next_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__req_txn_ff;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_i;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__ret_inst_o;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__l_cmd_valid;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__s_cmd_valid;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__f_cmd_valid;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_load;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__is_lsu_store;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__i_with_delay;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__threads_valid_prev;
        CData/*1:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__state;
        CData/*1:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__next_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_valid_ff;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_ff;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__lsu_cmd_valid_ff;
        CData/*1:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_op_type_ff;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__no_fpu_cmd_valid;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_active;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__lsu_op_ff;
        CData/*1:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__state;
        CData/*1:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__next_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_i;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__data_valid_o;
        CData/*2:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hburst;
        CData/*3:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hprot;
        CData/*1:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__htrans;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwrite;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hmastlock;
        CData/*2:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__state;
        CData/*2:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__next_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__req_txn_ff;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__addr_in_vid_range;
        CData/*1:0*/ top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__g_logic_many_threads__DOT__local_vid_addr;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__core_ctrl_reg__DOT____Vcellout__g_fields__BRA__0__KET____DOT__field_u__rdata;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__pslverr;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__we;
        CData/*0:0*/ top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__re;
        CData/*2:0*/ top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__next_state;
        CData/*2:0*/ top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__state;
        CData/*1:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd_op_type;
    };
    struct {
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1_valid;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__store_op;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_op;
        CData/*2:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__state;
        CData/*1:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__next_thread_state;
        CData/*1:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cur_thread_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_stall;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__load_rd_addr;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_rr;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__wr_en;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__addr_w;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs1;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__addr_rs2;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready;
        CData/*2:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1_valid;
        CData/*2:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__state;
        CData/*1:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__next_thread_state;
        CData/*1:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__cur_thread_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_stall;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__load_rd_addr;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_rr;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__wr_en;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__addr_w;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r;
        CData/*2:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1_valid;
        CData/*2:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__state;
        CData/*1:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__next_thread_state;
        CData/*1:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__cur_thread_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_stall;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__load_rd_addr;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_rr;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__wr_en;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__addr_w;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r;
        CData/*2:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__lsu_ready_i;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1_valid;
        CData/*2:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__state;
        CData/*1:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__next_thread_state;
        CData/*1:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__cur_thread_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_stall;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__load_rd_addr;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_rr;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__wr_en;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__addr_w;
        CData/*4:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__gen_latch_r_addr__DOT__ff_addr_r;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__ready_prev;
        CData/*2:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__prev_state;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_give_result;
        CData/*0:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_fpu_fsm_u__DOT__fpu_load;
        CData/*0:0*/ top_env__DOT__ahb_lsu_mem_u__DOT__do_write;
        CData/*0:0*/ top_env__DOT__ahb_fet_mem_u__DOT__do_write;
    };
    struct {
        CData/*0:0*/ top_env__DOT__edge_detector_u__DOT__g_catch__DOT__sig_d1;
        CData/*0:0*/ __Vdpi_export_trigger;
        CData/*3:0*/ __Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__strb;
        CData/*1:0*/ __VdfgRegularize_h6e95ff9d_0_0;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_8;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_9;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_10;
        CData/*0:0*/ __VnbaEventTrigger;
        CData/*4:0*/ __VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        CData/*0:0*/ __VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        CData/*0:0*/ __VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1;
        CData/*4:0*/ __VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        CData/*0:0*/ __VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        CData/*0:0*/ __VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1;
        CData/*4:0*/ __VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        CData/*0:0*/ __VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        CData/*0:0*/ __VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1;
        CData/*4:0*/ __VdlyDim0__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        CData/*0:0*/ __VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        CData/*0:0*/ __VdlySet__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v1;
        CData/*0:0*/ __VdlySet__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top_env__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top_env__DOT__rst_n__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VinactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        SData/*15:0*/ top_env__DOT__ahb_lsu_mem_u__DOT__address;
        SData/*15:0*/ top_env__DOT__ahb_fet_mem_u__DOT__address;
        SData/*15:0*/ __VdlyDim0__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0;
        IData/*31:0*/ top_env__DOT__lsu_ahb_i__BRA__31__03a0__KET__;
        IData/*31:0*/ top_env__DOT__fet_ahb_i__BRA__31__03a0__KET__;
        IData/*31:0*/ top_env__DOT__monitor_core_active__Vstatic__ccr;
        IData/*31:0*/ top_env__DOT__start__Vstatic__start_pc;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__pc_i_ff;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__addr_i;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__haddr;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_fetcher_u__DOT__ahb_master_u__DOT__hwdata_i;
        IData/*30:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__fpu_cmd_ff;
        IData/*29:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__cmd_ff;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__cmd_idx_ff;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__haddr;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_lsu_u__DOT__ahb_master_u__DOT__hwdata_i;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__prdata;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__csrm_wedata;
        IData/*31:0*/ top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__wdata_masked;
        IData/*29:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__cmd;
        IData/*30:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__dec_cmd;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs1;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__rs2;
        IData/*29:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__l_cmd;
        IData/*29:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__u_cmd;
        IData/*29:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__s_cmd;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_or;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__data_w;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs1;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__rs2;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_or;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__data_w;
    };
    struct {
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs1;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__rs2;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_or;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__data_w;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs1;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__rs2;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_or;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__data_w;
        IData/*31:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__vid_i;
        IData/*31:0*/ __Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__Vfuncout;
        IData/*31:0*/ __Vfunc_top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__apb_slave_u__DOT__get_we_mask_from_strb__10__mask;
        VlWide<3>/*95:0*/ __VdfgRegularize_h6e95ff9d_0_3;
        VlWide<3>/*95:0*/ __VdfgRegularize_h6e95ff9d_0_4;
        VlWide<3>/*95:0*/ __VdfgRegularize_h6e95ff9d_0_5;
        VlWide<3>/*95:0*/ __VdfgRegularize_h6e95ff9d_0_6;
        IData/*31:0*/ __VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        IData/*31:0*/ __VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2;
        IData/*31:0*/ __VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        IData/*31:0*/ __VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2;
        IData/*31:0*/ __VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        IData/*31:0*/ __VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2;
        IData/*31:0*/ __VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v0;
        IData/*31:0*/ __VdlyVal__top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf__v2;
        IData/*31:0*/ __VdlyVal__top_env__DOT__ahb_fet_mem_u__DOT__mem__v0;
        IData/*31:0*/ __VactIterCount;
        IData/*31:0*/ __VinactIterCount;
        IData/*31:0*/ __Vi;
        QData/*48:0*/ top_env__DOT__apb_in;
        QData/*46:0*/ top_env__DOT__core_u__DOT__core_decoder_u__DOT__gen_debug_info__DOT__command;
        VlWide<3>/*66:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__alu_struct;
        VlWide<3>/*66:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__alu_struct;
        VlWide<3>/*66:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__alu_struct;
        VlWide<3>/*66:0*/ top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__alu_struct;
        VlUnpacked<IData/*31:0*/, 4> top_env__DOT__start__Vstatic__vid;
        VlUnpacked<IData/*31:0*/, 4> top_env__DOT__core_u__DOT__vid_arr;
        VlUnpacked<QData/*32:0*/, 4> top_env__DOT__core_u__DOT__rs1_arr;
        VlUnpacked<QData/*32:0*/, 4> top_env__DOT__core_u__DOT__rs2_arr;
        VlUnpacked<SData/*9:0*/, 4> top_env__DOT__core_u__DOT__thread_unit_info;
        VlUnpacked<CData/*1:0*/, 4> top_env__DOT__core_u__DOT__thread_states;
        VlUnpacked<CData/*0:0*/, 4> top_env__DOT__core_u__DOT__lsu_r2_thread;
        VlUnpacked<IData/*31:0*/, 8> top_env__DOT__core_u__DOT__core_fetcher_u__DOT__inst_q;
        VlUnpacked<IData/*31:0*/, 4> top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_rdata;
        VlUnpacked<IData/*31:0*/, 4> top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__vid_wedata;
        VlUnpacked<IData/*31:0*/, 32> top_env__DOT__core_u__DOT__gen_threads__BRA__0__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf;
        VlUnpacked<IData/*31:0*/, 32> top_env__DOT__core_u__DOT__gen_threads__BRA__1__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf;
        VlUnpacked<IData/*31:0*/, 32> top_env__DOT__core_u__DOT__gen_threads__BRA__2__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf;
        VlUnpacked<IData/*31:0*/, 32> top_env__DOT__core_u__DOT__gen_threads__BRA__3__KET____DOT__thread_unit_u__DOT__tu_regfile_u__DOT__rf;
        VlUnpacked<IData/*31:0*/, 65536> top_env__DOT__ahb_lsu_mem_u__DOT__mem;
        VlUnpacked<IData/*31:0*/, 65536> top_env__DOT__ahb_fet_mem_u__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VactTriggeredAcc;
        VlUnpacked<QData/*63:0*/, 2> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 17> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_ha024b98c__0;
    VlEvent __VnbaEvent;
    VlTriggerScheduler __VtrigSched_h8674f324__0;

    // INTERNAL VARIABLES
    Vtop_env__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop_env___024root(Vtop_env__Syms* symsp, const char* namep);
    ~Vtop_env___024root();
    VL_UNCOPYABLE(Vtop_env___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
