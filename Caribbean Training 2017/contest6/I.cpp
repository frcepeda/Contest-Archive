// Accepted
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 5010;
const int mod = 1000000007;

typedef long long ll;

int t, n, k, x;
int c[maxn];
int L, G, E;
ll f[maxn], finv[maxn];

ll inv(ll x){
	ll r = 1;

	for (ll e = mod-2; e; e /= 2){
		if (e % 2)
			r = (r * x) % mod;
		x = (x * x) % mod;
	}

	return r;
}

ll choose(int n, int k){
	if (n < 0 || k < 0 || k > n) return 0;
	return f[n] * finv[k] % mod * finv[n-k] % mod;
}

int main(){
	finv[0] = finv[1] = f[0] = f[1] = 1;
	for (int i = 2; i < maxn; i++){
		f[i] = f[i-1] * i % mod;
		finv[i] = inv(f[i]);
	}

	scanf("%d %d", &n, &t);

	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	scanf("%d %d", &k, &x);

	for (int i = 0; i < n; i++){
		if (c[i] < c[k-1])
			L++;
		else if (c[i] > c[k-1])
			G++;
		else
			E++;
	}

	E--;

	ll ans = 0;

	for (int i = 0; i <= E; i++){
		ll tmp = 0;

		for (int j = 0; j <= i; j++)
			tmp = (tmp + choose(L, x-1-j) * choose(G, t-x-i+j) % mod) % mod;

		ans = (ans + tmp * choose(E, i) % mod + mod) % mod;
	}

	printf("%lld\n", ans);
}
