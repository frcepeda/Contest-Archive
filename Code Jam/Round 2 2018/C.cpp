#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// matching

#define MAXN 20010
#define INF 40404040

int N;
int pair_A[MAXN], pair_B[MAXN];
vector<int> adj[MAXN];

int queue[MAXN];
int qs, qe, NIL;

#define resetQueue() qs = qe = 0
#define queueNotEmpty (qs < qe)
#define push(x) queue[qe++] = x
#define pop() queue[qs++]

int dist[MAXN];

bool matching_BFS(){
	resetQueue();

	for (int i = 0; i < N; i++){
		if (pair_A[i] == NIL){
			dist[i] = 0;
			push(i);
		} else dist[i] = INF;
	}

	dist[NIL] = INF;

	while (queueNotEmpty){
		int curr = pop();

		if (dist[curr] >= dist[NIL]) continue;

		for (auto x: adj[curr]){
			if (dist[pair_B[x]] == INF){
				dist[pair_B[x]] = dist[curr] + 1;
				push(pair_B[x]);
			}
		}
	}

	return dist[NIL] < INF;
}

bool matching_DFS(int x){
	if (x == NIL) return true;

	for (auto y: adj[x]){
		if (dist[pair_B[y]] == dist[x] + 1 &&
		    matching_DFS(pair_B[y])){
			pair_B[y] = x;
			pair_A[x] = y;
			return true;
		}
	}

	dist[x] = INF;
	return false;
}

int matching(){
	int size = 0;

	fill(pair_A, pair_A + N + 1, NIL);
	fill(pair_B, pair_B + N + 1, NIL);

	while (matching_BFS())
		for (int i = 0; i < N; i++)
			if (pair_A[i] == NIL && matching_DFS(i))
				size++;

	return size;
}

// end matching

int main(){
	int T, n;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d", &n);

		for (int i = 0; i < 2*n*n; i++)
			adj[i].clear();
		N = NIL = 2*n*n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++){
				int x;
				scanf("%d", &x);

				if (x < 0) x = n - x;
				x--;

				adj[i + n*x].push_back(j + n*x);
			}

		printf("Case #%d: %d\n", t, n*n - matching());
	}
}
