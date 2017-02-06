#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int mod = 1000000007;
int n;

ll inv(ll x){
	int r = 1;

	for (int e = mod - 2; e; e /= 2){
		if (e % 2)
			r = r * x % mod;
		x = x * x % mod;
	}

	return r;
}

int main(){
	scanf("%d", &n);

	ll ans = 0;

	for (int i = 2; i <= n; i++)
		ans = (ans + (i-1)) % mod;

	ans = ((ans * inv(n-1)) % mod + mod) % mod;

	for (int i = 2; i <= n; i++)
		ans = ((ans * i) % mod + mod) % mod;

	printf("%lld\n", ans);
}
