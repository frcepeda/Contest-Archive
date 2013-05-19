#include <stdio.h>

#define MAXN 65
#define MAXNUM 10010

long long int dp[MAXNUM];
int T, N, A[MAXN];

int gcd(int a, int b){
	int c;
	while (b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void){
	int i, j;

	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);

		for (i = 0; i < N; i++)
			scanf("%d", &A[i]);
		A[N] = 0;

		for (i = 0; i < MAXNUM; i++)
			dp[i] = 0;

		for (i = 0; i < N; i++){
			dp[A[i]]++;
			for (j = 1; j < MAXNUM; j++)
				if (dp[j])
					dp[gcd(j,A[i+1])] += dp[j];
		}

		printf("%lld\n", dp[1]/2);
	}

	return 0;
}
