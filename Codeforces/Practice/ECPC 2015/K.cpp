#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int T, n, p;
ll a, b;
int dp[1000100][200];

int m(int x){ return (x % p + p) % p; }

ll inv(ll a, ll b) {	
	ll xx = 0, y = 0;
	ll yy = 1, x = 1;

	while (b) {
		ll q = a/b;
		ll t = b; b = a%b; a = t;
		t = xx; xx = x-q*xx; x = t;
		t = yy; yy = y-q*yy; y = t;
	}

	return x;
}

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%lld %lld %d %d", &a, &b, &n, &p);

		ll ans = 0, ii = inv(10,p);

		for (int i = 1; i <= n; i++){
			ll x;

			a *= 10;
			x = a / b;
			a = a % b;

			for (int j = 0; j < p; j++){
				dp[i][j] = x % p == j;

				if (p == 2 || p == 5){
					if (!dp[i][j]) continue;
					for (int k = 0; k < p; k++)
						dp[i][j] += dp[i-1][k];
				} else {
					dp[i][j] += dp[i-1][m(ii*(j-x))];
				}
			}
			ans += dp[i][0];
		}

		printf("%lld\n", ans);
	}
}
