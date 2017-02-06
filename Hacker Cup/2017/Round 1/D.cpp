#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;

const int maxcache = 1001000000;
const int cachemult = 50;
ll f[maxcache/cachemult];

const int maxn = 2010;
int T, N, M, R[maxn];

ll ff(ll x){
	ll ret = f[x/cachemult];

	for (ll i = (x/cachemult)*cachemult+1; i <= x; i++)
		ret = (ret * i) % mod;

	return ret;
}

ll inv(ll x){
	ll ret = 1;

	for (ll b = mod-2; b; b /= 2){
		if (b % 2)
			ret = (ret * x) % mod;
		x = (x * x) % mod;
	}

	return ret;
}

ll ways(ll s){
	if (s < 0) return 0;
	ll k = N - 2;
	ll num = (s + 1) * (k + s + 2) % mod * ff(k + s + 1) % mod;
	ll den = (k + 1) * (k + 2) % mod * ff(s + 1) % mod;
	return num * inv(den) % mod + mod;
}

int main(){
	ll acc = f[0] = 1;
	for (ll i = 1; i < maxcache; i++){
		acc = (acc * i) % mod;
		if (i % cachemult == 0)
			f[i / cachemult] = acc;
	}

	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d %d", &N, &M);

		ll acc = 0;

		for (int i = 0; i < N; i++){
			scanf("%d", &R[i]);
			acc += 2 * R[i];
		}

		if (N == 1){
			printf("Case #%d: %d\n", t, M);
			continue;
		}

		ll ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
				if (i == j) continue;

				int ij = R[i] + R[j];

				ans += ways(M-1 - acc + ij);
				ans %= mod;
			}

		printf("Case #%d: %lld\n", t, ans);
	}
}
