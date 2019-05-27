import math

T = int(input())

for t in range(1, T+1):
    N, L = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()]

    x, ax = None, None
    for i in range(len(B)-1):
        g = math.gcd(B[i], B[i+1])
        if g != B[i]:
            x, ax = i+1, g
            break

    A = [0] * (L+1)
    A[x] = ax

    for i in range(x-1,-1,-1):
        A[i] = B[i] // A[i+1]
    for i in range(x+1,L+1):
        A[i] = B[i-1] // A[i-1]

    P = sorted(list(set(A)))

    key = dict()
    for i in range(len(P)):
        key[P[i]] = chr(ord('A') + i)

    ans = ''.join([key[x] for x in A])

    print('Case #%d: %s' % (t, ans))
