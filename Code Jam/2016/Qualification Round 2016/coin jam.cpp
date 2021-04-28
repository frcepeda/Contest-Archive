#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

typedef __int128 ll;

vector<ll> toTest = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll mult(ll a, ll b, ll n){
	ll ans = 0;

	for (; b; b /= 2) {		
		if (b % 2)
			ans = (ans + a) % n;		
		a = (a + a) % n;
	}

	return ans;
}

ll pow(ll a, ll b, ll n) {
	ll ans = 1;

	for (; b; b /= 2) {		
		if (b % 2)
			ans = mult(ans, a, n);
		a = mult(a, a, n);
	}

	return ans;
}

bool isPrimeMR (ll n){
	if (n == 2) return true;
	if (n % 2 == 0 || n <= 1) return false;

	ll m;
	int k = 0;
	for (m = n-1; m % 2 == 0; m /= 2)
		k++;

	for (auto a: toTest){
		if (a >= n) break;

		ll x = pow(a, m, n);
	
		if (x == 1 || x == n-1) continue;

		int j;
		for (j = 0; j < k-1; j++){
			x = mult(x, x, n);
			if (x == n-1) break;
		}

		if (j == k-1) return false;
	}

	return true;			
}

ll factor(ll n){
	ll A = 2 + rand() % (n-2);
	ll B = 2 + rand() % (n-2);

	// MAKE SURE f DOESN'T OVERFLOW!
	auto f = [&](ll x){ return mult(x, x + A, n) + B; };
	ll d, x = 2, y = 2;

	do {
		x = f(x);
		y = f(f(y));
		d = __gcd(abs(x - y), n);
	} while (d == 1);

	return d;
}

ll properDivisor(ll n){
	if (n == 1 || isPrimeMR(n)) return -1;

	ll f;
	do f = factor(n);
	while (f == n);

	return min(f, n/f);
}

/*
int N = 16;
int J = 50;
*/
int N = 32;
int J = 500;
long long f[1000];

ll rev(ll x){
	ll one = 1;
	ll y = 0;

	for (int i = 0; i < N-2; i++)
		y |= (one << (N-2-i-1)) * !!(x & (one << i));

	return y;
}

ll pad(ll x){
	ll one = 1;
	return (one << (N-1)) | (x << 10) | 1;
}

ll toBase(ll x, ll b){
	ll r = 0;

	for (; x; x /= 2)
		r = r * b + (x % 2);

	return r;
}

bool iscoinjam(ll x){
	x = pad(x);

	for (int k = 2; k <= 10; k++){
		ll y = toBase(x, k);
		ll z = properDivisor(y);

		if (z == -1) return false;

		f[k] = z;
	}

	return true;
}

int main(){
	printf("Case #1:\n");

	for (int i = 0, j = 0; i < J; i++, j++){
		for (; !iscoinjam(j); j++);

		for (ll z = pad(j); z; z /= 2)
			putchar('0' + z % 2);

		for (int k = 2; k <= 10; k++)
			printf(" %lld", f[k]);
		printf("\n");
		fflush(stdout);
		fprintf(stderr, "**%d**", i);
	}
}
