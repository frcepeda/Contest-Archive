#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 101

int A[MAXN][MAXN];
map<int,int> m;
int N;

int g(int x){
	if (m[x] == 0) m[x] = ++N;
	return m[x];
}

int main() {
	int t = 0;
	
	while (++t){
		int a, b, i, j, k, ans = 0;
		
		N = 0;
		m.clear();
		
		for (i = 0; i < MAXN; i++)
			for (j = 0; j < MAXN; j++)
				A[i][j] = 0;
		
		while (scanf("%d %d", &a, &b), (a || b))
			A[g(a)][g(b)]++;
		
		if (N == 0) break;
			
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				if (A[i][j] == 0)
					A[i][j] = 1<<25;
		
		for (k = 1; k <= N; k++)
			for (i = 1; i <= N; i++)
				for (j = 1; j <= N; j++)
					A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
		
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				if (i != j)
					ans += A[i][j];
		
		printf("Case %d: average length between pages = %.03lf clicks\n", t, (double)ans/N/(N-1));
	}
}