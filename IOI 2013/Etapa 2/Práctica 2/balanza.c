#include <stdio.h>

int N, G1, G2, A, B;

int gcd(int a, int b){
	int t;

	while (b != 0){
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}

int main(void){
	scanf("%d", &N);

	while (N--){
		scanf("%d %d %d %d", &G1, &G2, &A, &B);
		if (G1 < G2){
			int t = G1;
			G1 = G2;
			G2 = t;
		}
		printf("%d", ((G1 - G2) % gcd(A,B)) == 0);
	}
	printf("\n");

	return 0;
}
