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
};

double dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
double cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }
double dist2(PT p, PT q) { return dot(p-q, p-q); }

bool linesParallel(PT a, PT b, PT c, PT d){
	return cross(b - a, c - d) < EPS;
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

#define MAXN 1010

int N;
circle C[MAXN];
vector<PT> toTest;

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int x, y, r;
		scanf("%d %d %d", &x, &y, &r);
		C[i].fst.x = x;
		C[i].fst.y = y;
		C[i].snd = r;

		toTest.push_back(C[i].fst);
	}

	for (int i = 0; i < N; i++)
		for (int j = i+1; j < N; j++)
			CircleCircleIntersection(C[i].fst, C[j].fst, C[i].snd, C[j].snd, toTest);

	int ans = 0;
	for (auto z: toTest){
		int w = 0;
		for (int i = 0; i < N; i++)
			if (dist2(C[i].fst, z) <= C[i].snd * C[i].snd + EPS)
				w++;
		ans = max(w, ans);
	}

	printf("%d\n", ans);
}
