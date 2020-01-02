#sb2
#Sb
#data mem last address
#245
#hk2018
#
#
addi $1, $1, 0x24
sll $1, $1, 24
addi $3, $3, 5
sb $3, 1($1)
lw $2, 0($1)
jr $0
