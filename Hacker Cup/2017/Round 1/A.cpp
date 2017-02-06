#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 303;
int T, N, M, C[maxn][maxn], v[maxn][maxn], dp[maxn][maxn], t;

int f(int i, int j){
	if (j < 0) return 1<<29;
	if (i == N) return 0;

	if (v[i][j] == t) return dp[i][j];
	v[i][j] = t;

	int acc = 0;
	dp[i][j] = f(i+1, j-1);

	for (int k = 0; k < M; k++){
		acc += C[i][k];
		dp[i][j] = min(
			dp[i][j],
			f(i+1, j+k) + acc + (k+1)*(k+1)
		);
	}

	return dp[i][j];
}

int main(){
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d %d", &N, &M);

		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++)
				scanf("%d", &C[i][j]);
			sort(C[i], C[i] + M);
		}

		printf("Case #%d: %d\n", t, f(0, 0));
	}
}
