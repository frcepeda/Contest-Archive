#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const long double EPS = 1e-9;
const int MAXN = 1000010;

struct PT{

	long double x, y;
	PT() {}
	PT(long double x, long double y): x(x), y(y) {}
	PT(const PT &a): x(a.x), y(a.y) {}
	PT operator + (const PT &p) const {return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const {return PT(x - p.x, y - p.y); }
	PT operator * (long double c) const {return PT(x*c, y*c); }
	PT operator / (long double c) const {return PT(x/c, y/c); }

};

long double dot(PT p, PT q){
	return p.x*q.x + p.y*q.y;
}

long double dist2(PT p, PT q){
	return dot(p-q,p-q);
}

long double cross(PT p, PT q){
	return p.x*q.y - p.y*q.x;
}

bool linesParallel(PT a, PT b, PT c, PT d){
	return fabs(cross(b-a, c-d)) < EPS;
}

bool linesCollinear(PT a, PT b, PT c, PT d){
	return linesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;
}

PT linesIntersection(PT a, PT b, PT c, PT d){
	b = b - a;
	d = c - d;
	c = c - a;
	return a + b*cross(c, d)/cross(b, d);
}


vector<PT> polygon;
vector<pii> lines;
ll N;

bool testAttack(ll skip) {
	lines.clear();

	for (ll i = 0; i < N; i++)
		lines.push_back(mp(i,(i+skip+1)%N));

	random_shuffle(lines.begin(), lines.end());

	PT ans = PT(MAXN, MAXN);
	for (ll i = 0; i < N; i++) {
		PT curr = polygon[lines[i].first];
		PT nxt = polygon[lines[i].second];
			
		if (cross(nxt-curr, ans-curr) <= EPS) continue; //Yaay \o/

		PT u(curr), v(nxt);

		for (ll j = 0; j < i; j++) {
			PT p1 = polygon[lines[j].first];
			PT p2 = polygon[lines[j].second];

			if (linesParallel(curr, nxt, p1, p2)) continue;

			PT temp = linesIntersection(curr, nxt, p1, p2);

			PT d = p2 - p1;
			PT r = u - p1; long double cr = cross(d, r);
			PT s = v - p1; long double cs = cross(d, s);

			if (cr < EPS && cs < EPS) continue; // yay
			if (cr > -EPS && cs > -EPS) return false;

			if (cr < EPS) v = temp;
			else u = temp;
		}



		ans = cross(v-u, PT(1,0)) > -EPS ? v : u;
	}

	return true;
}

int main() {
	scanf("%lld", &N);

	if (N <= 3) {
		printf("1\n");
		return 0;
	}
	
	for (ll i = 0; i < N; i++){
		long double a, b;
		scanf("%Lf %Lf", &a, &b); //Given in clockwise direction
		polygon.push_back(PT(a, b));
	}

	ll low = 1, hi = N - 2, mid;
	if (low < hi) {
		mid = (low + hi)/2;
		if (testAttack(mid))
			low = mid + 1;
		else
			hi = mid;
	}

	printf("%lld\n", hi);
}
