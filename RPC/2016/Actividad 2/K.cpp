#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100100

int t, T, N, M;
int v[MAXN][2], dp[MAXN][2];
vector<int> adj[MAXN];

int f(int n, bool p, int parent){
	if (v[n][p] == t)
		return dp[n][p];
	v[n][p] = t;

	int dp2[2][3] = {0};
	int i = 0, last = 0;
	for (auto x : adj[n]){
		if (x == parent) continue;

		dp2[i%2][0] = dp2[(i+1)%2][0] + f(x, false, n) + 1;

		for (int j = 1; j <= 2; j++)
			dp2[i%2][j] = min(dp2[(i+1)%2][j] + f(x, false, n) + 1,
			                  dp2[(i+1)%2][j-1] + f(x, true, n));

		last = i++;
	}

	return dp[n][p] = dp2[last%2][p ? 1 : 2];
}

int main(){
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d %d", &N, &M);

		for (int i = 1; i <= N; i++)
			adj[i].clear();

		for (int i = 0; i < M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int g = 0, ans = 0;
		for (int i = 1; i <= N; i++){
			if (v[i][0] != t && v[i][1] != t){
				g++;
				ans += f(i, false, -1);
			}
		}

		printf("%d\n", N + ans + g - 1);
	}
}
