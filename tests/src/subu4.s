#subu4
#Subu
#ignore overflow
#12
#hk2018
#
#
lui $3, 0x4000
lui $1, 0x8000
subu $2, $3, $1
srl $2, $2, 28
jr $0