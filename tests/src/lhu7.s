#lhu7
#Lhu
#functionality putc memory exception
#245
#hk2018
#
#
lui $3, 0x3000
addi $3, $3, 4
lhu $2, 2($3)
jr $0
