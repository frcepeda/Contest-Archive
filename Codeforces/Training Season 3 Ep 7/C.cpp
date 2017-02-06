#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
const int maxn = 210;
int deg[maxn];
const long long M = 1000000007;
long long c[maxn][maxn];
bool adj[maxn][maxn];

long long choose(int a, int b){
	if (b > a) return 0;
	if (a < 0) return 0;
	return c[a][b];
}

int main(){
	cin >> n >> m;

	for (int i = 0; i < maxn; i++){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % M;
	}

	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		deg[a]++; deg[b]++;
		adj[a][b] = adj[b][a] = true;
	}

	long long ans = 0;

	for (int i = 1; i <= n; i++)
		deg[i]--;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (!adj[i][j]) continue;

			int tri = 0;
			for (int k = 1; k <= n; k++)
				tri += adj[i][k] && adj[k][j];

			ans += choose(deg[i] - tri, 3) * choose(deg[j], 2) % M;
			ans %= M;
			ans += tri * choose(deg[i] - tri, 2) % M
			       * choose(deg[j] - 1, 2) % M;
			ans %= M;
			ans += choose(tri, 2) * (deg[i] - tri) % M
			       * choose(deg[j] - 2, 2) % M;
			ans %= M;
			ans += choose(tri, 3) * choose(deg[j] - 3, 2) % M;
			ans %= M;

			//cout << i << ' ' << j << ' ' << ans << endl;
		}
	}

	cout << ans << endl;
}
