#include <stdio.h>
#include <stdbool.h>

#define MAXN 100100
#define MAXM 300100

typedef struct {
	int node, idx, next;
} edge;

int N, M;
edge graph[MAXM*2];
int start[MAXN], nextEdge = 1;
int team[MAXN];

void addEdge(int a, int b, int i){
	graph[nextEdge].node = b;
	graph[nextEdge].idx = i;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

bool fill(int n, int t, int x){
	if (team[n])
		return t != team[n];
	team[n] = t;

	for (int i = start[n]; i; i = graph[i].next)
		if (graph[i].idx < x &&
		    fill(graph[i].node, t == 1 ? 2 : 1, x))
			return true;

	return false;
}

bool try(int x){
	int i;

	for (i = 1; i <= N; i++)
		team[i] = 0;

	for (i = 1; i <= N; i++)
		if (!team[i] && fill(i, 1, x))
			return true;

	return false;
}

int main(){
	int i;

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		addEdge(a, b, i);
		addEdge(b, a, i);
	}

	int lo = 0, hi = M, mid;
	while (lo < hi){
		mid = (lo + hi)/2;
		if (try(mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%d\n", hi);
}
