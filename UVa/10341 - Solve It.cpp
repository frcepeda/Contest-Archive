#include <cstdio>
#include <cmath>

using namespace std;

int p, q, r, s, t, u;

double f(double x){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double solve(){
	double lo = 0, hi = 1, mid;
	
	for (int t = 0; t < 200; t++){
		mid = (lo + hi) / 2;
		if (f(mid) <= 0)
			hi = mid;
		else
			lo = mid;
	}
	
	return hi;
}

int main() {
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
		double d = solve();
		if (fabs(f(d)) < 1e-6)
			printf("%.4lf\n", d);
		else
			printf("No solution\n");
	}
}