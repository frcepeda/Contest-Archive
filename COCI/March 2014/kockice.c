// 100/100 points
#include <stdio.h>

#define MAXN 300100

int N;
long long a[MAXN], b[MAXN];

long long _abs(long long x){ return x >= 0 ? x : -x; }

long long f(long long pivot){
	long long ret = _abs(a[N/2] - pivot) + _abs(b[N/2] - pivot);
	int i;

	for (i = 1; i <= N/2; i++)
		ret += _abs(a[N/2-i] - (pivot + i)) + _abs(a[N/2+i] - (pivot + i)) + _abs(b[N/2-i] - (pivot + i)) + _abs(b[N/2+i] - (pivot + i));

	return ret;
}

int main(void){
	int i;
	
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%lld", &a[i]);
	for (i = 0; i < N; i++)
		scanf("%lld", &b[i]);

	long long lo = 0, hi = 1LL<<60, mid;

	while (lo < hi){
		mid = (lo + hi) / 2;

		if (f(mid) > f(mid+1))
			lo = mid + 1;
		else
			hi = mid;
	}

	printf("%lld\n", f(hi));

	return 0;
}
