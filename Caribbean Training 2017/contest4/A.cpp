#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int n, m;
bool l[maxn], r[maxn];

int main(){
	scanf("%d %d", &n, &m);

	vector<pair<int,int>> v;

	for (int i = 1; i <= n; i++){
		int j;
		while (scanf("%d", &j), j){
			if (l[i] || r[j]) continue;
			l[i] = r[j] = true;
			v.push_back(make_pair(i, j));
		}
	}

	printf("%lu\n", v.size());

	for (auto w: v)
		printf("%d %d\n", w.first, w.second);
}
