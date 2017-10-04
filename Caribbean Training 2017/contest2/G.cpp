#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <random>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

struct node {
	int v, cnt, t;
	const node *l, *r;

	node() : v(-1), cnt(0), l(NULL), r(NULL) {}
	node(int v) : v(v), cnt(1), l(NULL), r(NULL) {}
	node(const node *n) : v(n->v), cnt(n->cnt), l(n->l), r(n->r) {}
};

typedef pair<int,int> pii;
typedef node * pnode;
typedef const node * cpnode;

const int maxs = 4000000;
node S[maxs];
int nexts, nodec, currt = 1;

pnode allocN(){
	for (nodec++; S[nexts].t == currt; nexts++);
	return &S[nexts++];
};

void mark(cpnode x, int t){
	if (!x) return;
	const_cast<pnode>(x)->t = t;
	mark(x->l, t);
	mark(x->r, t);
}

void gc(cpnode root){
	fprintf(stderr, "gc!\n"); fflush(stderr);
	mark(root, ++currt);
	nexts = 0;
}

int cnt(cpnode x) { return x ? x->cnt : 0; }

bool unif(int a, int b){
	return (long long)(a) * RAND_MAX > (long long)(a+b) * rand();
}

cpnode merge(cpnode l, cpnode r){
	if (!l || !r) return l ? l : r;

	pnode x = allocN();

	if (unif(cnt(l), cnt(r))){
		*x = *l;
		x->r = merge(l->r, r);
	} else {
		*x = *r;
		x->l = merge(l, r->l);
	}

	x->cnt = cnt(x->l) + 1 + cnt(x->r);
	return x;
}

pair<cpnode,cpnode> split(cpnode x, int k){
	if (!x) return mp(nullptr, nullptr);
	if (k == 0) return mp(nullptr, x);
	if (k == x->cnt) return mp(x, nullptr);

	pnode t = allocN(); *t = *x;
	pair<cpnode,cpnode> ret;

	if (k <= cnt(x->l)){
		ret = split(x->l, k);
		t->l = ret.snd;
		ret = mp(ret.fst, t);
	} else {
		ret = split(x->r, k - cnt(x->l) - 1);
		t->r = ret.fst;
		ret = mp(t, ret.snd);
	}

	t->cnt = cnt(t->l) + 1 + cnt(t->r);
	return ret;
}

void inorder(cpnode x, vector<int> &v){
	if (!x) return;
	inorder(x->l, v);
	v.push_back(x->v);
	inorder(x->r, v);
}

int n, m;

int main(){
	srand(1337);

	scanf("%d %d", &n, &m);

	vector<int> count(m), from(m), to(m);
	vector<cpnode> tree(m+1);

	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &count[i], &from[i], &to[i]);

	tree[m] = NULL;
	for (int i = 0; i < n; i++){
		auto x = allocN(); *x = node(i);
		tree[m] = merge(tree[m], x);
	}

#ifdef TEST
	vector<int> v(n), w(n), z;
	for (int i = 0; i < n; i++)
		v[i] = i;
#endif

	for (int i = m-1; i >= 0; i--){
		auto source = split(split(tree[i+1], to[i]-1).snd, count[i]).fst;

		cpnode left, dump, right;
		tie(left, dump) = split(tree[i+1], from[i]-1);
		tie(dump, right) = split(dump, count[i]);

		tree[i] = merge(merge(left, source), right);

		if (nexts >= maxs - 10000) gc(tree[i]);

#ifdef TEST
		copy(v.begin(), v.end(), w.begin());
		copy(v.begin() + to[i]-1, v.begin() + to[i]-1+count[i], w.begin() + from[i]-1);
		copy(w.begin(), w.end(), v.begin());
		z.clear();
		assert(z.size() == 0);
		inorder(tree[i], z);
		if (z != v) exit(0);
#endif
	}

	fprintf(stderr, "total gc count %d\n", currt-1);
	fprintf(stderr, "total nodes allocated %d\n", nodec);

	vector<int> ans; ans.reserve(n);
	inorder(tree[0], ans);
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i]+1, i+1 < ans.size() ? ' ' : '\n');
}
