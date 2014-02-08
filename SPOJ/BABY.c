#include <stdio.h>
#include <stdlib.h>

#define MAXN 16
#define MAXB (1<<MAXN)

unsigned char bitCount[MAXB];
int dp[MAXB];
int T, N;
int source[MAXN], target[MAXN];

int min(int a, int b){ return a < b ? a : b; }

int main(void){
	int i, j;

	for (i = 1; i < MAXB; i++)
		bitCount[i] = bitCount[i ^ (i&-i)] + 1;

	while (scanf("%d", &N), N){
		for (i = 0; i < N; i++)
			scanf("%d", &source[i]);

		for (i = 0; i < N; i++)
			scanf("%d", &target[i]);

		for (i = 1; i < (1<<N); i++)
			for (j = 0, dp[i] = (1<<30); (1<<j) <= i; j++)
				if (i & (1<<j))
					dp[i] = min(dp[i],
					            dp[i^(1<<j)] + abs(bitCount[i]-j-1) + abs(source[j]-target[bitCount[i]-1]));

		printf("%d\n", dp[(1<<N) -1]);
	}

	return 0;
}
