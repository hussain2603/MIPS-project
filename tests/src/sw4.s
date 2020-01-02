#sw4
#sw
#functionality test instr mem
#245
#aak718
#
#
lui $1, 0x1000
addi $3, $3, 5
sw $3, 4($1)
lw $2, 0($1)
jr $0
