#include <cstdio>
#include <algorithm>

using namespace std;

int v, e;

struct edge {
	int node, next;
};

edge graph[2000];
int start[500], nextEdge, coins[500];
bool adj[500][500];

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int main(){
	int i, j, k, l;

	while (scanf("%d %d", &v, &e) != EOF){
		int ans = 0;

		nextEdge = 1;

		for (i = 1; i <= v; i++)
			for (j = 1; j <= v; j++)
				adj[i][j] = false;

		for (i = 1; i <= v; i++){
			start[i] = 0;
			scanf("%d", &coins[i]);
		}

		while (e--){
			scanf("%d %d", &i, &j);
			adj[i][j] = adj[j][i] = true;
			addEdge(i,j); addEdge(j,i);
			ans = max(ans, coins[i] + coins[j]);
		}

		for (i = 1; i <= v; i++)
			for (j = start[i]; j; j = graph[j].next)
				for (k = start[i]; k; k = graph[k].next)
					if (j != k && adj[graph[j].node][graph[k].node])
						ans = max(ans, coins[i] + coins[graph[j].node] + coins[graph[k].node]);

		for (i = 1; i <= v; i++)
			for (j = 1; j <= v; j++)
				if (i != j && adj[i][j])
					for (k = start[i]; k; k = graph[k].next)
						if (graph[k].node != j && adj[graph[k].node][j])
							for (l = start[j]; l; l = graph[l].next)
								if (graph[l].node != i && graph[l].node != graph[k].node &&
								    adj[graph[l].node][graph[k].node] && adj[graph[l].node][i])
									ans = max(ans, coins[i] + coins[j] + coins[graph[k].node] + coins[graph[l].node]);

		printf("%d\n", ans);
	}
}
