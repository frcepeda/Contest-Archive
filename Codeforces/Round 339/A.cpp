#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define fst first
#define snd second

typedef pair<double,double> pii;

int n;
pii P, A[100100];

double q(int i, double z){
	pii x;
	x.fst = A[i].fst * z + A[(i+1)%n].fst * (1-z);
	x.snd = A[i].snd * z + A[(i+1)%n].snd * (1-z);
	return hypot(abs(x.snd - P.snd), abs(x.fst - P.fst));
}

double f(int i){
	double lo = 0, hi = 1, mid;

	while (hi - lo > 1e-9){
		mid = (lo + hi)/2;
		if (q(i,mid) < q(i,mid+1e-10))
			lo = mid;
		else
			hi = mid;
	}

	return q(i,(lo+hi)/2);
}

double g(int i){
	double lo = 0, hi = 1, mid;

	while (hi - lo > 1e-9){
		mid = (lo + hi)/2;
		if (q(i,mid) > q(i,mid+1e-10))
			lo = mid;
		else
			hi = mid;
	}

	return q(i,(lo+hi)/2);
}

int main(){
	scanf("%d %lf %lf", &n, &P.fst, &P.snd);

	double M = 0, m = 1e100;
	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &A[i].fst, &A[i].snd);

	for (int i = 0; i < n; i++){
		double a = q(i,0), b = q(i,1), c = g(i), d = f(i);
		m = min(m, min(a,min(b,min(c,d))));
		M = max(M, max(a,max(b,max(c,d))));
	}

	printf("%.18lf\n", 3.14159265359 * (M*M - m*m));
}