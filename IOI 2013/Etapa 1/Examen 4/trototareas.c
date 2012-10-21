#include <stdio.h>

#define MAXS 210
#define MAXN 510

int dp[MAXS];
int value[MAXN], time[MAXN];

int N, S;

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int i, j;

	scanf("%d %d", &N, &S);

	for (i = 0; i < N; i++)
		scanf("%d %d", &value[i], &time[i]);

	for (i = 0; i < N; i++){
		for (j = MAXS-1; j > value[i]; j--){
			if (dp[j-value[i]]){
				if (dp[j])
					dp[j] = min(dp[j], dp[j-value[i]] + time[i]);
				else
					dp[j] = dp[j-value[i]] + time[i];
			}
		}

		if (dp[value[i]])
			dp[value[i]] = min(time[i], dp[value[i]]);
		else
			dp[value[i]] = time[i];
	}

	int best = 100000000;

	for (i = S; i < MAXS; i++){
		if (dp[i])
			best = min(best, dp[i]);
	}

	printf("%d\n", best);

	return 0;
}

