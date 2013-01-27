#include <stdio.h>

typedef unsigned long long int ulli;

typedef struct {
	long long int x, y;
} pair;

ulli n, p, q, m, c, e, d, phi;

ulli square(ulli n){
	return n * n;
}

ulli modPower(ulli n, ulli e, ulli mod){
	if (e == 0)
		return 1;
	else if (e % 2 == 0)
		return square(modPower(n,e/2,mod)) % mod;
	else
		return (modPower(n,e-1,mod) * n) % mod;
}

unsigned long long int modulo(long long int n, long long int mod){
	while (n < 0)
		n += mod;
	return n % mod;
}

pair exgcd(ulli a, ulli b){
	if (b == 0){
		pair p = {.x = 1, .y = 0};
		return p;
	} else {
		pair m = {.x = a/b, .y = a%b};
		pair n = exgcd(b, m.y);
		pair r = {n.y, n.x - m.x * n.y};
		return r;
	}
}

ulli modMultInverse(ulli n, ulli mod){
	return modulo(exgcd(n,mod).x, mod);
}

int main(void){
	scanf("%llu %llu %llu", &n, &e, &c);

	if (n % 2 == 0){
		p = 2;
		q = n / 2;
	} else {
		for (p = 3;; p += 2){
			if (n % p == 0){
				q = n / p;
				break;
			}
		}
	}

	phi = (p - 1) * (q - 1);

	d = modMultInverse(e, phi);

	printf("%llu\n", modPower(c, d, n));

	return 0;
}
