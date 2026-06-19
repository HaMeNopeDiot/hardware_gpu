# S-type (3/3)
- [x] SW        // `M[rs1 + imm] = rs2`
- [x] ADD       // `rd = rs1 + rs2`
- [x] MUL       // `rd = rs1 * rs2`

# L-type (2/2)
- [x] LW        // `rd = M[rs1 + imm]`
- [x] ADDI      // `rd = r1 + imm`

# U-type (1/2)
- [x] IMM       // `rd = rs1 << 20`
- [ ] RET       // `End of program`

# F-type (0/6)
- [x] FADD      // `rd = rs1 + rs2`
- [x] FMUL      // `rd = rs1 * rs2`
- [x] FDIV      // `rd = rs1 / rs2`
- [x] FSQRT     // `rd = sqrt(rs1)`
- [x] FNEG      // `rd = -rs1`                  // with RTZ
- [x] FMAX      // `rd = max(rs1, rs2)`


- [x] Проверка работы последовательных команд с задержкой