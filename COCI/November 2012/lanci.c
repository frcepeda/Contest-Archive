#include <stdio.h>
#include <stdlib.h>

#define MAXN 500010

int intCmp(const void *a, const void *b){
	if (*(int *)a > *(int *)b)
		return 1;
	if (*(int *)a < *(int *)b)
		return -1;
	return 0;
}

int N;
int lengths[MAXN];
int answer;

int main(void){
	int i, s, e;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &lengths[i]);

	qsort(lengths, N, sizeof(lengths[0]), intCmp);

	for (s = 0, e = N-1; s < e; s++){
		if (lengths[s] < e-s){
			e -= lengths[s];
			answer += lengths[s];
		} else {
			answer += e-s;
			break;
		}
	}

	printf("%d\n", answer);

	return 0;
}
