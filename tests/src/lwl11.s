#lwl11
#Lwl
#Data mem top boundary
#92
#aak718
#
#
lui $3, 0x2400
addi $3, $3, -4
addi $5, $5, 92
sw $5, 0($3)
lwl $2, 0($3)
jr $0