#include <stdio.h>

#define MAXN 500100

int N, M;
int V[MAXN];

int max(int a, int b){
	return a > b ? a : b;
}

int gcd(int a, int b){
	int c;
	while (b){
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

int main(void){
	int i, j, acc, best = 0;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		scanf("%d", &V[i]);

	for (i = 0; i < N; i++){
		acc = 0;
		for (j = i; j < N; j++){
			acc = gcd(acc, V[j]);
			if (acc >= M)
				best = max(best, j - i + 1);
			else break;
		}
	}

	printf("%d\n", best);

	return 0;
}
