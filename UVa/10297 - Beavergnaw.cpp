#include <cstdio>
#include <cmath>

using namespace std;

double D, V;

double cyl(double diameter, double height){
	return (M_PI * diameter * diameter / 4) * height;
}

double cone(double basediameter, double height){
	return cyl(basediameter, height) / 3;
}

double f(double d){
	return cyl(D,D) - (2*cone(D, D/2) + cyl(d,d) - 2*cone(d, d/2));
}

int main() {
	while (scanf("%lf %lf", &D, &V), (D+V > 0)){
		double lo = 0, hi = D, mid;
		for (int i = 0; i < 30; i++){
			mid = (lo + hi) / 2;
			if (f(mid) <= V)
				hi = mid;
			else
				lo = mid;
		}
		printf("%.03lf\n", hi);
	}
}