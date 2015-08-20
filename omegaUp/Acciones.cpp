#include <cstdio>
#include <algorithm>
#include <climits>

#define fst first
#define snd second
#define mp make_pair

using namespace std;

#define MAXN 32
#define MAXM (1<<(MAXN/2))

int n, m, P[MAXN];
pair<int, long long> A[MAXM], B[MAXM];

int main(){
	int i, j;

	scanf("%d", &n);
	m = 1<<(n/2);

	for (i = 0; i < n; i++)
		scanf("%d", &P[i]);

	for (i = 0; i < m; i++){
		A[i].fst = B[i].fst = __builtin_popcount(i);
		for (j = 0; j < n/2; j++){
			A[i].snd += P[j] * ((i & (1<<j)) ? 1 : -1);
			B[i].snd += P[j+n/2] * ((i & (1<<j)) ? 1 : -1);
		}
	}

	sort(A, A + m);
	sort(B, B + m);

	long long ans = LONG_LONG_MAX;

	for (i = 0; i < m; i++){
		int t = n/2 - A[i].fst;

		auto right = lower_bound(B, B + m, mp(t, -A[i].snd));
		if (right != B + m && right->fst == t)
			ans = min(ans, llabs(A[i].snd + right->snd));

		auto left = right - 1;
		if (left >= B && left->fst == t)
			ans = min(ans, llabs(A[i].snd + left->snd));
	}

	printf("%lld\n", ans);
}
