#!/usr/bin/jc
NB. a j script for matrix multiplication of a random vector * random matrix

n =. ".>{.|.ARGV  NB. dimension of our vector (and square matrix)
NB. ARGV          list of input arguments
NB. |.            reverse list
NB. {.            take head of list
NB. >             open (unbox) item
NB. ".            convert char array to numbers

a =. n ?@$ 0      NB. generate a vector of N random values from 0 to 1
b =. n ?@$ 0      NB. generate another vector of N random values from 0 to 1
m =. a*/b         NB. build a random table by multiplying each cell of a with the entire b

word=.a+/[+/.*m   NB. compute inner product (vector * matrix) of a and m
echo word         NB. display result

exit''
