import time, os, subprocess

# determine overhead involved in simply calling the scripts
silent = " 2>&1 > /dev/null" # redirect standard output to trash
jtest = "nothing.ijs"
jtestcmd = "jc < " + jtest + silent
ctestcmd = "./a.out" + silent

def timer(cmd):
    start = time.time()
    subprocess.Popen(cmd, shell=True)
    end = time.time()
    return end - start

def overhead(script):
    iters = 100
    avg = 0
    for i in range(iters):
        avg += timer(script)
    return avg / iters 

print "J interpreter overhead: ", overhead(jtestcmd)
print "C++ binary file overhead: ", overhead(ctestcmd)
