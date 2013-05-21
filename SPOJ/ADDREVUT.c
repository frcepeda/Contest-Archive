#include <stdio.h>

unsigned int N, P, Pr;

unsigned int reverse(unsigned int x){
	unsigned int ret = 0;
	while (x){
		ret *= 10;
		ret += x % 10;
		x /= 10;
	}
	Pr = ret;
	return ret;
}

#define isPal(x) (x == reverse(x))

int main(void){
	scanf("%d", &N);

	while (N--){
		int i = 0;

		scanf("%d", &P);

		for (; !isPal(P); i++)
			P = P + Pr;

		printf("%d %u\n", i, P);
	}

	return 0;
}
