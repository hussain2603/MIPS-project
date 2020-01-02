#beq1
#Beq
#basic functionality
#0
#hk2018
#
#
addi $3, $3, 0xffff
addi $4, $4, 0xffff
beq $3, $4, 0x0002
add $5, $1, $3
addi $2, $0, 0x0003
jr $0
