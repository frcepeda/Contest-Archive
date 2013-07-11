#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	const int N = 500000;
	const int M = 3;

	srand(time(NULL));

	int i;

	printf("%d %d\n", N, M);

	for (i = 0; i < N; i++)
		printf("%d%c", rand(), i != N-1 ? ' ' : '\n');

	return 0;
}
