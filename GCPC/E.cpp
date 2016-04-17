#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
double V;
int best;
double bestv = 1e100;
const double dx = 5e-6;

double vol(double a, double b, double h){
	double r = 0;

	for (double x = 0; x < h; x += dx)
		r += dx * M_PI * pow(a * exp(-x*x) + b * sqrt(x), 2);

	//fprintf(stderr, "%lf\n", r);

	return r;
}

int main(){
	scanf("%lf %d", &V, &N);

	for (int i = 0; i < N; i++){
		double v, a, b, h;

		scanf("%lf %lf %lf", &a, &b, &h);

		v = vol(a, b, h);

		if (fabs(v - V) < fabs(bestv - V)){
			bestv = v;
			best = i;
		}
	}

	printf("%d\n", best);
}
