# Polyglot Inner Product
Results: J is fast.

<img src="https://raw.githubusercontent.com/hoosierEE/Homework/master/Vectors/MatrixMult/output/graph.png"
  style="width=100%;"/>

#### The Assignment
Write a matrix multiplication algorithm in C++, benchmark it.
Try to make it faster by paying attention to memory access patterns.

#### The Twist
Do the same thing in a different language and compare the results by:

* execution time
* programmer time
* code size

For this particular shootout, the languages being compared are

* [C++](http://isocpp.org/), the de-facto systems programming language. Key features:
    * speed 
    * control
* [J](http://www.jsoftware.com/), an APL dialect that doesn't require a special keyboard. Key features:
    * statistical analysis
    * tacit programming.

## Try it
prerequesites:

* `jconsole`, a command-line front-end for the J language
* `make` and a recent GCC to compile the C program for your system
* `python` to run the benchmarking script

running:

1. In a terminal, navigate to the MatrixMult folder and run `make`.
2. run `pytimer` to display the execution times (e.g. on UNIX based systems, type `./pytimer`)

## Files
```
MatrixMult/
├── exe
│   ├── cexe
│   ├── cnothing
│   ├── jexe
│   └── jnothing
├── makefile
├── old
│   ├── argv.ijs
│   ├── oldInnerProduct.cpp
│   └── oldInnerProduct.ijs
├── pytimer
├── README.markdown
└── src
    ├── cInnerProduct.cpp
    ├── cnothing.cpp
    ├── jInnerProduct.ijs
    └── jnothing.ijs

3 directories, 14 files
```
