/*
    ID: frceped1
    LANG: C
    TASK: pprime
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("pprime.in", "r"); out = fopen("pprime.out", "w")
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

#define MAXSIZE 10

int min, max;
int palindrome[MAXSIZE];
int digitsOfPalindrome;

int isPrime(int num){
	int i, limit = sqrt(num);
	for (i = 2; i <= limit; i++)
		if (num % i == 0) // evenly divides by i
			return 0;
	return 1;
}

void generatePalindromes(int start, int end){
	int i;

	if (start > end){
		int i, num = palindrome[0];
		for (i = 1; i < digitsOfPalindrome; i++){
			num *= 10;
			num += palindrome[i];
		}
		if (num >= min && num <= max && isPrime(num))
			print("%d\n", num);
		return;
	}

	for (i = start ? 0 : 1; i < 10; i++){ // if start > 0, start outputting by 1
		palindrome[start] = palindrome[end] = i;
		generatePalindromes(start+1, end-1);
	}
}

int main(void){
	openFiles();
	int i;
	
	read("%d %d", &min, &max);

	for (i = 0; i < log10(max)+1; i++){
		digitsOfPalindrome = i+1;
		generatePalindromes(0,i);
	}

	return 0;
}
