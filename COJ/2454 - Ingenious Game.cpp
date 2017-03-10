#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#define mp make_pair
#define fst first
#define snd second
#define EPS (1e-10)

typedef int ll;

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT(const PT &p) : x(p.x), y(p.y) {}
	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
	PT operator * (const double &c) const { return PT(x*c, y*c); }
	PT operator / (const double &c) const { return PT(x/c, y/c); }
	bool operator < (const PT &p) const { return mp(y,x) < mp(p.y,p.x); }
	bool operator == (const PT &p) const { return mp(y,x) == mp(p.y,p.x); }
};

double dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
double cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }
double dist2(PT p, PT q) { return dot(p-q, p-q); }
double area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

bool LinesParallel(PT a, PT b, PT c, PT d){
	return fabs(cross(b - a, c - d)) < EPS;
}

bool LinesCollinear(PT a, PT b, PT c, PT d){
	return LinesParallel(a, b, c, d) &&
	       fabs(cross(a-b, a-c)) < EPS &&
	       fabs(cross(c-d, c-a)) < EPS;
}

PT LineLineI(PT a, PT b, PT c, PT d){
	b = b - a;
	d = c - d;
	c = c - a;
	return a + b * cross(c, d) / cross(b, d);
}

typedef pair<PT, double> circle;

PT RotateCCW90(PT p) { return PT(-p.y,p.x); }

void CircleCircleIntersection(PT a, PT b, double r, double R, vector<PT> &ret){
	double d = sqrt(dist2(a,b));
	if (d > r+R || d+min(r, R) < max(r, R)) return;
	double x = (d*d-R*R+r*r)/(2*d);
	double y = sqrt(r*r-x*x);
	PT v = (b-a)/d;
	ret.push_back(a+v*x + RotateCCW90(v)*y);
	if (y > 0)
		ret.push_back(a+v*x - RotateCCW90(v)*y);
}

#define MAXN 100110

int N, T;
PT P[MAXN], Q[MAXN];
vector<PT> CH;

void convexHull(){
	sort(Q, Q + N);
	vector<PT> up, dn;
	for (int i = 0; i < N; i++){
		while (up.size() > 1 && area2(up[up.size()-2], up.back(), Q[i]) >= 0) up.pop_back();
		while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), Q[i]) <= 0) dn.pop_back();
		up.push_back(Q[i]);
		dn.push_back(Q[i]);
	}
	CH = up;
	for (auto w: dn) CH.push_back(w);
}

bool SegmentsIntersect(PT a, PT b, PT c, PT d){
	if (LinesCollinear(a, b, c, d)){
		if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
		if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0) return false;
		return true;
	}
	if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
	if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
	return true;
}

bool works(){
	for (int i = 0; i < 4; i++)
		if (find(CH.begin(), CH.end(), P[i]) == CH.end())
			return false;

	return SegmentsIntersect(P[0], P[1], P[2], P[3]);
}

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);

		for (int i = 0; i < N; i++){
			scanf("%lf %lf", &P[i].x, &P[i].y);
			Q[i] = P[i];
		}

		convexHull();

		printf("%s\n", !works() ? "POSSIBLE" : "IMPOSSIBLE");
	}
}
