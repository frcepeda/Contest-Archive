#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

#define MAXN 1000

char names[MAXN][11];

int N, P;

bool friendships[MAXN][MAXN];

int find(char *str){
	int hi = N, lo = 0, mid;

	while (lo < hi){
		mid = (hi+lo)/2;
		int cmp = strcmp(str, names[mid]);
		if (cmp > 0){
			lo = mid + 1;
		} else if (cmp < 0){
			hi = mid;
		} else {
			return mid;
		}
	}

	return -1; /* shouldn't happen */
}

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%s", names[i]);

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			int tmp;
			scanf("%d", &tmp);
			friendships[i][j] = !!tmp;
		}
	}

	scanf("%d", &P);

	char A[11], B[11];
	while (P--){
		scanf("%s", A);
		scanf("%s", B);
		printf("%d\n", friendships[find(A)][find(B)]);
	}

	return 0;
}

