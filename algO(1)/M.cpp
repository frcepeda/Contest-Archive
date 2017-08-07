#include <iostream>
#include <utility>
#include <algorithm>

#define fst first
#define snd second
#define mp make_pair

using namespace std;

const int maxn = 210;

int T, N, K;
pair<int, int> c[maxn*maxn];
vector<int> adj[maxn];

pair<vector<int>, bool> toposort(){
	function<bool(int)> dfs;

	vector<int> e, v(N, 0);

	dfs = [&](int n){
		if (v[n] == 1) return true;
		if (v[n] == 2) return false;

		v[n] = 2;

		for (auto x: adj[n])
			if (!dfs(x))
				return false;

		e.push_back(n);
		v[n] = 1;

		return true;
	};

	for (int i = 0; i < N; i++)
		if (!dfs(i))
			return mp(e, false);

	reverse(e.begin(), e.end());

	return mp(e, true);
}

vector<int> toarr(const vector<int> &p){
	vector<int> a(p.size());

	for (int i = 0; i < N; i++)
		a[p[i]] = i;

	return a;
}

int score(const vector<int> &p){
	int ans = 0;

	auto v = toarr(p);

	for (int i = 0; i < K; i++)
		if (v[c[i].fst] < v[c[i].snd])
			ans++;

	return ans;
}

int main(){
	cin >> T;

	while (T--){
		cin >> N >> K;

		for (int i = 0; i < N; i++)
			adj[i].clear();

		for (int i = 0; i < K; i++){
			cin >> c[i].fst >> c[i].snd;
			adj[c[i].fst].push_back(c[i].snd);
		}

		auto best = toposort();
		vector<int> p;

		if (!best.snd){
			int bestscore = 0;

			p.clear();

			for (int i = 0; i < N; i++)
				p.push_back(i);

			for (auto ss: vector<int>{7, 17, 1337, 345903485, 999459939, 929292292}){
				srand(ss);
				for (int k = 0; k < 1000000 || bestscore < K/2; k++){
					int w;

					vector<int> s = p;
					random_shuffle(s.begin(), s.end());

					if ((w = score(s)) > bestscore){
						p = s;
						bestscore = w;
					}

					reverse(s.begin(), s.end());

					if ((w = score(s)) > bestscore){
						p = s;
						bestscore = w;
					}
				}
			}
		} else {
			p = move(best.fst);
			cerr << "DAG!" << endl;
		}

		cerr << "Score: " << score(p) << "/" << K << endl;

		p = toarr(p);

		for (int i = 0; i < N; i++)
			cout << p[i] << (i+1 < N ? ' ' : '\n');

		cerr << "Remaining: " << T << endl;
	}
}
