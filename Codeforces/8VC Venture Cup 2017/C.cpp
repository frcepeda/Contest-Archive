#include <cstdio>
#include <algorithm>

int n;

const int maxn = 10010;
int p[maxn], ans;

int id(int x){
	if (x == p[x]) return x;
	return p[x] = id(p[x]);
}

void join(int a, int b){
	a = id(a);
	b = id(b);
	if (a == b) return;
	ans--;
	p[a] = b;
}

int main(){
	scanf("%d", &n);

	ans = n;
	for (int i = 1; i <= n; i++)
		p[i] = i;

	for (int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);
		join(i, a);
	}

	printf("%d\n", ans);
}
