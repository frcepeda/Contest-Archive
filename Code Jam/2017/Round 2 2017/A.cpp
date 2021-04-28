#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;
int T, N, P, G[maxn], C[maxn];
int dp[maxn][maxn][maxn][4];

int main(){
	scanf("%d", &T);

	for (int tt = 1; tt <= T; tt++){
		scanf("%d %d", &N, &P);

		int acc = 0;

		for (int i = 1; i <= N; i++){
			scanf("%d", &G[i]);
			acc += (G[i] + P - 1) / P;
			C[G[i] % P]++;
		}

		int t[4];
		for (t[1] = 0; t[1] <= G[1]; t[1]++)
		for (t[2] = 0; t[2] <= G[2]; t[2]++)
		for (t[3] = 0; t[3] <= G[3]; t[3]++)
		if (t[1] || t[2] || t[3])
		for (int k = 0; k < P; k++){
			dp[t[1]][t[2]][t[3]][k] = 1<<29;
			for (int j = 1; j < P; j++){
				if (!t[j]) continue;
				int l = (4 + k - j) % 4;
				int c = k < j;
				dp[t[1]][t[2]][t[3]][k] = min(
					dp[t[1]][t[2]][t[3]][k],
					dp[t[1]-(j==1)][t[2]-(j==2)][t[3]-(j==3)][l] + c
				);
			}
		}

		printf("Case #%d: %d\n", tt, acc + dp[G[1]][G[2]][G[3]][0]);
	}
}
