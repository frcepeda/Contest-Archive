/*
    ID: frceped1
    LANG: C
    TASK: frac1
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("frac1.in", "r"); out = fopen("frac1.out", "w")
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

#define MAXFRACTIONS 100000

typedef struct {
	int numerator, denominator;
} fraction;

fraction makeFraction(int n, int d){
	fraction f = { .numerator = n, .denominator = d };
	return f;
}

int doubleCmp(double a, double b){
	if (a > b) return 1;
	else if (a < b) return -1;
	else return 0;
}

double fractToDouble(fraction *f){
	return (double)f->numerator / f->denominator;
}

int fractCmp(void *ap, void *bp){
	return doubleCmp(fractToDouble((fraction *) ap), fractToDouble((fraction *) bp));
}

fraction fractions[MAXFRACTIONS];
int fractionCount;

int addFraction(int numerator, int denominator){
	fractions[fractionCount++] = makeFraction(numerator, denominator);
}

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(void){
	openFiles();

	addFraction(1, 1);
	addFraction(0, 1);

	int n, d, i;

	read("%d", &d);

	for (; d >= 2; d--)
		for (n = 1; n <= d; n++)
			if (gcd(n,d) == 1)
				addFraction(n, d);

	qsort(fractions, fractionCount, sizeof(fraction), fractCmp);

	for (i = 0; i < fractionCount; i++)
		print("%d/%d\n", fractions[i].numerator, fractions[i].denominator);

	return 0;
}

