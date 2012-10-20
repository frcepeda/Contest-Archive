#include <stdio.h>
#include <stdlib.h>

#define MAXN 300010

int intCmp(const void *ap, const void *bp){
	if (*(int *)ap > *(int *)bp)
		return 1;
	if (*(int *)bp > *(int *)ap)
		return -1;
	return 0;
}

int N;
int points[MAXN];

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int i, answer = 1, best = 0, nextVal = 1;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &points[i]);

	qsort(points, N, sizeof(int), intCmp);

	for (i = N-2; i >= 0; i--){
		int me = points[i] + N;
		best = max(best, points[i+1] + nextVal++);
		if (me >= best)
			answer++;
	}

	printf("%d\n", answer);

	return 0;
}
