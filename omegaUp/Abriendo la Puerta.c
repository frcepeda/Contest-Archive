#include <stdio.h>

#define MAXN 20010

int P, R, next[MAXN], prev[MAXN];

int main(void){
	int i, j, k;

	scanf("%d %d", &P, &R);

	for (i = 1; i <= P; i++){
		next[i] = i + 1;
		prev[i] = i - 1;
	}
	next[P] = 1;
	prev[1] = P;

	j = 1;
	for (i = 0; i < P-1; i++){
		next[prev[j]] = next[j];
		prev[next[j]] = prev[j];

		for (scanf("%d", &k); k > 0; k--)
			j = next[j];
	}

	printf("%d\n", 1 + (P + R - j) % P);

	return 0;
}
