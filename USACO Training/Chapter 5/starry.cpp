/*
    ID: frceped1
    LANG: C++
    TASK: starry
 */

#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

#ifdef DBG
	#define openFiles()
#else
	#define openFiles() freopen("starry.in", "r", stdin); freopen("starry.out", "w", stdout)
#endif

#define fst first
#define snd second

typedef pair<int,int> pii;

const int maxn = 105;
int W, H;
char m[maxn][maxn], c[maxn][maxn];
pii p[maxn][maxn];
set<pii> v[maxn][maxn];

const int dr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dc[] = {1, 1, 1, 0, 0, -1, -1, -1};

pii id(pii x){
	if (x == p[x.fst][x.snd]) return x;
	return p[x.fst][x.snd] = id(p[x.fst][x.snd]);
}

void join(pii a, pii b){
	auto ga = id(a);
	auto gb = id(b);

	if (v[ga.fst][ga.snd].size() < v[gb.fst][gb.snd].size())
		swap(ga, gb);

	p[ga.fst][ga.snd] = id(b);
	v[ga.fst][ga.snd].insert(v[gb.fst][gb.snd].begin(), v[gb.fst][gb.snd].end());
}

char tmp[2][2*maxn][2*maxn];

void dfs(int r, int c, char tmp[2*maxn][2*maxn], bool vv[maxn][maxn]){
	if (!m[r][c] || vv[r][c]) return;
	vv[r][c] = true;
	tmp[r+maxn][c+maxn] = 1;

	for (int k = 0; k < 8; k++){
		int nr = r + dr[k];
		int nc = c + dc[k];
		dfs(nr, nc, tmp, vv);
	}
}

bool eq(){
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			if (tmp[0][i][j] != tmp[1][i][j])
				return false;
	return true;
}

void bump(char t[2*maxn][2*maxn]){
	static char tt[2*maxn][2*maxn];
	int mr = 2*maxn, mc = 2*maxn;

	for (int i = 0; i < 2*maxn; i++)
		for (int j = 0; j < 2*maxn; j++){
			if (t[i][j]){
				mr = min(mr, i);
				mc = min(mc, j);
			}
			tt[i][j] = 0;
		}

	for (int i = mr; i < 2*maxn; i++)
		for (int j = mc; j < 2*maxn; j++)
			tt[i-mr][j-mc] = t[i][j];

	for (int i = 0; i < 2*maxn; i++)
		for (int j = 0; j < 2*maxn; j++)
			t[i][j] = tt[i][j];
}

void rotate(){
	static char tt[2*maxn][2*maxn];

	for (int i = 0; i < 2*maxn; i++)
		for (int j = 0; j < 2*maxn; j++)
			tt[j][2*maxn-i-1] = tmp[0][i][j];

	for (int i = 0; i < 2*maxn; i++)
		for (int j = 0; j < 2*maxn; j++)
			tmp[0][i][j] = tt[i][j];

	bump(tmp[0]);
}

void flip(){
	static char tt[2*maxn][2*maxn];

	for (int i = 0; i < 2*maxn; i++)
		for (int j = 0; j < 2*maxn; j++)
			tt[2*maxn-i-1][j] = tmp[0][i][j];

	for (int i = 0; i < 2*maxn; i++)
		for (int j = 0; j < 2*maxn; j++)
			tmp[0][i][j] = tt[i][j];

	bump(tmp[0]);
}

bool same(pii a, pii b){
	static bool vv[maxn][maxn];

	for (int k = 0; k < 2; k++)
		for (int i = 0; i < 2*maxn; i++)
			for (int j = 0; j < 2*maxn; j++)
				tmp[k][i][j] = 0;

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			vv[i][j] = false;

	dfs(a.fst, a.snd, tmp[0], vv);

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			vv[i][j] = false;

	dfs(b.fst, b.snd, tmp[1], vv);

	bump(tmp[0]); bump(tmp[1]);

/*
	for (int i = 0; i < 2*maxn; i++){
		for (int j = 0; j < 2*maxn; j++)
			printf("%c", tmp[0][i][j] ? '1' : '0');
		printf("\n");
	}

	printf("\n");
	for (int i = 0; i < 2*maxn; i++){
		for (int j = 0; j < 2*maxn; j++)
			printf("%c", tmp[1][i][j] ? '1' : '0');
		printf("\n");
	}
*/

	for (int x = 0; x < 2; x++){
		for (int k = 0; k < 4; k++){
			if (eq()) return true;
			rotate();
		}
		flip();
	}

	return false;
}

int main(){
	openFiles();

	scanf("%d %d", &W, &H);

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++){
			scanf(" %c", &m[i][j]);
			m[i][j] = m[i][j] == '1';
			p[i][j] = pii(i,j);
		}

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			if (m[i][j])
			for (int k = 0; k < 8; k++){
				int ni = i + dr[k];
				int nj = j + dc[k];
				if (m[ni][nj]){
					join(pii(i,j), pii(ni,nj));
				}
			}

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			if (m[i][j])
				for (int ii = 1; ii <= H; ii++)
					for (int jj = 1; jj <= W; jj++)
						if (m[ii][jj]){
							auto g = id(pii(ii,jj));
							auto gg = id(pii(i,j));

							if (g == gg) continue;
							if (v[g.fst][g.snd].count(pii(gg.fst, gg.snd))) continue;

							v[g.fst][g.snd].insert(pii(gg.fst, gg.snd));
							v[gg.fst][gg.snd].insert(pii(g.fst, g.snd));

							if (same(pii(i,j), pii(ii,jj)))
								join(pii(i,j), pii(ii,jj));
						}
    
	char nextc = 'a';
	for (int i = 1; i <= H; i++){
		for (int j = 1; j <= W; j++){
			if (!m[i][j]){
				printf("0");
			} else {
				auto g = id(pii(i,j));

				if (!c[g.fst][g.snd])
					c[g.fst][g.snd] = nextc++;

				printf("%c", c[g.fst][g.snd]);
			}
		}
		printf("\n");
	}
}
