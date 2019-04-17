##
# Constants
##
CC=gcc
DEPENDENCIES=./src/bitmap.o
SRC_ENTRY=./src/parser.o
BIN_OUTPUT=./bin/parser.out

parser: $(SRC_ENTRY) $(DEPENDENCIES)
	$(CC) -std=c99 -o $(BIN_OUTPUT) $(SRC_ENTRY) $(DEPENDENCIES)
