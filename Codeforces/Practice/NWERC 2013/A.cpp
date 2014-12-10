#include <cstdio>
#include <algorithm>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

struct edge {
	int node, next;
};

int p[2010];

int id(int x){
	if (p[x] == x) return x;
	return p[x] = id(p[x]);
}

void join(int a, int b){
	p[id(a)] = id(b);
}

edge graph[5010];
int start[2010], nextEdge;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int N;

int a[2010][2010], b[2010][2010];
piii edges[4000100];
int ecount;

int queue[2010];
int qs, qe;

#define push(x) queue[qe++] = x
#define pop() queue[qs++]
#define queueNotEmpty (qs < qe)

void search(const int x){
	int i;
	qs = qe = 0;
	push(x);

	for (i = 0; i < N; i++) b[x][i] = 0;

	while (queueNotEmpty){
		int c = pop();

		for (i = start[c]; i; i = graph[i].next)
			if (!b[x][graph[i].node]){
				b[x][graph[i].node] = b[x][c] + a[c][graph[i].node];
				push(graph[i].node);
			}
	}

	b[x][x] = 0;
}

int main(){
	int i, j;
	bool first = true;

	while (scanf("%d", &N) != EOF){
		if (!first) putchar('\n');
		first = false;

		nextEdge = 1;
		for (i = 0; i < N; i++){
			start[i] = 0;
			p[i] = i;
		}

		ecount = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++){
				scanf("%d", &a[i][j]);
				if (i < j)
					edges[ecount++] = mp(a[i][j], mp(i,j));
			}

		sort(edges, edges + ecount);

		for (i = 0; i < ecount; i++)
			if (id(edges[i].snd.fst) != id(edges[i].snd.snd)){
				join(edges[i].snd.fst, edges[i].snd.snd);
				addEdge(edges[i].snd.fst, edges[i].snd.snd);
				addEdge(edges[i].snd.snd, edges[i].snd.fst);
			}

		for (i = 0; i < N; i++)
			search(i);

		for (i = 0; i < ecount; i++)
			if (a[edges[i].snd.fst][edges[i].snd.snd] != b[edges[i].snd.fst][edges[i].snd.snd]){
				addEdge(edges[i].snd.fst,edges[i].snd.snd);
				addEdge(edges[i].snd.snd,edges[i].snd.fst);
				goto end;
			}

		for (i = 0; i < N; i++){
			if (start[i]){
				addEdge(i,graph[start[i]].node);
				addEdge(graph[start[i]].node,i);
				goto end;
			}
		}

end:
		for (i = 0; i < N; i++)
			for (j = start[i]; j; j = graph[j].next)
				if (i < graph[j].node)
					printf("%d %d %d\n", i+1, graph[j].node+1, a[i][graph[j].node]);
	}
}
