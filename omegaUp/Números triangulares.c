#include <stdio.h>

#define MOD 1019
#define MAXN 10010
#define MAXSQ 1000

int dp[MAXN][MAXSQ];
int N;

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < MAXSQ; i++)
		dp[0][i] = 1;

	for (i = 1; i <= N; i++)
		for (j = 1; j < MAXSQ; j++)
			dp[i][j] = ((i >= (j*(j+1))/2 ? dp[i - (j*(j+1))/2][j] : 0) + dp[i][j-1]) % MOD;

	printf("%d\n", dp[N][MAXSQ-1]);

	return 0;
}
