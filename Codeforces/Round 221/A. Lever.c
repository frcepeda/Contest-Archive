#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXS 1000100

long long int acc = 0;
int N;
char str[MAXS];

int main(void){
	int i, j;

	while (!isspace(str[N++] = getchar()));
	N--;

	for (i = 0; i < N && str[i] != '^'; i++);

	for (j = 0; j < N; j++)
		if (isdigit(str[j]))
			acc += (i-j)*(str[j] - '0');

	if (!acc)
		printf("balance\n");
	else if (acc > 0)
		printf("left\n");
	else
		printf("right\n");

	return 0;
}
