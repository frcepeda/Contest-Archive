#include <stdio.h>

#define MOD 1000000007

unsigned long long int square(unsigned long long int n){
	return n * n;
}

unsigned long long int twotothe(int a){
	switch (a){
		case 0:
			return 1;
		case 1:
			return 2;
		default:
			if (a % 2 == 0){
				return square(twotothe(a/2)) % MOD;
			} else {
				return 2 * square(twotothe(a/2)) % MOD;
			}
	}
}

int main(void){
	int T, N, a, b;

	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);

		a = b = N/2;
		if (N % 2 == 0){
			a--;
		}

		printf("%lld\n", (twotothe(a+1) + twotothe(b+1) - 2) % MOD);
	}

	return 0;
}

