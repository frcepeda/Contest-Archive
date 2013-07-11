#include <stdio.h>

#define MOD 1000
#define P 6
#define N 300

int prices[P] = {1,5,20,50,100,200};
int dp[N+1];

int main(void){
	int i, j;

	dp[0] = 1;

	for (j = 0; j < P; j++)
		for (i = 1; i <= N; i++)
			if (i - prices[j] >= 0)
				dp[i] = (dp[i] + dp[i - prices[j]]) % MOD;

	printf("%d\n", dp[N]);

	return 0;
}
