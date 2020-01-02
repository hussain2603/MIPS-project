#sh7
#sh
#functionality test out of data mem
#245
#hk2018
#
#
lui $1, 0x1100
addi $1, $1, 4
addi $3, $3, 65
sh $3, 2($1)
jr $0
