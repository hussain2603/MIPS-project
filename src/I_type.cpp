#include "I_type.hpp"
#include <vector>


int ADDI(const int32_t& rs, const int32_t& immediate, int32_t& rt){
    int result = rs + immediate;
    if(rs < 0 && immediate < 0 && result >= 0) {
        exit(ARITHMETIC_EXCEPTION);
    }
    else if(rs >= 0 && immediate >= 0 && result < 0) {
        exit(ARITHMETIC_EXCEPTION);
    }
    else {
        rt = result;
    }
    return 0;
}

int ADDIU(const int32_t& rs, const int32_t& immediate, int32_t& rt){
    rt = rs + immediate;
    return 0;
}

int ANDI(const int32_t& rs, const int32_t& immediate, int32_t& rt){
    int32_t u_immediate = immediate & 0x0000FFFF;
    rt = rs & u_immediate;
    return 0;
}

int BEQ(const int32_t& rs, const int32_t& immediate, const int32_t& rt, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch){
    int32_t immediate_ = immediate << 2;
    if(rs == rt){
        jump_PC = NextPC + immediate_;
        is_branch = true;
    }
    return 0;
}

int BGEZ(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch){
    int32_t immediate_ = immediate << 2;
    if(rs >= 0){
        jump_PC = NextPC + immediate_;
        is_branch = true;
    }
    return 0;
}

int BGEZAL(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch, int32_t& return_address){
    int32_t immediate_ = immediate << 2;
    return_address = NextPC + 4;
    if(rs >= 0) {
        jump_PC = NextPC + immediate_;
        is_branch = true;
    }
    return 0;
}

int BGTZ(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch){
    int32_t immediate_ = immediate << 2;
    if(rs > 0){
        jump_PC = NextPC + immediate_;
        is_branch = true;
    }
    return 0;
}

int BLEZ(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch){
    int32_t immediate_ = immediate << 2;
    if(rs <= 0){
        jump_PC = NextPC + immediate_;
        is_branch = true;
    }
    return 0;
}

int BLTZ(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch){
    int32_t immediate_ = immediate << 2;
    if(rs < 0){
        jump_PC = NextPC + immediate_;
        is_branch = true;
    }
    return 0;
}

int BLTZAL(const int32_t& rs, const int32_t& immediate, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch, int32_t& return_address){
    int32_t immediate_ = immediate << 2;
    return_address = NextPC + 4;
    if(rs < 0) {
        jump_PC = NextPC + immediate_;
        is_branch = true;
    }
    return 0;
}

int BNE(const int32_t& rs, const int32_t& immediate, const int32_t& rt, const uint32_t& NextPC, uint32_t& jump_PC, bool& is_branch){
    int32_t immediate_ = immediate << 2;
    if(rs != rt){
        jump_PC = NextPC + immediate_;
        is_branch = true;
    }
    return 0;
}

int LB(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt){
    
    int32_t effective_address = base + offset;
    int32_t byte_to_load = 0;
    int8_t byte =0;
    

    if(effective_address >= DMEM_OFFSET && effective_address < DMEM_OFFSET + DMEM_LENGTH){
        byte = data_mem[dmem_to_index(effective_address)];
        byte_to_load = byte;
    }
    
    else if(effective_address >= IMEM_OFFSET && effective_address < (IMEM_OFFSET + (IMEM_LENGTH*4))){
        if(effective_address % 4 == 0){
            byte_to_load = (instr_mem[imem_to_index(effective_address)] & 0xFF000000) >> 24;
        }
        else if(effective_address % 4 == 1){
            byte_to_load = (instr_mem[imem_to_index(effective_address)] & 0x00FF0000) >> 16;
        }
        else if(effective_address % 4 == 2){
            byte_to_load = (instr_mem[imem_to_index(effective_address)] & 0x0000FF00) >> 8;
        }
        else{
            byte_to_load = instr_mem[imem_to_index(effective_address)] & 0x000000FF;
        }
    }
    else if(effective_address == GETC_OFFSET + 3){
        byte = GetC();
        byte_to_load = byte;
    }
    
    else if(effective_address == GETC_OFFSET || effective_address == GETC_OFFSET + 1 || effective_address == GETC_OFFSET + 2){
        if(GetC() == EOF) byte_to_load = 0xFFFFFFFF;
        else byte_to_load = 0;
    }
        
    else exit(MEMORY_EXCEPTION); //out of range
    
    rt = byte_to_load;
    
    return 0;
}

