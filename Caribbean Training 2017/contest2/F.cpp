#include <cstdio>
#include <map>
#include <cassert>
#include <algorithm>

using namespace std;

struct node {
	int v;
	const node *l, *r;
};

map<int, int> M;
#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> pii;
typedef node * pnode;
typedef const node * cpnode;

cpnode build(int l, int r){
	pnode n = new node;
	n->v = 1000000009;
	n->l = n->r = NULL;

	if (l == r) return n;

	n->l = build(l, (l+r)/2);
	n->r = build((l+r)/2+1, r);

	return n;
}

cpnode update(cpnode n, int l, int r, int i, int x){
	if (i < l || r < i) return n;

	pnode nn = new node;

	if (l == r){
		nn->v = min(n->v, x);
		nn->l = nn->r = NULL;
		return nn;
	}

	nn->l = update(n->l, l, (l+r)/2, i, x);
	nn->r = update(n->r, (l+r)/2+1, r, i, x);
	nn->v = max(nn->l->v, nn->r->v);

	return nn;
}

int query(cpnode n, int l, int r, int b){
	if (n->v < b) return 0;
	if (l == r) return l;

	if (n->l->v >= b)
		return query(n->l, l, (l+r)/2, b);
	return query(n->r, (l+r)/2+1, r, b);
}

int n, s, m;

int main(){
	scanf("%d %d %d", &n, &s, &m);

#define between(n,a,b) (a <= n && n <= b)
	assert(
		between(n,2,1000000000) &&
		between(s,1,100000) &&
		between(m,0,100000)
	);

	vector<int> a(m), b(m), c(m);

	M[0] = 0;
	M[1000000001] = 0;

	for (int i = 0; i < m; i++){
		scanf("%d %d %d", &c[i], &a[i], &b[i]);
		M[a[i]] = 0; M[b[i]] = 0;
	}

	int nn = 0;
	for (auto &w: M)
		w.snd = nn++;

	vector<cpnode> t(nn+1);

	vector<pii> e;

	for (int i = 0; i < m; i++)
		e.push_back(mp(b[i], i));

	sort(e.begin(), e.end(), greater<pii>());

	t[nn] = build(1, s);
	auto ei = e.begin();

	for (int i = nn-1; i >= 0; i--){
		t[i] = t[i+1];
		for (; ei != e.end() && M[ei->fst] > i; ei++){
			int k = ei->snd;
			t[i] = update(t[i], 1, s, c[k], a[k]);
		}
	}

	int q, p = 0;
	scanf("%d", &q);

	while (q--){
		int x, y, a, b;
		scanf("%d %d", &x, &y);
		a = x + p;
		b = y + p;

		if (a < b){
			a = prev(M.upper_bound(a))->snd;
			p = query(t[a], 1, s, b);
		} else p = 0;

		printf("%d\n", p);
	}
}
