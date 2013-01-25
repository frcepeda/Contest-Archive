#include <stdio.h>
#include <stdbool.h>

#define MAXN 40

bool inUse[MAXN];
int dp[MAXN][MAXN];
int n, k, d;

int main(void){
	int i, j;

	scanf("%d", &d);

	while (d--){
		scanf("%d %d", &n, &k);
		n = n * 2;

		for (i = 0; i < MAXN; i++)
			inUse[i] = false;

		dp[n][0] = 1;
		for (i = 1; i < MAXN; i++)
			dp[n][i] = 0;

		for (i = 0; i < k; i++){
			scanf("%d", &j);
			inUse[j-1] = true;
		}
		
		for (i = n-1; i >= 0; i--){
			dp[i][0] = dp[i+1][1];

			for (j = 1; j < MAXN; j++){
				dp[i][j] = dp[i+1][j+1];
				if (!inUse[i])
					dp[i][j] += dp[i+1][j-1];
			}
		}

		printf("%d\n", dp[0][0]);
	}

	return 0;
}

