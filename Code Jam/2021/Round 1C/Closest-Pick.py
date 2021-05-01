from fractions import Fraction
from decimal import localcontext, Decimal

T = int(input())

for t in range(1,T+1):
    N, K = [int(x) for x in input().split()]
    P = [0] + sorted([int(x) for x in input().split()]) + [K+1]

    L = P[1] - P[0] - 1
    R = P[N+1] - P[N] - 1
    M,M1 = 0,0
    PP = [0,0]

    for i in range(2,N+1):
        PP.append(P[i] - P[i-1] - 1)
    
    PP = sorted(PP)

    ans = max(PP[-1], (PP[-1]+1)//2 + (PP[-2]+1)//2)
    ans = max(ans, (PP[-1]+1)//2 + max(L,R))
    ans = max(ans, L+R)
    
    prob = Fraction(ans, K)

    with localcontext() as ctx:
        ctx.prec = 10
        print(f"Case #{t}: {Decimal(prob.numerator) / Decimal(prob.denominator)}")
