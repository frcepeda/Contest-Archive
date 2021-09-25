#include <cstdio>
#include <algorithm>

using namespace std;

const int maxr = 505;
int dp[maxr][maxr][maxr], tri[35];
int R, B;

int main(){
	for (int i = 1; tri[i-1] < maxr; i++)
		tri[i] = i * (i+1) /2;

	for (int i = 500; i > 0; i--)
	for (int r = 0; r <= 500; r++)
	for (int b = 0; b <= 500; b++)
		for (int k = 0; tri[k] <= b && (k+1)*i <= r; k++)
			dp[i][r][b] = max(dp[i][r][b], k+1 + dp[i+1][r - (k+1)*i][b - tri[k]]);

	for (int r = 0; r <= 500; r++)
	for (int b = 0; b <= 500; b++)
		for (int k = 0; tri[k] <= b; k++)
			dp[0][r][b] = max(dp[0][r][b], k + dp[1][r][b - tri[k]]);

	int T;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d %d", &R, &B);
		printf("Case #%d: %d\n", t, dp[0][R][B]);
	}
}
