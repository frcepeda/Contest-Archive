#include <stdio.h>

#define MAXN 101

int grid[MAXN][MAXN];
int w, h, T;

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int i, j;

	scanf("%d", &T);

	while (T--){
		scanf("%d %d", &h, &w);

		for (i = 1; i <= h; i++)
			grid[i][w+1] = 0;

		for (i = 1; i <= h; i++)
			for (j = 1; j <= w; j++)
				scanf("%d", &grid[i][j]);

		for (i = h-1; i > 0; i--)
			for (j = 1; j <= w; j++)
				grid[i][j] += max(max(grid[i+1][j-1], grid[i+1][j]), grid[i+1][j+1]);

		j = 0;
		for (i = 1; i <= w; i++)
			j = max(j, grid[1][i]);

		printf("%d\n", j);
	}

	return 0;
}
