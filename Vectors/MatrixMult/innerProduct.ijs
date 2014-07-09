NB. NB. hard-coded matrix multiplcation in J (issue the following commands from a J interactive session)
NB. NB. to run, install j from jsoftware.com and use jconsole:
NB. NB.                 jconsole < sameInJ.ijs
NB. 
NB. a=.i.4
NB. +/[a*(a+/a)
NB. 
NB. NB. output: 14 20 26 32
NB. 
NB. NB. commented:
NB. NB. a=.i.4       NB. create a vector [0 1 2 3]
NB. NB. +/[a*(a+/a)  NB. show inner product

NB. random floating-point version:

n=. 100
a=. n ?@$ 0   NB. generate a vector of N values from 0 to 1
b=. n ?@$ 0   NB. generate another vector of N values from 0 to 1
m=. a*/b      NB. build a table by multiplying each cell of a with the entire b

a+/[+/.*m     NB. compute inner product (vector * matrix) of a and m
