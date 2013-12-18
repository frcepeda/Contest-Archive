#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

#define MAXN 1010

int c1, c2, c3, c4;
int n, m;
int a[MAXN], b[MAXN];
int asum[MAXN], bsum[MAXN];

int main(){
	int ans, besta, bestb, i;

	scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (i = 1; i <= m; i++)
		scanf("%d", &b[i]);

	sort(a+1, a+1 + n, greater<int>());
	sort(b+1, b+1 + m, greater<int>());

	for (i = 1; i <= n+1; i++)
		asum[i] = a[i] + asum[i-1];

	for (i = 1; i <= m+1; i++)
		bsum[i] = b[i] + bsum[i-1];

	ans = c4;
	besta = min(c3, c1 * asum[n]);
	bestb = min(c3, c1 * bsum[m]);

	for (i = 1; i <= n; i++)
		besta = min(besta, i * c2 + (asum[n+1] - asum[i]) * c1);

	for (i = 1; i <= m; i++)
		bestb = min(bestb, i * c2 + (bsum[m+1] - bsum[i]) * c1);

	ans = min(ans, besta + bestb);

	printf("%d\n", ans);
}
