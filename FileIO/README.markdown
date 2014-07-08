# Simple(?) CSV parsing in C++

## Contents
* a `raw` directory which contains many csv files from the oscilloscope
* a python script (`filenamelist.py`) which writes the names of these csv files to a text file called "csvNames"
* a C++ source file which concatenates and parses the csv files
* a makefile for building the C++ source code on your system.

## Dependencies
1. A recent C++ compiler (makes use of C++11 features)
2. A python interpreter >= 2.4
3. This repository (to use the symlink to the makefile)

## Usage
Run the following commands:
```
python filenameList.py
make
```

Then run `output_executable`. 

For example from a Linux terminal you would issue the command:
`./output_executable`