int LBU(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt){
    
    int32_t effective_address = base + offset;
    uint8_t byte = 0;
    uint32_t byte_to_load = 0;
    
    if(effective_address >= DMEM_OFFSET && effective_address < DMEM_OFFSET + DMEM_LENGTH){
        byte = data_mem[dmem_to_index(effective_address)];
        byte_to_load = byte;
    }
    
    else if(effective_address >= IMEM_OFFSET && effective_address < (IMEM_OFFSET + (IMEM_LENGTH*4))){
        if(effective_address % 4 == 0){
            byte_to_load = (instr_mem[imem_to_index(effective_address)] & 0xFF000000) >> 24;
        }
        else if(effective_address % 4 == 1){
            byte_to_load = (instr_mem[imem_to_index(effective_address)] & 0x00FF0000) >> 16;
        }
        else if(effective_address % 4 == 2){
            byte_to_load = (instr_mem[imem_to_index(effective_address)] & 0x0000FF00) >> 8;
        }
        else{
            byte_to_load = instr_mem[imem_to_index(effective_address)] & 0x000000FF;
        }
    }
    else if(effective_address == GETC_OFFSET + 3){
        byte_to_load = GetC();
    }
    
    else if(effective_address == GETC_OFFSET || effective_address == GETC_OFFSET + 1 || effective_address == GETC_OFFSET + 2){
        if(GetC() == EOF){
            byte_to_load = 0xFFFFFFFF;
        }
        else byte_to_load = 0;
    }
    
    else exit(MEMORY_EXCEPTION); //out of range
    
    rt = byte_to_load & 0xFF;
    
    return 0;
}

int LH(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt){
    
    uint8_t byte1 = 0, byte2 = 0;
    int32_t effective_address = base + offset;
    int32_t halfword_to_load = 0;
    if(effective_address % 2 != 0) exit(MEMORY_EXCEPTION); //alignment
    else{
        if(effective_address >= DMEM_OFFSET && effective_address < DMEM_OFFSET + DMEM_LENGTH){
            byte1 = (data_mem[dmem_to_index(effective_address)]); //MSB
            byte2 = (data_mem[dmem_to_index(effective_address + 1)]); //2nd
            
            int16_t temp = ((static_cast<int16_t> (byte1) << 8) + byte2);
            halfword_to_load = temp;
        }
        
        else if(effective_address >= IMEM_OFFSET && effective_address < (IMEM_OFFSET + (IMEM_LENGTH*4))){
            if(effective_address % 4 == 0) {
                 halfword_to_load = (instr_mem[imem_to_index(effective_address)] & 0xFFFF0000) >> 16;
            }
            else halfword_to_load = instr_mem[imem_to_index(effective_address)] & 0x0000FFFF;
        }
        
        else if(effective_address == GETC_OFFSET){
            halfword_to_load = (GetC() & 0xFFFF0000) >> 16;
        }
        
        else if(effective_address == GETC_OFFSET + 2){
            halfword_to_load = GetC();
        }
        
        else exit(MEMORY_EXCEPTION); //out of range
    }
    
    rt = halfword_to_load;
    
    return 0;
}

