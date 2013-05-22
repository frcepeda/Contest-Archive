#include <stdio.h>
#include <stdlib.h>

#define MAXN 20010

int intCmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int T, N, K;
int height[MAXN];

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int i;

	scanf("%d", &T);

	while (T--){
		int best = 1<<30;

		scanf("%d %d", &N, &K);

		for (i = 0; i < N; i++)
			scanf("%d", &height[i]);

		qsort(height, N, sizeof(int), intCmp);

		for (i = 0; i + K <= N; i++)
			best = min(best, height[i+K-1] - height[i]);

		printf("%d\n", best);
	}

	return 0;
}
