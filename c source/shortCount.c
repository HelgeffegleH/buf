#include "shortmacro.h"
unsigned int __cdecl shortCount(unsigned short* hay, unsigned short* ned, unsigned int haylen, unsigned int nedlen, unsigned int overlap){	
	// specify overlap = 1 to count overlapping occurances, eg in hay='aaa', the needle 'aa' is found twice: [aa]a and a[aa].
	// for shortCount(), compiled with gcc  -Ofast
	unsigned int i=0;
	unsigned int n=0;
	unsigned int j;
	unsigned int rem;
	unsigned int increment = (overlap==1 ? 1 : nedlen);
	if (nedlen>haylen)
		return 0;
	haylen-=nedlen-1;
	switch (nedlen) {
		case 1: 	// nedlen: 1 
			while (i<haylen) {
				if cmpShort1z(ned,hay,i)
					n++;
				++i;
			}
			break;
		case 2: // nedlen: 2
			while (i<haylen) {
				if cmpShort2z(ned,hay,i) {
					n++;
					i+= increment;
				} else {
					++i;
				}
			}
			break;
		case 3: // nedlen: 3
			while (i<haylen) {
				if cmpShort3z(ned,hay,i) {
					n++;
					i+= increment;
				} else {
					++i;
				}
			}
			break;
		case 4: // nedlen: 4
			while (i<haylen) {
				if cmpShort3z(ned,hay,i) {
					n++;
					i+= increment;
				} else {
					++i;
				}
			}			
			break;
		default: // nedlen: 4+
			rem = nedlen % 4;			
			if (rem == 0){
				do {
					if cmpShort4(ned,hay,0) {
						for (j=4; j<nedlen && cmpShort4(ned,hay,j); j=j+4);	
						if (j == nedlen){
							n+=1;
							i+= increment;
							hay+= increment;
							goto eol0;
						}
					}
					i++;
					++hay;
					eol0:;
				} while (i<haylen);
			} else if (rem==1) {
				do {
					if cmpShort4(ned,hay,0){
						for (j=4; j<nedlen-1 && cmpShort4(ned,hay,j); j=j+4);
						if (j == nedlen-1 && hay[nedlen-1]==ned[nedlen-1]){
							n+=1;
							i+= increment;
							hay+= increment;
							goto eol1;
						}
					}
					i++;
					++hay;
					eol1:;
				} while (i<haylen); 
			} else if (rem==2) {
				do {
					if cmpShort4(ned,hay,0) {
						for (j=4; j<nedlen-2 && cmpShort4(ned,hay,j); j=j+4);
						if (j == nedlen-2 && hay[nedlen-2]==ned[nedlen-2] && hay[nedlen-1]==ned[nedlen-1]){
							n+=1;
							i+= increment;
							hay+= increment;
							goto eol2;
						}
					}
					i++;
					++hay;
					eol2:;
				} while (i<haylen);
			} else if (rem==3) {
				do {
					if cmpShort4(ned,hay,0){
						for (j=4; j<nedlen-3 && cmpShort4(ned,hay,j) ; j=j+4);
						if (j == nedlen-3 && hay[nedlen-3]==ned[nedlen-3] && hay[nedlen-2]==ned[nedlen-2] && hay[nedlen-1]==ned[nedlen-1]){
							n+=1;
							i+= increment;
							hay+= increment;
							goto eol3;
						}
					}
					i++;
					++hay;
					eol3:;
				} while (i<haylen);
			} 
			break;
	}
	return n; // return the result.
}
