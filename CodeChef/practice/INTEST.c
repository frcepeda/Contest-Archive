#include <stdio.h>

int main(void){
	int N, K, answer = 0;

	scanf("%d %d", &N, &K);

	int curr;
	while (N--){
		scanf("%d", &curr);
		answer += curr % K == 0;
	}

	printf("%d\n", answer);
	
	return 0;
}
