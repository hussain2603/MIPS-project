
#ifndef types_hpp
#define types_hpp
 /* types_hpp */

#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "R_type.hpp"
#include "I_type.hpp"
#include "J_type.hpp"
#include "defined_constants.hpp"

int check_Rtype(const uint32_t* information,
                int32_t* registers,
                int32_t& LO,
                int32_t& HI,
                uint32_t& PC,
                uint32_t& NextPC,
                uint32_t& jump_PC,
                bool& is_branch);

int check_Itype(const uint32_t* information,
                 std::vector<uint8_t>& data_mem,
                const std::vector<uint32_t>& instr_mem,
                int32_t* registers,
                uint32_t& PC,
                uint32_t& NextPC,
                uint32_t& jump_PC,
                bool& is_branch);

int check_Jtype(const uint32_t* information,
                int32_t* registers,
                uint32_t& PC,
                uint32_t& NextPC,
                uint32_t& jump_PC,
                bool& is_branch);

#endif
