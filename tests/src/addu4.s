#addu4
#Addu
#ignore overflow
#255
#hk2018
#
#
addi $1, $1, 1
sll $1, $1, 31
addi $3, $3, -1
addu $2, $3, $1
jr $0
