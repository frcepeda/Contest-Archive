#include <stdio.h>

#define MAXN 1000000

int N, answer;
int coord[MAXN][4];

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int i, j, k;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d %d %d %d", &coord[i][0], &coord[i][1], &coord[i][2], &coord[i][3]);

	for (i = 0; i < 1<<4; i++){
		int minSoFar = 1<<30;
		int maxSoFar = -(1<<30);

		for (j = 0; j < N; j++){
			int this = 0;

			for (k = 0; k < 4; k++)
				this += (1<<k) & i ? coord[j][k] : -coord[j][k];

			minSoFar = min(minSoFar, this);
			maxSoFar = max(maxSoFar, this);
		}

		answer = max(answer, maxSoFar - minSoFar);
	}


	printf("%d\n", answer);

	return 0;
}
