#include <stdio.h>

#define MAXN 105

int grid[MAXN][MAXN];
int n, m, k;
int r, c;

int mod(int x, int m){
	if (x >= 0) return x % m;
	return -((-x) % m) + m;
}

int main(void){
	int i, j;

	scanf("%d %d %d", &n, &m, &k);

	while (k--){
		scanf("%d", &i);
		if (i == 1) r++;
		if (i == 2) r--;
		if (i == 3) c++;
		if (i == 4) c--;
	}

	r = mod(r, n);
	c = mod(c, m);

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &grid[i][j]);

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			printf("%d%c", grid[(i+r)%n][(j+c)%m], j != m-1 ? ' ' : '\n');

	return 0;
}
