// Accepted
#include <stdio.h>

int main(void){
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
		printf("%d\n", 2*a*b);
	return 0;
}
