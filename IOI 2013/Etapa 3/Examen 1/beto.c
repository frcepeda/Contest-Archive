#include <stdio.h>
#include <stdbool.h>

#define MAXN 100010

long long int max(long long int a, long long int b){
	return a > b ? a : b;
}

typedef struct {
	int node, next;
} edge;

edge graph[MAXN*2];
int start[MAXN];
int nextEdge = 1;

void addEdge(int a, int b, edge *graph, int *next, int *start){
	graph[*next].node = b;
	graph[*next].next = start[a];
	start[a] = (*next)++;
}

int N;

bool isLeaf[MAXN];
int cStart[MAXN];
edge children[MAXN];
long long int increment[MAXN], decrement[MAXN], value[MAXN];

int nextChild = 1;

void buildTree(int n, int p){
	int i;

	isLeaf[n] = true;

	for (i = start[n]; i; i = graph[i].next){
		if (graph[i].node == p) continue;

		addEdge(n, graph[i].node, children, &nextChild, cStart);
		isLeaf[n] = false;

		buildTree(graph[i].node, n);
	}
}

void countSteps(int n){
	int i;

	if (isLeaf[n]){
		if (value[n] > 0)
			decrement[n] = value[n];
		else
			increment[n] = -value[n];
		return;
	}

	for (i = cStart[n]; i; i = children[i].next){
		countSteps(children[i].node);
		increment[n] = max(increment[n], increment[children[i].node]);
		decrement[n] = max(decrement[n], decrement[children[i].node]);
	}

	long long int diff = increment[n] - decrement[n] + value[n];

	if (diff > 0)
		decrement[n] += diff;
	else
		increment[n] += -diff;
}

int main(void){
	int i;

	scanf("%d", &N);

	for (i = 1; i < N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		addEdge(a,b,graph,&nextEdge,start);
		addEdge(b,a,graph,&nextEdge,start);
	}

	for (i = 1; i <= N; i++)
		scanf("%lld", &value[i]);

	buildTree(1,-1);

	countSteps(1);

	printf("%lld\n", increment[1] + decrement[1]);

	return 0;
}