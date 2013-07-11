#include <stdio.h>
#include <stdbool.h>

#define MAXN 22

int min(int a, int b){
	return a < b ? a : b;
}

int C, K, N;
int seg[MAXN][2];
int tmp[MAXN][2];

#define contains(a,b) (a[0] <= b[0] && b[1] <= a[1])

bool works(int n){
	int i, j;

	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			if (tmp[i][0] < tmp[j][1] && tmp[j][0] < tmp[i][1] &&
			    !(contains(tmp[i],tmp[j]) || contains(tmp[j],tmp[i])))
				return false;

	return true;
}

int main(void){
	int i, k;

	scanf("%d", &C);

	while (C--){
		int best = MAXN;

		scanf("%d %d", &K, &N);

		if (N > MAXN){
			printf("11\n");
			continue;
		}

		for (i = 0; i < N; i++){
			scanf("%d %d", &seg[i][0], &seg[i][1]);
			if (seg[i][0] > seg[i][1]){
				k = seg[i][0];
				seg[i][0] = seg[i][1];
				seg[i][1] = k;
			}
		}

		for (k = 0; k < (1<<N); k++){
			int n = 0;

			for (i = 0; i < N; i++){
				if (k & (1<<i)){
					tmp[n][0] = seg[i][0];
					tmp[n++][1] = seg[i][1];
				}
			}

			if (works(n))
				best = min(best, N-n);
		}

		printf("%d\n", best);
	}

	return 0;
}
