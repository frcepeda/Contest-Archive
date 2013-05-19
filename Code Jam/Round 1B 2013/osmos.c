#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000100

int intCmp(const unsigned long long int *a, const unsigned long long int *b){
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	return 0;
}

int T, N;

unsigned long long int sizes[MAXN];

unsigned long long int min(unsigned long long int a, unsigned long long int b){
	return a < b ? a : b;
}

int bs(unsigned long long int acc, int start){
	int limit = N - start;
	int best = limit;
	int i, j;

	for (i = 1; i < limit; i++){
		acc += acc - 1;

		for (; start < N && sizes[start] < acc; start++)
			acc += sizes[start];

		best = min(best, i + (N - start));
	}

	return best;
}

int main(void){
	int t, i;
	unsigned long long int acc;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%llu %d", &acc, &N);

		for (i = 0; i < N; i++)
			scanf("%llu", &sizes[i]);

		qsort(sizes, N, sizeof(sizes[0]), intCmp);

		for (i = 0; sizes[i] < acc && i < N; i++)
			acc += sizes[i];

		printf("Case #%d: %d\n", t, bs(acc, i));
	}

	return 0;
}
