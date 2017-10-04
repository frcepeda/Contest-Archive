// Accepted
#include <cstdio>
#include <algorithm>

using namespace std;

#define mp pii
#define fst first
#define snd second
#define pb push_back

struct pii {
	int l, r;

	pii() { }
	pii(int l, int r) : l(l), r(r) {}
	pii(const pii &p) : l(p.l), r(p.r) {}
	bool operator < (const pii &p) const {
		return make_pair(l, r) < make_pair(p.l, p.r);
	}
};

const int maxn = 15;
int n, a[maxn];

vector<pii> v[maxn];

vector<pii> step(int ai, pii range){
	int l = range.l, r = range.r;
	vector<pii> ans;

	if (r < 0) return ans;

	pii right = mp(ai-r, ai+r);

	if (l < 0){
		ans.pb(right);
	} else {
		if (l + ai <= right.r)
			ans.pb(mp(max(right.l, l+ai), right.r));
		if (right.l <= ai - l)
			ans.pb(mp(right.l, min(right.r, ai-l)));
	}

	return ans;
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	v[n].pb(mp(-1, 1));

	for (int i = n-1; i >= 0; i--){
		for (auto z: v[i+1]){
			auto w = step(a[i], z);
			for (auto z: w) v[i].pb(z);
		}

		sort(v[i].begin(), v[i].end());

		vector<pii> tmp;

		for (auto w: v[i]){
			while (!tmp.empty()){
				pii p = *tmp.rbegin();

				if (p.r >= w.l){
					w.l = p.l;
					tmp.pop_back();
				} else break;
			}
			tmp.pb(w);
		}

		v[i] = tmp;
	}

	printf("%lu\n", v[0].size());

	for (auto w: v[0])
		printf("%d %d\n", w.l, w.r);
}
