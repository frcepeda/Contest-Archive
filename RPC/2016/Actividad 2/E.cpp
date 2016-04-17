#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 510
#define fst first
#define snd second
#define mp make_pair
#define TREE (50*MAXN*MAXN)

typedef pair<int,int> pii;

int T, M, N, K;

char g[MAXN][MAXN];
bool tree[TREE];

bool btwn(int a, int b, int c){
	return a <= b && b <= c;
};

bool contained(int i, int j, int k, int l, int a, int b, int c, int d){
	return btwn(a, i, c) && btwn(a, k, c) && btwn(b, j, d) && btwn(b, l, d);
}

bool intersect(int i, int j, int k, int l, int a, int b, int c, int d){
	int p = max(i, a), q = max(j, b);
	int r = min(k, c), s = min(l, d);
	return p <= r && q <= s;
}

void update(int n, int i, int j, int k, int l, int a, int b, int c, int d){
	if (!intersect(i, j, k, l, a, b, c, d)) return;
	if (tree[n]) return;

	if (contained(i, j, k, l, a, b, c, d)){
		tree[n] = true;
		return;
	}

	int ik = (i + k)/2, jl = (j + l)/2;
	update(4*n+1, i, j, ik, jl, a, b, c, d);//a, b, ac, ad);
	update(4*n+2, ik+1, j, k, jl, a, b, c, d);//ac+1, b, c, bd);
	update(4*n+3, i, jl+1, ik, l, a, b, c, d);//a, bd+1, ac, d);
	update(4*n+4, ik+1, jl+1, k, l, a, b, c, d);//ac+1, bd+1, c, d);
}

bool query(int n, int i, int j, int k, int l, int a, int b){
	if (!contained(a,b,a,b,i,j,k,l)) return false;
	if (tree[n] || (i == a && k == a && j == b && l == b))
		return tree[n];
	bool r = false;
	int ik = (i + k)/2, jl = (j + l)/2;
	r |= query(4*n+1, i, j, ik, jl, a, b);
	r |= query(4*n+2, ik+1, j, k, jl, a, b);
	r |= query(4*n+3, i, jl+1, ik, l, a, b);
	r |= query(4*n+4, ik+1, jl+1, k, l, a, b);
	return r;
}

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i < TREE; i++)
			tree[i] = false;

		for (int i = 1; i <= N; i++)
			scanf("%s", g[i]+1);

		while (K--){
			int ta, tb, tc, td;
			scanf("%d %d %d %d", &ta, &tb, &tc, &td);
			int a = N-td+1, c = N-tb+1;
			int b = ta, d = tc;
			update(0, 1, 1, N, M, a, b, c, d);
		}

		int ans[2] = {0};
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (query(0, 1, 1, N, M, i, j))
					ans[g[i][j] == 'R']++;

		printf("%d %d\n", ans[0], ans[1]);
	}
}
