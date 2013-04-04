#include <stdio.h>

#define MAXN 100*100 + 10

int numbers[MAXN];
int N, M, D;

int abs(int a){
	return a < 0 ? -a : a;
}

int intCmp(const int *a, const int *b){
	return *a - *b;
}

int main(void){
	int i, j;

	scanf("%d %d %d", &N, &M, &D);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &numbers[i*M + j]);

	N *= M;

	int m = numbers[0] % D;
	for (i = 1; i < N; i++){
		if (numbers[i] % D != m){
			printf("-1\n");
			return 0;
		}
	}

	qsort(numbers, N, sizeof(numbers[0]), intCmp);

	int answer = 0;

	for (i = 0; i < N; i++)
		answer += abs(numbers[N/2] - numbers[i])/D;

	printf("%d\n", answer);

	return 0;
}
