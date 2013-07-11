#include <stdio.h>
#include <stdbool.h>

#define MAXP 1500000

int n;
bool notPrime[MAXP];

int main(void){
	int i, j;

	scanf("%d", &n);

	notPrime[0] = notPrime[1] = true;

	for (i = 4; i < MAXP; i += 2)
		notPrime[i] = true;

	for (i = 3; i < 1500; i += 2)
		if (!notPrime[i])
			for (j = i*i; j < MAXP; j += i)
				notPrime[j] = true;

	for (i = 2; n; i++)
		if (!notPrime[i])
			printf("%d%c", i, --n ? ' ' : '\n');

	return 0;
}
