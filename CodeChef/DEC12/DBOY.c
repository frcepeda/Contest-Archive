#include <stdio.h>

#define MAXN 510
#define MAXDIST MAXN*2

int dp[MAXDIST];
int fuel[MAXN];
int dist[MAXN];
int T, N;

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int i, j, answer;

	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);

		for (i = 0; i < N; i++)
			scanf("%d", &dist[i]);

		for (i = 0; i < N; i++)
			scanf("%d", &fuel[i]);

		for (i = 0; i < MAXDIST; i++)
			dp[i] = 0;

		for (i = 0; i < N; i++){
			dp[fuel[i]] = 1;
			for (j = fuel[i]+1; j < MAXDIST; j++){
				if (dp[j-fuel[i]]){
					if (dp[j])
						dp[j] = min(dp[j], dp[j-fuel[i]] + 1);
					else
						dp[j] = dp[j-fuel[i]] + 1;
				}
			}
		}

		answer = 0;
		for (i = 0; i < N; i++)
			answer += dp[dist[i]*2];

		printf("%d\n", answer);
	}

	return 0;
}

