#include <stdio.h>

int N;
int answer;

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		for (j = 1; j * j <= i; j++)
			if (i % j == 0)
				answer++;

	printf("%d\n", answer);

	return 0;
}
