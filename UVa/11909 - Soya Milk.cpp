// Accepted
// Check if the spilled milk is more than half the total volume.
// If it is less, then subtract the upper triangle from the total.
// Otherwise, the remaining milk is the lower triangle.

#include <cstdio>
#include <cmath>

using namespace std;

double l, w, h, theta;

int main(){
	while (scanf("%lf %lf %lf %lf", &l, &w, &h, &theta) != EOF){
		double a;

		if (l * tan(theta * M_PI / 180) <= h)
			a = l * h - l * tan(theta * M_PI / 180) * l / 2;
		else
			a = h * tan(theta * M_PI / 180 - M_PI/2) * h / 2;

		printf("%.03lf mL\n", abs(a * w));
	}
}
