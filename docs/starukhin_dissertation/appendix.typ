#import "@preview/codelst:2.0.2": sourcecode

#show raw: set text(size: 9pt)

= Приложения

#align(center, [*Листинг файла base_pkg.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/utils/base_pkg.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла ahb_pkg.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/utils/ahb_pkg.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла ahb_master.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/utils/ahb_master.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла apb_pkg.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/utils/apb_pkg.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла apb_slave.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/utils/apb_slave.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла reg_if.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/interfaces/reg_if.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла tu_pkg.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/tu_pkg.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла handshake_fpu_pkg.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/handshake_fpu_pkg.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла tu_fpu_fsm.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/tu_fpu_fsm.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла tu_alu.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/tu_alu.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла tu_regfile.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/tu_regfile.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла thread_unit.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/thread_unit.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла decoder_pkg.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/decoder_pkg.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла core_decoder.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/core_decoder.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла core_fetcher.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/core_fetcher.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла core_arbiter.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/core_arbiter.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла core_lsu_fsm_pkg.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/core_lsu_fsm_pkg.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла core_lsu.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/core_lsu.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла prim_access_pkg.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/reg_common/prim_access_pkg.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла prim_bit.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/reg_common/prim_bit.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла prim_field.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/reg_common/prim_field.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла prim_register.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/reg_common/prim_register.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла core_regblk_pkg.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/reg_common/core_regblk_pkg.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла core_reg_structure_pkg.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/reg_common/core_reg_structure_pkg.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла core_csrm.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/reg_common/core_csrm.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла core_csrm_hndl.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/core_csrm_hndl.sv"))]
)

#pagebreak()

#align(center, [*Листинг файла core.sv*])
#figure(
  sourcecode(lang: "systemverilog")[#raw(read("../../hardware/rtl/core.sv"))]
)


// #figure(
//   sourcecode(lang: "python")[#raw(read("code/inresults.h"))]
//   , caption: [Листинг файла inresults.h]
// )

// = Приложение 2

// #figure(
//   sourcecode(lang: "python")[#raw(read("code/inresults.c"))]
//   , caption: [Листинг файла inresults.c]
// )

// = Приложение 3

// #figure(
//   sourcecode(lang: "python")[#raw(read("code/draw_pt_fetch_shade_pipeline.c"))]
//   , caption: [Листинг файла draw_pt_fetch_shade_pipeline.c]
// )