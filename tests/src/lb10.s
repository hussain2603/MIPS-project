#lb10
#Lb
#functionality to getc
#137
#hk2018
#AH
#
lui $3, 0x3000
lb $4, 3($3)
lb $5, 3($3)
add $2, $4, $5
jr $0
