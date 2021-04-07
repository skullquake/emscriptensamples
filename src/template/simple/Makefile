CXX=em++
CC=emcc
EMRUN=emrun
EMMAKE=emmake
CFLAGS=
CXXFLAGS=
LDFLAGS=-O3 -s WASM=1 -s EXPORTED_FUNCTIONS='["_hello"]' 
SRC=./src/a.cpp
BINDIR=./bin
BIN=$(BINDIR)/hello.html
HOST=0.0.0.0
PORT=8089
BROWSER=w3m
$(BIN):$(SRC)
	$(CXX) -o $(BIN) $(CXXFLAGS) $(SRC) $(LDFLAGS)
run:$(BIN)
	$(EMRUN) --no_browser --host=$(HOST) --port=$(PORT)  --serve_root=$(BINDIR) $(BIN)

.phony:clean
clean:
	rm ./bin/*
