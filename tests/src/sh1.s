#sh1
#sh
#functionality test 
#5
#hk2018
#
#
lui $1, 0x2000
addi $3, $3, 5
sh $3, 2($1)
lw $2, 0($1)
jr $0
