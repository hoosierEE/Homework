NB. hard-coded matrix multiplcation in J (issue the following commands from a J interactive session)
NB. to run, install j from jsoftware.com and use jconsole:
NB.                 jconsole < sameInJ.ijs

a=.b=.i.4               
c=.a+/b                 
+/[a*(a+/b)             

NB. output: 14 20 26 32

NB. commented:
NB. a=.b=.i.4               NB. create a vector [0 1 2 3]
NB. c=.a+/b                 NB. create a matrix [[0 1 2 3][1 2 3 4][2 3 4 5][3 4 5 6]]
NB. +/[a*(a+/b)             NB. show inner product
