#lwl10
#Lwl
#Instr mem top boundary exception
#245
#aak718
#
#
xori $3, $0, 0xf
lui $3, 0x1100
lwl $2, 0($3)
jr $0