#include <stdio.h>

long long n, M;

long long fib[2][2] = {{1,1},{1,0}};
long long c[2][2] = {{1,0},{0,1}};

void mult(long long a[2][2], long long b[2][2]){
	long long a00 = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % M;
	long long a01 = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % M;
	long long a10 = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % M;
	long long a11 = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % M;
	a[0][0] = a00;
	a[0][1] = a01;
	a[1][0] = a10;
	a[1][1] = a11;
}

int main(void){
	scanf("%lld %lld", &n, &M);

	if (n == 0){
		printf("0\n");
		return 0;
	}

	for (n--; n > 0; n /= 2){
		if (n % 2)
			mult(c, fib);
		mult(fib, fib);
	}

	printf("%lld\n", c[0][0]);

	return 0;
}
