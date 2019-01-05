// Accepted
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;
const int maxinv = 100;
ll ii[maxinv];

ll inv(ll x){
	ll ret = 1;
	for (int e = mod-2; e; e /= 2){
		if (e % 2)
			ret = (ret * x) % mod;
		x = (x * x) % mod;
	}
	return ret;
}

const int maxk = 10100;
ll n, k;

ll dp[maxk][70];

ll go(ll p, int pp){
	dp[0][0] = 1;
	for (int i = 1; i <= pp; i++)
		dp[0][i] = (dp[0][i-1] * p) % mod;

	for (int j = 1; j <= k; j++){
		ll acc = 0;
		for (int i = 0; i <= pp; i++){
			acc = (acc + dp[j-1][i]) % mod;
			dp[j][i] = acc * ii[i+1] % mod;
		}
	}

	return dp[k][pp];
}

int main(){
	cin >> n >> k;

	for (int i = 1; i < maxinv; i++)
		ii[i] = inv(i);

	ll ans = 1;

	for (ll i = 2; i*i <= n; i++){
		int cnt = 0;

		for (; n % i == 0; n /= i)
			cnt++;

		if (cnt)
			ans = (ans * go(i, cnt)) % mod;
	}
	
	if (n != 1)
		ans = (ans * go(n, 1)) % mod;

	cout << ans << endl;
}
