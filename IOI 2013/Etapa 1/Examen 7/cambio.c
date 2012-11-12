#include <stdio.h>

#define MAXN 100
#define MAXC 10010

int N, C;
int values[MAXN];
int dp[MAXC];

int main(void){
	int i, j;

	scanf("%d %d", &C, &N);

	for (i = 0; i < N; i++)
		scanf("%d", &values[i]);

	dp[0] = 1;

	for (i = 0; i < N; i++){
		for (j = values[i]; j <= C; j++){
			dp[j] += dp[j-values[i]];
			dp[j] %= 987654321;
		}
	}

	printf("%d\n", dp[C]);

	return 0;
}
