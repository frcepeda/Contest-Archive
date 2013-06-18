#include <stdio.h>
#include <stdbool.h>

#define MAXN 2010
#define MAXINTERACTIONS (1000000*2 + 100)

typedef struct {
	int node, next;
} edge;

int start[MAXN];
edge graph[MAXINTERACTIONS];
int nextEdge = 1;

int op[] = {[1] = 2, [2] = 1};

bool conflict = false;
char color[MAXN];

int T, N, M;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

void dfs(int node, int c){
	int i;

	if (color[node]){
		if (color[node] != c)
			conflict = true;
		return;
	}

	color[node] = c;

	for (i = start[node]; !conflict && i; i = graph[i].next)
		dfs(graph[i].node, op[c]);
}

int main(void){
	int i, t;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d %d", &N, &M);

		while (M--){
			int a, b;
			scanf("%d %d", &a, &b);
			a--, b--;
			addEdge(a,b);
			addEdge(b,a);
		}

		for (i = 0; !conflict && i < N; i++)
			if (!color[i])
				dfs(i,1);

		printf("Scenario #%d:\n", t);
		if (conflict)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");

		if (t < T){
			for (i = 0; i < N; i++)
				start[i] = color[i] = 0;
			nextEdge = 1;
			conflict = false;
		}
	}

	return 0;
}
