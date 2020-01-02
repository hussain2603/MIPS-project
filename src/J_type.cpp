
#include "J_type.hpp"

int J(const uint32_t& instr_index, uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch){
    uint32_t upper_bits_index = NextPC & 0xF0000000;
    uint32_t instr_index_ = instr_index << 2; //shift left 2 bits
    
    jump_PC = instr_index_ + upper_bits_index;
    is_branch = true;
    return 0;
}

int JAL(const uint32_t& instr_index, uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch, int32_t& return_address){
    uint32_t upper_bits_index = NextPC & 0xF0000000;
    uint32_t instr_index_ = instr_index << 2; //shift left 2 bits
    
    jump_PC = instr_index_ + upper_bits_index;
    is_branch = true;
    
    return_address = NextPC + 4;
    
    return 0;
}
