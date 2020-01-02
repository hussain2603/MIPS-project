#lbu3
#lbu
#functionality with negative number
#255
#hk2018
#
#
lui $3, 0x2000
addi $1, $1, 0xffff
sw $1, 0($3)
lbu $2, 3($3)
jr $0
