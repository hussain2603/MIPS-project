#sb1
#Sb
#functionality for data mem
#5
#hk2018
#
#
lui $1, 0x2000
addi $3, $3, 5
sb $3, 3($1)
lw $2, 0($1)
jr $0
