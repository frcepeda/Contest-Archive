#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200100;
int n, p[maxn], v[maxn];

void dfs(int x){
	if (v[x]) return;
	v[x] = true;
	dfs(p[x]);
}

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);

	int ans = 0;
	for (int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		ans = (ans + x) % 2;
	}

	ans = (ans + 1) % 2;

	int k = 0;
	for (int i = 1; i <= n; i++)
		if (!v[i]){
			dfs(i);
			k++;
		}

	printf("%d\n", ans + (k == 1 ? 0 : k));
}
