#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 510

int n;
int c[MAXN];
int dp[MAXN][MAXN][2];
bool v[MAXN][MAXN][2];

int f(int i, int j, bool p){
	if (j < i) return 0;
	if (i == j) return !p;
	if (v[i][j][p]) return dp[i][j][p];

	v[i][j][p] = true;
	dp[i][j][p] = 1<<30;

	for (int q = 0; q <= p; q++)
		for (int k = i; k < j; k++)
			dp[i][j][p] = min(dp[i][j][p], f(i,k,q) + f(k+1,j,p-q));

	for (int k = 0; i+k <= j-k && c[i+k] == c[j-k]; k++)
		dp[i][j][p] = min(dp[i][j][p], (!p) + f(i+k+1, j-k-1, true));

	return dp[i][j][p];
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	printf("%d\n", f(0, n-1, false));
}
