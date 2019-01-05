#include <stdio.h>

int main(){
	int N, a, b;
	scanf("%d", &N);
	while (N--){
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}
	return 0;
}