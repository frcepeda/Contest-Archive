#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100100
#define MAXK 310
#define UNVISITED (-1)

struct edge {
	int node, next, cost;
};

int start[MAXN], nextEdge = 1;
edge graph[2*MAXN];

void addEdge(int a, int b, int c){
	graph[nextEdge].node = b;
	graph[nextEdge].cost = c;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int N, M, K, SCCK[MAXK], numSCC;
int T[MAXK], U[MAXN], D[MAXK][MAXK];
int group[MAXN];

vector<int> dfs_num, dfs_low, S, visited;
int dfsNumberCounter;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for (int i = start[u]; i; i = graph[i].next){
		if (graph[i].cost > 0) continue;
		if (dfs_num[graph[i].node] == UNVISITED)
			tarjanSCC(graph[i].node);
		if (visited[graph[i].node])
			dfs_low[u] = min(dfs_low[u], dfs_low[graph[i].node]);
	}

	if (dfs_low[u] == dfs_num[u]){
		numSCC++;
		while (true){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			group[v] = numSCC;
			if (u == v) break;
		}
	}
}

int main(){
	scanf("%d %d %d", &N, &M, &K);

	int l = 0;
	for (int i = 0; i < K; i++){
		scanf("%d", &T[i]);
		for (int j = 0; j < T[i]; j++)
			U[l++] = i;
	}

	for (int i = 0; i < M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		addEdge(a, b, c);
		addEdge(b, a, c);
	}

	dfs_num.assign(N, UNVISITED);
	dfs_low.assign(N, 0);
	visited.assign(N, 0);
	dfsNumberCounter = numSCC = 0;
	for (int i = 0; i < N; i++)
		if (dfs_num[i] == UNVISITED)
			tarjanSCC(i);

	for (int i = 0; i < N; i++){
		if (SCCK[U[i]] == 0)
			SCCK[U[i]] = group[i];
		if (SCCK[U[i]] != group[i]){
			printf("No\n");
			return 0;
		}
	}

	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			D[i][j] = i == j ? 0 : (1<<29);

	for (int i = 0; i < N; i++){
		for (int j = start[i]; j; j = graph[j].next){
			int z = graph[j].node;
			D[U[z]][U[i]] = min(D[U[z]][U[i]], graph[j].cost);
			D[U[i]][U[z]] = min(D[U[i]][U[z]], graph[j].cost);
		}
	}

	for (int k = 0; k < K; k++)
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

	printf("Yes\n");
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			printf("%d%c", D[i][j] < (1<<29) ? D[i][j] : -1, j < K-1 ? ' ' : '\n');
}
