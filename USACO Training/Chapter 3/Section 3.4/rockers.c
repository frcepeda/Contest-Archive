/*
    ID: frceped1
    LANG: C
    TASK: rockers
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("rockers.in", "r", stdin); freopen("rockers.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 22

int M, T, N;
int length[MAXN];

int dp[MAXN][MAXN][MAXN];

int max(int a, int b, int c){
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int main(void){
	openFiles();

	int i, j, k;

	scanf("%d %d %d", &N, &T, &M);

	for (i = 1; i <= N; i++)
		scanf("%d", &length[i]);

	for (i = 1; i <= M; i++){
		for (j = 1; j <= N; j++){
			for (k = 0; k <= T; k++){
				if (k - length[j] >= 0)
					dp[i][j][k] = max(dp[i][j-1][k], dp[i][j-1][k - length[j]] + 1, dp[i-1][j-1][T] + 1);
				else
					dp[i][j][k] = dp[i][j-1][k];
			}
		}
	}

	printf("%d\n", dp[M][N][T]);

	return 0;
}
