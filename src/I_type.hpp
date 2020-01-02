
#ifndef I_type_hpp
#define I_type_hpp
#pragma once

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <bitset>
#include "defined_constants.hpp"
#include "memory.hpp"


int ADDI(const int32_t& rs, const int32_t& immediate, int32_t& rt);
int ADDIU(const int32_t& rs, const int32_t& immediate, int32_t& rt);
int ANDI(const int32_t& rs, const int32_t& immediate, int32_t& rt);
int BEQ(const int32_t& rs, const int32_t& immediate, const int32_t& rt, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch);
int BGEZ(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch);
int BGEZAL(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch, int32_t& return_address);
int BGTZ(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch);
int BLEZ(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch);
int BLTZ(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch);
int BLTZAL(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch, int32_t& return_address);
int BNE(const int32_t& rs, const int32_t& immediate, const int32_t& rt, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch);
int LB(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt);
int LBU(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt);
int LH(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt);
int LHU(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt);
int LUI(const int32_t& immediate, int32_t& rt);
int LW(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt);
int LWL(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt);
int LWR(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt);
int ORI(const int32_t& rs, const int32_t& immediate, int32_t& rt);
int SB(const int32_t& base, const int32_t& offset, const int32_t& rt, std::vector<uint8_t>& data_mem);
int SH(const int32_t& base, const int32_t& offset, const int32_t& rt, std::vector<uint8_t>& data_mem);
int SLTI(const int32_t& base, const int32_t& immediate, int32_t& rt);
int SLTIU(const int32_t& base, const int32_t& immediate, int32_t& rt);
int SW(const int32_t& base, const int32_t& offset, const int32_t& rt, std::vector<uint8_t>& data_mem);
int XORI(const int32_t& base, const int32_t& immediate, int32_t& rt);


#endif /* I_type_hpp */
