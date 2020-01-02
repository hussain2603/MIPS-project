#sb5
#Sb
#functionality writing to instr mem
#245
#hk2018
#
#
lui $1, 0x1000
addi $1, $1, 0
addi $3, $3, 5
sb $3, 2($1)
jr $0
