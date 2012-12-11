#include <stdio.h>

#define MAXN 205

int grid[MAXN][MAXN];
int R, C, S;

#define rectSize(a,b,c,d) (grid[c][d] - grid[c][b-1] - grid[a-1][d] + grid[a-1][b-1])

int main(void){
	int i, j, answer = 0;

	scanf("%d %d %d", &R, &C, &S);
	
	for (i = 1; i <= R; i++)
		for (j = 1; j <= C; j++)
			scanf("%d", &grid[i][j]);

	for (i = 1; i <= R; i++)
		for (j = 2; j <= C; j++)
			grid[i][j] += grid[i][j-1];

	for (i = 2; i <= R; i++)
		for (j = 1; j <= C; j++)
			grid[i][j] += grid[i-1][j];

	for (i = 1; i <= R; i++){
		for (j = i; j <= R; j++){
			int a, b;
			a = b = 1;

			while (a <= C && b <= C){
				int size = rectSize(i,a,j,b);

				if (size == S)
					answer++;

				if ((b == C || size >= S) && a < b)
					a++;
				else
					b++;
			}
		}
	}

	printf("%d\n", answer);

	return 0;
}
