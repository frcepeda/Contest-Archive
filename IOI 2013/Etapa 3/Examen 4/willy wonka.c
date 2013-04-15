#include <stdio.h>

#define MAXN 1010

unsigned long long int min(unsigned long long int a, unsigned long long int b){
	return a < b ? a : b;
}

int N, A;
unsigned long long int candy[MAXN], totalCandy;
unsigned long long int bestWaste = 1<<30, best;

unsigned long long int possibleCandy(int B, int K){
	unsigned long long int i, ret = 0;

	for (i = 0; i < N; i++)
		ret += min(candy[i], B);

	return ret;
}

int tryK(int K){
	unsigned long long int lo = 0, hi = 1LL<<60, mid;

	while (lo < hi){
		mid = (lo + hi) / 2;
		if (possibleCandy(mid, K) >= mid * K)
			lo = mid + 1;
		else
			hi = mid;
	}

	lo--;

	return totalCandy - lo * K;
}

int main(void){
	int i;

	scanf("%d %d", &N, &A);

	for (i = 0; i < N; i++){
		scanf("%llu", &candy[i]);
		totalCandy += candy[i];
	}

	for (i = A; i <= N; i++){
		int waste = tryK(i);
		if (waste <= bestWaste){
			bestWaste = waste;
			best = i;
		}
	}

	printf("%llu\n", best);

	return 0;
}
