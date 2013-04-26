/*
    ID: frceped1
    LANG: C
    TASK: stall4
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("stall4.in", "r", stdin); freopen("stall4.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 210

int N, M;
const int source = 0, sink = MAXN*2-1;

int graph[MAXN*2][MAXN*2];
int flow[MAXN*2], parent[MAXN*2];
bool visited[MAXN*2];

int min(int a, int b){
	return a < b ? a : b;
}

int maxFlow(void){
	int ret = 0;

	while (true){
		int i, l;

		for (i = 0; i < MAXN*2; i++)
			parent[i] = flow[i] = visited[i] = 0;
		flow[0] = 1<<30;

		while (true){
			int best = -1, bestFlow = 0;

			for (i = 0; i < MAXN*2; i++){
				if (!visited[i] && flow[i] > bestFlow){
					best = i;
					bestFlow = flow[i];
				}
			}

			visited[best] = true;

			if (best == sink || best == -1)
				break;

			for (i = 0; i < MAXN*2; i++){
				if (flow[i] < min(bestFlow, graph[best][i])){
					flow[i] = min(bestFlow, graph[best][i]);
					parent[i] = best;
				}
			}
		}

		if (flow[sink] == 0)
			break;

		for (i = sink; i != source; i = parent[i]){
			l = parent[i];
			graph[l][i] -= flow[sink];
			graph[i][l] += flow[sink];
		}

		ret += flow[sink];
	}

	return ret;
}

int main(void){
	int i, j, k;

	openFiles();

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++){
		graph[source][i] = 1;

		scanf("%d", &j);
		while (j--){
			scanf("%d", &k);
			graph[i][k+MAXN] = 1;
		}
	}

	for (i = 1; i <= M; i++)
		graph[i+MAXN][sink] = 1;

	printf("%d\n", maxFlow());

	return 0;
}
