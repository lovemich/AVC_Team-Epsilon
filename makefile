C = g++
FLAGS  = -Wall -Wextra

BIN = main

SRC = $(shell find ./src/ -type f -name '*.cpp')
OBJ = $(patsubst ./src/%.cpp, build/%.o, $(SRC))

default: $(BIN)

$(BIN): $(OBJ)
	$(C) $(OBJ)

build/%.o: src/%.cpp
	$(C) -c $< -o $@ $(FLAGS)

clean: clean-bin clean-iso
	rm -rf ./build
	mkdir -p ./build

