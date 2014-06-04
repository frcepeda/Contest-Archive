// Accepted
#include <stdio.h>

int main(void){
	long long int a, b;
	while (scanf("%lld %lld", &a, &b) != EOF)
		printf("%lld\n", a > b ? a - b : b - a);
	return 0;
}
