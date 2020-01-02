#lhu3
#lhu
#fucntionality to check the correct half is loaded
#5
#hk2018
#
#
lui $3, 0x2000
addi $1, $1, 3
addi $6, $6, 2
sb $6, 1($3)
sb $1, 3($3)
lhu $4, 0($3)
lhu $5, 2($3)
add $2, $4, $5
jr $0
