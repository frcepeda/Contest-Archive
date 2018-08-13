#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 3010;
int n, m, p[maxn], cnt[maxn];
vector<int> c[maxn];

ll go(int x){
	ll cost = 0;

	static vector<int> v;
	v.clear();

	int votes = cnt[1];
	for (int i = 2; i <= m; i++){
		int extra = max(int(c[i].size()) - (x-1), 0);
		for (int j = 0; j < extra; j++)
			cost += c[i][j];
		for (int j = extra; j < c[i].size(); j++)
			v.push_back(c[i][j]);
		votes += extra;
	}

	sort(v.begin(), v.end());
	for (int i = 0; votes + i < x; i++)
		cost += v[i];

	return cost;
}

int main(){
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		c[x].push_back(y);
	}

	for (int i = 1; i <= m; i++){
		sort(c[i].begin(), c[i].end());
		cnt[i] = c[i].size();
	}

	ll ans = 1LL<<60;

	for (int i = 1; i <= n; i++)
		ans = min(ans, go(i));

	cout << ans << endl;
}
