// Accepted
// For every segment, the distance function to M is unimodal.
// Binary search for the best point for each segment and take the global minimum.

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<double,double> pii;

pii M, a, b;
int N;

#define mp make_pair
#define fst first
#define snd second
#define EPS 1e-8
#define dist(a,b) hypot(a.fst - b.fst, a.snd - b.snd)

pii p(double d){
	return mp(d*a.fst + (1-d)*b.fst, d*a.snd + (1-d)*b.snd);
}

pair<double, pii> minimize(){
	double lo = 0, hi = 1, mid;
	
	for (int i = 0; i < 100; i++){
		mid = (lo + hi) / 2;
		if (dist(M, p(mid)) > dist(M, p(mid + EPS)))
			lo = mid;
		else
			hi = mid;
	}
	
	return mp(dist(M, p(mid)), p(mid));
}

int main() {
	while (scanf("%lf %lf", &M.fst, &M.snd) == 2){
		scanf("%d", &N);
		scanf("%lf %lf", &a.fst, &a.snd);
		
		pair<double, pii> ans = mp(1e40, mp(0,0));
		
		while (N--){
			b = a;
			scanf("%lf %lf", &a.fst, &a.snd);
			ans = min(ans, minimize());
		}
		
		printf("%.04lf\n%.04lf\n", ans.snd.fst, ans.snd.snd);
	}
}