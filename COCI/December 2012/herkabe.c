#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAXN 3010 
#define MAXK 3010

char sto[MAXN][MAXK];
char *strings[MAXN];
int factorial[MAXN];
int N;
int answer = 1;

int strcmp_q(const void *a, const void *b){
	return strcmp(*(char **)a, *(char **)b);
}

void countStuff(int a, int b, int k){
	int groups = 1;
	int last = a, i;

	if (b - a < 1) return;

	for (i = a+1; i <= b && !strings[i][k]; i++);
	for (; i <= b; i++){
		if (strings[i][k] != strings[i-1][k]){
			groups++;
			countStuff(last, i-1, k);
			last = i;
		}
	}
	countStuff(last, b, k+1);

	answer *= factorial[groups];
	answer %= MOD;
}

int main(void){
	int i, j, k;

	scanf("%d", &N);

	factorial[0] = 1;
	for (i = 1; i <= N; i++)
		factorial[i] = (factorial[i-1] * i) % MOD;

	for (i = 0; i < N; i++){
		scanf("%s", sto[i]);
		strings[i] = sto[i];
	}

	qsort(strings, N, sizeof(char *), strcmp_q);

	countStuff(0, N-1, 0);

	printf("%d\n", answer);

	return 0;
}
