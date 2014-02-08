#include <stdio.h>

#define MOD 1000000000
#define MAXK 1010
#define MAXS 9010

unsigned int dp[MAXK][MAXS];

int K, S;

int main(void){
	int i, j, k;

	scanf("%d %d", &K, &S);

	dp[0][0] = 1;

	for (i = 1; i <= K; i++)
		for (j = 0; j <= S; j++)
			for (k = 0; k <= 9 && j-k >= 0; k++)
				dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;

	printf("%d\n", dp[K][S]);

	return 0;
}
