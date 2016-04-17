#include <cstdio>
#include <algorithm>

using namespace std;

#define L 1000099

int n;
int dp[1001000];
int p[1000100], a[1000100];

int main(){
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		p[a+1] = b;
	}

	for (i = 1; i <= L; i++)
		a[i] = a[i-1] + !!p[i];

	int ans = 1<<30;
	for (i = 1; i <= L; i++){
		int w = i - p[i] - 1;
		dp[i] = a[i-1] + (w >= 0 ? dp[w] - a[w] : 0);

		ans = min(ans, dp[i] + a[L] - a[i]);
	}

	printf("%d\n", ans);
}
