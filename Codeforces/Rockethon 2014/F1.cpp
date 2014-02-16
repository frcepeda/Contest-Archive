#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 3010
typedef long long ll;
int n, k;
ll p[MAXN];
ll dpbuy[MAXN][MAXN], dpsell[MAXN][MAXN];

int main(){
	int i, j;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
		scanf("%lld", &p[i]);

	for (j = 1; j <= k; j++){
		ll bestsell = -(1LL<<50); // FIXME
		ll bestbuy = 0;
		for (i = n-1; i >= 0; i--){
			dpsell[j][i] = p[i] + bestbuy;
			dpbuy[j][i] = -p[i] + bestsell;
			bestbuy = max(bestbuy, dpbuy[j-1][i]);
			bestsell = max(bestsell, dpsell[j][i]);
		}
	}
	
	ll ans = 0;
	for (i = 0; i < n; i++)
		ans = max(ans, dpbuy[k][i]);

	printf("%lld\n", ans);
}
