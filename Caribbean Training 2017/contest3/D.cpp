#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long double ld;

ld a, b, c, d;

typedef long double FT;

const FT EPS = 1e-9;

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

PT p, q, r, bp, bq, br;
PT u, v, w;
FT R, T, uv, uw, vw;

vector<PT> CircleCircleIntersection(PT a, PT b, FT r, FT R){
	vector<PT> ret;
	FT d = sqrt(dist2(a,b));

	FT x = (d*d-R*R+r*r)/(2*d);
	FT y = sqrt(r*r-x*x);
	PT v = (b-a)/d;

	ret.push_back(a+v*x + RotateCCW90(v)*y);
	ret.push_back(a+v*x - RotateCCW90(v)*y);

	return ret;
}

inline FT sq(FT x) { return x*x; }

inline FT E(FT alpha, FT beta){
	u = p + PT(cos(alpha), sin(alpha)) * R;
	v = q + PT(cos(beta), sin(beta)) * R;
	uv = sqrt(dist2(u,v));

	auto V = CircleCircleIntersection(u, v, uv, uv);

	double d0 = sqrt(dist2(V[0], r));
	double d1 = sqrt(dist2(V[1], r));

	w = d0 < d1 ? V[0] : V[1];

	return min(d0, d1);
}

inline bool isEquilateral(){
	uw = sqrt(dist2(u,w));
	vw = sqrt(dist2(v,w));

	return fabs(uv-uw) < 1e-6 && fabs(uv-vw) < 1e-6 &&
	       fabs(uw-vw) < 1e-6;
}

inline bool isInside(){
	return sqrt(dist2(w, r)) <= R;
}

const FT pi = acos(-1);

const FT TN = 0, T0 = 2;

inline FT delta(){
	return (FT(rand())/RAND_MAX - .5)*T/T0;
}

bool works(){
	T = T0;
	FT alpha = delta(), beta = delta();

	const int imax = 50000;

	for (int i = 0; i < imax; i++){
		T = T0 - FT(i)*(T0-TN)/imax;
		//T = .99955 * T;
		//T = (T0 - TN) * (1 + cos(i*pi/imax)) / 2;

		FT F = E(alpha, beta);

		if (isInside()){
			//cerr << "breaking! iteration: " << i << endl;
			break;
		}

		FT alpha_ = alpha + delta();
		FT beta_ = beta + delta();

		FT FF = E(alpha_, beta_);
		
		if (false && i % 1000 == 0)
			cerr << T << ' ' << F << endl;

		if (FF < F || rand() < RAND_MAX*exp((F - FF)/T)){
			alpha = alpha_;
			beta = beta_;
		}
	}

	E(alpha, beta);
	//cerr << "stopped at: " << << endl;

	if (isInside()){
		bp = u;
		bq = v;
		br = w;
		return true;
	} else return false;
}

int main(){
	cin >> p.x >> p.y;
	cin >> q.x >> q.y;
	cin >> r.x >> r.y;

	FT lo = 0, hi = 300, mid;

	cerr << fixed << setprecision(10);
	cout << fixed << setprecision(10);

	srand(493488);

	for (int i = 0; i < 30; i++){
		R = mid = (lo+hi)/2;
		//cerr << "iteration " << i << ": testing " << mid << endl;
		if (works())
			hi = mid;
		else
			lo = mid;
	}

	cout << bp.x << ' ' << bp.y << endl;
	cout << bq.x << ' ' << bq.y << endl;
	cout << br.x << ' ' << br.y << endl;
}
