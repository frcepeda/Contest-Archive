#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1010
#define INF (1<<30)

int dp[MAXN][8];
int map[MAXN][3];
int n, t = 0;

int main(){
	while (scanf("%d", &n), t++, n){
		int i, j;

		for (i = 0; i < 3; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &map[j][i]);

		for (i = 0; i < 8; i++)
			dp[n][i] = dp[n+1][i] = -INF;
		dp[n][0] = 0;

		for (i = n-1; i >= 0; i--){
			for (j = 0; j < 8; j++){
				int hor[3];
				for (int k = 0; k < 3; k++) hor[k] = map[i][k] * map[i+1][k];
				int ver[2] = {map[i][0] * map[i][1], map[i][1] * map[i][2]};

				dp[i][j] = dp[i+1][0];

				if (!j){
					dp[i][j] = max(dp[i][j], dp[i+1][8] + hor[0] + hor[1] + hor[2]);
					dp[i][j] = max(dp[i][j], dp[i+1][4] + ver[0] + hor[2]);
					dp[i][j] = max(dp[i][j], dp[i+1][1] + ver[1] + hor[0]);
				}

				if (!(j & 1))
					dp[i][j] = max(dp[i][j], dp[i+1][1] + hor[0]);

				if (!(j & 2))
					dp[i][j] = max(dp[i][j], dp[i+1][2] + hor[1]);

				if (!(j & 4))
					dp[i][j] = max(dp[i][j], dp[i+1][4] + hor[2]);

				if (!(j & 5))
					dp[i][j] = max(dp[i][j], dp[i+1][5] + hor[0] + hor[2]);

				if (!(j & 3)){
					dp[i][j] = max(dp[i][j], dp[i+1][3] + hor[0] + hor[1]);
					dp[i][j] = max(dp[i][j], dp[i+1][0] + ver[0]);
				}

				if (!(j & 6)){
					dp[i][j] = max(dp[i][j], dp[i+1][6] + hor[1] + hor[2]);
					dp[i][j] = max(dp[i][j], dp[i+1][0] + ver[1]);
				}
			}
		}

		printf("Case %d: %d\n", t, dp[0][0]);
	}
}
