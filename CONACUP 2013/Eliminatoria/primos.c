#include <stdio.h>

#define MAXK 50000100
#define LIM 8000

int N, K;
int isNotPrime[MAXK];

int main(void){
	int i, j;

	isNotPrime[2] = 1;
	for (i = 4; i < MAXK; i += 2)
		isNotPrime[i] = 1;

	for (i = 3; i < LIM; i += 2)
		if (!isNotPrime[i])
			for (j = i*i; j < MAXK; j += i)
				isNotPrime[j] = 1;

	for (i = 1; i < MAXK; i++)
		isNotPrime[i] = isNotPrime[i-1] + !isNotPrime[i];

	scanf("%d", &N);

	while (N--){
		scanf("%d", &K);
		printf("%d\n", isNotPrime[K-1]);
	}

	return 0;
}
