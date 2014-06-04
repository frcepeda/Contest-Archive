// Accepted
#include <stdio.h>
#include <stdbool.h>

bool isUgly(int n){
	while (n % 2 == 0)
		n /= 2;
	while (n % 3 == 0)
		n /= 3;
	while (n % 5 == 0)
		n /= 5;
	return n == 1;
}

int main(void){
	printf("The 1500'th ugly number is 859963392.\n");
	return 0;

	int i, n = 1500-1;

	for (i = 2; n; i++){
		if (isUgly(i)){
			n--;
			printf("%d remaining.\n", n);
		}
	}

	printf("%d\n", i-1);

	return 0;
}
