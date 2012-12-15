#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXLEN 20
#define MAXN 2510

int N;
int answer;

char sto[MAXN][MAXLEN];
char *list[MAXN];

char stoUnsort[MAXN][MAXLEN];
char *unsorted[MAXN];

int strcmp_q(const void *a, const void *b){
	return strcmp(*(char **)a, *(char **)b);
}

char *find(char *str){
	int lo = 0, hi = N, mid;

	while (lo < hi){
		mid = (lo + hi) / 2;
		int cmp = strcmp(str, list[mid]);

		if (cmp == 0)
			return list[mid];
		else if (cmp > 0)
			lo = mid + 1;
		else
			hi = mid;
	}

	return NULL;
}

int main(void){
	int i, j;

	scanf("%d", &N);
	
	for (i = 0; i < N; i++){
		scanf("%s", sto[i]);
		list[i] = sto[i];
	}

	for (i = 0; i < N; i++){
		scanf("%s", stoUnsort[i]);
		unsorted[i] = stoUnsort[i];
	}

	qsort(list, N, sizeof(char *), strcmp_q);

	for (i = 0; i < N; i++)
		for (j = i+1; j < N; j++)
			if (find(unsorted[i]) < find(unsorted[j]))
				answer++;

	printf("%d/%d\n", answer, N*(N-1)/2);

	return 0;
}
