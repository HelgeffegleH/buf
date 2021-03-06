﻿// compare shorts, o - offset.
#define cmpShort1(b1,b2,o) (b1[o] == b2[o])
#define cmpShort2(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1])
#define cmpShort3(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2])
#define cmpShort4(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2] && b1[o+3] == b2[o+3])
#define cmpShort5(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2] && b1[o+3] == b2[o+3] && b1[o+4] == b2[o+4])
#define cmpShort6(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2] && b1[o+3] == b2[o+3] && b1[o+4] == b2[o+4] && b1[o+5] == b2[o+5])
#define cmpShort7(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2] && b1[o+3] == b2[o+3] && b1[o+4] == b2[o+4] && b1[o+5] == b2[o+5] && b1[o+6] == b2[o+6])
#define cmpShort8(b1,b2,o) (b1[o] == b2[o] && b1[o+1] == b2[o+1] && b1[o+2] == b2[o+2] && b1[o+3] == b2[o+3] && b1[o+4] == b2[o+4] && b1[o+5] == b2[o+5] && b1[o+6] == b2[o+6] && b1[o+7] == b2[o+7])

// cmp shorts where ned offset (o) is zero.
#define cmpShort1z(b1,b2,o) (b1[0] == b2[o])
#define cmpShort2z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1])
#define cmpShort3z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2])
#define cmpShort4z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2] && b1[3] == b2[o+3])
#define cmpShort5z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2] && b1[3] == b2[o+3] && b1[4] == b2[4])
#define cmpShort6z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2] && b1[3] == b2[o+3] && b1[4] == b2[4] && b1[5] == b2[o+5])
#define cmpShort7z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2] && b1[3] == b2[o+3] && b1[4] == b2[4] && b1[5] == b2[o+5] && b1[6] == b2[o+6])
#define cmpShort8z(b1,b2,o) (b1[0] == b2[o] && b1[1] == b2[o+1] && b1[2] == b2[o+2] && b1[3] == b2[o+3] && b1[4] == b2[4] && b1[5] == b2[o+5] && b1[6] == b2[o+6] && b1[7] == b2[o+7])

// casting was slower, hence this uglyness
// This is redundant.