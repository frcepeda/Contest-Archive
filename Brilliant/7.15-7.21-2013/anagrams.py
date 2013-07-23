from sys import *

words = stdin.read().split()

words = map(sorted, words)

count = 0

for w in words:
	if words.count(w) > 1:
		count += 1

print count
