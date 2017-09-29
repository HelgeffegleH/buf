#include "bytemacro.h"
unsigned int __cdecl byteFind(unsigned char* hay, unsigned char* ned, unsigned int haylen, unsigned int nedlen){
	// for byteFind(), compiled with gcc, -Ofast.
	unsigned int i=0;
	unsigned int j;
	unsigned int rem;
	if (nedlen>haylen)
		return 0xFFFFFFFF;
	haylen-=nedlen-1;
	switch (nedlen) {
		case 1: 	// buffer: 1 
			while (i<haylen) {
				if cmpByte1z(ned,hay,i)
					return i;
				++i;
			}
			break;
		case 2: // buffer: 2
			while (i<haylen) {
				if cmpByte2z(ned,hay,i)
					return i;
				++i;
			}
			break;
		case 3: // buffer: 3
			while (i<haylen) {
				if cmpByte3z(ned,hay,i)
					return i;
				++i;
			}
			break;
		case 4: // buffer: 4
			while (i<haylen) {
				if cmpByte4z(ned,hay,i)
					return i;
				++i;
			}			
			break;
		default: // buffer: 4+
			rem = nedlen % 4;
			if (rem == 0){
				do {
					if cmpByte4(ned,hay,0) {
						for (j=4; j<nedlen && cmpByte4(ned,hay,j); j=j+4);	
						if (j == nedlen)
							return i;
					}
					i++;
					++hay;
				} while (i<haylen);
			} else if (rem==1) {
				do {
					if cmpByte4(ned,hay,0){
						for (j=4; j<nedlen-1 && cmpByte4(ned,hay,j); j=j+4);
						if (j == nedlen-1 && hay[nedlen-1]==ned[nedlen-1]){
							return i;
						}
					}
					i++;
					++hay;
				} while (i<haylen); 
			} else if (rem==2) {
				do {
					if cmpByte4(ned,hay,0) {
						for (j=4; j<nedlen-2 && cmpByte4(ned,hay,j); j=j+4);
						if (j == nedlen-2 && hay[nedlen-2]==ned[nedlen-2] && hay[nedlen-1]==ned[nedlen-1]){
							return i;
						}
					}
					i++;
					++hay;
				} while (i<haylen);
			} else if (rem==3) {
				do {
					if cmpByte4(ned,hay,0){
						for (j=4; j<nedlen-3 && cmpByte4(ned,hay,j) ; j=j+4);
						if (j == nedlen-3 && hay[nedlen-3]==ned[nedlen-3] && hay[nedlen-2]==ned[nedlen-2] && hay[nedlen-1]==ned[nedlen-1]){
							return i;
						}
					}
					i++;
					++hay;
				} while (i<haylen);
			} 
			break;
	}	
	return 0xFFFFFFFF; // not found
}