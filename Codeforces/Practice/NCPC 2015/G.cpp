#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

#define fst first
#define snd second
#define mp make_pair

using namespace std;

#define MAXG 100010
#define MAXM 20020
#define L 10001

typedef pair<int,int> pii;

int g, m;
pii p[MAXG], c[MAXM];
int r[MAXG];

pair<int,pii> cE[2*MAXM];

int main(){
	int i, j, k, ans = 0;

	scanf("%d", &g);

	for (i = 0; i < g; i++)
		scanf("%d %d", &p[i].fst, &p[i].snd);

	sort(p, p + g);

	scanf("%d", &m);

	for (i = 0; i < m; i++){
		scanf("%d %d %d", &c[i].fst, &c[i].snd, &r[i]);
		cE[2*i]   = mp(c[i].fst - r[i], mp(0, i));
		cE[2*i+1] = mp(c[i].fst + r[i], mp(1, i));
	}

	sort(cE, cE + 2*m);

	set<int> active;
	vector<pii> t;

	for (i = j = k = 0; i < L; i++){
		for (; j < 2*m && (cE[j].fst < i || (cE[j].fst == i && cE[j].snd.fst == 0)); j++){
			if (cE[j].snd.fst == 0)
				active.insert(cE[j].snd.snd);
			else
				active.erase(cE[j].snd.snd);
		}

		t.clear();
		for (; k < g && p[k].fst < i; k++);
		for (; k < g && p[k].fst == i; k++)
			t.push_back(mp(p[k].snd, 1));

		if (t.size() == 0) continue;

		for (auto &x : active){
			int d = abs(c[x].fst - i);
			double h = sqrt(r[x]*r[x] - d*d);
			t.push_back(mp(ceil(c[x].snd - h), 0));
			t.push_back(mp(floor(c[x].snd + h), 2));
		}

		sort(t.begin(), t.end());

		int o = 0;
		for (auto &x : t){
			if (x.snd == 0)
				o++;
			else if (x.snd == 1)
				ans += o == 0;
			else
				o--;
		}
	}

	printf("%d\n", ans);
}
