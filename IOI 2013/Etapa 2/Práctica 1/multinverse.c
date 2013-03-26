#include <stdio.h>

typedef struct {
	long long int a, b;
} pair;

long long int gcd(long long int a, long long int b){
	long long int t;

	while (b != 0){
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}

pair extendedgcd(long long int a, long long int b){
	if (b == 0){
		pair p = {1, 0};
		return p;
	} else {
		pair p = {a / b, a % b};
		pair q = extendedgcd(b, p.b);
		pair r = {q.b, q.a - p.a * q.b};
		return r;
	}
}

long long int modMultInverse(long long int n, long long int mod){
	return extendedgcd(n, mod).a;
}

long long int mod(long long int a, long long int b){
	while (a < 0)
		a += b;
	return a % b;
}

int main(void){
	long long int a, N;

	scanf("%lld %lld", &a, &N);

	if (gcd(a, N) == 1)
		printf("%lld\n", mod(modMultInverse(a, N), N));
	else
		printf("-1\n");

	return 0;
}
