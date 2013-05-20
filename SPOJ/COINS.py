import sys

mem = {}

mem[0] = 0
mem[1] = 1

def f(n):
	if mem.has_key(n):
		return mem[n]
	mem[n] = max(n, f(n//2) + f(n//3) + f(n//4))
	return mem[n]

def solve(x):
	print f(int(x))

map(solve, sys.stdin.read().split())
