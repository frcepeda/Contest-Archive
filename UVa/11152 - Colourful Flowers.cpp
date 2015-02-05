// Accepted
// Geometry? What's that?

#include <cstdio>
#include <cmath>

using namespace std;

double a, b, c;

int main(){
	while (scanf("%lf %lf %lf", &a, &b, &c) != EOF){
		double s = (a + b + c) / 2;
		double A = sqrt(s * (s - a) * (s - b) * (s - c));
		double R = a * b * c / 4 / A;
		double r = A / s;
		double circumcircle = M_PI * R * R;
		double incircle = M_PI * r * r;
		printf("%.04lf %.04lf %.04lf\n", circumcircle - A, A - incircle, incircle);
	}
}
