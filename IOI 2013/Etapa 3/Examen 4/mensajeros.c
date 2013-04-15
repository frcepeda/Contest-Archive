#include <stdio.h>

#define MAXNODES 100100

unsigned long long int min(unsigned long long int a, unsigned long long int b){
	return a < b ? a : b;
}

typedef struct {
	int node;
	double s;
} pair;

typedef struct {
	int node, next, dist;
} edge;

edge graph[MAXNODES*2];
int start[MAXNODES];
int nextEdge = 1;

void addEdge(int a, int b, int c){
	graph[nextEdge].node = b;
	graph[nextEdge].dist = c;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int N;
unsigned long long int cost[MAXNODES], rootDist[MAXNODES];
int path[MAXNODES], len;

int speed[MAXNODES], preparation[MAXNODES];

void precomputeDistances(int node, int parent){
	int i;

	for (i = start[node]; i; i = graph[i].next){
		if (graph[i].node != parent){
			rootDist[graph[i].node] = rootDist[node] + graph[i].dist;
			precomputeDistances(graph[i].node, node);
		}
	}
}

#define dist(i,j) (rootDist[i] - rootDist[j])

pair stack[MAXNODES];

int lowerBound(int hi, int s){
	int lo = 0, mid;

	while (lo < hi){
		mid = (lo + hi) / 2;
		if (stack[mid].s <= s)
			lo = mid + 1;
		else
			hi = mid;
	}

	return stack[lo - 1].node;
}

#define intersect(a,b) ((double)cost[a] - cost[b])/(rootDist[a] - rootDist[b])

int bestIndex(int node, int sti){
	int lo = 0, hi = sti, mid;
	double intersection;

	while (lo < hi){
		mid = (lo + hi) / 2;
		intersection = intersect(node, stack[mid].node);
		if (intersection > stack[mid].s)
			lo = mid + 1;
		else
			hi = mid;
	}

	if (lo == 0 || intersect(node, stack[lo-1].node) > stack[lo-1].s)
		return lo;
	else
		return -1;
}

void f(int node, int parent, int sti){
	int i, best;
	pair _save;

	if (node != 1){
		best = lowerBound(sti, speed[node]);
		cost[node] = cost[best] + dist(node, best) * speed[node] + preparation[node];
	}

	best = bestIndex(node, sti);

	if (best != -1){
		_save = stack[best];
		stack[best].node = node;
		stack[best].s = best > 0 ? intersect(node, stack[best-1].node) : 0;
	}

	for (i = start[node]; i; i = graph[i].next)
		if (graph[i].node != parent)
			f(graph[i].node, node, best != -1 ? best + 1 : sti);

	if (best != -1)
		stack[best] = _save;
}

int main(void){
	int i, a, b, c;

	scanf("%d", &N);

	for (i = 1; i < N; i++){
		scanf("%d %d %d", &a, &b, &c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}

	precomputeDistances(1, -1);

	for (i = 2; i <= N; i++)
		scanf("%d %d", &preparation[i], &speed[i]);

	f(1, -1, 0);

	for (i = 2; i <= N; i++)
		printf("%llu%c", cost[i], i != N ? ' ' : '\n');

	return 0;
}
