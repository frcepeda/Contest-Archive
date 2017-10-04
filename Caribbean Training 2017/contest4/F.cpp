#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 330;
int A, B;

const int maxa = maxn, maxb = maxn;
bool adj[maxa][maxb];
int pairA[maxa], pairB[maxb];
const int NIL = maxn-1;

namespace matching {
	const int INF = 1<<29;

	int queue[maxa];
	int qs, qe;

	int dist[maxa];

	bool bfs(){
		qs = qe = 0;
		
		for (int i = 0; i < A; i++){
			if (pairA[i] == NIL){
				dist[i] = 0;
				queue[qe++] = i;
			} else dist[i] = INF;
		}

		dist[NIL] = INF;

		while (qs < qe){
			int curr = queue[qs++];
			if (dist[curr] < dist[NIL])
				for (int i = 0; i < B; i++)
					if (adj[curr][i] && dist[pairB[i]] == INF){
						dist[pairB[i]] = dist[curr] + 1;
						queue[qe++] = pairB[i];
					}
		}

		return dist[NIL] < INF;
	}

	bool dfs(int x){
		if (x == NIL) return true;

		for (int i = 0; i < B; i++)
			if (adj[x][i] && dist[pairB[i]] == dist[x] + 1 &&
			    dfs(pairB[i])){
				pairB[i] = x;
				pairA[x] = i;
				return true;
			}

		dist[x] = INF;
		return false;
	}

	int matching(){
		int size = 0;

		fill(pairA, pairA + maxa, NIL);
		fill(pairB, pairB + maxb, NIL);

		while (bfs())
			for (int i = 0; i < A; i++)
				if (pairA[i] == NIL && dfs(i))
					size++;

		return size;
	}
}

bool v[maxn], v2[maxn];

void dfs(int x){
	if (v[x]) return;
	v[x] = true;

	for (int j = 0; j < B; j++)
		if (adj[x][j] && pairB[j] != x)
			dfs(pairB[j]);
}

int main(){
	scanf("%d %d", &A, &B);

	for (int i = 0; i < A; i++){
		int x, y;
		scanf("%d", &x);
		while (x--){
			scanf("%d", &y);
			adj[i][y-1] = true;
		}
	}

	matching::matching();

	int X = 0, Y = 0;

	for (int i = 0; i < A; i++)
		if (pairA[i] == NIL)
			dfs(i);

	for (int i = 0; i < A; i++)
		if (v[i]){
			X++;
			/*
			for (int j = 0; j < B; j++)
				if (adj[i][j] && !v2[j]){
					v2[j] = true;
					Y++;
				}
				*/
		}

	printf("%d\n", X);

	for (int i = 0, j = 0; i < A; i++)
		if (v[i]){
			printf("%d%c", i+1, ++j < X ? ' ' : '\n');
		}
}
