#include <stdio.h>
#include <stdlib.h>

#define MAXN 1010

long long int dp[MAXN][MAXN];
int x[MAXN], y[MAXN];

int n, m;

long long int min(long long int a, long long int b){
	return a < b ? a : b;
}

int intRevCmp(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

int main(void){
	int i, j;

	scanf("%d %d", &m, &n);
	m--, n--;

	for (i = 0; i < m; i++)
		scanf("%d", &x[i]);

	for (i = 0; i < n; i++)
		scanf("%d", &y[i]);

	qsort(x, m, sizeof(int), intRevCmp);
	qsort(y, n, sizeof(int), intRevCmp);

	for (i = m; i >= 0; i--)
		for (j = n; j >= 0; j--)
			if (i != m || j != n)
				dp[i][j] = min(i < m ? dp[i+1][j] + x[i] * (j+1) : (1LL<<55),
					       j < n ? dp[i][j+1] + y[j] * (i+1) : (1LL<<55));

	printf("%lld\n", dp[0][0]);

	return 0;
}
