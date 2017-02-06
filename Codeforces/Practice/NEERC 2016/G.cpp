#include <cstdio>
#include <set>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

vector<pair<int,pair<int,int>>> moves;

const int maxn = 105;
int n;
bool adj[maxn][maxn];

#ifdef TEST
int c[maxn][maxn], s[maxn], steps;
#endif

int m(int x){
	if (x % n) return (x % n + n) % n;
	else return n;
}

int move(int i, int k, int j){
	if (i == 0 || j == 0) k = 1;
#ifdef TEST
	if (j == 0 && s[0]) exit(-1);
	if (!c[i][k] || s[j] == n) exit(-1);
	c[i][k]--; s[i]--;
	c[j][k]++; s[j]++;
	steps++;
#else
	printf("%d %d %d\n", i, k, j);
#endif
}

void dfs(int x){
	for (int i = 0; i <= n; i++){
		if (adj[x][i]){
			adj[x][i] = false;
			dfs(i);
			moves.push_back(mp(i, mp(i, x)));
		}
	}
}

int main(){
	scanf("%d", &n);

	adj[0][1] = adj[2][0] = true;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				adj[i][j] = true;

	adj[2][1] = false;

#ifdef TEST
	for (int i = 1; i <= n; i++){
		c[i][i] = n;
		s[i] = n;
	}
#endif

	dfs(0);

	for (auto it = moves.rbegin(); it != moves.rend(); it++)
		move(it->fst, it->snd.fst, it->snd.snd);

#ifdef TEST
	for (int i = 1; i <= n; i++)
		if (s[i] != n || any_of(c[i]+1, c[i]+1+n, [](int x){ return x != 1; }))
			exit(-1);
	printf("OK: %d steps (%d optimal?)\n", steps, n*(n-1) + 1);
#endif
}
