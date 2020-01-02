#lbu11
#lbu
#functionality to check getc with 2 inputs
#137
#hk2018
#AH
#
lui $3, 0x3000
lbu $4, 3($3)
lbu $5, 3($3)
add $2, $4, $5
jr $0
