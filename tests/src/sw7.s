#sw7
#sw
#functionality test null mem
#245
#aak718
#
#
addi $3, $3, 72
sw $3, 0($1)
lw $2, 0($1)
jr $0
