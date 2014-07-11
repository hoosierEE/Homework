#!/usr/bin/jc
NB. trying to figure out how to read command-line args
NB. finally figured it out (see jexe script in this directory)
n=:}.}.ARGV
unboxed=: >n
echo 2 * unboxed
exit''
