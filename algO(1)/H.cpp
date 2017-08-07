#include <cstdio>
#include <algorithm>

using namespace std;

int T, t;
int N, M;

const int maxn = 100100;

vector<int> adj[maxn];
bool type[maxn];

int dp[maxn][2], v[maxn][2];

int f(int n, bool x){
	if (v[n][x] == t) return dp[n][x];
	v[n][x] = t;

	int me = !x && type[n];
	dp[n][x] = me;

	for (auto v: adj[n])
		dp[n][x] = max(dp[n][x], me + f(v, type[n]));

	return dp[n][x];
}

int main(){
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d %d", &N, &M);

		for (int i = 0; i < N; i++){
			int tmp;
			scanf("%d", &tmp);
			type[i] = !!tmp;
			adj[i].clear();
		}

		while (M--){
			int a, b;
			scanf("%d %d", &a, &b);
			adj[b].push_back(a);
		}

		int ans = 0;

		for (int i = 0; i < N; i++)
			ans = max(ans, f(i, 0));

		printf("%d\n", ans);
	}
}
