import os
f = open('csvNames', 'w')
lst = (os.listdir("raw"))
for i in lst:
    print >>f, i
f.close()
