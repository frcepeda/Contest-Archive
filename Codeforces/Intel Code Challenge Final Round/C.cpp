#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

typedef long long ll;

ll m, n, k, x, y, c, d, f, g;

ll ff(ll x, ll y){
	if ((y - x) % d)
		return -1;

	ll t = (x * m * g + y * n * f) / d;

	return (t % c + c) % c;
}

ll go(){
	ll s[2] = {x, n-x};
	ll t[2] = {y, m-y};

	ll z = c + 1;

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			ll w = ff(s[i], t[j]);
			if (w == -1) continue;
			if (w / n % 2 == i && w / m % 2 == j)
				z = min(z, w);
		}
	}

	return z < c ? z : -1;
}

#define mp make_pair
#define fst first
#define snd second

void bezout(){
	pair<ll, ll> s{0,1}, t{1,0}, r{m, n};

	while (r.fst){
		ll q = r.snd / r.fst;
		r = mp(r.snd - q * r.fst, r.fst);
		s = mp(s.snd - q * s.fst, s.fst);
		t = mp(t.snd - q * t.fst, t.fst);
	}

	if (s.snd * n + t.snd * m == d){
		f = s.snd; g = t.snd;
	} else {
		f = -s.snd; g = -t.snd;
	}
}

int main(){
	cin >> n >> m >> k;

	d = __gcd(m, n);
	c = m * n / d;
	bezout();

	assert(f * n + g * m == d);

	for (int i = 0; i < k; i++){
		cin >> x >> y;
		cout << go() << endl;
	}
}
