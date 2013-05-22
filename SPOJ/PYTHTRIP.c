#include <stdio.h>

int N;

int intsqrt(int x){
	int lo = 0, hi = x, mid;

	while (lo < hi){
		mid = (lo + hi) / 2;

		if (mid * mid >= x)
			hi = mid;
		else
			lo = mid + 1;
	}

	return hi;
}

int main(void){
	int A, B, C;

	scanf("%d", &N);

	while (N--){
		scanf("%d %d", &A, &B);

		C = intsqrt(A*A + B*B);

		if (A*A + B*B == C*C)
			printf("YES %d\n", C);
		else
			printf("NO\n");
	}

	return 0;
}
