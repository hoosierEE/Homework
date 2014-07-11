import time, os, subprocess

silent = " 2>&1 > /dev/null" # redirect standard output to trash
jtest = "nothing.ijs"
jtestcmd = "jc < " + jtest + silent
ctest = "a.out"
ctestcmd = "./" + ctest + silent

def timer(cmd):
    """ Measure the time it takes to invoke the given command
    using a shell subprocess. """
    start = time.time()
    subprocess.Popen(cmd, shell=True)
    end = time.time()
    return end - start

def overhead(cmd, fname):
    """ how long it takes for python to simply call an external program """
    if os.path.isfile(fname):
        iters = 100
        avg = 0
        for i in range(iters):
            avg += timer(cmd)
        return avg / iters 
    else:
        return "missing file"
        
print "J interpreter overhead: ", overhead(jtestcmd, jtest)
print "C++ binary file overhead: ", overhead(ctestcmd, ctest)
