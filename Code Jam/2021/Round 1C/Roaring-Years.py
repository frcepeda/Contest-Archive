T = int(input())

def roaring(x, n):
    s = ""

    for i in range(n):
        s += str(x+i)

    return int(s)

def count(x, n):
    lo = 1
    hi = x
    
    while lo < hi:
        mid = (lo + hi)//2
        if roaring(mid, n) > x:
            hi = mid
        else:
            lo = mid + 1
    
    return hi - 1

def roaringBelow(x):
    ans = 0
    i = 2

    while True:
        tmp = count(x,i)
        if tmp == 0:
            break
        ans += tmp
        i += 1

    return ans

for t in range(1,T+1):
    N = int(input())

    cnt = roaringBelow(N)

    lo = 1
    hi = 10**20

    while lo < hi:
        mid = (lo+hi)//2
        if roaringBelow(mid) <= cnt:
            lo = mid + 1
        else:
            hi = mid

    print(f"Case #{t}: {lo}")
