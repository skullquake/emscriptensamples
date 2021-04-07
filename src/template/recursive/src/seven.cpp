#include<emscripten.h>
extern "C"{
	EMSCRIPTEN_KEEPALIVE
	int seven(){
		return 7;
	}
}
