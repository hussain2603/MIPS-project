
#ifndef J_type_hpp
#define J_type_hpp
#pragma once

#include <stdio.h>

#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <bitset>
#include "defined_constants.hpp"

int J(const uint32_t& instr_index, uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch);
int JAL(const uint32_t& instr_index, uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch, int32_t& return_address);

#endif /* J_type_hpp */
