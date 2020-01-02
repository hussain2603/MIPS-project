#lwr1
#Lwr
#Basic functionality dmem
#9
#aak718
#
#
lui $1, 0x2000
addi $3, $3, 2550
sw $3, 0($1)
lwr $2, 2($1)
jr $0