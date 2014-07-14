#!/usr/bin/jc

NB. a j script for matrix multiplication of a random vector * random matrix
NB. this is split into 5 lines of logic for readability.

n =. ".>{.|.ARGV    NB. vector of n elements, n*n matrix

NB. explained below:
NB. ARGV            NB. the input argument list (consists of boxed char arrays like char* argv[] in C)
NB. |.              NB. reverse list
NB. {.              NB. take head of list
NB. >               NB. open (a.k.a. unbox) item
NB. ".              NB. convert char array to numbers

a =. n ?@$ 0        NB. generate a vector of N random values from 0 to 1
b =. n ?@$ 0        NB. generate another vector of N random values from 0 to 1
m =. a*/b           NB. build a random table by multiplying each cell of a with the entire b


NB. the main program. compute inner product of a and m
word =. ": a +/ . * m

writefile =: 1!:2
fn =. < 'output/joutput.txt'
word writefile fn

NB. echo word           NB. display result

exit''
