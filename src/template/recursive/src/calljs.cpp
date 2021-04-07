#include<emscripten.h>
extern "C"{
	extern void _imp0(void);
	extern void _imp1(int);
	EMSCRIPTEN_KEEPALIVE
	void call_imp0(void){
		_imp0();
	}
	EMSCRIPTEN_KEEPALIVE
	void call_imp1(int i){
		_imp1(i);
	}

}
