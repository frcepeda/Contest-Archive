#include <stdio.h>
#include <stdlib.h>

int log2_(unsigned long long int num){
	int log = -1;
	while (num != 0){
		log++;
		num >>= 1;
	}
	return log;
}

int main(void){
	long long int n, k;

	scanf("%lld %lld", &n, &k);

	if (k == 2) {
		printf("%d\n", n/2);
	} else {
		printf("%d\n", n);
	}

	return 0;
}