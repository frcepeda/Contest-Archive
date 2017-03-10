#include <cstdio>
#include <algorithm>

using namespace std;

#ifndef LOL
typedef __int128 ll;
#else
typedef long long ll;
#endif

long long X;

ll modPow(ll b, ll e, ll m){
	ll r = 1;
	
	for (; e; e /= 2){
		if (e % 2)
			r = (r * b) % m;
		b = (b * b) % m;
	}

	return r;
}

ll p = 1000000001111107LL;

int main(){
	while (scanf("%lld", &X), (X != -1)){
		if (X == 0) {
			printf("0\n");
		} else if (modPow(X, (p-1)/2, p) == 1){
			ll N = modPow(X, ((p-1)/2+1)/2, p);
			ll M = p - N;
			if (N > M) swap(N, M);
			printf("%lld %lld\n", (long long)N, (long long)M);
		} else {
			printf("DUENDE DIABOLICO\n");
		}
	}
}
