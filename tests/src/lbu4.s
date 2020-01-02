#lbu4
#lbu
#functionality with negative number to see 0 extension
#15
#hk2018
#
#
lui $3, 0x2000
addi $1, $1, 0xff0f
sw $1, 0($3)
lbu $2, 3($3)
jr $0
