#lwl3
#Lwl
#getc top boundary
#65
#aak718
#A
#
lui $3, 0x3000
addi $3, $3, 3
lwl $2, 0($3)
srl $2, $2, 24
jr $0
