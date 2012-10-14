/*
    ID: frceped1
    LANG: C
    TASK: barn1
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("barn1.in", "r", stdin); freopen("barn1.out", "w", stdout)
#else
	#define openFiles()
#endif

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

	scanf("%d %*d %d", &canPurchase, &stallNum);

	for (i = 0; i < stallNum; i++)
		scanf("%d", &stalls[i]);

	qsort(stalls, stallNum, sizeof(int), intCmp);

	answer = stalls[stallNum-1] - stalls[0] + 1;

	for (i = 1; i < stallNum; i++)
		stalls[i-1] = stalls[i] - stalls[i-1] - 1;

	int spaceNum = stallNum - 1;
	qsort(stalls, spaceNum, sizeof(int), intReverseCmp);

	canPurchase--;
	if (canPurchase > spaceNum) canPurchase = spaceNum;

	for (i = 0; i < canPurchase; i++)
		answer -= stalls[i];

	printf("%d\n", answer);

	return 0;
}
