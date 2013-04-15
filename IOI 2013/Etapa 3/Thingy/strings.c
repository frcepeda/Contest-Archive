#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1010
#define MAXM MAXN
#define MAXALPHA 'z'
#define BASE 31

int max(int a, int b){
	return a > b ? a : b;
}

char words[MAXN][MAXM];
int wordLen[MAXN];
int wordIdx[MAXN];
int N, maxM;

unsigned long long int baseN[MAXM];
unsigned long long int hash[MAXN][MAXM];

int wordCmp(const int *a, const int *b){
	int lo = 0, hi = max(wordLen[*a], wordLen[*b]), mid;

	while (lo < hi){
		mid = (lo + hi) / 2;
		if (hash[*a][mid] == hash[*b][mid])
			lo = mid + 1;
		else
			hi = mid;
	}

	return words[*a][hi] - words[*b][hi];
}

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%s", words[i]);
		wordLen[i] = strlen(words[i]);
		wordIdx[i] = i;
		maxM = max(maxM, wordLen[i]);
	}

	baseN[0] = 1;
	for (i = 1; i < maxM; i++)
		baseN[i] = baseN[i-1] * BASE;

	for (i = 0; i < N; i++){
		hash[i][0] = words[i][0] - 'a';
		for (j = 1; j < wordLen[i]; j++)
			hash[i][j] = words[i][j-1] * BASE + words[i][j] - 'a';
	}

	qsort(wordIdx, N, sizeof(wordIdx[0]), (int (*)(const void *, const void *)) wordCmp);

	for (i = 0; i < N; i++)
		printf("%s\n", words[wordIdx[i]]);

	return 0;
}
