import time, os, subprocess

silent = " 2>&1 > /dev/null" # redirect standard output to trash
jtest = "nothing.ijs"
jtestcmd = "jc < " + jtest + silent
ctest = "nothing"
ctestcmd = "./" + ctest + silent

jreal = "innerProduct.ijs"
creal = "innerProduct"

jrealcmd = "jc < " + jreal + silent
crealcmd = "./" + creal + silent

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
        
# calculate overhead
jOH = overhead(jtestcmd, jtest)
cOH = overhead(ctestcmd, ctest)

# calculate time to run "real" programs 
jtime = timer(jrealcmd)
ctime = timer(crealcmd)


print "J system time: ", jtime
print "C++ system time: ", ctime

#print ""
#print "J interpreter overhead: ", jOH
#print "C++ binary file overhead: ", cOH
#print "J realistic time: ", jtime - jOH
#print "C++ realistic time: ", ctime - cOH
#
