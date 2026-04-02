# --------------------------------------------------------------
#  fpnew_bfm.py
# --------------------------------------------------------------
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, Timer, Combine, Event
from pyuvm import utility_classes    # ваш метакласс Singleton

from enum import Enum

class OpEnum(Enum):
    FMADD = 0       # op[0] * op[1] + op[2]
    FNMSUB = 1      # op[0] * op[1] - op[2]
    ADD = 2         # op[1] + op[2]
    MUL = 3         # op[0] * op[1]
    DIV = 4         # op[0] / op[1]
    SQRT = 5        # sqrt(op[0])
    SGNJ = 6        # (op[0] * sign(op[1])) * -1
    MINMAX = 7      # min
    CMP = 8     
    CLASSIFY = 9
    F2F = 10
    F2I = 11
    I2F = 12
    CPKAB = 13
    CPKCD = 14
    ADDS = 15

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
        await RisingEdge(self.clk)

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
        await RisingEdge(self.clk)

    async def drive_flush(self, flush: bool = True):
        """Устанавливает сигнал flush_i."""
        self.flush_i.value = int(flush)
        await RisingEdge(self.clk)

    async def drive_out_ready(self, ready: bool = True):
        """Сигнал готовности тест‑бенча принимать результат."""
        self.out_ready_i.value = int(ready)
        await RisingEdge(self.clk)

    # --------------------------------------------------------------
    #  Handshake‑in (in_valid / in_ready)
    # --------------------------------------------------------------
    async def wait_in_ready(self, timeout: int = 1000):
        """
        Ожидает, пока DUT подаст `in_ready_o == 1`.
        Если за `timeout` тактов ничего не пришло – падает.
        """
        for _ in range(timeout):
            if int(self.in_ready_o.value) == 1:
                return
            await RisingEdge(self.clk)
        assert False, "Timeout waiting for in_ready_o == 1"

    # --------------------------------------------------------------
    #  Handshake‑out (out_valid / out_ready)
    # --------------------------------------------------------------
    async def wait_out_valid(self, timeout: int = 1000):
        """
        Ожидает, пока DUT подаст `out_valid_o == 1`.
        При получении события ставит внутренний Event, чтобы
        монитор мог отреагировать.
        """
        for _ in range(timeout):
            if int(self.out_valid_o.value) == 1:
                self._out_event.set()
                return
            await RisingEdge(self.clk)
        assert False, "Timeout waiting for out_valid_o == 1"

    async def wait_handshake(self, timeout: int = 1000):
        """
        Полный «handshake» в обе стороны:
          1) Ждём, пока DUT готов принять вход (in_ready_o);
          2) Ждём, пока DUT выдаст результат (out_valid_o);
        """
        await self.wait_in_ready(timeout)
        await self.wait_out_valid(timeout)

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
    async def transaction(self,
                          operands,
                          op_code,
                          op_mod: int = 0,
                          rnd_mode: int = 0,
                          src_fmt: int = 0,
                          dst_fmt: int = 0,
                          int_fmt: int = 0,
                          vectorial: int = 0,
                          tag=None,
                          mask=None,
                          flush: bool = False,
                          out_ready: bool = True,
                          timeout: int = 1000):
        """
        Полный сценарий:
          1) Устанавливаем все входные поля.
          2) Ждём, пока DUT примет их (in_ready_o).
          3) Ждём, пока DUT выдаст результат (out_valid_o).
          4) Считываем и возвращаем результат.

        Возвращаемый словарь – то же, что и из `read_output()`.
        """
        # 1) Драйв всех входов
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
        await self.drive_flush(flush)
        await self.drive_out_ready(out_ready)

        # 2) Ждём handshake
        await self.wait_handshake(timeout)
        cocotb.log.debug(f"Handshake cptrure")

        # 3) Считываем результат
        return await self.read_output()

    # --------------------------------------------------------------
    #  Монитор – асинхронный процесс, который постоянно пишет
    #          изменения интересных сигналов в лог.
    # --------------------------------------------------------------
    async def monitor(self, interval: float = 0.0):
        """
        Запускается в тесте как:
            cocotb.start_soon(bfm.monitor())
        Если `interval` > 0, то вывод делается раз в `interval` сек,
        иначе – каждый тактовый фронт.
        """
        while True:
            # Печать только когда есть «значимый» выход (out_valid)
            if self.out_valid_o.value.integer:
                out = await self.read_output()
                cocotb.log.info(f"[MON] out_valid=1  result=0x{out['result']:0{self.WIDTH//4}X}  "
                                f"status=0x{out['status']:X}  tag={out['tag']}  "
                                f"busy={out['busy']}  early_valid={out['early_valid']}")
            if interval:
                await Timer(interval, units="ns")
            else:
                await RisingEdge(self.clk)