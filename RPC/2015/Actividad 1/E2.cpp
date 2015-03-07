/*
German Collegiate Programming Contest: Equator

See E.cpp for an O(N lg N) solution (which was
the one we made during the contest).

This is a classical twist on the classical maximum
subarray sum problem. Unfortunately we hadn't solved it
before the contest. So yay.

The idea is simple. Either the best subarray wraps
around or it doesn't. If it doesn't wrap arround, then
the solution for the regular maximum subarray sum gives
the correct answer.

If the solution does wrap around, then that means that
the elements that aren't in the solution /don't/ wrap
around, so we can flip the sign of all the elements in
the array and run the original algorithm again. Sneaky.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000100

int T, N, a[MAXN];
int p, m, bp, bm, sum;

int main(){
	scanf("%d", &T);

	while (T--){
		int i;
		p = m = bp = bm = sum = 0;

		scanf("%d", &N);

		for (i = 0; i < N; i++){
			scanf("%d", &a[i]);
			sum += a[i];
		}

		for (i = 0; i < N; i++){
			p = a[i] + max(0, p);
			m = -a[i] + max(0, m);
			bp = max(p, bp);
			bm = max(m, bm);
		}

		printf("%d\n", max(bp, sum + bm));
	}
}
