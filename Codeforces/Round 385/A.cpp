#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1010;
int n, m, k, total;
int g[maxn], p[maxn], sz[maxn];
vector<int> v;

int id(int x){
	if (p[x] == x) return x;
	return p[x] = id(p[x]);
}

void join(int u, int v){
	if (id(u) == id(v)) return;
	sz[id(u)] += sz[id(v)];
	p[id(v)] = id(u);
}

int main(){
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}

	for (int i = 0; i < k; i++)
		cin >> g[i];

	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		join(u, v);
	}

	int soFar = 0;
	for (int i = 0; i < k; i++){
		soFar += sz[id(g[i])];
		v.push_back(sz[id(g[i])]);
	}
	sort(v.begin(), v.end());
	*v.rbegin() += n - soFar;

	for (auto z: v)
		total += z * (z-1) / 2;

	cout << total - m << endl;
}
