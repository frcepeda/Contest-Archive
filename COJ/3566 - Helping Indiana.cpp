#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 2010
#define mp make_pair
#define fst first
#define snd second

int N;
char g[MAXN][MAXN];
int d[MAXN][MAXN][4];
deque<pair<pair<int,int>,int>> q;
int qs, qe;

int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
int flip[] = {2,3,0,1};

int search(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < 4; k++)
				d[i][j][k] = 1<<30;
	d[0][0][0] = 0;

	q.push_back(mp(mp(0,0),0));

	while (true){
		int r, c, k;
		auto ww = q.front(); q.pop_front();
		r = ww.fst.fst;
		c = ww.fst.snd;
		k = ww.snd;

		if (r == N-1 && c == N-1 && k == 2)
			return d[r][c][k];

		int nk = (k + (g[r][c] == 'H' ? 1 : -1) + 4) % 4;
		if (d[r][c][nk] > d[r][c][k] + 1){
			d[r][c][nk] = d[r][c][k] + 1;
			q.push_back(mp(mp(r,c), nk));
		}

		int nr = r + dr[k];
		int nc = c + dc[k];
		int fk = flip[k];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			continue;
		if (d[nr][nc][fk] <= d[r][c][k])
			continue;
		d[nr][nc][fk] = d[r][c][k];
		q.push_front(mp(mp(nr,nc), fk));
	}
}

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%s", g[i]);

	printf("%d\n", search());
}
