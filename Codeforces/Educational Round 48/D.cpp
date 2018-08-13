#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

const int maxn = 105, bits = 35;
int n, m;
ll a[maxn], b[maxn];
ll g[maxn][maxn];

bool go(ll mask){
	vector<int> r, c;

assert(r.empty());
assert(c.empty());

	for (int i = 0; i < n; i++)
		if (a[i] & mask)
			r.push_back(i);

	for (int i = 0; i < m; i++)
		if (b[i] & mask)
			c.push_back(i);

	if (r.size() % 2 != c.size() % 2)
		return false;

	while (!r.empty() && !c.empty()){
		g[r.back()][c.back()] ^= mask;
//cout << mask << ':' << r.back() << ',' << c.back() << '\n';
		r.pop_back();
		c.pop_back();
	}

	while (!r.empty()){
		int a = r.back(); r.pop_back();
		int b = r.back(); r.pop_back();
//cout << mask << ':' << a << ',' << 0 << '\n';
//cout << mask << ':' << b << ',' << 0 << '\n';
		g[a][0] ^= mask;
		g[b][0] ^= mask;
	}

	while (!c.empty()){
		int a = c.back(); c.pop_back();
		int b = c.back(); c.pop_back();
//cout << mask << ':' << 0 << ',' << a << '\n';
//cout << mask << ':' << 0 << ',' << b << '\n';
		g[0][a] ^= mask;
		g[0][b] ^= mask;
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int j = 0; j < m; j++)
		cin >> b[j];

	for (int i = 0; i < bits; i++)
		if (!go(1LL<<i)){
			cout << "NO\n";
			return 0;
		}

	cout << "YES\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cout << g[i][j] << (j < m-1 ? ' ' : '\n');
}

