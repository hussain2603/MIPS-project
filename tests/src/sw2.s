#sw2
#sw
#functionality test for misaligned
#245
#aak718
#
#
lui $1, 0x2000
addi $1, $1, 4
addi $3, $3, 5
sw $3, 1($1)
lw $2, 0($1)
jr $0
