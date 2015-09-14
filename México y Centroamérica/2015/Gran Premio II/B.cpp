#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 200100
#define MAXC 32

int N, C;
int dp[MAXN][2];
int a[MAXN];

int main(){
	while (scanf("%d %d", &N, &C) == 2){
		int i, j;

		for (i = 0; i < N; i++)
			scanf("%d", &a[i]);

		dp[N][0] = 0;
		dp[N][1] = -(1<<30);

		for (i = N-1; i >= 0; i--){
			dp[i][0] = max(dp[i+1][0], dp[i+1][1] - C - a[i]);
			dp[i][1] = max(dp[i+1][1], dp[i+1][0] + a[i]);
		}

		printf("%d\n", dp[0][0]);
	}
}
