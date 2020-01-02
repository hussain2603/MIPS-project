
#include "R_type.hpp"


int ADD(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    int32_t temp = sr1 + sr2;
    if(sr1 < 0 && sr2 < 0 && temp >= 0) {
        exit(ARITHMETIC_EXCEPTION);
    }
    else if(sr1 >= 0 && sr2 >= 0 && temp < 0) {
        exit(ARITHMETIC_EXCEPTION);
    }
    else {
        dr = temp;
        return 0;
    }
}

int ADDU(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    uint32_t sr1_ = sr1;
    uint32_t sr2_ = sr2;
    uint32_t dr_ = dr;
    dr_ = sr1_ + sr2_;
    dr = dr_;
    return 0;
}

int AND(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    dr = sr1 & sr2;
    return 0;
}

int SUB(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    int32_t temp = sr1 - sr2;
    if((sr1 >= 0) && (sr2 < 0) && (temp < 0)){
        exit(ARITHMETIC_EXCEPTION);
    }
    else if((sr1 < 0) && (sr2 >= 0) && (temp >= 0)){
        exit(ARITHMETIC_EXCEPTION);
    }
    else {
        dr = temp;
        return 0;
    }
}

int SUBU(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    uint32_t sr1_ = sr1;
    uint32_t sr2_ = sr2;
    uint32_t dr_ = dr;
    dr_ = sr1_ - sr2_;
    dr = dr_;
    return 0;
}

int XOR(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    dr = sr1 ^ sr2;
    return 0;
}

int DIV(const int32_t& sr1, const int32_t& sr2, int32_t& LO, int32_t& HI){
    if(sr2 != 0){
        LO = sr1 / sr2;
        HI = sr1 % sr2;
    }
    return 0;
}

int DIVU(const int32_t& sr1, const int32_t& sr2, int32_t& LO, int32_t& HI){
    uint32_t sr1_ = sr1;
    uint32_t sr2_ = sr2;
    uint32_t HI_ = HI;
    uint32_t LO_ = LO;
    if(sr2 != 0){
        LO_ = sr1_ / sr2_;
        HI_ = sr1_ % sr2_;
        HI = HI_;
        LO = LO_;
    }
    return 0;
}

int JR(const int32_t& sr, uint32_t& jump_PC, bool& is_branch){
        jump_PC = sr;
        is_branch = true;
        return 0;
}

int JALR(const int32_t& sr1, int32_t& dr, uint32_t& jump_PC, uint32_t& PC, bool& is_branch){
    dr = PC + 8;
   if(sr1 != dr) {
        jump_PC = sr1;
        is_branch = true;
    }
    return 0;
}

int MFHI(const int32_t& HI, int32_t& dr){
    dr = HI;
    return 0;
}

int MFLO(const int32_t& LO, int32_t& dr){
    dr = LO;
    return 0;
}

int MTHI(int32_t& HI, const int32_t& sr){
    HI = sr;
    return 0;
}

int MTLO(int32_t& LO, const int32_t& sr){
    LO = sr;
    return 0;
}

int MULT(const int32_t& sr1, const int32_t& sr2, int32_t& HI, int32_t& LO){
    int64_t sr1_ = sr1;
    int64_t sr2_ = sr2;
    int64_t result = sr1_ * sr2_;
    HI = result >> 32;
    LO = result & 0xFFFFFFFF;
    return 0;
}

int MULTU(const int32_t& sr1, const int32_t& sr2, int32_t& HI, int32_t& LO){
    uint32_t sr1_ = sr1;
    uint32_t sr2_ = sr2;
    uint32_t HI_ = HI;
    uint32_t LO_ = LO;
    uint64_t sr1_64 = sr1_;
    uint64_t sr2_64 = sr2_;
    uint64_t result = sr1_64 * sr2_64;
    HI_ = result >> 32;
    LO_ = result & 0xFFFFFFFF;
    HI = HI_;
    LO = LO_;
    return 0;
}

int OR(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    dr = sr1 | sr2;
    return 0;
}

int SLL(const int32_t& sr2, const uint32_t& sa, int32_t& dr){
    dr = sr2 << sa;
    return 0;
}

int SLLV(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    dr = sr2 << sr1;
    return 0;
}

int SLT(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    dr = (sr1 < sr2);
    return 0;
}

int SLTU(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    uint32_t sr1_ = sr1;
    uint32_t sr2_ = sr2;
    uint32_t dr_ = dr;
    dr_ = (sr1_ < sr2_);
    dr = dr_;
    return 0;
}

int SRA(const int32_t& sr2, const uint32_t& sa, int32_t& dr){
    dr = (sr2 >> sa);
    return 0;
}

int SRAV(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    dr = (sr2 >> sr1);
    return 0;
}

int SRL(const int32_t& sr2, const uint32_t& sa, int32_t& dr){
    uint32_t sr2_ = sr2;
    uint32_t dr_ = dr;
    dr_ = (sr2_ >> sa);
    dr = dr_;
    return 0;
}

int SRLV(const int32_t& sr1, const int32_t& sr2, int32_t& dr){
    uint32_t sr1_ = sr1;
    uint32_t sr2_ = sr2;
    uint32_t dr_ = dr;
    dr_ = (sr2_ >> sr1_);
    dr = dr_;
    return 0;
}

