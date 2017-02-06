#include <cstdio>
#include <algorithm>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

const int maxn = 1000100;
int acc[maxn];
pair<int,int> g[maxn]; int gc;

int tree[4*maxn];

void init(int n, int l, int r){
	if (l == r){
		tree[n] = g[l].snd;
		return;
	}

	init(2*n+1, l, (l+r)/2);
	init(2*n+2, (l+r)/2+1, r);

	tree[n] = min(tree[2*n+1], tree[2*n+2]);
}

int query(int n, int i, int j, int l = 0, int r = gc-1){
	if (j < l || r < i) return 1<<30;

	if (i <= l && r <= j) return tree[n];

	return min(query(2*n+1, i, j, l, (l+r)/2),
	           query(2*n+2, i, j, (l+r)/2+1, r));
}

int T, A, B;

int main(){
	for (int i = 4; i < maxn; i += 2)
		acc[i] = 1;
	for (int i = 3; i*i < maxn; i += 2)
		if (!acc[i])
			for (int j = i*i; j < maxn; j += i)
				acc[j] = 1;

	int pp = 2;
	for (int i = 3; i < maxn; i += 2){
		if (acc[i]) continue;
		g[gc++] = mp(pp, i - pp);
		pp = i;
	}

	gc -= 1;

	for (int i = 0; i < gc; i++)
		g[i].snd += g[i+1].snd;

	init(0, 0, gc-1);

	scanf("%d", &T);

	while (T--){
		scanf("%d %d", &A, &B);

		int start = lower_bound(g, g + gc, mp(A, 0)) - g;

		if (start == gc){
			printf("-1\n");
			continue;
		}

		int end = upper_bound(g + start, g + gc, mp(B, 0),
			[](pair<int,int> l, pair<int,int> r){
				return l.fst < r.fst + r.snd;
			}
		) - g;

		if (start == end)
			printf("-1\n");
		else
			printf("%d\n", query(0, start, end - 1) + 1);
	}
}
