#include <stdio.h>

#define MAXN 510

int n, m, k, s;
char map[MAXN][MAXN];

void dfs(int i, int j){
	if (i < 0 || j < 0 || i >= n || j >= m || map[i][j] != 'X' || !s) return;
	map[i][j] = '.';
	s--;
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1);
}

void start(void){
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (map[i][j] == 'X'){
				dfs(i,j);
				return;
			}
}

int main(void){
	int i, j;

	scanf("%d %d %d", &n, &m, &k);

	for (i = 0; i < n; i++)
		scanf("%s", map[i]);

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (map[i][j] == '.'){
				map[i][j] = 'X';
				s++;
			}
	s -= k;

	start();

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			printf("%c%s", map[i][j], j != m-1 ? "" : "\n");

	return 0;
}
