
#ifndef defined_constants_hpp
#define defined_constants_hpp

#include <vector>

#define IMEM_OFFSET 0x10000000
#define IMEM_LENGTH 0x400000 //length in words (0x1000000 in bytes)
#define DMEM_OFFSET 0x20000000
#define DMEM_LENGTH 0x4000000 //length in bytes
#define GETC_OFFSET 0x30000000 //length is 4 bytes
#define PUTC_OFFSET 0x30000004 //length is 4 bytes

#define ARITHMETIC_EXCEPTION -10
#define MEMORY_EXCEPTION -11
#define INVALID_INSTRUCTION -12
#define IO_ERROR -21
#define EOF_ERROR -1
#define INTERNAL_ERROR -20
#endif /* defined_constants_h */

