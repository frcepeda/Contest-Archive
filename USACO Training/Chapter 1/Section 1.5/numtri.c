/*
    ID: frceped1
    LANG: C
    TASK: numtri
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("numtri.in", "r", stdin); freopen("numtri.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXTREE 1000

int size;
int tree[MAXTREE][MAXTREE];
int dp[MAXTREE][MAXTREE];

int max(int a, int b){ return a>b?a:b; }

int main(void){
	openFiles();

	int i,j;
	scanf("%d", &size);

	for (j = size - 1; j >= 0; j--)
		for (i = 0; i < size - j; i++)
			scanf("%d", &tree[i][j]);

	for (i = 0; i < size; i++)
		dp[i][0] = tree[i][0];

	for (j = 1; j < size; j++)
		for (i = 0; i < size - j; i++)
			dp[i][j] = max(dp[i][j-1], dp[i+1][j-1]) + tree[i][j];

	printf("%d\n", dp[0][size-1]);

	return 0;
}
