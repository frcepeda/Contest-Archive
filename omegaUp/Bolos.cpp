#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 60100

int n, k, w;
int dp[2][MAXN], pin[MAXN], acc[MAXN], score[MAXN];

int main(){
	int T;

	scanf("%d", &T);

	while (T--){
		int i, j;

		scanf("%d %d %d", &n, &k, &w);

		fill(dp[0], dp[0] + MAXN, 0);
		fill(acc, acc + MAXN, 0);
		fill(score, score + MAXN, 0);

		for (i = 0; i < n; i++)
			scanf("%d", &pin[i]);

		for (i = n-1; i >= 0; i--){
			acc[i] = pin[i] + acc[i+1];
			score[i] = acc[i] - acc[i+w];
		}

		for (j = 1; j <= k; j++)
			for (i = n-1; i >= 0; i--)
				dp[j%2][i] = max(dp[j%2][i+1], dp[(j-1)%2][i+w] + score[i]);

		printf("%d\n", dp[k%2][0]);
	}
}
