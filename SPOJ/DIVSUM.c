#include <stdio.h>

#define MAXN 500001

unsigned int sum[MAXN];
int T, N;

int main(void){
	int i, j;

	for (i = 1; i < MAXN; i++)
		for (j = 2*i; j < MAXN; j += i)
			sum[j] += i;
	
	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);
		printf("%u\n", sum[N]);
	}

	return 0;
}
