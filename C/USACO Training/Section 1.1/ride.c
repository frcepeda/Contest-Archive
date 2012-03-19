/*
 ID: frceped1
 LANG: C
 TASK: ride
 */

#include <stdio.h>
#include <ctype.h>

int value(char *str){
	int i, a = 1;
	for (i = 0; isupper(str[i]); i++) {
		a *= str[i] - 'A' + 1;
		a %= 47;
	}
	return a;
}

int main(void){
	char a[50], b[50];
	int aVal, bVal;
	FILE *in, *out;
	in = fopen("ride.in", "r");
	out = fopen("ride.out", "w");
	printf("OPENED FILES\n");
	fgets(a, sizeof(a), in);
	fgets(b, sizeof(b), in);
	printf("%s", a);
	printf("%s", b);
	aVal = value(a);
	bVal = value(b);
	printf("%d, %d", aVal, bVal);
	if (aVal == bVal) {
		fprintf(out, "GO\n");
	} else {
		fprintf(out, "STAY\n");
	}
	return 0;
}