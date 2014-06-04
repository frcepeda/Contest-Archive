#include <cstdio>
#include <algorithm>

using namespace std;

struct edge {
	int next, node;
};

edge graph[2010];
int nextEdge = 1, start[1010];

void resetGraph(){
	nextEdge = 1;
	for (int i = 0; i < 1010; i++)
		start[i] = 0;
}

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int T, N, v = 1;
int mem[1010], vis[1010];

int dp(int n, int p){
	if (vis[n] == v)
		return mem[n];
	vis[n] = v;

	int best = -100000, sndbest = -100000;
	for (int i = start[n]; i; i = graph[i].next){
		if (graph[i].node == p) continue;
		int d = dp(graph[i].node, n);

		if (d >= best){
			sndbest = best;
			best = d;
		} else if (d > sndbest)
			sndbest = d;
	}

	return mem[n] = max(1, 1 + best + sndbest);
}

int main(){
	int t;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int i, a, b, best = 0;

		resetGraph();
		scanf("%d", &N);

		for (i = 1; i < N; i++){
			scanf("%d %d", &a, &b);
			addEdge(a, b);
			addEdge(b, a);
		}

		for (i = 1; i <= N; i++, v++)
			best = max(best, dp(i, -1));

		printf("Case #%d: %d\n", t, N - best);
	}
}
