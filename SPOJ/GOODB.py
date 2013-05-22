import sys
import math

def choose(n,k):
	return math.factorial(n)/(math.factorial(n-k) * math.factorial(k))

N, W, T, R = map(long, sys.stdin.readline().split())

print (choose(N,W) * choose(N-W, T)) % 1000000007
