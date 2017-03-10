#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 2005

int R, C, P, F;

enum {
	empty,
	fruit,
	pine
} g[MAXN][MAXN];

#define mp make_pair
#define fst first
#define snd second

int sq[MAXN][MAXN], acc[MAXN][MAXN];
int maxFruit;

int fruitAt(int r, int c, int L){
	return acc[r][c] - (r-L >= 0 ? acc[r-L][c] : 0)
	                 - (c-L >= 0 ? acc[r][c-L] : 0)
	                 + (r-L >= 0 && c-L >= 0 ? acc[r-L][c-L] : 0);
}

int main(){
	scanf("%d %d %d %d", &C, &R, &P, &F);

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			g[i][j] = empty;

	int a, b;
	for (int i = 0; i < P; i++){
		scanf("%d %d", &a, &b);
		g[b][a] = pine;
	}

	for (int i = 0; i < F; i++){
		scanf("%d %d", &a, &b);
		g[b][a] = fruit;
	}

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++){
			acc[i][j] = acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1];
			acc[i][j] += g[i][j] == fruit;
			if (g[i][j] != pine){
				sq[i][j] = 1 + min(sq[i-1][j], min(sq[i][j-1], sq[i-1][j-1]));
				maxFruit = max(maxFruit, fruitAt(i, j, sq[i][j]));
			}
		}

	int bestArea = 1<<30;
	pair<int,int> best;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++){
			int lo = 0, hi = sq[i][j], mid;
			while (lo < hi){
				mid = (lo + hi)/2;
				if (fruitAt(i, j, mid) >= maxFruit)
					hi = mid;
				else
					lo = mid + 1;
			}
			if (fruitAt(i, j, hi) >= maxFruit && hi < bestArea){
				bestArea = hi;
				best = mp(i-hi,j-hi);
			}
		}

	printf("%d %d\n%d\n%d\n", best.snd, best.fst, bestArea, maxFruit);
}
