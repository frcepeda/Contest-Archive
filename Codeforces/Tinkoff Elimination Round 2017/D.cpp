#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
const int INF = 1<<28;
int n, m, k;
int dp[maxn][maxn][maxn];
bool v[maxn][maxn][maxn];
int d[maxn][maxn];

int f(int x, int p, int r){
	if (r == 0) return 0;
	if (v[x][p][r]) return dp[x][p][r];
	v[x][p][r] = true;

	dp[x][p][r] = INF;

	int m = min(x, p);
	int M = max(x, p);

	for (int i = m+1; i < M; i++)
		if (d[x][i] != INF)
			dp[x][p][r] = min(
				dp[x][p][r],
				min(
				        f(i, x, r-1),
				        f(i, p, r-1)
				) + d[x][i]
			);

	return dp[x][p][r];
}

int main(){
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = INF;

	scanf("%d", &m);

	for (int i = 0; i < m; i++){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		d[u][v] = min(d[u][v], c);
	}

	int ans = f(0, n+1, k);

	printf("%d\n", ans != INF ? ans : -1);
}
