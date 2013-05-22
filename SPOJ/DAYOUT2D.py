from sys import *

N = int(stdin.readline())

for x in range(1,N+1):
	s = stdin.readline()
	c = stdin.readline()[0]
	print "Case %s: %s" % (x, s.count(c))
