/*
 ID: frceped1
 LANG: C
 TASK: ride
 */

#include <stdio.h>
#include <ctype.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("ride.in", "r", stdin); freopen("ride.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

int value(char *str){
	int i, a = 1;
	for (i = 0; isupper(str[i]); i++) {
		a *= str[i] - 'A' + 1;
		a %= 47;
	}
	return a;
}

int main(void){
	openFiles();
	char a[50], b[50];
	int aVal, bVal;

	scanf("%s", a);
	scanf("%s", b);

	aVal = value(a);
	bVal = value(b);

	if (aVal == bVal)
		printf("GO\n");
	else
		printf("STAY\n");

	return 0;
}
