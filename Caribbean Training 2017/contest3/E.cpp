#include <cstdio>
#include <algorithm>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

typedef long double FT;

const FT EPS = 1e-10;

struct PT {
	FT x, y;
	PT() {}
	PT(FT x, FT y) : x(x), y(y) {}
	PT(const PT &p) : x(p.x), y(p.y) {}
	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
	PT operator * (FT c)    const { return PT(c*x, c*y); }
	PT operator / (FT c)    const { return PT(x/c, y/c); }
	bool operator < (const PT &p) const { return false; }
};

FT dot(const PT p, const PT q) { return p.x*q.x + p.y*q.y; }
FT dist2(const PT p, const PT q) { return dot(p-q,p-q); }
FT cross(const PT p, const PT q) { return p.x*q.y - p.y*q.x; }
FT norm2(const PT p) { return dot(p,p); }

PT ProjectPointSegment(PT a, PT b, PT c){
	FT r = norm2(b-a);
	if (fabs(r) < EPS) return a;
	r = dot(c-a, b-a)/r;
	if (r < 0) return a;
	if (r > 1) return b;
	return a + (b-a)*r;
}

FT DistancePointSegment(PT a, PT b, PT c){
	return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

const int maxn = 1010;
int N;
pair<PT,PT> P[maxn];

FT atan(PT a){
	FT f = atan2(a.y, a.x);
	if (f < 0) f += M_PI;
	return f;
}

pair<int, pair<PT,PT>> go(PT z, PT o){
	pair<int, pair<PT,PT>> ret = mp(0, mp(z, o));

	vector<pair<PT,bool>> e;

	int acc = 0;
	for (int i = 0; i < N; i++){
		if (DistancePointSegment(P[i].fst, P[i].snd, z) < EPS){
			acc++;
			continue;
		}


		bool b = atan(P[i].fst-z) > atan(P[i].snd-z);
		e.push_back(mp(P[i].fst, b));
		e.push_back(mp(P[i].snd, !b));
	}

	sort(e.begin(), e.end(),
		[=](const pair<PT,bool> &a, const pair<PT,bool> &b){
			FT tha = atan(a.fst - z);
			FT thb = atan(b.fst - z);
			if (fabs(tha - thb) < EPS)
				return a.snd < b.snd;
			return tha < thb;
		}
	);

	int cnt = 0;
	for (const auto w: e){
		if (!w.snd) cnt++; else cnt--;
		if (cnt >= ret.fst){ 
			ret.fst = cnt;
			ret.snd.snd = w.fst;
		}
	}

	ret.fst += acc;
	return ret;
}

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%Lf %Lf %Lf %Lf", &P[i].fst.x, &P[i].fst.y,
		                         &P[i].snd.x, &P[i].snd.y);

	pair<int, pair<PT,PT>> ans;
	ans.fst = 0;

	for (int i = 0; i < N; i++){
		ans = max(ans, go(P[i].fst, P[i].snd));
		ans = max(ans, go(P[i].snd, P[i].fst));
	}

	int a = round(ans.snd.fst.x);
	int b = round(ans.snd.fst.y);
	int c = round(ans.snd.snd.x);
	int d = round(ans.snd.snd.y);

	fprintf(stderr, "intersections: %d\n", ans.fst);
	printf("%d %d %d %d\n", a, b, c, d);
}
