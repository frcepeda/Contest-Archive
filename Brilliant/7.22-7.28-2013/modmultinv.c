#include <stdio.h>

typedef struct {
	long long int first, second;
} pair;

int gcd(int a, int b){
	int c;
	while (b){
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

pair exgcd(long long int a, long long int b){
	if (b == 0){
		pair p = {1,0};
		return p;
	} else {
		long long int r = a / b;
		long long int s = a % b;
		pair x = exgcd(b, s);
		pair p = {x.second, x.first - r * x.second};
		return p;
	}
}

int modMultInv(int R, int M){
	long long int ret = exgcd(R, M).first;
	if (ret < 0)
		ret = -(-ret % M) + M;
	return (int)(ret % 1000);
}

int main(void){
	int R, M, acc = 0;

	while (scanf("%d %d", &R, &M) != EOF)
		if (gcd(R, M) == 1)
			acc = (acc + modMultInv(R, M)) % 1000;

	printf("%d\n", acc);

	return 0;
}
