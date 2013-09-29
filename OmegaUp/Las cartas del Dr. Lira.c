// 100 points
#include <stdio.h>

#define MAXN 55

int N;
char str[MAXN];

int main(void){
	int i, A = 0, B = 0;

	scanf("%d", &N);
	scanf("%s", str);

	for (i = 0; i < N; i++)
		A += str[i] == 'B' == i % 2;

	for (i = 0; i < N; i++)
		B += str[i] == 'B' == (i+1) % 2;

	printf("%d\n", A < B ? A : B);

	return 0;
}
