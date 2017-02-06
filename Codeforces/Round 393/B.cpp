#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int n, dp[maxn], t[maxn];

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);

	int x = 1, y = 1, b = 0;
	for (int i = 1; i <= n; i++){
		for (; x < i && t[i] - t[x] >= 90; x++);
		for (; y < i && t[i] - t[y] >= 1440; y++);

		dp[i] = 20 + dp[i-1];
		dp[i] = min(dp[i], 50 + dp[x-1]);
		dp[i] = min(dp[i], 120 + dp[y-1]);

		int p = dp[i] - b;
		b += p;

		printf("%d\n", p);
	}
}
