#include <stdio.h>

#define MOD 1000
#define MAXDP 2000
#define N 11

int weight[N] = {2,5,14,17,19,13,1,3,5,11,19};
int value[N] = {57,191,417,231,741,139,28,117,13,9,18};

int dp[MAXDP];

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int i, j;

	for (i = 0; i < MAXDP; i++)
		for (j = 0; j < N; j++)
			if (i - weight[j] >= 0)
				dp[i] = max(dp[i], dp[i-weight[j]] + value[j]);

	printf("%d\n", (dp[1739] + dp[72] + dp[212] + dp[55] + dp[511] + dp[1239] + dp[99]) % MOD);

	return 0;
}
