/*
    ID: frceped1
    LANG: C
    TASK: ditch
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("ditch.in", "r", stdin); freopen("ditch.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXM 210

int min(int a, int b){
	return a < b ? a : b;
}

int graph[MAXM][MAXM];
int N, M;

int last[MAXM], flow[MAXM];
bool visited[MAXM];

int maxFlow(void){
	int answer = 0;

	while (true){ // try a new path
		int i, l;

		for (i = 1; i <= M; i++){
			last[i] = -1;
			flow[i] = 0;
			visited[i] = false;
		}

		flow[1] = 1<<30;

		while (true){ // Dijkstra's algorithm
			int best = -1, bestFlow = 0;

			for (i = 1; i <= M; i++){
				if (!visited[i] && bestFlow < flow[i]){
					bestFlow = flow[i];
					best = i;
				}
			}

			visited[best] = true;

			if (best == M || best == -1)
				break;

			for (i = 1; i <= M; i++){
				if (flow[i] < min(bestFlow, graph[best][i])){
					last[i] = best;
					flow[i] = min(bestFlow, graph[best][i]);
				}
			}
		}

		if (!visited[M])
			break;

		for (i = M; i != 1; i = last[i]){
			int l = last[i];
			graph[l][i] -= flow[M];
			graph[i][l] += flow[M];
		}

		answer += flow[M];
	}

	return answer;
}

int main(void){
	int i;

	openFiles();

	scanf("%d %d", &N, &M);

	while (N--){
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		graph[s][e] += c;
	}

	printf("%d\n", maxFlow());

	return 0;
}
