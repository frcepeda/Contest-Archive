#include <stdio.h>

#define C 10000000

int cnt(int x){
	int r = 0;
	for (; x; x /= 10) r += x % 10;
	return r;
}

int main(void){
	int N, i;

	scanf("%d", &N);

	for (i = N; cnt(i % C) != 21; i++);

	printf("%d %07d\n", (i - N + C) % C, i % C);

	return 0;
}
