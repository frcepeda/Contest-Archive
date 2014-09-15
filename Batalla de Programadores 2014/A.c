#include <stdio.h>
#include <stdlib.h>

long long int X, Y;

int main(void){
	long long int lo = 2, hi = (1LL<<40), mid;

	scanf("%lld %lld", &X, &Y);

	while (lo < hi){
		mid = (lo + hi) / 2;
		if (mid * (Y - X) >= Y * X)
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%lld\n", (mid + X - 1) / X);

	return 0;
}
