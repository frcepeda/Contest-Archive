#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 110

int N;
bool g[MAXN][MAXN], v[MAXN][MAXN];

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

int dfs(int r, int c){
	if (r < 0 || c < 0 || r > 101 || c > 101) return 0;
	if (g[r][c]) return 1;
	if (v[r][c]) return 0;
	v[r][c] = true;
	int a = 0;
	for (int i = 0; i < 4; i++)
		a += dfs(r + dr[i], c + dc[i]);
	return a;
}

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		g[a][b] = true;
	}

	printf("%d\n", dfs(0,0));
}
