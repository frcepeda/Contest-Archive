#include <stdio.h>

#define MAXN 100100

typedef struct {
	int node, next, dist;
} edge;

edge graph[MAXN*2];
int start[MAXN];
int nextEdge = 1;

void addEdge(int a, int b, int c){
	graph[nextEdge].node = b;
	graph[nextEdge].dist = c;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int N;

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

int best, bestDist = 1<<30;

int worstCase[MAXN];

int precomputeStuffness(int node, int parent){
	int i;

	for (i = start[node]; i; i = graph[i].next){
		if (graph[i].node == parent) continue;

		worstCase[node] = max(worstCase[node], precomputeStuffness(graph[i].node, node) + graph[i].dist);
	}

	return worstCase[node];
}


int tmparr[MAXN], tmparrdist[MAXN];

void tryEverything(int node, int parent, int parentWorst, int *tmp, int *tmpDist){
	int i, j, len = 0;
	int thisNode = max(parentWorst, worstCase[node]);

	if (thisNode < bestDist || (thisNode == bestDist && node < best)){
		bestDist = thisNode;
		best = node;
	} else return;

	for (i = start[node]; i; i = graph[i].next){
		if (graph[i].node == parent) continue;

		tmpDist[len] = graph[i].dist;
		tmp[len++] = graph[i].node;
	}

	for (i = 0; i < len; i++){
		thisNode = parentWorst + tmpDist[i];

		for (j = 0; j < len; j++){
			if (j == i) continue;

			thisNode = max(thisNode, worstCase[tmp[j]] + tmpDist[i] + tmpDist[j]);
		}

		tryEverything(tmp[i], node, thisNode, tmp + len, tmparrdist + len);
	}
}

int main(void){
	int i, a, b, c;

	scanf("%d", &N);

	for (i = 1; i < N; i++){
		scanf("%d %d %d", &a, &b, &c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}

	precomputeStuffness(1, -1);

	tryEverything(1, -1, 0, tmparr, tmparrdist);

	printf("%d %d\n", best, bestDist);

	return 0;
}
