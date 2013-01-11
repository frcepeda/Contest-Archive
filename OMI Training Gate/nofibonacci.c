#include <stdio.h>

int fib[30000] = {1, 2};
int next = 2, N;

int main(void){
	int i, j = 4;

	scanf("%d", &N);

	for (; fib[next-1] < N; next++)
		fib[next] = fib[next-1] + fib[next-2];

	for (i = 1; j = fib[i-1] + 1, i < next; i++)
		while (fib[i] > j && j < N)
			printf("%d ", j++);

	printf("\n");

	return 0;
}
