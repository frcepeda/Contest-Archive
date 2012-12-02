#include <stdio.h>

#define MAXN 1010
#define MAXVOL (3000*30 + 100)

int dp[MAXVOL];

int dish[MAXN];

int N, M, totalCapacity;

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int i, j, best = 0;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		scanf("%d", &dish[i]);

	for (i = 0; i < M; i++){
		scanf("%d", &j);
		totalCapacity += j;
	}

	for (i = 0; i < N; i++){
		for (j = totalCapacity; j > dish[i]; j--)
			if (dp[j - dish[i]])
				dp[j] = max(dp[j], dp[j - dish[i]] + 1);
		dp[dish[i]] = max(dp[dish[i]], 1);
	}

	for (i = totalCapacity; i >= 0; i--)
		if(dp[i] > dp[best])
			best = i;

	printf("%d %d", dp[best], best);

	return 0;
}

