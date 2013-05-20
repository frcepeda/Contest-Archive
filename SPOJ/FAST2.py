import sys

t = int(sys.stdin.readline())

ans = []

mod = 1298074214633706835075030044377087L

acc = 0L
two = 1L
for i in range(501):
	acc += two
	two *= 2
	if acc >= mod:
		acc %= mod
	ans.append(str(acc) + '\n')

for x in range(t):
	n = int(sys.stdin.readline())
	sys.stdout.write(ans[n])