int LHU(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt){
    
    uint32_t byte1 = 0, byte2 = 0;
    int32_t effective_address = base + offset;
    uint32_t halfword_to_load = 0;
    
    if(effective_address % 2 != 0) exit(MEMORY_EXCEPTION); //alignment
    else{
        if(effective_address >= DMEM_OFFSET && effective_address < DMEM_OFFSET + DMEM_LENGTH){
            byte1 = data_mem[dmem_to_index(effective_address)] << 8; //MSB
            byte2 = data_mem[dmem_to_index(effective_address + 1)]; //2nd
            halfword_to_load = byte1 + byte2;
        }
        
        else if(effective_address >= IMEM_OFFSET && effective_address < (IMEM_OFFSET + (IMEM_LENGTH*4))){
            if(effective_address % 4 == 0) {
                halfword_to_load = (instr_mem[imem_to_index(effective_address)] & 0xFFFF0000) >> 16;
            }
            else halfword_to_load = instr_mem[imem_to_index(effective_address)] & 0x0000FFFF;
        }
        
        else if(effective_address == GETC_OFFSET){
            halfword_to_load = (GetC() & 0xFFFF0000) >> 16;
        }
        
        else if(effective_address == GETC_OFFSET + 2){
            halfword_to_load = GetC();
        }
        
        else exit(MEMORY_EXCEPTION); //out of range
    }
    
    rt = halfword_to_load & 0xFFFF;
    
    return 0;
}

int LUI(const int32_t& immediate, int32_t& rt){
    rt = (immediate << 16) & 0xFFFF0000;
    return 0;
}

int LW(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt){
    int32_t byte1 = 0, byte2 = 0, byte3 = 0, byte4 = 0;
    int32_t effective_address = base + offset;
    int32_t word_to_load = 0;
    if(effective_address % 4 != 0) exit(MEMORY_EXCEPTION); //alignment
    else{
        if(effective_address >= DMEM_OFFSET && effective_address < DMEM_OFFSET + DMEM_LENGTH){
            byte1 = data_mem[dmem_to_index(effective_address)] << 24;
            byte2 = data_mem[dmem_to_index(effective_address + 1)] << 16;
            byte3 = data_mem[dmem_to_index(effective_address + 2)] << 8;
            byte4 = data_mem[dmem_to_index(effective_address + 3)];
            word_to_load = byte1 + byte2 + byte3 + byte4;
        }
        else if(effective_address >= IMEM_OFFSET && effective_address < (IMEM_OFFSET + (IMEM_LENGTH*4))){
            word_to_load = instr_mem[imem_to_index(effective_address)];
        }
        else if(effective_address == GETC_OFFSET){
            word_to_load = GetC();
        }
        else {
            exit(MEMORY_EXCEPTION);
        }//out of range
        rt = word_to_load;
    }
    return 0;
}

int LWL(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt){
    int32_t byte1 = 0, byte2 = 0, byte3 = 0, byte4 = 0;
    int32_t effective_address = base + offset;
    int32_t word_to_load = 0;

    if(effective_address >= DMEM_OFFSET && effective_address < DMEM_OFFSET + DMEM_LENGTH){
        switch(effective_address % 4){
            case 0:
                rt = rt & 0;
                byte1 = data_mem[dmem_to_index(effective_address)] << 24;
                byte2 = data_mem[dmem_to_index(effective_address + 1)] << 16;
                byte3 = data_mem[dmem_to_index(effective_address + 2)] << 8;
                byte4 = data_mem[dmem_to_index(effective_address + 3)];
                break;
            case 1:
                rt = rt & 0x000000FF;
                byte1 = data_mem[dmem_to_index(effective_address)] << 24;
                byte2 = data_mem[dmem_to_index(effective_address + 1)] << 16;
                byte3 = data_mem[dmem_to_index(effective_address + 2)] << 8;
                break;
            case 2:
                rt = rt & 0x0000FFFF;
                byte1 = data_mem[dmem_to_index(effective_address)] << 24;
                byte2 = data_mem[dmem_to_index(effective_address + 1)] << 16;
                break;
            case 3:
                rt = rt & 0x00FFFFFF;
                byte1 = data_mem[dmem_to_index(effective_address)]  << 24;
                break;
        }
        word_to_load = byte1 + byte2 + byte3 + byte4;
    }
    else if(effective_address >= IMEM_OFFSET && effective_address < (IMEM_OFFSET + (IMEM_LENGTH*4))){
        switch(effective_address % 4){
            case 0:
                rt = rt & 0;
                word_to_load = instr_mem[imem_to_index(effective_address)];
                break;
            case 1:
                rt = rt & 0x000000FF;
                word_to_load = (instr_mem[imem_to_index(effective_address)] & 0x00FFFFFF) << 8;
                break;
            case 2:
                rt = rt & 0x0000FFFF;
                word_to_load = (instr_mem[imem_to_index(effective_address)] & 0x0000FFFF) << 16;
                break;
            case 3:
                rt = rt & 0x00FFFFFF;
                word_to_load = (instr_mem[imem_to_index(effective_address)] & 0x000000FF) << 24;
                break;
        }
    }
    else if(effective_address >= GETC_OFFSET && effective_address < (GETC_OFFSET + 4)){
        word_to_load = GetC();
        switch(effective_address % 4){
            case 0:
                rt = rt & 0;
                break;
            case 1:
                rt = rt & 0x000000FF;
                word_to_load = word_to_load << 8;
                break;
            case 2:
                rt = rt & 0x0000FFFF;
                word_to_load = word_to_load << 16;
                break;
            case 3:
                rt = rt & 0x00FFFFFF;
                word_to_load = word_to_load << 24;
                break;
        }
    }
    else {
        exit(MEMORY_EXCEPTION);
    }//out of range
    
    rt += word_to_load;
    
    return 0;
}

