#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

#define LIMIT (1<<20)

/*
int L;
long long special[LIMIT], N;
*/

const int L = 18;
long long special[L] = {
	8LL,
	49LL,
	288LL,
	1681LL,
	9800LL,
	57121LL,
	332928LL,
	1940449LL,
	11309768LL,
	65918161LL,
	384199200LL,
	2239277041LL,
	13051463048LL,
	76069501249LL,
	443365544448LL,
	2584123765441LL,
	15061377048200LL,
	87784138523761LL
};
long long N;

bool isSquare(long long x){
	long long lo = 0, hi = x / 2, mid;
	while (lo < hi){
		mid = (lo + hi)/2;
		if (mid > LLONG_MAX / mid || mid * mid >= x)
			hi = mid;
		else
			lo = mid + 1;
	}
	return hi * hi == x;
}

int main(){
	/*
	for (long long i = 3; i <= 10000000L; i += 2){
		if (isSquare((i*i - 1) / 2))
			special[L++] = i*i - 1;
		if (isSquare((i*i + 1) / 2))
			special[L++] = i*i;
	}

	printf("%d\n", L);
	for (int i = 0; i < L; i++)
		printf("%lld\n", special[i]);
	*/

	while (scanf("%lld", &N), N)
		printf("%d\n", (int)(upper_bound(special, special + L, N) - special));
}
