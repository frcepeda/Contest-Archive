#include <stdio.h>
#include <math.h>

int N;
double a, b, c, d, s;

int main(void){
	scanf("%d", &N);

	while (N--){
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		s = (a+b+c+d)/2;
		printf("%.2lf\n", sqrt((s-a)*(s-b)*(s-c)*(s-d)));
	}

	return 0;
}
