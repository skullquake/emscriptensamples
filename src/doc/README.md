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
