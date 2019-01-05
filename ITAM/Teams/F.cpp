#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 55;
int n, m;
char g[maxn][maxn];
int v[maxn][maxn];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

bool dfs(int r, int c, int pr, int pc){
	if (v[r][c] == 2) return true;
	if (v[r][c]) return false;
	v[r][c] = 2;

	for (int k = 0; k < 4; k++){
		int nr = r + dr[k];
		int nc = c + dc[k];
		if (nr == pr && nc == pc)
			continue;
		if (g[r][c] == g[nr][nc] && dfs(nr, nc, r, c))
			return true;
	}

	v[r][c] = 1;
	return false;
}

bool go(){
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (dfs(i, j, i, j))
				return true;

	return false;
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%s", &g[i][1]);

	printf("%s\n", go() ? "Si" : "No");
}
