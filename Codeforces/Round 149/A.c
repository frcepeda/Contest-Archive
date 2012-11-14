#include <stdio.h>
#include <stdbool.h>

int x, y, a, b;

int main(void){
	int i, j;
	int count = 0;

	scanf("%d %d %d %d", &x, &y, &a, &b);

	for (i = a; i <= x; i++)
		for (j = b; j <= y && j < i; j++)
			count++;

	printf("%d\n", count);
	for (i = a; i <= x; i++)
		for (j = b; j <= y && j < i; j++)
			printf("%d %d\n", i, j);

	return 0;
}

