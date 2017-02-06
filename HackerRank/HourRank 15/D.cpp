#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 2010;
const int maxl = 15;
const ll mod = 1000000007LL;
int n, q;
vector<int> adj[maxn];
int p[maxn][maxl], d[maxn];

void dfs(int x, int pp){
	d[x] = d[pp] + 1;
	p[x][0] = pp;
	
	for (auto v: adj[x]){
		if (v == pp) continue;
		dfs(v, x);
	}
}

int lca(int u, int v){
	if (d[u] < d[v]) swap(u, v);

	for (int i = maxl-1; i >= 0; i--)
		if (d[p[u][i]] >= d[v])
			u = p[u][i];

	if (u == v) return u;

	for (int i = maxl-1; i >= 0; i--)
		if (p[u][i] != p[v][i]){
			u = p[u][i];
			v = p[v][i];
		}

	return p[u][0];
}

ll dist(int u, int v){
	return d[u] + d[v] - 2 * d[lca(u,v)];
}

int main(){
	scanf("%d", &n);
	scanf("%d", &q);

	for (int i = 1; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 1);

	for (int l = 1; l < maxl; l++)
		for (int i = 1; i <= n; i++)
			p[i][l] = p[p[i][l-1]][l-1];

	while (q--){
		int k;
		vector<int> v;

		scanf("%d", &k);

		for (int i = 0; i < k; i++){
			int a;
			scanf("%d", &a);
			v.push_back(a);
		}

		long long ans = 0;

		for (int i = 0; i < k; i++)
			for (int j = i+1; j < k; j++)
				ans = (ans + v[i] * v[j] % mod * dist(v[i], v[j]) % mod + mod) % mod;

		printf("%lld\n", ans);
	}
}
