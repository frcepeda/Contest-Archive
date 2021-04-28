T = int(input())

for t in range(1,T+1):
    N = int(input())
    nums = [int(x) for x in input().split()]

    last = nums[0]
    ans = 0

    for j in range(1,N):
        curr = nums[j]
        fact = 1

        if last < curr:
            last = curr
            continue

        while (last >= curr * fact):
            ans += 1
            fact *= 10

        delta = last - curr * fact / 10

        if delta+1 < fact / 10:
            ans -= 1
            last = last + 1
        else:
            last = curr * fact

    print(f"Case #{t}: {ans}")
