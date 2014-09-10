// Accepted
#include <stdio.h>

#define MOD 1000000007ull

int T;

long long power(long long a, long long b){
	long long r = 1;

	for (; b; b /= 2){
		if (b % 2)
			r = (r * a) % MOD;
		a = (a * a) % MOD;
	}

	return r % MOD;
}

long long inv(long long x){
	return power(x, MOD-2);
}

int main(void){
	scanf("%d", &T);

	while (T--){
		long long x, n, ans, xn;

		scanf("%lld %lld", &n, &x);

		if (x == 1){
			ans = n * (n+1) / 2;
			ans %= MOD;
		} else {
			ans = (x * inv(x-1)) % MOD;
			xn = power(x,n);
			xn = ((n * xn % MOD) * (x-1) - (xn - 1)) % MOD;
			if (xn < 0) xn += MOD;
			ans = (ans * xn) % MOD;
			ans = (ans * inv(x-1)) % MOD;
		}

		printf("%lld\n", ans);
	}
}
