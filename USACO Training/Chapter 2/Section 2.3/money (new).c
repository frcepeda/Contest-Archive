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

long long int dp[MAXN];

int N, V;
int values[MAXV];

int main(void){
	openFiles();

	int i, j;

	scanf("%d %d", &V, &N);

	for (i = 0; i < V; i++)
		scanf("%d", &values[i]);

	dp[0] = 1;

	for (i = 0; i < V; i++){
		for (j = values[i]; j <= N; j++){
			dp[j] += dp[j-values[i]];
		}
	}

	printf("%lld\n", dp[N]);

	return 0;
}
