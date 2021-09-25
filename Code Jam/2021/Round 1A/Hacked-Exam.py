from fractions import Fraction
from collections import defaultdict
import itertools

T = int(input())

for t in range(1,T+1):
    N, Q = [int(x) for x in input().split()]

    A = []
    for i in range(N):
        a, s = input().split()
        A.append((a,int(s)))
    
    for x in range(3-N):
        A.append(A[-1])

    best = ""
    ans = Fraction(0)
    
    dpR = defaultdict(lambda: 0)
    dpL = defaultdict(lambda: 0)

    for i in range(Q,-1,-1):
        for a in range(Q+1):
            for b in range(Q+1):
                for c in range(Q+1):
                    if i == Q:
                        if a == 0 and b == 0 and c == 0:
                            dpR[i,a,b,c] = 1
                        else:
                            dpR[i,a,b,c] = 0
                        continue

                    for y in "TF":
                        ap = a - (1 if A[0][0][i] == y else 0)
                        bp = b - (1 if A[1][0][i] == y else 0)
                        cp = c - (1 if A[2][0][i] == y else 0)
                        
                        if ap < 0 or bp < 0 or cp < 0:
                            continue

                        dpR[i,a,b,c] += dpR[i+1,ap,bp,cp]

    for i in range(Q+1):
        for a in range(Q+1):
            for b in range(Q+1):
                for c in range(Q+1):
                    if i == 0:
                        if a == 0 and b == 0 and c == 0:
                            dpL[i,a,b,c] = 1
                        else:
                            dpL[i,a,b,c] = 0
                        continue

                    for y in "TF":
                        ap = a - (1 if A[0][0][i-1] == y else 0)
                        bp = b - (1 if A[1][0][i-1] == y else 0)
                        cp = c - (1 if A[2][0][i-1] == y else 0)
                        
                        if ap < 0 or bp < 0 or cp < 0:
                            continue

                        dpL[i,a,b,c] += dpL[i-1,ap,bp,cp]

    for q in range(Q):
        b = {'T': 0, 'F': 0}
        for y in "TF":
            for al in range(A[0][1]+1):
                for bl in range(A[1][1]+1):
                    for cl in range(A[2][1]+1):
                        ar = A[0][1] - al + (-1 if A[0][0][q] == y else 0)
                        br = A[1][1] - bl + (-1 if A[1][0][q] == y else 0)
                        cr = A[2][1] - cl + (-1 if A[2][0][q] == y else 0)

                        if ar < 0 or br < 0 or cr < 0:
                            continue

                        b[y] += dpL[q,al,bl,cl] * dpR[q+1,ar,br,cr]
        
        if b['T'] >= b['F']:
            best += 'T'
            ans += Fraction(b['T'], b['T'] + b['F'])
        else:
            best += 'F'
            ans += Fraction(b['F'], b['T'] + b['F'])

    print(f"Case #{t}: {best} {ans.numerator}/{ans.denominator}")
