#include <stdio.h>

#define MAXN 100010
#define INF (1<<30)

int dp[2][6];
int cost[MAXN][3];
int T, N;

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int t, i, j;

	for (t = 1; scanf("%d", &N), N; t++){ 
		for (i = 0; i < N; i++)
			for (j = 0; j < 3; j++)
				scanf("%d", &cost[i][j]);

		dp[(N-1)%2][2] = INF;
		dp[(N-1)%2][1] = cost[N-1][1];
		dp[(N-1)%2][0] = cost[N-1][0] + cost[N-1][1];

		for (i = N-2; i >= 0; i--){
			for (j = 2; j >= 0; j--){
				dp[i%2][j] = dp[(i+1)%2][j];

				if (j < 2){
					dp[i%2][j] = min(dp[i%2][j], dp[i%2][j+1]);
					dp[i%2][j] = min(dp[i%2][j], dp[(i+1)%2][j+1]);
				}

				if (j > 0)
					dp[i%2][j] = min(dp[i%2][j], dp[(i+1)%2][j-1]);

				dp[i%2][j] += cost[i][j];
			}
		}

		printf("%d. %d\n", t, dp[0][1]);
	}

	return 0;
}
