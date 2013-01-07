#include <stdio.h>

#define MAXN 100010

int A, B, N;

int main(void){
	int i, num;

	scanf("%d %d %d", &A, &B, &N);
	num = A%B;

	if (num != 0){
		for (i = 0; i <= 9; i++)
			if ((num * 10 + i) % B == 0)
				break;
		if (i <= 9){
			printf("%d%d", A, i);
		} else {
			printf("-1\n");
			return 0;
		}
	} else {
		printf("%d", A);
	}

	for (i = num != 0; i < N; i++)
		printf("0");
	printf("\n");

	return 0;
}
