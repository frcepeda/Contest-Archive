#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 200010;
int N, Q;
int a[maxn], b[maxn], tree[4*maxn], p[4*maxn];
int L[maxn], R[maxn];

void push(int n, bool leaf){
	if (!p[n]) return;
	tree[n] = p[n];
	if (!leaf){
		p[2*n+1] = p[n];
		p[2*n+2] = p[n];
	}
	p[n] = 0;
}

void update(int x, int y, int v, int n = 0, int l = 0, int r = N-1){
	push(n, l == r);

	if (y < l || r < x) return;

	if (x <= l && r <= y){
		p[n] = v;
		push(n, l == r);
		return;
	}

	update(x, y, v, 2*n+1, l, (l+r)/2);
	update(x, y, v, 2*n+2, (l+r)/2+1, r);
}

void dump(int n = 0, int l = 0, int r = N-1){
	push(n, l == r);
	if (l == r){
		b[l] = tree[n];
		return;
	}
	dump(2*n+1, l, (l+r)/2);
	dump(2*n+2, (l+r)/2+1, r);
}

bool works(){
	update(0, N-1, 1);

	for (int i = 1; i <= Q; i++)
		if (L[i] != N)
			update(L[i], R[i], i);

	dump();

	if (L[Q] == N){
		auto x = find(a, a+N, 0);
		if (x == a+N) return false;
		b[x - a] = Q;
	}

	for (int i = 0; i < N; i++)
		if (a[i] && a[i] != b[i])
			return false;

	return true;
}

int main(){
	scanf("%d %d", &N, &Q);

	fill(L+1, L+1+Q, N);

	for (int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		L[a[i]] = min(L[a[i]], i);
		R[a[i]] = max(R[a[i]], i);
	}

	if (works()){
		printf("YES\n");
		for (int i = 0; i < N; i++)
			printf("%d%c", b[i], i != N-1 ? ' ' : '\n');
	} else printf("NO\n");
}
