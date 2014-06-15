// Accepted
#include <stdio.h>

int main(void){
	long long int i;
	for (i = 0; i < 50000; i++)
		printf("%lld\n", i | (i << 32));
	return 0;
}
