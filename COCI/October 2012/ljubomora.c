#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXM 300010

int N, M;
int colors[MAXM];

bool try(int max){
	int i, remaining = N;
	int tmp, required;

	for (i = 0; i < M; i++){
		tmp = colors[i];
		required = tmp/max;
		required += !!(tmp % max);

		if (required <= remaining)
			remaining -= required;
		else
			return false;
	}

	return true;
}

int main(void){
	int i, hi, lo = 1, mid, best;

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++)
		scanf("%d", &colors[i]);

	best = hi = 1000000000;

	while (lo <= hi){
		mid = (lo+hi)/2;

		if (try(mid)){
			hi = mid - 1;
			if (mid < best)
				best = mid;
		} else {
			lo = mid + 1;
		}
	}

	printf("%d\n", best);

	return 0;
}
