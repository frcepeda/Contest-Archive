#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 10010

int N, X, S[MAXN];
int T, t;
int dp[MAXN][MAXN], vis[MAXN][MAXN];

int f(int i, int j){
	if (vis[i][j] == t) return dp[i][j];
	if (i > j) return 0;
	if (i == j) return 1;
	vis[i][j] = t;
	return dp[i][j] = min(f(i+1,j), min(f(i,j-1), S[i] + S[j] <= X ? f(i+1,j-1) : 100000000)) + 1;
}

int main(){
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int i;

		scanf("%d %d", &N, &X);

		for (i = 0; i < N; i++)
			scanf("%d", &S[i]);

		sort(S, S+N);

		printf("Case #%d: %d\n", t, f(0,N-1));
	}
}
