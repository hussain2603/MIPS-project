#lw10
#lw
#functionality top boundary
#112
#hk2018
#
#
lui $3, 0x2400
addi $1, $1, 112
sw $1, -4($3)
lw $2, -4($3)
jr $0