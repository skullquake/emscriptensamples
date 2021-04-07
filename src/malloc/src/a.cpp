//https://stackoverflow.com/questions/46748572/how-to-access-webassembly-linear-memory-from-c-c
#include<emscripten.h>
#include<string>
#define BUFSZ 32
extern "C"{
extern void _log(const char*);
EMSCRIPTEN_KEEPALIVE
int sum(int*buf,int sz){
	int ret=0;
	for(int i=0;i<sz;i++){
		ret+=buf[i];
	}
	return ret;
}
EMSCRIPTEN_KEEPALIVE
double avg(int*buf,int sz){
	double ret=0;
	for(int i=0;i<sz;i++){
		ret+=buf[i];
	}
	return ret/sz;
}
}
