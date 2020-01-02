#lh4
#lh
#fucntionality to check sign extension
#255
#hk2018
#
#
lui $3, 0x2000
addi $1, $1, 0xffff
sw $1, 0($3)
lh $2, 2($3)
srl $2, $2, 18
jr $0
