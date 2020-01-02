#sh8
#sh
#functionality test misaligned
#245
#hk2018
#
#
lui $1, 0x2000
addi $1, $1, 4
addi $3, $3, 5
sh $3, 1($1)
lw $2, 0($1)
jr $0
