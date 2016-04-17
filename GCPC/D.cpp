#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 105
#define fst first
#define snd second

int t, n;
pair<int,int> p[MAXN];
int v[MAXN];

bool dfs(int x){
	if (x == n+1) return true;
	else if (v[x] == t) return false;
	v[x] = t;

	for (int i = 0; i <= n+1; i++)
		if (abs(p[x].fst - p[i].fst) + abs(p[x].snd - p[i].snd) <= 1000 && dfs(i))
			return true;

	return false;
}

int main(){
	int T;
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d", &n);

		for (int i = 0; i <= n+1; i++)
			scanf("%d %d", &p[i].fst, &p[i].snd);

		printf("%s\n", dfs(0) ? "happy" : "sad");
	}
}
