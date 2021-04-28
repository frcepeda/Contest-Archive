T = int(input())

for t in range(1,T+1):
    M = int(input())
    P = []

    for i in range(M):
        p, n = [int(x) for x in input().split()]
        for j in range(n):
            P.append(p)
    
    ans = 0

    for i in range(2**len(P)):
        sum, product = 0, 1
        for j in range(len(P)):
            if i & (1<<j):
                sum += P[j]
            else:
                product *= P[j]
        if sum == product and ans < sum:
            ans = sum

    print(f"Case #{t}: {ans}")
