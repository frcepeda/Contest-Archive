#include <stdio.h>

#define MAXN 1000

long long int N;
long long int seq[MAXN], hi[MAXN], lo[MAXN];
long long int best;

long long int max(long long int a, long long int b){
	return a > b ? a : b;
}

long long int min(long long int a, long long int b){
	return a < b ? a : b;
}

int main(void){
	long long int i;

	for (; scanf("%lld", &seq[N]) != EOF; N++);

	if (seq[0] > 0)
		hi[0] = best = seq[0];
	else
		lo[0] = best = seq[0];

	for (i = 1; i < N; i++){
		if (seq[i] > 0){
			hi[i] = hi[i-1] * seq[i];
			lo[i] = lo[i-1] * seq[i];
		} else if (seq[i] < 0){
			hi[i] = lo[i-1] * seq[i];
			lo[i] = hi[i-1] * seq[i];
		} else hi[i] = lo[i] = 0;

		hi[i] = max(hi[i], seq[i]);
		lo[i] = min(lo[i], seq[i]);

		best = max(best, hi[i]);
	}

	printf("%lld\n", best);

	return 0;
}
