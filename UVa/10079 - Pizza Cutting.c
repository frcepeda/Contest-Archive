// Accepted
#include <stdio.h>

int main(void){
	long long int n;
	while (scanf("%lld", &n), n >= 0)
		printf("%lld\n", n*(n+1)/2 + 1);
	return 0;
}