int LWR(const int32_t& base, const int32_t& offset, const std::vector<uint8_t>& data_mem, const std::vector<uint32_t>& instr_mem, int32_t& rt){
    int32_t byte1 = 0, byte2 = 0, byte3 = 0, byte4 = 0;
    int32_t effective_address = base + offset;
    int32_t word_to_load = 0;

    if(effective_address >= DMEM_OFFSET && effective_address < DMEM_OFFSET + DMEM_LENGTH){
        switch(effective_address % 4){
            case 0:
                rt = rt & 0xFFFFFF00;
                byte1 = data_mem[dmem_to_index(effective_address)];
                break;
            case 1:
                rt = rt & 0xFFFF0000;
                byte1 = data_mem[dmem_to_index(effective_address)];
                byte2 = data_mem[dmem_to_index(effective_address - 1)] << 8;
                break;
            case 2:
                rt = rt & 0xFF000000;
                byte1 = data_mem[dmem_to_index(effective_address)];
                byte2 = data_mem[dmem_to_index(effective_address - 1)] << 8;
                byte3 = data_mem[dmem_to_index(effective_address - 2)] << 16;
                break;
            case 3:
                rt = rt & 0;
                byte1 = data_mem[dmem_to_index(effective_address)];
                byte2 = data_mem[dmem_to_index(effective_address - 1)] << 8;
                byte3 = data_mem[dmem_to_index(effective_address - 2)] << 16;
                byte4 = data_mem[dmem_to_index(effective_address - 3)] << 24;
                break;
        }
        word_to_load = byte1 + byte2 + byte3 + byte4;
    }
    else if(effective_address >= IMEM_OFFSET && effective_address < (IMEM_OFFSET + (IMEM_LENGTH*4))){
        switch(effective_address % 4){
            case 0:
                rt = rt & 0xFFFFFF00;
               word_to_load = instr_mem[imem_to_index(effective_address)] >> 24;
                break;
            case 1:
                rt = rt & 0xFFFF0000;
                word_to_load = instr_mem[imem_to_index(effective_address)] >> 16;
                break;
            case 2:
                rt = rt & 0xFF000000;
                word_to_load = instr_mem[imem_to_index(effective_address)] >> 8;
                break;
            case 3:
                rt = rt & 0;
                word_to_load = instr_mem[imem_to_index(effective_address)];
                break;
        }
    }
    else if(effective_address >= GETC_OFFSET && effective_address < (GETC_OFFSET + 4)){
        word_to_load = GetC();
        switch(effective_address % 4){
            case 0:
                rt = rt & 0xFFFFFF00;
                word_to_load = (word_to_load >> 24) & 0x000000FF;
                break;
            case 1:
                rt = rt & 0xFFFF0000;
                word_to_load = (word_to_load >> 16) & 0x0000FFFF;
                break;
            case 2:
                rt = rt & 0xFFFFFF00;
                word_to_load = (word_to_load >> 8) & 0x00FFFFFF;
                break;
            case 3:
                rt = rt & 0;
                break;
        }
    }
    else {
        exit(MEMORY_EXCEPTION);
    }//out of range
    rt += word_to_load;

    return 0;
}


