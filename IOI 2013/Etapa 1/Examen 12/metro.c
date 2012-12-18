#include <stdio.h>

#define MAXN 30010
#define MAXM 200010

typedef struct {
	int a, b, cost;
} edge;

edge edges[MAXM];
int N, M;

int parent[MAXN];
int rank[MAXN];
int remaining;

int edgeCmp(const void *a, const void *b){
	return ((edge *)a)->cost - ((edge *)b)->cost;
}

int find(int n){
	if (parent[n] == n)
		return n;
	else
		return parent[n] = find(parent[n]);
}

void join(int a, int b){
	if (find(a) == find(b))
		return;

	if (rank[a] < rank[b])
		parent[find(a)] = find(b);
	else if (rank[a] > rank[b])
		parent[find(b)] = find(a);
	else {
		rank[a]++;
		parent[find(b)] = find(a);
	}
	remaining--;
}

int main(void){
	int i, answer = 0;

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++)
		scanf("%d %d %d", &edges[i].a, &edges[i].b, &edges[i].cost);
	
	qsort(edges, M, sizeof(edge), edgeCmp);

	for (i = 1; i <= N; i++)
		parent[i] = i;
	remaining = N;

	for (i = 0; N && i < M; i++){
		if (find(edges[i].a) != find(edges[i].b)){
			join(edges[i].a, edges[i].b);
			answer += edges[i].cost;
		}
	}

	printf("%d\n", answer);

	return 0;
}
