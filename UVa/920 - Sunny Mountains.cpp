// Accepted
// Sweep from right to left, remembering the last (highest) y the sun hit.

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define mp make_pair
#define fst first
#define snd second
#define MAXN 110

typedef pair<int, int> pii;

int C, N;
pii p[MAXN];

int main() {
	scanf("%d", &C);
	
	while (C--){
		int i;
		
		scanf("%d", &N);
		
		for (int i = 0; i < N; i++)
			scanf("%d %d", &p[i].fst, &p[i].snd);
		
		sort(p, p + N);
		
		double last = 0, ans = 0;
		
		for (i = N-2; i >= 0; i--){
			if (p[i].snd <= p[i+1].snd || p[i].snd <= last) continue;
			double m = (double)(p[i+1].snd - p[i].snd) / (p[i+1].fst - p[i].fst);
			double b = p[i].snd;
			// y = mx + b
			double x = (last - b) / m;
			double l = hypot(p[i].snd - last, x);
			ans += l;
			last = max(last, (double)p[i].snd);
		}
		
		printf("%.02lf\n", ans);
	}
}