/*
    ID: frceped1
    LANG: C
    TASK: fence
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("fence.in", "r", stdin); freopen("fence.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXNODES 510
#define MAXTOUR 2000

typedef struct {
	int node, next, other_end;
} edge;

edge graph[MAXTOUR];
int start[MAXNODES];
int nextNode = 1;

int degree[MAXNODES];

int F;

int tour[MAXTOUR];
int tourCount;

int min(int a, int b){
	return a < b ? a : b;
}

int addEdge(int a, int b){
	graph[nextNode].node = b;

	if (!start[a] || graph[start[a]].node > b){
		graph[nextNode].next = start[a];
		start[a] = nextNode;
	} else {
		a = start[a];
		while (graph[a].next && graph[graph[a].next].node < b)
			a = graph[a].next;

		graph[nextNode].next = graph[a].next;
		graph[a].next = nextNode;
	}

	return nextNode++;
}

void deleteEdge(int a, int b, int idx){
	int other_end = graph[idx].other_end;

	start[a] = graph[idx].next;

	if (start[b] == other_end){
		start[b] = graph[other_end].next;
		return;
	}

	graph[other_end].node = graph[graph[other_end].next].node;
	graph[graph[graph[other_end].next].other_end].other_end = other_end;
	graph[other_end].other_end = graph[graph[other_end].next].other_end;
	graph[other_end].next = graph[graph[other_end].next].next;
}

void eulerianTour(int node){
	int i;

	for (i = start[node]; i; i = start[node]){
		if (i == 0 || graph[i].node == 0) break;
		deleteEdge(node, graph[i].node, i);
		eulerianTour(graph[i].node);
	}

	tour[tourCount++] = node;
}

int main(void){
	openFiles();

	int start = MAXNODES;

	scanf("%d", &F);

	while (F--){
		int a, b, aPlace, bPlace;
		scanf("%d %d", &a, &b);

		aPlace = addEdge(a,b);
		bPlace = addEdge(b,a);

		graph[aPlace].other_end = bPlace;
		graph[bPlace].other_end = aPlace;

		start = min(start, min(a,b));
		degree[a]++;
		degree[b]++;
	}

	for (F = 1; F < MAXNODES; F++){
		if (degree[F] % 2){
			start = F;
			break;
		}
	}

	eulerianTour(start);

	for (tourCount--; tourCount >= 0; tourCount--)
		printf("%d\n", tour[tourCount]);

	return 0;
}
