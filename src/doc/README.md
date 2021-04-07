```
emcc/em++ <flags> <input C/C++ files>
-g - generate debug information
--emrun - generate emrun aware artifact
-s option=value - set compiler configuration value
	-s WASM=1 - generate WebAssembly
	-s ONLY_MY_CODE=1 - do not include stdlib in artifact
	-s EXPORTED_FUNCTIONS='[...]' - list export functions
	-s SIDE_MODULE=1 - create dynamic library, no html/js will be generated, only a special binary output

example:
emcc -o hello.html -O3 -s WASM=1 -s EXPORTED_FUNCTIONS='["_hello"]' hello.c

emrun:
emrun --host 0.0.0.0 --port 8080 --browser firefox

memory:

WebAssembly.Memory contains bytes for data processing and transfer
Constructor has two fields: initial and maximum
Both identify numbers of pages (65,536 bytes/page)
To transfer data, two blocks needs to be created, one in javascript and one in webassembly.

The following is always automatically created for you

var mem=new WebAssembly.Memory({
	initial:256,
	maximum:256
});

Memory blocks may be of type Uint32Array, Int2Array, Float32Array, Float64Array

The read/write of memory takes place as follows

var mem=new WebAssembly.Memory({
	initial:256,
	maximum:256
});
var blck=new Uint32Array(mem.buffer,offset,len);

Offset and length of blocks needs to be obtained by functions, e.g.

int*getOffset(){return&intpu[0]};

Data Transfer Process:
1. Set env.memory to WebAssembly.Memory
2. Call WebAssembly function to obtain array address
3. Created typed array using the memory and address
4. Call WebAssembly function to process data
5. Access processed data through the typed array

var memObj=new WebAssembly.Memory({
	initial:256,
	maximum:256
});
var importObj={
	env:{
		memory:memObj
	}
};
WebAssembly.instantiateStreaming(fetch("index.wasm"),importObj).then(function(module){
	var offset=result.instance.exports._getOffset();
	var mem=new Uint32Array(memObj.buffer,offset,len);
},function(error){
	console.error(error);
});

```
