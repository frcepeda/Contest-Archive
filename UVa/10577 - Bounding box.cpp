#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

typedef pair<double,double> point;

#define sq(a) ((a)*(a))

bool collinear(point a, point b, point c){
	return (a.fst - b.fst)*(a.snd - c.snd) == (a.fst - c.fst)*(a.snd - b.snd);
}

pair<point, double> circumcircle(point a, point b, point c){
	if (collinear(a,b,c)) return mp(mp(0,0),-1);

	double A = 2 * (b.fst - a.fst);
	double B = 2 * (b.snd - a.snd);
	double C = sq(a.fst) + sq(a.snd) - sq(b.fst) - sq(b.snd);
	double D = 2 * (c.fst - a.fst);
	double E = 2 * (c.snd - a.snd);
	double F = sq(a.fst) + sq(a.snd) - sq(c.fst) - sq(c.snd);
	
	double x = (B*F - C*E)/(A*E - B*D);
	double y = (C*D - A*F)/(A*E - B*D);
	
	return mp(mp(x, y), sqrt(sq(a.fst - x) + sq(a.snd - y)));
}

int n;
point p[3];

int main() {
	for (int t = 1; scanf("%d", &n), n; t++){
		int i;
		double minx = 1e30, maxx = -1e30;
		double miny = 1e30, maxy = -1e30;
		
		for (i = 0; i < 3; i++)
			scanf("%lf %lf", &p[i].fst, &p[i].snd);
			
		auto circle = circumcircle(p[0], p[1], p[2]);
		double theta = 2*M_PI/n;
		double offset = atan2(circle.fst.snd - p[0].snd, circle.fst.fst - p[0].fst);
		
		for (i = 0; i < n; i++){
			double x = circle.fst.fst + circle.snd * cos(theta*i + offset);
			double y = circle.fst.snd + circle.snd * sin(theta*i + offset);
			minx = min(minx, x);
			maxx = max(maxx, x);
			miny = min(miny, y);
			maxy = max(maxy, y);
		}
			
		printf("Polygon %d: %.3lf\n", t, (maxx - minx) * (maxy - miny));
	}
}