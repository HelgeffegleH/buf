// compare bytes, o - offset.
#define cmpByte1(b1,b2,o) (b1[o] == b2[o])
#define cmpByte2(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1])
#define cmpByte3(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2])
#define cmpByte4(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2] && b1[o+3] == b2[o+3])
#define cmpByte5(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2] && b1[o+3] == b2[o+3] && b1[o+4] == b2[o+4])
#define cmpByte6(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2] && b1[o+3] == b2[o+3] && b1[o+4] == b2[o+4] && b1[o+5] == b2[o+5])
#define cmpByte7(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2] && b1[o+3] == b2[o+3] && b1[o+4] == b2[o+4] && b1[o+5] == b2[o+5] && b1[o+6] == b2[o+6])
#define cmpByte8(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2] && b1[o+3] == b2[o+3] && b1[o+4] == b2[o+4] && b1[o+5] == b2[o+5] && b1[o+6] == b2[o+6] && b1[o+7] == b2[o+7])

// cmp bytes where ned offset (o) is zero.
#define cmpByte1z(b1,b2,o) (b1[0] == b2[o])
#define cmpByte2z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1])
#define cmpByte3z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2])
#define cmpByte4z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2] && b1[3] == b2[o+3])
#define cmpByte5z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2] && b1[3] == b2[o+3] && b1[4] == b2[4])
#define cmpByte6z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2] && b1[3] == b2[o+3] && b1[4] == b2[4] && b1[5] == b2[o+5])
#define cmpByte7z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2] && b1[3] == b2[o+3] && b1[4] == b2[4] && b1[5] == b2[o+5] && b1[6] == b2[o+6])
#define cmpByte8z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2] && b1[3] == b2[o+3] && b1[4] == b2[4] && b1[5] == b2[o+5] && b1[6] == b2[o+6] && b1[7] == b2[o+7])

// casting was slower, hence this uglyness
// This is redundant.