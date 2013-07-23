/*
    ID: frceped1
    LANG: C
    TASK: race3
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("race3.in", "r", stdin); freopen("race3.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXNODES 110
#define MAXEDGES 250

int min(int a, int b){
	return a < b ? a : b;
}

int N;

typedef struct {
	int node, next;
} edge;

edge graph[MAXEDGES];
int nextEdge = 1;
int start[MAXNODES];

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

bool unavoidable[MAXNODES];
int unCount;
bool splitting[MAXNODES];
int spCount;

char visited[MAXNODES];
int low[MAXNODES];

bool dfs(int n, int avoid){
	if (n == avoid || visited[n])
		return false;
	if (n == N)
		return true;

	int i;
	visited[n] = true;

	for (i = start[n]; i; i = graph[i].next)
		if (dfs(graph[i].node, avoid))
			return true;

	return false;
}

void firstHalf(int n, int split){
	int i;

	if (n == split || visited[n]) return;
	visited[n] = 1;

	for (i = start[n]; i; i = graph[i].next)
		firstHalf(graph[i].node, split);
}

bool ded;
bool secondHalf(int n){
	int i;
	bool ret = false;

	if (visited[n] == 1)
		ded = true;

	if (n == N) return true;
	if (visited[n]) return false;

	visited[n] = 2;
	for (i = start[n]; i; i = graph[i].next)
		if (secondHalf(graph[i].node))
			ret = true;

	return ret;
}

int main(void){
	int i, j, n = 0;

	openFiles();

	for (scanf("%d", &n); n != -1; scanf("%d", &n)){
		if (n == -2)
			N++;
		else
			addEdge(N,n);
	}
	N--;

	for (i = 1; i < N; i++){
		for (j = 0; j <= N; j++)
			visited[j] = false;
		unCount += unavoidable[i] = !dfs(0,i);
	}

	printf("%d", unCount);
	for (i = 0; i <= N; i++)
		if (unavoidable[i])
			printf(" %d", i);
	printf("\n");

	for (i = 1; i < N; i++){
		ded = false;
		for (j = 0; j <= N; j++)
			visited[j] = 0;
		firstHalf(0,i);
		if (secondHalf(i) && !ded){
			for (j = 1; j < N; j++)
				if (!visited[j]) break;
			spCount += splitting[i] = j == N;
		}
	}

	printf("%d", spCount);
	for (i = 0; i <= N; i++)
		if (splitting[i])
			printf(" %d", i);
	printf("\n");

	return 0;
}
