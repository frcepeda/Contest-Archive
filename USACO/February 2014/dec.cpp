#include <cstdio>
#include <algorithm>

using namespace std;

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("dec.in", "r", stdin); freopen("dec.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define _maxN 20
#define _maxB (1<<_maxN)

struct bonus_s {
	int k, p, a;

	bool operator < (const bonus_s &b) const {
		return p < b.p;
	}
};

int N, B;

int s[_maxN][_maxN];
bonus_s bonus[_maxN];

int dp[_maxB];
char bCount[_maxB];

int main(void){
	int i, j;

	openFiles();

	scanf("%d %d", &N, &B);

	for (i = 0; i < B; i++){
		scanf("%d %d %d", &bonus[i].k, &bonus[i].p, &bonus[i].a);
		bonus[i].k = min(bonus[i].k, N);
	}

	sort(bonus, bonus + B);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &s[i][j]);

	for (i = 1; i < (1<<N); i++){
		bCount[i] = bCount[i ^ (i&-i)] + 1;

		for (j = 0; (1<<j) <= i; j++)
			if (i & (1<<j))
				dp[i] = _max(dp[i], dp[i^(1<<j)] + s[j][bCount[i]-1]);

		for (j = 0; j < B; j++)
			if (bonus[j].k == bCount[i] && dp[i] >= bonus[j].p)
				dp[i] += bonus[j].a;
	}

	printf("%d\n", dp[(1<<N) - 1]);
}
