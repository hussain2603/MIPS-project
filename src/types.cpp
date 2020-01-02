
#include "types.hpp"


int check_Rtype(const uint32_t* information,
                int32_t* registers,
                int32_t& LO,
                int32_t& HI,
                uint32_t& PC,
                uint32_t& NextPC,
                uint32_t& jump_PC,
                bool& is_branch) {
    
    int32_t &dr = registers[information[3]];
    int32_t &sr1 = registers[information[1]];
    int32_t &sr2 = registers[information[2]];
    const uint32_t &shift_amt = information[4]; //aka hint
    uint32_t fnCode = information[5];

    
    switch(fnCode){
        case 32:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return ADD(sr1, sr2, dr);
            
        case 33:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return ADDU(sr1, sr2, dr);
            
        case 36:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return AND(sr1, sr2, dr);
            
        case 26:
            if((shift_amt != 0) || (dr != 0)) exit(INVALID_INSTRUCTION);
            return DIV(sr1, sr2, LO, HI);
            
        case 27:
            if((shift_amt != 0) || (dr != 0)) exit(INVALID_INSTRUCTION);
            return DIVU(sr1, sr2, LO, HI);
            
        case 9:
            if((sr2 != 0) || (shift_amt != 0)) exit(INVALID_INSTRUCTION);//hint preset to 0
            return JALR(sr1, dr, jump_PC, PC, is_branch);
            
        case 8:
            if((sr2 != 0) || (dr != 0) || (shift_amt != 0)) exit(INVALID_INSTRUCTION);//hint set to 0
            return JR(sr1, jump_PC, is_branch);
            
        case 16:
            if((shift_amt != 0) || (sr1 != 0) || (sr2 != 0)) exit(INVALID_INSTRUCTION);
            return MFHI(HI, dr);
            
        case 18:
            if((shift_amt != 0) || (sr1 != 0) || (sr2 != 0)) exit(INVALID_INSTRUCTION);
            return MFLO(LO, dr);
            
        case 17:
            if((shift_amt != 0) || (sr2 != 0) || (dr != 0)) exit(INVALID_INSTRUCTION);
            return MTHI(HI, sr1);
            
        case 19:
            if((shift_amt != 0) || (sr2 != 0) || (dr != 0)) exit(INVALID_INSTRUCTION);
            return MTLO(LO, sr1);
            
        case 24:
            if((shift_amt != 0) || (dr != 0)) exit(INVALID_INSTRUCTION);
            return MULT(sr1, sr2, HI, LO);
            
        case 25:
            if((shift_amt != 0) || (dr != 0)) exit(INVALID_INSTRUCTION);
            return MULTU(sr1, sr2, HI, LO);
            
        case 37:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return OR(sr1, sr2, dr);
            
        case 0:
            if(sr1 != 0) exit(INVALID_INSTRUCTION);
            return SLL(sr2, shift_amt, dr);
            
        case 4:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return SLLV(sr1, sr2, dr);
            
        case 42:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return SLT(sr1, sr2, dr);
            
        case 43:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return SLTU(sr1, sr2, dr);
            
        case 3:
            if(sr1 != 0) exit(INVALID_INSTRUCTION);
            return SRA(sr2, shift_amt, dr);
            
        case 7:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return SRAV(sr1, sr2, dr);
            
        case 2:
            if(sr1 != 0) exit(INVALID_INSTRUCTION);
            return SRL(sr2, shift_amt, dr);
            
        case 6:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return SRLV(sr1, sr2, dr);
            
        case 34:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return SUB(sr1, sr2, dr);
            
        case 35:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return SUBU(sr1, sr2, dr);
            
        case 38:
            if(shift_amt != 0) exit(INVALID_INSTRUCTION);
            return XOR(sr1, sr2, dr);
            
        default:
            exit(INTERNAL_ERROR);
        }
}


