// Accepted
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000100

int N, K;
int batt[MAXN];

int intCmp(const int *ap, const int *bp){
	return *ap - *bp;
}

bool works(int d){
	int i, rem = 0;
	int nRem = N;

	for (i = 0; nRem && i < 2*N*K - 1; i++){
		if (batt[i+1] - batt[i] <= d){
			rem += 2 * (K-1);
			nRem--;
			i++;
		} else {
			if (!rem)
				return false;
			else
				rem--;
		}
	}

	return nRem == 0;
}

int main(void){
	int i, lo, hi, mid;

	while (scanf("%d %d", &N, &K) != EOF){
		for (i = 0; i < 2*N*K; i++)
			scanf("%d", &batt[i]);

		qsort(batt, 2*N*K, sizeof(int), intCmp);

		lo = 0;
		hi = 1<<30;

		while (lo < hi){
			mid = lo + (hi - lo) / 2;

			if (works(mid))
				hi = mid;
			else
				lo = mid + 1;
		}

		printf("%d\n", hi);
	}

	return 0;
}
