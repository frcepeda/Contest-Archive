#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 110;
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

int N, M;
bool m[maxn][maxn], v[maxn][maxn];
char maxc[maxn][maxn], minc[maxn][maxn];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
char *E = "DURL";
char *R = "UDLR";


void dfs(int r, int c, bool first = false){
	v[r][c] = true;

	for (int k = 0; k < 4; k++){
		int r1 = r + dr[k];
		int c1 = c + dc[k];

		if (r1 < 0 || r1 >= N || c1 < 0 || c1 >= M)
			continue;

		if (m[r1][c1] || v[r1][c1]) continue;

		if (first) minc[r][c] = E[k];
		minc[r1][c1] = R[k];
		dfs(r1, c1);
	}
}

int main(){
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++){
		char tmp[maxn];
		scanf("%s", tmp);
		for (int j = 0; j < M; j++)
			m[i][j] = tmp[j] == '.';
	}

	int cnt[2] = {0};
	for (int r0 = 0; r0 < N; r0++)
		for (int c0 = 0; c0 < M; c0++)
			if (!m[r0][c0]){
				if (!v[r0][c0])
					dfs(r0, c0, true);
				cnt[(r0+c0)%2]++;
			}

	for (int r0 = 0; r0 < N; r0++)
	for (int c0 = 0; c0 < M; c0++)
	for (int k = 0; k < 4; k++){
		int r1 = r0 + dr[k];
		int c1 = c0 + dc[k];

		if (m[r0][c0])
			maxc[r0][c0] = minc[r0][c0] = '.';

		if (r1 < 0 || r1 >= N || c1 < 0 || c1 >= M)
			continue;

		if (!m[r0][c0] && !m[r1][c1]){
			maxc[r0][c0] = E[k];
			int x = r0*M+c0, y = r1*M+c1;
			if ((r0+c0) % 2) swap(x, y);
			adj[x][y] = true;
		}
	}

	A = B = N*M;

	matching::matching();
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
	for (int u = 0; u < N*M; u++){
		if (pairA[u] == NIL) continue;
		int v = pairA[u];

		pair<int,int> x = mp(u/M, u%M);
		pair<int,int> y = mp(v/M, v%M);
		if (x >= y) swap(x, y);

		if (x.fst == y.fst){
			maxc[x.fst][x.snd] = 'R';
			maxc[y.fst][y.snd] = 'L';
		} else {
			maxc[x.fst][x.snd] = 'D';
			maxc[y.fst][y.snd] = 'U';
		}
	}

	for (int i = 0; i < N; i++)
		printf("%s\n", minc[i]);
	printf("\n");
	for (int i = 0; i < N; i++)
		printf("%s\n", maxc[i]);
}
