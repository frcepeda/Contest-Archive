#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

#define MAXN (100*10)

int M;

bool notPrime[MAXN];

int main(void){
	int i, j;

	scanf("%d", &M);

	for (j = 4; j < MAXN; j += 2)
		notPrime[j] = true;

	for (i = 3; i < MAXN; i += 2)
		if (!notPrime[i])
			for (j = i*i; j < MAXN; j += i)
				notPrime[j] = true;

	while (M--){
		char x[110];
		scanf("%s", x);
		for (i = j = 0; x[i]; i++) j += x[i] - '0';
		printf("%sUltraPrimo\n", notPrime[j] ? "No " : "");
	}

	return 0;
}
