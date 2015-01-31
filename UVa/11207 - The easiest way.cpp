// Accepted
// The squares can be arranged on a single line or on a 2x2 grid.

#include <cstdio>
#include <algorithm>

using namespace std;

#define fst first
#define snd second

int N;

double f(pair<double,double> s){
	return max(min(s.fst, s.snd)/2, min(s.fst/4, s.snd));
}

int main() {
	while (scanf("%d", &N), N){
		int i;
		pair<double,double> s, t, b {0,0}, c;
		for (i = 1; i <= N; i++){
			scanf("%lf %lf", &s.fst, &s.snd);
			t.fst = s.snd; t.snd = s.fst;
			c = make_pair(max(f(s), f(t)), i);
			if (c.fst > b.fst)
				b = c;
		}
		printf("%.0lf\n", b.snd);
	}
}