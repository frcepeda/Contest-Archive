#include <cstdio>
#include <algorithm>

using namespace std;

#define fst first
#define snd second
#define mp make_pair

enum upd {
	nothing,
	flip,
	left,
	right
};

typedef pair<int,int> pii;

struct node {
	node *l, *r;
	upd u; bool rev, me;
	pii c;
	int cnt, pr;
	node(): l(NULL), r(NULL), u(nothing), rev(false), me(false), c(mp(1,0)), cnt(0) {}
} sto[1000100];

typedef node * pnode;

void apply(pnode t, upd u){
	if (t == NULL) return;
	if (u == flip){
		t->c = mp(t->c.snd, t->c.fst);
		t->me ^= true;
		if (t->u == left)
			t->u = right;
		else if (t->u == right)
			t->u = left;
		else if (t->u == flip)
			t->u = nothing;
		else
			t->u = flip;
	} else if (u == left){
		t->c = mp(t->c.fst + t->c.snd, 0);
		t->u = left;
		t->me = false;
	} else if (u == right){
		t->c = mp(0, t->c.fst + t->c.snd);
		t->u = right;
		t->me = true;
	}
}

void push(pnode t){
	if (t != NULL){
		if (t->rev){
			t->rev = false;
			swap(t->l, t->r);
			if (t->l != NULL) t->l->rev ^= true;
			if (t->r != NULL) t->r->rev ^= true;
		}

		if (t->u != nothing){
			apply(t->l, t->u);
			apply(t->r, t->u);
			t->u = nothing;
		}
	}
}

int cnt(pnode t){
	if (t == NULL) return 0;
	return t->cnt;
}

void update(pnode t){
	if (t != NULL){
		t->c = mp(!t->me, t->me);
		t->cnt = 1;

		if (t->l != NULL){
			t->c.fst += t->l->c.fst;
			t->c.snd += t->l->c.snd;
			t->cnt += t->l->cnt;
		}

		if (t->r != NULL){
			t->c.fst += t->r->c.fst;
			t->c.snd += t->r->c.snd;
			t->cnt += t->r->cnt;
		}
	}
}

void split(pnode t, pnode &l, pnode &r, int k, int add = 0){
	if (t == NULL){
		l = r = NULL;
		return;
	}
	push(t);
	int key = add + cnt(t->l);
	if (key < k){
		split(t->r, t->r, r, k, key + 1), l = t;
		update(l);
	} else {
		split(t->l, l, t->l, k, add), r = t;
		update(r);
	}
}

void merge(pnode &t, pnode l, pnode r){
	push(l); push(r);
	if (l == NULL)
		t = r;
	else if (r == NULL)
		t = l;
	else if (l->pr > r->pr)
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l, l, r->l), t = r;
	update(t);
}

int N, M;

int main(){
	while (scanf("%d %d", &N, &M) != EOF){
		pnode root = &sto[0];

		for (int i = 0; i < N; i++){
			sto[i] = node();
			sto[i].pr = rand();
			if (i) merge(root, root, &sto[i]);
		}

		while (M--){
			int t, i, j, c;
			scanf("%d %d %d", &t, &i, &j);

			pnode l = NULL, m = NULL, r = NULL;
			split(root, l, m, i);
			split(m, m, r, j-i+1);

			if (t == 0){
				printf("%d %d\n", m->c.snd, m->c.fst);
			} else if (t == 1){
				m->rev ^= true;
			} else if (t == 2){
				apply(m, flip);
			} else if (t == 3){
				scanf("%d", &c);
				apply(m, c == 0 ? right : left);
			}

			merge(root, l, m);
			merge(root, root, r);
		}
	}
}
