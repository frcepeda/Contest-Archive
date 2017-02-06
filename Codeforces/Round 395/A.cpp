#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int n, k;
int c[maxn], d[maxn];
vector<int> adj[maxn];

int main(){
	scanf("%d", &n);

	for (int i = 1; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);

	for (int i = 1; i <= n; i++)
		for (auto z: adj[i])
			d[i] += c[z] != c[i];

	for (int i = 1; i <= n; i++)
		if (d[i])
			k++;

	for (int i = 1; i <= n; i++){
		int q = 0;

		bool ded = false;
		for (auto z: adj[i]){
			if (c[z] != c[i] && d[z] == 1)
				q++;
			else if (d[z]){
				ded = true;
				break;
			}
		}

		if (ded) continue;

		if (q == k - !!d[i]){
			printf("YES\n%d\n", i);
			return 0;
		}
	}

	printf("NO\n");
}
