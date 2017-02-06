#include <cstdio>

int T;

double a, b, c;

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%lf %lf %lf", &a, &b, &c);

		double tq = ((a+b-c)*(a-b+c)*(-a+b+c))/(a*b*c);

		if (a == b && b == c){
			printf("equilateral\n");
		} else if (tq > .5){
			printf("good\n");
		} else {
			printf("bad\n");
		}
	}
}
