// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_ENV_H_
#define VERILATED_VTOP_ENV_H_  // guard

#include "verilated.h"
#include "svdpi.h"

class Vtop_env__Syms;
class Vtop_env___024root;
class VerilatedVcdC;
class Vtop_env_prim_register__FBz8_FCz7;
class Vtop_env_reg_if;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtop_env VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtop_env__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = true;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vtop_env_reg_if* const __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__3__KET__;
    Vtop_env_reg_if* const __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__2__KET__;
    Vtop_env_reg_if* const __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__1__KET__;
    Vtop_env_reg_if* const __PVT__top_env__DOT__core_u__DOT__rt_if__BRA__0__KET__;
    Vtop_env_reg_if* const __PVT__top_env__DOT__core_u__DOT__rl_if;
    Vtop_env_prim_register__FBz8_FCz7* const __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__pc_reg;
    Vtop_env_prim_register__FBz8_FCz7* const __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__0__KET____DOT__vid_reg;
    Vtop_env_prim_register__FBz8_FCz7* const __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__1__KET____DOT__vid_reg;
    Vtop_env_prim_register__FBz8_FCz7* const __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__2__KET____DOT__vid_reg;
    Vtop_env_prim_register__FBz8_FCz7* const __PVT__top_env__DOT__core_u__DOT__core_csrm_hndl_u__DOT__core_csrm_u__DOT__gen_vid_regs__BRA__3__KET____DOT__vid_reg;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtop_env___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtop_env(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtop_env(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtop_env();
  private:
    VL_UNCOPYABLE(Vtop_env);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); eval_end_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    /// DPI Export functions
    static svLogic is_done();
    static svLogic load_vertex_buffer_mem();
    static svLogic load_vertex_shader_mem();
    static int read_data_mem(int address);
    static int read_fetcher_mem(int address);
    static void start();
    static svLogic write_data_mem(int address, int data);
    static svLogic write_fetcher_mem(int address, int data);

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
