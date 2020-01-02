
#include "memory.hpp"

int dmem_to_index(uint32_t effective_address){
    return effective_address - DMEM_OFFSET; //index of dmem vector
}

int index_to_dmem(uint32_t index){
    return DMEM_OFFSET + index;
}

int imem_to_index(uint32_t effective_address){
    if(effective_address % 4 == 0) return (effective_address - IMEM_OFFSET) / 4;
    else {
        return (effective_address - IMEM_OFFSET - (effective_address % 4)) / 4;
    }
}

int32_t GetC(){
    int32_t input_char = std::getchar();
    if(input_char == EOF && input_char == std::cin.eof()) return -1;
    else return input_char;
}


