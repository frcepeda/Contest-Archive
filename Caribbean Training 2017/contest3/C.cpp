#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long double FT;

const FT EPS = 1e-12;

struct PT {
	FT x, y;
	PT() {}
	PT(FT x, FT y) : x(x), y(y) {}
	PT(const PT &p) : x(p.x), y(p.y) {}
	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
	PT operator * (FT c)    const { return PT(c*x, c*y); }
	PT operator / (FT c)    const { return PT(x/c, y/c); }
};

FT dot(const PT p, const PT q) { return p.x*q.x + p.y*q.y; }
FT dist2(const PT p, const PT q) { return dot(p-q,p-q); }
FT cross(const PT p, const PT q) { return p.x*q.y - p.y*q.x; }
FT norm2(const PT p) { return dot(p,p); }
PT RotateCCW90(PT p) { return PT(-p.y,p.x); }

bool PtInSegment(PT p, PT a, PT b){
	return min(a.x,b.x) <= p.x + EPS && p.x - EPS <= max(a.x,b.x) &&
	       min(a.y,b.y) <= p.y + EPS && p.y - EPS <= max(a.y,b.y);
}

vector<PT> CircleLineIntersection(PT a, PT b, PT c, FT r){
	vector<PT> ret;
	PT aa = a, bb = b;
	b = b-a;
	a = a-c;
	FT A = dot(b, b);
	FT B = dot(a, b);
	FT C = dot(a, a) - r*r;
	FT D = B*B - A*C;
	if (D < -EPS) return ret;
	ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
	if (!PtInSegment(ret.back(), aa, bb))
		ret.pop_back();
	if (D > EPS){
		ret.push_back(c+a+b*(-B-sqrt(D))/A);
		if (!PtInSegment(ret.back(), aa, bb))
			ret.pop_back();
	}
	return ret;
}

FT CircularSegment(PT a, PT b, PT c, FT r){
	a = a-c; b = b-c;
	FT th = acos(dot(a,b)/sqrt(norm2(a)*norm2(b)));
	return r * th;
}

vector<PT> CircleCircleIntersection(PT a, PT b, FT r, FT R){
	vector<PT> ret;
	FT d = sqrt(dist2(a,b));

	if (d > r+R || d+min(r, R) < max(r, R)) return ret;
	FT x = (d*d-R*R+r*r)/(2*d);
	FT y = sqrt(r*r-x*x);
	PT v = (b-a)/d;
	ret.push_back(a+v*x + RotateCCW90(v)*y);
	if (y > 0)
		ret.push_back(a+v*x - RotateCCW90(v)*y);

	return ret;
}

vector<PT> TangentPoint(PT p, PT c, FT r){
	FT pc = sqrt(dist2(p, c));
	FT d = sqrt(pc*pc - r*r);
	return CircleCircleIntersection(p, c, d, r);
}

int main(){
	PT w, h, c; FT r;

	scanf("%Lf %Lf %Lf %Lf", &w.x, &w.y, &h.x, &h.y);
	scanf("%Lf %Lf %Lf", &c.x, &c.y, &r);

	auto P = CircleLineIntersection(w, h, c, r);

	FT ans = 1e100;
	if (P.size() <= 1){
		ans = sqrt(dist2(w, h));
	} else {
		vector<PT> tw = TangentPoint(w, c, r);
		vector<PT> th = TangentPoint(h, c, r);

		for (auto L: tw)
			for (auto R: th)
				ans = min(ans,
					sqrt(dist2(w, L)) +
					sqrt(dist2(h, R)) +
					CircularSegment(L, R, c, r)
				);

	}

	printf("%.8Lf\n", ans);
}
