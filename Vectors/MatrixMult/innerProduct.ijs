NB. random floating-point version:

n=. 100       NB. dimension of our vector (and square matrix)
a=. n ?@$ 0   NB. generate a vector of N values from 0 to 1
b=. n ?@$ 0   NB. generate another vector of N values from 0 to 1
m=. a*/b      NB. build a table by multiplying each cell of a with the entire b

a+/[+/.*m     NB. compute inner product (vector * matrix) of a and m
