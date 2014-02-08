#include <stdio.h>

#define MAXN 10005
#define MAXS 105
#define MAXK 6

int dp[MAXN][MAXS][MAXK];
int N, K, R;

int intsqrt(int i){
	int lo = 0, hi = i/2, mid;

	while (lo < hi){
		mid = (lo + hi)/2;
		if (mid * mid <= i)
			lo = mid + 1;
		else
			hi = mid;
	}

	return lo - 1;
}

int main(void){
	int i, j, k;

	scanf("%d %d %d", &N, &K, &R);
	R--;

	for (i = 1; i <= 100; i++)
		for (j = i; j >= 0; j--)
			dp[i*i][j][0] = 1;

	for (k = 1; k < K; k++)
		for (i = 0; i < MAXN; i++)
			for (j = intsqrt(i); j > 0; j--)
				dp[i][j][k] = dp[i - j*j][j][k-1] + dp[i][j+1][k];

	for (k = K-1, i = 1; k >= 0; k--){
		for (; dp[N][i][k] - dp[N][i+1][k] <= R; i++)
			R -= dp[N][i][k] - dp[N][i+1][k];

		N -= i * i;

		printf("%d^2%c", i, k ? '+' : '\n');
	}

	return 0;
}
