#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100100

struct edge{
	int next, node, cost;
};

edge graph[MAXN*2];
int start[MAXN], nextEdge = 1;
int N, F;
int parent[MAXN], weight[MAXN];
int all[MAXN];
bool L[MAXN], V[MAXN];
int ans;

void addEdge(int a, int b, int c){
	graph[nextEdge].node = b;
	graph[nextEdge].cost = c;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

void buildTree(int n){
	int i;
	for (i = start[n]; i; i = graph[i].next)
		if (graph[i].node != parent[n]){
			parent[graph[i].node] = n;
			weight[graph[i].node] = graph[i].cost;
			buildTree(graph[i].node);
		}
}

void up(int n){
	if (n == 1 || V[n]) return;
	V[n] = true;
	up(parent[n]);
	all[n] = all[parent[n]] + weight[n];
}

int main(){
	int i;

	scanf("%d %d", &N, &F);
	
	for (i = 1; i < N; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		addEdge(a, b, c);
		addEdge(b, a, c);
		ans += c;
	}

	for (i = 0; i < F; i++){
		int x;
		scanf("%d", &x);
		L[x] = true;
	}

	buildTree(1);

	for (i = 1; i <= N; i++)
		if (L[i])
			up(i);

	for (i = 1; i <= N; i++)
		if (!V[i])
			ans -= weight[i];

	int x = 0;
	
	for (i = 1; i <= N; i++)
		if (L[i])
			x = max(x, all[i]);

	printf("%d\n", ans - x);
}
