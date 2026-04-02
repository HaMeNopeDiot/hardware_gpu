import struct

def float_to_ieee754(n: int, bits=32) -> str:
    if bits == 32:
        # 'f' for float (32-bit), 'I' for unsigned int (32-bit)
        packed = struct.pack('!f', n)
        return bin(struct.unpack('!I', packed)[0])[2:].zfill(32)
    elif bits == 64:
        # 'd' for double (64-bit), 'Q' for unsigned long long (64-bit)
        packed = struct.pack('!d', n)
        return bin(struct.unpack('!Q', packed)[0])[2:].zfill(64)

def ieee754_to_float(hex_str, bits=32):
    binary_data = bytes.fromhex(hex_str)
    if bits == 32:
        return struct.unpack('!f', binary_data)[0]
    elif bits == 64:
        return struct.unpack('!d', binary_data)[0]

def float_to_i754(n: int, bits=32) -> int:
    return int(float_to_ieee754(n, bits), 2)

# Example: 10.75 in 32-bit IEEE 754
# print(float_to_ieee754(10.75, 32))
# Output: 01000001001011000000000000000000