/*
    ID: frceped1
    LANG: C++
    TASK: buylow
 */

#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

#ifdef LOCAL
	#define openFiles()
#else
	#define openFiles() freopen("buylow.in", "r", stdin); freopen("buylow.out", "w", stdout)
#endif

#define fst first
#define snd second
#define mp make_pair

const int maxn = 5010;

typedef string ll;
typedef pair<int,ll> pii;

int N, a[maxn], b[maxn];
pii tree[4*maxn];

string add(string &a, string &b){
	if (a.empty()) return b;
	if (b.empty()) return a;

	string r = "";

	char acc = 0;

	for (int i = 0; i < max(a.size(), b.size()); i++){
		char aa = i < a.size() ? a[a.size()-i-1] - '0' : 0;
		char bb = i < b.size() ? b[b.size()-i-1] - '0' : 0;
		acc += aa + bb;
		r += acc % 10 + '0';
		acc /= 10;
	}

	if (acc) r += acc % 10 + '0';

	reverse(r.begin(), r.end());

	return r;
}

pii merge(pii a, pii b){
	if (a.fst == b.fst)
		return mp(a.fst, add(a.snd, b.snd));
	return max(a, b);
}

pii query(int x, int y, int n = 0, int l = 0, int r = N-1){
	if (y < l || r < x) return mp(0, "0");

	if (x <= l && r <= y)
		return tree[n];

	return merge(query(x, y, 2*n+1, l, (l+r)/2),
	             query(x, y, 2*n+2, (l+r)/2+1, r));
}

void update(int i, pii v, int n = 0, int l = 0, int r = N-1){
	if (i < l || r < i) return;

	tree[n] = merge(tree[n], v);

	if (l == r) return;

	update(i, v, 2*n+1, l, (l+r)/2);
	update(i, v, 2*n+2, (l+r)/2+1, r);
}

bool idxcmp(int x, int y){
	return mp(a[x], -x) > mp(a[y], -y);
}

int main(){
	openFiles();

	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		b[i] = i;
	}

	sort(b, b + N, idxcmp);

	for (int i = 0; i < N; i++){
		int l = i && a[b[i-1]] == a[b[i]] ? b[i-1] + 1 : 0;

		pii q = query(l, b[i]-1);

		q.fst++;

		if (q.fst == 1 && l == 0)
			q.snd = "1";

		update(b[i], q);
	}

	pii q = query(0, N-1);

	printf("%d %s\n", q.fst, q.snd.c_str());
}
