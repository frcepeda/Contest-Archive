#include <stdio.h>

#define MAXN 510

int dp[MAXN][MAXN];
int maxHeight[MAXN];

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

int N, K, T;

int main(void){
	int i, j, k;

	scanf("%d %d %d", &N, &K, &T);

	for (i = 1; i <= N; i++)
		scanf("%d", &maxHeight[i]);

	for (i = 1; i <= N; i++){
		for (j = 1; j <= K; j++){
			int minSoFar = 1<<30;
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			for (k = i; k > 0 && i - k < T; k--){
				minSoFar = min(minSoFar, maxHeight[k]);
				dp[i][j] = max(dp[i][j], dp[k-1][j-1] + (i - k + 1) * minSoFar);
			}
		}
	}

	printf("%d\n", dp[N][K]);

	return 0;
}
