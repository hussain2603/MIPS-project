#sw5
#sw
#functionality test getc
#245
#aak718
#
#
lui $1, 0x3000
addi $3, $3, 5
sw $3, 0($1)
lw $2, 0($1)
jr $0
