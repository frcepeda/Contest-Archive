#include <stdio.h>

#define MAXN 2010
#define MOD 1000000009

int N, K;

unsigned long long int square(unsigned long long int n){
	return n * n;
}

unsigned long long int exponentiate(unsigned long long int n, int exp){
	if (exp == 0)
		return 1;
	else if (exp % 2 == 0)
		return square(exponentiate(n, exp/2)) % MOD;
	else
		return (exponentiate(n, exp-1) * n) % MOD;
}

unsigned int modMultInverse(int i){
	return (unsigned int)exponentiate(i, MOD-2);
}

int main(void){
	int i, j;
	unsigned long long int answer = 1;

	scanf("%d %d", &N, &K);

	for (i = N + K - 1; i > N; i--)
		answer = (answer * i) % MOD;

	for (i = 2; i < K; i++)
		answer = (answer * modMultInverse(i)) % MOD;

	printf("%llu\n", answer);

	return 0;
}
