#include <stdio.h>

#define MAXN 155
#define INF (1<<27)

inline int max(int a, int b) { return a > b ? a : b; }

int N;
int dp[MAXN][MAXN][MAXN][2];
int a[MAXN];
char str[MAXN];

int main(void){
	int i, j, k, l, x;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	scanf("%s", str);

	for (i = 0; i <= N; i++)
		for (l = 0; l <= N; l++){
			if (i) dp[i][i-1][l][0] = dp[i][i-1][l][1] = a[l] != -1 ? a[l] : -INF;
			dp[i][i][l][0] = dp[i][i][l][1] = a[l+1] != -1 ? a[l+1] : -INF;
			dp[i][i][l][0] = max(dp[i][i][l][0], a[l] != -1 && a[1] != -1 ? a[l] + a[1] : -INF);
			dp[i][i][l][1] = max(dp[i][i][l][1], a[l] != -1 && a[1] != -1 ? a[l] + a[1] : -INF);
			if (!l) dp[i][i][0][0] = max(dp[i][i][0][0], 0);
		}

	for (j = 1; j < N; j++){
		for (i = 0; i+j < N; i++){
			for (l = 0; l < N; l++){
				for (k = 0; k <= 1; k++){
					dp[i][i+j][l][k] = k ? -INF : 0;

					if (l && a[l] != -1)
						dp[i][i+j][l][k] = max(dp[i][i+j][l][k], dp[i][i+j][0][k] + a[l]);

					for (x = i; x < i+j; x++){
						dp[i][i+j][l][k] = max(dp[i][i+j][l][k], dp[i][x][l][l||k] + dp[x+1][i+j][0][l||k]);
						dp[i][i+j][l][k] = max(dp[i][i+j][l][k], dp[i][x][0][l||k] + dp[x+1][i+j][l][l||k]);
					}

					if (str[i] == str[i+j])
						dp[i][i+j][l][k] = max(dp[i][i+j][l][k], dp[i+1][i+j-1][l+2][1]);
				}
			}
		}
	}

	printf("%d\n", dp[0][N-1][0][0]);

	return 0;
}
