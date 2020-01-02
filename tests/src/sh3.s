#sh3
#sh
#functionality test instr mem
#245
#hk2018
#
#
lui $1, 0x1000
addi $3, $3, 12
sh $3, 2($1)
lw $2, 0($1)
jr $0
