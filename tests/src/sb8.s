#sb8
#Sb
#functionality test in last memory of data mem
#5
#hk2018
#
#
addi $1, $1, 0x24
sll $1, $1, 24
addi $3, $3, 5
sb $3, -1($1)
lw $2, -4($1)
jr $0
