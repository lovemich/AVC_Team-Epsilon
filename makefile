C = g++
FLAGS  = -Wall -Wextra
LIB = -lE101

BIN = main

SRC = $(shell find ./src/ -type f -name '*.cpp')
OBJ = $(patsubst ./src/%.cpp, build/%.o, $(SRC))

default: $(BIN)

$(BIN): $(OBJ)
	$(C) -o $(BIN) $(OBJ) $(LIB)

build/%.o: src/%.cpp clean
	$(C) -c $< -o $@ $(FLAGS)

setup_dirs:
	mkdir -p ./build

clean:
	rm -rf ./build
	mkdir -p ./build

