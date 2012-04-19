/*
    ID: frceped1
    LANG: C
    TASK: sprime
 */

#include <stdio.h>
#include <math.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("sprime.in", "r"); out = fopen("sprime.out", "w")
	#define getchar() fgetc(in)
	#define putchar(c) fputc(c, out)
#else
	#define read(...) scanf(__VA_ARGS__)
	#define print(...) printf(__VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), stdin);
	#define openFiles()
#endif

FILE *in, *out;

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
	read("%d", &length);

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
		print("%d\n", from[i]);

	return 0;
}
