#include <stdio.h>

#define MAXN 10100
#define MAXLG 15

typedef struct {
	int node, cost, next;
} edge;

edge graph[MAXN*2];
int start[MAXN];
int nextEdge = 1;

void addEdge(int a, int b, int c){
	graph[nextEdge].node = b;
	graph[nextEdge].cost = c;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int T, N;
int depth[MAXN];
int rootDist[MAXN];
int parent[MAXN][MAXLG];

void dfs(int node, int p, int d, int dist){
	int i;
	depth[node] = d;
	rootDist[node] = dist;
	parent[node][0] = p;

	for (i = start[node]; i; i = graph[i].next){
		if (graph[i].node == p) continue;
		dfs(graph[i].node, node, d+1, dist + graph[i].cost);
	}
}

#define swap(a,b) {int t = a; a = b; b = t;}

int lca(int a, int b){
	int lg = -1, i;

	if (depth[a] > depth[b])
		swap(a,b);

	for (i = depth[b]; i; i >>= 1)
		lg++;

	for (i = lg; i >= 0; i--)
		if (parent[b][i] != -1 && depth[a] <= depth[parent[b][i]])
			b = parent[b][i];

	if (a == b)
		return a;

	for (i = lg; i >= 0; i--)
		if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
			a = parent[a][i], b = parent[b][i];

	return parent[a][0];
}

int dist(int a, int b){
	int c = lca(a,b);
	return rootDist[a] + rootDist[b] - 2 * rootDist[c];
}

int up(int n, int k){
	int i;
	for (i = 0; (1<<i) <= k; i++)
		if ((1<<i) & k)
			n = parent[n][i];
	return n;
}

int kth(int a, int b, int k){
	int c = lca(a,b);
	int pathDist = depth[a] + depth[b] - 2 * depth[c] + 1;
	int first = depth[a] - depth[c] + 1;

	k--;
	if (k < first)
		return up(a, k);
	else
		return up(b, depth[b] - depth[c] - (k - first + 1));
}

int main(void){
	int i, j, a, b, c, k;
	char str[10];

	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);

		nextEdge = 1;
		for (i = 1; i <= N; i++)
			start[i] = 0;

		for (i = 0; i < MAXN; i++)
			for (j = 0; j < MAXLG; j++)
				parent[i][j] = -1;

		for (i = 1; i < N; i++){
			scanf("%d %d %d", &a, &b, &c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}

		dfs(1, -1, 0, 0);

		for (j = 1; j < MAXLG; j++)
			for (i = 1; i <= N; i++)
				if (parent[i][j-1] != -1)
					parent[i][j] = parent[parent[i][j-1]][j-1];

		while (scanf("%s", str), str[1] != 'O'){
			if (str[1] == 'I'){ // dist
				scanf("%d %d", &a, &b);
				printf("%d\n", dist(a, b));
			} else {
				scanf("%d %d %d", &a, &b, &k);
				printf("%d\n", kth(a, b, k));
			}
		}

		if (T)
			printf("\n");
	}

	return 0;
}
