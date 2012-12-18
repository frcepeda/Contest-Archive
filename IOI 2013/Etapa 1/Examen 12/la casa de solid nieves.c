#include <stdio.h>

#define MAXP 510
#define INFINITY (1<<30)

unsigned int dist[MAXP][MAXP];
int C, P, F;
int cities[MAXP];

int bestDist = INFINITY, best;

unsigned int min(unsigned int a, unsigned int b){
	return a < b ? a : b;
}

int main(void){
	int i, j, k;

	scanf("%d %d %d", &P, &F, &C);

	for (i = 0; i < F; i++)
		scanf("%d", &cities[i]);

	for (i = 1; i <= P; i++)
		for (j = 1; j <= P; j++)
			if (i != j)
				dist[i][j] = INFINITY;

	for (i = 0; i < C; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (c < dist[a][b])
			dist[a][b] = dist[b][a] = c;
	}

	for (k = 1; k <= P; k++)
		for (i = 1; i <= P; i++)
			for (j = 1; j <= P; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (i = 1; i <= P; i++){
		int tmp = 0;

		for (j = 0; j < F; j++)
			tmp += dist[i][cities[j]];

		if (tmp < bestDist){
			bestDist = tmp;
			best = i;
		}
	}

	printf("%d\n", best);

	return 0;
}
