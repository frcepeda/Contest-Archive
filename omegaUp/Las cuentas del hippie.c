#include <stdio.h>

#define MAXN 60100

int beads[MAXN];
int N, C;

int main(void){
	int i, j, c = 0, best = 100000;

	scanf("%d %d", &C, &N);

	for (i = 0; i < N; i++){
		scanf("%d", &beads[i]);
		beads[i+N] = beads[i];
	}

	N *= 2;

	for (i = j = 0; i < N; i++){
		for (; c < C && j < N; j++)
			if (!beads[j])
				c++;

		if (c == C && j - i - C < best)
			best = j - i - C;

		if (!beads[i]) c--;
	}

	printf("%d\n", best);

	return 0;
}
