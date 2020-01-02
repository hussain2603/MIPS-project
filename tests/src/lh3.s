#lh3
#lh
#fucntionality to check the correct half is loaded
#6
#hk2018
#
#
lui $3, 0x2000
addi $1, $1, 3
sb $1, 1($3)
sb $1, 3($3)
lh $4, 0($3)
lh $5, 2($3)
add $2, $4, $5
jr $0
