#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXC 10010
#define MAXV 50010
#define fst first
#define snd second

struct edge {
	int node, next, cost;
};

edge graph[2*MAXV];
int start[MAXC], nextEdge;

void addEdge(int a, int b, int c){
	graph[nextEdge].cost = c;
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int C, V;

typedef pair<int,int> pii;

priority_queue<pii, vector<pii>, greater<pii>> q;
bool v[MAXC*2];

int f(int x, int y){
	if (y < C) return C + x;
	return x;
}

int search(){
	while (!q.empty()) q.pop();

	for (int i = 0; i < 2*C; i++)
		v[i] = false;

	q.push({0, 0});

	while (!q.empty()){
		pii curr = q.top(); q.pop();

		if (v[curr.snd]) continue;
		v[curr.snd] = true;

		if (curr.snd == C-1)
			return curr.fst;

		for (int i = start[curr.snd%C]; i; i = graph[i].next){
			pii n = {curr.fst + graph[i].cost, f(graph[i].node, curr.snd)};
			if (v[n.snd]) continue;
			q.push(n);
		}
	}

	return -1;
}

int main(){
	while (scanf("%d %d", &C, &V) == 2){
		fill(start, start + C, 0);
		nextEdge = 1;

		for (int i = 0; i < V; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			addEdge(a, b, c);
			addEdge(b, a, c);
		}

		printf("%d\n", search());
	}
}
