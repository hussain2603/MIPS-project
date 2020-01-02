#include "decode.hpp"


void r_information (const uint32_t& full_instruction, uint32_t* information){
    information[0] = (full_instruction >> 26) & 0x3f; //opcode
    information[1] = (full_instruction >> 21) & 0x1f; //sr1
    information[2] = (full_instruction >> 16) & 0x1f; //sr2
    information[3] = (full_instruction >> 11) & 0x1f; //dest
    information[4] = (full_instruction >> 6) & 0x1f; //shift amt
    information[5] = full_instruction & 0x3f; //fncode
}


void i_information (const uint32_t& full_instruction, uint32_t* information){
    information[0] = (full_instruction >> 26) & 0x3f; //opcode
    information[1] = (full_instruction >> 21) & 0x1f; //sr1 or base
    information[2] = (full_instruction >> 16) & 0x1f; //sr2 or rt
    information[3] = (full_instruction  & 0xffff); //offset or immediate
}

void j_information (const uint32_t& full_instruction, uint32_t* information){
    information[0] = (full_instruction >> 26) & 0x3f; //opcode
    information[1] = (full_instruction & 0x3ffffff); //memory address
}


int find_instruction(const uint32_t& full_instruction, std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, uint32_t& opcode, uint32_t* information, uint32_t& PC, uint32_t& NextPC, int32_t& LO, int32_t& HI, uint32_t& jump_PC, bool& is_branch, int32_t* registers){
    opcode = ((full_instruction >> 26 ) & 0x3f);
    
    if(opcode == 0){
        r_information (full_instruction,information);
        return check_Rtype(information, registers, LO, HI, PC, NextPC, jump_PC, is_branch);
    }
    else if ((opcode == 2) || (opcode == 3)){
        j_information (full_instruction, information);
        return check_Jtype(information, registers, PC, NextPC, jump_PC, is_branch);
    }
    else{
        i_information (full_instruction, information);
        return check_Itype(information, data_mem, instr_mem, registers, PC, NextPC, jump_PC, is_branch);
    }
    return(INVALID_INSTRUCTION); //if it doesnt match any of the other types
}