int ORI(const int32_t& rs, const int32_t& immediate, int32_t& rt){
    int32_t u_immediate = immediate & 0x0000FFFF;
    rt = rs | u_immediate;
    return 0;
}

int SB(const int32_t& base, const int32_t& offset, const int32_t& rt, std::vector<uint8_t>& data_mem){
    
    int32_t effective_address = base + offset;
    int32_t byte_to_store = rt;
    
    if(effective_address >= DMEM_OFFSET && effective_address < DMEM_OFFSET + DMEM_LENGTH){
        data_mem[dmem_to_index(effective_address)] = (byte_to_store & 0x000000FF); //LSB
    }
    else if(effective_address == PUTC_OFFSET || effective_address  == PUTC_OFFSET + 1 || effective_address == PUTC_OFFSET + 2){
        std::putchar(0);
    }
    else if(effective_address == PUTC_OFFSET + 3){
        std::putchar(byte_to_store);
    }
    else exit(MEMORY_EXCEPTION); //out of range

    return 0;
}

int SH(const int32_t& base, const int32_t& offset, const int32_t& rt, std::vector<uint8_t>& data_mem){
    int32_t effective_address = base + offset;
    int32_t halfword_to_store = rt;
    int8_t byte1 = 0, byte2 = 0;
    
    if(effective_address % 2 != 0) exit(MEMORY_EXCEPTION); //alignment
    else{
        if(effective_address >= DMEM_OFFSET && effective_address < DMEM_OFFSET + DMEM_LENGTH){
            byte1 = ((halfword_to_store & 0x0000FF00) >> 8);
            byte2 = (halfword_to_store & 0x000000FF);
            data_mem[dmem_to_index(effective_address)] = byte1;
            data_mem[dmem_to_index(effective_address + 1)] = byte2;
        }
        else if(effective_address == PUTC_OFFSET){
            std::putchar((halfword_to_store & 0xFFFF0000) >> 16);
        }
        else if(effective_address == PUTC_OFFSET + 2){
            std::putchar(halfword_to_store);
        }
        else exit(MEMORY_EXCEPTION); //out of range
    }
    return 0;
}

int SLTI(const int32_t& base, const int32_t& immediate, int32_t& rt){
    rt = (base < immediate);
    return 0;
}

int SLTIU(const int32_t& base, const int32_t& immediate, int32_t& rt){
    uint32_t u_base = base;
    uint32_t u_rt = rt;
    u_rt = (u_base < immediate);
    rt = u_rt;
    return 0; 
}

int SW(const int32_t& base, const int32_t& offset, const int32_t& rt, std::vector<uint8_t>& data_mem){
    int32_t effective_address = base + offset;
    int32_t word_to_store = rt;
    
    if(effective_address % 4 != 0) exit(MEMORY_EXCEPTION); //alignment
    else{
        if(effective_address >= DMEM_OFFSET && effective_address < DMEM_OFFSET + DMEM_LENGTH){
            data_mem[dmem_to_index(effective_address)] = (int8_t)((word_to_store & 0xFF000000) >> 24); //MSB
            data_mem[dmem_to_index(effective_address + 1)] = (int8_t)((word_to_store & 0x00FF0000) >> 16); //2nd
            data_mem[dmem_to_index(effective_address + 2)] = (int8_t)((word_to_store & 0x0000FF00) >> 8); //3rd
            data_mem[dmem_to_index(effective_address + 3)] = (int8_t)((word_to_store & 0x000000FF)); //LSB
        }
        else if(effective_address == PUTC_OFFSET){
            std::putchar(word_to_store);
        }
        else exit(MEMORY_EXCEPTION); //out of range
    }
    return 0;
}

int XORI(const int32_t& base, const int32_t& immediate, int32_t& rt){
    int32_t u_immediate = immediate & 0x0000FFFF;
    rt = base ^ u_immediate;
    return 0;
}
