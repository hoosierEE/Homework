CC = g++
FILES = *.cpp
OUT_EXE = output_executable
OPTS = -std=c++0x

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(OPTS)

clean:
	-rm -f *.o core $(OUT_EXE)

rebuild: clean build
