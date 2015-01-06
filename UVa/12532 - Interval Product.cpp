#include <cstdio>
#include <cctype>

using namespace std;

#define MAXN 100100

short tree[MAXN*4];
short A[MAXN];
int N, K;

void treeInit(int n, int l, int r){
	if (l == r){
		tree[n] = A[l];
		return;
	}
	
	treeInit(2*n+1, l, (l+r)/2);
	treeInit(2*n+2, (l+r)/2+1, r);
	
	tree[n] = tree[2*n+1] * tree[2*n+2];
}

short query(int n, int l, int r, int i, int j){
	if (i > r || j < l) return 1;
	if (i <= l && r <= j) return tree[n];
	return query(2*n+1, l, (l+r)/2, i, j) * query(2*n+2, (l+r)/2+1, r, i, j);
}

void update(int n, int l, int r, int i, int v){
	if (i < l || i > r) return;
	
	if (l == r){
		tree[n] = v;
		return;
	}
	
	update(2*n+1, l, (l+r)/2, i, v);
	update(2*n+2, (l+r)/2+1, r, i, v);
	
	tree[n] = tree[2*n+1] * tree[2*n+2];
}

int main() {
	while (scanf("%d %d", &N, &K) == 2){
		int I, V;
		char c;
		
		for (int i = 1; i <= N; i++){
			scanf("%d", &V);
			A[i] = V < 0 ? -1 : V > 0 ? 1 : 0;
		}
		
		treeInit(0, 1, N);
		
		while (K--){
			do {
				c = getchar();
			} while (c != 'C' && c != 'P');
			
			scanf("%d %d", &I, &V);
			
			if (c == 'C'){
				update(0, 1, N, I, V < 0 ? -1 : V > 0 ? 1 : 0);
			} else {
				short x = query(0, 1, N, I, V);
				putchar(x < 0 ? '-' : x > 0 ? '+' : '0');
			}
		}
		
		putchar('\n');
	}
}