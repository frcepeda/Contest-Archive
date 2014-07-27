#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long int ans[100000];
int ansCount;
int n;

int ullcmp(unsigned long long int *x, unsigned long long int *y){
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}

long long int intsqrt(unsigned long long int x){
	unsigned long long int lo = 0, hi = 4294967296ULL, mid;
	while (lo < hi){
		mid = (lo + hi) / 2;
		if (mid * mid >= x)
			hi = mid;
		else
			lo = mid + 1;
	}
	return mid * mid == x ? mid : -1;
}

void doStuff(long long int y){
	long long int den = intsqrt((2*y-3)*(2*y-3)+8*n);
	if (den == -1) return;
	long long int tmp = -2*y + 3 + den;
	if (tmp > 0 && tmp % 2 == 0 && tmp/2 <= ULONG_MAX/y)
		ans[ansCount++] = tmp/2 * y;
	tmp = -2*y + 3 - den;
	if (tmp > 0 && tmp % 2 == 0 && tmp/2 <= ULONG_MAX/y)
		ans[ansCount++] = tmp/2 * y;
}

int main(void){
	int i;

	scanf("%d", &n);

	for (i = 0; i < 62; i++)
		doStuff(1LL<<i);

	qsort(ans, ansCount, sizeof(ans[0]), ullcmp);
	for (i = 0; i < ansCount; i++)
		if (i == 0 || ans[i] != ans[i-1])
			printf("%llu\n", ans[i]);

	if (ansCount == 0)
		printf("-1\n");

	return 0;
}
