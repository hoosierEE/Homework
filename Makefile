# from the command line:
# g++ matrix.cpp -o hello

all: hello

hello:
	g++ matrix.cpp -o hello

clean:
	rm -rf *o hello
