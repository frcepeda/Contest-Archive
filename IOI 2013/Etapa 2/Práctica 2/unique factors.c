#include <stdio.h>
#include <math.h>
#include <assert.h>

#define MAXDIV 2000

unsigned int divisors[MAXDIV];
int dCount;

unsigned int dp[MAXDIV];

unsigned int primes[MAXDIV][2];
int pCount;

unsigned int N;

int unsignedIntCmp(const void *ap, const void *bp){
	unsigned int a = *(unsigned int *)ap;
	unsigned int b = *(unsigned int *)bp;
	if (a > b) return 1;
	else if (a < b) return -1;
	return 0;
}

int findDivisor(unsigned int d){
	int lo = 0, hi = dCount, mid;

	while (lo < hi){
		mid = (lo + hi) / 2;

		if (divisors[mid] < d)
			lo = mid + 1;
		else
			hi = mid;
	}

	return hi;
}

void generateDivisors(int d, unsigned int curr){
	int i;

	if (d == pCount){
		divisors[dCount++] = curr;
		return;
	}

	for (i = 0; i < primes[d][1]; i++){
		generateDivisors(d+1, curr);
		curr *= primes[d][0];
	}
	generateDivisors(d+1, curr);
}

int main(void){
	int i, j, _sqrt;

	scanf("%u", &N);

	_sqrt = sqrt(N);

	if (N % 2 == 0)
		primes[0][0] = 2;

	while (N % 2 == 0){
		primes[0][1]++;
		N /= 2;
	}

	if (primes[0][0] == 2)
		pCount++;

	for (i = 3; i <= _sqrt; i += 2){
		if (N % i == 0)
			primes[pCount][0] = i;

		while (N % i == 0){
			primes[pCount][1]++;
			N /= i;
		}

		if (primes[pCount][0] == i)
			pCount++;
	}

	if (N != 1){
		primes[pCount][0] = N;
		primes[pCount][1] = 1;
		pCount++;
	}

	generateDivisors(0, 1);
	qsort(divisors, dCount, sizeof(divisors[0]), unsignedIntCmp);

	dp[0] = 1;

	/*
	   Why switch i and j around?

	   Since we don't care about the order in which the factors appear (it's a
	   multiplication, after all,) we need to count combinations, not permutations.

	   A solution for that is to have a two-dimensional dp with state (curr, max), where
	   max is the largest number you're allowed to divide by in this state. This enumerates
	   the combinations, since it imposes an ordering on the way they are generated.

	   The recurrence would be f(curr, max) = f(curr/max, curr/max) + f(curr, max-1), where
	   the first term is only added if max | curr.

	   Instead of filling a two-dimensional table, j can be the outer loop, representing max.
	   By the j-th iteration, dp[i] contains the ways to get a factorization using only
	   elements from div[0..j].
	 */

	for (j = 1; j < dCount; j++)
		for (i = 1; i < dCount; i++)
			if (divisors[i] % divisors[j] == 0)
				dp[i] += dp[findDivisor(divisors[i] / divisors[j])];

	printf("%u\n", dp[dCount-1] - 1); // factorizations must have at least 2 elements (in this problem).

	return 0;
}
