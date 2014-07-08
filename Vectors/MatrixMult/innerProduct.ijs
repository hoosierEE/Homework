NB. hard-coded matrix multiplcation in J (issue the following commands from a J interactive session)
NB. to run, install j from jsoftware.com and use jconsole:
NB.                 jconsole < sameInJ.ijs

a=.i.4
+/[a*(a+/a)

NB. output: 14 20 26 32

NB. commented:
NB. a=.i.4       NB. create a vector [0 1 2 3]
NB. +/[a*(a+/a)  NB. show inner product
