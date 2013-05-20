#include <stdio.h>

int T, N;

#define sum(x) ((x)*(x+1)/2)

int main(void){
	scanf("%d", &T);

	while (T--){
		unsigned long long int k, l, m;
		scanf("%d", &N);

		N--;

		k = N/3;
		l = N/5;
		m = N/15;

		printf("%llu\n", 3*sum(k) + 5*sum(l) - 15*sum(m));
	}

	return 0;
}
