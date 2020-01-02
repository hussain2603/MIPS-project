#lwl1
#Lwl
#Basic functionality dmem
#246
#aak718
#
#
lui $1, 0x2000
addi $3, $3, 2550
sw $3, 0($1)
lwl $4, 2($1)
srl $2, $4, 16
jr $0
