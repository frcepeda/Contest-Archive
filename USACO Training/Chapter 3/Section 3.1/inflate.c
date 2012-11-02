/*
    ID: frceped1
    LANG: C
    TASK: inflate
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("inflate.in", "r", stdin); freopen("inflate.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 10010

int time[MAXN];
int points[MAXN];
int dp[MAXN];

int N, M;

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	openFiles();

	int i, j;

	scanf("%d %d", &M, &N);

	for (i = 0; i < N; i++)
		scanf("%d %d", &points[i], &time[i]);

	for (i = 0; i < N; i++)
		for (j = time[i]; j <= M; j++)
			dp[j] = max(dp[j], dp[j-time[i]] + points[i]);

	printf("%d\n", dp[M]);

	return 0;
}
