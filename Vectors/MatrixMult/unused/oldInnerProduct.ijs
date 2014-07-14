NB. NB. hard-coded matrix multiplcation in J (issue the following commands from a J interactive session)
NB. NB. to run, install j from jsoftware.com and use jconsole:
NB. NB.                 jconsole < sameInJ.ijs
NB. 
a=.i.4
+/[a*(a+/a)
NB. 
NB. NB. output: 14 20 26 32
NB. 
NB. NB. commented:
NB. NB. a=.i.4       NB. create a vector [0 1 2 3]
NB. NB. +/[a*(a+/a)  NB. show inner product
