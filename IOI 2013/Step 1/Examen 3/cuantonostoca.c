#include <stdio.h>
#include <stdbool.h>

#define MAXN 100010

int N, A;
int C[MAXN];

int acc;

bool test(int num){
	int remaining = A, tmp = 0, i = 0;

	while (remaining--){
		while (tmp < num){
			if (i < N)
				tmp = C[i++];
			else
				return false;
		}
		tmp -= num;
	}

	return true;
}

int main(void){
	int i;

	scanf("%d %d", &N, &A);

	for (i = 0; i < N; i++){
		scanf("%d", &C[i]);
		acc += C[i];
	}

	int hi = acc, lo = 0, mid, best = 0;

	while (lo <= hi){
		mid = (hi+lo)/2;
		if (test(mid)){
			if (mid > best)
				best = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	printf("%d\n", best);

	return 0;
}

