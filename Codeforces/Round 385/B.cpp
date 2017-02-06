#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int ans[1010];
bool u[1010];
vector<int> v, w;

void go(vector<int> &v){
	fill(u, u + 1010, false);

	printf("%d\n", (int)v.size());
	for (int j = 0; j < v.size(); j++){
		printf("%d%c", v[j], j < v.size()-1 ? ' ' : '\n');
		u[v[j]-1] = true;
	}
	fflush(stdout);

	for (int i = 0; i < n; i++){
		int t;
		scanf("%d", &t);
		if (!u[i]) ans[i] = min(ans[i], t);
	}
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		ans[i] = 1000000001;

	for (int k = 0; (1<<k) < n; k++){
		v.clear();
		w.clear();

		for (int i = 0; i < n; i++)
			if (i / (1<<k) % 2)
				v.push_back(i+1);
			else
				w.push_back(i+1);

		go(v);
		go(w);
	}

	printf("-1\n");
	for (int i = 0; i < n; i++)
		printf("%d%c", ans[i], i < n-1 ? ' ' : '\n');
	fflush(stdout);
}
