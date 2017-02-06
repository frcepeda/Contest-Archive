#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;

#define mp make_pair

typedef pair<int,int> pii;
const int maxn = 15;
vector<pii> adj[maxn];

const ll MOD = 1000000009;

bool v[maxn];

ll inv(ll x){
	ll r = 1, e = MOD-2;

	for (; e; e /= 2){
		if (e % 2)
			r = (r * x) % MOD;
		x = (x * x) % MOD;
	}

	return r;
}

int f(int x, int acc, int p){
	int ret = acc;

	for (auto y: adj[x]){
		if (v[y.first] or y.first == p) continue;
		ret += f(y.first, acc + y.second, x);
	}

	return ret;
}

ll dfs(int d){
	if (d == n) return 0;

	ll ans = 0;
	for (int i = 1; i <= n; i++){
		if (!v[i]){
			ans = (ans + f(i, 0, -1)) % MOD;
			v[i] = true;
			ans = (ans + dfs(d + 1)) % MOD;
			v[i] = false;
		}
	}

	ans *= inv(n - d);

	return ans % MOD;
}

int main(){
	cin >> n;

	for (int i = 1; i < n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(mp(v, w));
		adj[v].push_back(mp(u, w));
	}

	ll ans = dfs(0);

	for (int i = 1; i <= n; i++)
		ans = (ans * i) % MOD;
	
	cout << ans << endl;
}
