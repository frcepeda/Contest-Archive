#include <stdio.h>
#include <stdbool.h>

#define MAXN 100010

unsigned int times[MAXN];
unsigned int N, M;

bool works(unsigned long long int time){
	int i;
	unsigned long long int checkedIn = 0;

	for (i = 0; i < N; i++)
		checkedIn += time / times[i];

	return checkedIn >= M;
}

int main(void){
	int i;

	scanf("%u %u", &N, &M);

	for (i = 0; i < N; i++)
		scanf("%u", &times[i]);

	unsigned long long int lo = 1, mid, hi = 1000000000000000010;

	while (lo < hi){
		mid = (lo + hi) / 2;

		if (works(mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%llu\n", hi);

	return 0;
}
