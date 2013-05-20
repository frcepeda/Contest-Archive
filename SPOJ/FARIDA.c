#include <stdio.h>

#define MAXN 1010

unsigned long long int dp[MAXN];
int T, N;

unsigned long long int max(unsigned long long int a, unsigned long long int b){
	return a > b ? a : b;
}

int main(void){
	int i, t;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d", &N);

		for (i = 0; i < N; i++){
			int k;
			scanf("%d", &k);
			dp[i] = max(k + (i > 1 ? dp[i-2] : 0), i > 0 ? dp[i-1] : 0);
		}

		printf("Case %d: %llu\n", t, dp[N-1]);
	}

	return 0;
}
