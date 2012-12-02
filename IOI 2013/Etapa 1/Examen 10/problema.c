#include <stdio.h>
#include <stdbool.h>

bool dp[20010];
int values[20010];
int N, sum;

int abs(int a){
	return a >= 0 ? a : -a;
}

int main(void){
	int i, j, diff;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d", &values[i]);
		sum += values[i];
	}

	for (i = 0; i < N; i++){
		for (j = 20000; j > values[i]; j--)
			dp[j] |= dp[j-values[i]];
		dp[values[i]] = true;
	}

	for (i = sum/2; i >= 0; i--)
		if (dp[i]) break;

	/*
	 * i+j = sum
	 * i-j = diff
	 * 2i = sum + diff
	 * diff = 2i - sum
	 */
	printf("%d\n", abs(2*i - sum));

	return 0;
}
