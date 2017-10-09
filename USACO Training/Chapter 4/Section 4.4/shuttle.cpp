/*
    ID: frceped1
    LANG: C++
    TASK: shuttle
 */

#include <algorithm>
#include <map>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

#ifdef LOCAL
	#define openFiles()
#else
	#define openFiles() freopen("shuttle.in", "r", stdin); freopen("shuttle.out", "w", stdout)
#endif

#define fst first
#define snd second
#define mp make_pair

typedef long long ll;

struct mov {
	ll parent;
	int mm;

	mov() {}
	mov(ll p, int m) : parent(p), mm(m) {}
};

const int maxn = 12;
int N;
string s, e;
map<ll, mov> v;

string fromNum(ll x){
	string r;

	for (int i = 0; i < 2*N+1; i++, x /= 3)
		r += x % 3 == 0 ? 'B' : x % 3 == 1 ? 'W' : '.';

	reverse(r.begin(), r.end());

	return r;
}

ll toNum(const string &s){
	ll r = 0;

	for (int i = 0; i < 2*N+1; i++)
		r = r * 3 + (s[i] == 'B' ? 0 : s[i] == 'W' ? 1 : 2);

	return r;
}

inline char opp(char x){ return x == 'B' ? 'W' : 'B'; }

void bfs(){
	queue<ll> q;

	q.push(toNum(s));

	while (true) {
		ll currNum = q.front(); q.pop();
		string curr = fromNum(currNum);

		if (curr == e) break;

		int w;
		for (w = 0; w < 2*N+1; w++)
			if (curr[w] == '.')
				break;

		for (int i = w-2; i <= w+2; i++){
			if (i < 0 || i >= 2*N+1 || curr[i] == '.') continue;

			string next = curr;
			int d = curr[i] == 'W' ? 1 : -1;

			if (i+d >= 0 && i+d < 2*N+1 && curr[i+d] == '.'){
				swap(next[i], next[i+d]);

				ll nn = toNum(next);

				if (v.find(nn) == v.end()){
					v[nn] = mov(currNum, i+1);
					q.push(nn);
				}
			}

			if (i+2*d >= 0 && i+2*d < 2*N+1 && curr[i+d] == opp(curr[i]) && curr[i+2*d] == '.'){
				swap(next[i], next[i+2*d]);

				ll nn = toNum(next);

				if (v.find(nn) == v.end()){
					v[nn] = mov(currNum, i+1);
					q.push(nn);
				}
			}
		}
	}
}

int main(){
	openFiles();

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		s += 'W';
	s += '.';
	for (int i = 0; i < N; i++)
		s += 'B';

	e = s;
	reverse(e.begin(), e.end());

	bfs();

	vector<int> ans;
	ll goal = toNum(s);
	for (ll x = toNum(e); x != goal; x = v[x].parent)
		ans.push_back(v[x].mm);

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], i+1 == ans.size() || (i+1) % 20 == 0 ? '\n' : ' ');
}