int check_Itype(const uint32_t* information,
                std::vector<uint8_t>& data_mem,
                const std::vector<uint32_t>& instr_mem,
                int32_t* registers,
                uint32_t& PC,
                uint32_t& NextPC,
                uint32_t& jump_PC,
                bool& is_branch){
    
    uint32_t opcode = information[0]; //unique
    int32_t &base = registers[information[1]]; //aka rs
    int32_t &rt = registers[information[2]];
    const int16_t &immediate_temp = information[3]; //16 bits
    const int32_t &immediate = immediate_temp; //sign extended
    const int32_t &special_case = information[2];
    int32_t &return_address = registers[31]; //for some branch instructions
    
    
    
    switch(opcode){
        case 0b00000000000000000000000000001000:
            return ADDI(base, immediate, rt);
            
        case 0b00000000000000000000000000001001:
            return ADDIU(base, immediate, rt);
            
        case 0b00000000000000000000000000001100:
            return ANDI(base, immediate, rt);
            
        case 0b00000000000000000000000000000100:
            return BEQ(base, immediate, rt, NextPC, jump_PC, is_branch);
            
        case 0b00000000000000000000000000000001:
            if(special_case == 1)
                return BGEZ(base, immediate, NextPC, jump_PC, is_branch);
            else if(special_case == 17) return BGEZAL(base, immediate, NextPC, jump_PC, is_branch, return_address); 
            else if(special_case == 0) return BLTZ(base, immediate, NextPC, jump_PC, is_branch);
            else if(special_case == 16) return BLTZAL(base, immediate, NextPC, jump_PC, is_branch, return_address);
            else exit(INTERNAL_ERROR);
            
        case 0b00000000000000000000000000000111:
            if(rt != 0) exit(INVALID_INSTRUCTION);
            return BGTZ(base, immediate, NextPC, jump_PC, is_branch);
            
        case 0b00000000000000000000000000000110:
            if(rt != 0) exit(INVALID_INSTRUCTION);
            return BLEZ(base, immediate, NextPC, jump_PC, is_branch);
            
        case 0b00000000000000000000000000000101:
            return BNE(base, immediate, rt, NextPC, jump_PC, is_branch);
            
        case 0b00000000000000000000000000100000:
            return LB(base, immediate, data_mem, instr_mem, rt);
            
        case 0b00000000000000000000000000100100:
            return LBU(base, immediate, data_mem, instr_mem, rt);
            
        case 0b00000000000000000000000000100001:
            return LH(base, immediate, data_mem, instr_mem, rt);
            
        case 0b00000000000000000000000000100101:
            return LHU(base, immediate, data_mem, instr_mem, rt);
            
        case 0b00000000000000000000000000001111:
            if(base != 0) exit(INVALID_INSTRUCTION);
            return LUI(immediate, rt);
            
        case 0b00000000000000000000000000100011:
            return LW(base, immediate, data_mem, instr_mem, rt);
            
        case 0b00000000000000000000000000100010:
            return LWL(base, immediate, data_mem, instr_mem, rt);
            
        case 0b00000000000000000000000000100110:
            return LWR(base, immediate, data_mem, instr_mem, rt);
            
        case 0b00000000000000000000000000001101:
            return ORI(base, immediate, rt);
            
        case 0b00000000000000000000000000101000:
            return SB(base, immediate, rt, data_mem);
            
        case 0b00000000000000000000000000101001:
            return SH(base, immediate, rt, data_mem);
            
        case 0b00000000000000000000000000001010:
            return SLTI(base, immediate, rt);
            
        case 0b00000000000000000000000000001011:
            return SLTIU(base, immediate, rt);
            
        case 0b00000000000000000000000000101011:
            return SW(base, immediate, rt, data_mem);
            
        case 0b00000000000000000000000000001110:
            return XORI(base, immediate, rt);
            
        default:
            exit(INTERNAL_ERROR);
    }
}

int check_Jtype(const uint32_t* information,
                int32_t* registers,
                uint32_t& PC,
                uint32_t& NextPC,
                uint32_t& jump_PC,
                bool& is_branch){
    
    uint32_t opcode = information[0]; //either 2 or 3
    const uint32_t &instr_index = information[1]; //memory address
    int32_t &return_address = registers[31];
    
    switch(opcode){
        case 2:
            return J(instr_index, NextPC, jump_PC, is_branch);
        case 3:
            return JAL(instr_index, NextPC, jump_PC, is_branch, return_address);
        default:
            exit(INTERNAL_ERROR);
    }
}

