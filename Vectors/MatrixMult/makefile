# makefile for some c++ files in a directory
CC = g++
OPTS = -std=c++11 -O3
OUT_DIR = bin/
SRC_DIR = src/
CTEST = cnothing
CMAIN = cInnerProduct
COUTPUT = cexe

all: nothing main

rebuild: clean nothing main

nothing: $(SRC_DIR)$(CTEST).cpp
	$(CC) -o $(OUT_DIR)$(CTEST).out $(SRC_DIR)$(CTEST).cpp $(OPTS)

main: $(SRC_DIR)$(CMAIN).cpp
	$(CC) -o $(OUT_DIR)$(COUTPUT).out $(SRC_DIR)$(CMAIN).cpp $(OPTS)

clean:
	-rm -f *.o core $(OUT_DIR)$(COUTPUT).out $(OUT_DIR)$(CTEST).out
