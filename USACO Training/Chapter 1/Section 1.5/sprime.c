/*
    ID: frceped1
    LANG: C
    TASK: sprime
 */

#include <stdio.h>
#include <math.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("sprime.in", "r", stdin); freopen("sprime.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXPRIMES 1000

int primeListA[MAXPRIMES] = {2,3,5,7};
int primeListB[MAXPRIMES];
int *from = primeListA;
int *to = primeListB;
int fromCount = 4, toCount = 0;

int isPrime(int num){
	int i, limit = sqrt(num);
	for (i = 2; i <= limit; i++)
		if (num % i == 0) // evenly divisible
			return 0;
	return 1;
}

int main(void){
	openFiles();

	int i, length;
	scanf("%d", &length);

	for (i = 2; i <= length; i++){
		int j, nextDigit, test;
		toCount = 0;
		for (j = 0; j < fromCount; j++){
			// numbers ending in an even digit aren't prime.
			for (nextDigit = 1; nextDigit < 10; nextDigit += 2){ 
				test = from[j]*10 + nextDigit;
				if (isPrime(test))
					to[toCount++] = test;
			}
		}

		int *temp = from;
		from = to;
		to = temp;
		fromCount = toCount;
	}

	for (i = 0; i < fromCount; i++)
		printf("%d\n", from[i]);

	return 0;
}
