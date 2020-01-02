#jalr5
#jalr
#functionality to test branch delay slot
#3
#hk2018
#
#
lui $1, 0x1000
addi $1, $1, 16
jalr $1
addi $2, $0, 3
jr $0



