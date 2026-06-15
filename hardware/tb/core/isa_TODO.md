# S-type (1/3)
- [ ] SW        // `M[rs1 + imm] = rs2`
- [x] ADD       // `rd = rs1 + rs2`
- [ ] MUL       // `rd = rs1 * rs2`

# L-type (2/2)
- [x] LW        // `rd = M[rs1 + imm]`
- [x] ADDI      // `rd = r1 + imm`

# U-type (1/2)
- [x] IMM       // `rd = rs1 << 20`
- [ ] RET       // `End of program`

# F-type (0/6)
- [ ] FADD      // `rd = rs1 + rs2`
- [ ] FMUL      // `rd = rs1 * rs2`
- [ ] FDIV      // `rd = rs1 / rs2`
- [ ] FSQRT     // `rd = sqrt(rs1)`
- [ ] FNEG      // `rd = -rs1`
- [ ] FMAX      // `rd = max(rs1, rs2)`


- [ ] Проверка работы последовательных команд с задержкой