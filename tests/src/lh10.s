#lh10
#lh
#functionality get multiple loads
#137
#hk2018
#AH
#
lui $3, 0x3000
lh $5, 2($3)
lh $6, 2($3)
add $2, $5, $6
jr $0
