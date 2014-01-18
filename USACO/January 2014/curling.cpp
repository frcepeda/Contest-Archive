// 100/100 points
#include <cstdio>
#include <algorithm>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("curling.in", "r", stdin); freopen("curling.out", "w", stdout)
#else
	#define openFiles()
#endif

using namespace std;

// USACO upload macros

#define MAXN 50010
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef pair<ll,ll> pll;

#define between(a,b,c) (a <= b && b <= c)
#define cw(a,b,c) (cross(a,b,c) <= 0)
#define inTriangle(p,a,b,c) (cw(b,a,p) && cw(c,b,p) && cw(a,c,p))

long long cross(pll &a, pll &b, pll &c){
	return (b.fst-a.fst)*(c.snd-a.snd) - (b.snd-a.snd)*(c.fst-a.fst);
}

int N;
pll A[MAXN], B[MAXN];
pll Ahull[MAXN], Bhull[MAXN];
int Asiz, Bsiz;

int convexHull(pll *P, pll *H){
	int s = 0, t, i;

	sort(P, P+N);

	for (i = 0; i < N; i++){
		while (s >= 2 && cw(H[s-2], H[s-1], P[i])) s--;
		H[s++] = P[i];
	}

	for (i = N-2, t = s; i >= 0; i--){
		while (s > t && cw(H[s-2], H[s-1], P[i])) s--;
		H[s++] = P[i];
	}

	return s-1;
}

bool inPoly(pll P, pll *H, int Hsiz){
	int lo = 0, hi = Hsiz, mid;

	if (Hsiz == 2)
		return cross(H[0], P, H[1]) == 0 &&
		       between(H[0].fst, P.fst, H[1].fst) &&
		       between(H[0].snd, P.snd, H[1].snd);

	while (hi - lo > 1){
		mid = (lo + hi)/2;

		if (cw(H[0], H[mid], P))
			hi = mid;
		else
			lo = mid;
	}

	return inTriangle(P, H[0], H[lo], H[hi]);
}

int main(){
	int i;
	openFiles();

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%lld %lld", &A[i].fst, &A[i].snd);
	for (i = 0; i < N; i++)
		scanf("%lld %lld", &B[i].fst, &B[i].snd);

	Asiz = convexHull(A, Ahull);
	Bsiz = convexHull(B, Bhull);

	int scoreA = 0, scoreB = 0;

	for (i = 0; i < N; i++)
		if (inPoly(B[i], Ahull, Asiz))
			scoreA++;

	for (i = 0; i < N; i++)
		if (inPoly(A[i], Bhull, Bsiz))
			scoreB++;

	printf("%d %d\n", scoreA, scoreB);
}
