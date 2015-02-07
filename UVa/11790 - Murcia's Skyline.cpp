#include <cstdio>
#include <algorithm>

#define MAXN 2010

using namespace std;
int h[MAXN], w[MAXN], dp[MAXN][MAXN];
int N, T;

int f(){
	int i, j;
	
	for (i = 0; i <= N; i++)
		dp[N+1][i] = 0;
		
	for (i = N; i; i--)
		for (j = 0; j < i; j++)
			dp[i][j] = max(dp[i+1][j], h[i] > h[j] ? dp[i+1][i] + w[i] : -(1<<20));
	
	return dp[1][0];
}

int main() {
	scanf("%d", &T);
	
	h[0] = -(1<<20);
	for (int t = 1; t <= T; t++){
		int i, j;
		
		scanf("%d", &N);
		
		for (i = 1; i <= N; i++)
			scanf("%d", &h[i]);
		
		for (i = 1; i <= N; i++)
			scanf("%d", &w[i]);
		
		int inc = f();
		
		for (i = 1; i <= N; i++)
			h[i] = -h[i];
			
		int dec = f();
		
		if (inc >= dec)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", t, inc, dec);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", t, dec, inc);
	}
}