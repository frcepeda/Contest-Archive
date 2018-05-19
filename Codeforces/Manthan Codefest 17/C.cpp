#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 100100;
const int maxx = 11;
int n, m, K, x;
int p[maxn], r[maxn], d[maxn];
int dp[maxn][maxx][2][2][2];
bool v[maxn][maxx][2][2][2];
ll MOD = 1000000007;

vector<int> adj[maxn];

void dfs(int a, int b){
	p[a] = b;
	d[a] = -1;

	int pp = -1;
	for (auto w : adj[a]){
		if (w == b) continue;
		r[w] = pp;
		pp = w;
		d[a] = w;

		dfs(w, a);
	}
}

ll f(int i, int j, bool k, bool l, bool pp){
	if (i == -1) return j == 0 && k == l;
	if (j < 0) return 0;

	if (v[i][j][k][l][pp])
		return dp[i][j][k][l][pp];
	v[i][j][k][l][pp] = true;

	ll tmp = 0;

	for (int w = 0; k && w <= j-1; w++)
		tmp = (tmp + f(r[i], w, k, true, pp) * f(d[i], j-1-w, false, false, true)) % MOD;

	for (int w = 0; w <= j; w++){
		tmp = (tmp + ((pp?K:m)-1) * f(r[i], w, k, l, pp) % MOD * f(d[i], j-w, false, false, false)) % MOD;
		tmp = (tmp + (K-1) * f(r[i], w, k, l, pp) % MOD * f(d[i], j-w, true, false, false)) % MOD;
	}

	return dp[i][j][k][l][pp] = tmp;
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 1; i < n; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	r[1] = -1;
	dfs(1, -1);

	scanf("%d %d", &K, &x);

	ll ans = 0;
	for (int i = 0; i <= x; i++)
		ans = (ans + f(1, i, 0, 0, 0) + f(1, i, 1, 0, 0)) % MOD;

	printf("%lld\n", ans);
}
