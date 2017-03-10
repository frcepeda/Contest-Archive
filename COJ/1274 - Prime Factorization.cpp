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

vector<ll> toTest = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll modPow(ll a, ll m, ll n){
	ll ans = 1;

	for (; m; m /= 2){
		if(m % 2)
			ans = (ans * a) % n;
		a = (a * a) % n;
	}
	return ans;
}

bool isPrimeMR(ll n){
	if (n == 2) return true;
	if (n % 2 == 0 || n <= 1) return false;

	ll m;
	int k = 0;
	for(m = n-1; m % 2 == 0; m /= 2) k++;

	for(auto a: toTest){
		if (a >= n) break;
		
		ll x = modPow(a, m, n);

		if (x == 1 || x == n-1) continue;

		int j;
		for(j = 0; j < k-1; j++){
			x = (x * x) % n;
			if(x == n-1) break;
		}

		if (j == k - 1) return false;
	}

	return true;
}

ll factor(ll n){
	ll A = 2 + rand() % (n - 2);
	ll B = 2 + rand() % (n - 2);

	auto f = [&](ll x){ return x * (x + A) % n + B; };
	ll d, x = 2, y = 2;

	do{
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

	factorize(f, v);
	factorize(n/f, v);
}

vector<int> ans[110];
vector<ll> factors[110];

int main(){
	int N;

	for (int n = 2; n <= 100; n++){
		factors[n] = factors[n-1];
		factorize(n, factors[n]);
		sort(factors[n].begin(), factors[n].end());
		int l = 0;
		auto &v = factors[n];
		for (int i = 0; i < v.size(); i++)
			if (i == v.size()-1 || v[i] != v[i+1]){
				ans[n].push_back(i-l+1);
				l = i+1;
			}
	}

	while(scanf("%d", &N), N){
		auto &vs = ans[N];

		printf("%3d! =", N);
		int i;
		for (i = 0; i < vs.size(); i++){
			printf("%3d", vs[i]);
			if ((i+1) % 15 == 0 && i < vs.size()-1)
				printf("\n      ");
		}
		printf("\n");
	}
}
