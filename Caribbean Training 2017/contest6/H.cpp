// Accepted
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 505;
int n, K;
int acc[maxn][maxn], optv[maxn][maxn], opt[maxn][maxn], dp[maxn][maxn][2];
bool u[maxn];

int main(){
	scanf("%d %d", &n, &K);

	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			scanf("%d", &acc[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = n; j >= 1; j--)
			acc[i][j] += acc[i-1][j] + acc[i][j+1] - acc[i-1][j+1];

	for (int k = 1; k <= K; k++){
		if (k != 1)
			for (int j = n-1; j >= 0; j--)
				dp[n][j][0] = dp[n][j][1] = -(1<<28);
		else
			for (int j = n-1; j >= 0; j--){
				dp[n][j][0] = 0;
				dp[n][j][1] = -(1<<28);
			}

		for (int j = n-2; j >= 0; j--){
			for (int i = n-1; i > j; i--){
				int l = dp[i+1][j][k%2];
				int r = dp[i+1][i][(k+1)%2] + acc[i][i+1] - acc[j][i+1];

				if (l <= r){
					dp[i][j][k%2] = r;
					if (optv[j][k] <= r){
						optv[j][k] = r;
						opt[j][k] = i;
					}
				} else dp[i][j][k%2] = l;
			}
		}
	}

	printf("%d\n", dp[1][0][K%2]);

	for (int i = K, p = 0; i > 0; p = opt[p][i--])
		printf("%d%c", opt[p][i], i > 1 ? ' ' : '\n');
}
