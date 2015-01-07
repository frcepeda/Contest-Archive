#include <cstdio>
#include <algorithm>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

typedef long long ll;

ll n, c1, c2, n1, n2;

pair<ll,ll> ex_gcd(ll a, ll b){
	pair<ll,ll> r = mp(b, a);
	pair<ll,ll> s = mp(0, 1);
	pair<ll,ll> t = mp(1, 0);

	while (r.fst){
		ll q = r.snd / r.fst;
		r = mp(r.snd - r.fst * q, r.fst);
		s = mp(s.snd - s.fst * q, s.fst);
		t = mp(t.snd - t.fst * q, t.fst);
	}

	return mp(s.snd, t.snd);
}

ll cost(pair<ll,ll> e){
	return e.fst < 0 || e.snd < 0 ? -1 : e.fst * c1 + e.snd * c2;
}

ll ceil_(ll a, ll b){
	return a >= 0 ? (a + b-1) / b : a / b;
}

int main(){
	while (scanf("%d", &n), n){
		scanf("%d %d %d %d", &c1, &n1, &c2, &n2);

		ll g = __gcd(n1, n2);

		if (n % g){
			printf("failed\n");
			continue;
		}

		n /= g;

		pair<ll,ll> x = ex_gcd(n1, n2);
		pair<ll,ll> e = mp(x.fst * n, x.snd * n);

		ll k = ceil_(-g * e.fst, n2);
		pair<ll,ll> minx = mp(e.fst + k*n2/g, e.snd - k*n1/g);

		ll j = ceil_(-g * e.snd, n1);
		pair<ll,ll> miny = mp(e.fst - j*n2/g, e.snd + j*n1/g);

		ll costx = cost(minx);
		ll costy = cost(miny);

		if (costx < 0 && costy < 0)
			printf("failed\n");
		else if (costy < 0 || costx < costy)
			printf("%lld %lld\n", minx.fst, minx.snd);
		else
			printf("%lld %lld\n", miny.fst, miny.snd);
	}
}
