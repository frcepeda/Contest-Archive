/*
    ID: frceped1
    LANG: C
    TASK: cowtour
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("cowtour.in", "r", stdin); freopen("cowtour.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 155
#define INF (10000000)

typedef struct {
	int x, y;
} point;

#define pointdist(a,b) (sqrt(pow(abs(a.x-b.x),2)+pow(abs(a.y-b.y),2)))

int N;

point pastures[MAXN];
double dist[MAXN][MAXN];
bool adj[MAXN][MAXN];

double mostdistant[MAXN];

int main(void){
	openFiles();

	int i, j, k;
	double best = INF;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			dist[i][j] = INF;

	for (i = 0; i < N; i++)
		dist[i][i] = 0;

	for (i = 0; i < N; i++)
		scanf("%d %d", &pastures[i].x, &pastures[i].y);

	do
		k = getchar();
	while (k != '0' && k != '1');
	ungetc(k, stdin);

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			adj[i][j] = getchar() == '1';
			if (adj[i][j])
				dist[i][j] = pointdist(pastures[i], pastures[j]);
		}
		getchar();
	}

	for (k = 0; k < N; k++)
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (dist[i][j] != INF && mostdistant[i] < dist[i][j])
				mostdistant[i] = dist[i][j];

	for (i = 0; i < N; i++)
		for (j = i+1; j < N; j++)
			if (dist[i][j] == INF && mostdistant[i] + mostdistant[j] + pointdist(pastures[i], pastures[j]) < best)
				best = mostdistant[i] + mostdistant[j] + pointdist(pastures[i], pastures[j]);

	for (i = 0; i < N; i++)
		for (j = i+1; j < N; j++)
			if (dist[i][j] != INF && dist[i][j] > best)
				best = dist[i][j];

	printf("%.6lf\n", best);

	return 0;
}
