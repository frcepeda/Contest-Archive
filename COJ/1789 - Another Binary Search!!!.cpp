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

int T;
long long N;

int main(){
	scanf("%d", &T);

	vector<ll> f;
	while (T--){
		scanf("%lld", &N);

		f.clear();
		factorize(N, f);
		sort(f.begin(), f.end());

		int a, b, c;
		ll p, q, r;
		pair<int, ll> tmp;

		auto g = [&](int z){
			if (f.size() <= z)
				return make_pair(z, (ll)0);
			ll w = f[z];
			int x;
			for (x = z; x < f.size() && f[x] == w; x++);
			return make_pair(x, w);
		};

		tmp = g(0);
		a = tmp.first;
		p = tmp.second;
		tmp = g(a);
		b = tmp.first - a;
		q = tmp.second;
		tmp = g(a+b);
		c = tmp.first - a - b;
		r = tmp.second;

		if (N == 1 || isPrimeMR(N))
			printf("Vasha\n0\n");
		else if (a >= 3)
			printf("Vasha\n%lld\n", (long long)(p*p));
		else if (a >= 2 && b >= 1)
			printf("Vasha\n%lld\n", (long long)(p*p));
		else if (a+b+c >= 3)
			printf("Vasha\n%lld\n", (long long)(p*q));
		else
			printf("Molek\n");
	}
}
