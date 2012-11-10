#include <stdio.h>

int N, X, Y;

double min(double a, double b){
	return a < b ? a : b;
}

int main(void){
	double best;

	scanf("%d %d", &X, &Y);

	best = (1000 * (double)X / Y);

	scanf("%d", &N);

	while (N--){
		scanf("%d %d", &X, &Y);
		best = min(best, (1000 * (double)X / Y));
	}

	printf("%.2lf\n", best);

	return 0;
}

