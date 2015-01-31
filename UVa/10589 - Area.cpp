#include <cstdio>

int M, N, a;

#define chk(x,y) ((x)*(x) + (y)*(y) <= a*a)

int main(){
	while (scanf("%d %d", &N, &a), N){
		M = 0;

		for (int i = 0; i < N; i++){
			double x, y;
			scanf("%lf %lf", &x, &y);
			if (chk(x,y) &&
			    chk(a-x, y) &&
			    chk(x, a-y) &&
			    chk(a-x, a-y))
				M++;
		}

		printf("%.05lf\n", ((long long) M * a * a) / (double) N);
	}
}
