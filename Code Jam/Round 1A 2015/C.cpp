#include <cstdio>
#include <algorithm>

using namespace std;

#define fst first
#define snd second

typedef pair<long long,long long> pii;

int T, N, cnt[1<<16];
pii p[20], q[20], hull[20];

long long ccw(pii &p1, pii &p2, pii &p3){
	  return (p2.fst - p1.fst)*(p3.snd - p1.snd) - (p2.snd - p1.snd)*(p3.fst - p1.fst);
}

bool works(int x, int b, int c){
	int i, j;

	for (i = j = 0; i < N; i++)
		if (b & (1<<i))
			q[j++] = p[i];

	sort(q, q + c);

	int t, k = 0;

	// taken from http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#C

	for (i = 0; i < c; ++i) {
		while (k >= 2 && ccw(hull[k-2], hull[k-1], q[i]) < 0) --k;
		hull[k++] = q[i];
	}
	       
	for (i = c-2, t = k+1; i >= 0; --i) {
		while (k >= t && ccw(hull[k-2], hull[k-1], q[i]) < 0) --k;
		hull[k++] = q[i];
	}

	for (i = 0; i < k; i++)
		if (hull[i] == p[x])
			return true;

	return false;
}

int solve(int x){
	int m = 0;

	for (int b = 0; b < (1<<N); b++)
		if (works(x, b, cnt[b]))
			m = max(m, cnt[b]);

	return N - m;
}

int main(){
	for (int i = 1; i < (1<<16); i++)
		cnt[i] = 1 + cnt[i^(i&-i)];

	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
			scanf("%lld %lld", &p[i].fst, &p[i].snd);

		printf("Case #%d:\n", t);
		for (int i = 0; i < N; i++)
			printf("%d\n", solve(i));
	}
}
