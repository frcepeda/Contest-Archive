#include <stdio.h>

#define MAXN 33

int D;
int dice[MAXN];

long long int dp[MAXN];

int intCmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(void){
	int i, j;
	long long int ans = 0;

	scanf("%d", &D);

	for (i = 0; i < D; i++)
		scanf("%d", &dice[i]);

	qsort(dice, D, sizeof(int), intCmp);

	for (i = 1; i < MAXN; i++)
		dp[i] = 1;

	for (i = 0; i < D; i++)
		for (j = 1; j < MAXN; j++)
			dp[j] = j <= dice[i] ? dp[j] + dp[j-1] : dp[j-1];

	printf("%lld\n", dp[dice[D-1]]);

	return 0;
}
