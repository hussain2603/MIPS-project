#lwr5
#Lwr
#dmem bottom boundary 
#3
#aak718
#
#
lui $1, 0x2000
addi $3, $3, 1002
sw $3, 0($1)
lwr $2, 2($1)
jr $0
