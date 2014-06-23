# My first Python program! :)
# when run (with `python filenameList.py`), it writes the names of the files
# in the `raw` directory to a plain text file called `csvNames`
# e.g. if the contents of `raw` are `file1` and `file2` then
# the text of `csvNames` will be:
#  raw/file1
#  raw/file2
import os
f = open('csvNames', 'w')
lst = (os.listdir("raw"))
for i in lst:
    print >>f, "raw/" + i
f.close()
