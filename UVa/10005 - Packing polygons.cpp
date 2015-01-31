#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 102
#define fst first
#define snd second
#define sq(x) ((x)*(x))

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

int N;
double R;
pll p[MAXN];

bool circle2PtsRad(pll p1, pll p2, double r, pdd &c) {
	double d2 = (p1.fst - p2.fst) * (p1.fst - p2.fst) + (p1.snd - p2.snd) * (p1.snd - p2.snd);
	double det = r * r / d2 - 0.25;
	if (det < 0.0) return false;
	double h = sqrt(det);
	c.fst = (p1.fst + p2.fst) * 0.5 + (p1.snd - p2.snd) * h;
	c.snd = (p1.snd + p2.snd) * 0.5 + (p2.fst - p1.fst) * h;
	return true;
}

bool allIn(pdd &c){
	for (int i = 0; i < N; i++)
		if (sq(c.fst - p[i].fst) + sq(c.snd - p[i].snd) > sq(R))
			return false;
	return true;
}

int main() {
	while (scanf("%d", &N), N){
		int i, j;
		pdd c;
		bool possible = false;
		
		for (i = 0; i < N; i++)
			scanf("%lld %lld", &p[i].fst, &p[i].snd);
			
		scanf("%lf", &R);
		
		for (i = 0; i < N; i++)
			for (j = i+1; j < N; j++)
				if ((circle2PtsRad(p[i], p[j], R, c) && allIn(c)) ||
				    (circle2PtsRad(p[j], p[i], R, c) && allIn(c))){
				    	possible = true;
				    	goto done;
				    }
		
		done:
		if (possible)
			printf("The polygon can be packed in the circle.\n");
		else
			printf("There is no way of packing that polygon.\n");
	}
}