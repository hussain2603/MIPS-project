
#ifndef memory_hpp
#define memory_hpp

#include <stdio.h>
#include <iostream>
#include "defined_constants.hpp"


int dmem_to_index(uint32_t effective_address);
int index_to_dmem(uint32_t index);
int imem_to_index(uint32_t effective_address);
int32_t GetC();

#endif /* memory_hpp */
