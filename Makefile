##
# Constants
##
CC=gcc
DEPENDENCIES=./src/bitmap.o ./src/util.o
SRC_ENTRY=./src/parser.o
BIN_OUTPUT=./bin/parser.out

##
# $ make compile - Compiles the object files
##
compile: $(SRC_ENTRY) $(DEPENDENCIES)
	$(CC) -std=c99 -o $(BIN_OUTPUT) $(SRC_ENTRY) $(DEPENDENCIES)

##
# $ make exec - Executes the final binary file
##
exec: $(BIN_OUTPUT)
	$(BIN_OUTPUT) ./test/x.bmp

compile_tests: test/main.o src/bitmap.o
	gcc -std=c99 -o bin/main.bin test/main.o src/bitmap.o

run_tests: test/main.o src/bitmap.o
	bin/main.bin test/x.bmp
