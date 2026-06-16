import struct
import numpy as np
def float_to_ieee754(n: int, bits=32) -> str:

    if bits == 8:
        # Minifloat: 1 бит знак, 4 бита экспонента, 3 бита мантисса
        # Bias = 7, диапазон экспоненты: -6 до +8
        return _float_to_minifloat8(n)
    elif bits == 16:
        # IEEE 754 Half Precision
        # Используем numpy для точного преобразования
        half = np.float16(n)
        # Получаем байты и конвертируем в int
        int_repr = int.from_bytes(half.tobytes(), byteorder='little')
        return bin(int_repr)[2:].zfill(16)
    elif bits == 32:
        # 'f' for float (32-bit), 'I' for unsigned int (32-bit)
        packed = struct.pack('!f', n)
        return bin(struct.unpack('!I', packed)[0])[2:].zfill(32)
    elif bits == 64:
        # 'd' for double (64-bit), 'Q' for unsigned long long (64-bit)
        packed = struct.pack('!d', n)
        return bin(struct.unpack('!Q', packed)[0])[2:].zfill(64)

def ieee754_to_float(hex_str, bits=32):
        # Убираем возможный префикс 0x
    hex_str = hex_str.replace('0x', '').replace('0X', '')
    binary_data = bytes.fromhex(hex_str)

    if bits == 8:
        # Minifloat: 1-4-3 формат
        int_val = int(hex_str, 16)
        return _minifloat8_to_float(int_val)
    elif bits == 16:
        # IEEE 754 Half Precision
        binary_data = bytes.fromhex(hex_str.zfill(4))
        # Используем numpy для точного преобразования
        # Конвертируем big-endian hex в little-endian для numpy
        int_val = int.from_bytes(binary_data, byteorder='big')
        return float(np.frombuffer(
            int_val.to_bytes(2, byteorder='little'),
            dtype=np.float16
        )[0])
    elif bits == 32:
        #print(f"DEBUG: binary_data = {binary_data}, type = {type(binary_data)}, len = {len(binary_data)}")
        return struct.unpack('!f', binary_data)[0]
    elif bits == 64:
        return struct.unpack('!d', binary_data)[0]

def float_to_i754(n: int, bits=32) -> int:
    out = float_to_ieee754(n, bits)
    # print(f"v: {n} with type {type(n)} --> {out} (bits: {bits})")
    return int(out, 2)

# Example: 10.75 in 32-bit IEEE 754
# print(float_to_ieee754(10.75, 32))
# Output: 01000001001011000000000000000000
def _float_to_minifloat8(n: float) -> str:
    """
    Конвертирует float в 8-bit minifloat (1-4-3 формат).
    Формат: 1 бит знак, 4 бита экспонента, 3 бита мантисса
    Bias = 7
    """
    # Обработка специальных случаев
    if n == 0:
        return '00000000'
    if n == float('inf'):
        return '01111000'  # +Inf
    if n == float('-inf'):
        return '11111000'  # -Inf
    if n != n:  # NaN check
        return '01111100'  # NaN

def _minifloat8_to_float(int_val: int) -> float:
    """
    Конвертирует 8-bit minifloat (1-4-3 формат) в float.
    Формат: 1 бит знак, 4 бита экспонента, 3 бита мантисса
    Bias = 7
    """
    # Извлекаем компоненты
    sign = (int_val >> 7) & 0x1
    exp = (int_val >> 3) & 0xF      # 4 бита экспоненты
    mant = int_val & 0x7            # 3 бита мантиссы

    bias = 7

    # Специальные случаи
    if exp == 0xF:  # Все биты экспоненты = 1
        if mant == 0:
            return float('-inf') if sign else float('inf')
        else:
            return float('nan')

    if exp == 0:  # Денормализованное число или ноль
        if mant == 0:
            return -0.0 if sign else 0.0
        # Денормализованное: (0.mant) * 2^(1-bias)
        value = (mant / 8.0) * (2 ** (1 - bias))
    else:
        # Нормализованное: (1.mant) * 2^(exp-bias)
        value = (1.0 + mant / 8.0) * (2 ** (exp - bias))

    return -value if sign else value
