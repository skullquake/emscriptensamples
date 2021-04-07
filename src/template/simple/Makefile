CXX=em++
CC=emcc
EMRUN=emrun
EMMAKE=emmake
CFLAGS=
CXXFLAGS=
LDFLAGS=
SRC=./src/a.cpp
BIN=./bin/a.js
$(BIN):$(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(BIN)
run:$(BIN)
	$(EMRUN)
.phony:clean
clean:
	rm ./bin/*
