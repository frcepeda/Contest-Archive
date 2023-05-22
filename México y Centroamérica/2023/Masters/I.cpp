// bug: need to change dfs below to bfs.

#include <cstdio>
#include <algorithm>

using namespace std;

struct edge {
	int node, next, cap, flow;
};

constexpr int INF = 10000000, s = 0, t = 1;
constexpr int MAXE = 30 * 30 * 3, MAXV = 30 * 30 * 2;
edge g[MAXE*2];
int n, start[MAXV], nextEdge = 2;

void addEdge(int a, int b, int c){
	g[nextEdge] = {b, start[a], c, 0};
	start[a] = nextEdge++;
	g[nextEdge] = {a, start[b], 0, 0};
	start[b] = nextEdge++;
}

int maxFlow(){
	int tot = 0;
	static int q[MAXV], z[MAXV], d[MAXV], p[MAXV], qs, qe, curr;

	while (true){
		fill(d, d + n, MAXV);
		d[s] = qs = qe = 0;
		q[qe++] = s;

		while (qs < qe){
			curr = q[qs++];
			z[curr] = start[curr];
			if (d[curr] == d[t]) continue;
			for (int i = start[curr]; i; i = g[i].next)
				if (g[i].cap - g[i].flow > 0 &&
				    d[g[i].node] > d[curr] + 1){
					d[g[i].node] = d[curr] + 1;
					q[qe++] = g[i].node;
				}
		}

		if (d[t] == MAXV) return tot;

		curr = s;
		while (true){
			while (z[curr] && (g[z[curr]].cap - g[z[curr]].flow <= 0 ||
			       d[g[z[curr]].node] != d[curr] + 1))
				z[curr] = g[z[curr]].next;

			if (!z[curr]){
				if (curr == s) break;
				curr = g[p[d[curr]-1]^1].node;
				d[g[p[d[curr]]].node] = -INF;
				continue;
			}

			p[d[curr]] = z[curr];
			curr = g[z[curr]].node;

			if (curr == t){
				int m = INF;
				for (int i = 0; i < d[t]; i++)
					m = min(m, g[p[i]].cap - g[p[i]].flow);
				for (int i = 0; i < d[t]; i++){
					g[p[i]].flow += m;
					g[p[i]^1].flow -= m;
				}
				tot += m;
				curr = s;
			}
		}
	}
}

int H, S, P;
int houseIn(int house) { return 2*house; }
int houseOut(int house) { return 2*house + 1; }
int park(int p) { return 2 + 2*H + p - 1; }
int school(int s) {return 2 + 2*H + P + s - 1; };

constexpr int maxn = 33;
int R, C, D;
char m[maxn][maxn];
int idx[maxn][maxn], v[maxn][maxn], vv;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void dfs(int r, int c, int d) {
    if (v[r][c] == vv || d > D) return;
    v[r][c] = vv;

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (nr < 0 || nr >= R) continue;
        if (nc < 0 || nc >= C) continue;
        if (m[nr][nc] == 'H' || m[nr][nc] == '#') continue;
        if (m[nr][nc] == 'P') {
            addEdge(park(idx[nr][nc]), houseIn(vv), 1);
            continue;
        }
        if (m[nr][nc] == 'S') {
            addEdge(houseOut(vv), school(idx[nr][nc]), 1);
            continue;
        }
        dfs(nr, nc, d+1);
    }
}

int main() {
    scanf("%d %d %d", &R, &C, &D);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf(" %c", &m[i][j]);
            auto up = [&](int &ii) {
                idx[i][j] = ++ii;
            };
            if (m[i][j] == 'H') up(H);
            if (m[i][j] == 'S') up(S);
            if (m[i][j] == 'P') up(P);
        }
    }
	
	n = 2 + 2*H + P + S + 10;

    for (int i = 1; i <= H; i++){
        addEdge(houseIn(i), houseOut(i), 1);
    }

    for (int i = 1; i <= P; i++){
        addEdge(0, park(i), 1);
    }

    for (int i = 1; i <= S; i++){
        addEdge(school(i), 1, 1);
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (m[i][j] == 'H') {
                vv = idx[i][j];
                dfs(i, j, 0);
            }
        }
    }

    printf("%d\n", maxFlow());
}