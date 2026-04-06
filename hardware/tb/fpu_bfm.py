# --------------------------------------------------------------
#  fpnew_bfm.py
# --------------------------------------------------------------
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, Timer, Combine, Event, ClockCycles
from pyuvm import utility_classes    # ваш метакласс Singleton

from fpu_item   import FPUItem

class FPUBfm(metaclass=utility_classes.Singleton):
    """
    Bus Functional Model для модуля fpnew_top.

    В конструкторе собираются все сигналы DUT, а также
    запоминаются параметры ширины данных и количества «LANE».
    """

    # --------------------------------------------------------------
    #  Конструктор
    # --------------------------------------------------------------
    def __init__(self,
                 dut,
                 clk_name: str = "clk_i",
                 rst_name: str = "rst_ni"):
        """
        Параметры
        ----------
        dut        – объект `cocotb.top` (или переданный в тесте `dut`);
        clk_name   – имя сигнала тактовой частоты (по умолчанию «clk_i»);
        rst_name   – имя сигнала активного‑low сброса (по умолчанию «rst_ni»).
        """
        self.dut = dut

        # ------------------  Тактовый/сбросовый  ------------------
        self.clk   = getattr(dut, clk_name)
        self.rst_n = getattr(dut, rst_name)

        # ------------------  Входные сигналы  --------------------
        self.operands_i     = dut.operands_i      # [NUM_OPERANDS][WIDTH]
        self.rnd_mode_i     = dut.rnd_mode_i
        self.op_i           = dut.op_i
        self.op_mod_i       = dut.op_mod_i
        self.src_fmt_i      = dut.src_fmt_i
        self.dst_fmt_i      = dut.dst_fmt_i
        self.int_fmt_i      = dut.int_fmt_i
        self.vectorial_op_i = dut.vectorial_op_i
        self.tag_i          = dut.tag_i
        self.simd_mask_i    = dut.simd_mask_i
        self.in_valid_i     = dut.in_valid_i
        self.flush_i        = dut.flush_i

        # ------------------  Handshake‑in  -----------------------
        self.in_ready_o = dut.in_ready_o     # output от DUT

        # ------------------  Выходные сигналы  ------------------
        self.result_o       = dut.result_o
        self.status_o       = dut.status_o
        self.tag_o          = dut.tag_o
        self.out_valid_o    = dut.out_valid_o
        self.busy_o         = dut.busy_o
        self.early_valid_o  = dut.early_valid_o

        # ------------------  Handshake‑out  --------------------
        self.out_ready_i = dut.out_ready_i

        # ------------------  Параметры ширины  -----------------
        # Поскольку параметры модуля недоступны из cocotb,
        # их удобно передавать вручную (или захватить один‑разово).
        # Мы будем пытаться «угадать» их по типу сигнала.
        self.WIDTH        = int(len(self.result_o))    # битность результата
        self.NUM_OPERANDS = int(len(self.operands_i) / len(self.result_o))  # количество операндов
        self.NUM_LANES    = int(len(self.simd_mask_i)) # lanes = ширина маски
        cocotb.log.debug(f"setup: {self.WIDTH}, {self.NUM_OPERANDS}, {self.NUM_LANES}")

        # ------------------  События/монитор  -----------------
        self._out_event = Event()   # будет ставиться, когда out_valid_o = 1

    # --------------------------------------------------------------
    #  СБРОС
    # --------------------------------------------------------------
    async def reset(self, cycles: int = 2):
        """
        Активный low‑reset на `cycles` тактов.
        После завершения гарантирует один «чистый» тактовый фронт.
        """
        self.rst_n.value = 0
        for _ in range(cycles):
            await RisingEdge(self.clk)
        self.rst_n.value = 1
        await RisingEdge(self.clk)

    # --------------------------------------------------------------
    #  Драйвер «idle» – все входы в 0 (кроме clk/rst)
    # --------------------------------------------------------------
    def drive_idle(self):
        """Устанавливает все входные сигналы в ноль (без await)."""
        self.operands_i.value     = 0
        self.rnd_mode_i.value     = 0
        self.op_i.value           = 0
        self.op_mod_i.value       = 0
        self.src_fmt_i.value      = 0
        self.dst_fmt_i.value      = 0
        self.int_fmt_i.value      = 0
        self.vectorial_op_i.value = 0
        self.tag_i.value          = 0
        self.simd_mask_i.value    = 0
        self.in_valid_i.value     = 0
        self.flush_i.value        = 0
        # handshakes
        self.in_ready_o.value     = 0
        self.out_ready_i.value    = 0

    # --------------------------------------------------------------
    #  Драйверы отдельных групп сигналов
    # --------------------------------------------------------------
    async def drive_operands(self, operand_list, valid: bool = True):
        """
        operand_list – список/кортеж длиной NUM_OPERANDS,
                       каждый элемент – int, помещающийся в WIDTH бит.
        """
        if len(operand_list) != self.NUM_OPERANDS:
            raise ValueError(f"operands list must contain {self.NUM_OPERANDS} elements")

        tmp_val = 0
        for i, val in enumerate(operand_list):
            # ограничиваем разрядность, если передали «слишком» большое число
            mask = (1 << self.WIDTH) - 1
            cocotb.log.debug(f"val: {val}; mask: {hex(mask)}; ({self.WIDTH * i})")
            tmp_val |= ((val & mask) << (self.WIDTH * i))
        self.operands_i.value = tmp_val
        self.in_valid_i.value = int(valid)

    async def drive_op(self,
                       op_code,
                       op_mod: int = 0,
                       rnd_mode: int = 0,
                       src_fmt: int = 0,
                       dst_fmt: int = 0,
                       int_fmt: int = 0,
                       vectorial: int = 0,
                       tag=None,
                       mask=None):
        """
        Одновременная установка всех «операционных» полей.
        `tag` и `mask` могут быть `None` → оставляем без изменения.
        """
        self.op_i.value           = op_code
        self.op_mod_i.value       = op_mod
        self.rnd_mode_i.value     = rnd_mode
        self.src_fmt_i.value      = src_fmt
        self.dst_fmt_i.value      = dst_fmt
        self.int_fmt_i.value      = int_fmt
        self.vectorial_op_i.value = vectorial
        if tag is not None:
            self.tag_i.value = tag
        if mask is not None:
            self.simd_mask_i.value = mask
        # await RisingEdge(self.clk)

    async def drive_op_by_item(self, item: FPUItem):
        self.op_i.value             = item._op_code.value
        self.op_mod_i.value         = item._op_mod.value
        self.rnd_mode_i.value       = item._rnd_mode.value
        self.src_fmt_i.value        = item._src_fmt.value
        self.dst_fmt_i.value        = item._dst_fmt.value
        self.int_fmt_i.value        = item._int_fmt.value
        self.vectorial_op_i.value   = item._vectorial_op_i.value
        self.tag_i.value            = item._tag.value
        self.simd_mask_i.value      = item._simd_mask_i.value

    async def drive_operands_by_item(self, item: FPUItem, valid: bool = True):
        if len(item._operands) != self.NUM_OPERANDS:
            raise ValueError(f"operands list must contain {self.NUM_OPERANDS} elements")
        tmp_val = 0
        for i, val in enumerate(item._operands):
            mask = (1 << self.WIDTH) - 1
            cocotb.log.debug(f"val: {val}; mask: {hex(mask)}; ({self.WIDTH * i})")
            tmp_val |= ((val & mask) << (self.WIDTH * i))
        self.operands_i.value = tmp_val
        self.in_valid_i.value = int(valid)

    async def drive_flush(self, flush: bool = True):
        """Устанавливает сигнал flush_i."""
        self.flush_i.value = int(flush)
        # await RisingEdge(self.clk)

    async def drive_out_ready(self, ready: bool = True):
        """Сигнал готовности тест‑бенча принимать результат."""
        self.out_ready_i.value = int(ready)
        #await RisingEdge(self.clk)

    # --------------------------------------------------------------
    #  Handshake‑in (in_valid / in_ready)
    # --------------------------------------------------------------
    async def wait_in_ready(self, timeout: int = 1000, tag: int = -1):
        """
        Ожидает, пока DUT подаст `in_ready_o == 1`.
        Если за `timeout` тактов ничего не пришло – падает.
        """
        for _ in range(timeout):
            if int(self.in_ready_o.value) == 1 \
                    and (tag == -1 or int(self.tag_i.value) == tag):
                return
            await RisingEdge(self.clk)
        assert False, f"Timeout waiting for in_ready_o == 1  with tag == {tag}"

    # --------------------------------------------------------------
    #  Handshake‑out (out_valid / out_ready)
    # --------------------------------------------------------------
    async def wait_out_valid(self, timeout: int = 1000, tag: int = 0):
        """
        Ожидает, пока DUT подаст `out_valid_o == 1`.
        При получении события ставит внутренний Event, чтобы
        монитор мог отреагировать.
        """
        for _ in range(timeout):
            await Timer(1, unit="ns")
            if int(self.out_valid_o.value) == 1 and int(self.tag_o.value) == tag:
                self._out_event.set()
                return
            await RisingEdge(self.clk)
        assert False, f"Timeout waiting for out_valid_o == 1 with tag == {tag}"


    # --------------------------------------------------------------
    #  Чтение выходных сигналов
    # --------------------------------------------------------------
    async def read_output(self):
        """
        Считывает все выходные сигналы в один словарь.
        Вызывается после того, как `out_valid_o` уже стал 1.
        """
        # Синхронный захват – гарантируем, что читаем в один такт
        # await RisingEdge(self.clk)

        out = {
            "result"       : int(self.result_o.value),
            "status"       : int(self.status_o.value),
            "tag"          : int(self.tag_o.value) if hasattr(self.tag_o, "value") else None,
            "out_valid"    : int(self.out_valid_o.value),
            "busy"         : int(self.busy_o.value),
            "early_valid"  : int(self.early_valid_o.value)
        }
        return out

    # --------------------------------------------------------------
    #  Композитный метод – одна транзакция «от начала до конца»
    # --------------------------------------------------------------
    async def wait_responce(self, tag: int =-1):
        cocotb.log.debug(f"Start capture responce with tag {tag}")
        await self.wait_out_valid(1000, tag)
        cocotb.log.debug(f"Handshake capture with tag {tag}")
        res = await self.read_output()
        self.out_ready_i.value = 1
        await RisingEdge(self.clk)
        self.out_ready_i.value = 0
        return res

    async def transaction(self,
                          operands,
                          op_code,
                          op_mod: int = 0,
                          rnd_mode: int = 0,
                          src_fmt: int = 0,
                          dst_fmt: int = 0,
                          int_fmt: int = 0,
                          vectorial: int = 0,
                          tag=0,
                          mask=None,
                          flush: bool = False,
                          out_ready: bool = True,
                          timeout: int = 1000):
        await self.drive_operands(operands, valid=True)
        await self.drive_op(op_code,
                            op_mod=op_mod,
                            rnd_mode=rnd_mode,
                            src_fmt=src_fmt,
                            dst_fmt=dst_fmt,
                            int_fmt=int_fmt,
                            vectorial=vectorial,
                            tag=tag,
                            mask=mask)
        response_task = cocotb.start_soon(self.wait_responce(tag))
        await RisingEdge(self.clk)
        await self.wait_in_ready(timeout)
        self.drive_idle()
        return response_task

    async def txn_by_item(self, item: FPUItem, timeout: int = 1000):
        await self.drive_operands_by_item(item)
        await self.drive_op_by_item(item)
        response_task = cocotb.start_soon(self.wait_responce(item._tag))
        await RisingEdge(self.clk)
        await self.wait_in_ready(timeout)
        self.drive_idle()
        return response_task

    async def send_txn(self, item: FPUItem, vectorial: int = 0):
        return await self.transaction(operands=item._operands,
                               op_code=item._op_code.value,
                               op_mod=item._op_mod,
                               rnd_mode=item._rnd_mode.value,
                               src_fmt=item._src_fmt.value,
                               dst_fmt=item._dst_fmt.value,
                               int_fmt=item._int_fmt.value,
                               tag = item._tag,
                               vectorial = vectorial,
                               mask = None,
                               flush = False,
                               out_ready = True,
                               timeout=1000)

    async def send_pack_txns(self,
                             item_l: list[FPUItem],
                             flush = False,
                             out_ready = True,
                             timeout: int = 1000
                             ):
        for item in item_l:
            await self.drive_operands(item._operands)
            await self.drive_op(item._op_code.value,
                            op_mod=item._op_mod,
                            rnd_mode=item._rnd_mode.value,
                            src_fmt=item._src_fmt.value,
                            dst_fmt=item._dst_fmt.value,
                            int_fmt=item._int_fmt.value,
                            vectorial=0,
                            tag=item._tag,
                            mask=None)


        await self.drive_flush(flush)
        await self.drive_out_ready(out_ready)

        # 2) Ждём handshake
        await self.wait_handshake(timeout, 0x01)
        cocotb.log.debug(f"Handshake cptrure")

        result = await self.read_output()
        # self.drive_idle()
        # 3) Считываем результат
        return result
