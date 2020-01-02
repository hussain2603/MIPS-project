#sw7
#sw
#functionality test out of data mem
#245
#aak718
#
#
lui $1, 0x1100
addi $3, $3, 5
sw $3, 0($1)
lw $2, 0($1)
jr $0
