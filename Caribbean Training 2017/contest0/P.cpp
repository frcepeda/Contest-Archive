#include <cstdio>
#include <cmath>

using namespace std;

int K, x[2], y[2], r[2];

int main(){
	scanf("%d", &K);

	for (int k = 0; k < K; k++){
		scanf("%d %d %d", &x[0], &y[0], &r[0]);
		scanf("%d %d %d", &x[1], &y[1], &r[1]);

		int dx = x[0] - x[1], dy = y[0] - y[1];
		int d = dx*dx + dy*dy, r2 = r[0] + r[1];
		r2 *= r2;

		if (d > r2)
			printf("There are no points\n");
		else if (d < r2)
			printf("Too many points\n");
		else {
			long double a = double(r[0]) / (r[0] + r[1]);
			long double p = x[0] + a * (x[1] - x[0]);
			long double q = y[0] + a * (y[1] - y[0]);
			printf("There are only 1 of them\n%0.6Lf %0.6Lf\n", p, q);
		}

		if (k+1 < K) putchar('\n');
	}
}
