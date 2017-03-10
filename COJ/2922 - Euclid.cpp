#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT operator + (const PT &a) const { return PT(x+a.x,y+a.y); }
	PT operator - (const PT &a) const { return PT(x-a.x,y-a.y); }
	PT operator * (const double &c) const { return PT(x*c,y*c); }
	PT operator / (const double &c) const { return PT(x/c,y/c); }
};

double dot(const PT &a, const PT &b){ return a.x*b.x + a.y*b.y; }
double cross(const PT &a, const PT &b){ return a.x*b.y - a.y*b.x; }
double norm(const PT &a){ return hypot(a.x, a.y); }

PT get(){
	PT w;
	scanf("%lf %lf", &w.x, &w.y);
	return w;
}

int main(){
	while (true){
		PT A = get();
		PT B = get();
		PT C = get();
		PT D = get();
		PT E = get();
		PT F = get();

		vector<PT> pts = {A,B,C,D,E,F};
		if (all_of(pts.begin(), pts.end(),
			[](PT &a){ return a.x == 0 && a.y == 0; }))
			break;

		PT v = B - A;
		PT w = C - A;

		double nv = norm(v);
		double nw = norm(w);
		double alpha = acos(dot(v,w)/(nv*nw));
		double target = fabs(cross(E-D, F-D)/2);

		double nn = target / (sin(alpha) * nv);

		PT H = A + (w * nn / nw);
		PT G = B + (w * nn / nw);

		printf("%.3lf %.3lf %.3lf %.3lf\n", G.x, G.y, H.x, H.y);
	}
}
