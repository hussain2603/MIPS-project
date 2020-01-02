#lw2
#lw
#misaligned offset
#245
#hk2018
#
#
lui $3, 0x2000
addi $1, $1, 112
sw $1, 0($3)
lw $2, 9($3)
jr $0