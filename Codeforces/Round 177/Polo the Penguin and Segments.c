#include <stdio.h>

int N, K, count;

int main(void){
	int a, b;

	scanf("%d %d", &N, &K);

	while (N--){
		scanf("%d %d", &a, &b);
		count += b - a + 1;
	}

	printf("%d\n", (K - (count % K)) % K);

	return 0;
}
