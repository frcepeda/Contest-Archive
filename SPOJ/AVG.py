import sys

t = int(sys.stdin.readline())

for x in range(t):
	n = int(sys.stdin.readline())
	nums = map(int, sys.stdin.readline().split())
	print (sum(nums)//n)
