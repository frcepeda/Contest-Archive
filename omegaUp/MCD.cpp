#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXLG 18
#define MAXN 400010

int N;
int st[MAXLG][MAXN];

int query(int a, int b){
	int l;
	for (l = 0; (1<<l) < b - a + 1; l++);
	l = max(l-1, 0);
	return __gcd(st[l][a], st[l][b - (1<<l) + 1]);
}

int main(){
	int i, j, ans = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d", &st[0][i]);
		st[0][i+N] = st[0][i];
	}
	
	N *= 2;

	for (j = 1; j < MAXLG; j++)
		for (i = 0; i < N; i++)
			st[j][i] = __gcd(st[j-1][i], st[j-1][min(N-1, i + (1<<(j-1)))]);

	for (i = 0; i < N/2; i++){
		int lo = i, hi = N, mid;
		while (lo < hi){
			mid = (lo + hi) / 2;
			if (query(i, mid) == 1)
				hi = mid;
			else
				lo = mid + 1;
		}
		ans = max(ans, hi - i);
	}

	printf("%d\n", ans <= N/2 ? ans : -1);
}
