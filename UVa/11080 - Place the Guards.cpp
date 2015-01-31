#include <cstdio>
#include <algorithm>

#define MAXV 210
#define MAXE 10010

using namespace std;

struct edge {
	int node, next;
};

int T, v, e, b, s;
edge graph[MAXE*2];
int start[MAXV], nextEdge;
short color[MAXV];

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int f(int n, int p, int c){
	if (color[n])
		return color[n] == c;
		
	if (c == 1) b++;
	color[n] = c;
	s++;
	
	for (int i = start[n]; i; i = graph[i].next){
		if (graph[i].node == p) continue;
		if (!f(graph[i].node, n, c == 1 ? 2 : 1)) return false;
	}
	
	return true;
}

int main() {
	scanf("%d", &T);
	
	while (T--){
		int i;
		
		scanf("%d %d", &v, &e);
		fill(start, start + v, 0);
		fill(color, color + v, 0);
		nextEdge = 1;
		
		while (e--){
			int s, t;
			scanf("%d %d", &s, &t);
			if (s != t){
				addEdge(s, t);
				addEdge(t, s);
			}
		}
		
		int ans = 0;
		for (i = 0; i < v; i++)
			if (!color[i]){
				b = s = 0;
				if (!f(i, -1, 1)) break;
				ans += max(min(b, s-b), 1);
			}
		
		printf("%d\n", i == v ? ans : -1);
	}
}