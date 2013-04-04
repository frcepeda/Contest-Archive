#include <stdio.h>

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){ // HAI
	int tux; // I HAS A TUX
	scanf("%d", &tux); // GIMMEH TUX
	int foo = 0; // I HAS A FOO ITS 0
	int bar = 0; // I HAS A BAR ITS 0
	int baz = 0; // I HAS A BAZ ITS 0
	int quz = 1; // I HAS A QUZ ITS 1
	while (tux--){ // IM IN YR LOOP NERFIN YR TUX TIL BOTH SAEM TUX AN 0
		int pur; // I HAS A PUR
		scanf("%d", &pur); // GIMMEH PUR
		foo += pur; // FOO R SUM OF FOO AN PUR
		bar += 1; // BAR R SUM OF BAR AN 1
		if (max(foo * quz, bar * baz) == foo * quz){ // BOTH SAEM BIGGR OF PRODUKT OF FOO AN QUZ AN PRODUKT OF BAR BAZ AN PRODUKT OF FOO AN QUZ
			baz = foo; // BAZ R FOO
			quz = bar; // QUZ R BAR
		}
	}
	printf("%lf\n", (double)baz / quz); // VISIBLE SMOOSH QUOSHUNT OF BAZ QUZ
	return 0;
}
