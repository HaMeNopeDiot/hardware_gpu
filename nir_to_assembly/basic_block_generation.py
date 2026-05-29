from instruction import Instruction


class BasicBlockGenerator:
    class LiveInfo:
        def __init__(self, live: bool, next_use: int) -> None:
            self.live = live
            self.next_use = next_use

        def __repr__(self) -> str:
            return f"LiveInfo({self.live}, {self.next_use})"

    class RegisterInfo:
        def __init__(self, live: bool, next_use: int, stores: str) -> None:
            self.live = live
            self.next_use = next_use
            self.stores = stores

        def __repr__(self) -> str:
            return f"RegisterInfo({self.live}, {self.next_use}, {self.stores})"

    DEFAULT_LIVEINFO = LiveInfo(False, 0)
    DEFAULT_REGISTER_INFO = RegisterInfo(False, 0, "")

    def __init__(self) -> None:
        self.NUM_OF_REGISTERS = 32
        self.FIRST_GP_REGISTER = 3
        self.registers = [self.DEFAULT_REGISTER_INFO] * self.NUM_OF_REGISTERS
        self.registers[0] = self.RegisterInfo(True, 0, "zero")  # always zero
        self.registers[1] = self.RegisterInfo(True, 0, "v_id")  # contains vertex_id
        self.registers[2] = self.RegisterInfo(True, 0, "sp")  # contains stack pointer

        self.register_names = [f"x{i}" for i in range(self.NUM_OF_REGISTERS)]
        self.register_names[0] = "zero"
        self.register_names[1] = "v_id"
        self.register_names[2] = "sp"

        self.storage_memory = {}
        self.storage_stack = []
        self.storage_registers = {}

        self.target_code = []

    def _remove_register_association(self, ir_name: str, regnum: int) -> None:
        self.registers[regnum] = self.DEFAULT_REGISTER_INFO
        self.storage_registers.pop(ir_name, "None")

    def _add_register_association(
        self, ir_name: str, regnum: int, info: LiveInfo
    ) -> None:
        self.registers[regnum] = self.RegisterInfo(info.live, info.next_use, ir_name)
        self.storage_registers[ir_name] = regnum

    def _update_register_info(self, regnum: int, info: LiveInfo) -> None:
        self.registers[regnum].live = info.live
        self.registers[regnum].next_use = info.next_use

    def _find_register_space(self, dont_touch: set) -> int:
        most_not_needed = self.FIRST_GP_REGISTER
        for i in range(self.FIRST_GP_REGISTER, self.NUM_OF_REGISTERS):
            if i in dont_touch:
                continue
            elif not self.registers[i].live:
                most_not_needed = i
                break
            elif self.registers[i].next_use > self.registers[most_not_needed].next_use:
                most_not_needed = i

        return most_not_needed

    def _free_register(self, regnum: int) -> None:
        """
        The register is either already free or it contains some data, that we may or may not need to save
        """
        ir_name = self.registers[regnum].stores
        if not self.registers[regnum].live:
            self._remove_register_association(ir_name, regnum)
            return

        self._remove_register_association(ir_name, regnum)

        if ir_name in self.storage_memory:
            # the value is already available in the memory, no need to allocate space on the stack
            return

        for i in range(len(self.storage_stack)):
            if self.storage_stack[i] is None:
                self.storage_stack[i] = ir_name
                self.storage_memory[ir_name] = ["sp", str(4 * i)]
                self.target_code.append(
                    Instruction(
                        opcode="sw",
                        result="",
                        result_size=1,
                        args=[self.register_names[regnum], "sp", str(4 * i)],
                    )
                )

        self.storage_stack.append(ir_name)
        self.storage_memory[ir_name] = ["sp", str(4 * (len(self.storage_stack) - 1))]
        self.target_code.append(
            Instruction(
                opcode="sw",
                result="",
                result_size=1,
                args=[
                    self.register_names[regnum],
                    "sp",
                    str(4 * (len(self.storage_stack) - 1)),
                ],
            )
        )

    def _get_register_for(self, ir_name: str, dont_touch: set, info: LiveInfo) -> int:
        # if the value we need is loaded into the registers just return it
        if ir_name in self.storage_registers:
            regnum = self.storage_registers[ir_name]
            self._update_register_info(regnum, info)
            return regnum

        # if the value is not in the registers right now, we need to load it
        to_load = self._find_register_space(dont_touch)
        self._free_register(to_load)
        self._add_register_association(ir_name, to_load, info)
        if ir_name in self.storage_memory:
            # if its a value somewhere in the memory we just load it from there
            self.target_code.append(
                Instruction(
                    opcode="lw",
                    result=self.register_names[to_load],
                    result_size=1,
                    args=self.storage_memory[ir_name],
                )
            )
            return to_load

        return to_load

    def generate(self, ir: list[Instruction]) -> list[Instruction]:
        """
        No Live-variables at the end of the block
        We only care about sw instructions
        """
        self.__init__()
        info = self._determine_liveness(ir)

        # not a correct way to init the stack pointer, but i don't care
        self.target_code.append(
            Instruction(opcode="li", result="sp", result_size=1, args=["stack_base"])
        )
        self.target_code.append(
            Instruction(
                opcode="li",
                result=self.register_names[self.FIRST_GP_REGISTER],
                result_size=1,
                args=["stack_size"],
            )
        )
        self.target_code.append(
            Instruction(
                opcode="mul",
                result=self.register_names[self.FIRST_GP_REGISTER],
                result_size=1,
                args=[self.register_names[self.FIRST_GP_REGISTER], "v_id"],
            )
        )
        self.target_code.append(
            Instruction(
                opcode="add",
                result="sp",
                result_size=1,
                args=[self.register_names[self.FIRST_GP_REGISTER], "sp"],
            )
        )

        for i in range(len(ir)):
            dont_touch = set()
            args = []
            for arg in ir[i].args:
                if arg[0] == "t":
                    register = self._get_register_for(arg, dont_touch, info[i][arg])
                    args.append(self.register_names[register])
                    dont_touch.add(register)
                else:
                    args.append(arg)

            result = 0
            if ir[i].opcode != "sw" and ir[i].opcode != "ret":
                result = self._get_register_for(
                    ir[i].result, set(), info[i][ir[i].result]
                )
            if ir[i].opcode == "lw":
                is_absolute_link = True
                for arg in ir[i].args:
                    if arg[0] == "t":
                        is_absolute_link = False
                        break
                if is_absolute_link:
                    self.storage_memory[ir[i].result] = ir[i].args

            self.target_code.append(
                Instruction(
                    opcode=ir[i].opcode,
                    result=self.register_names[result],
                    result_size=1,
                    args=args,
                )
            )

        self.target_code.append(
            Instruction(
                opcode="ret",
                result="",
                result_size=1,
                args=[],
            )
        )

        return self.target_code

    def _determine_liveness(self, ir: list[Instruction]) -> list[dict]:
        info = []
        symbol_table: dict[str, BasicBlockGenerator.LiveInfo] = dict()
        for i in range(len(ir) - 1, -1, -1):
            instr_info = {}
            instr_info[ir[i].result] = symbol_table.get(
                ir[i].result, self.DEFAULT_LIVEINFO
            )
            symbol_table[ir[i].result] = self.DEFAULT_LIVEINFO
            for arg in ir[i].args:
                if arg[0] == "t":
                    instr_info[arg] = symbol_table.get(arg, self.DEFAULT_LIVEINFO)
                    symbol_table[arg] = self.LiveInfo(True, i)

            info.insert(0, instr_info)

        # for i in range(len(info)):
        #     print(f"{i:<4} {info[i]}")
        return info
