#include <stdio.h>

#define MAXN 105

int T, N;
int values[MAXN][MAXN];
int dp[MAXN][MAXN];

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int i, j;

	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				scanf("%d", &values[i][j]);

		for (i = 0; i < N; i++)
			dp[i][N] = dp[N][i] = -10000000;
		dp[N-1][N-1] = 0;

		for (i = N-1; i >= 0; i--){
			for (j = N-1; j >= 0; j--){
				if (i == N-1 && j == N-1) continue;

				dp[i][j] = max(dp[i][j+1], dp[i+1][j]) + values[i][j];
			}
		}

		if (dp[0][0] < 0)
			printf("Bad Judges\n");
		else
			printf("%.6lf\n", (double)dp[0][0] / (N + N - 3));
	}

	return 0;
}

