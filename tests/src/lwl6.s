#lwl6
#Lwl
#Top boundary dmem exception
#245
#aak718
#
#
lui $1, 0x2400
addi $3, $3, 1002
sw $3, 0($1)
lwl $4, 0($1)
srl $2, $4, 24
jr $0