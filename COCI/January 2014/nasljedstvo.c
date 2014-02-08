#include <stdio.h>

int N, O;

int main(void){
	scanf("%d %d", &N, &O);
	int t;
	for (t = 0; (O+t)/N != t; t++);
	printf("%d %d\n", O + t, O + O/(N-1));
	return 0;
}
