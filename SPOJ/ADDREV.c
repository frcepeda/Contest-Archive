#include <stdio.h>

unsigned int N, A, B;

unsigned int reverse(unsigned int x){
	unsigned int ret = 0;
	while (x){
		ret *= 10;
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int main(void){
	scanf("%d", &N);

	while (N--){
		int i = 0;

		scanf("%d %d", &A, &B);

		printf("%u\n", reverse(reverse(A) + reverse(B)));
	}

	return 0;
}
