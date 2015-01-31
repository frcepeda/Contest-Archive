// Accepted
// The shape in question is an ellipse.

#include <cstdio>
#include <cmath>

using namespace std;

int N;
double D, L;

int main(){
	scanf("%d", &N);

	while (N--){
		scanf("%lf %lf", &D, &L);
		double a = sqrt((L*L - D*D)/4), b = L/2;
		printf("%.03lf\n", M_PI * a * b);
	}
}
