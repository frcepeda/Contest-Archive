#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 110
#define MAXQ 1010

int T;
int N, QL, X;
int E[MAXN], Q[MAXN], dp[MAXN][MAXQ];

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d %d %d", &N, &QL, &X);

		for (int i = 1; i <= N; i++)
			scanf("%d", &E[i]);
		for (int i = 1; i <= N; i++)
			scanf("%d", &Q[i]);

		for (int i = 0; i <= QL; i++)
			dp[0][i] = 0;

		for (int i = 1; i <= N; i++)
			for (int q = 0; q <= QL; q++){
				dp[i][q] = dp[i-1][q] + Q[i];
				if (q >= E[i])
					dp[i][q] = min(dp[i][q],
					               dp[i-1][q-E[i]]);
			}

		printf("%s-Man\n", dp[N][QL] <= X ? "Yes" : "No");
	}
}
