#include <cstdio>

#define MAXT 10010
#define MAXN 110

int f, t, n;
int l[MAXN];
bool dp[MAXT][MAXN];

bool works(){
	int i, j;

	for (j = 0; j <= t; j++)
		dp[j][n] = true;

	for (i = n-1; i >= 0; i--)
		for (j = 0; j <= t; j++){
			dp[j][i] = false;
			if (j + l[i] <= t)
				dp[j][i] |= dp[j + l[i]][i+1];
			if (j - l[i] >= 0)
				dp[j][i] |= dp[j - l[i]][i+1];
		}

	for (j = 0; j <= t; j++)
		if (dp[j][0])
			return true;

	return false;
}

int main(){
	int z;

	scanf("%d", &f);

	for (z = 0; z < f; z++){
		scanf("%d %d", &t, &n);

		for (int i = 0; i < n; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			l[i] = b - a;
		}

		if (!works()) break;
	}

	printf("%s\n", z == f ? "possible" : "impossible");
}
