#bne1
#Bne
#functionality when not equal
#0
#hk2018
#
#
addi $3, $3, 0xfff0
addi $4, $4, 0xffff
bne $3, $4, 2
add $5, $1, $3
addi $2, $0, 3
jr $0
