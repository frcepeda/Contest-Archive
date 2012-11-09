#include <stdio.h>

#define MAXN 20
#define MAXBITS (1<<N)

int best = 1000000;
int N, B;
int values[MAXN];

int main(void){
	int i, j, sum;

	scanf("%d %d", &N, &B);

	for (i = 0; i < N; i++)
		scanf("%d", &values[i]);

	for (i = 0; i < MAXBITS; i++){
		for (j = 0, sum = 0; j < N; j++)
			if (i & (1<<j))
				sum += values[j];
		if (sum >= B && sum-B < best)
			best = sum-B;
	}

	printf("%d\n", best);

	return 0;
}
