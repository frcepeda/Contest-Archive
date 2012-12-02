#include <stdio.h>

#define MAXN 1000010
#define MOD 1000000007

int dp[MAXN][2];
int N, answer;

int main(void){
	scanf("%d", &N);

	int i, j;

	dp[0][0] = dp[0][1] = 1;
	for (i = 1; i <= N; i++){
		for (j = 0; j <= 1; j++){
			dp[i][j] = dp[i-1][0];
			if (!j) dp[i][j] += dp[i-1][1];
			dp[i][j] %= MOD;
		}
	}
	answer = dp[N][0];

	dp[0][0] = 0;
	for (i = 1; i < N; i++){
		for (j = 0; j <= 1; j++){
			dp[i][j] = dp[i-1][0];
			if (!j) dp[i][j] += dp[i-1][1];
			dp[i][j] %= MOD;
		}
	}
	answer -= dp[N-1][1];

	while (answer < 0)
		answer += MOD;
	answer %= MOD;

	printf("%d\n", answer);

	return 0;
}

