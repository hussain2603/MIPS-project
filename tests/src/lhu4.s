#lhu4
#Lhu
#Check zero extension
#1
#hk2018
#
#
lui $3, 0x2000
addi $1, $1, 0xffff
sw $1, 0($3)
lhu $2, 2($3)
srl $2, $2, 15
jr $0
