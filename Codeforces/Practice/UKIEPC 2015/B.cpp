#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
double g, d[4], th[4];

int main(){
	int i;

	scanf("%d %lf", &N, &g);

	for (i = 0; i < N; i++)
		scanf("%lf %lf", &d[i], &th[i]);

	for (i = 0; i < N; i++){
		double v = 0;
		for (int j = i; j < N; j++)
			v = sqrt(v*v + 2*g*cos(M_PI/180*th[j])*d[j]);
		printf("%.7lf\n", v);
	}
}
