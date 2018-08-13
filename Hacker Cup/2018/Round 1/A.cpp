#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1010;
int T, N;
ll dp[3][maxn];
char m[3][maxn];

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d", &N);

		for (int i = 0; i < 3; i++)
			scanf("%s", m[i]);

		dp[2][N] = 1;
		dp[1][N] = dp[0][N] = 0;

		for (int i = N-1; i >= 0; i--){
			dp[0][i] = dp[1][i] = dp[2][i] = 0;

			if (m[0][i] == '.' && m[1][i] == '.')
				dp[0][i] = dp[1][i+1];

			if (m[2][i] == '.' && m[1][i] == '.')
				dp[2][i] = dp[1][i+1];

			if (m[0][i] == '.' && m[1][i] == '.')
				dp[1][i] = dp[0][i+1];

			if (m[2][i] == '.' && m[1][i] == '.')
				dp[1][i] = (dp[1][i] + dp[2][i+1]) % 1000000007;
		}

		printf("Case #%d: %lld\n", t, dp[0][0]);
	}
}
