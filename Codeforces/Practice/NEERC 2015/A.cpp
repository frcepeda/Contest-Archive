#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double w, h;

bool f(double x){
	return (2*x <= w && 2*x <= h) || (3*x <= w && x <= h) || (3*x <= h && x <= w);
}

int main(){
	freopen("alex.in", "r", stdin);
	freopen("alex.out", "w", stdout);

	scanf("%lf %lf", &w, &h);

	/*
	double lo = 0, hi = min(w,h), mid;

	for (int i = 0; i < 200; i++){
		mid = (lo + hi)/2;
		if (!f(mid))
			hi = mid;
		else
			lo = mid;
	}
	*/

	double d = max(max(min(w/3,h), min(h/3,w)), min(h/2,w/2));

	printf("%.8lf\n", d);
}
