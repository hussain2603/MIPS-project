#sw1
#sw
#functionality test for data mem
#5
#aak718
#
#
lui $1, 0x2000
addi $1, $1, 4
addi $3, $3, 5
sw $3, 0($1)
lw $2, 0($1)
jr $0
