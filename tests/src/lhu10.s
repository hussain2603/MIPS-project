#lhu10
#lhu
#functionality get multiple loads
#137
#hk2018
#AH
#
lui $3, 0x3000
lhu $5, 2($3)
lhu $6, 2($3)
add $2, $5, $6
jr $0
