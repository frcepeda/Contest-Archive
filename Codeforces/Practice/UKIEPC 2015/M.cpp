#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define MAXM 1010

#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int N, M;
long long m[MAXM], n[MAXM];
long long x[MAXM], y[MAXM];

set<long long> ans;

int main(){
	int i, j;

	scanf("%d %d", &M, &N);

	for (i = 0; i < M; i++)
		scanf(LLD, &m[i]);
	for (i = 0; i < N; i++)
		scanf(LLD, &n[i]);

	adjacent_difference(m, m + M, x);
	adjacent_difference(n, n + N, y);

	for (j = 1; j+M-1 <= N; j++){
		for (i = 2; i < M; i++)
			//if (((__int128)x[1]) * y[j+i-1] != ((__int128)x[i]) * y[j])
			if (x[1] * y[j+i-1] != x[i] * y[j])
				break;

		if (i >= M){
			//printf("* %d\n", j);
			ans.insert(y[j]);
		}
	}

	printf("%lu\n", ans.size());
	int r = ans.size();
	for (auto &w : ans)
		printf(LLD"%c", w, --r ? ' ' : '\n');
}
