#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("optmilk.in", "r", stdin); freopen("optmilk.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 40010

int N, D;
int M[MAXN], dp[MAXN];

int max(int a, int b){ return a > b ? a : b; }

int main(void){
	int i, j, m, c;
	unsigned long long ans = 0;

	openFiles();
	
	scanf("%d %d", &N, &D);

	for (i = 1; i <= N; i++){
		scanf("%d", &M[i]);
		dp[i] = max(dp[i-1], dp[i-2] + M[i]);
	}

	while (D--){
		scanf("%d %d", &i, &m);

		M[i] = m;
		for (c = 2; c && i <= N; i++, c--){
			int d = max(dp[i-1], dp[i-2] + M[i]);

			if (d != dp[i]){
				dp[i] = d;
				c = 2;
			}
		}

		ans += dp[N];
	}

	printf("%llu\n", ans);

	return 0;
}
