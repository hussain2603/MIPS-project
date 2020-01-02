#lwr10
#Lwr
#Instr mem top boundary exception
#245
#aak718
#
#
xori $3, $0, 0xf
lui $3, 0x1100
lwr $2, 3($3)
jr $0