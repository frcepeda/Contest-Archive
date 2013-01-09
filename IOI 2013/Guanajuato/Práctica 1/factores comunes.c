#include <stdio.h>
#include <math.h>

long long int gcd(long long int a, long long int b){
	long long int t;

	while (b != 0){
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}

int main(void){
	unsigned long long int A, B, G, ans;

	scanf("%llu %llu", &A, &B);

	G = gcd(A, B);

	int i, j = 0, k = (int)sqrt(G) + 1;

	while (G % 2 == 0){
		G /= 2;
		j++;
	}
	ans = j + 1;

	for (j = 0, i = 3; i <= k; i += 2, j = 0){
		while (G % i == 0){
			G /= i;
			j++;
		}
		ans *= j + 1;
	}

	if (G > 1) // Handles the case where both are equal and primes.
		ans *= 2;

	printf("%llu\n", ans);

	return 0;
}
