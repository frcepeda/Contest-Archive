#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll x, y, d;

void extendedEuclid(ll a, ll b){
	if (!b) { x = 1; y = 0; d = a; return; }
	extendedEuclid(b, a % b);
	ll x1 = y;
	ll y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}

// ax + by = d

ll multiplicativeInverse(ll a, ll N){
	extendedEuclid(a, N);
	x %= N;
	if (x < 0) x += N;
	return x;
}

ll modExp(ll x, ll y, ll m){
	ll r = 1;

	for (; y; y /= 2){
		if (y & 1)
			r = (r * x) % m;
		x = (x * x) % m;
	}

	return r % m;
}

int phi(int x){
	int i;
	for (i = 2; x % i; i++);
	return (i - 1) * (x/i - 1);
}

ll decrypt(int n, int e, int c){
	return modExp(c, multiplicativeInverse(e, phi(n)), n);
}

int main(void){
	ll n, e, c;
	scanf("%lld %lld %lld", &n, &e, &c);
	printf("%lld\n", decrypt(n, e, c));
}
