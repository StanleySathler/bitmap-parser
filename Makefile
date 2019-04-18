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
	$(BIN_OUTPUT) /home/stanley/Desktop/x.bmp
