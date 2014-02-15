// 0/0 points :(
#include <stdio.h>

#define MAXN 1005

long long dp[MAXN][MAXN];
int N, K;
int grid[MAXN][3];

long long max(long long a, long long b) { return a > b ? a : b; }
long long max3(long long a, long long b, long long c) { return a > b ? (a > c ? a : c) : (b > c ? b : c); }
long long min(long long a, long long b) { return a < b ? a : b; }
long long min3(long long a, long long b, long long c) { return a < b ? (a < c ? a : c) : (b < c ? b : c); }

int main(void){
	int i, j;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &grid[i][j]);

	for (j = 0; j <= K; j++)
		dp[N][j] = dp[N+1][j] = -(1LL << 50);
	dp[N][0] = 0;

	for (i = N-1; i >= 0; i--){
		for (j = 0; j <= K; j++){
			long long block = grid[i][0] + grid[i][1] + grid[i][2] + grid[i+1][0] + grid[i+1][1] + grid[i+1][2];
			dp[i][j] = dp[i+1][j];

			if (j >= 1){
				dp[i][j] = max(dp[i][j], max(
						dp[i+1][j-1] + grid[i][1] + max( 
							grid[i][0],
							grid[i][2]
						),
						dp[i+2][j-1] + max3(
							grid[i][0] + grid[i+1][0],
							grid[i][1] + grid[i+1][1],
							grid[i][2] + grid[i+1][2]
						)
						));
			}
			
			if (j >= 2){
				dp[i][j] = max3(dp[i][j],
						dp[i+2][j-2] + block - min3(
							grid[i][0] + grid[i+1][0],
							grid[i][1] + grid[i+1][1],
							grid[i][2] + grid[i+1][2]
						),
						dp[i+2][j-2] + block - min(
							min(
								grid[i][0] + grid[i][1],
								grid[i+1][0] + grid[i+1][1]
							), min(
								grid[i][1] + grid[i][2],
								grid[i+1][1] + grid[i+1][2]
							)
						));
			}
			
			if (j >= 3)
				dp[i][j] = max(dp[i][j], dp[i+2][j-3] + block);
		}
	}

	printf("%lld\n", dp[0][K]);

	return 0;
}
