#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 1010
#define MAXM 1000100
#define UNVISITED -1

struct edge {
	int node, next;
};

edge graph[MAXM];
int start[MAXN], nextEdge;
int id[MAXN], out[MAXN];

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int T, N, M, Q;

int dfsNumberCounter, numSCC;
vector<int> dfs_num, dfs_low, S, visited;

void tarjan(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;

	for (int i = start[u]; i; i = graph[i].next){
		int v = graph[i].node;

		if (dfs_num[v] == UNVISITED)
			tarjan(v);
		if (visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if (dfs_low[u] == dfs_num[u]){
		while (true){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			id[v] = u;
			if (u == v) break;
		}
	}
}

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d %d", &N, &M);

		nextEdge = 1;
		for (int i = 0; i < N; i++)
			start[i] = 0;

		for (int i = 0; i < M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			addEdge(a-1, b-1);
		}

		S.clear();
		dfs_num.assign(N, UNVISITED); dfs_low.assign(N, 0); visited.assign(N, 0);
		dfsNumberCounter = numSCC = 0;

		for (int i = 0; i < N; i++)
			if (dfs_num[i] == UNVISITED)
				tarjan(i);

		fill(out, out + N, 0);

		for (int i = 0; i < N; i++)
			for (int j = start[i]; j; j = graph[j].next)
				if (id[i] != id[graph[j].node])
					out[id[i]]++;

		scanf("%d", &Q);

		while (Q--){
			int x;
			scanf("%d", &x);
			printf("%d\n", out[id[x-1]]);
		}
	}
}
