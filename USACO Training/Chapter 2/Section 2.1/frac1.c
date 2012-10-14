/*
    ID: frceped1
    LANG: C
    TASK: frac1
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("frac1.in", "r", stdin); freopen("frac1.out", "w", stdout)
#else
	#define openFiles()
#endif

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

	scanf("%d", &d);

	for (; d >= 2; d--)
		for (n = 1; n <= d; n++)
			if (gcd(n,d) == 1)
				addFraction(n, d);

	qsort(fractions, fractionCount, sizeof(fraction), fractCmp);

	for (i = 0; i < fractionCount; i++)
		printf("%d/%d\n", fractions[i].numerator, fractions[i].denominator);

	return 0;
}

