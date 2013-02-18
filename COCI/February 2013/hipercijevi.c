#include <stdio.h>
#include <stdbool.h>

#define MAXNODES 150000
#define MAXEDGES 2200000
#define MAXQUEUE 1000000

typedef struct {
	int node, next;
} edge;

typedef struct {
	int node, steps;
} state;

#define addEdge(a,b) graph[nextGraph].node = (b); graph[nextGraph].next = start[(a)]; start[(a)] = nextGraph++

int start[MAXNODES];
edge graph[MAXEDGES];
int nextGraph = 1;

bool visited[MAXNODES];
state queue[MAXQUEUE];
int qs, qe;

#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])
#define queueIsNotEmpty (qs < qe)

int N, K, M;

int search(void){
	state curr = {.node = 1, .steps = 0}, next;
	int i;

	push(curr);
	visited[curr.node] = true;

	while (queueIsNotEmpty){
		curr = pop();

		if (curr.node == N)
			return curr.steps / 2 + 1;

		next.steps = curr.steps + 1;
		for (i = start[curr.node]; i; i = graph[i].next){
			if (!visited[graph[i].node]){
				next.node = graph[i].node;
				visited[next.node] = true;
				push(next);
			}
		}
	}

	return -1;
}

int main(void){
	int i, j;

	scanf("%d %d %d", &N, &K, &M);

	for (i = 1; i <= M; i++){
		for (j = 0; j < K; j++){
			int k;
			scanf("%d", &k);
			addEdge(N+i, k);
			addEdge(k, N+i);
		}
	}

	printf("%d\n", search());

	return 0;
}
