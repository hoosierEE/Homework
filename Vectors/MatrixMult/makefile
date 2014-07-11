# makefile for some c++ files in a directory

CC = g++
OPTS = -std=c++11
OUT_DIR = exe/
SRC_DIR = src/
CTEST = cnothing
CMAIN = cInnerProduct.cpp
COUTPUT = cexe

all: clean nothing main

nothing: $(SRC_DIR)$(CTEST).cpp
	$(CC) -o $(OUT_DIR)$(CTEST) $(SRC_DIR)$(CTEST).cpp $(OPTS)

main: $(SRC_DIR)$(CMAIN)
	$(CC) -o $(OUT_DIR)$(COUTPUT) $(SRC_DIR)$(CMAIN) $(OPTS)

clean:
	-rm -f *.o core $(OUT_DIR)$(COUTPUT) $(OUT_DIR)$(CTEST)

