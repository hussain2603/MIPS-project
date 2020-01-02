#sw6
#sw
#functionality test putc
#0
#aak718
#
#H
lui $1, 0x3000
addi $1, $1, 4
addi $3, $3, 72
sw $3, 0($1)
jr $0
