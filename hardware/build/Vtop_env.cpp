// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop_env__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtop_env::Vtop_env(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop_env__Syms(contextp(), _vcname__, this)}
    , __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__{vlSymsp->TOP.__PVT__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__}
    , __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__{vlSymsp->TOP.__PVT__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__}
    , __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__{vlSymsp->TOP.__PVT__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__}
    , __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__{vlSymsp->TOP.__PVT__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__}
    , __PVT__top_env__DOT__core_u__DOT__rl_if{vlSymsp->TOP.__PVT__top_env__DOT__core_u__DOT__rl_if}
    , __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg{vlSymsp->TOP.__PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg}
    , __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg{vlSymsp->TOP.__PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg}
    , __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg{vlSymsp->TOP.__PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg}
    , __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg{vlSymsp->TOP.__PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg}
    , __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg{vlSymsp->TOP.__PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtop_env::Vtop_env(const char* _vcname__)
    : Vtop_env(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop_env::~Vtop_env() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop_env___024root___eval_debug_assertions(Vtop_env___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_env___024root___eval_static(Vtop_env___024root* vlSelf);
void Vtop_env___024root___eval_initial(Vtop_env___024root* vlSelf);
void Vtop_env___024root___eval_settle(Vtop_env___024root* vlSelf);
void Vtop_env___024root___eval(Vtop_env___024root* vlSelf);

void Vtop_env::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_env::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop_env___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->clearTriggeredEvents();
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop_env___024root___eval_static(&(vlSymsp->TOP));
        Vtop_env___024root___eval_initial(&(vlSymsp->TOP));
        Vtop_env___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop_env___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vtop_env::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vtop_env::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vtop_env::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtop_env::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtop_env::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop_env___024root___eval_final(Vtop_env___024root* vlSelf);

VL_ATTR_COLD void Vtop_env::final() {
    contextp()->executingFinal(true);
    Vtop_env___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop_env::hierName() const { return vlSymsp->name(); }
const char* Vtop_env::modelName() const { return "Vtop_env"; }
unsigned Vtop_env::threads() const { return 1; }
void Vtop_env::prepareClone() const { contextp()->prepareClone(); }
void Vtop_env::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtop_env::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vtop_env___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtop_env___024root__trace_init_top(Vtop_env___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop_env___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_env___024root*>(voidSelf);
    Vtop_env__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop_env___024root__trace_decl_types(tracep);
    Vtop_env___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop_env___024root__trace_register(Vtop_env___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop_env::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtop_env::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 1102);
    Vtop_env___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
