#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1005;
int dp[maxn][maxn][2];
int n, a[maxn];

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n+1; j++)
			for (int k = 0; k < 2; k++){
				dp[i][j][k] = dp[i-1][j][k];

				if (j == n+1 || (k && a[i] > a[j]) || (!k && a[i] < a[j]))
					dp[i][j][k] = max(dp[i][j][k], dp[i-1][i][1-k] + 1);

				ans = max(ans, dp[i][j][k]);
			}


	printf("%d\n", ans);
}
