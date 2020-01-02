#jalr4
#jalr
#functionality to test correct r31
#16
#hk2018
#
#
lui $1, 0x1000
addi $1, $1, 20
jalr $1
add $25, $2, $3
addi $4, $1, 3
addi $2, $0, 3
add $2, $0, $31
jr $0



