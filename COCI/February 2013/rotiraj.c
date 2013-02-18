#include <stdio.h>

#define MAXN 100010
#define MAXQ MAXN

int seq[MAXN];
int nums[MAXN];
int N, K, Q;

int mod(int n, int m){
	while (n < 0)
		n += m;
	return n % m;
}

void rotate(int start, int end, int times){
	static int tmp[MAXN];
	int i;

	for (i = start; i < end; i++)
		tmp[i] = seq[start + mod(i - start + times, end - start)];

	for (i = start; i < end; i++)
		seq[i] = tmp[i];
}

int op[MAXQ], X[MAXQ];

int main(void){
	int i, j;

	scanf("%d %d %d", &N, &K, &Q);

	for (i = 0; i < Q; i++)
		scanf("%d %d", &op[i], &X[i]);

	for (i = 0; i < N; i++)
		scanf("%d", &seq[i]);

	for (i = Q-1; i >= 0; i--){
		if (op[i] == 2){
			rotate(0, N, X[i]);
		} else {
			for (j = 0; j < N/K; j++)
				rotate(j*K, (j+1)*K, X[i]);
		}
	}

	for (i = 0; i < N; i++)
		printf("%d ", seq[i]);
	printf("\n");

	return 0;
}
