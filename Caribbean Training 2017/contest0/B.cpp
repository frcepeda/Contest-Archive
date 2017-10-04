#include <cstdio>
#include <algorithm>

using namespace std;

int A, B;

const int maxn = 255, INF = 1<<28, NIL = 254;
bool adj[maxn][maxn];
int pair_A[maxn], pair_B[maxn];

int q[maxn], qs, qe;

int dist[maxn];

bool bfs(){
	qs = qe = 0;

	for (int i = 0; i < A; i++)
		if (pair_A[i] == NIL){
			dist[i] = 0;
			q[qe++] = i;
		} else dist[i] = INF;

	dist[NIL] = INF;

	while (qs < qe){
		int curr = q[qs++];
		if (dist[curr] < dist[NIL])
			for (int i = 0; i < B; i++)
				if (adj[curr][i] && dist[pair_B[i]] == INF){
					dist[pair_B[i]] = dist[curr] + 1;
					q[qe++] = pair_B[i];
				}
	}

	return dist[NIL] < INF;
}

bool dfs(int x){
	if (x == NIL) return true;

	for (int i = 0; i < B; i++)
		if (adj[x][i] && dist[pair_B[i]] == dist[x] + 1 &&
		    dfs(pair_B[i])){
			pair_B[i] = x;
			pair_A[x] = i;
			return true;
		}

	dist[x] = INF;
	return false;
}

int main(){
	scanf("%d %d", &A, &B);

	for (int i = 0; i < A; i++){
		int x;
		while (scanf("%d", &x), x)
			adj[i][x-1] = true;
	}

	int size = 0;

	fill(pair_A, pair_A + maxn, NIL);
	fill(pair_B, pair_B + maxn, NIL);

	while (bfs())
		for (int i = 0; i < A; i++)
			if (pair_A[i] == NIL && dfs(i))
				size++;

	printf("%d\n", size);

	for (int i = 0; i < A; i++)
		if (pair_A[i] != NIL)
			printf("%d %d\n", i+1, pair_A[i]+1);
}
