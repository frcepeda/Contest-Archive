#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 510
#define MAXE 40100
#define LOGN 10

struct edge {
	int node, next;
};

int T, n, m;
edge graph[MAXE];
int start[MAXN], nextEdge;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int v[MAXE], p[MAXE];
int ans;

int queue[MAXE];
int qs, qe;

#define push(x) queue[qe++] = x
#define pop() queue[qs++]
#define queueNotEmpty (qs < qe)

void bfs(int s){
	qs = qe = 0;

	push(s);

	for (int i = 0; i < n; i++)
		v[i] = 0;
	v[s] = 1;
	p[s] = -1;

	while (queueNotEmpty){
		int c = pop();

		for (int i = start[c]; i; i = graph[i].next){
			if (graph[i].node == p[c]) continue;

			if (!v[graph[i].node]) {
				v[graph[i].node] = v[c] + 1;
				p[graph[i].node] = c;
				push(graph[i].node);
			} else {
				int t = v[c] + v[graph[i].node] - 1;
				ans = min(ans, t);
			}
		}
	}
}

int main(){
	int t, i, j;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d %d", &n, &m);

		ans = 1<<27;
		nextEdge = 1;
		for (i = 0; i < n; i++){
			start[i] = 0;
			v[i] = 0;
		}

		while (m--){
			scanf("%d %d", &i, &j);
			addEdge(i, j);
			addEdge(j, i);
		}

		for (i = 0; i < n; i++)
			bfs(i);

		if (ans > n)
			printf("Case %d: impossible\n", t);
		else
			printf("Case %d: %d\n", t, ans);
	}
}
