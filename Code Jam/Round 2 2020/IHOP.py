import math

def tri(a, b):
    a -= 1
    return b*(b+1)//2 - a*(a+1)//2

def even(a, b):
    a -= 1
    a //= 2
    b //= 2
    return b*(b+1) - a*(a+1)

def odd(a, b):
    return tri(a, b) - even(a, b)

def tribsearch(x):
    lo, hi = 0, 5*10**9
    while lo < hi:
        mid = (lo + hi)//2
        if tri(1, mid) >= x:
            hi = mid
        else:
            lo = mid + 1
    return hi

def solve(L, R):
    swapped = False
    if L < R:
        L, R = R, L
        swapped = True

    steps = 0
    delta = L - R
    k = tribsearch(delta)

    steps += k
    L -= tri(1, k)

    if L < R or (L == R and swapped):
        L, R = R, L
        swapped ^= True

    def fL(x):
        if steps % 2 == 0:
            return odd(steps+1, x)
        else:
            return even(steps+1, x)

    def fR(x):
        if steps % 2 == 1:
            return odd(steps+1, x)
        else:
            return even(steps+1, x)

    lo, hi = 0, 5*10**9
    while lo < hi:
        mid = (lo + hi)//2
        if fL(mid) > L or fR(mid) > R:
            hi = mid
        else:
            lo = mid + 1
    
    lo -= 1

    L -= fL(lo)
    R -= fR(lo)
    steps = lo

    if swapped:
        L, R = R, L
    
    return steps, L, R

T = int(input())

for t in range(1, T+1):
    L, R = map(int, input().split(' '))

    steps, l, r = solve(L, R)

    print("Case #" + str(t) + ": " + str(steps) + " " + str(l) + " " + str(r))
