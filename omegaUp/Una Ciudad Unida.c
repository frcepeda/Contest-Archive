#include <stdio.h>
#include <stdbool.h>

#define MAXN 2010
#define MAXE 100100

typedef struct {
	int node, next;
} edge;

int N, M;
edge graph[2*MAXE];
int start[MAXN], nextEdge = 1;
bool v[MAXN];
int component[MAXN], cSiz;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int search(int n){
	int i, x = 1;

	if (v[n]) return 0;
	v[n] = true;

	for (i = start[n]; i; i = graph[i].next)
		x += search(graph[i].node);

	return x;
}

int main(void){
	int i, j;

	scanf("%d %d", &N, &M);

	while (M--){
		scanf("%d %d", &i, &j);
		addEdge(i,j);
		addEdge(j,i);
	}

	for (i = 1; i <= N; i++)
		if (!v[i])
			component[cSiz++] = search(i);

	unsigned long long ans = 0;

	for (i = 1; i < cSiz; i++){
		ans += component[i] * component[i-1];
		component[i] += component[i-1];
	}

	printf("%llu\n", ans);

	return 0;
}
