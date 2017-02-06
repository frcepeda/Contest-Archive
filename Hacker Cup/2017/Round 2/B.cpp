#include <cstdio>
#include <iterator>
#include <cassert>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fst first
#define snd second

map<ld,ld> P;
int T, N;
ll Ax, Bx, Cx, Ah, Bh, Ch;
ll H, X;

const ld eps = 1e-6;

bool eq(ld a, ld b){
	return abs(a - b) < eps;
}

ld lineAt(typeof(P.begin()) w, ld x){
	auto z = next(w);

	assert(w->fst <= x && x <= z->fst);

	ld m = (z->snd - w->snd) / (z->fst - w->fst);

	return w->snd + m * (x - w->fst);
}

pair<ld,ld> lineeq(ld x0, ld y0, ld x1, ld y1){
	ld m = (y1 - y0) / (x1 - x0);
	ld b = y0 - m * x0;
	return make_pair(m, b);
}

ld gg(bool bw, ld px, ld ph){
	ld ret = 0;
	auto c = P.insert(make_pair(px, ph)).fst;

	while (true){
		ld nh = H - abs(X - c->fst);
		ld pnh = H - abs(X - px);

		if (c->snd >= nh){
			ld a, b, cc, d;
			tie(a, cc) = lineeq(c->fst, c->snd, px, ph);
			tie(b, d) = lineeq(c->fst, nh, px, pnh);
			ld ix = (d - cc) / (a - b);
			ld ih = H - abs(X - ix);
			ret += (pnh - ph) * abs(px - ix) / 2;
			P[ix] = ih;
			break;
		} else {
			ret += (pnh - ph + nh - c->snd) * abs(px - c->fst) / 2;
			px = c->fst; ph = c->snd;
			if (bw){
				c--;
				P.erase(next(c));
			} else {
				c++;
				P.erase(prev(c));
			}
		}
	}

	return ret;
}

ld go(){
	const ld h = lineAt(prev(P.upper_bound(X)), X);

	if (h >= H) return 0;

	ld ret = 0;

	ret += gg(true, X, h);
	ret += gg(false, X, h);

	P[X] = H;

	return ret;
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d", &N);
		scanf("%lld %lld %lld %lld", &X, &Ax, &Bx, &Cx);
		scanf("%lld %lld %lld %lld", &H, &Ah, &Bh, &Ch);

		P.clear();
		P[-100000000] = 0;
		P[100000000] = 0;

		ld area = go();
		ld ans = area;

		for (int i = 1; i < N; i++){
			X = ((Ax * X + Bx) % Cx) + 1;
			H = ((Ah * H + Bh) % Ch) + 1;
			area += go();
			ans += area;
		}

		printf("Case #%d: %.10Lf\n", t, ans);
	}
}
