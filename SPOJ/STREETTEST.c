#include <stdio.h>

#define MAXN 510

int dp[MAXN];
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

	for (j = 0; j < K; j++){
		for (i = N; i > 0; i--){
			int minSoFar = 1<<28;
			for (k = i; k > 0 && i - k < T; k--){
				minSoFar = min(minSoFar, maxHeight[k]);
				dp[i] = max(dp[i], dp[k-1] + (i - k + 1) * minSoFar);
			}
		}

		for (i = 1; i <= N; i++)
			dp[i] = max(dp[i], dp[i-1]);
	}

	printf("%d\n", dp[N]);

	return 0;
}
