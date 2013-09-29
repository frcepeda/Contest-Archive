// Accepted
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

#define MAXN 1100

#define mp make_pair
#define fst first
#define snd second

typedef long long int lli;
typedef pair<lli,lli> point;
typedef pair< pair<pair<lli,lli>,pair<lli,lli> >, bool> line;
set<line> lines;

point points[MAXN];
int N;

lli gcd(lli a, lli b){
	lli c;
	while (b != 0){
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

pair< pair<lli,lli>,pair<lli,lli> > mkline(point a, point b){
	lli up = a.snd - b.snd;
	lli down = a.fst - b.fst;
	if (up < 0){
		up = -up;
		down = -down;
	}
	lli g = gcd(up,down);
	up /= g;
	down /= g;
	lli up0 = - a.fst * up + a.snd * down;
	lli down0 = down;
	g = gcd(up0, down0);
	if (up0 < 0){
		up0 = -up0;
		down0 = -down0;
	}
	up0 /= g;
	down0 /= g;
	return mp(mp(up,down),mp(up0,down0));
}

line getLine(point a, point b){
	if (a.fst == b.fst)
		return mp(mp(mp(0,0),mp(a.fst,0)),true);
	else
		return mp(mkline(a,b), false);
}

int main(){
	int i, j;

	while (scanf("%d", &N), N){
		lines.clear();
		for (i = 0; i < N; i++)
			scanf("%lld %lld", &points[i].fst, &points[i].snd);

		for (i = 0; i < N; i++)
			for (j = i+1; j < N; j++)
				lines.insert(getLine(points[i],points[j]));

		printf("%d\n", (int)lines.size());
	}
}
