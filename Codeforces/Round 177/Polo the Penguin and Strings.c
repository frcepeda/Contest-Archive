#include <stdio.h>

int N, K;

int main(void){
	int i;

	scanf("%d %d", &N, &K);

	if (K > N || (K == 1 && N > 1)){
		printf("-1\n");
		return 0;
	}

	i = 0;
	while (N-- > 0){
		putchar(i + 'a');

		if (N <= K - 1){
			i++;
		} else {
			i ^= 1;
		}

		if (N == K && i == 1){
			putchar(1 + 'a');
			putchar(0 + 'a');
			i = 2;
			N -= 2;
		}
	}

	putchar('\n');

	return 0;
}
