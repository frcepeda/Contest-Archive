#include <cstdio>
#include <algorithm>

using namespace std;

#define NIL 102
#define MAXN 105
#define MAXA MAXN
#define MAXB MAXN
#define INF (1<<30)

int T;
int A, B, P;
int pair_A[MAXN], pair_B[MAXN];
bool adj[MAXN][MAXN];

int queue[MAXN];
int qs, qe;
#define resetQueue() qs = qe = 0
#define queueNotEmpty (qs < qe)
#define push(x) queue[qe++] = x
#define pop() queue[qs++]

int dist[MAXA];

bool matching_BFS(){
	resetQueue();

	for (int i = 0; i < A; i++){
		if (pair_A[i] == NIL){
			dist[i] = 0;
			push(i);
		} else {
			dist[i] = INF;
		}
	}

	dist[NIL] = INF;

	while (queueNotEmpty){
		int curr = pop();
		if (dist[curr] < dist[NIL])
			for (int i = 0; i < B; i++)
				if (adj[curr][i] && dist[pair_B[i]] == INF){
					dist[pair_B[i]] = dist[curr] + 1;
					push(pair_B[i]);
				}
	}

	return dist[NIL] < INF;
}

bool matching_DFS(int x){
	if (x == NIL) return true;

	for (int i = 0; i < B; i++)
		if (adj[x][i] && dist[pair_B[i]] == dist[x] + 1 && matching_DFS(pair_B[i])){
			pair_B[i] = x;
			pair_A[x] = i;
			return true;
		}

	dist[x] = INF;
	return false;
}

int matching(void){
	int size = 0;

	fill(pair_A, pair_A + MAXA, NIL);
	fill(pair_B, pair_B + MAXB, NIL);

	while (matching_BFS())
		for (int i = 0; i < A; i++)
			if (pair_A[i] == NIL && matching_DFS(i))
				size++;

	return size;
}

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d %d %d", &A, &B, &P);

		for (int i = 0; i < A; i++)
			for (int j = 0; j < B; j++)
				adj[i][j] = false;

		while (P--){
			double i, j;
			scanf("%lf %lf", &i, &j);
			adj[(int)i][(int)j] = true;
		}

		printf("%d\n", matching());
	}
}
