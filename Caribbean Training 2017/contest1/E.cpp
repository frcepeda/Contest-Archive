#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 100100;
int N, c[maxn], u[maxn], p[maxn], c_[maxn], u_[maxn];

struct ccmp { bool operator()(const int &a, const int &b) const { return c[a] < c[b]; } };
struct ucmp { bool operator()(const int &a, const int &b) const { return u[a] < u[b]; } };
struct pcmp { bool operator()(const int &a, const int &b) const { return p[a] < p[b]; } };

set<int, ucmp> T[4*maxn];

void build(int n = 0, int l = 0, int r = N-1){
	for (int i = r; i >= l; i--)
		T[n].insert(c_[i]);

	if (l == r) return;

	build(2*n+1, l, (l+r)/2);
	build(2*n+2, (l+r)/2+1, r);
}

bool any(int ll, int b, int n = 0, int l = 0, int r = N-1){
	if (r < ll) return false;

	if (ll <= l)
		return T[n].lower_bound(b) != T[n].end();

	return any(ll, b, 2*n+1, l, (l+r)/2) ||
	       any(ll, b, 2*n+2, (l+r)/2+1, r);
}

int go(int n, int b){
	if (T[n].size() == 1) return *T[n].begin();
	if (T[2*n+2].lower_bound(b) != T[2*n+2].end())
		return go(2*n+2, b);
	return go(2*n+1, b);
}

int get(int ll, int rr, int b, int n = 0, int l = 0, int r = N-1){
	if (rr < l || r < ll) return -1;

	if (ll <= l && r <= rr){
		auto w = T[n].lower_bound(b);
		return w != T[n].end() ? go(n, b) : -1;
	}

	int ra = get(ll, rr, b, 2*n+2, (l+r)/2+1, r);
	if (ra != -1) return ra;
	return get(ll, rr, b, 2*n+1, l, (l+r)/2);
}

void erase(int i, int n = 0, int l = 0, int r = N-1){
	if (c[i] < l || r < c[i]) return;

	T[n].erase(i);

	if (l == r) return;

	erase(i, 2*n+1, l, (l+r)/2);
	erase(i, 2*n+2, (l+r)/2+1, r);
}


int main(){
	scanf("%d", &N);

	vector<int> v;

	for (int i = 0; i < N; i++){
		scanf("%d %d %d", &c[i], &u[i], &p[i]);
		v.push_back(i);
	}

	sort(v.begin(), v.end(),
		[=](int x, int y){ return pii(c[x],-u[x]) < pii(c[y],-u[y]); });

	copy(v.begin(), v.end(), c_);

	for (int i = 0; i < N; i++)
		c[v[i]] = i;

	sort(v.begin(), v.end(),
		[=](int x, int y){ return pii(u[x],-c[x]) < pii(u[y],-c[y]); });

	for (int i = 0; i < N; i++)
		u[v[i]] = i;

	build();

	priority_queue<int, vector<int>, pcmp> q;
	set<int, ccmp> s;

	for (int i = 0; i < N; i++)
		if (!any(c[i]+1, i)){
			q.push(i);
			s.insert(i);
		}

	c[N] = -1; u[N] = N;
	c[N+1] = N; u[N+1] = -1;
	s.insert(N); s.insert(N+1);

	for (int i = 1; i <= N; i++){
		int x = q.top(); q.pop();

		auto w = s.erase(s.find(x));

		erase(x);

		int left = c[*prev(w)]+1;
		int right = c[*w]-1;
		int bttm = *w;

		while (true){
			int curr = get(left, right, bttm);
			if (curr < 0) break;
			q.push(curr);
			s.insert(curr);
			right = c[curr]-1;
			bttm = curr;
		}

		printf("%d%c", x+1, i < N ? ' ' : '\n');
	}
}
