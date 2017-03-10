#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 50100
#define MAXE 55

int N, E;
int D[MAXE][MAXE], dp[MAXN][MAXE];
bool v[MAXN][MAXE];
int color[MAXN];
vector<int> adj[MAXN];

int f(int x, int c, int p){
	if (v[x][c]) return dp[x][c];
	v[x][c] = true;

	for (auto y: adj[x]){
		if (y == p) continue;
		int m = 1<<30;
		for (int i = 1; i <= E; i++)
			if (!color[y] || i == color[y])
				m = min(m, f(y, i, x) + D[c][i]);
		dp[x][c] += m;
	}

	return dp[x][c];
}

int main(){
	scanf("%d %d", &N, &E);
	
	for (int i = 1; i <= E; i++)
		for (int j = 1; j <= E; j++)
			scanf("%d", &D[i][j]);

	for (int i = 1; i <= E; i++){
		int x, k;
		scanf("%d", &k);
		while (k--){
			scanf("%d", &x);
			color[x] = i;
		}
	}

	for (int i = 1; i < N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	adj[0].push_back(1);

	printf("%d\n", f(0, 0, -1));
}
