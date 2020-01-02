#lwl5
#Lwl
#dmem bottom boundary 
#234
#aak718
#
#
lui $1, 0x2000
addi $3, $3, 1002
sw $3, 0($1)
lwl $2, 0($1)
jr $0
