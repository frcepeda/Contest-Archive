#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 300;
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

int main(){
	scanf("%d %d", &A, &B);

	for (int i = 0; i < A; i++){
		int j;
		while (scanf("%d", &j), j)
			adj[i][j-1] = true;
	}

	matching::matching();

	vector<pair<int,int>> v;

	for (int i = 0; i < A; i++){
		if (pairA[i] != NIL)
			v.push_back(make_pair(i+1, pairA[i]+1));
		else for (int j = 0; j < B; j++)
			if (adj[i][j]){
				v.push_back(make_pair(i+1, j+1));
				break;
			}
	}

	for (int i = 0; i < B; i++)
		if (pairB[i] == NIL)
			for (int j = 0; j < A; j++)
				if (adj[j][i]){
					v.push_back(make_pair(j+1, i+1));
					break;
				}

	printf("%lu\n", v.size());

	for (auto w: v)
		printf("%d %d\n", w.first, w.second);
}
