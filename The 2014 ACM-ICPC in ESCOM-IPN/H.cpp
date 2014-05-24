// Accepted
#include <cstdio>

int X, Y, N;
int d[50];
long long dp[7500];

int main(){
	while (true){
		int i, j;

		scanf("%d %d %d", &X, &Y, &N);
		if (X == 0 && Y == 0 && N == 0) break;

		for (i = 0; i <= 7000; i++)
			dp[i] = 0;

		for (i = 0; i < N; i++)
			scanf("%d", &d[i]);

		dp[7000] = 1;

		for (i = 6999; i >= 0; i--)
			for (j = 0; j < N; j++)
				if (d[j] - i >= X && d[j] - i <= Y)
					dp[i] += dp[d[j]];

		printf("%lld\n", dp[0]);
	}
}
