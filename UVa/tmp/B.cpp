#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
	int v;
	node *l, *r;
};

typedef node * pnode;

#define fst first
#define snd second

const int maxn = 1000100;
int n, q, a[maxn];
pair<int,int> b[maxn];
pnode t[maxn];

node nodes[maxn*41];
int nextNode;

pnode build(int l = 1, int r = n){
	pnode x = &nodes[nextNode++];

	x->v = 0;

	if (l == r){
		x->l = x->r = NULL;
		return x;
	}

	x->l = build(l, (l+r)/2);
	x->r = build((l+r)/2+1, r);

	return x;
}

pnode update(pnode nn, int i, int l = 1, int r = n){
	if (i < l || r < i) return nn;

	pnode x = &nodes[nextNode++];

	x->v = nn->v + 1;

	if (l == r){
		x->l = x->r = NULL;
		return x;
	}

	x->l = update(nn->l, i, l, (l+r)/2);
	x->r = update(nn->r, i, (l+r)/2+1, r);

	return x;
}

int query(pnode x, pnode y, int k, int l = 1, int r = n){
	if (l == r) return l;

	int cnt = y->l->v - x->l->v;

	if (cnt >= k)
		return query(x->l, y->l, k, l, (l+r)/2);

	return query(x->r, y->r, k - cnt, (l+r)/2+1, r);
}

int main(){
	while (scanf("%d %d", &n, &q) != EOF){
		nextNode = 0;

		for (int i = 1; i <= n; i++){
			b[i].snd = i;
			scanf("%d", &b[i].fst);
		}

		sort(b+1, b+1 + n);

		for (int i = 1; i <= n; i++)
			a[b[i].snd] = i;

		t[0] = build();
		for (int i = 1; i <= n; i++)
			t[i] = update(t[i-1], a[i]);

		while (q--){
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);
			printf("%d\n", b[query(t[l-1], t[r], k)].fst);
		}
	}
}
