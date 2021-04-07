//https://stackoverflow.com/questions/46748572/how-to-access-webassembly-linear-memory-from-c-c
#include<emscripten.h>
#include<string>
#define BUFSZ 32
extern "C"{
extern void _imp0(void);
extern void _imp1(int);
extern void _log(const char*);
EMSCRIPTEN_KEEPALIVE
const int bufsz=BUFSZ;
EMSCRIPTEN_KEEPALIVE
int buf0[BUFSZ];
EMSCRIPTEN_KEEPALIVE
int buf1[BUFSZ];
EMSCRIPTEN_KEEPALIVE
int getBufsz(){return bufsz;};
EMSCRIPTEN_KEEPALIVE
int sumBuf(){
	int ret=0;
	for(int i=0;i<BUFSZ;i++){
		ret+=buf0[i]+buf1[i];
	}
	return ret;
}
EMSCRIPTEN_KEEPALIVE
int dotBuf(){
	int ret=0;
	for(int i=0;i<BUFSZ;i++){
		ret+=buf0[i]*buf1[i];
	}
	return ret;
}

}
