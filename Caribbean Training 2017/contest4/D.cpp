#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 50;
int A, B;

const int maxa = maxn*maxn + 100;
const int maxb = maxa;
bool adj[maxa][maxb];
int pairA[maxa], pairB[maxb];
const int NIL = maxa-1;

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

int N, P;
bool m[maxn][maxn];

int main(){
	scanf("%d %d", &N, &P);

	for (int i = 0; i < P; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		m[r-1][c-1] = true;
	}

	int cnt[2] = {0};
	for (int r0 = 0; r0 < N; r0++)
		for (int c0 = 0; c0 < N; c0++)
			if (!m[r0][c0])
				cnt[(r0+c0)%2]++;

	int dr[4] = {1, -1, 0, 0};
	int dc[4] = {0, 0, 1, -1};
	for (int r0 = 0; r0 < N; r0++)
	for (int c0 = 0; c0 < N; c0++)
	for (int k = 0; k < 4; k++){
		int r1 = r0 + dr[k];
		int c1 = c0 + dc[k];

		if (r1 < 0 || r1 >= N || c1 < 0 || c1 >= N)
			continue;

		if (!m[r0][c0] && !m[r1][c1]){
			int x = r0*N+c0, y = r1*N+c1;
			if ((r0+c0) % 2) swap(x, y);
			adj[x][y] = true;
		}
	}

	A = B = N*N;

	if (matching::matching() == cnt[0] && cnt[0] == cnt[1]){
		printf("Yes\n");

#define mp make_pair
#define pb push_back
#define fst first
#define snd second
		vector<pair<int,int>> H, V;

		for (int u = 0; u < N*N; u++){
			if (pairA[u] == NIL) continue;
			int v = pairA[u];

			pair<int,int> x = mp(u/N, u%N);
			pair<int,int> y = mp(v/N, v%N);
			if (x >= y) swap(x, y);

			if (x.fst == y.fst) V.pb(x);
			else H.pb(x);
		}

		printf("%lu\n", H.size());
		for (auto w: H)
			printf("%d %d\n", w.fst + 1, w.snd + 1);
		printf("%lu\n", V.size());
		for (auto w: V)
			printf("%d %d\n", w.fst + 1, w.snd + 1);
	} else printf("No\n");
}
