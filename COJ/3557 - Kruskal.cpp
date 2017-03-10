#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef LOL
typedef long long ll;
#else
typedef __int128 ll;
#endif

vector<ll> toTest = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll modPow(ll b, ll e, ll m){
	ll r = 1;

	for (; e; e /= 2){
		if (e % 2)
			r = (r * b) % m;
		b = (b * b) % m;
	}

	return r;
}

bool isPrimeMR(ll n){
	if (n == 2) return true;
	if (n % 2 == 0 || n <= 1) return false;

	ll m; int k = 0;
	for (m = n-1; m%2 == 0; m /= 2) k++;

	for (auto a: toTest){
		if (a >= n) break;

		ll x = modPow(a, m, n);

		if (x == 1 || x == n-1) continue;

		int j;
		for (j = 0; j < k-1; j++){
			x = (x * x) % n;
			if (x == n-1) break;
		}

		if (j == k-1) return false;
	}

	return true;
}

ll factor(ll n){
	ll A = 2 + rand() % (n-2);
	ll B = 2 + rand() % (n-2);

	auto f = [&](ll x){ return x * (x + A) % n + B; };
	ll d, x = 2, y = 2;

	do {
		x = f(x);
		y = f(f(y));
		d = __gcd(x >= y ? x - y : y - x, n);
	} while (d == 1);

	return d;
}

void factorize(ll n, vector<ll> &v){
	if (n == 1) return;
	if (isPrimeMR(n)){
		v.push_back(n);
		return;
	}

	ll f;
	do f = factor(n);
	while (f == n);

	factorize(f, v); factorize(n/f, v);
}

#define MAXN 6010

int T, N;
long long K, a[MAXN];

int main(){
	scanf("%d", &T);

	while (T--){
		long long x = 0;
		bool autoWin = false;

		scanf("%d %lld", &N, &K);

		for (int i = 0; i < N; i++)
			scanf("%lld", &a[i]);

		bool allOnes = all_of(a, a + N, [](long long z){ return z == 1; });

		if (allOnes){
			// do nothing
		} else if (N == 1 && a[0] > 2){
			auto z = a[0];
			int k = 0;
			for (z--, k++; !isPrimeMR(z); z--, k++);
			x = k % (K+1);
		} else if (N > 1) {
			for (int i = 0; i < N; i++){
				auto z = a[i];
				int k = 0;

				for (; z > 1 && !isPrimeMR(z); z--, k++);

				if (z > 1){
					if (k <= K)
						autoWin = true;
					else
						x ^= k % (K+1);
				} else x ^= 1;
			}
		}

		printf("%s\n", x || autoWin ? "YES" : "NO");
	}
}
