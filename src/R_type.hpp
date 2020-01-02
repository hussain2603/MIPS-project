
#ifndef R_type_hpp
#define R_type_hpp
#pragma once

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <bitset>
#include "defined_constants.hpp"


int ADD(const int32_t& sr1, const int32_t& sr2, int32_t& dr);
int ADDU(const int32_t& sr1, const int32_t& sr2, int32_t& dr);
int AND(const int32_t& sr1, const int32_t& sr2, int32_t& dr);
int DIV(const int32_t& sr1, const int32_t& sr2, int32_t& LO, int32_t& HI);
int DIVU(const int32_t& sr1, const int32_t& sr2, int32_t& LO, int32_t& HI);
int JALR(const int32_t& sr1, int32_t& dr, uint32_t& jump_PC, uint32_t& PC, bool& is_branch);
int JR(const int32_t& sr, uint32_t& jump_PC, bool& is_branch);
int MFHI(const int32_t& HI, int32_t& dr);
int MFLO(const int32_t& LO, int32_t& dr);
int MTHI(int32_t& HI, const int32_t& sr);
int MTLO(int32_t& LO, const int32_t& sr);
int MULT(const int32_t& sr1, const int32_t& sr2, int32_t& HI, int32_t& LO);
int MULTU(const int32_t& sr1, const int32_t& sr2, int32_t& HI, int32_t& LO);
int OR(const int32_t& sr1, const int32_t& sr2, int32_t& dr);
int SLL(const int32_t& sr2, const uint32_t& sa, int32_t& dr);
int SLLV(const int32_t& sr1, const int32_t& sr2, int32_t& dr);
int SLT(const int32_t& sr1, const int32_t& sr2, int32_t& dr);
int SLTU(const int32_t& sr1, const int32_t& sr2, int32_t& dr);
int SRA(const int32_t& sr2, const uint32_t& sa, int32_t& dr);
int SRAV(const int32_t& sr1, const int32_t& sr2, int32_t& dr);
int SRL(const int32_t& sr2, const uint32_t& sa, int32_t& dr);
int SRLV(const int32_t& sr1, const int32_t& sr2, int32_t& dr);
int SUB(const int32_t& sr1, const int32_t& sr2, int32_t& dr);
int SUBU(const int32_t& sr1, const int32_t& sr2, int32_t& dr);
int XOR(const int32_t& sr1, const int32_t& sr2, int32_t& dr);

#endif /*R_type_hpp */
