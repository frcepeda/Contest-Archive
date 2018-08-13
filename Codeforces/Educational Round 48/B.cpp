#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1010;
char s[maxn], t[maxn];
int dp[maxn][maxn];
int n, m, q;

int main(){
	scanf("%d %d %d", &n, &m, &q);
	scanf("%s %s", s, t);

	if (n >= m)
	for (int i = 0; i+m <= n; i++)
		if (strncmp(s+i, t, m) == 0)
			dp[i][i+m-1] = 1;

	for (int k = m+1; k <= n; k++)
		for (int i = 0; i+k <= n; i++){
			int j = i+k-1;
			dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
		}

	while (q--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a-1][b-1]);
	}
}
