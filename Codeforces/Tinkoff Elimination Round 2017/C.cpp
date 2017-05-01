#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

#define fst first
#define snd second
#define mp make_pair

using namespace std;

typedef long double ld;
typedef pair<ld, ld> pdd;

const int maxn = 100100;
int n;
int x1, y1, x2, y2;
int rx[maxn], ry[maxn], vx[maxn], vy[maxn];

pdd time_(int x, int v, int a, int b){
	if (v == 0){
		if (a < x && x < b)
		       return mp(0, 1e50);
		return mp(0, 0);
	}

	pdd r;

	r.fst = (a - x) / ld(v);
	r.snd = (b - x) / ld(v);

	if (r.fst > r.snd)
		swap(r.fst, r.snd);

	r.fst = max((ld)0, r.fst);

	return r;
}

pdd merge(pdd a, pdd b){
	return mp(
		max(a.fst, b.fst),
		min(a.snd, b.snd)
	);
}

void go(){
	pdd I = mp(0, 1e50);

	for (int i = 0; i < n; i++){
		pdd x = time_(rx[i], vx[i], x1, x2);
		pdd y = time_(ry[i], vy[i], y1, y2);

		I = merge(I, merge(x, y));

		if (I.fst + 1e-12 >= I.snd)
			return;
	}

	cout << setprecision(10) << I.fst << endl;
	exit(0);
}

int main(){
	cin >> n;
	cin >> x1 >> y1 >> x2 >> y2;

	for (int i = 0; i < n; i++)
		cin >> rx[i] >> ry[i] >> vx[i] >> vy[i];

	go();

	cout << -1 << endl;
}
