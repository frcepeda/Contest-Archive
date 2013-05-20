#include <stdio.h>

#define MAXN 100100

int M, N;
int map[MAXN];
int dp[MAXN];
int row[MAXN];

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int i, j;

	while (scanf("%d %d", &N, &M), N){
		dp[M+1] = dp[M] = 0;
		for (i = 0; i < N; i++){
			for (j = 0; j < M; j++)
				scanf("%d", &map[j]);

			for (j = M-1; j >= 0; j--)
				dp[j] = max(dp[j+2] + map[j], dp[j+1]);

			row[i] = dp[0];
		}

		dp[N+1] = dp[N] = 0;
		for (i = N-1; i >= 0; i--)
			dp[i] = max(row[i] + dp[i+2], dp[i+1]);

		printf("%d\n", dp[0]);
	}

	return 0;
}
