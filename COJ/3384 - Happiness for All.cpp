#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1010

struct s {
	int n, r;
};

int p[MAXN];
s g[MAXN];
int v[MAXN];

int id(int x){
	if (p[x] == x)
		return x;
	return p[x] = id(p[x]);
}

void join(int a, int b){
	a = id(a);
	b = id(b);

	if (a != b){
		g[a].n += g[b].n;
		g[a].r += g[b].r;
		p[b] = a;
	}

	g[a].r++;
}

int N, M, R, E;

int main(){
	scanf("%d %d %d %d", &N, &M, &R, &E);

	for (int i = 1; i <= N; i++){
		p[i] = i;
		g[i] = {1, 0};
	}

	while (M--){
		int a, b;
		scanf("%d %d", &a, &b);
		join(a, b);
	}

	long long ans = 0;
	for (int i = 1; i <= N; i++){
		if (!v[id(i)]){
			int z = id(i);
			v[z] = true;
			ans += min(R * (((long long) g[z].n) * (g[z].n - 1) / 2 - g[z].r),
			           E * (long long) g[z].n);
		}
	}

	printf("%lld\n", ans);
}
