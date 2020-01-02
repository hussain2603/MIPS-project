#ifndef decode_hpp
#define decode_hpp

#pragma once
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <bitset>
#include "defined_constants.hpp"
#include "types.hpp"



void r_information (const uint32_t& full_instruction, uint32_t* information);
void i_information (const uint32_t& full_instruction, uint32_t* information);
void j_information (const uint32_t& full_instruction, uint32_t* information);
int find_instruction(const uint32_t& full_instruction, std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, uint32_t& opcode, uint32_t* information, uint32_t& PC, uint32_t& NextPC, int32_t& LO, int32_t& HI, uint32_t& jump_PC, bool& is_branch, int32_t* registers);


#endif /* decode_hpp */

