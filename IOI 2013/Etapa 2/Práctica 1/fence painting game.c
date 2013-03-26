#include <stdio.h>

unsigned long long int gcd(unsigned long long int a, unsigned long long int b){
	unsigned long long int t;

	while (b != 0){
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}

int main(void){
	unsigned long long int N, K;

	scanf("%llu %llu", &N, &K);

	printf("%llu\n", gcd(N,K+1));

	return 0;
}
