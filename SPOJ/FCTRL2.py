import sys

fact = [1L]

for x in range(1,101):
	fact.append(fact[-1] * x)

t = int(sys.stdin.readline())

for x in range(t):
	n = int(sys.stdin.readline())
	print fact[n]
