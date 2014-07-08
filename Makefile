CC = g++
FILES = *.cpp
OUT_EXE = a.out
OPTS = -std=c++11

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(OPTS)

clean:
	-rm -f *.o core $(OUT_EXE)

rebuild: clean build
