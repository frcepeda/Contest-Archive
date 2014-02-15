// 80/80 points
#include <stdio.h>

#define MAXK 11
#define MAXN (1<<MAXK)

int K, N;
int labels[MAXN];
int level[MAXN];

#define two(i) (1<<(i))

void findLevels(int i, int k){
	int l = two(k-1) - 1;

	if (k > 1){
		findLevels(i, k-1);
		findLevels(i + l + 1, k-1);
	}

	level[i + l] = k;
}

int main(void){
	int i, j;

	scanf("%d", &K);
	N = (1<<K) - 1;

	for (i = 0; i < N; i++)
		scanf("%d", &labels[i]);

	findLevels(0, K);

	for (j = K; j > 0; j--){
		int fst = 1;
		for (i = 0; i < N; i++){
			if (level[i] == j){
				printf("%s%d", fst ? "" : " ", labels[i]);
				fst = 0;
			}
		}
		putchar('\n');
	}

	return 0;
}
