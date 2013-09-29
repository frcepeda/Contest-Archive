// 100/100 points
#include <stdio.h>

#define MAXN 15

/*
We can split the problem in half with a simple observation.
The tallest tower must be in both sequences. Also, it will block the rest
of the towers from view. We can exploit this to separate the problem into
the front side and back side. If f(n,m) counts the ways we can set up n
towers so only m can be seen from one side, the answer we want is

\sum_{i=0}^{N-1} (N-1 \choose i) * f(i,F-1) * f(N-i-1,B-1).

This is because the only thing that matters is the relative ordering of the
towers, so we can simply count the ways n towers can be distributed, since
all the heights are different. The problem is symmetric on the front and
back, so we only need to define f.

Now, to compute f, we can reuse the same observation. When we place the
tallest tower, any tower that we place after index i will be blocked from
view. On the visible side, we must arrange the remaining towers so only
m-1 are visible, and we can arrange the hidden side in any way we want.
This gives us

f(0,0) = 1
f(n,m)
    | m > n     = 0
    | otherwise = \sum_{i=0}^{n-1} (n-1 \choose i) * f(i,m-1) * (n-i-1)!,

which solves the problem in O(N^3) time and O(N^2) memory.

This can be improved further by observing that f(n,m) corresponds to the
unsigned Stirling numbers of the first kind, which can be computed in O(N^2)
time.

The unsigned Stirling numbers of the first kind count the number of
permutations with n elements and k cycles. Consider a permutation with k
cycles of the N buildings. Every cycle must have a maximum element, and we
can sort the cycles in increasing order of their maximum element. This
ensures that k buildings are visible. Since all the permutations with k
cycles are being counted, every possible ordering with k visible buildings
will be counted. This is because only one representation per cycle has
exactly one visible building, namely the one that starts with the largest
building.
*/

int choose[MAXN][MAXN];
int stirling[MAXN][MAXN];
int N, F, B;

int main(void){
	int i, j, k;

	scanf("%d %d %d", &N, &F, &B);

	for (i = 0; i < MAXN; i++){
		choose[i][0] = choose[i][i] = 1;
		for (j = 1; j < i; j++)
			choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
	}

	stirling[0][0] = 1;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= i; j++)
			stirling[i][j] = stirling[i-1][j-1] + (i-1) * stirling[i-1][j];

	int ans = 0;
	for (i = 0; i < N; i++)
		ans += choose[N-1][i] * stirling[i][F-1] * stirling[N-i-1][B-1];

	printf("%d\n", ans);

	return 0;
}
