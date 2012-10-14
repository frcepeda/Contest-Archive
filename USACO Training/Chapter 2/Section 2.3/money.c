/*
    ID: frceped1
    LANG: C
    TASK: money
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("money.in", "r", stdin); freopen("money.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXV 30
#define MAXN 10010

long long int dp[MAXV][MAXN];

int N, V;
int values[MAXV];

int main(void){
	openFiles();

	int i, j;

	scanf("%d %d", &V, &N);

	for (i = 1; i <= V; i++)
		scanf("%d", &values[i]);

	dp[0][0] = 1;

	for (i = 1; i <= V; i++){
		dp[i][0] = 1;
		for (j = 1; j <= N; j++){
			if (values[i] <= j){
				dp[i][j] = dp[i-1][j] + dp[i][j-values[i]];
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	printf("%lld\n", dp[V][N]);

	return 0;
}
