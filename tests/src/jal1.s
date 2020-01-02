#jal1
#Jal 
#functionality for return value
#9
#hk2018
#
#
addi $2, $0, 5
jal func
addi $2, $2, 1
addi $2, $2, 1
addi $2, $2, 1
jr $0
nop
func: addi $2, $2, 1
jr $31
