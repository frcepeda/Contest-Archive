#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 510
#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> pii;
int R, C;
int h[MAXN][MAXN];
int d[MAXN][MAXN];
pii q[MAXN*MAXN];
int qs, qe;
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

#define INF (1<<29)

bool works(int x){
	qs = qe = 0;
	q[qe++] = mp(1,1);

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			d[i][j] = INF;
	d[1][1] = x;

	while (qs < qe){
		auto c = q[qs++];

		if (d[c.fst][c.snd] >= h[c.fst][c.snd])
			continue;

		if (c.fst == R && c.snd == C)
			return true;

		for (int i = 0; i < 4; i++){
			int r_ = c.fst + dr[i];
			int c_ = c.snd + dc[i];
			if (r_ <= 0 || c_ <= 0 || r_ > R || c_ > C)
				continue;
			if (d[r_][c_] <= d[c.fst][c.snd] + 1)
				continue;
			d[r_][c_] = d[c.fst][c.snd] + 1;
			q[qe++] = mp(r_,c_);
		}
	}

	return false;
}

int main(){
	scanf("%d %d", &R, &C);

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			scanf("%d", &h[i][j]);

	int lo = 0, hi = 10000000, mid;

	while (lo <= hi){
		mid = (lo + hi)/2;
		if (works(mid))
			lo = mid + 1;
		else
			hi = mid - 1;
	}

	printf("%d\n", lo-1);
}
