/*
    ID: frceped1
    LANG: C
    TASK: kimbits
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("kimbits.in", "r", stdin); freopen("kimbits.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXLEN 32
#define MAXL MAXLEN

unsigned int stringsBeforeWithCount[MAXL][MAXLEN];
unsigned int N, L, I;

unsigned int stringsBefore(int i){
	int acc = 1, j;

	for (j = 1; j <= L; j++)
		acc += stringsBeforeWithCount[j][i];

	return acc;
}

int main(void){
	openFiles();

	unsigned int i, j, acc;

	scanf("%u %u %u", &N, &L, &I);
	I--;

	for (i = 1; i <= N; i++)
		stringsBeforeWithCount[1][i] = i-1;

	for (i = 2; i <= L; i++)
		for (j = i+1; j <= N; j++)
			stringsBeforeWithCount[i][j] = stringsBeforeWithCount[i][j-1] + stringsBeforeWithCount[i-1][j-1];

	for (i = N; i > 0; i--){
		int before = stringsBefore(i);
		if (before <= I){
			I -= before;
			L--; // when you put a bit, the remaining sequence will have one bit less.
			putchar('1');
		} else {
			putchar('0');
		}
	}
	putchar('\n');

	return 0;
}
