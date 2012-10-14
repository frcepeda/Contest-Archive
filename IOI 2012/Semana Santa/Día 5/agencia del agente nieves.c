#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXNUM 1000+5

int ascending(const void *ap, const void *bp){
	int a = *(int *)ap;
	int b = *(int *)bp;
	if (a > b) return 1;
	if (b > a) return -1;
	return 0;
}

int descending(const void *a, const void *b){
	return -ascending(a,b);
}

int from[MAXNUM];
int to[MAXNUM];
int length;

int willTake[MAXNUM];
int takeNum;
int willPlace[MAXNUM];
int placeNum;

int tax[MAXNUM];
int willTest[MAXNUM];
int testNum;

long long int baseCost;
long long int answer;
long long int lastAnswer = -1;

void read(int *seq){
	int i;
	for (i = 0; i < length; i++){
		char c;
		do {
			c = getchar();
		} while (!isdigit(c));
		seq[i] = c - '0';
	}
}

void calculateAnswer(void){
	int i;

	qsort(willTake, takeNum, sizeof(int), descending);
	qsort(willPlace, placeNum, sizeof(int), ascending);

	answer = 0;

	int lastCost = baseCost;
	for (i = 0; i < takeNum; i++){
		lastCost -= willTake[i];
		answer += lastCost;
	}

	for (i = 0; i < placeNum; i++){
		lastCost += willPlace[i];
		answer += lastCost;
	}

	if (lastAnswer == -1 || answer < lastAnswer){
		lastAnswer = answer;
	}
}

int main(void){
	int i;

	scanf("%d", &length);

	read(from);
	read(to);

	for (i = 0; i < length; i++){
		scanf("%d", &tax[i]);
	}

	for (i = 0; i < length; i++){
		if (from[i] && !to[i]){
			baseCost += tax[i];
			willTake[takeNum++] = tax[i];
		} else if (!from[i] && to[i]) {
			willPlace[placeNum++] = tax[i];
		} else if (from[i] && to[i]) {
			baseCost += tax[i];
			willTest[testNum++] = tax[i];
		}
	}

	calculateAnswer();

	qsort(willTest, testNum, sizeof(int), descending);

	for (i = 0; i < testNum; i++){
		willTake[takeNum++] = willTest[i];
		willPlace[placeNum++] = willTest[i];
		calculateAnswer();
	}

	printf("%lld\n", lastAnswer);

	return 0;
}

