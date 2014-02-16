#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("rblock.in", "r", stdin); freopen("rblock.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 260
#define MAXM 50100

#define fst first
#define snd second
#define mp make_pair
typedef pair<int,int> pii;

priority_queue< pii, vector<pii>, greater<pii> > q;

int N, M;
int graph[MAXN][MAXN];
int parent[MAXN], best[MAXN];

int candidates[MAXN], cLen;

int search(){
	int i;

	while (!q.empty()) q.pop();

	for (i = 2; i <= N; i++)
		best[i] = 1<<30;

	q.push(mp(0, 1));

	while (true){
		pii c = q.top(); q.pop();

		if (c.fst > best[c.snd]) continue;
		if (c.snd == N) return c.fst;

		for (i = 1; i <= N; i++){
			if (graph[c.snd][i] == -1) continue;

			pii n = mp(c.fst + graph[c.snd][i], i);

			if (n.fst < best[n.snd]){
				best[n.snd] = n.fst;
				parent[n.snd] = c.snd;
				q.push(n);
			}
		}
	}
}

int main(void){
	int i, j, opt, ans = 0;

	openFiles();

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			graph[i][j] = -1;

	for (i = 0; i < M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[b][a] = c;
	}

	opt = search();

	for (i = N; i != 0; i = parent[i])
		candidates[cLen++] = i;

	for (i = 0; i < cLen-1; i++){
		graph[candidates[i]][candidates[i+1]] *= 2;
		graph[candidates[i+1]][candidates[i]] *= 2;

		ans = max(ans, search() - opt);

		graph[candidates[i]][candidates[i+1]] /= 2;
		graph[candidates[i+1]][candidates[i]] /= 2;
	}

	printf("%d\n", ans);
}
