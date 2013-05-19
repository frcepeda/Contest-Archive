import sys

def gcd(a,b):
	if b == 0:
		return a
	return gcd(b, a%b)

p,q = sys.stdin.readline().split()
p = long(p)
q = long(q)
n = sys.stdin.readline().split()[0]
n = long(n)
a = sys.stdin.readline().split()[::-1]

g = gcd(p,q)
p /= g
q /= g

x,y = 0L,1L

for k in a:
	x += y * long(k)
	g = gcd(x,y)
	x /= g
	y /= g
	x,y = y,x

if p == y and q == x:
	print "YES"
else:
	print "NO"
