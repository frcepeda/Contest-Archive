#include <stdio.h>
#include <stdbool.h>

#define MAXN 100001
#define SIEVELIMIT 318
bool sieve[MAXN];
int A, B;

int primes[MAXN];
int primeNum;

bool isPrime(int n){
	int hi = primeNum, lo = 0, mid;

	while (lo < hi){
		mid = (lo+hi)/2;
		if (primes[mid] == n)
			return true;
		else if (primes[mid] < n)
			lo = mid+1;
		else
			hi = mid;
	}

	return false;
}

int main(void){
	int i, answer = 0;

	scanf("%d %d", &A, &B);

	for (i = 2; i <= SIEVELIMIT; i++){
		if (!sieve[i]){
			int j = i*i;
			for (; j < MAXN; j += i){
				sieve[j] = true;
			}
			primes[primeNum++] = i;
		}
	}

	for (; i < MAXN; i++)
		if (!sieve[i])
			primes[primeNum++] = i;

	for (i = A; i <= B; i++){
		if (sieve[i]){
			int j, tmp = i, count = 0;
			
			for (j = 0; j < primeNum && tmp != 1; j++){
				while (tmp % primes[j] == 0){
					count++;
					tmp /= primes[j];
				}
			}

			if (isPrime(count))
				answer++;
		}
	}

	printf("%d\n", answer);

	return 0;
}
