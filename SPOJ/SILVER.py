import sys
import math

tests = map(int, sys.stdin.read().split()[:-1])

for N in tests:
	print int(math.floor(math.log(N,2)))
