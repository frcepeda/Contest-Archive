#include <stdio.h>
#include <stdbool.h>

#define MAXN 110
#define OFF (100*100*10)

int max(int a, int b){ return a > b ? a : b; }

int dp[MAXN][OFF*2];
bool v[MAXN][OFF*2];
int n, k, a[MAXN], b[MAXN];

int f(int i, int d){
	if (i < 0)
		return d == 0 ? 0 : -1000000;
	if (v[i][d+OFF]) return dp[i][d+OFF];
	v[i][d+OFF] = true;
	return dp[i][d+OFF] = max(f(i-1, d), f(i-1, d + a[i] - k*b[i]) + a[i]);
}

int main(void){
	int i;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);

	i = f(n-1, 0);

	printf("%d\n", i ? i : -1);

	return 0;
}
