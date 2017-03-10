#include <algorithm>
#include <cstdio>
#include <deque>

using namespace std;

#define MAXN 1010
#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int n, m, a, b, c, d;
int g[MAXN][MAXN], s[MAXN][MAXN];

piii h[MAXN][MAXN];
deque<pair<int,pii>> q;

inline int area(int i, int j, int r, int c){
	return s[i][j] - (i+r <= n ? s[i+r][j] : 0)
	               - (j+c <= m ? s[i][j+c] : 0)
	               + (i+r <= n && j+c <= m ? s[i+r][j+c] : 0);
}

inline int outer(int i, int j){
	return area(i, j, b, a);
}

inline int inner(int i, int j){
	return area(i, j, d, c);
}

int main(){
	scanf("%d %d %d %d %d %d", &m, &n, &a, &b, &c, &d);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &g[i][j]);

	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			s[i][j] = g[i][j] + s[i+1][j] + s[i][j+1] - s[i+1][j+1];

	for (int i = 2; i+d <= n; i++){
		q.clear();

		int j;
		for (j = 2; j+c < a; j++){
			while (!q.empty() && q.back().fst > inner(i,j))
				q.pop_back();
			q.push_back(mp(inner(i,j), mp(i,j)));
		}

		for (; j+c <= m; j++){
			if (j-a+c+1 > 1 && q.front().fst == inner(i, j-a+c+1))
				q.pop_front();
			while (!q.empty() && q.back().fst > inner(i,j))
				q.pop_back();
			q.push_back(mp(inner(i,j), mp(i,j)));
			h[i][j-a+c+2] = q.front();
		}
	}

	auto best = mp(-1, mp(mp(0,0), mp(0,0)));
	for (int j = 1; j+a <= m+1; j++){
		q.clear();

		for (int i = 2; i+d < b; i++){
			while (!q.empty() && q.back().fst > h[i][j+1].fst)
				q.pop_back();
			q.push_back(h[i][j+1]);
		}

		for (int i = 1; i+b <= n+1; i++){
			if (i > 1 && q.front().fst == h[i][j+1].fst)
				q.pop_front();
			while (!q.empty() && q.back().fst > h[i+b-d-1][j+1].fst)
				q.pop_back();

			q.push_back(h[i+b-d-1][j+1]);
			auto z = q.front();

			best = max(best,
			           mp(outer(i,j) - z.fst, mp(mp(i,j), z.snd))
				  );
		}
	}

	printf("%d %d\n%d %d\n", best.snd.fst.snd, best.snd.fst.fst, best.snd.snd.snd, best.snd.snd.fst);
}
