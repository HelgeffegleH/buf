#import ..\buf.ahk -> buf
strCount(byref hay, byref ned, overlap := 0){
	return buf -> short_count(&hay, &ned, strlen(hay), strlen(ned), overlap)
}