#include <stdio.h>

#define MAXN 400005
#define MOD 1000000007

unsigned int factorial[MAXN];

typedef struct {
	unsigned int s, t;
} pair;

long long int mod(long long int a){
	while (a < 0)
		a += MOD;
	return a % MOD;
}

long long int modmultinvers(long long int b, long long int a){
	long long int x = 0, lastx = 1;
	long long int y = 1, lasty = 0;
	long long int t;

	while (b != 0){
		long long int q = a / b;
		t = b;
		b = a % b;
		a = t;

		t = x;
		x = lastx - q * x;
		lastx = t;

		t = y;
		y = lasty - q * y;
		lasty = t;
	}

	return lasty;
}

unsigned long long int choose(unsigned int k, unsigned int n){
	return (factorial[n] * modmultinvers((factorial[n-k] * factorial[k]) % MOD, MOD)) % MOD;
}

int main(void){
	unsigned int R, N, M, A, B, i;

	scanf("%d", &R);

	factorial[0] = 1;
	for (i = 1; i <= MAXN; i++)
		factorial[i] = (factorial[i-1] * i) % MOD;

	while (R--){
		long long unsigned int answer = 0;

		scanf("%u %u %u %u", &N, &M, &A, &B);

		for (i = A; i <= M; i++){
			answer += (choose(i, i + N - B) * choose(N - i, N - i + B - 1)) % MOD;
			answer %= MOD;
		}

		printf("%llu\n", answer);
	}

	return 0;
}

