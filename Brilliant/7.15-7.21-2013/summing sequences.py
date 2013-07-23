from sys import *

seq = map(int, stdin.read().split())
count = len(seq)

def N(s):
	ans = 0
	for i in range(count):
		for j in range(count):
			k = 0
			curr = 0
			for k in range(i,j+1):
				curr += seq[k]
			if curr == s:
				ans += 1
	return ans

print (N(11) + N(2) + N(9) + N(14)) % 1000
