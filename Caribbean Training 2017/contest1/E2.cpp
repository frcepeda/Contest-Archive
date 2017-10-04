#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii, int> piii;

using namespace __gnu_pbds;
typedef tree<piii, null_type, greater<piii>, rb_tree_tag,
	tree_order_statistics_node_update> ost;

struct node {
	int c[4], s;
	pii m;
	vector<int> p;
	int pend;
};

const int maxn = 100100;
const int maxt = 5000000;
const int inf = 1<<30;
int n, c[maxn], u[maxn], p[maxn];

node T[maxt];
int nextn = 2;

map<pii, vector<int>> m;

pii tmin(const pii &a, const pii &b){
	if (a.fst < b.fst)
		return a;
	else if (a.fst > b.fst)
		return b;
	return a.fst != inf && p[a.snd] > p[b.snd] ? a : b;
}

void push(int x){
	if (T[x].s && T[x].pend){
		T[x].m.fst += T[x].pend;
		
		for (int j = 0; j < 4; j++){
			T[T[x].c[j]].pend += T[x].pend;
		}

		T[x].pend = 0;
	}
}

void build(int i, int v, bool z, int x = 1, int l = 0, int r = inf, int b = 0, int t = inf){
	if (c[i] < l || c[i] > r || u[i] < b || u[i] > t) return;

	if (l == r && b == t){
		if (z && !T[x].p.empty()){
			int j = *T[x].p.rbegin();
			T[x].p.pop_back();
			T[x].m = mp(v, j);
		} else if (!z) {
			T[x].p.push_back(v);
			T[x].s++;
		}
		return;
	}

	if (T[x].c[0] == 0){
		for (int j = 0; j < 4; j++){
			T[x].c[j] = nextn++;
			T[T[x].c[j]].m = mp(inf, inf);
		}
		assert(nextn < maxt);
	}

	int c = (l+r)/2;
	int d = (b+t)/2;

	build(i, v, z, T[x].c[0], l, c, b, d);
	build(i, v, z, T[x].c[1], c+1, r, b, d);
	build(i, v, z, T[x].c[2], l, c, d+1, t);
	build(i, v, z, T[x].c[3], c+1, r, d+1, t);

	T[x].s = 0;
	T[x].m = mp(inf, inf);
	for (int j = 0; j < 4; j++){
		T[x].s += T[T[x].c[j]].s;
		T[x].m = tmin(T[x].m, T[T[x].c[j]].m);
	}
}

void update(int ll, int rr, int bb, int tt, int x = 1, int l = 0, int r = inf, int b = 0, int t = inf){
	push(x);

	if (!T[x].s || rr < l || r < ll || tt < b || t < bb) return;

	if (ll <= l && r <= rr && bb <= b && t <= tt){
		T[x].pend--;
		push(x);
		return;
	}

	int c = (l+r)/2;
	int d = (b+t)/2;

	update(ll, rr, bb, tt, T[x].c[0], l, c, b, d);
	update(ll, rr, bb, tt, T[x].c[1], c+1, r, b, d);
	update(ll, rr, bb, tt, T[x].c[2], l, c, d+1, t);
	update(ll, rr, bb, tt, T[x].c[3], c+1, r, d+1, t);

	T[x].m = mp(inf, inf);
	for (int j = 0; j < 4; j++)
		T[x].m = tmin(T[x].m, T[T[x].c[j]].m);
}

int count(int ll, int rr, int bb, int tt, int x = 1, int l = 0, int r = inf, int b = 0, int t = inf){
	push(x);

	if (!T[x].s || rr < l || r < ll || tt < b || t < bb)
		return 0;

	if (ll <= l && r <= rr && bb <= b && t <= tt)
		return T[x].s;

	int c = (l+r)/2;
	int d = (b+t)/2;

	return count(ll, rr, bb, tt, T[x].c[0], l, c, b, d) +
		count(ll, rr, bb, tt, T[x].c[1], c+1, r, b, d) +
		count(ll, rr, bb, tt, T[x].c[2], l, c, d+1, t) +
		count(ll, rr, bb, tt, T[x].c[3], c+1, r, d+1, t);
}

void remove(int i, int x = 1, int l = 0, int r = inf, int b = 0, int t = inf){
	push(i);

	if (!T[x].s || c[i] < l || c[i] > r || u[i] < b || u[i] > t) return;

	if (l == r && b == t){
		if (!T[x].p.empty()){
			int j = *T[x].p.rbegin();
			T[x].p.pop_back();
			T[x].m = mp(0, j);
			T[x].s--;
		} else T[x].m = mp(inf,inf);
		return;
	}

	int c = (l+r)/2;
	int d = (b+t)/2;

	remove(i, T[x].c[0], l, c, b, d);
	remove(i, T[x].c[1], c+1, r, b, d);
	remove(i, T[x].c[2], l, c, d+1, t);
	remove(i, T[x].c[3], c+1, r, d+1, t);

	T[x].m = mp(inf, inf);
	for (int j = 0; j < 4; j++)
		T[x].m = tmin(T[x].m, T[T[x].c[j]].m);

	assert(T[x].m >= 0);
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d %d %d", &c[i], &u[i], &p[i]);
		build(i, i, false);
	}

	for (int i = 0; i < n; i++){
		auto &w = m[mp(c[i], u[i])];
		sort(w.begin(), w.end(), [=](int x, int y){ return p[x] < p[y]; });
		build(i, count(c[i]+1, inf, u[i]+1, inf), true);
	}

	for (int i = 1; i <= n; i++){
		auto a = T[1].m;
		printf("%d%c", a.snd+1, i < n ? ' ' : '\n');
		update(0, c[a.snd]-1, 0, u[a.snd]-1);
		remove(a.snd);
	}
}
