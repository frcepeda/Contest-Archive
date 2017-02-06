#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 100100;
int n, m, k[MAXN], c[MAXN][2], fw[MAXN], l[MAXN];
bool v[MAXN];
vector<pair<int, bool>> adj[MAXN];
vector<pll> groups;

pll dp(vector<int> &idx, bool loop){
	ll prev[2][2], curr[2][2];

	for (int i = idx.size()-1; i >= 0; i--){
		bool flip = false;

		if (loop || i < idx.size()-1){
			bool j = adj[idx[i]].size() > 1
			       && adj[idx[i]][0].fst != idx[i+1];
			flip = adj[idx[i]][j].snd;
		}

		for (x = 0; x <= 1; x++)
			for (int p = 0; p <= 1; p++){
				if (!loop || i){
					if ((p && !flip) || (!p && flip))
						curr[x][p] = prev[x^1][1] + prev[x^1][0];
					else
						curr[x][p] = prev[x^1][1] + prev[x][0];
				} else {
				}
			}

		prev[0][0] = curr[0][0];
		prev[0][1] = curr[0][1];
		prev[1][0] = curr[1][0];
		prev[1][1] = curr[1][1];
	}

	return mp(prev[0][0] + prev[0][1], prev[1][0] + prev[1][1]);
}

pll go(int x){
	v[x] = true;

	if (k[x] == 2){
		if (c[x][0] == c[x][1])
			return mp(1, 1);
		else if (c[x][0] == -c[x][1])
			return mp(1, 0);
	}

	if (adj[x].empty())
		return mp(1, 1);

	deque<int> tmp;
	tmp.push_back(x);
	bool frontback = false;
	bool looped = false;
	for (auto ww: adj[x]){
		int w = ww.fst;
		int last = x;

		while (w != x){
			if (frontback)
				tmp.push_front(w);
			else
				tmp.push_back(w);

			if (adj[w].size() < 2) break;

			int nn = adj[w][adj[w][0].fst == last].fst;
			last = w;
			w = nn;
		}

		if (w == x){
			looped = true;
			break;
		}

		frontback ^= true;
	}

	for (auto w: tmp)
		v[w.fst] = true;

	return dp(tmp, looped);
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		scanf("%d", &k[i]);

		for (int j = 0; j < k[i]; j++)
			scanf("%d", &c[i][j]);

		if (k[i] == 2 && abs(c[i][0]) == abs(c[i][1]))
			continue;

		for (int j = 0; j < k[i]; j++){
			int x = abs(c[i][j]);
			if (l[x]){
				bool flip = false;
				for (int z = 0; z < k[l[x]]; z++)
					if (c[i][j] == -c[l[x]][z])
						flip = true;

				adj[i].push_back(mp(l[x], flip));
				adj[l[x]].push_back(mp(i, flip));
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (!v[i])
			groups.push_back(go(i));
}
