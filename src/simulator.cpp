#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "decode.hpp"
#include "defined_constants.hpp"


int main (int argc, char *argv[]){
    
    std::vector<uint32_t>instr_mem (IMEM_LENGTH,0); // empty vector of imem which loads instructions read from the binary
    std::vector<uint8_t> data_mem;
    data_mem.resize(DMEM_LENGTH);
    std::fill(data_mem.begin(), data_mem.end(), 0);
    
    uint32_t information[6] = {0}; //array to divide and store decoded instructions
    uint32_t full_instruction;
    
    int32_t registers[32] = {0}; // array of uint registers all set to zero
    uint32_t PC = IMEM_OFFSET; // set to start of imem
    uint32_t NextPC = IMEM_OFFSET + 4;  //declared for branch delays
    int32_t LO = 0; //special register
    int32_t HI = 0; //special register
    uint32_t jump_PC = 0; //for branch delays
    bool is_branch = false; //for branch delays
    
    std::ifstream file;
    char binary;
    std::string ins;
    uint32_t int_ins;
    uint32_t opcode;
    int count = 0;
    int index = 0;
    std::string line;
    
    file.open(argv[1]);
    
    if(!file.is_open()){
        exit(IO_ERROR);
    }
    else{
        
        while(!file.eof()){ //reads the binary file char by char
            while(file >> std::noskipws >> binary){ //reads the space character as well
                std::bitset<8> test(binary);
                ins += test.to_string();
                count++;
                if(count == 4){
                    count = 0;
                    int_ins = std::stoul(ins, nullptr, 2);
                    instr_mem[index] = int_ins;
                    ins = "";
                    index ++;
                }
            }
        }
    }
    
    uint32_t addr_instr = (PC - IMEM_OFFSET)/4; //gives the index of the imemory vector
    
    while(PC != 0){
        if(PC % 4 != 0){
            exit(MEMORY_EXCEPTION);
            
        }else if((PC<IMEM_OFFSET) || (PC > IMEM_OFFSET + IMEM_LENGTH)){
            exit(MEMORY_EXCEPTION); // if it is not in the right memory location
            
        }else if(PC<=IMEM_OFFSET + IMEM_LENGTH){
            full_instruction = instr_mem[addr_instr];
            find_instruction(full_instruction, data_mem, instr_mem, opcode, information, PC, NextPC, LO, HI, jump_PC, is_branch, registers);
            
            PC = NextPC; // increment PC to the next instruction
            NextPC = PC + 4;
            addr_instr = (PC - IMEM_OFFSET)/4;
            
            if(is_branch){
                NextPC = jump_PC; //moves PC to the branch instruction,
                //jump_PC wil be set by the branch/jump instructions
                is_branch = false;
            }
            registers[0] = 0;
            
        }else{
            exit(EOF_ERROR);
        }
    }
    std::exit(registers[2] & 0xFF);
}
