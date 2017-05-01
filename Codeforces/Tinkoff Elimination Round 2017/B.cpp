#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int n, m;
char g[maxn][maxn];
bool v[maxn][maxn][4][3];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

bool dfs(int r, int c, int d, int t){
	if (g[r][c] == 'T') return true;
	if (g[r][c] != '.') return false;

	if (v[r][c][d][t]) return false;
	v[r][c][d][t] = true;

	if (dfs(r + dr[d], c + dc[d], d, t))
		return true;

	if (t)
		for (int i = 0; i < 4; i++)
			if (dfs(r + dr[i], c + dc[i], i, t-1))
				return true;

	return false;
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%s", g[i]+1);

	int sr, sc;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (g[i][j] == 'S'){
				sr = i;
				sc = j;
				g[i][j] = '.';
			}

	bool works = false;

	for (int i = 0; i < 4 && !works; i++)
		works |= dfs(sr, sc, i, 2);

	printf("%s\n", works ? "YES" : "NO");
}
