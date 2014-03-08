// 84/140 points
#include <stdio.h>

#define MAXN 10
#define MAXM 23

long long dp[2][1<<MAXM];
int N, K, M;

int main(void){
	int i, j, k;

	scanf("%d %d %d", &N, &K, &M);

	for (i = 1; i <= 26; i++)
		dp[0][i] = 1;

	for (i = 0; i < N-1; i++){
		for (j = 0; j < (1<<M); j++)
			dp[(i+1)&1][j] = 0;

		for (j = 0; j < (1<<M); j++)
			for (k = 1; k <= 26; k++)
				dp[(i+1)&1][((j*33) ^ k) % (1<<M)] += dp[i&1][j];
	}

	printf("%lld\n", dp[(N-1)&1][K]);

	return 0;
}
