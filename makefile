C = g++ -std=c++0x
FLAGS  = -Wall -Wextra -MMD -MP
DEFINE =
LIB = -lE101

BIN = main

SRC = $(shell find ./src/ -type f -name '*.cpp')
OBJ = $(patsubst ./src/%.cpp, build/%.o, $(SRC))
DEP = $(patsubst ./src/%.cpp, build/%.d, $(SRC))

.PHONY: nolink all run sudo_run clean

default: $(BIN)

nolink: $(OBJ)

all: all.cpp | build/
	$(C) -o $(BIN) all.cpp $(LIB) -Wall -Wextra $(DEFINE)

run: $(BIN)
	./$(BIN)

sudo_run: $(BIN)
	sudo ./$(BIN)

clean:
	rm -rf ./build
	mkdir -p ./build

$(BIN): $(OBJ)
	$(C) -o $(BIN) $(OBJ) $(LIB)

build/%.o: src/%.cpp | build/
	$(C) -c $< -o $@ $(FLAGS) $(DEFINE)

build/:
	mkdir -p ./build

-include $(DEP)
