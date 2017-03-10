#include <cstdio>
#include <cmath>
#include <algorithm>

int N;
double X, Y, Z;

int main(){
	scanf("%d", &N);

	while (N--){
		scanf("%lf %lf %lf", &X, &Y, &Z);
		double s = (X + Y + Z)/2;
		printf("%.1lf\n", 7*sqrt(s * (s-X) * (s-Y) * (s-Z)));
	}
}
