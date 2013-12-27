#include <stdio.h>
#include <stdbool.h>

#define MAXK 10000100

bool win[MAXK];
int N, K;

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 1; i < MAXK; i++)
		for (j = i; !win[i] && j != 0; j /= 10)
			if (j % 10 && !win[i-j%10])
				win[i] = true;

	while (N--){
		scanf("%d", &K);
		printf("%d\n", win[K]);
	}

	return 0;
}
