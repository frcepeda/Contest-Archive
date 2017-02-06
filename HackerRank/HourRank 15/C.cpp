#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 2010;
const ll mod = 1000000007LL;
ll choose[maxn][maxn], f[maxn], t[maxn];
int q, n, a[maxn];

int main(){
	t[0] = 1;
	t[1] = 500000004;
	for (int i = 2; i < maxn; i++)
		t[i] = (t[i-1] * t[1]) % mod;

	for (int i = 0; i < maxn; i++){
		choose[i][0] = choose[i][i] = 1;
		for (int j = 1; j < i; j++)
			choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % mod;
	}

	f[0] = f[1] = 1;
	for (int i = 2; i < maxn; i++)
		f[i] = (f[i-1] * i) % mod;

	scanf("%d", &q);

	while (q--){
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		sort(a, a + n);
		a[n] = 0;

		int m = 0, k = 0;
		for (int i = 0; i < n; i++){
			if (a[i] == a[i+1])
				k++, i++;
			else
				m++;
		}

		ll ans = 0;

		for (int i = 0; i <= k; i++){
			ll w = (i%2?-1:1) * choose[k][i] % mod * f[n-i] % mod * t[k-i] % mod + mod;
			//fprintf(stderr, "%lld\n", w % mod);
			ans = (ans + w) % mod;
		}

		printf("%lld\n", ans);
	}
}
