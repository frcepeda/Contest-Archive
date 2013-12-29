#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define MAXN 100010
#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> pii;

struct sortsnd {
	  bool operator() (const pii &a, const pii &b) const {return a.snd < b.snd;}
};

int n, m, s;
pii a[MAXN];
pair<pii,int> b[MAXN];
int c[MAXN];
set<pii> active;
int chosen[MAXN], cCnt;
int best[MAXN], bCnt;

bool check(int d){
	int i = n-1, j = m-1, _s = s;
	cCnt = 0;
	active.clear();

	while (j >= 0 && _s >= 0){
		for (; i >= 0 && a[j].fst <= b[i].fst.fst; i--)
			active.insert(mp(b[i].fst.snd, b[i].snd));

		set<pii>::iterator it = active.begin();

		if (it == active.end()) return false;

		_s -= it->fst;
		chosen[cCnt++] = it->snd;
		j -= d;

		active.erase(it);
	}

	return j < 0 && _s >= 0;
}

int main(){
	int i, lo, mid, hi;

	scanf("%d %d %d", &n, &m, &s);

	for (i = 0; i < m; i++){
		scanf("%d", &a[i].fst);
		a[i].snd = i;
	}

	for (i = 0; i < n; i++)
		scanf("%d", &b[i].fst.fst);

	for (i = 0; i < n; i++)
		scanf("%d", &b[i].fst.snd);

	for (i = 0; i < n; i++)
		b[i].snd = i+1;

	sort(a, a+m);
	sort(b, b+n);
	
	lo = 0; hi = m+1;
	while (lo < hi){
		mid = (lo + hi)/2;
		if (check(mid)){
			for (i = 0; i < cCnt; i++)
				best[i] = chosen[i];
			bCnt = cCnt;
			hi = mid;
		} else
			lo = mid + 1;
	}

	if (bCnt){
		int j = m-1;
		for (i = 0; i < bCnt && j >= 0; i++)
			for (int k = 0; k < hi && j >= 0; k++)
				c[a[j--].snd] = best[i];

		printf("YES\n");
		for (i = 0; i < m; i++)
			printf("%d%c", c[i], i != m-1 ? ' ' : '\n');
	} else printf("NO\n");
}
