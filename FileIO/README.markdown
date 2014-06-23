# Simple(?) CSV parsing in C++

## Contents
* a directory called "raw" which contains many csv files from the oscilloscope
* a python script which writes the names of these csv files to a text file called "csvNames"
* a C++ source file for concatenating and parsing the csv files
* a makefile for building the C++ source on your system.

## Dependencies
A recent C++ compiler (makes use of C++11 features)
A python interpreter >= 2.4

## Usage
Run the following commands:
```
python filenameList.py
make
```

Then run `output_executable`. For example from a Linux terminal you would issue the command:
`./output_executable`
