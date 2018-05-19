#include <cstdio>
#include <cmath>
#include <algorithm>

#define fst first
#define snd second

using namespace std;

int N;

typedef pair<double, double> pdd;

typedef long double ld;

const ld PI = acos(-1);

ld toRad(ld x){
	return x * PI / 180;
}

pdd read_latlong(){
	double a, b;
	char c;

	scanf("%lf%c%*c", &a, &c);

	if (c == 'S') a = -a;

	scanf("%lf%c", &b, &c);

	if (c == 'W') b = -b;

	return make_pair(a, b);
}

long double dist(pdd a, pdd b){
	ld p1 = toRad(a.fst);
	ld p2 = toRad(b.fst);
	ld dp = toRad(b.fst - a.fst);
	ld dl = toRad(b.snd - a.snd);

	ld aa = sin(dp/2) * sin(dp/2) + cos(p1) * cos(p2) * sin(dl/2) * sin(dl/2);
	ld c = 2 * atan2(sqrt(aa), sqrt(1-aa));

	ld d = 6400 * c;

	//fprintf(stderr, "%Lf\n", d);

	return d;
}

int main(){
	scanf("%d", &N);

	pdd p, n;

	p = read_latlong();

	long double d = 0;

	for (int i = 1; i < N; i++){
		n = read_latlong();
		d += dist(p, n);
		p = n;
	}

	printf("%.0Lf\n", d);
}
