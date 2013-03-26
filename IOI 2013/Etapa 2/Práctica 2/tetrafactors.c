#include <stdio.h>

#define MAXN 5200000

char divisors[MAXN];

int main(void){
	int N, i, j;

	scanf("%d", &N);

	for (i = 2; i <= MAXN; i++)
		if (divisors[i] <= 3)
			for (j = i; j <= MAXN; j += i)
				divisors[j]++;

	for (i = 2; i <= MAXN; i++){
		if (divisors[i] == 3)
			N--;
		if (!N){
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}
