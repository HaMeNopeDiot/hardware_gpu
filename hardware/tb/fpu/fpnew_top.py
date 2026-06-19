# test_my_design.py (simple)

import cocotb
from cocotb.triggers import Timer, ClockCycles

from fpu.fpu_bfm import FPUBfm
from fpu.fppconverter import ieee754_to_float
from fpu.fpu_item import FPUItem, FpFormatE, IntFormatE, OperationE

from numbers import Real
from decimal import Decimal


def print_result(result):
    cocotb.log.info(result)
    res = hex(result["result"])
    if result["result"] != 0:
        if len(res) - 2 < 16:
            res = "0x" + (16 + 2 - len(res)) * "0" + res[2:]
        cocotb.log.info(f"TRY TO SEND HEX: {res}")
        cocotb.log.info(f"RESULT: {(ieee754_to_float(res[2:], 64))}")


async def clock_generator(clk, time: Real | Decimal, unit: str = "step"):
    while True:
        clk.value = 0
        await Timer(time, unit)
        clk.value = 1
        await Timer(time, unit)

async def fpu_test(dut):
    """Try accessing the design."""
    clk = dut.clk_i
    rst_n = dut.rst_ni
    cocotb.start_soon(clock_generator(clk, 10, unit="ns"))

    rst_n.value = 1
    await ClockCycles(clk, 1)
    rst_n.value = 0
    await ClockCycles(clk, 1)
    rst_n.value = 1


    fpu_bfm = FPUBfm(dut)
    fpu_bfm.drive_idle()


    main_op = OperationE.DIV
    fpu_item1 = FPUItem(operands=[3, 7, -3],
                       op_code=main_op,
                       src_fmt=FpFormatE.FP64,
                       dst_fmt=FpFormatE.FP64,
                       int_fmt=IntFormatE.INT64,
                       tag=0x1)

    fpu_item2 = FPUItem(operands=[6, -1, 8],
                   op_code=main_op,
                   src_fmt=FpFormatE.FP64,
                   dst_fmt=FpFormatE.FP64,
                   int_fmt=IntFormatE.INT64,
                   tag=0x2)

    fpu_item3 = FPUItem(operands=[0.5, 4, 12],
               op_code=main_op,
               src_fmt=FpFormatE.FP64,
               dst_fmt=FpFormatE.FP64,
               int_fmt=IntFormatE.INT64,
               tag=0x3)

    fpu_item4 = FPUItem(operands=[0.5, 3, 8],
               op_code=main_op,
               src_fmt=FpFormatE.FP64,
               dst_fmt=FpFormatE.FP64,
               int_fmt=IntFormatE.INT64,
               tag=0x4)

    # await fpu_bfm.drive_operands(operands)
    respond_task_1 = await fpu_bfm.txn_by_item(fpu_item1)
    respond_task_2 = await fpu_bfm.txn_by_item(fpu_item2)
    respond_task_3 = await fpu_bfm.txn_by_item(fpu_item3)
    respond_task_4 = await fpu_bfm.txn_by_item(fpu_item4)

    await Timer(1000, unit="ns")
    print_result(await respond_task_1)
    print_result(await respond_task_2)
    print_result(await respond_task_3)
    print_result(await respond_task_4)

    await Timer(2000, unit="ns")

    fpu_item0 = FPUItem(operands=[1, 2, 3],
           op_code=OperationE.MUL,
           src_fmt=FpFormatE.FP16,
           dst_fmt=FpFormatE.FP16,
           int_fmt=IntFormatE.INT16,
           tag=0x1)
    fpu_item0._vectorial_op_i = 1
    fpu_item0.vectoral_operands_pack([5, 7, 8, 10], [10, 4, 2, 1], [12, 3, 7, 1])
    respond_task_5 = await fpu_bfm.txn_by_item(fpu_item0)

    print(f"HEX RS: {hex((await respond_task_5)["result"])}")

    for e in fpu_item0._operands:
        print(f"HEX OP: {hex(e)}")