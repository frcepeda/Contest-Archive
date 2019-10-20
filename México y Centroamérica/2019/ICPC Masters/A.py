def mat_exp(x, e):
    ret = 1

    return 

T = int(input())

for t in range(T):
    S, Ks, Ns = input().split()
    K = int(Ks)
    N = int(Ns)

    M = [[0 for x in range(26)] for y in range(26)]

    for i in range(K):
        c, r = input().split()

        for x in r:
            M[ord(x)-ord('a')][ord(c)-ord('a')] += 1
    
    for r in range(26):
        for c in range(26):
            print(M[r][c], end = '')
    
    M = mat_exp(M, N)

    for r in range(26):
        for c in range(26):
            print(M[r][c], end = '')
