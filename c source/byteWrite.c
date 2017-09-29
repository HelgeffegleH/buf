typedef unsigned int __cdecl (*pbyteFind)(unsigned char*, unsigned char*, unsigned int, unsigned int);
//typedef unsigned int __cdecl byteFind(unsigned char* hay, unsigned char* ned, unsigned int haylen, unsigned int nedlen)
unsigned int __cdecl byteWrite(unsigned char* hay, unsigned char* ned, unsigned char* wrt, unsigned int haylen, unsigned int nedlen,unsigned int wrtlen, unsigned int nWrites, int o,  pbyteFind byteFind){
	// for byteWrite(), compiled with gcc -Ofast
	unsigned int p,k;
	unsigned int n=0;
	if (nedlen > haylen || wrtlen>haylen || nWrites==0)
		return 0;
	while ((p=byteFind(hay,ned,haylen,nedlen))!=0xFFFFFFFF){
		if ((o>=0 && p+wrtlen+o>haylen) || (o<0 && ((int)p+o)<0)) // avoids writing outside of haystack.
			return n;
		for (k=0; k<wrtlen; ++k)
			hay[((int)(p+k))+o]=wrt[k];
		
		hay+=p+wrtlen;
		haylen-=p+wrtlen;
		++n;		
		if (nedlen > haylen || wrtlen>haylen || nWrites == n)
			return n;
	}
	return n;
}