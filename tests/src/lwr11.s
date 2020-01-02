#lwr11
#Lwr
#Dmem top boundary
#170
#aak718
#
#
lui $3, 0x2400
addi $3, $3, -4
lui $5, 0xaaaa
sw $5, 0($3)
lwr $2, 1($3)
jr $0