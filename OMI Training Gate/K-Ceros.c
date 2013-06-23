#include <stdio.h>

typedef unsigned long long int ulli;

ulli count(ulli N){
	ulli two = 0, five = 0, t;

	for (t = N; t > 1; t /= 2)
		two += t/2;

	for (t = N; t > 1; t /= 5)
		five += t/5;

	return two < five ? two : five;
}

ulli k;

int main(void){
	ulli lo = 0, hi = (1LLU<<63), mid;

	scanf("%llu", &k);

	while (lo < hi){
		mid = lo + (hi - lo) / 2;
		if (count(mid) >= k)
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%llu\n", hi);

	return 0;
}
