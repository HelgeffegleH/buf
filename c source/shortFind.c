// Modified version of bufFind.c
#include "shortmacro.h"
unsigned int __cdecl shortFind(unsigned short* hay, unsigned short* ned, unsigned int haylen, unsigned int nedlen){
	// for shortFind(), compiled with gcc, -Ofast.
	unsigned int i=0;
	unsigned int j;
	unsigned int rem;
	if (nedlen>haylen)
		return 0xFFFFFFFF;
	haylen-=nedlen-1;
	switch (nedlen) {
		case 1: 	// nedlen: 1 
			while (i<haylen) {
				if cmpShort1z(ned,hay,i)
					return i;
				++i;
			}
			break;
		case 2: // nedlen: 2
			while (i<haylen) {
				if cmpShort2z(ned,hay,i)
					return i;
				++i;
			}
			break;
		case 3: // nedlen: 3
			while (i<haylen) {
				if cmpShort3z(ned,hay,i)
					return i;
				++i;
			}
			break;
		case 4: // nedlen: 4
			while (i<haylen) {
				if cmpShort4z(ned,hay,i)
					return i;
				++i;
			}			
			break;
		default: // nedlen: 4+
			rem = nedlen % 4;			
			if (rem == 0){
				do {
					if cmpShort4(ned,hay,0) {
						for (j=4; j<nedlen && cmpShort4(ned,hay,j); j=j+4);	
						if (j == nedlen)
							return i;
					}
					i++;
					++hay;
				} while (i<haylen);
			} else if (rem==1) {
				do {
					if cmpShort4(ned,hay,0){
						for (j=4; j<nedlen-1 && cmpShort4(ned,hay,j); j=j+4);
						if (j == nedlen-1 && hay[nedlen-1]==ned[nedlen-1]){
							return i;
						}
					}
					i++;
					++hay;
				} while (i<haylen); 
			} else if (rem==2) {
				do {
					if cmpShort4(ned,hay,0) {
						for (j=4; j<nedlen-2 && cmpShort4(ned,hay,j); j=j+4);
						if (j == nedlen-2 && hay[nedlen-2]==ned[nedlen-2] && hay[nedlen-1]==ned[nedlen-1]){
							return i;
						}
					}
					i++;
					++hay;
				} while (i<haylen);
			} else if (rem==3) {
				do {
					if cmpShort4(ned,hay,0){
						for (j=4; j<nedlen-3 && cmpShort4(ned,hay,j) ; j=j+4);
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