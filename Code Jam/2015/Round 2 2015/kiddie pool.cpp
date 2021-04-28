#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>

#define MAXN 105
#define EPS (1e-14L)
#define mp make_pair
#define fst first
#define snd second

using namespace std;

typedef pair<long double,long double> pdd;

int T, N;
long double V, X, C[MAXN], R[MAXN];
vector<pdd> l, g;

bool works(long double t){
	long double rem = V;

	l.clear();
	g.clear();

	for (int i = 0; i < N; i++){
		if (C[i] < X){
			l.push_back(mp(C[i]-X, R[i]*t));
		} else if (C[i] > X) {
			g.push_back(mp(C[i]-X, R[i]*t));
		} else {
			rem -= R[i] * t;
		}
	}

	while (rem >= EPS && !l.empty() && !g.empty()){
		pdd a = *l.rbegin(); l.pop_back();
		pdd b = *g.rbegin(); g.pop_back();

		if (a.snd <= -b.fst * b.snd / a.fst){
			rem -= a.snd;
			long double z = -a.fst * a.snd / b.fst;
			rem -= z;
			if (b.snd - z >= EPS)
				g.push_back(mp(b.fst, b.snd - z));
		} else {
			rem -= b.snd;
			long double z = -b.fst * b.snd / a.fst;
			rem -= z;
			if (a.snd - z >= EPS)
				l.push_back(mp(a.fst, a.snd - z));
		}
	}

	return rem < EPS;
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d %Lf %Lf", &N, &V, &X);

		long double mc = 20000, Mc = 0;
		for (int i = 0; i < N; i++){
			scanf("%Lf %Lf", &R[i], &C[i]);
			mc = min(mc, C[i]);
			Mc = max(Mc, C[i]);
		}

		printf("Case #%d: ", t);

		if (X < mc || X > Mc){
			printf("IMPOSSIBLE\n");
			continue;
		}

		long double lo = 0, hi = 2e6, mid;
		while (abs(hi - lo) > 1e-7){
			mid = (lo + hi)/2;
			if (works(mid))
				hi = mid;
			else
				lo = mid;
		}

		printf("%.8Lf\n", (lo + hi)/2);
		fflush(stdout);
	}
}
