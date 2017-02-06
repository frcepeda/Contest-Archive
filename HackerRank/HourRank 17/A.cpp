#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, h[110];

int main(){
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);

	int ans = 0;
	for (int i = 0; i < n-1; i++)
		ans = max(ans, h[i+1] - k - ans);

	printf("%d\n", ans);
}
