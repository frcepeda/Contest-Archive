#include <stdio.h>
#include <stdlib.h>

#define MAXN 5010

int skills[MAXN];

int intCmp(const void *ap, const void *bp){
	int a = *((int *)ap);
	int b = *((int *)bp);
	if (a > b) return 1;
	if (b > a) return -1;
	return 0;
}

int main(void){
	int T, N, i, best;

	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);

		for (i = 0; i < N; i++)
			scanf("%d", &skills[i]);

		qsort(skills, N, sizeof(int), intCmp);

		unsigned int best = 1<<31;
		for (i = 0; i < N-1; i++)
			if (best > skills[i+1]-skills[i])
				best = skills[i+1]-skills[i];

		printf("%u\n", best);
	}

	return 0;
}

