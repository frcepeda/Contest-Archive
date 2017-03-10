#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define MAXN 50100
#define MAXS 1000001

int N, R;
set<int> s[MAXS];
int t[MAXN];
int tree[4*MAXN];

void update(int n, int x, int v, int a, int b){
	if (x < a || b < x) return;
	if (a == b){
		tree[n] = v;
		return;
	}
	update(2*n+1, x, v, a, (a+b)/2);
	update(2*n+2, x, v, (a+b)/2+1, b);
	tree[n] = min(tree[2*n+1], tree[2*n+2]);
}

int query(int n, int i, int j, int a, int b){
	if (j < a || b < i) return 1<<30;
	if (i <= a && b <= j) return tree[n];

	return min(query(2*n+1, i, j, a, (a+b)/2),
	           query(2*n+2, i, j, (a+b)/2+1, b));
}

int main(){
	scanf("%d %d", &N, &R);

	for (int i = 1; i <= N; i++){
		int a;
		scanf("%d", &a);
		t[i] = a;
		s[a].insert(i);
	}

	for (int i = 1; i <= N; i++){
		auto z = s[t[i]].find(i);
		z++;
		int d = z == s[t[i]].end() ? N+1 : *z;
		update(0, i, d, 0, N);
	}

	while (R--){
		char tmp[10];
		int a, b;
		scanf("%s", tmp);
		if (tmp[0] == 'C'){
			scanf("%d %d", &a, &b);

			if (t[a] == b) continue;

			auto y = s[t[a]].find(a);
			if (y != s[t[a]].begin()){
				int d = next(y) == s[t[a]].end() ? N+1 : *next(y);
				update(0, *prev(y), d, 0, N);
			}
			s[t[a]].erase(y);

			auto z = s[b].insert(a).first;
			if (z != s[b].begin())
				update(0, *prev(z), a, 0, N);

			int d = next(z) == s[b].end() ? N+1 : *next(z);
			update(0, a, d, 0, N);
			t[a] = b;
		} else {
			scanf("%d", &a);
			int lo = 0, hi = a-1, mid;

			while (lo <= hi){
				mid = (lo + hi)/2;
				if (query(0, mid, a, 0, N) <= a)
					lo = mid + 1;
				else
					hi = mid - 1;
			}

			printf("%d\n", a - lo + 1);
		}
	}
}
