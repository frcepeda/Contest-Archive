#include <cstdio>
#include <tuple>
#include <algorithm>

using namespace std;

typedef double dd;

struct PT {
	dd x, y;
	PT() {}
	PT(dd x, dd y) : x(x), y(y) {}
	PT operator + (const PT &a) const { return PT(x+a.x, y+a.y); }
	PT operator - (const PT &a) const { return PT(x-a.x, y-a.y); }
	PT operator * (dd z) const { return PT(x*z, y*z); }
	PT operator / (dd z) const { return PT(x/z, y/z); }
};

double cross(const PT &a, const PT &b) { return a.x*b.y - a.y*b.x; }
double dot(const PT &a, const PT &b) { return a.x*b.x + a.y*b.y; }
double norm(const PT &a) { return dot(a,a); }
double dist2(const PT &a, const PT &b) { return norm(a-b); }
double dist(const PT &a, const PT &b) { return sqrt(dist2(a,b)); }

PT rotate90(const PT &x){
	return PT(-x.y, x.x);
}

PT rotate(const PT &x, double a){
	return PT(cos(a) * x.x - sin(a) * x.y,
	          sin(a) * x.x + cos(a) * x.y);
}

const int maxn = 1010;
int n;
PT p[maxn];

bool works(double D){
	for (int i = 0; i < n; i++){
		PT a = p[i], b = p[i+1], c = p[i+2];

		PT ac = c - a;
		ac = ac / norm(ac);
		PT ab = b - a;
		ab = ab / norm(ab);

		PT v = rotate90(ac);

		a = a + v * D;
		c = c + v * D;
		b = b - v * D;

		if (cross(b - a, c - a) >= 0)
			return false;
	}

	return true;
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &p[i].x, &p[i].y);

	p[n] = p[0]; p[n+1] = p[1];

	double lo = 0, hi = 1e60, mid;

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			hi = min(hi, dist(p[i], p[j])/2);

	printf("%d\n", works(.4));

	for (int i = 0; i < 200; i++){
		mid = (lo+hi)/2;
		if (works(mid))
			lo = mid;
		else
			hi = mid;
	}

	printf("%.8lf\n", mid);
}
