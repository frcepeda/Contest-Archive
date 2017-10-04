#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> pii;

int M, N, p, q;
pii s, t;

map<pii,pii> pr;

int dx[8], dy[8];

vector<pii> go(){
	queue<pii> q;

	pr[s] = mp(0,0);
	q.push(s);

	while (!q.empty()){
		pii c = q.front(); q.pop();

		for (int i = 0; i < 8; i++){
			pii d = mp(c.fst + dx[i], c.snd + dy[i]);

			if (d.fst < 1 || d.fst > M ||
			    d.snd < 1 || d.snd > N ||
			    pr.find(d) != pr.end()) continue;

			pr[d] = c;
			q.push(d);
		}
	}

	vector<pii> v;

	if (pr.find(t) == pr.end())
		return v;

	for (pii c = t; c != mp(0,0); c = pr[c])
		v.push_back(c);

	return v;
}

int main(){
	scanf("%d %d %d %d %d %d %d %d", &M, &N, &p, &q, &s.fst, &s.snd, &t.fst, &t.snd);

	for (int i = 0; i < (1<<3); i++){
		int a = (i&1) ? p : q;
		int b = (i&1) ? q : p;
		dx[i] = a * ((i&2)?1:-1);
		dy[i] = b * ((i&4)?1:-1);
	}

	vector<pii> v = go();

	printf("%d\n", ((int)v.size())-1);

	for (vector<pii>::reverse_iterator i = v.rbegin(); i != v.rend(); i++)
		printf("%d %d\n", i->fst, i->snd);
}
