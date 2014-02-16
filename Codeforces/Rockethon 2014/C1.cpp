#include <cstdio>
#include <algorithm>

#define MAXN 30

using namespace std;

int n, k, best = 1<<30;
int p[MAXN], e[MAXN];
int epts[MAXN];

int main(){
	int i, j;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
		scanf("%d %d", &p[i], &e[i]);

	for (i = 0; i < (1<<n); i++){
		int eff = 0, pts = 0, rank = n+1;
		for (j = 0; j < n; j++)
			if (i & (1<<j)){
				eff += e[j];
				pts++;
				epts[j] = 0;
			} else {
				epts[j] = 1;
			}

		for (j = 0; j < n; j++)
			if (pts > p[j] + epts[j] || (pts == p[j] && (i & (1<<j))))
				rank--;

		if (rank <= k)
			best = min(best, eff);
	}

	printf("%d\n", best < (1<<30) ? best : -1);
}
