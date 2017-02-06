#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110, maxk = 5010;
int T, t, N, M, K;
int v[maxn][maxk][3], dp[maxn][maxk][3];
int d[maxn][maxn], S[maxk], D[maxk];

int f(int n, int x, int c){
	if (c < 0) return 1<<25;
	if (x == K) return 0;

	if (v[n][x][c] == t)
		return dp[n][x][c];

	v[n][x][c] = t;

	if (c == 0)
		dp[n][x][c] = f(S[x], x, 1) + d[n][S[x]];
	else {
		dp[n][x][c] = f(D[x], x+1, c-1) + d[n][D[x]];

		if (c != 2 && x+1 < K)
			dp[n][x][c] = min(
				dp[n][x][c],
				f(S[x+1], x, 2) + d[n][S[x+1]]
			);
	}

	dp[n][x][c] = min(dp[n][x][c], (1<<25));

	return dp[n][x][c];
}

int main(){
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				d[i][j] = i == j ? 0 : (1<<25);

		while (M--){
			int a, b, g;
			scanf("%d %d %d", &a, &b, &g);
			d[a][b] = d[b][a] = min(d[a][b], g);
		}

		for (int i = 0; i < K; i++)
			scanf("%d %d", &S[i], &D[i]);

		for (int k = 1; k <= N; k++)
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					d[i][j] = min(
						d[i][j],
						d[i][k] + d[k][j]
					);

		int ans = f(1, 0, 0);

		printf("Case #%d: %d\n", t, ans < (1<<25) ? ans : -1);
	}
}
