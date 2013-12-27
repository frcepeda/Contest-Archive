#include <stdio.h>

int main(void){
	unsigned long long N, lo, hi, mid;

	scanf("%llu", &N);

	lo = 0;
	hi = 1LL<<31;

	while (lo < hi){
		mid = (lo + hi)/2;
		if (mid*(mid+1) >= 2*N)
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%llu\n", hi);
 
	return 0;
}
