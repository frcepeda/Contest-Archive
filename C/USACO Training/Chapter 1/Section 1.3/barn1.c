/*
    ID: frceped1
    LANG: C
    TASK: barn1
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("barn1.in", "r"); out = fopen("barn1.out", "w")
#else
	#define read(...) scanf(__VA_ARGS__)
	#define print(...) printf(__VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), stdin);
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

#define MAXNUM 200

int intCmp(const void *ap, const void *bp){
	int a = *(int *)ap;
	int b = *(int *)bp;
	if (a > b) return 1;
	if (b > a) return -1;
	return 0;
}

int intReverseCmp(const void *a, const void *b){
	return -intCmp(a,b);
}

int stalls[MAXNUM];
int stallNum, canPurchase;

int main(void){
	openFiles();
	int i, answer;

	read("%d %*d %d", &canPurchase, &stallNum);

	for (i = 0; i < stallNum; i++){
		read("%d", &stalls[i]);
	}

	qsort(stalls, stallNum, sizeof(int), intCmp);

	answer = stalls[stallNum-1] - stalls[0] + 1;

	for (i = 1; i < stallNum; i++){
		stalls[i-1] = stalls[i] - stalls[i-1] - 1;
	}

	int spaceNum = stallNum - 1;
	qsort(stalls, spaceNum, sizeof(int), intReverseCmp);

	canPurchase--;
	if (canPurchase > spaceNum) canPurchase = spaceNum;

	for (i = 0; i < canPurchase; i++){
		answer -= stalls[i];
	}

	print("%d\n", answer);
	return 0;
}
