#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#ifndef LOL
typedef __int128 ll;
#else
typedef long long ll;
#endif

ll modPow(ll a, ll m, ll n){
	ll ans = 1;

	for (; m; m /= 2){
		if (m % 2)
			ans = (ans * a) % n;
		a = (a * a) % n;
	}

	return ans;
}

#define MAXN 1000010

const ll p = 1000000007LL;
const ll q = (p-1)/2;
ll C[MAXN], B[MAXN], A[MAXN];

int main(){
	C[0] = B[0] = A[0] = 1;

	for (int i = 1; i < MAXN; i++){
		C[i] = (C[i-1] * i) % (q-1);
		B[i] = (B[i-1] * i) % q;
		A[i] = (A[i-1] * i) % p;
	}

	int N;
	scanf("%d", &N);
	while (N--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (b <= 1){
			printf("%lld\n", (long long)A[a]);
			continue;
		}

		auto s = modPow(B[b], C[c], q);
		auto k = modPow(2, q-2, q);
		auto x = (s * k) % q;
		auto ans = modPow(A[a], 2*x, p);

/*
#ifdef LOL
		printf("s = %lld\n", (long long)s);
		printf("k = %lld\n", (long long)k);
		printf("x = %lld\n", (long long)x);
#endif
*/

		printf("%lld\n", (long long)ans);
	}
}
