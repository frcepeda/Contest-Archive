/*
    ID: frceped1
    LANG: C
    TASK: range
 */

#include <stdio.h>
#include <ctype.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("range.in", "r", stdin); freopen("range.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 252

int grid[MAXN][MAXN];
int N;

int count[MAXN];

#define actualCount(a,b,c,d) grid[c][d] + grid[a-1][b-1] - grid[a-1][d] - grid[c][b-1]

int main(void){
	openFiles();

	int i, j, k;

	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			do {
				grid[i][j] = getchar();
			} while (!isdigit(grid[i][j]));
			grid[i][j] -= '0';
			if (j)
				grid[i][j] += grid[i][j-1];
		}
	}

	for (i = 2; i <= N; i++)
		for (j = 1; j <= N; j++)
			grid[i][j] += grid[i-1][j];

	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			for (k = 2; i+k <= N+1 && j+k <= N+1; k++){
				if (actualCount(i,j,i+k-1,j+k-1) == k*k)
					count[k]++;
				else break;
			}
		}
	}


	for (i = 2; i <= N; i++)
		if (count[i])
			printf("%d %d\n", i, count[i]);

	return 0;
}
